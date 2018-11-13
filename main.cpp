#include <iostream>
#include "proxyserver.h"

int main(int argc, char *argv[])
{
    try {

        ip::address inputAddress;
        int inputPort{ 0 };

        if(argc > 2){
            inputAddress = ip::address::from_string(argv[1]);
            inputPort = atoi(argv[2]); //port for connect
        }

        unsigned int cores = std::thread::hardware_concurrency();

        ip::tcp::endpoint ep(inputAddress, inputPort);

        io_context ioContext; // input output os

        //ProxyServer prxServer(ioContext);
        ioContext.run();


    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
