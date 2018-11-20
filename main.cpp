#include <iostream>
#include "proxyserver.h"

int main(int argc, char *argv[])
{
    try {

        if(argc != 3){
            std::cerr << "Usage: proxy_server <local host ip> <port>\n";
            return  1;
        }

        const std::string local_host = argv[1];
        const unsigned short local_port = static_cast<unsigned short>(::atoi(argv[2]));

        const unsigned int cores = std::thread::hardware_concurrency();

        //TODO: all io_contxt must be in diff threads
        std::vector<std::shared_ptr<io_context>> contxtVector;

        for(size_t i{ 0 }; i < cores; i++){

            std::shared_ptr<io_context> ioContxt(new io_context);
            contxtVector.push_back(ioContxt);
        }        

        ProxyServer prxServer(contxtVector, local_host, local_port);
        prxServer.accepteConnections();

    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
