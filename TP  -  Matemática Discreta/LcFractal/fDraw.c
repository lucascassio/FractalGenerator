#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define LINE_LENGTH 5
#define ANGLE_INCREMENT 90
#define M_PI 3.14159265358979323846264338327

void drawFractal(SDL_Renderer* renderer, const char* fractal)
{
    int x = WINDOW_WIDTH / 2;
    int y = WINDOW_HEIGHT / 2;
    int angle = 0;

    for (int i = 0; fractal[i] != '\0'; i++) {
        switch (fractal[i]) {
            case 'F':
                // Calculate the endpoint of the line
                int dx = LINE_LENGTH * cos(angle * M_PI / 180);
                int dy = LINE_LENGTH * sin(angle * M_PI / 180);
                int x2 = x + dx;
                int y2 = y + dy;

                // Draw the line
                SDL_RenderDrawLine(renderer, x, y, x2, y2);

                // Update the current position
                x = x2;
                y = y2;
                break;
            case '+':
                angle += ANGLE_INCREMENT;
                break;
            case '-':
                angle -= ANGLE_INCREMENT;
                break;
            default:
                // Ignore other characters
                break;
        }
    }
}

int main()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Failed to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (window == NULL) {
        printf("Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Set the drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Clear the renderer
    SDL_RenderClear(renderer);

    // Read the fractal final from the file
    FILE* fp = fopen("fractal.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    char line[1000000];
    char fractal[1000000] = {0};

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "Fractal Final:") != NULL) {
            // Read the fractal final string
            fgets(fractal, sizeof(fractal), fp);
            break;
        }
    }

    fclose(fp);

    // Draw the fractal
    drawFractal(renderer, fractal);

    // Present the rendered image to the screen
    SDL_RenderPresent(renderer);

    // Wait for the user to close the window
    SDL_Event event;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }
    }

    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
