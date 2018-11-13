#include "proxyserver.h"

ProxyServer::ProxyServer()
{
    m_thrPool = new boost::asio::thread_pool(std::thread::hardware_concurrency());
}

void ProxyServer::start(ip::tcp::endpoint& ep)
{
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

void ProxyServer::handle_accept(std::shared_ptr<client> sp_client, boost::system::error_code &erc)
{

}
