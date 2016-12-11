#ifndef ILLEGAL_EXCEPTION_H
#define ILLEGAL_EXCEPTION_H

// using c++ lib
#include <stdexcept> 
#include <string>
#include <iostream>

class IllegalException: public std::exception {
private:
  std::string msg = "";
public:  
  IllegalException(std::string msg) {    
    this->msg = msg;
  }

  inline void whatMsg() const {
    using namespace std;
    cout << msg << endl;
  }
};

#endif // ILLEGAL_EXCEPTION_H

