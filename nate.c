#include <stdio.h>

struct Student {
	char reg_no[20];
	char firstname[30];
	char lastname[30];
	float intro_to_programming;
	float networking;
	float accounting;
};

void addStudent(struct Student *student) {
	printf("Enter student details:\n");
	printf("Reg No: ");
	scanf("%s", student->reg_no);
	printf("First name: ");
	scanf("%s", student->firstname);
	printf("Last name: ");
	scanf("%s", student->lastname);
	printf("Intro to Programming: ");
	scanf("%f", &student->intro_to_programming);
	printf("Networking: ");
	scanf("%f", &student->networking);
	printf("Accounting: ");
	scanf("%f", &student->accounting);
}

void displayStudentDetails(struct Student *student) {
	printf("Student details:\n");
	printf("Reg No: %s\n", student->reg_no);
	printf("First name: %s\n", student->firstname);
	printf("Last name: %s\n", student->lastname);
	printf("Intro to Programming: %.2f\n", student->intro_to_programming);
	printf("Networking: %.2f\n", student->networking);
	printf("Accounting: %.2f\n", student->accounting);
}

float calculateAverageMarks(struct Student *student) {
	return (student->intro_to_programming + student->networking + student->accounting) / 3;
}

struct Student* findStudentWithHighestAverageMarks(struct Student *students, int num_students) {
	struct Student *highestAverageStudent = NULL;
	float highestAverage = 0.0;
	for (int i = 0; i < num_students; i++) {
		float averageMarks = calculateAverageMarks(&students[i]);
		if (averageMarks > highestAverage) {
			highestAverage = averageMarks;
			highestAverageStudent = &students[i];
		}
	}
	return highestAverageStudent;
}

int main() {
	struct Student students[100];
	int num_students;

	printf("Enter the number of students: ");
	scanf("%d", &num_students);

	for (int i = 0; i < num_students; i++) {
		addStudent(&students[i]);
	}

	for (int i = 0; i < num_students; i++) {
		displayStudentDetails(&students[i]);
	}

	struct Student* highestAverageStudent = findStudentWithHighestAverageMarks(students, num_students);

	printf("Student with the highest average marks:\n");
	displayStudentDetails(highestAverageStudent);

	return 0;
}
