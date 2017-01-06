#include "test.h"
#include "deferpp.h"
#include <pthread.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <chrono>




//#define CHECK
int globalEvent = 0;

void* ThreadFcn(void*){

    return nullptr;
}


int main(){
    std::cout<<"Test Started"<<std::endl;

    globalEvent = eventfd(0, EFD_NONBLOCK);
    ECHECKED(globalEvent != -1);

    pthread_t threadId = 0;
    ECHECKED_CALL( pthread_create(&threadId, nullptr, ThreadFcn, nullptr) );
    DEFER { ECHECKED_CALL( pthread_join(threadId, nullptr) ); };

    auto start = std::chrono::steady_clock::now();
    const unsigned PingMax = 1000000;
/*


    std::cout<<"Send Set Wait pairs"<<std::endl;
    auto tcStart = ::GetTickCount();
    for(unsigned i = 0; i < PingMax; ++i){
        e1.Set();
        e2.Wait();
    }

    auto totalTicks = ::GetTickCount() - tcStart;
    */

    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>
                            (std::chrono::steady_clock::now() - start).count();

    std::cout<<"Thread ping-pong seconds="<<(milliseconds/1000.0)
             <<" per second="<<(1000.0*PingMax/milliseconds)<<std::endl;

    std::cout<<"Test Finished"<<std::endl;
    return 0;
}
