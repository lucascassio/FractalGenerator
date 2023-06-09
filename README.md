# FractalGenerator
# Instruções de Execução

Os programas foram desenvolvidos e testados em um ambiente Linux (Ubuntu 20.04 LTS) utilizando a linguagem de programação C.

# Pré-requisitos

Para compilar e executar o programa, é necessário ter instalado o seguinte componente:

Compilador de linguagem C (gcc)

Instalação no Linux (Ubuntu):

    sudo apt update
    sudo apt install build-essential
    
Instalação no Windows (opcional):

Se você estiver utilizando o Windows e desejar compilar e executar o programa, siga as etapas abaixo:

Instale o compilador de C (gcc) usando o MinGW-W64:

Baixe o MinGW-W64 do site oficial: https://mingw-w64.org/doku.php

Selecione a versão apropriada para o seu sistema (32 bits ou 64 bits).

Execute o instalador e siga as instruções para concluir a instalação.

Certifique-se de adicionar o diretório bin do MinGW-W64 ao PATH do sistema para que o compilador gcc seja acessível a partir do prompt de comando.

# Compilação

Para compilar o programa, siga as etapas abaixo:

Abra um terminal (no Linux) ou prompt de comando (no Windows).

Navegue até o diretório onde o arquivo de código-fonte está localizado.

Compile o programa:

No Linux:

    gcc -o generate_fractal fractal.c -lm
    
No Windows (usando MinGW-W64):

    gcc -o generate_fractal fractal.c -lm
    
# Execução

Após a compilação do programa, siga as etapas abaixo para executá-lo:

Execute o programa para gerar a string de instruções do fractal:

No Linux:

    ./generate_fractal
    
No Windows:

    generate_fractal.exe
    
Isso criará um arquivo chamado "fractal.txt" no diretório atual, contendo a string de instruções para o fractal.

# Opcional: Visualização do Fractal

Se desejar visualizar o fractal gerado, você precisará da biblioteca gráfica SDL2 instalada. No entanto, observe que a biblioteca SDL2 é mais comumente usada em sistemas Linux.

Instalação no Linux (Ubuntu):

Siga as instruções abaixo para instalar a biblioteca gráfica SDL2:

Atualize os pacotes:

    sudo apt update
    
Instale a biblioteca gráfica SDL2:

    sudo apt install libsdl2-dev
    
Instalação no Windows (opcional):

Se você estiver utilizando o Windows e desejar instalar a biblioteca gráfica SDL2, siga as etapas abaixo:

Baixe a biblioteca gráfica SDL2 para Windows do site oficial: https://www.libsdl.org/download-2.0.php

Escolha a versão correta para o seu sistema (32 bits ou 64 bits).

Extraia o conteúdo do arquivo baixado.

Copie os arquivos de biblioteca (DLL) para o diretório do sistema do Windows (por exemplo, C:\Windows\System32).

Copie os arquivos de cabeçalho (H) para o diretório de inclusão do compilador (por exemplo, C:\MinGW\include).

# Compilação e execução do programa de visualização (opcional):

Após ter a biblioteca SDL2 instalada, siga as etapas abaixo:

Abra um terminal (no Linux) ou prompt de comando (no Windows).

Navegue até o diretório onde o arquivo de código-fonte está localizado.

Compile o programa de visualização:

No Linux:

    gcc -o visualize_fractal fDraw.c -lSDL2 -lm
    
No Windows (usando MinGW-W64):

    gcc -o visualize_fractal fDraw.c -lmingw32 -lSDL2main -lSDL2 -lm
    
Execute o programa de visualização do fractal:

No Linux:

    ./visualize_fractal
    
No Windows:

    visualize_fractal.exe
    
Isso abrirá uma janela exibindo o fractal desenhado com base na string de instruções do arquivo "fractal.txt". Certifique-se de ter a biblioteca gráfica SDL2 instalada para executar este programa. Observe que a visualização do fractal é opcional e a biblioteca SDL2 é mais comumente usada em sistemas Linux. Caso contrário, você pode ignorar essa etapa.

Para fechar a janela do visualizador de fractal, clique no botão de fechar ou pressione a tecla "Esc".
