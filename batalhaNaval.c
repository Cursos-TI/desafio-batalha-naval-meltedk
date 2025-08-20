#include <stdio.h>

#define LINHA 3
#define COLUNA 5

int main() {
	//array de caracteres para cordenadas no grid
	char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

	//Declara a matriz tabuleiro
	int tabuleiro[10][10];

	//Declara matriz das habilidades
	int cone[LINHA][COLUNA];
	int cruz[LINHA][COLUNA];
	int octa[LINHA][COLUNA];

	int linha, coluna; // Cordenadas de apoio

    char verChar; // Variável de apoio para transformar cordernada vertical de letra para número

	int pontos = 0; // Usada para contar quantos partes dos navios as habilidades acertaram



	//-CONTRUÇÃO DAS MATRIZES------------------------------------------------------------------------------------------
	//Inicializa a matriz tabuleiro com valores padrão de 0 para todas as células
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			tabuleiro[i][j] = 0;
		}
	}

	// Construção da matriz cone
	for(int i = 0; i < LINHA; i++) {
		for(int j = 0; j < COLUNA; j++) {
			// O cone começa com 1 no topo e expande para baixo
			if( j >= 2 - i && j <= 2 + i && i <= 2 ) {
				cone[i][j] = 1;
			} else {
				cone[i][j] = 0;
			}
		}
	}

	// Construção da matriz Cruz
	for(int i = 0; i < LINHA; i++) {
		for(int j = 0; j < COLUNA; j++) {
			if(i == 1 || j == 2)
	       			cruz[i][j] = 1;
	   		else
	       			cruz[i][j] = 0;
		}
	}

	// Construção da matriz octaedro
	for(int i = 0; i < LINHA; i++) {
		for(int j = 0; j < COLUNA; j++) {
			if( (i == 0 && j == 2) || (i == 1 && j > 0 && j < 4) || (i == 2 && j == 2) )
	       			octa[i][j] = 1;
	   		else
	       			octa[i][j] = 0;
		}
	}



	//-INICIO DO PROGRAMA----------------------------------------------------------------------------------------------

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

	// Legenda
	printf("Legenda:\n");
	printf("0 = Água.\n");
	printf("1 = Área de efeito das habilidade.\n");
	printf("3 = Navios.\n");
	printf("5 = Partes dos navios danificadas por habilidades.\n\n");



	//-LEITURA DAS CORDENADAS DOS NAVIOS-------------------------------------------------------------------------------

	// Definindo a posição do navio horizontal
	printf("\n\n\t*** Defina a posição do navio horizontal *** \n\n");
	printf("Digite a letra correspondente à coluna do primeiro navio (horizontal): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do primeiro navio (horizontal): ");
	scanf("%d", &linha);
	// Troca a letra da coluna por número
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
			printf("\nPosição ocupada! Não foi possível posicionar o navio\n\n");
		} else { // Inserindo o navio no tabuleiro
			tabuleiro[linha][coluna - 1] = 3;
			tabuleiro[linha][coluna] = 3; //Essa cordenada define o centro do navio
			tabuleiro[linha][coluna + 1] = 3;
		}
	} else {
		printf("\nCordenadas inválidas para o navio horizontal: alguma parte do navio está para fora do limite do tabuleiro!\n\n");
	}


	// Definindo a posição do navio vertical
	printf("\n\n\t*** Defina a posição do navio vertical *** \n\n");
	printf("Digite a letra correspondente à coluna do segundo navio (vertical): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do segundo navio (vertical): ");
	scanf("%d", &linha);
	// Troca a letra da coluna por número
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
			printf("\nPosição ocupada! Não foi possível posicionar o navio\n\n");
		} else { // Inserindo o navio no tabuleiro
			tabuleiro[linha - 1][coluna] = 3;
			tabuleiro[linha][coluna] = 3; //Essa cordenada define o centro do navio
			tabuleiro[linha + 1][coluna] = 3;
		}
	} else {
		printf("\nCordenadas inválidas para o navio vertical: alguma parte do navio está para fora do limite do tabuleiro!\n\n");
	}


	// Definindo a posição do navio diagonal primário (\)
	printf("\n\n\t*** Defina a posição do navio diagonal primário (\\) *** \n\n");
	printf("Digite a letra correspondente à coluna do terceiro navio (diagonal primário \\): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do terceiro navio (diagonal primário \\): ");
	scanf("%d", &linha);
	// Troca a letra da coluna por número
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
			printf("\nPosição ocupada! Não foi possível posicionar o navio\n\n");
		} else { // Inserindo o navio no tabuleiro
			tabuleiro[linha - 1][coluna - 1] = 3;
			tabuleiro[linha][coluna] = 3; //Essa cordenada define o centro do navio
			tabuleiro[linha + 1][coluna + 1] = 3;
		}
	} else {
		printf("\nCordenadas inválidas para o navio diagonal primário: alguma parte do navio está para fora do limite do tabuleiro!\n\n");
	}


	// Definindo a posição do navio diagonal secundário (/)
	printf("\n\n\t*** Defina a posição do navio diagonal secundário (\\) *** \n\n");
	printf("Digite a letra correspondente à coluna do quarto navio (diagonal secundário /): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do quarto navio (diagonal secundário /): ");
	scanf("%d", &linha);
	// Troca a letra da coluna por número
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
			printf("\nPosição ocupada! Não foi possível posicionar o navio\n\n");
		} else { // Inserindo o navio no tabuleiro
			tabuleiro[linha - 1][coluna + 1] = 3;
			tabuleiro[linha][coluna] = 3; //Essa cordenada define o centro do navio
			tabuleiro[linha + 1][coluna - 1] = 3;
		}
	} else {
		printf("\nCordenadas inválidas para o navio diagonal secundário: alguma parte do navio está para fora do limite do tabuleiro!\n\n");
	}


	// Exibindo o tabuleiro com os navios que foram registrados com exito
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

	// Legenda
	printf("Legenda:\n");
	printf("0 = Água.\n");
	printf("1 = Área de efeito das habilidade.\n");
	printf("3 = Navios.\n");
	printf("5 = Partes dos navios danificadas por habilidades.\n\n");



	//-LEITURA DAS CORDENADAS DAS HABILIDADES--------------------------------------------------------------------------

	// Posiciona o cone
	printf("\n\n\t*** Defina a posição da habilidade cone *** \n\n");
	printf("Digite a letra correspondente à coluna do cone (para baixo): ");
	scanf(" %c", &verChar);
	printf("Digite a linha do cone (para baixo): ");
	scanf("%d", &linha);
	// Troca a letra da coluna por número
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
	// Verifica se posição é válida
	if( (linha >= 1 && linha <= 8) && (coluna >= 3 && coluna <= 8) ) {
		linha--; //linha = 2; 3 no tabuleiro
		coluna--; //coluna = 4; E no tabuleiro
		// verifica navios e posiciona habilidade no tabuleiro
		for(int i = linha, k = 0; k < 3; i++, k++) { //i = 2; 2 menor que 2 + 2
			for(int j = coluna - 2, l = 0; l < 5; j++, l++) {
				if(tabuleiro[i][j] == 0)
					tabuleiro[i][j] = cone[k][l];
				else if(tabuleiro[i][j] == 3 && cone[k][l] == 1)
					tabuleiro[i][j] = 5;
			}
		}
	} else {
		printf("\nCordenadas inválidas para o ataque em cone, alguma parte do ataque está para fora do tabuleiro\n\n");
	}


	// Posiciona a cruz
	printf("\n\n\t*** Defina a posição da habilidade cruz *** \n\n");
	printf("Digite a letra correspondente à coluna do centro da cruz: ");
	scanf(" %c", &verChar);
	printf("Digite a linha do centro da cruz: ");
	scanf("%d", &linha);
	// Troca a letra da coluna por número
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
	// Verifica se posição é válida
	if( (linha >= 2 && linha <= 9) && (coluna >= 3 && coluna <= 8) ) {
		linha--; //linha = 2; 3 no tabuleiro
		coluna--; //coluna = 4; E no tabuleiro
		// verifica navios e posiciona habilidade no tabuleiro
		for(int i = linha - 1, k = 0; k < 3; i++, k++) { //i = 2; 2 menor que 2 + 2
			for(int j = coluna - 2, l = 0; l < 5; j++, l++) {
				if(tabuleiro[i][j] == 0)
					tabuleiro[i][j] = cruz[k][l];
				else if(tabuleiro[i][j] == 3 && cruz[k][l] == 1)
					tabuleiro[i][j] = 5;
			}
		}
	} else {
		printf("\nCordenadas inválidas para o ataque em octaedro, alguma parte do ataque está para fora do tabuleiro\n\n");
	}


	// Posiciona o octaedro
	printf("\n\n\t*** Defina a posição da habilidade octaedro *** \n\n");
	printf("Digite a letra correspondente à coluna do centro do octaedro: ");
	scanf(" %c", &verChar);
	printf("Digite a linha do centro do octaedro: ");
	scanf("%d", &linha);
	// Troca a letra da coluna por número
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
	// Verifica se posição é válida
	if( (linha >= 2 && linha <= 9) && (coluna >= 2 && coluna <= 9) ) {
		linha--; //linha = 2; 3 no tabuleiro
		coluna--; //coluna = 4; E no tabuleiro
		// verifica navios e posiciona habilidade no tabuleiro
		for(int i = linha - 1, k = 0; k < 3; i++, k++) { //i = 2; 2 menor que 2 + 2
			for(int j = coluna - 2, l = 0; l < 5; j++, l++) {
				if(tabuleiro[i][j] == 0)
					tabuleiro[i][j] = octa[k][l];
				else if(tabuleiro[i][j] == 3 && octa[k][l] == 1)
					tabuleiro[i][j] = 5;
			}
		}
	} else {
		printf("\nCordenadas inválidas para o ataque em cruz, alguma parte do ataque está para fora do tabuleiro\n\n");
	}



	//-EXIBIÇÃO FINAL--------------------------------------------------------------------------------------------------

	// Exibindo o tabuleiro com os navios e as habilidades que foram registradas com exito
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

	// Legenda
	printf("Legenda:\n");
	printf("0 = Água.\n");
	printf("1 = Área de efeito das habilidade.\n");
	printf("3 = Navios.\n");
	printf("5 = Partes dos navios danificadas por habilidades.\n\n");



	// Exibindo quantas partes dos navios foram acertadas
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(tabuleiro[i][j] == 5)
				pontos++;
		}
	}
	printf("\n\nVocê acertou %d partes(s) dos navios!!!\n", pontos);


	return 0;

}