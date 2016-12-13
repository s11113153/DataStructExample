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
  printf("head is deleted %p\n", head);
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
  Data *ptr = head;
  while(ptr != NULL) {
    // found specifics data and insert it to behind
    if ( strncmp(ptr->name, name, sizeof(ptr->name) )== 0) {            
      node->next = ptr->next;
      ptr->next = node;
      return;
    }
    ptr = ptr->next;
  }

  // if the name is found, just return and interrupt
  // else print message
  printf("Insert is fail, data \"%s\": not found !!!\n", name);
}

void HsuLinkList::LinkList::Impl::deleteFirst() throw(IllegalException) {
  if (!isInitializeHeader()) throw IllegalException("head is null");  
  head = head->next;
}

void HsuLinkList::LinkList::Impl::deleteAtLast() throw(IllegalException) {
  if (!isInitializeHeader()) throw IllegalException("delete at last fail");        
  Data *ptr = head;
  Data *previous = head;

  //move to the previous position of the last data
  while(ptr->next != NULL) { ptr = ptr->next; }  
  
  // previous = head = ptr
  // head = null  // or call deleteFirst();
  if (previous == ptr && previous == head) {
    Data **p = &head;
    *p = NULL;
  }
  // moveing to position of ptr, set ptr.next = null  
  else {
    while(previous->next != ptr) {
      previous = previous->next;      
    }  
    previous->next = NULL;   
  } 
}

void HsuLinkList::LinkList::Impl::deleteDataWithSpecificedName(char const * name) throw(IllegalException) {
  Data *ptr = head;
  Data *previous = head;
  bool isFound = false;

  // search specified name in linklist
  while(ptr != NULL) {    
    if (strncmp(ptr->name, name, sizeof(ptr->name)) == 0) {
      isFound = true;      
      break;      
    }
    ptr = ptr->next;    
  }    
  
  if (!isFound) {
    printf("%s\n", "not found name");
    return;
  }
  
  if (ptr == previous) { deleteFirst(); }
  else {
    while(previous->next != ptr) {
      previous = previous->next;
    }  
    previous->next = ptr->next;
  }
}

void HsuLinkList::LinkList::Impl::reverse() throw(IllegalException) {
  Data *p = head;
  Data *q = NULL;
  Data *r = NULL;

  while(p != NULL) {      
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  head = q;
}

void HsuLinkList::LinkList::Impl::printNodes() const {
  Data *ptr = head;
  printf("%s\n", "====================================");
  while (ptr != NULL) {
    printf("%s %d\n", ptr->name, ptr->age);    
    ptr = ptr->next;
  }
}