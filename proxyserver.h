#ifndef PROXYSERVER_H
#define PROXYSERVER_H
#include <../libs/boost/boost/asio.hpp>

class ProxyServer
{
public:
    ProxyServer();

private::
    void connect();

    boost::asio::ip::tcp::socket m_socket;
};

#endif // PROXYSERVER_H
