#include "threadpool.h"
#include "thread"

ThreadPool::ThreadPool()
{
    m_cores = std::thread::hardware_concurrency();
}
