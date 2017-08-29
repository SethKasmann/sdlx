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

#ifndef WINDOW_H
#define WINDOW_H

#include "types.h"
#include <string>

class SDL_Window;
class SDL_Renderer;

namespace sdlx {

    // Window defaults.
    static const int DEFAULT_WIDTH  = 640;
    static const int DEFAULT_HEIGHT = 480;
    
    class Image;

    class Window
    {
    public:
        Window(const std::string& name="CISS 245");
        Window(int width, int height, const std::string& name="CISS 245");
        ~Window();
        SDL_Renderer* get_renderer();


        //------------------------------------------------------------------------
        // Window Properties
        //------------------------------------------------------------------------

        int  get_id() const;
        void get_size(int& w, int& h) const;
        void set_size(int w, int h);
        void hide();
        void show();
        int  fullscreen();

        //------------------------------------------------------------------------
        // Basic Drawing
        //------------------------------------------------------------------------

        void clear(const Color& c=BLACK);
        void draw();

        //------------------------------------------------------------------------
        // Pixel drawing
        //------------------------------------------------------------------------

        int put_point(const Point& p, const Color& c);
        int put_point(const Point& p, int r, int g, int b, int a=255);
        int put_point(int x, int y, const Color& c);
        int put_point(int x, int y, int r, int g, int b, int a=255);

        //------------------------------------------------------------------------
        // Line drawing
        //------------------------------------------------------------------------

        int put_line(int x0, int y0, int x1, int y1, const Color& c);
        int put_line(int x0, int y0, int x1, int y1, int r, int g, int b, int a=255);
        int put_line(const Point* const p, size_t size, const Color& c);
        int put_line(const Point* const p, size_t size, int r, int g, int b, int a=255);

        //------------------------------------------------------------------------
        // Circle drawing
        //------------------------------------------------------------------------

        int put_circle(int x, int y, int rad, int r, int g, int b, int a=255);
        int put_circle(const Circle& cir, const Color& c);
        int put_circle(int x, int y, int r, const Color& c);
        int put_circle(const Circle& c, int r, int g, int b, int a=255);

        int put_unfilled_circle(int x, int y, int r, const Color& c);
        int put_unfilled_circle(int x, int y, int rad, int r, int g, int b, int a=255);
        int put_unfilled_circle(const Circle& c, int r, int g, int b, int a=255);
        int put_unfilled_circle(const Circle& cir, const Color& c);

        //------------------------------------------------------------------------
        // Ellipse drawing
        //------------------------------------------------------------------------

        int put_ellipse(int x, int y, int rx, int ry, int r, int g, int b, int a=255);
        int put_ellipse(const Ellipse& e, const Color& c);
        int put_ellipse(int x, int y, int rx, int ry, const Color& c);
        int put_ellipse(const Ellipse& e, int r, int g, int b, int a=255);

        int put_unfilled_ellipse(int x, int y, int rx, int ry, const Color& c);
        int put_unfilled_ellipse(int x, int y, int rx, int ry, int r, int g, int b, int a=255);
        int put_unfilled_ellipse(const Ellipse& e, int r, int g, int b, int a=255);
        int put_unfilled_ellipse(const Ellipse& e, const Color& c);

        //------------------------------------------------------------------------
        // Image drawing
        //------------------------------------------------------------------------

        void put_image(Image& image, Rect& src, Rect& dst);
        void put_image(Image& image, Rect& dst);

        //------------------------------------------------------------------------
        // Rectangle drawing
        //------------------------------------------------------------------------

        int put_rect(const Rect& rect, int r, int g, int b, int a=255);
        int put_rect(const Rect& r, const Color& c);
        int put_rect(int x, int y, int w, int h, const Color& c);
        int put_rect(int x, int y, int w, int h, int r, int g, int b, int a=255);

        int put_unfilled_rect( int x, int y, int w, int h, const Color& c);
        int put_unfilled_rect( const Rect& r, const Color& c);
        int put_unfilled_rect(const Rect& rect, int r, int g, int b, int a=255);
        int put_unfilled_rect(int x, int y, int w, int h, int r, int g, int b, int a=255);

        //------------------------------------------------------------------------
        // Polygon drawing
        //------------------------------------------------------------------------

        int put_polygon(const Point* const p, size_t size, const Color& c);
        int put_polygon(const Point* const p, size_t size, int r, int g, int b, int a=255);
        int put_unfilled_polygon(const Point* const p, size_t size, const Color& c);
        int put_unfilled_polygon(const Point* const p, size_t size, int r, int g, int b, int a=255);

    private:
        bool _closed;
        SDL_Window* _window;
        SDL_Renderer* _renderer;

        Window(const Window& w);
        void operator=(const Window& w);
        
        int _set_color(int r, int g, int b, int a);
        void init(const std::string& name, int width, int height);
        int _put_point(int x, int y);
        int _put_line(int x0, int y0, int x1, int y1);
        int _put_line(const Point* const p, size_t size);
        int _put_rect(const Rect& r);
        int _put_unfilled_rect(int x, int y, int w, int h);
        int _put_unfilled_polygon(const Point* const p, size_t size);
    };
    
}

#endif