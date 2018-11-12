#include "proxyserver.h"

ProxyServer::ProxyServer()
{
    thrPool = new boost::asio::thread_pool(std::thread::hardware_concurrency());
}

void ProxyServer::start()
{

}

void ProxyServer::stop()
{

}

void ProxyServer::connect()
{

}
