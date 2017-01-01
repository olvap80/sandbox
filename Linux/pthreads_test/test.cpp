#include "test.h"
#include "deferpp.h"
#include <pthread.h>
#include <cstring>




//#define CHECK

void* ThreadFcn(void*){

    return nullptr;
}

int main(){
    std::cout<<"Test Started"<<std::endl;

    pthread_t threadId = 0;
    CHECKED_CALL( pthread_create(&threadId, nullptr, ThreadFcn, nullptr) );
    DEFER { CHECKED_CALL( pthread_join(threadId, nullptr) ); };



    std::cout<<"Test Finished"<<std::endl;
    return 0;
}
