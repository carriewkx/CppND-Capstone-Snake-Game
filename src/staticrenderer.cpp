#include "staticrenderer.h"
#include <iostream>
#include <string>

StaticRenderer::StaticRenderer(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer,
                               const std::size_t screen_width, const std::size_t screen_height,
                               const std::size_t grid_width, const std::size_t grid_height)
    : Renderer(sdl_window, sdl_renderer, screen_width, screen_height, grid_width, grid_height)
{
}

void StaticRenderer::Render(const char *bmpFileName)
{
    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render start bitmap
    SDL_Rect block;
    block.x = 0;
    block.y = 0;
    block.w = screen_width;
    block.h = screen_height;
    SDL_Surface *surface = SDL_LoadBMP(bmpFileName);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
    SDL_RenderCopy(sdl_renderer, texture, NULL, &block);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void StaticRenderer::Wait()
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    bool running = true;
    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
            if (elapsed.count() > 1000) {
                if (e.type == SDL_QUIT || e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN)
                {
                    running = false;
                }
            }
        }
    }
}
