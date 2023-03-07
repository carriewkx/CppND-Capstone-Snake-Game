#include <iostream>
#include "controller.h"
#include "game.h"
#include "helper.h"

int main()
{
    Helper helper;
    double diff = -1.0;
    while (diff < 0){
      helper.ReadUserInput(diff);
    }
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{16};
    constexpr std::size_t kGridHeight{16};

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    SDL_Window *sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED, kScreenWidth,
                                              kScreenHeight, SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window)
    {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    SDL_Renderer *sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == sdl_renderer)
    {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    PlayRenderer playRenderer(sdl_window, sdl_renderer, kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    StaticRenderer staticRenderer(sdl_window, sdl_renderer, kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);

    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, staticRenderer, playRenderer, kMsPerFrame, diff);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    return 0;
}