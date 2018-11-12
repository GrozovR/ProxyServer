#ifndef PROXYSERVER_H
#define PROXYSERVER_H
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

using namespace boost::asio;

class ProxyServer
{
public:
    ProxyServer();

    void start();
    void stop();

private:
    void connect();

    ip::tcp::socket m_socket;
    bool m_started{ false };

    thread_pool* thrPool{nullptr};
};

#endif // PROXYSERVER_H
