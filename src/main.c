#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int main(void) {
  SDL_version sdlver;
  SDL_VERSION(&sdlver);
  printf("Compiled against SDL version %d.%d.%d\n", sdlver.major, sdlver.minor, sdlver.patch);
  printf("Hello from the VividEngine team!");
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow(
    "VividEngine",
    480,
    360,
    SDL_WINDOW_RESIZABLE
  );
  int running = 1;
  SDL_Surface* icon = IMG_Load("icon_tr.png");
  SDL_SetWindowIcon(window, icon);
  SDL_DestroySurface(icon);
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
