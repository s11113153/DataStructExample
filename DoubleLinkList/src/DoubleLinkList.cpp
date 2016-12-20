#include "DoubleLinkList.hpp"

DLinkList::DoubleLinkList::DoubleLinkList() {
  // memset(&head, 0, sizeof(Node*));
  // memset(&foot, 0, sizeof(Node*));  
}

DLinkList::DoubleLinkList::~DoubleLinkList() {
  head.reset();
  foot.reset();
  // head = NULL;  
}

void DLinkList::DoubleLinkList::createHeader(unique_ptr<Node[]> &root, int length) {
  Node *ptr = root.get();  
  if (ptr == NULL) {
    head = std::make_shared<Node>("system_root", 0);
  }        
  else {   
    head = std::make_shared<Node>(ptr[0].name, ptr[0].data);
    auto llink = head;    
    for (size_t i = 1; i < length; i++) {      
      auto newnode = std::make_shared<Node>(ptr[i].name, ptr[i].data); 
      llink->next = newnode;
      ptr[i].prev = head;
      llink = newnode;
      foot = newnode;
    }    
  }  
}

void DLinkList::DoubleLinkList::printNodes() {    
  auto ptr = head;
  printf("=================================================\n");
  while(ptr != NULL) {
    printf("name: %15s data: %d\n", ptr->name, ptr->data);
    ptr = ptr->next;
  }
  printf("=================================================\n");
}

shared_ptr<Node> DLinkList::DoubleLinkList::getByIndex(int index) {  
  auto ptr = head;
  int count = 0;
  while(ptr != NULL) {
    if (count == index) break;
    count++;      
    ptr = ptr->next;      
  }
  return ptr;
}

void DLinkList::DoubleLinkList::insertFirst(char const * name, const int data) {  
  auto newnode = std::make_shared<Node>(name, data);
  head->prev = newnode;
  newnode->next = head;
  head = newnode;
}

void DLinkList::DoubleLinkList::insertAt(shared_ptr<Node> ptr, char const * name, const int data) {
  auto newnode = std::make_shared<Node>(name, data);  
  newnode->prev = ptr;  
  newnode->next = ptr->next;  
  ptr->next->prev = newnode;      
  ptr->next = newnode;
}

void DLinkList::DoubleLinkList::insertAtLast(char const * name, const int data) {
  auto newnode = std::make_shared<Node>(name, data);
  newnode->next = NULL;
  foot->next = newnode;
  newnode->prev = foot;
  foot = newnode;
}

void DLinkList::DoubleLinkList::deleteAtLast() {
  foot->prev->next = NULL;
  foot = foot->prev;  
}

void DLinkList::DoubleLinkList::deleteAt(shared_ptr<Node> ptr) {
  ptr->prev->next = ptr->next;
  ptr->next->prev = ptr->prev;
}
