// Name: Mert
// Surname: Ozari
// Student ID: 251ADB057

#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char* argv[]) {
  FILE* fp;
  const char* filename = DEFAULT_FILENAME;
  char line[LINE_LEN];
  int line_count = 0;

  // Use the given filename if one is provided.
  if (argc > 1) {
    filename = argv[1];
  }

  printf("Writing lines to %s...\n", filename);
  fp = fopen(filename, "w");

  // Stop if the file could not be opened.
  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  if (fprintf(fp, "Hello, file I/O in C!\n") < 0 ||
      fprintf(fp, "This is another line.\n") < 0) {
    perror(filename);
    fclose(fp);
    return EXIT_FAILURE;
  }

  // Closing the file also flushes buffered output.
  if (fclose(fp) == EOF) {
    perror(filename);
    return EXIT_FAILURE;
  }

  fp = fopen(filename, "r");

  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  printf("Reading contents:\n");

  // Read and print one line at a time.
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
    line_count++;
  }

  // Distinguish a read error from the normal end of the file.
  if (ferror(fp)) {
    perror(filename);
    fclose(fp);
    return EXIT_FAILURE;
  }

  if (fclose(fp) == EOF) {
    perror(filename);
    return EXIT_FAILURE;
  }

  printf("Lines read: %d\n", line_count);

  return EXIT_SUCCESS;
}