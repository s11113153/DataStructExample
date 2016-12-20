#ifndef _DOUBLE_LINK_LIST_H
#define _DOUBLE_LINK_LIST_H

#include <stdio.h>
#include "./Node.h"
#include <iostream>
#include <cstdlib>
#include <memory>

using std::unique_ptr;
using std::shared_ptr;

namespace DLinkList {
  class DoubleLinkList {
  private:
    shared_ptr<Node> head;
    shared_ptr<Node> foot;
  public:
    void createHeader(unique_ptr<Node[]> &root, int length);
    shared_ptr<Node> getByIndex(int index);
    void insertFirst(char const * name, const int data);
    void insertAt(shared_ptr<Node> ptr, char const * name, const int data);
    void insertAtLast(char const * name, const int data);
    void deleteFirst();
    void deleteAtLast();
    void deleteAt(shared_ptr<Node> ptr);
    void printNodes();
    DoubleLinkList();
    ~DoubleLinkList();
  };
} // DoubleLinkList
#endif