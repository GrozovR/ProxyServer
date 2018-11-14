#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

std::string increaseIP(const std::string& ip){
    auto resIP = ip;

    //TODO: проверять с какого ip подключается клиент, макс ~251
    int lastNum = atoi(resIP.substr(resIP.find_last_of('.')));

    lastNum += 2;

    return resIP;
}

class tcp_connection
        : public boost::enable_shared_from_this<tcp_connection>
{
public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    static pointer create(boost::asio::io_context& io_context)
    {
        return pointer(new tcp_connection(io_context));
    }

    boost::asio::ip::tcp::socket& socket()
    {
        return m_incomeSocket;
    }

    void start();

private:
    tcp_connection(boost::asio::io_context& io_context)
        : m_incomeSocket(io_context)
    {}

    void createOutPutConnection(boost::asio::io_context& io_context){
        auto incomeAddress = m_incomeSocket.remote_endpoint().address();
        if(incomeAddress.is_v4()){
            std::string addrStr = incomeAddress.to_string();
            addrStr.
        }

       // m_outputSocket.async_connect()
    }


    boost::asio::ip::tcp::socket m_incomeSocket;
    boost::asio::ip::tcp::socket m_outputSocket;
    std::string m_message;

    int m_bytesTransmit{ 0 };
};

#endif // TCP_CONNECTION_H
