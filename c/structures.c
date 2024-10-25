#include <stdio.h>

struct Exam_day {
  int day;
  int year;
  char month[15];
} exam;

struct Student {
  char name[50];
  char surname[50];  
  int group_number;
  struct Exam_day exam;
} student;

int main() {
  struct Student s1;
  struct Exam_day s2;

  printf("%s", "Enter the name of the student: ");
  scanf("%s", student.name);
  printf("%s", "Enter the surname of the student: ");
  scanf("%s", student.surname);
  printf("%s", "Enter the group_number of the student: ");
  scanf("%d", &student.group_number);
  printf("%s", "Enter the day of the exam: ");
  scanf("%d", &student.exam.day);
  printf("%s", "Enter the year of the exam: ");
  scanf("%d", &student.exam.year);
  printf("%s", "Enter the month of the exam: ");
  scanf("%s", student.exam.month);

  printf("\nStudent's name: %s", student.name);
  printf("\nStudent's surname: %s", student.surname);
  printf("\nStudent's group_number: %d", student.group_number);
  printf("\nStudent's day of exam: %d", student.exam.day);
  printf("\nStudent's year of exam: %d", student.exam.year);
  printf("\nStudent's month of exam: %s", student.exam.month);
}
