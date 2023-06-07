#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000000

int main()
{
  int fractal_number;
  char axiom[MAX_STRING_LENGTH];
  char rule[MAX_STRING_LENGTH];
  double angle;

  printf("Número do fractal: ");
  scanf("%d", &fractal_number);
  getchar(); // Consumir o caractere de nova linha após a leitura do número do fractal

  printf("Axioma: ");
  fgets(axiom, MAX_STRING_LENGTH, stdin);
  axiom[strcspn(axiom, "\n")] = '\0'; // Remover a quebra de linha

  printf("Ângulo (em graus): ");
  scanf("%lf", &angle);
  getchar(); // Consumir o caractere de nova linha após a leitura do ângulo

  printf("Regra: ");
  fgets(rule, MAX_STRING_LENGTH, stdin);
  rule[strcspn(rule, "\n")] = '\0'; // Remover a quebra de linha

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

  char final_string[MAX_STRING_LENGTH] = {0};
  for (i = 0, j = 0; current_string[i] != '\0'; i++) {
    if (current_string[i] != 'X' && current_string[i] != 'Y') {
      final_string[j++] = current_string[i];
    }
  }
  final_string[j] = '\0';

  fprintf(fp, "Iteração 4:\n");
  fprintf(fp, "%s\n", current_string);

  fprintf(fp, "Fractal Final:\n");
  fprintf(fp, "%s\n", final_string);

  // Close the file
  fclose(fp);

  return 0;
}
