#ifdef __cplusplus
extern "C" {
#endif
// include c lib
#include <stdio.h>
#include "./Node.h"
#ifdef __cplusplus
}
#endif
// include c++ lib
#include <iostream>
#include <cstdlib>
#include <memory>

using std::unique_ptr;
using std::weak_ptr;

namespace DLinkList {
  class DoubleLinkList {
  private:
    unique_ptr<Node> head;    
    Node *foot;
    Node *now;
  public:
    void createHeader(unique_ptr<Node[]> &root, int length);
    Node* get(int index);
    // bool hasNext();
    // weak_ptr<Node> previous(int data);
    // weak_ptr<Node> next(int data);
    // insertFirst(int data);
    // insertAt(weak_ptr<Node> &ptr, int data);
    // insertAtLast(int data);
    // deleteFirst();
    // deleteAtLast();
    // DeleteAt(weak_ptr<Node> &ptr);
    void printNodes();
    DoubleLinkList();
    ~DoubleLinkList();
  };
} // DoubleLinkList
