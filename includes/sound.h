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

#ifndef SOUND_H
#define SOUND_H

class Mix_Chunk;
class _Mix_Music;

namespace sdlx {

    /*************************************************************************

        Class Sound

        This class allows you to play a wav file. Note that you need to 
        download SDL2_Mixer. 

        USAGE:
        Sound sound("mysound.wav");
        sound.play();
        delay(5000);

    *************************************************************************/
    class Sound
    {
    public:
        Sound(const char* filename=nullptr);
        ~Sound();
        void on();
        void off();
        void play();
    private:
        Mix_Chunk* sample;
        bool _on;
    };

    /*************************************************************************

        Class Music

        This class allows you to play a wav file. Note that you need to 
        download SDL2_Mixer. 

        USAGE:
      
        Music music("a.mid");

        music.play();
        delay(5000);

        music.stop();
        delay(100);

        music.play();
        delay(5000);

        music.stop();
        delay(100);

        music.load("b.mid");
        music.play();
        delay(5000);

        music.stop();
        delay(100);

    *************************************************************************/

    class Music
    {
    public:
        Music(const char* filename=nullptr);
        ~Music();
        void load(const char* filename=nullptr);
        void free();
        void on();
        void off();
        void play();
        void stop();
    private:
        _Mix_Music* sample;
        bool _on;
    };

}

#endif
