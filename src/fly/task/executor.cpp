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
 *   @email: lichuan@lichuan.me                                        *
 *   @github: https://github.com/lichuan/fly                           *
 *   @date: 2015-06-10 13:33:47                                        *
 *                                                                     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "fly/task/executor.hpp"

namespace fly {
namespace task {

Executor::Executor()
{
}

void Executor::run()
{
    while(auto *task = m_tasks.pop())
    {
        task->run();
        delete task;
    }
}

void Executor::add_task(Task *task)
{
    m_tasks.push(task);
}

void Executor::start()
{
    std::thread tmp(std::bind(&Executor::run, this));
    m_thread = std::move(tmp);
}

void Executor::wait()
{
    m_thread.join();
}

}
}
