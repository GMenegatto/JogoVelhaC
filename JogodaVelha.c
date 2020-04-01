///////////////////////////////////////////////////////////////
//JOGO DA VELHA
///////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

char tabuleiroTela(char tabuleiro2[3][3]){
	
	system("COLOR 74");
	system("cls");
	printf("\n\n");
	printf("\t  0 | 1 | 2 \n",		tabuleiro2[0][0], tabuleiro2[0][1], tabuleiro2[0][2]);
	printf("\t0 %c | %c | %c \n", 	tabuleiro2[0][0], tabuleiro2[0][1], tabuleiro2[0][2]);
	printf("\t------------\n");
	printf("\t1 %c | %c | %c \n", 	tabuleiro2[1][0], tabuleiro2[1][1], tabuleiro2[1][2]);
	printf("\t------------\n");	
	printf("\t2 %c | %c | %c \n", 	tabuleiro2[2][0], tabuleiro2[2][1], tabuleiro2[2][2]);
	
}

int main(){
	
	char tabuleiro2[3][3] = {0};
	int tabuleiro[3][3] = {0};
	int jogador = -1;
	int l = 4,c = 4,i,j;
	int soma,check, jogo = 1;
	
	tabuleiroTela(tabuleiro2);
	
	while(jogo == 1){
		if(jogador == -1){
			jogador = 1;
		}													//TROCA DE JOGADORES
		else{
			jogador = -1;
		}													

		printf("\nVez do jogador %d", jogador);
		c = 4;
		
		check = 0;
		while(check == 0){
			c = 4;
			while(c>2||c<0){
			printf("\n\nColuna: ");
			scanf("%d", &c);
		}
			l = 4;
			while(l>2||l<0){
			
			printf("Linha: ");
			scanf("%d", &l);
		}
		if(tabuleiro[l][c] == 0){
			check = 1;
			break;
		}
		else{
			printf("\nJogada nao possivel\n\n");
		}
	}
		tabuleiro[l][c] = jogador;
		
		if(jogador == 1){
			tabuleiro2[l][c] = 'X';
		}
		else{
			tabuleiro2[l][c] = 'O';
		}
		
		tabuleiroTela(tabuleiro2);
		
		for(i = 0; i < 3; i++){
			soma = 0;
			for(j = 0; j < 3; j++){
				soma = soma + tabuleiro[j][i];
				if(soma == 3){
					printf("\njogador 1 ganhou");			// CONDIÇAO DE VITORIA COLUNA
					jogo = 0;
				}
				if(soma == -3){
					printf("\njogador 2 ganhou");
					jogo = 0;
				}
			}
		}
		
				for(i = 0; i < 3; i++){
			soma = 0;
			for(j = 0; j < 3; j++){
				soma = soma + tabuleiro[i][j];
				if(soma == 3){
					printf("\njogador 1 ganhou");			// CONDIÇAO DE VITORIA LINHA
					jogo = 0;
				}
				if(soma == -3){
					printf("\njogador 2 ganhou");
					jogo = 0;
				}
			}
		}
		
		if(tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2] == -3){
			printf("jogador 2 ganhou");
			jogo = 0;
		}
		
		if(tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2] == 3){
			printf("jogador 1 ganhou");
			jogo = 0;
		}
		
		if(tabuleiro[2][0] + tabuleiro[1][1] + tabuleiro[0][2] == -3){
			printf("jogador 2 ganhou");
			jogo = 0;
		}
		
		if(tabuleiro[2][0] + tabuleiro[1][1] + tabuleiro[0][2] == 3){
			printf("jogador 1 ganhou");
			jogo = 0;
		}
		
	}


}

