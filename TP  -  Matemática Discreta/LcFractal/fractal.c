#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000000

int main()
{
    char axiom[] = "X";
    char ruleX[] = "YF+XF+Y";
    char ruleY[] = "XF-YF-X";

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

    // Write the final iteration with 'X' and 'Y'
    fprintf(fp, "Iteração 4:\n");
    fprintf(fp, "%s\n", current_string);

    // Remove the 'X' and 'Y' symbols from the final string
    char final_string[MAX_STRING_LENGTH] = {0};
    for (i = 0, j = 0; current_string[i] != '\0'; i++) {
        if (current_string[i] != 'X' && current_string[i] != 'Y') {
            final_string[j++] = current_string[i];
        }
    }
    final_string[j] = '\0';

    // Write the fractal final without 'X' and 'Y'
    fprintf(fp, "Fractal Final:\n");
    fprintf(fp, "%s\n", final_string);

    // Close the file
    fclose(fp);

    return 0;
}
