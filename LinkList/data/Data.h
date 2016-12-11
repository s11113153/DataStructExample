#ifndef _DATA_H
#define _DATA_H

#ifdef __cplusplus
extern "C" {
#endif
#include <string.h>
#include <stdio.h>
// ps 不能在 extern 使用c++ STL
struct Data {
  int age;
  char name[10];
  Data *next;
  Data() {         
    this->next = NULL;
  }
  Data(char *name, int age): Data() {    
    this->age = age;
    strncpy(this->name, name, sizeof(this->name));
  }  
};
#ifdef __cplusplus
}
#endif  

#endif // _DATA_H