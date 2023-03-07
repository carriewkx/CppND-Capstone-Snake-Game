#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "snake.h"
#include <memory>

class Renderer
{
public:
    Renderer(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer,
             const std::size_t screen_width, const std::size_t screen_height,
             const std::size_t grid_width, const std::size_t grid_height);
    virtual ~Renderer(){};

    virtual void Render(){};
    virtual void UpdateWindowTitle(){};

protected:
    SDL_Window *sdl_window;
    SDL_Renderer *sdl_renderer;

    const std::size_t screen_width;
    const std::size_t screen_height;
    const std::size_t grid_width;
    const std::size_t grid_height;
};

#endif