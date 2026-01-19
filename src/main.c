#include <SDL3/SDL.h>

int main(void) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow(
    "Title",
    480,
    360,
    SDL_WINDOW_RESIZABLE
  );
  int running = 1;
  SDL_Event event;
  while(running) {
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
        case SDL_EVENT_QUIT:
          running = 0;
          break;
      }
    }
    SDL_Delay(16);
  }
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
