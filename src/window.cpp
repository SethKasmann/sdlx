/*
 * SDLX, a SDL graphics library for CS students.
 * Copyright (C) 2017, Yihsiang Liow, Seth Kasmann
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <vector>
#include "window.h"
#include "image.h"
#include "sdllib.h"

namespace sdlx {
    
    Window::Window(const std::string& name)
    : _renderer(nullptr), _window(nullptr)
    {
        _init(name, DEFAULT_WIDTH, DEFAULT_HEIGHT);
    }

    Window::Window(int width, int height, const std::string& name)
    : _renderer(nullptr), _window(nullptr)
    {
        _init(name, width, height);    
    }

    Window::~Window()
    {
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
    }

    void Window::_init(const std::string& name, int width, int height)
    {
        _window = SDL_CreateWindow(
            name.c_str(),
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            0);

        if (_window == nullptr)
            std::cout << "Could not create window:" << SDL_GetError() << '\n';

        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

        if (_renderer == nullptr)
            std::cout << "Could not create window:" << SDL_GetError() << '\n';

        clear(BLACK);
        draw();
    }

    SDL_Renderer* Window::get_renderer()
    {
        return _renderer;
    }

    int Window::get_id() const
    {
        return SDL_GetWindowID(_window);
    }

    void Window::get_size(int& w, int& h) const
    {
        SDL_GetWindowSize(_window, &w, &h);
    }

    void Window::set_size(int w, int h)
    {
        SDL_SetWindowSize(_window, w, h);
    }

    void Window::hide()
    {
        SDL_HideWindow(_window);
    }

    void Window::show()
    {
        SDL_ShowWindow(_window);
    }

    int Window::fullscreen()
    {
        return SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
    }

    //------------------------------------------------------------------------
    // Basic drawing
    //------------------------------------------------------------------------
    void Window::clear(const Color& c)
    {
        _set_color(c.r, c.g, c.b, c.a);
        SDL_RenderClear(_renderer);
    }

    void Window::draw()
    {
        SDL_RenderPresent(_renderer);
    }

    //------------------------------------------------------------------------
    // Pixel drawing
    //------------------------------------------------------------------------

    int Window::put_point(const Point& p, const Color& c)
    {
        return _set_color(c.r, c.g, c.b, c.a) | _put_point(p.x, p.y);
    }

    int Window::put_point(const Point& p, int r, int g, int b, int a)
    {
        return _set_color(r, g, b, a) | _put_point(p.x, p.y);
    }

    int Window::put_point(int x, int y, const Color& c)
    {
        return _set_color(c.r, c.g, c.b, c.a) | _put_point(x, y);
    }

    int Window::put_point(int x, int y, int r, int g, int b, int a)
    {
        return _set_color(r, g, b, a) | _put_point(x, y);
    }

    //------------------------------------------------------------------------
    // Line drawing
    //------------------------------------------------------------------------

    int Window::put_line(int x0, int y0, int x1, int y1, const Color& c)
    {
        return _set_color(c.r, c.g, c.b, c.a) | _put_line(x0, y0, x1, y1);
    }

    int Window::put_line(int x0, int y0, int x1, int y1, int r, int g, int b, int a)
    {
        return _set_color(r, g, b, a) | _put_line(x0, y0, x1, y1);
    }

    int Window::put_line(const Point* const p, size_t size, const Color& c)
    {
        return _set_color(c.r, c.g, c.b, c.a) | _put_line(p, size);
    }

    int Window::put_line(const Point* const p, size_t size, int r, int g, int b, int a)
    {
        return _set_color(r, g, b, a) | _put_line(p, size);
    }

    //------------------------------------------------------------------------
    // Circle drawing
    //------------------------------------------------------------------------

    int Window::put_circle(int x, int y, int rad, int r, int g, int b, int a)
    {
        return filledCircleRGBA(_renderer, x, y, rad, r, g, b, a);
    }

    int Window::put_circle(const Circle& cir, const Color& c)
    {
        return put_circle(cir.x, cir.y, cir.r, c.r, c.g, c.b, c.a);
    }

    int Window::put_circle(const Circle& c, int r, int g, int b, int a)
    {
        return put_circle(c.x, c.y, c.r, r, g, b, a);
    }

    int Window::put_circle(int x, int y, int r, const Color& c)
    {
        return put_circle(x, y, r, c.r, c.g, c.b, c.a);
    }

    int Window::put_unfilled_circle(int x, int y, int rad, int r, int g, int b, int a)
    {
        return circleRGBA(_renderer, x, y, rad, r, g, b, a);
    }

    int Window::put_unfilled_circle(int x, int y, int r, const Color& c)
    {
        return put_unfilled_circle(x, y, r, c.r, c.g, c.b, c.a);
    }

    int Window::put_unfilled_circle(const Circle& c, int r, int g, int b, int a)
    {
        return put_unfilled_circle(c.x, c.y, c.r, r, g, b, a);
    }

    int Window::put_unfilled_circle(const Circle& cir, const Color& c)
    {
        return put_unfilled_circle(cir.x, cir.y, cir.r, c.r, c.g, c.g, c.a);
    }

    //------------------------------------------------------------------------
    // Ellipse drawing
    //------------------------------------------------------------------------

    int Window::put_ellipse(int x, int y, int rx, int ry, int r, int g, int b, int a)
    {
        return filledEllipseRGBA(_renderer, x, y, rx, ry, r, g, b, a);
    }

    int Window::put_ellipse(const Ellipse& e, const Color& c)
    {
        return put_ellipse(e.x, e.y, e.rx, e.ry, c.r, c.g, c.b, c.a);
    }

    int Window::put_ellipse(const Ellipse& e, int r, int g, int b, int a)
    {
        return put_ellipse(e.x, e.y, e.rx, e.ry, r, g, b, a);
    }

    int Window::put_ellipse(int x, int y, int rx, int ry, const Color& c)
    {
        return put_ellipse(x, y, rx, ry, c.r, c.g, c.b, c.a);
    }

    int Window::put_unfilled_ellipse(int x, int y, int rx, int ry, int r, int g, int b, int a)
    {
        return ellipseRGBA(_renderer, x, y, rx, ry, r, g, b, a);
    }

    int Window::put_unfilled_ellipse(int x, int y, int rx, int ry, const Color& c)
    {
        return put_unfilled_ellipse(x, y, rx, ry, c.r, c.g, c.b, c.a);
    }

    int Window::put_unfilled_ellipse(const Ellipse& e, int r, int g, int b, int a)
    {
        return put_unfilled_ellipse(e.x, e.y, e.rx, e.ry, r, g, b, a);
    }

    int Window::put_unfilled_ellipse(const Ellipse& e, const Color& c)
    {
        return put_unfilled_ellipse(e.x, e.y, e.rx, e.ry, c.r, c.g, c.b, c.a);
    }

    //------------------------------------------------------------------------
    // Image drawing
    //------------------------------------------------------------------------
    void Window::put_image(Image& image, Rect& src, Rect& dst)
    {
        SDL_RenderCopy(_renderer, image.get_texture(), &src, &dst);    
    }

    void Window::put_image(Image& image, Rect& dst)
    {
        SDL_RenderCopy(_renderer, image.get_texture(), NULL, &dst);
    }

    //------------------------------------------------------------------------
    // Rectangle drawing
    //------------------------------------------------------------------------

    int Window::put_unfilled_rect( int x, int y, int w, int h, const Color& c)
    {
        return _set_color(c.r, c.g, c.b, c.a) | _put_unfilled_rect(x, y, w, h);
    }

    int Window::put_unfilled_rect(const Rect& r, const Color& c)
    {
        return _set_color(c.r, c.g, c.b, c.a) | _put_unfilled_rect(r.x, r.y, r.w, r.h);
    }

    int Window::put_unfilled_rect(const Rect& rect, int r, int g, int b, int a)
    {
        return _set_color(r, g, b, a) | _put_unfilled_rect(rect.x, rect.y, rect.w, rect.h);
    }

    int Window::put_unfilled_rect(int x, int y, int w, int h, int r, int g, int b, int a)
    {
        return _set_color(r, g, b, a) | _put_unfilled_rect(x, y, w, h);
    }

    int Window::put_rect(const Rect& r, const Color& c)
    {
        return _set_color(c.r, c.g, c.b, c.a) | _put_rect(r);
    }

    int Window::put_rect(const Rect& rect, int r, int g, int b, int a)
    {
        return _set_color(r, g, b, a) | _put_rect(rect);
    }

    int Window::put_rect(int x, int y, int w, int h, const Color& c)
    {
        Rect r = { x, y, w, h };
        return _set_color(c.r, c.g, c.b, c.a) | _put_rect(r);
    }

    int Window::put_rect(int x, int y, int w, int h, int r, int g, int b, int a)
    {
        Rect rect = { x, y, w, h };
        return _set_color(r, g, b, a) | _put_rect(rect);
    }

    //------------------------------------------------------------------------
    // Polygon drawing
    //------------------------------------------------------------------------

    int Window::put_unfilled_polygon(const Point* const p, size_t size, const Color& c)
    {
        return _set_color(c.r, c.g, c.b, c.a) | _put_unfilled_polygon(p, size);
    }

    int Window::put_unfilled_polygon(const Point* const p, size_t size, int r, int g, int b, int a)
    {
        return _set_color(r, g, b, a) | _put_unfilled_polygon(p, size);
    }

    int Window::put_polygon(const Point* const p, size_t size, int r, int g, int b, int a)
    {
        if (size < 3)
            return -1;

        std::vector<int16_t> x(size);
        std::vector<int16_t> y(size);

        for (int i = 0; i < size; ++i)
        {
            x[i] = p[i].x;
            y[i] = p[i].y;
        }

        return filledPolygonRGBA(_renderer, x.data(), y.data(), size,
            r, g, b, a); 
    }

    int Window::put_polygon(const Point* const p, size_t size, const Color& c)
    {
        return put_polygon(p, size, c.r, c.g, c.b, c.a);
    }

    //------------------------------------------------------------------------
    // Private Functions - You cannot call these.
    //------------------------------------------------------------------------

    int Window::_set_color(int r, int g, int b, int a)
    {
        return SDL_SetRenderDrawColor(_renderer, r, g, b, a);
    }

    int Window::_put_point(int x, int y)
    {
        const SDL_Point point = { x, y };
        return SDL_RenderDrawPoints(_renderer, &point, 1);
    }

    int Window::_put_line(int x0, int y0, int x1, int y1)
    {
        SDL_Point points[2];
        points[0].x = x0;
        points[0].y = y0;
        points[1].x = x1;
        points[1].y = y1;
        return SDL_RenderDrawLines(_renderer, points, 2);
    }

    int Window::_put_line(const Point* const p, size_t size)
    {
        if (size < 2)
            return -1;
        return SDL_RenderDrawLines(_renderer, p, size);
    }

    int Window::_put_rect(const Rect& r)
    {
        return SDL_RenderFillRects(_renderer, &r, 1);
    }

    int Window::_put_unfilled_rect(int x, int y, int w, int h)
    {
        SDL_Point points[5];
        points[0].x = x;
        points[0].y = y;
        points[1].x = x + w - 1;
        points[1].y = y;
        points[2].x = x + w - 1;
        points[2].y = y + h - 1;
        points[3].x = x;
        points[3].y = y + h - 1;
        points[4].x = x;
        points[4].y = y;
        return SDL_RenderDrawLines(_renderer, points, 5);
    }

    int Window::_put_unfilled_polygon(const Point* const p, size_t size)
    {
        if (size < 3)
            return -1;
        return SDL_RenderDrawLines(_renderer, p, size)
             | _put_line(p[size-1].x, p[size-1].y, p[0].x, p[0].y);
    }

}