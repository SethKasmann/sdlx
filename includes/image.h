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

#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <iostream>
#include "types.h"

class SDL_Texture;
class _TTF_Font;

namespace sdlx {
    
    class Window;
    
    class Font
    {
    public:
        Font(const std::string& fontfamily="fonts/FreeSans.fft", size_t size=12);
        ~Font();
        _TTF_Font* get_font();
    private:
        _TTF_Font* _font;
    };

    class Image
    {
    public:
        Image();
        Image(const std::string& filename, Window& window);
        Image(const std::string& text, Font& font, const Color& c, Window& window);
        ~Image();
        SDL_Texture* get_texture();
        int get_width() const;
        int get_height() const;
        Rect get_rect() const;
    private:
          SDL_Texture* _image;
          int _w, _h;
    };
}
#endif


