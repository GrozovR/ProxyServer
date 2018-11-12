#include <QCoreApplication>

#include "proxyserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try {

        ip::address inputAddress;
        int inputPort{ 0 };

        if(argc > 2){
            inputAddress = ip::address::from_string(argv[1]);
            inputPort = atoi(argv[2]); //port for connect
        }

        unsigned int cores = std::thread::hardware_concurrency();

        ip::tcp::endpoint ep(inputAddress , inputPort);

        io_service service;
        io_context io_context; // input output os
        io_context.run();


    } catch (std::exception& e) {
        //std::cerr
    }

    return a.exec();
}
