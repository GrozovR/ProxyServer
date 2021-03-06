#ifndef TCP_CONNECTION_H
#define TCP_CONNECTION_H

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <mutex>

using namespace boost::asio;


class tcp_connection
        : public boost::enable_shared_from_this<tcp_connection>
{
public:
    typedef boost::shared_ptr<tcp_connection> pointer;

    //как это правильно использовать?
    static pointer create(boost::asio::io_context& io_context)
    {
        return pointer(new tcp_connection(io_context));
    }

    boost::asio::ip::tcp::socket& socket()
    {
        return m_incomeSocket;
    }

    void start();

    void handle_upstream_connect(const boost::system::error_code& error)
    {
        if(!error)
        {

        }
        else
            close();
    }

private:
    tcp_connection(boost::asio::io_context& io_context)
        : m_incomeSocket(io_context),
          m_outputSocket(io_context)
    {}

    void createOutPutConnection(boost::asio::io_context& io_context){
        auto incomeAddress = m_incomeSocket.remote_endpoint().address();

        if(incomeAddress.is_v4()){ // ??
            auto addressToConnect = increaseIP(incomeAddress.to_string());

            boost::asio::ip::tcp::endpoint conPoint(boost::asio::ip::address::from_string(addressToConnect),
                                                    m_incomeSocket.remote_endpoint().port());


            m_outputSocket.async_connect(conPoint,);

        }

    }

    void close()
    {}

    int m_bytesTransmit{ 0 };
    enum { max_data_length = 8192}; //8KB
    //как то должно синхронизоваться с определенной парой потоков
    unsigned char m_transfer_data[max_data_length];
    std::mutex m_mutex;
};

#endif // TCP_CONNECTION_H
