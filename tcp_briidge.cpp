#include "tcp_briidge.h"

tcp_briidge::tcp_briidge()
{

}


void tcp_briidge::createOutPutConnection()
{
    auto incomeAddress = m_incomeSocket.remote_endpoint().address();

    if(incomeAddress.is_v4()){ // ??

        auto addressToConnect = increaseIP(incomeAddress.to_string(),2);

        boost::asio::ip::tcp::endpoint conPoint(boost::asio::ip::address::from_string(addressToConnect),
                                                m_incomeSocket.remote_endpoint().port());
    }
}
