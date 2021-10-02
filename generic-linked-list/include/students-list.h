#ifndef STUDENTS_LIST_H
#define STUDENTS_LIST_H 

typedef struct students_list StudentsList;

#include "student.h"

StudentsList *create_students_list();
void insert_student_at_head(StudentsList *list, Student *student);
void insert_student_at_tail(StudentsList *list, Student *student);
void remove_student(StudentsList *list, Student *student);
void display_students_list(StudentsList *list);
void free_students_list(StudentsList *list);

#endif /* ifndef STUDENTS_LIST_H */
