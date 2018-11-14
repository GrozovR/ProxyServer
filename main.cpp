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
        thread_pool thr_pool(cores);

        for(size_t i{ 0 }; i < cores; i++){

            std::shared_ptr<io_context> ioContxt(new io_context);

        }

        ip::tcp::endpoint ep(inputAddress, inputPort);

        ios_deque
        io_context ioContext; // input output os

        //ProxyServer prxServer(ioContext);
        ioContext.run();


    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
