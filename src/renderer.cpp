#include "renderer.h"

Renderer::Renderer(SDL_Window *sdl_window, SDL_Renderer *sdl_renderer,
                   const std::size_t screen_width, const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : sdl_window(sdl_window),
      sdl_renderer(sdl_renderer),
      screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
{
    // nothing to do
}
