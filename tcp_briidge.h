#ifndef TCP_BRIIDGE_H
#define TCP_BRIIDGE_H

#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <mutex>

using namespace boost::asio;

//Increase last number of ip address += val
std::string&& increaseIP(const std::string& ip, const int val){

    std::string sbstr= ip.substr(ip.find_last_of('.')+1, ip.size() - 1);

    //TODO: check max ip number <=252 ?
    int lastNum = atoi(sbstr.c_str());
    lastNum += 2;

    sbstr = ip.substr(0, ip.find_last_of('.') + val);
    sbstr.append(std::to_string(lastNum));

    return std::move(sbstr);
}

class tcp_briidge : public boost::enable_shared_from_this<tcp_connection>
{
public:
    tcp_briidge();

private:
    void createOutPutConnection();

    boost::asio::ip::tcp::socket m_incomeSocket;
    boost::asio::ip::tcp::socket m_outgoSocket;
};

#endif // TCP_BRIIDGE_H
