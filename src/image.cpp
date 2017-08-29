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

#include "image.h"
#include "window.h"
#include "sdllib.h"

namespace sdlx {

    /*****************************************************************************
    Class Font
    *****************************************************************************/
    
    Font::Font(const std::string& fontfamily, size_t size)
    : _font(NULL)
    {
        _font = TTF_OpenFont(fontfamily.c_str(), size);
    }

    Font::~Font()
    {
        TTF_CloseFont(_font);
    }

    TTF_Font* Font::get_font()
    {
        return _font;
    }

    /*****************************************************************************
        Class Image
    *****************************************************************************/

    Image::Image()
    : _image(NULL), _w(0), _h(0)
    {}

    Image::Image(const std::string& filename, Window& window)
    : Image()
    {
        _image = IMG_LoadTexture(window.get_renderer(), filename.c_str());

        if (_image == NULL)
        {
            std::cout << "Error in Image::Image(): No image file" << filename << '\n';
            exit(1);
        }

        SDL_QueryTexture(_image, NULL, NULL, &_w, &_h);
    }

    Image::Image(const std::string& text, Font& font, const Color& c, Window& window)
    : Image()
    {
        SDL_Color color = { c.r, c.b, c.g, c.a };
        SDL_Surface* s = TTF_RenderText_Solid(font.get_font(), text.c_str(), color);
        _image = SDL_CreateTextureFromSurface(window.get_renderer(), s);
        SDL_QueryTexture(_image, NULL, NULL, &_w, &_h);
    }

    Image::~Image()
    {
        SDL_DestroyTexture(_image);
    }

    SDL_Texture* Image::get_texture()
    {
        return _image;
    }

    int Image::get_width() const
    {
        return _w;
    }

    int Image::get_height() const
    {
        return _h;
    }

    Rect Image::get_rect() const
    {
        return Rect { 0, 0, _w, _h };
    }

}