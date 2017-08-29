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

#include "device.h"
#include "sdllib.h"

namespace sdlx {

	//------------------------------------------------------------------------
    // Keyboard Class
    //------------------------------------------------------------------------

	Keyboard::Keyboard()
	: _cur(SDL_GetKeyboardState(nullptr))
	{
		for (int i = 0; i < SDLX_NUM_SCANCODES; ++i)
		{
			_pre[i] = 0;
		}
	}

	bool Keyboard::down(int key)
	{
		if (_cur[key])
			return true;
		_pre[key] = _cur[key];
		return false;
	}

	bool Keyboard::pressed(int key)
	{
		if (down(key) && !_pre[key])
		{
			_pre[key] = _cur[key];
			return true;
		}
	    return false;
	}

	//------------------------------------------------------------------------
    // Mouse Class
    //------------------------------------------------------------------------

    Mouse::Mouse()
    : _mask(SDL_GetMouseState(nullptr, nullptr))
    {}

    int Mouse::get_x()
    {
        int x;
        SDL_GetMouseState(&x, nullptr);
        return x;
    }

    int Mouse::get_y()
    {
        int y;
        SDL_GetMouseState(nullptr, &y);
        return y;
    }

    bool Mouse::down(uint32_t button)
    {
        if (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(button))
            return true;
        _mask &= ~SDL_BUTTON(button);
        return false;
    }

    bool Mouse::pressed(uint32_t button)
    {
        if (down(button))
        {
            if (!(_mask & SDL_BUTTON(button)))
            {
                _mask |= SDL_BUTTON(button);
                return true;
            }
        }
        return false;
    }
}
