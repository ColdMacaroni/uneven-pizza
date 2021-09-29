#include <stdio.h>
#include <stdlib.h>

#include <raylib.h>

#ifndef WIN_WIDTH
#define WIN_WIDTH 400
#endif

#ifndef WIN_HEIGHT
#define WIN_HEIGHT 400
#endif

typedef
struct xy
{
    int x;
    int y;
} xy;

int
main(int argc, char **argv)
{
    /* def circle params
     *      radius
     *      xy of center
     *
     * def num slices. Evenly distribute through circumference. (2pi)/num slices.
     *
     * Get a random value 0 <= x <= 2pi, get a random value 0 < x < radius. Polar coords?
     *
     * Connect edges of the slices to the random centre.
     */

    const unsigned int r = 40;
    const xy centre = { 100, 100 };

    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Why");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(WHITE);

            // Draw
        EndDrawing();
    }

    CloseWindow();

    // TO DO: Add pizza drawing
    // EXTENSION: oval pizza

    return 0;
}
