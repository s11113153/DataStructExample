#ifndef _DOUBLE_LINK_LIST_H
#define _DOUBLE_LINK_LIST_H

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

#include "./Node.hpp"
#include <iostream>
#include <cstdlib>
#include <memory>

namespace DLinkList {
  class DoubleLinkList {
  private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> foot;
    // TODO: it is used for previous(), next() methods    
    std::weak_ptr<Node> now;
  public:
    void createHeader(std::unique_ptr<Node[]> &root, int length);
    void insertFirst(char const * name, const int data);
    void printNodes();
    void insertAt(std::shared_ptr<Node> ptr, char const * name, const int data);
    std::shared_ptr<Node> getByIndex(int index);
    void insertAtLast(char const * name, const int data);
    void deleteAtLast();
    void deleteAt(std::shared_ptr<Node> ptr);
    void deleteFirst();        
    DoubleLinkList();
    ~DoubleLinkList();
    // TODO: Not implementation
    std::weak_ptr<Node> previous();    
    // TODO: Not implementation
    std::weak_ptr<Node> next();
  };
}
#endif