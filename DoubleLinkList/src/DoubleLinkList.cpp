#include "DoubleLinkList.hpp"

DLinkList::DoubleLinkList::DoubleLinkList() {
  memset(&head, 0, sizeof(Node*));
  memset(&foot, 0, sizeof(Node*));
  memset(&now, 0, sizeof(Node*));
}

DLinkList::DoubleLinkList::~DoubleLinkList() {
  delete head;
  head = foot = now = NULL;
}

void DLinkList::DoubleLinkList::createHeader(unique_ptr<Node[]> &root, int length) {
  Node *ptr = root.get();  
  if (ptr == NULL) {  
    head = new Node("system_root", 0);
  }        
  else {    
    head = new Node(ptr[0].name, ptr[0].data);     
    Node *llink = head;
    Node *rlink;
    for (size_t i = 1; i < length; i++) {
      Node *newnode = &ptr[i];      
      llink->next = newnode;
      ptr[i].prev = llink;
      llink = newnode;
    }    
  }      
}

void DLinkList::DoubleLinkList::printNodes() {  
  Node *ptr = head;
  printf("=================================================\n");
  while (ptr != NULL) {
    printf("name:[%15s],data: %d \n", ptr->name, ptr->data);
    ptr = ptr->next;
  }
  printf("=================================================\n");
}

Node* DLinkList::DoubleLinkList::get(int index) {
  Node *ptr = head;
  int count = 0;
  while(ptr != NULL) {
    if (count == index) break;    
    count ++;    
    ptr = ptr->next;
  }
  return ptr;
}