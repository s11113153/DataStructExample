#ifdef __cplusplus
extern "C" {  
#endif
// include c lib
#include <stdio.h>
#include "../data/Data.h"
#ifdef __cplusplus
} 
#endif
// include c++ lib
#include <iostream>
#include <cstdlib>
#include "LinkList.hpp"
#include "../interface/AbsListFactory.hpp"
#include "../exception/IllegalException.hpp"

int main(int argc, char const *argv[]) {  
  using namespace std;  
  using namespace HsuLinkList;
  LinkList list;    
  list.getFactory([&](AbsListFactory* imp) -> void {    
    Data *root;  
    imp->createHeader(&root);        
    char a1[] = "A1";
    char a2[] = "A2";
    char a3[] = "A3";
    char a4[] = "A4";
    char a5[] = "A5";     
    char first[] = "first";
    try {    
      Data node_1(a1, 85);  
      Data node_2(a2, 95);  
      Data node_3(a3, 68); 
      Data node_4(a4, 72);  
      Data node_5(a5, 79); 
      Data first_node(first, 100); 

      imp->insert(&node_1);
      imp->insert(&node_2);
      imp->insert(&node_3);
      imp->insertForFirst(&first_node);
      imp->insert(&node_4);
      imp->insert(&node_5);      
      imp->printNodes();    
    } catch(IllegalException e) {
      e.whatMsg();
    }        
  });  
  return EXIT_SUCCESS;
}