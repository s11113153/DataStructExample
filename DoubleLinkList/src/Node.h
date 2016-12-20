#ifndef _NODE_H
#define _NODE_H

#include <stdio.h>
#include <string.h>
#include <memory>

struct Node {
public: 
  std::shared_ptr<Node> next;
  std::shared_ptr<Node> prev;
  char name[20];
  int data;

  Node() {
    data = -1;
    next = NULL;
    prev = NULL;
    memset(this->name, '\0', sizeof(name));  
    // printf("node is initialized.\n");
  }

  Node(char const * name, int data): Node() {    
    setName(name);
    setData(data);    
  }

  Node & setName(char const * name) {
    strncpy(this->name, name, sizeof(this->name));
    return *this;
  }

  Node & setData(const int data) {
    this->data = data;
    return *this;
  }

  ~Node() {    
    // printf("%s is deinitialized.\n", this->name);
  }
};
#endif