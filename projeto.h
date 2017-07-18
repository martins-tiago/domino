/*
    \mainpage LP1
    \author Rui Moreira
    \Tiago Martins 24440
    \version 1.0
    \date 2016

R1. Permitir ao utilizador armazenar e gerir um ou mais conjuntos de pe�as de domin�, i.e., inserir e/ou remover as pe�as iniciais dum jogo de m�o usado no
jogo; as pe�as tamb�m podem ser geradas de forma aleat�ria; em nenhum dos casos podem haver pe�as repetidas nos v�rios conjuntos de pe�as m�o envolvidos;

IMPLEMENTADO

R2. Dada uma representa��o de pe�as ou sequ�ncias de pe�as recorrendo a tipos inteiros, permitir gerar as mesmas pe�as ou sequ�ncia usando caracteres/strings,
e vice-versa;

IMPLEMENTADO

R3. Dadas v�rias sequ�ncias de encaixe com tamanhos vari�veis (geradas por um algoritmo ou aleatoriamente) pretende-se permitir ordenar essas pesquisas por
ordem de tamanho (comprimento da sequ�ncia de encaixe);

IMPLEMENTADO

R4. Dadas v�rias sequ�ncias de encaixe com tamanhos vari�veis (geradas por um algoritmo ou aleatoriamente) pretende-se encontrar padr�es de encaixe nessas
sequ�ncias, ou seja, encontrar as posi��es de sub-sequ�ncias pr�-definidas de encaixe;

IMPLEMENTADO

R5. Dada um sequ�ncia de encaixe com v�rias pe�as, permitir substituir um padr�o de encaixe por outro padr�o (os padr�es podem ter tamanhos diferentes); dever�
ser poss�vel tamb�m substituir todas as ocorr�ncias de um padr�o por outro padr�o, numa dada sequ�ncia;

IMPLEMENTADO

R6. A partir de um conjunto de pe�as do jogador e de uma sequ�ncia de encaixe de pe�as inicial j� colocada na mesa de jogo (esta sequ�ncia pode ser vazia),
pretende-se determinar a sequ�ncia de encaixe final que utiliza todas as pe�as dispon�veis; poder�o existir uma ou mais sequ�ncias de encaixe com todas as
pe�as; se n�o for poss�vel encaixar todas as pe�as deve determinar-se a maior sequ�ncia de encaixe poss�vel;

IMPLEMENTADO

R7. Dados dois ou mais conjuntos de pe�as ou jogos de m�o e de uma sequ�ncia de encaixe de pe�as inicial colocada na mesa de jogo (esta sequ�ncia pode ser
vazia), pretende-se determinar se � poss�vel encaixar todas as pe�as desses conjuntos de m�o (retiradas � vez de cada m�o do jogador) de forma a
conseguir-se uma sequ�ncia v�lida; se n�o for poss�vel encaixar todas as pe�as ent�o deve determinar-se a maior sequ�ncia de encaixe poss�vel;

IMPLEMENTADO

R8. Permitir a manipula��o das estruturas de dados atrav�s da entrada e sa�da de dados via ficheiros de texto;

IMPLEMENTADO

R9. Permitir a manipula��o das estruturas de dados atrav�s da entrada e sa�da de dados via ficheiros bin�rios;

IMPLEMENTADO

R10. Permitir a manipula��o das estruturas de dados e das funcionalidades da aplica��o atrav�s de uma estrutura de intera��o baseada em texto (menus);
NB: este requisito aplica-se apenas a uma das implementa��es: i) ou ii).

IMPLEMENTADO

*/

#include <stdio.h> //biblioteca input output
#include <stdlib.h> //inclui fun��es padr�o
#include <string.h> //biblioteca que cont�m fun��es de stirngs
#include <time.h> //biblioteca que utilizo para poder utilizar a fun��o rand()


#define LIN 28 //variavel globais
#define COL 2 //variavel globais
#define COLSTR 4 //variavel globais
#define LINSEQ 800 //variavel globais
#define COLSEQ 200 //variavel globais


typedef struct pecaint
{

    int direito;
    int esquerdo;
    struct pecaint *pnext;


}PECAINT;

typedef struct peca
{

    char *str;
    struct peca *pnext;

}PECA;

typedef struct seq
{

    char *seqstr;

}SEQ;

typedef struct ordena
{

    int tamanho;
    int indice;


}ORDENA;

typedef struct pecasinit
{

    PECA *pfirst;
    PECAINT *pfirstint;
    SEQ *seqf;
    SEQ *seqss;
    SEQ *baralhoaux;
    SEQ *seqssaux;
    ORDENA *ordenaseq;
    int npecasint;
    int npecas;
    int nseqf;
    int nseqss;
    int nbaralhoaux;
    int nseqssaux;
    int nordena;

}PECASINIT;





//Assinatura das fun��es

void load_jogo_bin(PECASINIT *, char []);

void save_jogo_bin(PECASINIT , char []);

int separarseqinvertidasstruct(PECASINIT *);

void load_txt_jogo(PECASINIT *p, char []);

void save_txt_jogo(PECASINIT , char []);

void remove_seqf(PECASINIT *);

void ordernarsequenciasstruct(PECASINIT *);

void remove_seqss(PECASINIT *);

void remove_seqssaux(PECASINIT *);

void criapecasint(int pecasi[][COL], int );

void inserir_seqf(PECASINIT *, char []);

void inserir_baralhoaux(PECASINIT *, char []);

void inserir_seqssaux(PECASINIT *, char []);

void create_array_baralhoaux(PECASINIT *, int );

void inserir_seqss(PECASINIT *, char []);

void create_array_seqf(PECASINIT *, int );

void create_array_seqss(PECASINIT *, int );

void create_array_seqssaux(PECASINIT *, int );

void remove_peca(PECASINIT *p, char remove[]);

void criapecasstr(char pecass[][COLSTR], int );

void printpecasint(int pecasi[][COL], int, int, int );

void printpecasstr(char pecass[][COLSTR], int, int );

void printseqstr(char seqss[][COLSEQ], int, int );

int entregarbaralhos(char pecass[][COLSTR], PECASINIT *p, int n);

int preenchebaralhos(char pecass[][COLSTR],char baralhoss[][COLSTR], int );

int preenchebaralhosstruct(char pecass[][COLSTR], PECASINIT * ,int );

void inserir_peca(PECASINIT *, char pecanova[COLSTR]);

void inserir_pecaint(PECASINIT *, int , int );

void mostrarjogosstr(char baralhoss[][COLSTR], int );

void mostrarjogosstrstruct(PECASINIT ,int );

void mostrarjogosintstruct(PECASINIT , int );

void mostrarjogosint(int baralhosint[][COL], int );

void esvaziabaralhoint(int baralhosi[][COL], int, int );

void esvaziabaralhostr(char baralhoss[][COLSTR], int );

void esvaziabaralhostrstruct(PECASINIT * );

void esvaziaseqstr(char seqss[][COLSEQ], int );

int convertestrtoint(PECASINIT *, int );

int converteinttostr(PECASINIT *, int);

int remover(PECASINIT *, char pecass[][COLSTR], int );

PECA* find_peca_baralho(PECASINIT *, char[]);

int modificar(PECASINIT *, char pecass[][COLSTR], int );

int seq(PECASINIT *, int );

void printseqstr(char seqss[][COLSEQ], int, int );

int procsubseq(char seqf[][COLSEQ], int size, char subs[]);

int procsubseq_trocapadrao(char seqf[][COLSEQ], int size, char subs[], int );

void ordernarsequencias(char seqf[][COLSEQ], int );

void ordernarmatrizinteiros(int m[][2], int );

void trocapadrao(char seqf[][COLSEQ], int size, char padrao[], char padraon[], char seqfpadrao[][COLSEQ], int *sizeseqfpadrao);

int tirartracosinvertidos(char seqf[][COLSEQ], int numdeseq);

int seqcomseqincial(char baralhoss[][COLSTR], char seqf[][COLSEQ], int, char seqinit[]);

int separarseqinvertidas(char seqf[][COLSEQ], int );

int strtoque(char stra[][COLSEQ], char str[], char );

int retiraseqinitrepetida(char seqf[][COLSEQ], int size, char seqinit[]);

int jogoadois(char baralhoss[][COLSTR], char seqf[][COLSEQ], int, char seqinit[]);

int* eliminarep(int *, PECASINIT *p );

char* inverterstr(char str1[], char str2[]);

int baralhoausar(char baralhoss[][COLSTR], char baralhoaux[][COLSEQ], int );

int verificasequencia(char seq[]);

int procsubseq_ausar(char seqf[][COLSEQ], int , char subs[]);

int main_domino(int argc, char *argv[]);

void printseqstrstruct(PECASINIT );


