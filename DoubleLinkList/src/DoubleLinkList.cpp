#include "DoubleLinkList.hpp"

DLinkList::DoubleLinkList::DoubleLinkList() {

}

DLinkList::DoubleLinkList::~DoubleLinkList() {

}

void DLinkList::DoubleLinkList::createHeader(unique_ptr<Node[]> &root, int length) {
  Node *ptr = root.get();  
  if (ptr == NULL) {  
    head = std::make_unique<Node>("system_root", 0);
  }        
  else {    
    head = std::make_unique<Node>(ptr[0].name, ptr[0].data);         
    Node *llink = head.get();
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
  Node *ptr = head.get();  
  printf("=================================================\n");
  while (ptr != NULL) {
    printf("name:[%15s],data: %d \n", ptr->name, ptr->data);
    ptr = ptr->next;
  }
  printf("=================================================\n");
}


Node* DLinkList::DoubleLinkList::get(int index) {
  Node *ptr = head.get();
  int count = 0;
  while(ptr != NULL) {
    if (count == index) {
      printf("%s\n", "i found it");
      break;
    }
    count ++;    
    ptr = ptr->next;
  }
  return ptr;
}