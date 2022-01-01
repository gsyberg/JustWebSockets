#include "JustWebSocket.h"
#include "Utils.h"

#include <iostream>

constexpr unsigned short int s_defaultPort = 3000;

int main(int argc, char * argv[])
{
    unsigned short int port = s_defaultPort;

    if (argc > 1)
    {
        int suppliedPort = atoi(argv[1]);
        if (suppliedPort < 0 || suppliedPort > 65535)
        {
            std::cout << "Supplied port is out of range. Using default port.\n";
        }
        else
        {
            port = suppliedPort;
        }
    }

    std::cout << jw::Utils::getLogo() << "Just WebSockets server starting.\n";

	jw::JustWebSocket webSocket(port);
	webSocket.run();

    return 0;
}