#ifndef PROXYSERVER_H
#define PROXYSERVER_H
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "client.h"
using namespace boost::asio;

class ProxyServer
{
public:
    ProxyServer();

    void start(ip::tcp::endpoint& ep);
    void stop();

private:
    void connect();
    void handle_accept(std::shared_ptr<client> sp_client, boost::system::error_code& erc);

    ip::tcp::socket m_socket;
    bool m_started{ false };


    ip::tcp::acceptor m_acceptor;

    thread_pool* m_thrPool{nullptr};
};

#endif // PROXYSERVER_H
