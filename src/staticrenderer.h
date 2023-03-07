#ifndef STATICRENDERER_H
#define STATICRENDERER_H

#include <vector>
#include "renderer.h"
#include "SDL.h"
#include <string>

class StaticRenderer : Renderer
{
public:
    StaticRenderer(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer,
                const std::size_t screen_width, const std::size_t screen_height,
                const std::size_t grid_width, const std::size_t grid_height);

    void Render(const char * bmpFileName);
    void Wait();

private:
    const char * bmpFileName;
};

#endif