#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000000

int main() {
  int fractal_number;
  char axiom[MAX_STRING_LENGTH];
  int angle;
  char rule[MAX_STRING_LENGTH];

  printf("Número do fractal: ");
  scanf("%d", &fractal_number);

  printf("Axioma: ");
  getchar(); // Limpar o buffer do teclado antes de ler a string
  fgets(axiom, MAX_STRING_LENGTH, stdin);
  axiom[strcspn(axiom, "\n")] = '\0';  // Remover quebra de linha

  printf("Ângulo (em graus): ");
  scanf("%d", &angle);
  getchar(); // Limpar o buffer do teclado antes de ler a string

  printf("Regra: ");
  fgets(rule, MAX_STRING_LENGTH, stdin);
  rule[strcspn(rule, "\n")] = '\0';  // Remover quebra de linha

  char current_string[MAX_STRING_LENGTH] = {0};
  char next_string[MAX_STRING_LENGTH] = {0};
  int i, j, k, num_iterations;

  // Set the current string to the axiom
  strcpy(current_string, axiom);

  // Open the file for writing
  FILE* fp = fopen("fractal.txt", "w");
  if (fp == NULL) {
    printf("Failed to open the file.\n");
    return 1;
  }

  // Iterate the specified number of times
  for (num_iterations = 0; num_iterations < 4; num_iterations++) {
    // Write the iteration number to the file
    fprintf(fp, "Iteração %d:\n", num_iterations);

    // Write the current string to the file
    fprintf(fp, "%s\n", current_string);

    // Replace each 'F' in the current string with the rule
    for (i = 0, j = 0; current_string[i] != '\0'; i++) {
      if (current_string[i] == 'F') {
        for (k = 0; rule[k] != '\0'; k++) {
          next_string[j++] = rule[k];
        }
      } else {
        next_string[j++] = current_string[i];
      }
    }
    next_string[j] = '\0';

    // Copy the next string to the current string
    strcpy(current_string, next_string);
  }

  // Write the final iteration
  fprintf(fp, "Iteração %d:\n", num_iterations);
  fprintf(fp, "%s\n", current_string);

  // Close the file
  fclose(fp);

  return 0;
}
