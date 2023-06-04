#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000000

int main()
{
  // Definir número do fractal, axioma e regras
  int fractal_number;
  char axiom[MAX_STRING_LENGTH];
  char ruleX[MAX_STRING_LENGTH];
  char ruleY[MAX_STRING_LENGTH];
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

  printf("Regra X: ");
  fgets(ruleX, MAX_STRING_LENGTH, stdin);
  ruleX[strcspn(ruleX, "\n")] = '\0'; // Remover a quebra de linha

  printf("Regra Y: ");
  fgets(ruleY, MAX_STRING_LENGTH, stdin);
  ruleY[strcspn(ruleY, "\n")] = '\0'; // Remover a quebra de linha

  char current_string[MAX_STRING_LENGTH] = {0};
  char next_string[MAX_STRING_LENGTH] = {0};
  int i, j, k, num_iterations;

  // Set the current string to the axiom
  strcpy(current_string, axiom);

  // Iterate the specified number of times
  for (num_iterations = 0; num_iterations < 4; num_iterations++) {
    // Replace each 'X' in the current string with the X rule
    for (i = 0, j = 0; current_string[i] != '\0'; i++) {
      if (current_string[i] == 'X') {
        for (k = 0; ruleX[k] != '\0'; k++) {
          next_string[j++] = ruleX[k];
        }
      }
      // Replace each 'Y' in the current string with the Y rule
      else if (current_string[i] == 'Y') {
        for (k = 0; ruleY[k] != '\0'; k++) {
          next_string[j++] = ruleY[k];
        }
      } else {
        next_string[j++] = current_string[i];
      }
    }
    next_string[j] = '\0';

    // Copy the next string to the current string
    strcpy(current_string, next_string);
  }

  // Remove all occurrences of X and Y from the final string
  for (i = 0, j = 0; current_string[i] != '\0'; i++) {
    if (current_string[i] == 'X' || current_string[i] == 'Y') {
      continue;
    } else {
      current_string[j++] = current_string[i];
    }
  }
  current_string[j] = '\0';

  // Write the final string to a file
  FILE* fp = fopen("fractal.txt", "w");
  fprintf(fp, "%s", current_string);
  fclose(fp);

  return 0;
}
