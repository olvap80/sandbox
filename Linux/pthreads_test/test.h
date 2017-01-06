#ifndef TEST_H_
#define TEST_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <cstring>



///Report error with all the "extra" details
inline void ReportErrorCodeAndThrow(
    const char* file, int line, const char* fcn,
    const char* operationText, int errorCode
){
    //form the most descriptive error code
    std::ostringstream os;
    os<<file<<':'<<line<<": "<<fcn<<": operation "<<operationText
      <<" failed. Error "<<errorCode<<" ("<<std::strerror(errorCode)<<')';
    std::string str = os.str();

    //report to console
    std::cerr<<str<<std::endl;

    //throw as exception (do not allow to continue)
    /*TODO: use std::system_error some day*/
    throw std::runtime_error(str);
}

#define REPORT_ERROR_CODE_AND_THROW(operationText, errorCode) \
    ReportErrorCodeAndThrow(__FILE__,__LINE__,__func__, operationText, errorCode)

///Check condition and rise error when failed
/**Note: adds errno to report*/
#define ECHECKED(cond) \
	if( /*TODO mark as "unlikely"*/ !(cond)){ \
        REPORT_ERROR_CODE_AND_THROW(#cond, errno); \
    } \
	else ((void)0)

///Call API, check API result (error code) and rise error when failed
/**It is expected that API retunns "errno" like error code.
   Note: adds that "errno like" error code to report*/
#define ECHECKED_CALL(callThatReturnsErrorCode) \
    if( true ){\
        int errorCode = callThatReturnsErrorCode; \
        if( /*TODO mark as "unlikely"*/0 != errorCode ){ \
            REPORT_ERROR_CODE_AND_THROW(#callThatReturnsErrorCode, errorCode); \
        } \
    } else ((void)0)

#endif
