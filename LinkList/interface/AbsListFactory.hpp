#ifndef ABS_LIST_FACTORY_H
#define ABS_LIST_FACTORY_H

// using c lib
#ifdef __cplusplus
extern "C" {
#endif
#include "../data/Data.h"
#ifdef __cplusplus
}
#endif

// using c++ lib
#include <stdexcept> 
#include <iostream>
#include <memory>
#include "../exception/IllegalException.hpp"

class AbsListFactory {
public:  
  virtual void createHeader(std::shared_ptr<Data> &root) = 0;
  virtual void insert(Data *node) throw(IllegalException) = 0;
  virtual void printNodes() const = 0;
  virtual void insertForFirst(Data *node) throw(IllegalException) = 0;
  virtual void insert(char const * name, Data *node) throw(IllegalException) = 0;
  virtual void deleteFirst() throw(IllegalException) = 0;
  virtual void deleteAtLast() throw(IllegalException) = 0;
  virtual void deleteDataWithSpecificedName(char const * name) throw(IllegalException) = 0;
  virtual void reverse() throw(IllegalException) = 0;
};

#endif // ABS_LIST_FACTORY_H

