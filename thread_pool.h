#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include "tcp_connection.h"
#include "client.h"

using namespace boost::asio;

//TODO: изменить название хэдера

class CThreadPool
{
public:
    CThreadPool(std::vector<std::shared_ptr<io_context>> io_contxtVec);

    io_context &getContext();

private:
    std::vector<std::shared_ptr<io_context>> m_ioContxVec;
    std::size_t m_nextContext{0};
};

#endif // THREAD_POOL_H
