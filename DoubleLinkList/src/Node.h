#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <string.h>
#ifdef __cplusplus
}
#endif

struct Node {
public:
  char name[20];
  int data;
  struct Node *next;
  struct Node *prev;

  Node() {
    data = -1;
    memset(this->name, '\0', sizeof(name));    
    memset(&next, 0, sizeof(Node*));
    memset(&prev, 0, sizeof(Node*));
    printf("node is initialized.\n");
  }

  Node(const char * name, int data): Node() {    
    setName(name);
    setData(data);    
  }

  Node & setName(char const * x) {
    strncpy(this->name, x, sizeof(this->name));
    return *this;
  }

  Node & setData(const int data) {
    this->data = data;
    return *this;
  }

  ~Node() {
    printf("%s is deinitialized.\n", this->name);
  }
};
