#ifndef PROXYSERVER_H
#define PROXYSERVER_H
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "tcp_briidge.h"
#include "client.h"
#include "thread_pool.h"

using namespace boost::asio;

class ProxyServer
{

public:
    ProxyServer(std::vector<std::shared_ptr<io_context>> io_contxtVec,
                const std::string& local_host, unsigned short local_port);

    //void start(ip::tcp::endpoint& ep);
    void accepteConnections();
    void stop();

private:
    void start_accept();
    void connect();
    void handle_accept(tcp_connection::pointer new_connection, boost::system::error_code& erc);

    const std::string m_incomeIp;
    const unsigned short m_incomePort;
    std::string m_outcomeIp;

    ip::tcp::socket m_socket;
    bool m_started{ false };


    ip::tcp::acceptor m_acceptor;

    CThreadPool m_thread_pool;
};

#endif // PROXYSERVER_H
