#include <QCoreApplication>
//#include <../libs/boost_1_68_0/boost/asio/impl/src.hpp>
#include <../libs/boost/boost/asio.hpp>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    boost::asio::io_context io_context;
    io_context.run();

    return a.exec();
}
