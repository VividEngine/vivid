#include "vivid.h"

int VE_WINDOW_X = 0;
int VE_WINDOW_Y = 0;
SDL_Window* VE_WINDOW;
bool VE_RUNNING = false;
SDL_Event VE_EVENT;

void VE_Init(void) {
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();
  VE_WINDOW_X = 960;
  VE_WINDOW_Y = 720;
  VE_WINDOW = SDL_CreateWindow("VividEngine", VE_WINDOW_X, VE_WINDOW_Y, SDL_WINDOW_RESIZABLE);
  VE_RUNNING = true;
  if(!VE_WINDOW_X || !VE_WINDOW_Y || !VE_WINDOW || !VE_RUNNING) VE_Exception("VE_Init: Initialisation failure");
}

TTF_Font* VE_Font(const char* font_name, int font_size) {
  if(!font_name || !font_size) VE_Exception("VE_Font: Parameter error");
  TTF_Font* font = TTF_OpenFont(font_name, font_size);
  if(!font) VE_Exception("VE_Font: Generic failure");
}

void VE_SetIcon(const char* icon_path) {
  if(!icon_path) VE_Exception("VE_SetIcon: Parameter error");
  SDL_Surface* icon = IMG_Load(icon_path);
  if(!icon) VE_Exception("VE_SetIcon: Failure loading icon");
  if(!VE_WINDOW) VE_Exception("VE_SetIcon: Window not found");
  SDL_SetWindowIcon(VE_WINDOW, icon);
  SDL_DestroySurface(icon);
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
        if(VE_WINDOW_X != VE_EVENT.window.data1 || VE_WINDOW_Y != VE_EVENT.window.data2) VE_Exception("VE_PollEvent: Failure setting window data");
        break;
    }
  }
}

void VE_Exception(const char* message) {
  if(!message) VE_Exception("VE_Exception: Parameter error");
  SDL_Log(message);
  VE_RUNNING = false;
}