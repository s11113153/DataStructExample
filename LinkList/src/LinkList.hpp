#ifndef LINK_LIST_H
#define LINK_LIST_H

#ifdef __cplusplus
extern "C" {
#endif
// using c lib
#include <stdio.h>  
#include <string.h>
#include "../data/Data.h"
#ifdef __cplusplus
}
#endif

// using c++ lib
#include <functional>
#include "../interface/AbsListFactory.hpp"
#include <stdexcept> 
#include <functional>


namespace HsuLinkList {
  inline namespace v1 {    
    class LinkList {
    protected:
      class Impl: virtual public AbsListFactory {
      private:
        friend LinkList;
        Impl();    
        ~Impl();    
      public:        
        Data* head;    

        // checking header whether initialize
        std::function<bool()> isInitializeHeader = [=]() -> bool {
          return (this->head == NULL) ? false : true;      
        };    
        // createing a new first header
        virtual void createHeader(Data **root);         
        // add for first
        virtual void insertForFirst(Data *node) throw(IllegalException);
        // sequence order for add
        virtual void insert(Data *node) throw(IllegalException);
        // insert of speficis position
        virtual void insert(char const * name, Data *node) throw(IllegalException);
        // delete first data
        virtual void deleteFirst() throw(IllegalException);
        // delete at last data
        virtual void deleteAtLast() throw(IllegalException);
        // delete the data with the specified name
        virtual void deleteDataWithSpecificedName(char const * name) throw(IllegalException);
        // reverse of linklist'data
        virtual void reverse() throw(IllegalException);
        // print all fo the nodes
        virtual void printNodes() const;

      } impl;    
    public:    
      LinkList();
      ~LinkList();
      void getFactory(std::function<void(AbsListFactory*)> callback);      
    };
  }
} // end namespace
#endif // LINK_LIST_H

