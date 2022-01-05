#include "../include/students-list.h"
#include "../include/generic-list.h"
#include <stdio.h>
#include <stdlib.h>

struct students_list {
  list *list_students;
};

static int compare_registration(void *student1, void *student2) {
  Student *first_student = (Student *)student1;
  Student *second_student = (Student *)student2;

  return !(get_registration(first_student) == get_registration(second_student));
}

Studentslist *create_students_list() {
  Studentslist *students = (Studentslist *)malloc(sizeof(Studentslist));

  if (!students) {
    printf("Allocation error at create_students_list!");
    exit(1);
  }

  students->list_students = list_new();

  return students;
}

void insert_student_at_head(Studentslist *list, Student *student) {
  list_add_head(list->list_students, student);
}

void insert_student_at_tail(Studentslist *list, Student *student) {
  list_add_tail(list->list_students, student);
}

void remove_student(Studentslist *list, Student *student) {
  list_remove(list->list_students, compare_registration, student);
}

static void display(void *student) {
  display_student((Student *)student);
  printf("\n");
}

void display_students_list(Studentslist *list) {
  printf("\nStudents list: \n");
  list_display(list->list_students, display);
}

void free_students_list(Studentslist *list) {
  list_free(list->list_students);
  free(list);
}
