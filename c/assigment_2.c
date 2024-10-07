#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    WRITTEN,
    DIGITAL
} ExamType;

typedef union {
    int duration;
    char software[20];
} ExamInfo;

typedef struct {
    int student_id;
    char name[20];
    char faculty[30];
} Student;

typedef struct {
    int exam_id;
    ExamType exam_type;
    ExamInfo exam_info;
} Exam;

typedef struct {
    int exam_id;
    int student_id;
    int grade;
} ExamGrade;

void ADD_STUDENT(char *args[]) {
    int student_id = atoi(args[1]);
    char *name = args[2];
    char *faculty = args[3];

#define max_students 100
#define max_exams 50

Student students[100];
Exam exams[50];
ExamGrade grades[100 * 50];

int num_students = 0;
int num_exams = 0;
int num_grades = 0;

void ADD_STUDENT(char *args[]);
void ADD_EXAM(char *args[]);
void ADD_GRADE(char *args[]);
void UPDATE_EXAM(char *args[]);
void UPDATE_GRADE(char *args[]);
void SEARCH_STUDENT(char *args[]);
void SEARCH_GRADE(char *args[]);
void DELETE_STUDENT(char *args[]);
void LIST_OF_ALL_STUDENTS();

int validate_student_id(int student_id) {
    if (student_id < 0 || student_id >= MAX_STUDENTS) {
        return 0;
    }
    return 1;
}

int validate_exam_id(int exam_id) {
    if (exam_id < 0 || exam_id >= MAX_EXAMS) {
        return 0;
    }
    return 1;
}

int validate_name(char *name) {
    if (strlen(name) < 2 || strlen(name) >= MAX_NAME_LEN) {
        return 0;
    }
    return 1;
}

int validate_faculty(char *faculty) {
    if (strlen(faculty) < 4 || strlen(faculty) >= MAX_FACULTY_LEN) {
        return 0;
    }
    return 1;
}

int validate_exam_type(char *exam_type) {
    if (strcmp(exam_type, "WRITTEN") == 0 || strcmp(exam_type, "DIGITAL") == 0) {
        return 1;
    }
    return 0;
}

int validate_duration(int duration) {
    if (duration < 40 || duration > 180) {
        return 0;
    }
    return 1;
}

int validate_software(char *software) {
    if (strlen(software) < 2 || strlen(software) >= MAX_SOFTWARE_LEN) {
        return 0;
    }
    return 1;
}

int validate_grade(int grade) {
    if (grade < 0 || grade > 100) {
        return 0;
    }
    return 1;
}

    if (!validate_student_id(student_id)) {
        fprintf(outputf, "Invalid student id\n");
        return;
    }
    if (!validate_name(name)) {
        fprintf(outputf, "Invalid name\n");
        return;
    }
    if (!validate_faculty(faculty)) {
        fprintf(outputf, "Invalid faculty\n");
        return;
    }

    for (int i = 0; i < num_students; i++) {
        if (students[i].student_id == student_id) {
            fprintf(outputf, "Student: %d already exists\n", student_id);
            return;
        }
    }

    students[num_students].student_id = student_id;
    strcpy(students[num_students].name, name);
    strcpy(students[num_students].faculty, faculty);
    num_students++;

    printf("Student: %d added\n", student_id);
}

int main() {
    FILE *inputf = fopen("input.txt", "r");
    FILE *outputf = fopen("output.txt", "w");

    return 0;
}