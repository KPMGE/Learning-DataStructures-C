#ifndef STUDENT_H
#define STUDENT_H 

typedef struct student Student;

Student *create_student(char *name, int registration, float p1, float p2, float p3);
int get_registration(Student *student);
char *get_name(Student *student);
float get_average(Student *student);
void display_student(Student *student);
void free_student(Student *student);

#endif /* ifndef STUDENT_H */
