#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //para poder usar palavras com acentuação

int main() //início da função
{
	setlocale(LC_ALL, "Portuguese"); //para poder usar palavras com acentuação
	int Tab[8][8] = { 0 }, a = 0, b = 0, c; //variáveis do tipo inteiro
	int peao = 1, cav = 2, tor = 3; //variáveis do tipo inteiro
	int bis = 4, rei = 5, rai = 6, semP = 0; //variáveis do tipo inteiro
	int npeao = 0, ncav = 0, ntor = 0, nbis = 0; //variáveis do tipo inteiro
	int nrei = 0, nrai = 0, nsemP = 0; //variáveis do tipo inteiro

	//zerando todas as posições da matriz:
	for (a = 0; a < 8; a++) {
		for (b = 0; b < 8; b++) {
			Tab[a][b] = 0;
		}
	}

	//apresentação e menu para inserção de peças no tabuleiro:
	printf("*********************** TABULEIRO DE XADREZ ***********************\n\n\n");
	printf("____________________MENU PARA INSERÇÃO DE PEÇAS____________________\n\n");
	printf("\t1 - Peão\n");
	printf("\t2 - Cavalo\n");
	printf("\t3 - Torre\n");
	printf("\t4 - Bispo\n");
	printf("\t5 - Rei\n");
	printf("\t6 - Rainha\n");
	printf("\t0 - Não quero inserir peça nesta posição\n\n");
	printf("___________________________________________________________________\n\n");

	//pede para o usuário digitar um número para cada posição no tabuleiro:
	for (a = 0; a < 8; a++) //linhas
	{
		for (b = 0; b < 8; b++) //colunas
		{
			printf("Digite o número da peça que deseja colocar na posição [%d][%d]: ", a+1, b+1);
			scanf_s("%d", &Tab[a][b]);
			while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado

			//laço de repetição para caso o usuário digite um número menor que 0 ou maior que 6:
			while (Tab[a][b] < 0 || Tab[a][b] > 6) {
				printf("Digite um número entre 0 e 6!\n");
				printf("Digite o número da peça que deseja colocar na posição [%d][%d]: ", a, b);
				scanf_s("%d", &Tab[a][b]);
				while ((c = getchar()) != '\n' && c != EOF) {} //para limpar buffer de teclado
			}
		}
		printf("\n"); //para os números não ficarem todos na mesma linha
	}

	printf("\n\n"); //para pular mais linhas

	//imprime o tabuleiro digitado pelo usuário:
	printf("***************** SEU TABULEIRO *****************\n\n");
	for (a = 0; a < 8; a++) //linhas
	{
		for (b = 0; b < 8; b++) //colunas
		{
			printf("  %d", Tab[a][b]); //espaço antes do %d para os nºs não ficarem colados
		}
		printf("\n\n"); //para os caracteres não ficarem todos na mesma linha
	}

	//verifica a quantidade de cada peça no tabuleiro
	for (a = 0; a < 8; a++) {
		for (b = 0; b < 8; b++) {
			switch (Tab[a][b])
			{
			case 1: //quantos 1 o usuário inseriu
				npeao++; // soma 1 peão
				break;
			case 2: //quantos 2 o usuário inseriu
				ncav++; // soma 1 cavalo
				break;
			case 3: //quantos 3 o usuário inseriu
				ntor++; // soma 1 torre
				break;
			case 4: //quantos 4 o usuário inseriu
				nbis++; // soma 1 bispo
				break;
			case 5: //quantos 5 o usuário inseriu
				nrei++; // soma 1 rei
				break;
			case 6: //quantos 6 o usuário inseriu
				nrai++; // soma 1 rainha
				break;
			case 0: //quantos 0 o usuário inseriu
				nsemP++; // soma 1 espaço vazio
				break;
			default:
				break;
			}
		}
	}

	//impressão na tela da quantidade de cada tipo de peça inserida no tabuleiro:
	printf("\n\n***** QUANTIDADE DE CADA TIPO DE PEÇA NO TABULEIRO *****\n\n");
	printf("Você inseriu %d peões no tabuleiro.\n", npeao);
	printf("Você inseriu %d cavalos no tabuleiro.\n", ncav);
	printf("Você inseriu %d torres no tabuleiro.\n", ntor);
	printf("Você inseriu %d bispos no tabuleiro.\n", nbis);
	printf("Você inseriu %d reis no tabuleiro.\n", nrei);
	printf("Você inseriu %d rainhas no tabuleiro.\n", nrai);
	printf("Você deixou %d posições sem peças.\n", nsemP);

	printf("\n\n"); //para pular 2 linhas

	system("pause");
	return 0;
} //fim da função