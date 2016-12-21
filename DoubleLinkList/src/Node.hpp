#ifndef _NODE_H
#define _NODE_H

#ifdef __cplusplus
extern "C" {
#include <stdio.h>
#include <string.h>
#endif
#ifdef __cplusplus
}
#endif

#include <memory>

extern int inits;
extern int deinits;

struct Node {
  std::shared_ptr<Node> next;
  std::weak_ptr<Node> prev;
  char name[20];
  int data;

  Node() {
    data = -1;
    memset(this->name, '\0', sizeof(name));		
    inits++;
  }

  Node(char const * name, int data) : Node() {		
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
    deinits++;		
  }
};
#endif