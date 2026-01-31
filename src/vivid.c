#include "vivid.h"


void VE_Init(void) {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  int VE_WINDOW_X = 960;
  int VE_WINDOW_Y = 720;
  SDL_Window* VE_WINDOW = SDL_CreateWindow("VividEngine", VE_WINDOW_X, VE_WINDOW_Y, SDL_WINDOW_RESIZABLE);
  bool VE_RUNNING = true;
  SDL_Event VE_EVENT;
}

TTF_Font* VE_Font(const char* font_name, int font_size) {
  if(!font_name || !font_size) return NULL;
  return TTF_OpenFont(font_name, font_size);
}

int VE_SetIcon(const char* icon_path) {
  if(!icon_path) return 1;
  SDL_Surface* icon = IMG_Load(icon_path);
  SDL_SetWindowIcon(VE_WINDOW, icon);
  SDL_DestroySurface(icon);
  return 0;
}

void VE_Quit(void) {
  SDL_Quit();
  TTF_Quit();
}

void VE_PollEvent() {
  while(SDL_PollEvent(&VE_EVENT)) {
    switch(VE_EVENT.type) {
      case SDL_EVENT_QUIT:
        VE_RUNNING = false;
        break;
      case SDL_EVENT_WINDOW_RESIZED:
        VE_WINDOW_X = VE_EVENT.window.data1;
        VE_WINDOW_Y = VE_EVENT.window.data2;
        break;
    }
  }
}