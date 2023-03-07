#include "playrenderer.h"
#include <iostream>
#include <string>

PlayRenderer::PlayRenderer(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer,
                           const std::size_t screen_width, const std::size_t screen_height,
                           const std::size_t grid_width, const std::size_t grid_height)
    : Renderer(sdl_window, sdl_renderer, screen_width, screen_height, grid_width, grid_height)
{
}

void PlayRenderer::Render(Snake const snake, SDL_Point const &food)
{
    SDL_Rect block;
    block.w = screen_width / grid_width;
    block.h = screen_height / grid_height;

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Render food
    block.x = food.x * block.w;
    block.y = food.y * block.h;
    SDL_Surface *food_surface = SDL_LoadBMP("../textures/food.bmp");
    SDL_Texture *food_texture = SDL_CreateTextureFromSurface(sdl_renderer, food_surface);
    SDL_RenderCopy(sdl_renderer, food_texture, NULL, &block);

    // Render snake's body
    SDL_SetRenderDrawColor(sdl_renderer, 0x50, 0xC8, 0x78, 0xFF);
    for (SDL_Point const &point : snake.body)
    {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;
    if (snake.alive)
    {
        SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x80, 0x00, 0xFF);
    }
    else
    {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    SDL_RenderFillRect(sdl_renderer, &block);

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void PlayRenderer::UpdateWindowTitle(int score, int fps)
{
    std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
    SDL_SetWindowTitle(sdl_window, title.c_str());
}
