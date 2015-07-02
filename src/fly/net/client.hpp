/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                    _______    _                                     *
 *                   (  ____ \  ( \     |\     /|                      * 
 *                   | (    \/  | (     ( \   / )                      *
 *                   | (__      | |      \ (_) /                       *
 *                   |  __)     | |       \   /                        *
 *                   | (        | |        ) (                         *
 *                   | )        | (____/\  | |                         *
 *                   |/         (_______/  \_/                         *
 *                                                                     *
 *                                                                     *
 *     fly is an awesome c++11 network library.                        *
 *                                                                     *
 *   @author: lichuan                                                  *
 *   @qq: 308831759                                                    *
 *   @email: 308831759@qq.com                                          *
 *   @github: https://github.com/lichuan/fly                           *
 *   @date: 2015-06-23 16:49:58                                        *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef FLY__NET__CLIENT
#define FLY__NET__CLIENT

#include "fly/net/poller.hpp"
#include "fly/net/parser.hpp"

namespace fly {
namespace net {

class Client
{
public:
    Client(const Addr &addr, std::function<void(std::shared_ptr<Connection>)> cb, std::shared_ptr<Poller> poller, std::shared_ptr<Parser> parser);
    bool connect();
    uint64 id();
    
private:
    uint64 m_id;
    Addr m_addr;
    std::shared_ptr<Poller> m_poller;
    std::shared_ptr<Parser> m_parser;
    std::function<void(std::shared_ptr<Connection>)> m_cb;
};

}
}

#endif