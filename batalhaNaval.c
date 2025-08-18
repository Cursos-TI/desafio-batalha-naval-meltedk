#include <stdio.h>

int main() {
    //array de caracteres para cordenadas no grid
	char linhas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

	//Declara e inicializa a matriz tabuleiro com valores padrão de 0 para todas as células
	int tabuleiro[10][10];
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			tabuleiro[i][j] = 0;
		}
	}

	//Representação espacial de cada navio
	int primeiroNavio[3] = {3, 3, 3};
	int segundoNavio[3] = {3, 3, 3};

	int linhaHorizontal, colunaHorizontal; // Cordenadas do navio horizontal
	int linhaVertical, colunaVertical; // Cordenadas do navio vertical
	char horChar, verChar; // Variável de apoio para transformar cordernada vertical de letra para número


	// Imprimindo o tabuleiro vazio
	printf("\n TABULEIRO BATALHA NAVAL \n\n");
	printf("   ");

	for(int j = 0; j < 10; j++) {
		printf("%c ", linhas[j]); // Imprime as letras das colunas
	}

	printf("\n");

	for(int i = 0; i < 10; i++) {
		printf("%2d", i + 1);
		for(int j = 0; j < 10; j++) {
			printf(" %d", tabuleiro[i][j]);
		}
		printf("\n");
	}

	printf("\n");


	// Definindo a posição do navio horizontal
	printf("Digite a letra correspondente à coluna do primeiro barco (horizontal): ");
	scanf(" %c", &horChar);
	printf("Digite a linha do primeiro barco (horizontal): ");
	scanf("%d", &linhaHorizontal);

	if(horChar == 'A' || horChar == 'a')
		colunaHorizontal = 1;
	if(horChar == 'B' || horChar == 'b')
		colunaHorizontal = 2;
	if(horChar == 'C' || horChar == 'c')
		colunaHorizontal = 3;
	if(horChar == 'D' || horChar == 'd')
		colunaHorizontal = 4;
	if(horChar == 'E' || horChar == 'e')
		colunaHorizontal = 5;
	if(horChar == 'F' || horChar == 'f')
		colunaHorizontal = 6;
	if(horChar == 'G' || horChar == 'g')
		colunaHorizontal = 7;
	if(horChar == 'H' || horChar == 'h')
		colunaHorizontal = 8;
	if(horChar == 'I' || horChar == 'i')
		colunaHorizontal = 9;
	if(horChar == 'J' || horChar == 'j')
		colunaHorizontal = 10;

	if( (linhaHorizontal >= 1 && linhaHorizontal <= 10) && (colunaHorizontal >= 2 && colunaHorizontal <= 9) ) {
		linhaHorizontal--;
		colunaHorizontal--;
		tabuleiro[linhaHorizontal][colunaHorizontal - 1] = 3;
		tabuleiro[linhaHorizontal][colunaHorizontal] = 3; //Essa cordenada define o centro do navio
		tabuleiro[linhaHorizontal][colunaHorizontal + 1] = 3;
	} else {
		printf("Cordenadas inválidas para o navio horizontal: alguma parte do navio está para fora do limite do tabuleiro!\n");
	}


	// Definindo a posição do navio vertical
	printf("Digite a letra correspondente à coluna do segundo barco (vertical): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do segundo barco (vertical): ");
	scanf("%d", &linhaVertical);

	if(verChar == 'A' || verChar == 'a')
		colunaVertical = 1;
	if(verChar == 'B' || verChar == 'b')
		colunaVertical = 2;
	if(verChar == 'C' || verChar == 'c')
		colunaVertical = 3;
	if(verChar == 'D' || verChar == 'd')
		colunaVertical = 4;
	if(verChar == 'E' || verChar == 'e')
		colunaVertical = 5;
	if(verChar == 'F' || verChar == 'f')
		colunaVertical = 6;
	if(verChar == 'G' || verChar == 'g')
		colunaVertical = 7;
	if(verChar == 'H' || verChar == 'h')
		colunaVertical = 8;
	if(verChar == 'I' || verChar == 'i')
		colunaVertical = 9;
	if(verChar == 'J' || verChar == 'j')
		colunaVertical = 10;

	if( (linhaVertical >= 2 && linhaVertical <= 9) && (colunaVertical >= 1 && colunaVertical <= 10) ) {
		linhaVertical--;
		colunaVertical--;
		tabuleiro[linhaVertical - 1][colunaVertical] = 3;
		tabuleiro[linhaVertical][colunaVertical] = 3; //Essa cordenada define o centro do navio
		tabuleiro[linhaVertical + 1][colunaVertical] = 3;
	} else {
		printf("Cordenadas inválidas para o navio vertical: alguma parte do navio está para fora do limite do tabuleiro!\n");
	}


	//Verificando se os navios se sobrepõe
	if(linhaHorizontal == linhaVertical && colunaHorizontal == colunaVertical) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else if(linhaHorizontal == linhaVertical && colunaHorizontal == colunaVertical - 1) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else if(linhaHorizontal == linhaVertical && colunaHorizontal - 1 == colunaVertical) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else if(linhaHorizontal == linhaVertical - 1 && colunaHorizontal - 1 == colunaVertical) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else if(linhaHorizontal == linhaVertical - 1 && colunaHorizontal == colunaVertical) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else if(linhaHorizontal == linhaVertical - 1 && colunaHorizontal == colunaVertical - 1) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else if(linhaHorizontal - 1 == linhaVertical && colunaHorizontal == colunaVertical - 1) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else if(linhaHorizontal - 1 == linhaVertical && colunaHorizontal == colunaVertical) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else if(linhaHorizontal - 1 == linhaVertical && colunaHorizontal - 1 == colunaVertical) {
		printf("Cordenadas inválidas: os navios se sobrepõem\n");
	} else {
		// Exibindo o tabuleiro com os navios que foram cadastrados com exito
		printf("\n TABULEIRO BATALHA NAVAL \n\n");
		printf("   ");

		for(int j = 0; j < 10; j++) {
			printf("%c ", linhas[j]); // Imprime as letras das colunas
		}

		printf("\n");

		for(int i = 0; i < 10; i++) {
			printf("%2d", i + 1);
			for(int j = 0; j < 10; j++) {
				printf(" %d", tabuleiro[i][j]);
			}
			printf("\n");
		}
	}


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
