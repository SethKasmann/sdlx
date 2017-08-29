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

#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

class SDL_Point;
class SDL_Rect;

namespace sdlx {

    #define SDLX_NUM_SCANCODES 512

    typedef SDL_Point Point;
    typedef SDL_Rect Rect;
    typedef uint32_t u32;
    typedef int32_t s32;
    typedef uint8_t u8;

    struct Circle
    {
        int16_t x;
        int16_t y;
        int16_t r;
    };

    struct Ellipse
    {
        int16_t x;
        int16_t y;
        int16_t rx;
        int16_t ry;
    };

    struct Color
    {
        Color()
            : a(255)
        {}
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255)
            : r(red), g(green), b(blue), a(alpha)
        {}
        uint8_t r, g, b, a;
    };

    static const Color BLACK(0, 0, 0 );
    static const Color RED(255, 50, 50);
    static const Color WHITE(255, 255, 255);
    static const Color GREEN(0, 255, 0);
    static const Color BLUE(0, 0, 255);
    static const Color GRAY(130, 130, 130);
    static const Color DARKGRAY(50, 50, 50);
    static const Color YELLOW(231, 228, 13);
    static const Color CYAN(0, 255, 255);
    static const Color ORANGE(255, 114, 0);
}

#endif