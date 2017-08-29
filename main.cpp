#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream>

#include "sdlx.h"

// This tutorial will use the sdlx namespace. This is optional, and while
// it is advised to be cautious using namespaces, it is easier for new
// students to learn the library.
using namespace sdlx;

// Constants W, and H
const int W = 640;
const int H = 480;

int min( int a, int b )  
{
    return a < b ? a : b; 
}

void test_event()
{
    // Create a window. It's best to define the width and height as constants
    // in your program. The name is optional. The window will default to
    // 640 x 480 if no width and height are given.
    Window window(W, H, "Test Event");

    // Crate an Event object. It can be used to process events such as
    // a mouse click or a keyboard press. It also checks if the program
    // has been closed.
    Event event;
    bool quit = false;
    while (quit == false)
    {
        // This is your game loop. Generally we only break out if the user
        // closes the program. A common technique is to set a boolean to true
        // if the event.type() == QUIT.
        while (event.poll())
        {
            // This is your event loop. Each frame events are stored in a
            // queue. It's important to poll (or grab) each event until the
            // queue is empty.
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        delay(100); // Wait for 100 milliseconds before continuing.
    }

    // If the program reaches this point, then the user must have closed
    // the program.

    return;
}

/*****************************************************************************
This function show you how to draw a point (basically a dot on the screen).
First you have to create a Window object (you need a window right?). First we
need to create a color. To create a color of (r, g, b) you do this:

    Color c(r, g, b);

The color intensities r, g, b range from 0 to 255.
To put a pixel at location x, y, you do this:

    window.put_pixel(x, y, c); // c being your Color object.

Exercise: r,g,b are 255,255,255 which is white (correct?). Modify this program
to draw pixels with random color.

One thing to note that is that on the computer screen, the x-axis grows to
the right BUT the y-axis grows *downward*.

  0123456789 ...
 +-----------------------------
0|p
1|    r
2|
3| q
4|

p has x = 0, y = 0
q has x = 1, y = 3
r has x = 4, y = 1

WARNING: 
Another thing to note is that if you have a screen of width W, the maximum x
value you can use for drawing a pixel is W - 1. Likewise if the height if H,
the maximum y value is H - 1.

Exercise. Modify the program so that it draw random pixels (x,y) where x and y
are between 0 and 200.
*****************************************************************************/
void test_point()
{
    Window window(W, H, "Test Pixel");
    Event event;

    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        // Create a color.
        Color c;

        // Set color r, g, b.
        c.r = rand() % 255;
        c.g = rand() % 255;
        c.b = rand() % 255;

        // Set point position.
        int x = rand() % 640;
        int y = rand() % 480;

        // Put the point on the window.
        window.put_point(x, y, c);

        // Draw must only be called once at the end of the game loop.
        // Draw will actually render everything you have put on the screen.
        window.draw();
        
        delay(2);
    }
    return;
}

/*****************************************************************************
This function, test_line(), shows you how to draw a line:

    Color c(r, g, b);
    window.put_line(x0, y0, x1, y1, c);

This draws a line on the window from (x0,y0) to (x1,y1) with Color c;

Exercise. Modify the program to draw blue random lines.
*****************************************************************************/

void test_line()
{
    Window window(W, H, "Test Line");
    Event event;

    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        // Create a color using the constructor.
        // Color c(r, g, b);
        Color c(rand() % 256, rand() % 256, rand() % 256);

        // Computation part
        int x0 = rand() % W;
        int y0 = rand() % H;
        int x1 = rand() % W;
        int y1 = rand() % H;

        
        // Drawing part
        window.put_line(x0, y0, x1, y1, c);
        // Remember to call draw at the end of the loop!
        window.draw();

        delay(10);
    }
    return;
}

/*****************************************************************************
This function, test_connected_line(), shows you how to draw a more complex
line.

We can think of a line as a collection of points. You can use any container
you want that can be iterated. In this example we'll use an array.

Note that your collection must have at least two points.

To draw a line connecting 3 points, you do:

Color c;
Point line[3];
line[0].x = (value)
line[0].y = (value)
line[1].x = ...

window.put_line(line, 3, c);

NOTE: the first parameter is a pointer to the collection (in this case the array),
and the second parameter tells the window how many points to connect (Obviously
this number can't be greater than the size of the collection right?).

Exercise. Modify the program to connect 8 points.
*****************************************************************************/

void test_connected_line()
{
    Window window(W, H, "Test Connected Line");
    Event event;

    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        Color c(rand() % 256, rand() % 256, rand() % 256);
        Point line[3];
        // Computation part
        for (int i = 0; i < 3; ++i)
        {
            line[i].x = rand() % W;
            line[i].y = rand() % H;
        }
        
        // Drawing part
        window.put_line(line, 3, c);
        // Remember to call draw at the end of the loop!
        window.draw();

        delay(50);
    }
    return;
}

/*****************************************************************************
This function, test_circle(), shows you how to draw a circle:

Color c(r, g, b);
window.put_circle(x, y, rad, c);

This draws a circle on surface with center at (x,y), radius r, and with color
c.

Exercise. Modify the program to draw circles with radius 10.
*****************************************************************************/

void test_circle()
{
    Window window(W, H, "Test Circle");
    Event event;
    
    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        int x = rand() % W;
        int y = rand() % H;
        int r = rand() % 100 + 10;
        Color c(rand() % 256, rand() % 256, rand() % 256);

        window.put_circle(x, y, r, c);
        window.draw();

        delay(10);
    }
    return;
}

/*****************************************************************************
This function, test_unfilled_circle(), shows you how to draw an unfilled
circle.

This time we'll use the Circle object to store the x, y, and radius.
*****************************************************************************/

void test_unfilled_circle()
{
    Window window(W, H, "Test Unfilled Circle");
    Event event;

    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        Color c(0, rand() % 256, rand() % 256);
        Circle circle;
        circle.x = rand() % W;
        circle.y = rand() % H;
        circle.r = rand() % 100 + 10;

        window.put_unfilled_circle(circle, c);
        window.draw();

        delay(10);
    }
    return;
}

/*****************************************************************************
This function, test_rect(), shows you how to draw a rectangle. 

A Rect is an object that holds a rectangles x, y, width w, and height h.

For instance the following is a rectangle with top-left corner (2,1), width 4
and height 3.

 0123456789...
 +---------------------
0| 
1| xxxx
2| xxxx
3| xxxx
4|

Rect r;  // You better give me some values.
Color c;
surface.put_rect(r, c);

OPTIONAL: if you don't want to create a rect object, this is still ok:
    surface.put_rect(x, y, w, h, color);

*****************************************************************************/
void test_rect()
{
    Window window(W, H, "Test Rect");
    Event event;
    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }
        Rect r;
        r.x = rand() % (W - 1);
        r.y = rand() % (H - 1);
        r.w = rand() % (W - 1 - r.x);
        r.h = rand() % (H - 1 - r.y);
        Color c(rand() % 256, rand() % 256 , rand() % 256);

        window.put_rect(r, c);
        window.draw();

        delay(10);
    }
    return;
}

void test_unfilled_rect()
{
    Window window(W, H, "Test Unfilled Rect");
    Event event;
    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }
        Rect r;
        r.x = rand() % (W - 1);
        r.y = rand() % (H - 1);
        r.w = rand() % (W - 1 - r.x);
        r.h = rand() % (H - 1 - r.y);
        Color c(rand() % 256, rand() % 256 , rand() % 256);

        window.put_unfilled_rect(r, c);
        window.draw();

        delay(10);
    }
    return;
}

/*****************************************************************************
This function shows you how to draw a polygon.

We can thing of a polygon as a collection of points (just like
test_connected_line() above).

Color c;
Point polygon[5]; (you can use any number of points that you want).
polygon[0].x = (value);
polygon[0].y = (value);
polygon[1].x = ...

To put the polygon on the window, call:

    surface.put_polygon(polygon, 5, c);

where the first parameter is a pointer to your collection of points, the
second parameter is the number of points, and the final parameter is the
color.

By now you should know you can also call

    surface.put_unfilled_polygon(polygon, 5, c);

for an unfilled version.

Exercise: modify the code below to draw only triangles.
*****************************************************************************/
void test_polygon()
{
    Window window(W, H, "Test Polygon");
    Event event;

    int n = 500;

    bool quit = false;
    Point polygon[n];
    Color c(0, 0, 0);
    int dx[n], dy[n];

    for (int i = 0; i < n; ++i)
    {
        polygon[i].x = rand() % 640;
        polygon[i].y = rand() % 480;
        dx[i] = rand() % 3 + 1;
        dy[i] = rand() % 3 + 1;
    }

    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (polygon[i].x + dx[i] >= 640
                || polygon[i].x + dx[i] < 0)
            {
                dx[i] *= -1;
                if (c.r < 255) c.r += 1;
                if (c.g < 254) c.g += 2;
                if (c.b < 254) c.b += 2;
            }
            polygon[i].x += dx[i];
            if (polygon[i].y + dy[i] >= 480
                || polygon[i].y + dy[i] < 0)
            {
                dy[i] *= -1;
                if (c.r > 0) c.r -= 1;
                if (c.g > 0) c.g -= 1;
                if (c.b > 0) c.b -= 1;
            }
            polygon[i].y += dy[i];
        }

        // The collection of points.
        window.clear();
        window.put_unfilled_polygon(polygon, n, c);
        window.draw();

        delay(20);
    }
}

/*****************************************************************************
This function, test_key_up_down(), is going to use the event loop to check
when the spacebar is pressed or released.

For a full list of avaliable keys, check Keyboard.h.

In order to check if a key was pressed or released on the previous frame,
we have to check if the event.type() is KEYDOWN or KEYUP. For a full list
of event types, check Event.h.

Each event.type() has a function you can use to get the values. In this
example, if event.type() == KEYDOWN, we can call event.get_key() in order
to fetch the actual key that is pressed. Note: calling event.get_key()
without first checking if the event.type() is KEYUP or KEYDOWN will return
garbage values.

If you don't want to use events to process keyboard input, in the next
example test.keyboard() you will see how to use the Keyboard object to
process key presses.
*****************************************************************************/
void test_key_up_down()
{
    const int MAX_RADIUS = W / 4;

    Rect test;
    Window window(W, H, "Test Key Up / Down");
    Event event;

    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            // Now we can make the event type a switch. An 'if' block would work
            // as well.
            switch (event.type())
            {
                // We know about this one already.
                case QUIT:
                {
                    quit = true;
                    break;
                }
                // KEYDOWN event is if a key is pressed. This includes if a key
                // is held.
                case KEYDOWN:
                {
                    Key key = event.key();
                    if (key == KEY_SPACE)
                    {
                        Color red(255, 0, 0);
                        int x = rand() % W;
                        int y = rand() % H;
                        int r = rand() % MAX_RADIUS + 1; // Radius can't be 0.
                        window.put_circle(x, y, r, red);
                    }
                    break;
                }
                // KEYUP event is if a key is released. This event only occurs
                // on the frame the key is lifted.
                case KEYUP:
                {
                    Key key = event.key();
                    if (key == KEY_SPACE)
                    {
                        Color blue(0, 255, 0);
                        int x = rand() % W;
                        int y = rand() % H;
                        int r = rand() % MAX_RADIUS + 1; // Radius can't be 0.
                        window.put_circle(x, y, r, blue);
                    }
                    break;
                }
            }
        }
        window.draw();        
        delay(10);
    }
}

/*****************************************************************************
This function, test_keyboard(), shows you how to check keyboard inputs using
the Keyboard object.

    Keyboard keyboard;

When this function is running, press and release the left arrow key. The 
statement

    keyboard.down(KEY_LEFT);

is true if the left arrow key is down.
Try pressing the right arrow. The statement

    keyboard.pressed(KEY_RIGHT);

is true only on the frame the key is pressed. Do note by calling the pressed
function, the keyboard object will update internally. For each key, pressed
can only return true once per frame.

IMPORTANT: The Keyboard object can be used outside of the event loop.

*****************************************************************************/
void test_keyboard()
{
    Window window(W, H, "Test Keyboard");
    Event event;
    Keyboard keyboard;

    int rad = 1;

    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }
        // Check if the left arrow is down. If so, put a random ellipse on the
        // screen.
        if (keyboard.down(KEY_LEFT))
        {
            Color c;
            c.r = rand() % 256;
            c.g = rand() % 256;
            c.b = rand() % 256;
            c.a = rand() % 256; // control color shading. set to 255 by default.

            Ellipse e;
            e.x  = rand() % 640;
            e.y  = rand() % 480;
            e.rx = rand() % 100 + 1;
            e.ry = rand() % 100 + 1;

            window.put_ellipse(e, c);
        }
        // Check if the right arrow is pressed. If so, put a random ellipse on the
        // screen. See the difference between 'down' and 'pressed'.
        if (keyboard.pressed(KEY_RIGHT))
        {
            Color c;
            c.r = rand() % 256;
            c.g = rand() % 256;
            c.b = rand() % 256;
            c.a = rand() % 256; // control color shading. set to 255 by default.

            Ellipse e;
            e.x  = rand() % 640;
            e.y  = rand() % 480;
            e.rx = rand() % 100 + 1;
            e.ry = rand() % 100 + 1;

            window.put_ellipse(e, c);
        }

        window.draw();
        delay(10);
    }
    return;
}

void fancyhelloworld()
{
    Window window;
    Sound sound("sounds/laser.wav");
    Music music("sounds/GameLoop.ogg");
    music.play();
    Event event;

    Font font("fonts/FreeSans.ttf", 48);
    Image image("hello world", font, WHITE, window);
    Rect rect = image.get_rect();

    int r = 0;
    int g = 0;
    int b = 255;
    int dr = 1;
    int dg = 2;
    int db = 3;
    Color c(0, 100, 200);

    int dx = 2;
    int dy = 3;

    int RATE = 1000 / 60;

    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        int start = get_ticks();

        r += dr;
        if (r < 0)
        {
            r = 0;
            dr = - dr;
        }
        else if (r > 255)
        {
            r = 255;
            dr = -dr;
        }

        g += dg;
        if (g < 0)
        {
            g = 0;
            dg = - dg;
        }
        else if (g > 255)
        {
            g = 255;
            dg = -dg;
        }

        b += db;
        if (b < 0)
        {
            b = 0;
            db = -db;
        }
        else if (b > 255)
        {
            b = 255;
            db = -db;
        }
        Color c(r, g, b);
        Image image("hello world", font, c, window);

        rect.x += dx;
        if (rect.x < 0)
        {
            sound.play();
            rect.x = 0;
            dx = -dx;
        }
        else if (rect.x + rect.w > W - 1)
        {
            sound.play();
            rect.x = W - 1 - rect.w;
            dx = -dx;
        }

        rect.y += dy;
        if (rect.y < 0)
        {
            sound.play();
            rect.y = 0;
            dy = -dy;
        }
        else if (rect.y + rect.h > H - 1)
        {
            sound.play();
            rect.y = H - 1 - rect.h;
            dy = -dy;
        }

        window.clear(BLACK);
        window.put_image(image, rect);
        window.draw();

        int end = get_ticks();
        int dt = RATE - end + start;
        if (dt > 0) delay(dt);
    }
    return;
}



/*****************************************************************************
This function, test_image(), shows you how to load and draw and image.

The statement

    Image image("images/galaxian/GalaxianAquaAlien.gif", window);

creates an Image object, image, from a graphics image file. 'window' is
just the name of your Window object.

The statement 

    Rect rect = image.get_rect();

give you a Rect variable (object) with rect.x = 0, rect.y = 0 and rect.w and 
rect.h are the width and height of the image. rect is an object containing
4 variable x, y, w, h. The x in rect is called rect.x; the y in rect is called 
rect.y.

Another function in window that is helpful is the clear() function.

    window.clear(BLACK);

will fill the whole window with BLACK color. This is like clearing the 
whole window (if your background is black). If your background is red you
can paint the whole window red like this:

    Color red(255, 0, 0);
    window.clear(red);

Exercise. Change the background to your favorite color.

Exercise. Make the alien bug move at twice its speed.

Exercise. Make the alien bug stop when it hits the right wall.

Exercise. Make the alien bug move backward when it hits the right wall.
Hint: Suppose this is the window and the rect where you want to put the 
image.

... ------------+
                |
        XXXX    |
        XXXX    |
                |

The top-left of the rect is rect.x. The top-RIGHT of the rect is rect.x + 
rect.w.

Exercise. Make the alien bug move forward and backward between the left and 
right wall.

Exercise. Make the alien bug move in both the x and y direction within the
window.
*****************************************************************************/

void test_image()
{
    Window window;
    Event event;

    Image image("images/galaxian/GalaxianAquaAlien.gif", window);// loads image

    Rect rect = image.get_rect();
    
    int dx = 1;
    int dy = 0;
    
    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        if (event.type() == QUIT)
        {
            quit = true;
            break;
        }

        rect.x += dx;
        
        if (rect.x > 400)
        {
            dx = -1;
        }
        else if (rect.x < 0)
        {
            dx = 1;
        }
        
        window.clear(BLACK);
        window.put_image(image, rect); // put image on the window.
        window.draw();

        SDL_Delay(20);
    }
    return;
}


/*****************************************************************************
This function shows you how to play sound and music.
*****************************************************************************/
void test_sound()
{
    Window window(W, H, "Test Sound");
    Sound sound("sounds/laser.wav");        // create sound object from file
    Music music("sounds/GameLoop.ogg");     // create music object from file
    music.play();                           // loop over music
    Event event;

    bool quit = false;
    while (!quit)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        if (rand() < 100) 
        {
            sound.play(); // play sound randomly
        }
        delay(10);
    }
}

/*****************************************************************************
This function, helloworld(), shows you how to create an image from a font
file.

The statement

    Font font("fonts/FreeSans.ttf", 48);

creates a font object. 

The statement following statement creates an image using the font object.

    Color c(0, 0, 255); // color with red = 0, green = 0, blue = 255
    Image image("hello world", font, c, window);

You can of course change the string to whatever you need. The color variable
c can also be changed.

Exercise. Print a different message using a different font file, a different
color and a different size.
*****************************************************************************/
void helloworld()
{
    Window window(W, H, "Hello World!");
    Event event;

    Font font("fonts/FreeMonoBold.ttf", 72);
    Color c(0, 255, 255);
    Image image("Hello World!", font, c, window);
    Rect rect = image.get_rect();

    // Initially rect has x = 0, y = 0
    // Let's move it.
    rect.x = 10;
    rect.y = 10;


    bool quit = false;
    while (!quit)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }
        window.put_image(image, rect);
        window.draw();
    }

    delay(100);

    return;
}

/******************************************************************************

    A Mouse object keeps track of all of the mouse input information.
    You can read the x,y position of the mouse at any time (outside
    the event loop!).
    You can read the state of the mouse buttons at any time.

    Mouse mouse;
    - mouse.get_x(): the x-coordinate of the mouse cursor
    - mouse.get_y(): the y-coordinate of the mouse cursor
    - mouse.down(BUTTON_LEFT): true iff the left mouse button is down
    - mouse.pressed(BUTTON_LEFT) : true iff the left mouse button was pressed

    Instead of read the x,y, and button states in every single game loop,
    sometimes you can to read them only when the mouse is moved or when the
    button is pressed and released, i.e., when there's a mouse motion
    or mouse button event.
    - event.type() == MOUSEMOTION is true when the mouse is moved
    - event.type() == MOUSEBUTTONDOWN is true when a mouse button is pressed.

 *****************************************************************************/
void test_mouse()
{
    const int FONTSIZE = 24;
    Window window(W, H, "Test Mouse");
    Event event;
    Mouse mouse;
    Font font("fonts/FreeSans.ttf", FONTSIZE);
    
    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
        }

        std::stringstream out1;
        out1 << "x:" << mouse.get_x() << " y:" << mouse.get_y();
        Image image1(out1.str(), font, WHITE, window);
        Rect rect1 = image1.get_rect();

        std::stringstream out2;
        out2 << "leftbutton:"    << mouse.down(BUTTON_LEFT)
             << " middlebutton:" << mouse.down(BUTTON_MIDDLE)
             << " rightbutton:"  << mouse.down(BUTTON_RIGHT);
        Image image2(out2.str(), font, WHITE, window);
        Rect rect2 = image2.get_rect();
        rect2.y = FONTSIZE + 5;
        
        window.clear(BLACK);
        window.put_image(image1, rect1);
        window.put_image(image2, rect2);
        window.draw();

        delay(20);
    }
}

/******************************************************************************
    Instead of read the x,y, and button states in every single game loop,
    sometimes you can to read them only when the mouse is moved or when the
    button is pressed or released, i.e., when there's a mouse motion
    or mouse button event. Here's how to check for mouse motion event or mouse
    button pressed/released event:
    - event.type() == MOUSEMOTION is true when the mouse is moved
    - event.type() == MOUSEBUTTONDOWN is true when a mouse button is pressed
    - event.type() == MOUSEBUTTONUP is true when a mouse button is released

    After a MOUSEMOTION event, you can create a Motion object. Like this:
    Motion motion = event.motion();
        motion.x() - x position
        motion.y() - y position
        motion.dx() - distance moved on x-axis
        motion.dy() - distance moved on y-axis

    After a MOUSEBUTTONDOWN or MOUSEBUTTONUP you can create a BUTTON object.
    Like this:
        button == BUTTON_LEFT is true iff the left mouse button was pressed.
        button.x() - x position of mouse when pressed
        button.y() - y position of mouse when pressed
        button.double_click() - was it a double click ?
 *****************************************************************************/

void test_mouse_event()
{
    Window window(W, H, "Test Mouse Event");
    Event event;
    
    bool quit = false;
    while (quit == false)
    {
        while (event.poll())
        { 
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
            else if (event.type() == MOUSEMOTION)
            {
                Motion motion = event.motion();
                Circle cir;
                cir.x = motion.x();
                cir.y = motion.y();
                cir.r = rand() % 20 + 1;

                if (cir.x < 0 || cir.x >= W || cir.y < 0 || cir.y >= 480)
                    continue;

                Color c(rand() % 256, rand() % 256, rand() % 256);

                window.put_circle(cir, c);
            }
            else if (event.type() == MOUSEBUTTONDOWN)
            {
                Button button = event.button();
                Circle cir;
                cir.x = rand() % 640;
                cir.y = rand() % 480;
                cir.r = rand() % 20 + 1;
                if (button == BUTTON_LEFT)
                {
                    if (button.double_click())
                    {
                        window.put_circle(cir, GREEN);
                    }
                    else
                    {
                        window.put_circle(cir, BLUE);
                    }
                }
                else if (button == BUTTON_MIDDLE)
                {
                    window.clear(BLACK);
                }
                else if (button == BUTTON_RIGHT)
                {
                    if (button.double_click())
                    {
                        window.put_circle(cir, ORANGE);
                    }
                    else
                    {
                        window.put_circle(cir, YELLOW);
                    }
                }
            }
        }

        window.draw();
        delay(10);
    }
}

/******************************************************************************
 This is an example on using the mouse to perform drag-n-drop.
 *****************************************************************************/
void test_drag_n_drop()
{
    const int FONTSIZE = 24;
    Window window(W, H, "Test Drag and Drop");
    Font font("fonts/FreeSans.ttf", FONTSIZE);
    Event event;
    Mouse mouse;

    int x = 100, y = 100, w = 100, h = 100;
    bool move = false; // true iff the square is moving with the mouse

    std::stringstream out;
    out << "drag-n-drop sim: click on mouse to pick up/put down";
    Color c(255, 255, 255);
    Image helpimage(out.str(), font, c, window);
    //Image helpimage(font.render(out.str().c_str(), c));
    Rect helprect = helpimage.get_rect();
    
    bool quit = false;
    while (quit == false)
    {
        std::stringstream out;
        while (event.poll())
        { 
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
            else if (event.type() == MOUSEMOTION)
            {
                Motion motion = event.motion();
                if (move)
                {
                    x = motion.x();
                    y = motion.y();
                }
            }
            else if (event.type() == MOUSEBUTTONDOWN)
            {
                // do nothing ... pick up and put down
                // happens only when the button is released
            }
            else if (event.type() == MOUSEBUTTONUP)
            {
                Button button = event.button();
                int mousex = button.x();
                int mousey = button.y();
                if (x <= mousex && mousex <= x + w
                    && y <= mousey && mousey <= y + h)
                {
                    move = !move;
                }
            }
        }

        window.clear(BLACK);
        if (move)
        {            
            window.put_rect(x, y, w, h, 100, 100, 100);
        }
        else
        {
            window.put_rect(x, y, w, h, 255, 255, 255);
        }
        window.put_image(helpimage, helprect);
        window.draw();

        delay(10);
    }
}

/******************************************************************************
This function, test_touch_event, shows you how to test a touch screen event.
 *****************************************************************************/

void test_touch_event()
{
    Window window(W, H, "Test Touch Event");
    Event event;    

    bool quit = false;
    while (!quit)
    {
        while (event.poll())
        {
            if (event.type() == QUIT)
            {
                quit = true;
                break;
            }
            else if (event.type() == FINGERDOWN)
            {
                // Create finger object.
                Finger finger = event.finger();
                Color c(rand() % 256, rand() % 256, rand() % 256);
                int rad = rand() % 20 + 1;
                // Finger x and y is normalized to the range 0 .. 1. So we
                // need to multiply them by the W and H of the screen to
                // get the correct location.
                window.put_circle(finger.x() * W, finger.y() * H, rad, c);
            }
        }
        window.draw();
        delay(20);
    }
}

/*****************************************************************************
For our programs involving graphics and sound, the template is this:

int main(int argc, char* argv[])
{
    ... PROGRAM ...

    return 0;
}

Our main() is made up of calling various functions. This is the first time you
are actually seeing the *code* of functions. Before this, you have been 
*using* functions, i.e. *calling* the functions.

For instance the first function call is

    test_event();

When you run this program, the program will execute a function call to 
test_event(). This means that the program will look for "text_event" and 
execute the code until it sees the statement "return". Executing return
will cause the program to go back to where it came from.

After running the program, comment out the call to test_event(), uncomment
the call to test_pixel() and run the program. Etc.
*****************************************************************************/
int main(int argc, char* argv[])
{
    test_event();
    test_point();
    test_line();
    test_connected_line();
    test_circle();
    test_unfilled_circle();
    test_rect();
    test_unfilled_rect();
    test_polygon();
    test_image();
    helloworld(); // Of course we must have a hello world right?
    test_key_up_down();
    test_keyboard();
    test_sound();
    fancyhelloworld();

    // mouse
    test_mouse();
    test_mouse_event();
    test_drag_n_drop();

    test_touch_event();
    
    return 0;
}
