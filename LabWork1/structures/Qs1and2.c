#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Name {
    char* firstName;
    char* middleName;
    char* lastName;
} Name;

typedef struct DateofBirth {
    unsigned int day;
    unsigned int month;
    unsigned int year;
} DateofBirth;

typedef struct Marks {
    float English;
    float Mathematics;
    float ComputerScience;
} Marks;

struct Student {
    long int rollnumber;
    Name* name;
    char* gender;
    DateofBirth* dob;
    Marks* marks;
};

void init(struct Student* s1) {
    s1->name = (Name*)malloc(sizeof(Name));
    s1->dob = (DateofBirth*)malloc(sizeof(DateofBirth));
    s1->marks = (Marks*)malloc(sizeof(Marks));
    s1->gender = (char*)malloc(10 * sizeof(char));  
}

void inputStudentDetails(struct Student* s) {
    printf("Enter roll number: ");
    scanf("%ld", &s->rollnumber);
    
    printf("Enter first name: ");
    s->name->firstName = (char*)malloc(50 * sizeof(char));
    scanf("%s", s->name->firstName);
    
    printf("Enter middle name: ");
    s->name->middleName = (char*)malloc(50 * sizeof(char));
    scanf("%s", s->name->middleName);
    
    printf("Enter last name: ");
    s->name->lastName = (char*)malloc(50 * sizeof(char));
    scanf("%s", s->name->lastName);
    
    printf("Enter gender (Male/Female): ");
    scanf("%s", s->gender);
    
    printf("Enter date of birth (DD MM YYYY): ");
    scanf("%u %u %u", &s->dob->day, &s->dob->month, &s->dob->year);
    
    printf("Enter marks in English: ");
    scanf("%f", &s->marks->English);
    
    printf("Enter marks in Mathematics: ");
    scanf("%f", &s->marks->Mathematics);
    
    printf("Enter marks in Computer Science: ");
    scanf("%f", &s->marks->ComputerScience);
}

float calculateAverage(Marks* marks) {
    return (marks->English + marks->Mathematics + marks->ComputerScience) / 3.0;
}

void displayStudentDetails(struct Student* s) {
    printf("\nRoll Number: %ld\n", s->rollnumber);
    printf("Name: %s %s %s\n", s->name->firstName, s->name->middleName, s->name->lastName);
    printf("Gender: %s\n", s->gender);
    printf("Date of Birth: %02u/%02u/%04u\n", s->dob->day, s->dob->month, s->dob->year);
    printf("Marks: English: %.2f, Mathematics: %.2f, Computer Science: %.2f\n", 
            s->marks->English, s->marks->Mathematics, s->marks->ComputerScience);
    printf("Average Marks: %.2f\n", calculateAverage(s->marks));
}

void displayStudentsWithLowAggregate(struct Student* students, int num_students) {
    printf("\nStudents with less than 40%% aggregate marks:\n");
    for(int i = 0; i < num_students; i++) {
        float average = calculateAverage(students[i].marks);
        if(average < 40.0) {
            printf("%s %s %s - Average Marks: %.2f\n", 
                students[i].name->firstName, students[i].name->middleName, students[i].name->lastName, 
                average);
        }
    }
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    struct Student* students = (struct Student*)malloc(num_students * sizeof(struct Student));

    for(int i = 0; i < num_students; i++) {
        init(&students[i]);
        inputStudentDetails(&students[i]);
    }

    char firstName[50], middleName[50], lastName[50];
    printf("\nEnter the first name of the student to search: ");
    scanf("%s", firstName);
    printf("Enter the middle name of the student to search: ");
    scanf("%s", middleName);
    printf("Enter the last name of the student to search: ");
    scanf("%s", lastName);

    int found = 0;
    for(int i = 0; i < num_students; i++) {
        if(strcmp(students[i].name->firstName, firstName) == 0 &&
           strcmp(students[i].name->middleName, middleName) == 0 &&
           strcmp(students[i].name->lastName, lastName) == 0) {
            displayStudentDetails(&students[i]);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("");
    }

    displayStudentsWithLowAggregate(students, num_students);

    for(int i = 0; i < num_students; i++) {
        free(students[i].name->firstName);
        free(students[i].name->middleName);
        free(students[i].name->lastName);
        free(students[i].name);
        free(students[i].dob);
        free(students[i].marks);
        free(students[i].gender);
    }
    free(students);

    return 0;
}
