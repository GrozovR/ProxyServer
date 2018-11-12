#include <QCoreApplication>
//#include <../libs/boost_1_68_0/boost/asio/impl/src.hpp>
#include <../libs/boost/boost/asio.hpp>

using namespace boost::asio;

int main(int argc, char *argv[])
{


    try {

    } catch (std::exception& e) {
        //std::printf()
    }


    QCoreApplication a(argc, argv);

    io_service service;


    int inputPort; //port for connect
    ip::address inputAddress; //input address, line params
    ip::tcp::endpoint ep(inputAddress , 80);

    io_context io_context; // input output os
    io_context.run();

    return a.exec();
}
