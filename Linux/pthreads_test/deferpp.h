#include <utility>
#include <iostream>

//Deferpp (Defer++) is Go-like DEFER construction for C++
//Created by Pavlo M

///Defer following code until scope is exited
/**TODO: usage sample here*/
#define DEFER \
        auto DEFER_CAT_ID(callOnScopeExit,__LINE__) \
          = (Defer_SupportNamespace::tagClassForLambda) ->* [&]()

//Expand and concatenate macro arguments into combined identifier
#define DEFER_CAT_ID(a,b) DEFER_CAT_ID_EXPANDED_HELPER(a,b)
//helper macro to concatenate expanded macro arguments
#define DEFER_CAT_ID_EXPANDED_HELPER(a,b) a##b

namespace Defer_SupportNamespace{
    struct TagClassForLambda{ constexpr TagClassForLambda(){} };
    constexpr TagClassForLambda tagClassForLambda;

    template<class Lambda>
    class CallOnScopeExit{
    public:
        constexpr CallOnScopeExit(Lambda&& initialLambda)
            : isOwner(true), lambda(std::move(initialLambda)) {}

        CallOnScopeExit(CallOnScopeExit&& other)
            : isOwner(true), lambda(std::move(other.lambda) )
        {
            other.isOwner = false;
        }

        CallOnScopeExit& operator=(CallOnScopeExit&& other){
            lambda = std::move(other.lambda);
            other.isOwner = false;
            return *this;
        }

        ~CallOnScopeExit() noexcept(false) {
            bool uncaughtExceptionActive = std::uncaught_exception();
            try{
                if( isOwner ){
                    lambda();
                }
            }
            catch(...){
                //do not throw an exception from a destructor while processing another exception
                if(!uncaughtExceptionActive){
                    //rethrow same exception
                    throw;
                }
                else{
                    std::cerr<<"Exception in DEFER while another exception is active"<<std::endl;
                }
            }
        }
    private:
        bool isOwner; //ensure 100% lambda is called only one time
        Lambda lambda; //hold lambda, avoid slow std::function

        //ban copying
        CallOnScopeExit(const CallOnScopeExit& other);
        CallOnScopeExit& operator=(const CallOnScopeExit& other);
    };


    template<class Lambda>
    inline CallOnScopeExit<Lambda> operator ->* (const TagClassForLambda&, Lambda&& lambda){
        return CallOnScopeExit<Lambda>(std::move(lambda));
    }
}
