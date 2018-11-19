#ifndef PROXYSERVER_H
#define PROXYSERVER_H
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "tcp_connection.h"
#include "client.h"

using namespace boost::asio;

class ProxyServer
{

public:
    ProxyServer(io_context& io_context);
    ProxyServer(std::vector<std::shared_ptr<io_context>> io_contxtVec,
                const std::string& local_host, unsigned short local_port);

    //void start(ip::tcp::endpoint& ep);
    void accepteConnections();
    void stop();

private:
    void start_accept();
    void connect();
    void handle_accept(tcp_connection::pointer new_connection, boost::system::error_code& erc);

    ip::tcp::socket m_socket;
    bool m_started{ false };


    ip::tcp::acceptor m_acceptor;

    thread_pool* m_thrPool{nullptr};
};

#endif // PROXYSERVER_H
