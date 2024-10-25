#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//declaration of structers, enum and union
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

union ExamInfo{
        int duration;
        char software[20];
};

typedef struct {
    int exam_id;
    ExamType exam_type;
    union ExamInfo exam_info;
} Exam;

typedef struct {
    int exam_id;
    int student_id;
    int grade;
} ExamGrade;

// an array of students
Student students[100];
// an array of exams
Exam exams[50];
// an array of grades
ExamGrade grades[100];

ExamType exam_type;

// numbers of students, exams and grades
int num_students = 0;
int num_exams = 0;
int num_grades = 0;

//an array to store the first command 
char command[20];
//an array to store the space separated command with corresponding instructions
char converted[100];

// helper function for command "add_student" and "search_grade"
int add_student(Student students[], int num_students, int student_id) {
    int ret = -1;
    for (int i = 0; i < num_students; i++) {
        // if the student already exists, return -1; otherwise, it returns the index of a student with a certain ID
        if (students[i].student_id == student_id) {
                    ret = i;
                    break;
                }
        }
        return ret;
}

// helper function for command "add_exam" and "search_grade"
int add_exam(Exam exams[], int num_exams, int exam_id) {
    int ret = -1;
    for (int i = 0; i < num_exams; i++) {
        // if the exam already exists, return -1; otherwise, it returns the index of a exam with a certain ID
        if (exams[i].exam_id == exam_id) {
                    ret = i;
                    break;
                }
        }
        return ret;
}

// helper function for command  "add_student" and "add_exam" that check whether the name of a student or faculty is valide or not 
int valide_name(char name[]){
        int ans = 1;
        int ASCII;
        for(int i = 0; i < strlen(name); i++){
                if (name[i] != '\n'){
                        ASCII = (int)name[i];
                        if (!( (ASCII>=97 && ASCII<=122) || (ASCII>=65 && ASCII<=90))){
                                return -1;
                        }
                }

        }
        return ans;
}

// helper function that return index of grade for a particular student_id and exam_id
int update_grade(ExamGrade grades[], int num_grades, int exam_id, int student_id) {
        int ret = -1;
        for(int i = 0; i < num_grades; i++){
                if (grades[i].exam_id == exam_id && grades[i].student_id == student_id) {
                        ret = i;
                        break;
                }
        }
        return ret;
}

// helper function that return index of grade for a particular student_id and exam_id
int search_grade(ExamGrade grades[], int num_grades, int exam_id, int student){
        int ret = -1;
        for(int i = 0; i < num_grades; i++){
                if (grades[i].exam_id == exam_id && grades[i].student_id == student){
                        ret = i;
                        break;
                }
        }
        return ret;
}


int main() {

    // it opens the input and output files for reading
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");
    
    // the loop reads the commands from the input file
    while (1) {
        // read commands
        fgets(converted, sizeof(converted), inputFile);
        char *token = strtok(converted, " ");
        strncpy(command, token, 20);

        // if the command is "add_student", it reads the student's information and adds it to the students array
        if ((strcmp(command, "ADD_STUDENT") == 0) || (strcmp(command, "ADD_STUDENT\n") == 0)) {
            int student_id;
            char name[50], faculty[50];
            // it reads the student's id
            token = strtok(NULL, " ");
            student_id = strtol(token, NULL, 10);
            // it reads the student's name
            token = strtok(NULL, " ");
            strncpy(name, token, 20);
            // it reads the student's faculty
            token = strtok(NULL, " ");
            strncpy(faculty, token, 30);

            // check if the student already exists
            if (add_student(students, num_students, student_id) != -1) {
                fprintf(outputFile, "Student: %d already exists\n", student_id);
                continue;
            }

            // check if the id is valid
            if (student_id<=0 || student_id >= 1000) {
                fprintf(outputFile, "Invalid student id\n");
                continue;
            }

            // check if the name is valid
            if (strlen(name) <=1 || strlen(name)>=20 || valide_name(name) == -1) {
                fprintf(outputFile, "Invalid name\n");
                continue;
            }

            // check if the faculty is valid
            if (strlen(faculty)<=4 || strlen(faculty)>=30 || valide_name(name) == -1) {
                fprintf(outputFile, "Invalid faculty\n");
                continue;
            }

            // add the student to the students array
            fprintf(outputFile, "Student: %d added\n", student_id);
            students[num_students].student_id = student_id;
            strcpy(students[num_students].name, name);
            strcpy(students[num_students].faculty, faculty);
            //increase amount of students
            num_students++;
        }


        // if the command is "add_exam", it reads the exam's information and adds it to the exams array
        else if ((strcmp(command, "ADD_EXAM") == 0) || (strcmp(command, "ADD_EXAM\n") == 0)) {
            // it reads the exam's id
            int exam_id;
            token = strtok(NULL, " ");
            exam_id = strtol(token, NULL, 10);

             // check if the exam_id is valid
            if (exam_id <=0 || exam_id >=500) {
                fprintf(outputFile, "Invalid exam id\n");
                continue;
            }

            // check if the exam already exists
            if (add_exam(exams, num_exams, exam_id) != -1) {
                fprintf(outputFile, "Exam: %d already exists\n", exam_id);
                continue;
            }

             // define type of exam
            token = strtok(NULL, " ");
            if(!(strcmp(token,"WRITTEN"))) {
                exam_type = WRITTEN;
            }
            else if(!(strcmp(token, "DIGITAL"))) {
                exam_type = DIGITAL;
            } 
            else {
                // in case it is wrong output the following error into output.txt
                fprintf(outputFile, "Invalid exam type\n");
                continue;
            } 

            //check what type of exam we are dealing with to specify following duration or software
            token = strtok(NULL, " ");
            if (exam_type == WRITTEN) {
                int duration = strtol(token, NULL, 10);
                // check if the duration is valid
                if (!(duration>=40 && duration<=180)) {
                        fprintf(outputFile, "Invalid duration\n");
                        continue;
                    }
                exams[num_exams].exam_info.duration = duration;

            } else if (exam_type == DIGITAL) {
                char software[20];
                strncpy(software, token, 20);
                // check if the software is valid
                if (!(strlen(software)>2 && strlen(software)<20)) {
                        fprintf(outputFile, "Invalid software\n");
                        continue;
                    }
                if (valide_name(software) == -1) {

                        fprintf(outputFile, "Invalid software\n");
                        continue;
                    }
                strncpy(exams[num_exams].exam_info.software,software,20);
            }
            // add the exam to the exams array
            fprintf(outputFile, "Exam: %d added\n", exam_id);
            exams[num_exams].exam_id = exam_id;
            exams[num_exams].exam_type = exam_type;
            // increase amount of exams
            num_exams++;
        }

        // if the command is "add_grade", it reads the grade's information and adds it to the grades array
        else if ((strcmp(command, "ADD_GRADE") == 0) || (strcmp(command, "ADD_GRADE\n") == 0)) {
            int exam_id, student_id, grade;
            // it reads the exam's id
            token = strtok(NULL, " ");
            exam_id = strtol(token, NULL, 10);
            // it reads the student's id
            token = strtok(NULL, " ");
            student_id = strtol(token, NULL, 10);
            // it reads the grade
            token = strtok(NULL, " ");
            grade = strtol(token, NULL, 10);

             // check if the exam_id is valid
            if (exam_id <=0 || exam_id >=500){
                fprintf(outputFile, "Invalid exam id\n");
                continue;
            }

             // check if the exam exists
            if (add_exam(exams, num_exams, exam_id) == -1){
                    fprintf(outputFile, "Exam not found\n");
                    continue;
            }

             // check if the student_id is valid
            if (student_id <=0 || student_id >= 1000){
                    fprintf(outputFile, "Invalid student id\n");
                    continue;
            }

             // check if the student exists
            if (add_student(students, num_students, student_id) == -1){
                fprintf(outputFile, "Student not found\n", student_id);
                continue;
            }

            // check if the grade is valid
            if (!(grade>=0 && grade<=100)) {
                    fprintf(outputFile, "Invalid grade\n");
                    continue;
            }

            // add the grade to the grades array
            fprintf(outputFile,"Grade %d added for the student: %d\n", grade, student_id);
            grades[num_grades].exam_id = exam_id;
            grades[num_grades].student_id = student_id;
            grades[num_grades].grade = grade;
            // increase amount of grades
            num_grades++;
        }

         // if the command is "update_exam", it reads the exam's information and updates it in the exams array
        else if ((strcmp(command, "UPDATE_EXAM") == 0) || (strcmp(command, "UPDATE_EXAM\n") == 0)) {
            int exam_id, duration;
            char software[50];
            // it reads the exam's id
            token = strtok(NULL, " ");
            exam_id = strtol(token, NULL, 10);

            // define a type of the exam
            token = strtok(NULL, " ");
            if(!(strcmp(token,"WRITTEN"))) {
                exam_type = WRITTEN;
            }
            else if(!(strcmp(token, "DIGITAL"))) {
                exam_type = DIGITAL;
            }  
            else {
                fprintf(outputFile, "Invalid exam type\n");
                continue;
            }

            // it reads the exam's duration
            token = strtok(NULL, " ");
            if (exam_type == WRITTEN) {
                int duration = strtol(token, NULL, 10);
                // check if the duration is valid
                if (!(duration>=40 && duration<=180)) {
                        fprintf(outputFile, "Invalid duration\n");
                        continue;
                    }
                exams[exam_id].exam_info.duration = duration;

            // it reads the exam's software
            } else if (exam_type == DIGITAL) {
                char software[20];
                strncpy(software, token, 20);
                // check if the software is valid
                if (!(strlen(software)>2 && strlen(software)<25)) {
                        fprintf(outputFile, "Invalid software\n");
                        continue;
                    }
                strncpy(exams[exam_id].exam_info.software,software,20);
            }

            // update the exam in the exams array
            fprintf(outputFile, "Exam: %d updated\n", exam_id);
            exams[num_exams].exam_id = exam_id;
            exams[num_exams].exam_type = exam_type;
            num_exams++;
        }

        // if the command is "update_grade", it reads the grade's's information and updates it in the grades array
        else if ((strcmp(command, "UPDATE_GRADE") == 0) || (strcmp(command, "UPDATE_GRADE\n") == 0)) {
            int exam_id, student_id, grade;
            // it reads the exam's id
            token = strtok(NULL, " ");
            exam_id = strtol(token, NULL, 10);
            // it reads the student's id
            token = strtok(NULL, " ");
            student_id = strtol(token, NULL, 10);
            // it reads the grade
            token = strtok(NULL, " ");
            grade = strtol(token, NULL, 10);

            // it checks if grade is valid
            if(!(grade>=0 && grade<=100)) {
                    fprintf(outputFile, "Invalid grade\n");
                    continue;
            }

            // it updates the grade in the grades array
            fprintf(outputFile, "Grade %d updated for the student: %d\n", grade, student_id);
            grades[update_grade(grades, num_grades, exam_id, student_id)].grade = grade;
        }


        // if the command is "search_student", it prints the information about student
        else if ((strcmp(command, "SEARCH_STUDENT") == 0) || (strcmp(command, "SEARCH_STUDENT\n") == 0)) {
            // it reads the student's id
            int student_id;
            token = strtok(NULL, " ");
            student_id = strtol(token, NULL, 10);                   

            // it checks if student_id is valid
            if (student_id<=0 || student_id >= 1000){
                    fprintf(outputFile, "Invalid student id\n");
                    continue;
            }

            int search = add_student(students, num_students, student_id);
            // it checks if student exists
            if (search == -1) {
                    fprintf(outputFile, "Student not found\n");
                    continue;
            }
            // print information about student
            else {
                    fprintf(outputFile, "ID: %d, Name: %s, Faculty: %s", student_id, students[search].name, students[search].faculty);
            }
        }


        // if the command is "search_grade", it prints the information about student's grade
        else if ((strcmp(command, "SEARCH_GRADE") == 0) || (strcmp(command, "SEARCH_GRADE\n") == 0)) {
            int exam_id, student_id, grade; 
            // it reads the exam's id
            token = strtok(NULL, " ");
            exam_id = strtol(token, NULL, 10);
            // it reads the student's id
            token = strtok(NULL, " ");
            student_id = strtol(token, NULL, 10); 
            // it reads the grade
            token = strtok(NULL, " ");
            grade = grades[search_grade(grades, num_grades, exam_id, student_id)].grade;

            // it checks if exam's id is valid
            if (exam_id <=0 || exam_id >=500) {
                    fprintf(outputFile, "Invalid exam id\n");
                    continue;
            }

            // it checks if student's id is valid
            if (student_id <=0 || student_id >= 1000){
                fprintf(outputFile, "Invalid student id\n");
                continue;
            }

            // it checks if exam exists
            int exam = add_exam(exams, num_exams, exam_id);
            if (exam == -1) {
                fprintf(outputFile, "Exam not found\n");
                continue;
            }   

            // it checks if student exists
            int student = add_student(students, num_students, student_id);
            if (student == -1) {
                    fprintf(outputFile, "Student not found\n");
                    continue;
            }

            // due to the type of the exam, it prints information about student's grade
            if (exams[exam].exam_type == WRITTEN) {
                    fprintf(outputFile, "Exam: %d, Student: %d, Name: %s, Grade: %d, Type: %s, Info: %d\n", exams[exam].exam_id, students[student].student_id,  students[student].name, grade, "WRITTEN", exams[exam].exam_info.duration);
            }
            else {
                    fprintf(outputFile, "Exam: %d, Student: %d, Name: %s, Grade: %d, Type: %s, Info: %s", exams[exam].exam_id, students[student].student_id,  students[student].name, grade, "DIGITAL", exams[exam].exam_info.software);
            }
        }


        // if the command is "delete_student", it deletes student and all information about him
        else if ((strcmp(command, "DELETE_STUDENT") == 0) || (strcmp(command, "DELETE_STUDENT\n") == 0)) {
            // it reads the student's id
            token = strtok(NULL, " ");
            int student_id = strtol(token, NULL, 10);
            int student_index = -1;
            for (int i = 0; i < num_students; i++) {
                if (students[i].student_id == student_id) {
                    student_index = i;
                    break;
                }
            }

            if (student_index == -1) {
                return; 
            }

            // delete the student's grades
            for (int i = 0; i < num_grades; i++) {
                if (grades[i].student_id == student_id) {
                    for (int j = i; j < num_grades - 1; j++) {
                        grades[j] = grades[j + 1];
                    }
                    num_grades--;
                    i--; 
                }
            }

            // shift students to the left to remove the deleted student
            for (int i = student_index; i < num_students - 1; i++) {
                students[i] = students[i + 1];
            }
            num_students--;

            fprintf(outputFile, "Student: %d deleted\n", student_id); 
        
        }


        // if the command is "end", it breaks the loop
        else if ((strcmp(command, "END") == 0) || (strcmp(command, "END\n") == 0)) {
            break;
        }

        // if the command is "list_all_students", it prints the information about all students
        else if ((strcmp(command, "LIST_ALL_STUDENTS") == 0) || (strcmp(command, "LIST_ALL_STUDENTS\n") == 0) ) {
            for (int i = 0; i < num_students; i++) {
                fprintf(outputFile,"ID: %d, Name: %s, Faculty: %s", students[i].student_id, students[i].name, students[i].faculty);
            }
            break;
        }
        

        // if command is undefinied, it prints "invalid command"
        else {
            fprintf(outputFile, "Invalid command\n");
        }
    }
    return 0;
}