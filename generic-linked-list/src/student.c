#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"

struct student {
  char *name;
  int registration;
  float p1, p2,p3;
};

Student *create_student(char *name, int registration, float p1, float p2, float p3) {
  Student *student = (Student *) malloc(sizeof(Student));

  if (!student) {
    printf("Allocation error at create_student!");
    exit(1);
  }

  student->name = strdup(name);
  student->p1 = p1;
  student->p2 = p2;
  student->p3 = p3;
  student->registration = registration;

  return student;
}

int get_registration(Student *student) {
  return student->registration;
}

char *get_name(Student *student) {
  return student->name;
}

float get_average(Student *student) {
  return (student->p1 + student->p2 + student->p3) / 3.0;
}

void display_student(Student *student) {
  printf("Name: %s\n", student->name);
  printf("Registration: %d\n", student->registration);
  printf("Average: %.2f\n", get_average(student));
}

void free_student(Student *student) {
  free(student->name);
  free(student);
}
