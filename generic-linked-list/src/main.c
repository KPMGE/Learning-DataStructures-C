#include <stdio.h>
#include "../include/student.h"
#include "../include/students-list.h"

int main(void) {
  Student *kevin = create_student("Kevin", 15131,  9, 8, 10);
  Student *luana = create_student("Luana", 93203,  8, 5, 6);
  Student *laura = create_student("Laura", 51433,  5, 9, 4);
  Student *karol = create_student("Karol", 83242,  9, 5, 7);

  StudentsList *list = create_students_list();

  insert_student_at_head(list, kevin);
  insert_student_at_head(list, luana);
  insert_student_at_head(list, laura);
  insert_student_at_head(list, karol);

  printf("Original list: \n");
  display_students_list(list);

  printf("\nAfter remove Luana\n");
  remove_student(list, luana);
  display_students_list(list);

  printf("\nAfter remove Karol\n");
  remove_student(list, karol);
  display_students_list(list);

  free_student(kevin);
  free_student(luana);
  free_student(laura);
  free_student(karol);
  free_students_list(list);

  return 0;
}
