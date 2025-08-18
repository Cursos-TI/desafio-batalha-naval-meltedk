#include <stdio.h>

int main() {
	//array de caracteres para cordenadas no grid
	char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

	//Declara e inicializa a matriz tabuleiro com valores padrão de 0 para todas as células
	int tabuleiro[10][10];
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			tabuleiro[i][j] = 0;
		}
	}

	int linha, coluna; // Cordenadas de apoio

        char verChar; // Variável de apoio para transformar cordernada vertical de letra para número



	// Imprimindo o tabuleiro vazio
	printf("\n TABULEIRO BATALHA NAVAL \n\n");
	printf("   ");

	for(int j = 0; j < 10; j++) {
		printf("%c ", colunas[j]); // Imprime as letras das colunas
	}

	printf("\n");

	for(int i = 0; i < 10; i++) {
		printf("%2d", i + 1); // Imprime os números das linhas
		for(int j = 0; j < 10; j++) {
			printf(" %d", tabuleiro[i][j]);
		}
		printf("\n");
	}

	printf("\n");



	// Definindo a posição do navio horizontal
	printf("Digite a letra correspondente à coluna do primeiro barco (horizontal): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do primeiro barco (horizontal): ");
	scanf("%d", &linha);

	if(verChar == 'A' || verChar == 'a')
		coluna = 1;
	if(verChar == 'B' || verChar == 'b')
		coluna = 2;
	if(verChar == 'C' || verChar == 'c')
		coluna = 3;
	if(verChar == 'D' || verChar == 'd')
		coluna = 4;
	if(verChar == 'E' || verChar == 'e')
		coluna = 5;
	if(verChar == 'F' || verChar == 'f')
		coluna = 6;
	if(verChar == 'G' || verChar == 'g')
		coluna = 7;
	if(verChar == 'H' || verChar == 'h')
		coluna = 8;
	if(verChar == 'I' || verChar == 'i')
		coluna = 9;
	if(verChar == 'J' || verChar == 'j')
		coluna = 10;

	// Validando de navio está nos limites do tabuleiro
	if( (linha >= 1 && linha <= 10) && (coluna >= 2 && coluna <= 9) ) {
		linha--;
		coluna--;
		//Verificando sobreposição
		if(tabuleiro[linha][coluna - 1] == 3 ||
		tabuleiro[linha][coluna] == 3 ||
		tabuleiro[linha][coluna + 1] == 3) {
			printf("Posição ocupada! Não foi possível posicionar o navio\n");
		} else { // Inserindo o navio no tabuleiro
			tabuleiro[linha][coluna - 1] = 3;
			tabuleiro[linha][coluna] = 3; //Essa cordenada define o centro do navio
			tabuleiro[linha][coluna + 1] = 3;
		}
	} else {
		printf("Cordenadas inválidas para o navio horizontal: alguma parte do navio está para fora do limite do tabuleiro!\n");
	}


	// Definindo a posição do navio vertical
	printf("Digite a letra correspondente à coluna do segundo barco (vertical): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do segundo barco (vertical): ");
	scanf("%d", &linha);

	if(verChar == 'A' || verChar == 'a')
		coluna = 1;
	if(verChar == 'B' || verChar == 'b')
		coluna = 2;
	if(verChar == 'C' || verChar == 'c')
		coluna = 3;
	if(verChar == 'D' || verChar == 'd')
		coluna = 4;
	if(verChar == 'E' || verChar == 'e')
		coluna = 5;
	if(verChar == 'F' || verChar == 'f')
		coluna = 6;
	if(verChar == 'G' || verChar == 'g')
		coluna = 7;
	if(verChar == 'H' || verChar == 'h')
		coluna = 8;
	if(verChar == 'I' || verChar == 'i')
		coluna = 9;
	if(verChar == 'J' || verChar == 'j')
		coluna = 10;

	// Validando de navio está nos limites do tabuleiro
	if( (linha >= 2 && linha <= 9) && (coluna >= 1 && coluna <= 10) ) {
		linha--;
		coluna--;
		//Verificando sobreposição
		if(tabuleiro[linha - 1][coluna] == 3 ||
		tabuleiro[linha][coluna] == 3 ||
		tabuleiro[linha + 1][coluna] == 3) {
			printf("Posição ocupada! Não foi possível posicionar o navio\n");
		} else { // Inserindo o navio no tabuleiro
			tabuleiro[linha - 1][coluna] = 3;
			tabuleiro[linha][coluna] = 3; //Essa cordenada define o centro do navio
			tabuleiro[linha + 1][coluna] = 3;
		}
	} else {
		printf("Cordenadas inválidas para o navio vertical: alguma parte do navio está para fora do limite do tabuleiro!\n");
	}


	// Definindo a posição do navio diagonal primário (\)
	printf("Digite a letra correspondente à coluna do terceiro barco (diagonal primário \\): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do terceiro barco (diagonal primário \\): ");
	scanf("%d", &linha);

	if(verChar == 'A' || verChar == 'a')
		coluna = 1;
	if(verChar == 'B' || verChar == 'b')
		coluna = 2;
	if(verChar == 'C' || verChar == 'c')
		coluna = 3;
	if(verChar == 'D' || verChar == 'd')
		coluna = 4;
	if(verChar == 'E' || verChar == 'e')
		coluna = 5;
	if(verChar == 'F' || verChar == 'f')
		coluna = 6;
	if(verChar == 'G' || verChar == 'g')
		coluna = 7;
	if(verChar == 'H' || verChar == 'h')
		coluna = 8;
	if(verChar == 'I' || verChar == 'i')
		coluna = 9;
	if(verChar == 'J' || verChar == 'j')
		coluna = 10;

	// Validando de navio está nos limites do tabuleiro
	if( (linha >= 2 && linha <= 9) && (coluna >= 2 && coluna <= 9) ) {
		linha--;
		coluna--;
		//Verificando sobreposição
		if(tabuleiro[linha - 1][coluna - 1] == 3 ||
		tabuleiro[linha][coluna] == 3 ||
		tabuleiro[linha + 1][coluna + 1] == 3) {
			printf("Posição ocupada! Não foi possível posicionar o navio\n");
		} else { // Inserindo o navio no tabuleiro
			tabuleiro[linha - 1][coluna - 1] = 3;
			tabuleiro[linha][coluna] = 3; //Essa cordenada define o centro do navio
			tabuleiro[linha + 1][coluna + 1] = 3;
		}
	} else {
		printf("Cordenadas inválidas para o navio diagonal primário: alguma parte do navio está para fora do limite do tabuleiro!\n");
	}



	// Definindo a posição do navio diagonal secundário (/)
	printf("Digite a letra correspondente à coluna do segundo barco (diagonal secundário /): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do segundo barco (diagonal secundário /): ");
	scanf("%d", &linha);

	if(verChar == 'A' || verChar == 'a')
		coluna = 1;
	if(verChar == 'B' || verChar == 'b')
		coluna = 2;
	if(verChar == 'C' || verChar == 'c')
		coluna = 3;
	if(verChar == 'D' || verChar == 'd')
		coluna = 4;
	if(verChar == 'E' || verChar == 'e')
		coluna = 5;
	if(verChar == 'F' || verChar == 'f')
		coluna = 6;
	if(verChar == 'G' || verChar == 'g')
		coluna = 7;
	if(verChar == 'H' || verChar == 'h')
		coluna = 8;
	if(verChar == 'I' || verChar == 'i')
		coluna = 9;
	if(verChar == 'J' || verChar == 'j')
		coluna = 10;

	// Validando de navio está nos limites do tabuleiro
	if( (linha >= 2 && linha <= 9) && (coluna >= 2 && coluna <= 9) ) {
		linha--;
		coluna--;
		//Verificando sobreposição
		if(tabuleiro[linha - 1][coluna + 1] == 3 ||
		tabuleiro[linha][coluna] == 3 ||
		tabuleiro[linha + 1][coluna - 1] == 3) {
			printf("Posição ocupada! Não foi possível posicionar o navio\n");
		} else { // Inserindo o navio no tabuleiro
			tabuleiro[linha - 1][coluna + 1] = 3;
			tabuleiro[linha][coluna] = 3; //Essa cordenada define o centro do navio
			tabuleiro[linha + 1][coluna - 1] = 3;
		}
	} else {
		printf("Cordenadas inválidas para o navio diagonal secundário: alguma parte do navio está para fora do limite do tabuleiro!\n");
	}




	// Exibindo o tabuleiro com os navios que foram cadastrados com exito
	printf("\n TABULEIRO BATALHA NAVAL \n\n");
	printf("   ");

	for(int j = 0; j < 10; j++) {
		printf("%c ", colunas[j]); // Imprime as letras das colunas
	}

	printf("\n");

	for(int i = 0; i < 10; i++) {
		printf("%2d", i + 1); // Imprime os números das linhas
		for(int j = 0; j < 10; j++) {
			printf(" %d", tabuleiro[i][j]);
		}
		printf("\n");
	}

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
