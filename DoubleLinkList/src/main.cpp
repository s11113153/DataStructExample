#ifdef __cplusplus
extern "C" {
#endif
// include c lib
#include <stdio.h>
#include <time.h>
#ifdef __cplusplus
}
#endif
// include c++ lib
#include "DoubleLinkList.hpp"
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

#define ROOT_SIZE 7

using namespace DLinkList;
using std::shared_ptr;
using std::unique_ptr;
using std::endl;
using std::cout;
using std::vector;
using namespace std;

int getRandomIntvalue() {
  return rand() % 99 + 1;
}

// TODO not use it method
// template<typename T>
// std::shared_ptr<T> make_shared_array(size_t size) {
//   return std::shared_ptr<T>(new T[size], [] (T* ptr) {
//     printf("fuck\n");
//     delete [] ptr;
//   });
// }

// unique_ptr<Node*[]> root = std::make_unique<Node*[]>(30);

int main(int argc, char const *argv[]) {
  srand(signed(time(NULL)));  
  DoubleLinkList dLinkList;
  unique_ptr<Node[]> root = std::make_unique<Node[]>(ROOT_SIZE);  
  root[0].setName("abandon-1").setData(getRandomIntvalue());
  root[1].setName("abbreviation-2").setData(getRandomIntvalue());
  root[2].setName("abide-3").setData(getRandomIntvalue());
  root[3].setName("ability-4").setData(getRandomIntvalue());
  root[4].setName("able-5").setData(getRandomIntvalue());
  root[5].setName("abnormal-6").setData(getRandomIntvalue());
  root[6].setName("aboard-7").setData(getRandomIntvalue());
  dLinkList.createHeader(root, ROOT_SIZE);  
  dLinkList.insertFirst("BBC", getRandomIntvalue());    
  dLinkList.insertAt(dLinkList.getByIndex(6), "CNN", getRandomIntvalue());
  dLinkList.insertAt(dLinkList.getByIndex(4), "Apex", getRandomIntvalue());
  dLinkList.insertAt(dLinkList.getByIndex(4), "Bee", getRandomIntvalue());
  dLinkList.insertAtLast("Apple", getRandomIntvalue());
  dLinkList.insertAtLast("cat", getRandomIntvalue());  
  dLinkList.deleteAtLast();
  dLinkList.deleteAtLast();  
  dLinkList.deleteAt(dLinkList.getByIndex(1));
  dLinkList.deleteAt(dLinkList.getByIndex(1));
  dLinkList.printNodes();
  return EXIT_SUCCESS;
}
