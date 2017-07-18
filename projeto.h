/*
    \mainpage LP1
    \author Rui Moreira
    \Tiago Martins 24440
    \version 1.0
    \date 2016

R1. Permitir ao utilizador armazenar e gerir um ou mais conjuntos de peças de dominó, i.e., inserir e/ou remover as peças iniciais dum jogo de mão usado no
jogo; as peças também podem ser geradas de forma aleatória; em nenhum dos casos podem haver peças repetidas nos vários conjuntos de peças mão envolvidos;

IMPLEMENTADO

R2. Dada uma representação de peças ou sequências de peças recorrendo a tipos inteiros, permitir gerar as mesmas peças ou sequência usando caracteres/strings,
e vice-versa;

IMPLEMENTADO

R3. Dadas várias sequências de encaixe com tamanhos variáveis (geradas por um algoritmo ou aleatoriamente) pretende-se permitir ordenar essas pesquisas por
ordem de tamanho (comprimento da sequência de encaixe);

IMPLEMENTADO

R4. Dadas várias sequências de encaixe com tamanhos variáveis (geradas por um algoritmo ou aleatoriamente) pretende-se encontrar padrões de encaixe nessas
sequências, ou seja, encontrar as posições de sub-sequências pré-definidas de encaixe;

IMPLEMENTADO

R5. Dada um sequência de encaixe com várias peças, permitir substituir um padrão de encaixe por outro padrão (os padrões podem ter tamanhos diferentes); deverá
ser possível também substituir todas as ocorrências de um padrão por outro padrão, numa dada sequência;

IMPLEMENTADO

R6. A partir de um conjunto de peças do jogador e de uma sequência de encaixe de peças inicial já colocada na mesa de jogo (esta sequência pode ser vazia),
pretende-se determinar a sequência de encaixe final que utiliza todas as peças disponíveis; poderão existir uma ou mais sequências de encaixe com todas as
peças; se não for possível encaixar todas as peças deve determinar-se a maior sequência de encaixe possível;

IMPLEMENTADO

R7. Dados dois ou mais conjuntos de peças ou jogos de mão e de uma sequência de encaixe de peças inicial colocada na mesa de jogo (esta sequência pode ser
vazia), pretende-se determinar se é possível encaixar todas as peças desses conjuntos de mão (retiradas à vez de cada mão do jogador) de forma a
conseguir-se uma sequência válida; se não for possível encaixar todas as peças então deve determinar-se a maior sequência de encaixe possível;

IMPLEMENTADO

R8. Permitir a manipulação das estruturas de dados através da entrada e saída de dados via ficheiros de texto;

IMPLEMENTADO

R9. Permitir a manipulação das estruturas de dados através da entrada e saída de dados via ficheiros binários;

IMPLEMENTADO

R10. Permitir a manipulação das estruturas de dados e das funcionalidades da aplicação através de uma estrutura de interação baseada em texto (menus);
NB: este requisito aplica-se apenas a uma das implementações: i) ou ii).

IMPLEMENTADO

*/

#include <stdio.h> //biblioteca input output
#include <stdlib.h> //inclui funções padrão
#include <string.h> //biblioteca que contém funções de stirngs
#include <time.h> //biblioteca que utilizo para poder utilizar a função rand()


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





//Assinatura das funções

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


