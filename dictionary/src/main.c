#include "../include/dictionary.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int num = 10;
  float pi = 3.1415;
  char name[] = "Kevin";

  // create a new dictionary
  dictionary *my_dict = dictionary_new();

  // add some information to it
  dictionary_add(my_dict, "num", &num);
  dictionary_add(my_dict, "pi", &pi);
  dictionary_add(my_dict, "my name", &name);

  // retrive the information from it
  printf("The number recorded: %d\n", *(int *)dictionary_find(my_dict, "num"));
  printf("The PI number: %f\n", *(float *)dictionary_find(my_dict, "pi"));
  printf("My name: %s", (char *)dictionary_find(my_dict, "my name"));

  // free allocated memory
  dictionary_free(my_dict);
}
