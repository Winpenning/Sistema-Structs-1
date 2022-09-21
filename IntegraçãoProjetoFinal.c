//Declaração das Bibliotecas
#include <stdio.h>
#include <windows.h>
#include <conio.h>

//Declaração das Structs
typedef struct{
    char NomePersonagem[20];
    char Papel[20];
}Personagem;

typedef struct{
    char NomeAnime[25];
    int AnoDeLancamento;

    Personagem Personagem[20];
    int numPersonagens;
}Anime;

typedef struct{
    char Nome[20];
    char Headquarter[15];
    
    int numAnimes;
    Anime Anime[20];
}Estudio;

// Declaração das Funções
int show();
int main();

Estudio addEstudio();
void listarEstudios(Estudio Estudios[], int numEstudios);

Anime addAnime();
void listarAnimes(Estudio Estudios[], int numEstudios);

Personagem addPersonagem();
void listarPersonagens(Estudio Estudios[], int numEstudios);

Estudio addEstudio()
{
    Estudio Estudio;
    printf("    Digite o nome do estudio: ");
    scanf(" %[^\n]s", Estudio.Nome);
    printf("    Digite o headquarter: ");
    scanf(" %[^\n]s", Estudio.Headquarter);
    Estudio.numAnimes = 0;
    printf("\n    Estudios adicionado com sucesso\n\n");
    return Estudio;
}

Anime addAnime()
{
    Anime Anime;

    printf("    Digite o nome do Anime: ");
    scanf(" %[^\n]s", Anime.NomeAnime);
    printf("    Digite o ano de publicação: ");
    scanf("%d", &Anime.AnoDeLancamento);
    Anime.numPersonagens = 0;
    printf("\n    Anime adicionado com sucesso\n\n");
    return Anime;
}

Personagem addPersonagem()
{
    Personagem Personagem;
    printf("    Digite o nome do personagem: ");
    scanf(" %[^\n]s", Personagem.NomePersonagem);
    printf("    Digite o papel do personagem na história: ");
    scanf(" %[^\n]s", Personagem.Papel);
    printf("\n    personagem adicionado com sucesso\n\n");
    return Personagem;
}

void listarEstudios(Estudio Estudios[], int numEstudios)
{
    for (int i = 0; i < numEstudios; i++)
    {
        printf("\n    ID: %d\n    Nome: %s\n    Headquarter: %s\n", i, Estudios[i].Nome, Estudios[i].Headquarter);
    }
    printf("\n\n");
}

void listarAnimes(Estudio Estudios[], int numEstudios)
{
    for (int i = 0; i < numEstudios; i++){
         for(int j = 0; j < Estudios[i].numAnimes; j++){
            printf("\n    ID Anime: %d\n    ID Estudio: %d\n    Estudio: %s\n    Anime: %s\n    Ano de lancamento: %d\n",j, i, Estudios[i].Nome, Estudios[i].Anime[j].NomeAnime, Estudios[i].Anime[j].AnoDeLancamento); 
         }
    }
    printf("\n\n");
}

void listarPersonagens(Estudio Estudios[], int numEstudios)
{
    for (int i = 0; i < numEstudios; i++){
         for(int j = 0; j < Estudios[i].numAnimes; j++){
            for (int q = 0; q < Estudios[i].Anime[j].numPersonagens; q++){
                printf("    ID Anime: %d\n    ID Estudio: %d\n    ID Personagem: %d\n    Estudio: %s\n    Anime: %s\n    Nome do personagem: %s\n    Papel: %s\n",j, i, q, Estudios[i].Nome, Estudios[i].Anime[j].NomeAnime, Estudios[i].Anime[j].Personagem[q].NomePersonagem, Estudios[i].Anime[j].Personagem[q].Papel); 
                printf("\n\n");
            }
         }
    }
    printf("\n\n");
}

int x = 0, y = 0; /// VARI�VEIS GLOBAIS
char mp[3][2] = {'A', 'B',
                 'C', 'D',
                 'E', 'F',}; /// MATRIZ DA INTERFACE
int main()
{
    show(); /// TR�S A FUN��O SHOW PARA DENTRO DE MAIN

    int comando;
    int c = 0, op = 0, numEstudios = 0, numAnimes = 0, numPersonagens = 0;
    Estudio Estudios[20];

    printf("\n    SEJA BEM VINDO!!!\n    Prescione setas ou espaco para iniciar!\n    Prescione 'esc' para sair");

    while(comando != 27) /// 'clique esc para sair'
	{
	    comando = _getch();

		if(comando == 75 && x > 0) { x--; show(); } ///ESQUERDA
		if(comando == 77 && x < 1) { x++; show(); } ///DIREITA
		if(comando == 80 && y < 2) { y++; show(); } ///BAIXO
		if(comando == 72 && y > 0) { y--; show(); } ///CIMA

		if(comando == 32) /// 32 == espa�o
		{
			for(int i = 0; i < 4; i++)
			{
				for(int j = 0; j < 2; j ++)
				{
					if(x == j && y == i)
                    {
                        if(j < 2 && mp[i][j] == 'A') 
                        { 
                            Estudios[numEstudios] = addEstudio();
                            numEstudios ++; 
                        }
						if(j > 0 && mp[i][j] == 'B') 
                        { 
                            if(numEstudios == 0)
                            {
                                puts(" == Sem Estudios Cadastrados ==\n\n");
                            }
                            else
                            {
                                listarEstudios(Estudios, numEstudios);
                            }
                        }
                        if(j < 2 && mp[i][j] == 'C') 
                        { 
                            int cont;
                            int teste = 0 ;

                            if(numEstudios == 0)
                            {
                              puts(" == Sem Estudios Cadastrados ==\n\n");  
                            }
                            
                            if(numEstudios >= 1)
                            {
                                while (teste == 0)
                                {
                                    listarEstudios(Estudios, numEstudios);
                                    printf("Digite o ID do Estudio no qual sera adicionado o Anime: ");
                                    scanf("%d", &cont);
                                    if(cont <= numEstudios && cont >= 0)
                                    {
                                        teste = 1;
                                    }
                                }

                                Estudios[cont].Anime[Estudios[cont].numAnimes] = addAnime();
                                Estudios[cont].numAnimes++;
                                numAnimes++;
                        }
                        }
                        
						if(i < 2 && mp[i][j] == 'D') 
                        { 
                            if(numAnimes == 0)
                            {
                                puts(" == Sem Animes Cadastrados ==\n\n");
                            }
                            else
                            {
                                listarAnimes(Estudios, numEstudios);
                            }  
                        }
						if(i > 0 && mp[i][j] == 'E') 
                        { 
                            if(numEstudios == 0)
                            {
                                puts(" == Sem Estudios Cadastrados ==\n\n");
                            }
                            if(numAnimes == 0)
                            {
                                puts(" == Sem Animes Cadastrados ==\n\n");
                            }
                            else
                            {
                                int kka = 0; 
                                int cont1, cont2;
                                while (kka == 0)
                                {
                                    listarAnimes(Estudios, numEstudios);
                                    printf("Digite o ID do Estudio do anime: ");
                                    scanf("%d", &cont1);
                                    if(cont1 <= numEstudios && cont1 >= 0)
                                    {
                                        kka = 1;
                                    }
                                }
                                kka = 1;
                                while (kka == 1)
                                {
                                    printf("Digite o ID do Anime: ");
                                    scanf("%d", &cont2);
                                    if(cont2 <= Estudios[cont1].numAnimes && cont2 >= 0)
                                    {
                                        kka = 0;
                                    }
                                }
                                Estudios[cont1].Anime[cont2].Personagem[Estudios[cont1].Anime[cont2].numPersonagens] = addPersonagem();
                                Estudios[cont1].Anime[cont2].numPersonagens++;
                                numPersonagens++;
                            }
                        }
                        if(i > 0 && mp[i][j] == 'F') 
                        { 
                            if(numPersonagens == 0)
                            {
                                puts("== Sem personagens cadastrados ==\n\n");
                            }   
                            else
                            {
                                listarPersonagens(Estudios, numEstudios);
                            }
                            
                        }
                    }
				}
			}
		}              
	}
}

int show()
{
    //system("color 0B");   ///CORES
	system("cls");       //Limpa a tela
	printf("    ==========\n\n");

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if (j == x && i == y)
			{
				 printf("    [%c]", mp[i][j]);
			}
			else
			{
				printf("     %c ", mp[i][j]);
			} 
		}
		printf("\n\n");
	}
	puts("    ==========\n    A - Cadastrar Estudio\n    B - Listar Estudio\n    C - Cadastrar Animes\n    D - Listar Animes\n    E - Cadastrar Personagens\n    F - Listar Personagem\n    esc - Sair");
	Sleep(100);
}