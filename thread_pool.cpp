#include "thread_pool.h"

CThreadPool::CThreadPool(std::vector<std::shared_ptr<io_context> > io_contxtVec)
    : m_ioContxVec(io_contxtVec)
{

}

io_context &CThreadPool::getContext()
{
    io_context& ref_ioCntxt = *m_ioContxVec[m_counter];
    if(m_counter >= (m_ioContxVec.size() - 1))
        m_counter = 0;

    return ref_ioCntxt;
}
