#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include <SDL_version.h>

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

    SDL_VERSION(&compiled)
    SDL_GetVersion(&linked);

    cout<<version_message(compiled,linked);

    bool is_good = cout.good();

    int result = is_good ? EXIT_SUCCESS : EXIT_FAILURE;
    return result;
}
