/*================================================================================================*/
#include "LinkList.hpp"

HsuLinkList::LinkList::LinkList() { 
  // do nothing
}

HsuLinkList::LinkList::~LinkList() {  
}

void HsuLinkList::LinkList::getFactory(std::function<void(AbsListFactory*)> callback) {
  callback(&impl);
}

/*================================================================================================*/

HsuLinkList::LinkList::Impl::Impl() {
	head = NULL;
}
HsuLinkList::LinkList::Impl::~Impl() {  
  head = NULL;  
  delete head;
}

void HsuLinkList::LinkList::Impl::createHeader(Data **root) {        
  char nil[] = "nil";
  Data d(nil, -1);  
  *root = new Data(nil, -1);
  (*root)->age = -1;   
  head = (*root);      
}

void HsuLinkList::LinkList::Impl::insertForFirst(Data *node) throw(IllegalException) {
  if (!isInitializeHeader()) throw IllegalException("head is null, please call createHeader method.");      
  node->next = head;
  head = node;  
}

void HsuLinkList::LinkList::Impl::insert(Data *node) throw(IllegalException) {    
  if (!isInitializeHeader()) throw IllegalException("head is null, please call createHeader method.");    

  Data *tail = head;  
  while(tail->next != NULL) {    
    tail = tail->next;     
  }
  tail->next = node;         
}

void HsuLinkList::LinkList::Impl::insert(char const * name, Data *node) throw(IllegalException) {
  
}


void HsuLinkList::LinkList::Impl::printNodes() const {
  Data *ptr = head;
  printf("%s\n", "====================================");
  while (ptr != NULL) {
    printf("%s %d\n", ptr->name, ptr->age);    
    ptr = ptr->next;
  }
}