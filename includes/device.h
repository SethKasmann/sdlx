/*
 * SDLX, a SDL graphics library for CS students.
 * Copyright (C) 2017, Seth Kasmann, Yihsiang Liow
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

#ifndef DEVICE_H
#define DEVICE_H

#include "types.h"

namespace sdlx {

    /*************************************************************************

        A Keyboard object models a simple keyboard. 

        The function down(int key) will return true iff the key is currently 
        down. 

        The function pressed(int key) will return true only when the key is 
        first pressed. Do note the pressed function will update internally - 
        so each key you check can only return true once per game loop.

        (See a full list of available keys in constants.h)

    *************************************************************************/
    class Keyboard
    {
    public:
        Keyboard();
        bool down(int key);
        bool pressed(int key);
    private:
        const uint8_t* const _cur;
        uint8_t _pre[SDLX_NUM_SCANCODES];
    };

    /*************************************************************************

        A Mouse object models a simple mouse.

        The function x(), and y(), will return the x and y position of the
        mouse.

        The function down(int button) will return true iff the mouse button
        is currently down.

        The function pressed(int button) will return true only when the
        button is first pressed. Do note the pressed function will update
        internally - so each button you check can only return true once
        per game loop.

        (See a full list of available buttons in constants.h)

    *************************************************************************/
    class Mouse
    {
    public:
        Mouse();
        int get_x();
        int get_y();
        bool down(uint32_t button);
        bool pressed(uint32_t button);
    private:
        uint32_t _mask;
    };
}

#endif