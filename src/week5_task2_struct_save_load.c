// Name: Mert
// Surname: Ozari
// Student ID: 251ADB057

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

int save_student(const Student* s, const char* filename);
int load_student(const char* filename, Student* out);

int main(void) {
  Student s1 = {0};
  strcpy(s1.name, "Alice");
  s1.age = 21;
  s1.gpa = 3.75f;

  Student loaded = {0};
  const char* filename = "student.txt";

  printf("Saving student to file...\n");

  if (save_student(&s1, filename) != 0) {
    fprintf(stderr, "Failed to save student.\n");
    return EXIT_FAILURE;
  }

  printf("Loading student from file...\n");

  if (load_student(filename, &loaded) != 0) {
    fprintf(stderr, "Failed to load student.\n");
    return EXIT_FAILURE;
  }

  printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
         loaded.gpa);

  return EXIT_SUCCESS;
}

int save_student(const Student* s, const char* filename) {
  FILE* fp = fopen(filename, "w");

  if (fp == NULL) {
    return -1;
  }

  // Store all fields on one line, separated by spaces.
  if (fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa) < 0) {
    fclose(fp);
    return -1;
  }

  // Closing can fail if buffered data cannot be written.
  if (fclose(fp) == EOF) {
    return -1;
  }

  return 0;
}

int load_student(const char* filename, Student* out) {
  FILE* fp = fopen(filename, "r");

  if (fp == NULL) {
    return -1;
  }

  // Limit the name to 49 characters to leave room for '\0'.
  int fields_read = fscanf(fp, "%49s %d %f", out->name, &out->age, &out->gpa);

  int close_result = fclose(fp);

  // A valid record must contain all three fields.
  if (fields_read != 3 || close_result == EOF) {
    return -1;
  }

  return 0;
}