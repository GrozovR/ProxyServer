#include "proxyserver.h"

ProxyServer::ProxyServer(std::vector<std::shared_ptr<io_context> > io_contxtVec, const std::string &local_host, unsigned short local_port)
    : m_incomeIp(local_host),
      m_incomePort(local_port),
      m_outcomeIp(std::move(increaseIP(local_host, 1))), //считаем, что выходной интерфейс +1 от local_host
      m_thread_pool(io_contxtVec),
      m_acceptor()
{
    m_acceptor(io_context, ip::tcp::enpoint(ip::tcp::endpoint(ip::tcp::v4(), 13)))
}

void ProxyServer::accepteConnections()
{

}

void ProxyServer::start(ip::tcp::endpoint& ep)
{
    tcp_connection::pointer new_connection = tcp_connection::create(m_acceptor.get_io_context());

    m_acceptor.async_accept(new_connection->socket(),
                            boost::bind(&ProxyServer::handle_accept, this, new_connection, placeholders::error));

    m_acceptor.open(ep.protocol());
    m_acceptor.bind(ep);
    m_acceptor.listen();
}

void ProxyServer::stop()
{

}

void ProxyServer::connect()
{

}

void ProxyServer::handle_accept(tcp_connection::pointer new_connection, boost::system::error_code &erc)
{
    if(!erc)
    {
        new_connection->start();
        start_accept();
    }
}
