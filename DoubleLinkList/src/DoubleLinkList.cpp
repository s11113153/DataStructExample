#include "DoubleLinkList.hpp"

DLinkList::DoubleLinkList::DoubleLinkList() {
  memset(&head, 0, sizeof(Node*));
  memset(&foot, 0, sizeof(Node*));  
}

DLinkList::DoubleLinkList::~DoubleLinkList() {
  head.reset();
  foot.reset();
  head = NULL;
  foot = NULL;	
}

void DLinkList::DoubleLinkList::createHeader(std::unique_ptr<Node[]> &root, int length) {
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
      newnode->prev = llink;
      llink = newnode;			
      foot = newnode;
    }		
  }	
}

void DLinkList::DoubleLinkList::insertFirst(char const * name, const int data) {
  auto newnode = std::make_shared<Node>(name, data);
  newnode->next = head;	
  head->prev = newnode;	
  head = NULL;
  head = newnode;
}

void DLinkList::DoubleLinkList::printNodes() {
  auto ptr = head;
  printf("=================================================\n");
  while (ptr != NULL) {
    printf("name: %15s data: %d use_count: %d \n", ptr->name, ptr->data, ptr.use_count());
    ptr = ptr->next;
  }
  printf("=================================================\n");
}

void DLinkList::DoubleLinkList::insertAt(std::shared_ptr<Node> ptr, char const * name, const int data) {
  auto newnode = std::make_shared<Node>(name, data);
  newnode->prev = ptr;
  newnode->next = ptr->next;
  ptr->next->prev = newnode;
  ptr->next = newnode;
}

std::shared_ptr<Node> DLinkList::DoubleLinkList::getByIndex(int index) {
  auto ptr = head;
  int count = 0;
  while (ptr != NULL) {
    if (count == index) break;
    count++;
    ptr = ptr->next;
  }
  return ptr;
}

void DLinkList::DoubleLinkList::insertAtLast(char const * name, const int data) {
  auto newnode = std::make_shared<Node>(name, data);
  newnode->next = NULL;
  foot->next = newnode;
  newnode->prev = foot;
  foot = newnode;
}

void DLinkList::DoubleLinkList::deleteAtLast() {
  foot->prev.lock()->next = NULL;
  foot = foot->prev.lock();
}

void DLinkList::DoubleLinkList::deleteAt(std::shared_ptr<Node> ptr) {
  ptr->prev.lock()->next = ptr->next;
  ptr->next->prev = ptr->prev;
}

void DLinkList::DoubleLinkList::deleteFirst() {
  head = head->next;
  head->prev.lock() = NULL;
}