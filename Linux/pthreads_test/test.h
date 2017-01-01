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
    const char* callText, int errorCode
){
    //form the most descriptive error code
    std::ostringstream os;
    os<<file<<':'<<line<<": "<<fcn<<": Call "<<callText
      <<" failed. Error "<<errorCode<<" ("<<std::strerror(errorCode)<<')';
    std::string str = os.str();

    //report to console
    std::cerr<<str<<std::endl;

    //throw as exception (do not allow to continue)
    throw std::runtime_error(str);
}

#define REPORT_ERROR_CODE_AND_THROW(callText, errorCode) \
    ReportErrorCodeAndThrow(__FILE__,__LINE__,__func__, callText, errorCode)

#define CHECKED_CALL(callThatReturnsErrorCode) \
    if( true ){\
        int errorCode = callThatReturnsErrorCode; \
        if( /*TODO mark as "unlikely"*/0 != errorCode ){ \
            REPORT_ERROR_CODE_AND_THROW(#callThatReturnsErrorCode, errorCode); \
        } \
    } else ((void)0)

#endif
