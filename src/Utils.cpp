#include "Utils.h"

#include <string>
#include <sys/stat.h>

namespace jw
{

constexpr char jwLogo[] = 
"\n"
"          JJJJJJJJJJJWWWWWWWW                           WWWWWWWW\n"
"          J:::::::::JW::::::W                           W::::::W\n"
"          J:::::::::JW::::::W                           W::::::W\n"
"          JJ:::::::JJW::::::W                           W::::::W\n"
"            J:::::J   W:::::W           WWWWW           W:::::W \n"
"            J:::::J    W:::::W         W:::::W         W:::::W  \n"
"            J:::::J     W:::::W       W:::::::W       W:::::W   \n"
"            J:::::j      W:::::W     W:::::::::W     W:::::W    \n"
"            J:::::J       W:::::W   W:::::W:::::W   W:::::W     \n"
"JJJJJJJ     J:::::J        W:::::W W:::::W W:::::W W:::::W      \n"
"J:::::J     J:::::J         W:::::W:::::W   W:::::W:::::W       \n"
"J::::::J   J::::::J          W:::::::::W     W:::::::::W        \n"
"J:::::::JJJ:::::::J           W:::::::W       W:::::::W         \n"
" JJ:::::::::::::JJ             W:::::W         W:::::W          \n"
"   JJ:::::::::JJ                W:::W           W:::W           \n"
"     JJJJJJJJJ                   WWW             WWW            \n\n";

bool Utils::fileExists(const std::string& path)
{
    struct stat buffer;

    return (stat(path.c_str(), &buffer) == 0);
}

const char* Utils::getLogo()
{
    return jwLogo;
}

} // namespace jw