#ifndef STUDENTS_LIST_H
#define STUDENTS_LIST_H 

typedef struct students_list Studentslist;

#include "student.h"

Studentslist *create_students_list();
void insert_student_at_head(Studentslist *list, Student *student);
void insert_student_at_tail(Studentslist *list, Student *student);
void remove_student(Studentslist *list, Student *student);
void display_students_list(Studentslist *list);
void free_students_list(Studentslist *list);

#endif /* ifndef STUDENTS_LIST_H */
