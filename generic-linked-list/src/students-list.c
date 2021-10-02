#include <stdio.h>
#include <stdlib.h>
#include "../include/students-list.h"
#include "../include/generic-list.h"

struct students_list {
  List *list_students;
};

static int compare_registration(void *student1, void *student2) {
  Student *first_student = (Student *) student1;
  Student *second_student = (Student *) student2;

  return !(get_registration(first_student) == get_registration(second_student));
}

static int display(void *student, void *null) {
  Student *some_student = (Student *) student;
  display_student(some_student);
  printf("\n");
  return 1;
}

StudentsList *create_students_list() {
  StudentsList *students = (StudentsList *) malloc(sizeof(StudentsList));

  if (!students) {
    printf("Allocation error at create_students_list!");
    exit(1);
  }

  students->list_students = create_empty_list();

  return students;
}

void insert_student_at_head(StudentsList *list, Student *student) {
  insert_head(list->list_students, student);
}

void insert_student_at_tail(StudentsList *list, Student *student) {
  insert_tail(list->list_students, student);
}

void remove_student(StudentsList *list, Student *student) {
  remove_list(list->list_students, compare_registration, student);
}

void display_students_list(StudentsList *list) {
  printf("\nStudents list: \n");
  walk_through_list(list->list_students, display, NULL);
}

void free_students_list(StudentsList *list) {
  free_list(list->list_students);
  free(list);
}
