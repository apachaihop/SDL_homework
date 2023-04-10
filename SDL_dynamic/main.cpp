#include <iostream>
#include <sstream>
#include <string>

#include <SDL.h>
#include <SDL_messagebox.h>
#include <SDL_version.h>

#define WIDTH 800
#define HEIGHT 600

std::string version_message(const SDL_version c, const SDL_version l)
{
    std::ostringstream os;
    os << "Compiled: " << static_cast<int>(c.major) << '.';
    os << static_cast<int>(c.minor) << '.';
    os << static_cast<int>(c.patch) << std::endl
       << "Linked: " << static_cast<int>(l.major) << '.'
       << static_cast<int>(l.minor) << '.' << static_cast<int>(l.patch);

    return os.str();
}

int main(int /*argc*/, char* /*argv*/[])
{
    using namespace std;

    SDL_version compiled = { 0, 0, 0 };
    SDL_version linked   = { 0, 0, 0 };
    SDL_Window* window   = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        cerr << "SDL video failed to initialise: %s\n" << SDL_GetError();
        return 1;
    }

    SDL_VERSION(&compiled)
    SDL_GetVersion(&linked);
    window = SDL_CreateWindow("SDL_version", WIDTH, HEIGHT, 0);

    if (window == NULL)
    {
        cerr << "SDL window failed to initialise: %s\n" << SDL_GetError();
        return 1;
    }

    if (SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
                                 "version",
                                 version_message(compiled, linked).c_str(),
                                 window))
    {
        cerr << "Can'not view message box" << SDL_GetError();
        return 1;
    }
    return 0;
}
