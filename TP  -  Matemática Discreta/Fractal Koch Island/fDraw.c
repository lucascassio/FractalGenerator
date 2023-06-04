#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#define PI 3.14159265358979323846

int main()
{
  
  // Abrir o arquivo com a string do fractal
  FILE* file = fopen("fractal.txt", "r");
  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Ler a string do arquivo
  char current_string[100000];
  fgets(current_string, sizeof(current_string), file);

  // Fechar o arquivo
  fclose(file);

  // Configurar o SDL2
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("Fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // Configurar a cor da linha e do fundo
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // fundo branco
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // linha azul


  // Configurar o ponto inicial e o ângulo
  int x = 400;
  int y = 210;
  double direction = PI / 2.0;
  double length = 10.0;
  double theta = 90.0;

  // Desenhar o fractal
  for (int i = 0; current_string[i] != '\0'; i++) {
    switch (current_string[i]) {
      case 'F':  // Desenhar uma linha para frente
        {
          int new_x = x + (int)(length * cos(direction));
          int new_y = y + (int)(length * sin(direction));
          SDL_RenderDrawLine(renderer, x, y, new_x, new_y);
          x = new_x;
          y = new_y;
        }
        break;
      case '+':  // Virar à direita
        {
          direction += theta * PI / 180.0;
        }
        break;
      case '-':  // Virar à esquerda
        {
          direction -= theta * PI / 180.0;
        }
        break;
      default:  // Ignorar outros símbolos
        break;
    }
  }

  // Atualizar a janela do SDL2
  SDL_RenderPresent(renderer);

  // Aguardar até que a janela seja fechada
  SDL_Event event;
  while (SDL_WaitEvent(&event)) {
    if (event.type == SDL_QUIT) {
      break;
    }
  }

  // Encerrar o SDL2
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}