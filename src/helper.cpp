#include <iostream>
#include <SDL2/SDL.h>
#include "helper.h"

using namespace std;

void Helper::errorMessage(const char* failure) {
    cout << failure << " failed to initialize. Error: " << SDL_GetError() << endl;
}