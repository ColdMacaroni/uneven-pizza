#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// For pi
#define _USE_MATH_DEFINES
#include <math.h>

#include <raylib.h>

#ifndef WIN_WIDTH
#define WIN_WIDTH 460
#endif

#ifndef WIN_HEIGHT
#define WIN_HEIGHT 460
#endif

float rand_float(float min, float max);
Vector2 *gen_slices(const Vector2 centre, const float r, const int num_slices);
Vector2 rand_pt_circle(const Vector2 centre, const float r);

int
main(int argc, char **argv)
{
    // TO DO: Add pizza drawing
    // EXTENSION: oval pizza

    srand((unsigned)time(NULL));


    // Get num slices from cli arg
    int _slices;

    if (argc > 1)
        _slices = atoi(argv[1]);
    else
        _slices = 8;

    const int num_slices = _slices;

    const float r = (fminf(WIN_HEIGHT, WIN_HEIGHT) / 2)-20;
    const Vector2 centre = { WIN_WIDTH / 2, WIN_HEIGHT / 2 };

    // Generate slices at circumference
    Vector2 *slices = gen_slices(centre, r, num_slices);

    // Get a new center
    Vector2 bad_centre = rand_pt_circle(centre, r);

    SetTargetFPS(60);

    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Why");
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(WHITE);
            DrawCircleLines(centre.x, centre.y, r, BLACK);

            for (int i = 0; i < num_slices; i++)
                DrawLineV(slices[i], bad_centre, BLACK);

        EndDrawing();
        if (IsKeyPressed(KEY_SPACE))
        {
            // Create new pizza
            free(slices);
            slices = gen_slices(centre, r, num_slices);
            bad_centre = rand_pt_circle(centre, r);
        }
    }
    CloseWindow();

    free(slices);

    return 0;
}

float rand_float(const float min, const float max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);

}

Vector2 *gen_slices(const Vector2 centre, const float r, const int num_slices)
{
    Vector2 *slices = calloc(sizeof(Vector2), num_slices);

    // The diff in radians between each slice.
    const double offset = (2 * M_PI) / num_slices;

    for (int i = 0; i < num_slices; i++)
    {
        float uneven = rand_float(0, offset) - offset*2/3;
        slices[i] = (Vector2){
            centre.x + r * cos(offset * i + uneven),
            centre.y + r * sin(offset * i + uneven)
        };
    }

    return slices;
}

Vector2 rand_pt_circle(const Vector2 centre, const float r)
{
    /* Generates a random point inside a circle */
    const float rad = rand_float(0, M_PI*2);

    const float x = rand_float(0, 1);
    /* const float dist = r * 6 * (pow(x - 1, 3) + pow(x - 1, 2)) + 0.05; */
    /* const float dist = r * ((pow(x - 0.5, 2) * 3) / 4 + 0.25); */
    const float dist = r * (pow(x - 0.55, 2) / 4 + 0.1);

    return (Vector2){
            centre.x + dist * cos(rad),
            centre.y + dist * sin(rad)
    };
}
