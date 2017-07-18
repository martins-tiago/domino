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

#include "projeto.h"

/** \brief Função main */


int main_domino(int argc, char *argv[])
{
    /**
        \details função que contém o menu do programa e as respetivas chamadas as funcoes, neste momento estou também a fazer algumas verificações para verificar se as subsequencias a procurar são válidas, se os padrões a substituir são válidos. Estas verificações passarão posteriormente a ser realizadas dentro de funções
        \param int argc não está a ser usado mas contém o numero de posicoes do array de strings argv[] usadas,
        \param char *argv[]  não está a ser usado, mas contém o numero de posições do array de strings
        \return 0
    */

    PECASINIT p= {NULL,NULL,NULL,0,0,0};

    int num=1;
    int jogosaimprimir=0;
    int numdeseq=0;
    int pecasint[LIN][COL];
    int baralhosint[LIN][COL];
    char pecasstr[LIN][COLSTR];
    char baralhosstr[LIN][COLSTR];
    char seqstr[LINSEQ][COLSEQ];
    char subseq[LINSEQ];
    char padrao[LINSEQ]="4|3";
    char padraonovo[LINSEQ]="0|9-9|9-9|3";
    char seqinicial[LINSEQ]="9|9";
    int tam=0;


    //var menu
    char seqinicialaux[LINSEQ];
    char seqinicialpartida[LINSEQ][COLSEQ];
    char pecasstrinv[COLSTR];
    char pecasstraux[LIN][COLSTR];
    char op='0';
    char op1='0';
    char op2='0';
    char op3='0';
    char op4='0';
    int i=0;
    int j=0;
    int r=0;
    int cont=0;
    char subseqinv[COLSEQ];
    int contseq=0;
    int matrizprocurasub[LINSEQ][2];
    int k=0;
    char padraonovoinv[LINSEQ];
    char padraoinv[COLSEQ];
    char seqfpadrao[LINSEQ][COLSEQ];
    int sizeseqfpadrao=0;
    char subseqaux[COLSEQ];
    char auxinv[COLSEQ];
    int tamsubseq=0;
    char seqpadraoaux[LINSEQ][COLSEQ];
    char padraoaux[COLSEQ];
    char baralhosstrauxcominv[LINSEQ][COLSEQ];
    char baralhosstrauxcominvnovo[LINSEQ][COLSEQ];
    char baralhosstrauxcominvnovopadraonovo[LINSEQ][COLSEQ];
    char pecastrauxinvpadroes[LINSEQ][COLSTR];
    char padraototal[COLSEQ];

    //cria pecas todas
    criapecasint(pecasint,LIN);
    criapecasstr(pecasstr,LIN);
    criapecasstr(pecasstraux,LIN);

    //limpa baralhos
    esvaziabaralhoint(baralhosint,LIN,COL);
    esvaziabaralhostr(baralhosstr,LIN);
    esvaziaseqstr(seqstr,LINSEQ);
    esvaziaseqstr(seqfpadrao,LINSEQ);
    esvaziaseqstr(seqinicialpartida,LINSEQ);
    esvaziaseqstr(baralhosstrauxcominv,LINSEQ);
    esvaziaseqstr(baralhosstrauxcominvnovo,LINSEQ);
    esvaziabaralhostr(pecastrauxinvpadroes,LINSEQ);
    esvaziaseqstr(baralhosstrauxcominvnovopadraonovo,LINSEQ);

    create_array_seqf(&p,2);
    create_array_seqss(&p,2);
    create_array_seqssaux(&p,2);
    create_array_baralhoaux(&p,2);

    char filename[]="./lp1.txt";


    /**MENU**/

    while(1)
    {

        switch(op)
        {

        case '0':

            printf("--DOMINO--\n\n");
            printf("1- Ler Jogos do ficheiro\n");
            printf("2- Inserir manualmente\n");
            printf("3- Ler Jogos de um ficheiro binario\n");


            scanf("%c",&op1);
            system("CLS");

            switch(op1)
            {

                case '0':

                    op='0';

                break;

                case '1':

                    load_txt_jogo(&p,filename);
                    mostrarjogosstrstruct(p,7);
                    op='2';
                    scanf("%c",&op2);

                    break;

                break;

                case '2':

                    printf("Quantos jogos pretende:\n");
                    scanf("%d",&num);
                    system("CLS");

                    if (num<1||num>4)
                    {

                        printf("O NUMERO DE JOGOS TEM DE SER ENTRE 1 e 4!!\n");
                        op='0';

                    }
                    else
                    {

                        op='1';

                    }

                break;

                case '3':

                    load_jogo_bin(&p,"DOMINO.BIN");
                    mostrarjogosstrstruct(p,7);
                    op='3';
                    scanf("%c",&op2);

                    break;

                break;

                default:

                    printf("OPCAO INVALIDA\n");
                    op='0';

                break;

            }


        break;


        case '1':

            printf("--MENU--\n\n");
            printf("1- Criar jogo(s) alaeatoriamente\n");
            printf("2- Preencher jogo(s)\n");
            printf("0- Voltar atras\n");
            scanf(" %c",&op2);
            system("CLS");


            switch(op2)
            {

            case '1':

                p.npecas=0;
                p.pfirst=NULL;
                jogosaimprimir=entregarbaralhos(pecasstr,&p,num);

                /*inserir_peca(&p,"2|6");
                inserir_peca(&p,"6|6");
                inserir_peca(&p,"6|4");
                inserir_peca(&p,"4|5");
                inserir_peca(&p,"5|0");
                inserir_peca(&p,"0|3");
                inserir_peca(&p,"3|1");*/
                mostrarjogosstrstruct(p,jogosaimprimir);
                /*
                strcpy(baralhosstr[0],"6|4");
                strcpy(baralhosstr[1],"4|1");
                strcpy(baralhosstr[2],"2|2");
                strcpy(baralhosstr[3],"6|6");
                strcpy(baralhosstr[4],"5|1");
                strcpy(baralhosstr[5],"4|0");
                strcpy(baralhosstr[6],"3|2");
                */
                op='2';

                break;

            case '2':

                p.npecas=0;
                p.pfirst=NULL;
                jogosaimprimir=preenchebaralhosstruct(pecasstr,&p,num);
                mostrarjogosstrstruct(p,jogosaimprimir);
                op='2';

                break;

            case '0':

                op='0';

                break;

            default:

                printf("OPCAO INVALIDA\n");
                op='1';

                break;

            }



            break;

        case '2':

            printf("--MENU--\n\n");
            printf("1- Mostrar sequencias possiveis, (decrescente)\n");
            printf("2- Mostrar sequencias possiveis, (decrescente), com sequencia inicial\n");
            printf("3- Mostrar sequencias possiveis, (decrescente) com jogadores a jogar alternadamente\n");
            printf("4- Alterar Pecas\n");
            printf("5- Converter String para Inteiro\n");
            printf("0- Voltar ao Menu anterior\n\n");

            scanf(" %c",&op2);
            system("CLS");

            switch(op2)
            {

            case '1':

                numdeseq=seq(&p,num);
                ordernarsequenciasstruct(&p);
                separarseqinvertidasstruct(&p);
                printseqstrstruct(p);
                /*numdeseq=seq(baralhosstr,seqstr,num);
                ordernarsequencias(seqstr,numdeseq);
                numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                numdeseq=separarseqinvertidas(seqstr,numdeseq);
                printseqstr(seqstr,0,numdeseq);
                printf("\n");

                mostrarjogosstr(baralhosstr,jogosaimprimir);
                contseq=1;
                */
                op='3';

                break;

            case '2':

                mostrarjogosstr(baralhosstr,jogosaimprimir);
                esvaziaseqstr(seqinicialpartida,LINSEQ);
                esvaziaseqstr(baralhosstrauxcominv,LINSEQ);
                cont=0;
                printf("Insira a sequencia inicial: (SO PODE ESCOLHER PECAS DAS SEGUINTES)\n\n");
                //copia as pecas iniciais para o baralho vazio

                for(i=0; i<LIN; i++)
                {

                    strcpy(baralhosstrauxcominv[i],pecasstr[i]);

                }

                //copio as respetivas invertidas para o baralho auxiliar

                for(j=0; j<LIN; j++)
                {

                    if(pecasstr[j][0]!=pecasstr[j][2])
                    {

                        strcpy(baralhosstrauxcominv[i++],inverterstr(pecasstr[j],auxinv));

                    }

                }


                for(i=0; strcmp(baralhosstrauxcominv[i],"9|9")!=0; i++)
                {

                    for(j=0; strcmp(baralhosstr[j],"9|9")!=0; j++)
                    {

                        if(strcmp(baralhosstrauxcominv[i],baralhosstr[j])==0 || strcmp(baralhosstrauxcominv[i],inverterstr(baralhosstr[j],pecasstrinv))==0)
                        {

                            strcpy(baralhosstrauxcominv[i],"-");

                        }


                    }

                }


                scanf("%s",seqinicial);

                if(verificasequencia(seqinicial)==1)
                {

                    k=1;

                }

                //partimos a sequencia inicial partida e guardamos no array auxiliar
                strcpy(seqinicialaux,seqinicial);
                tamsubseq=strtoque(seqinicialpartida,seqinicialaux,'-');

                //verifico de o padrao novo possui pecas repetidas ou nao

                for(i=0; strcmp(seqinicialpartida[i],"9|9")!=0; i++)
                {

                    for(j=0; strcmp(baralhosstrauxcominv[j],"9|9")!=0; j++)
                    {
                        //printf("%s == %s\n",seqpadraoaux[i],baralhosstrauxcominvnovopadraonovo[j]);
                        if(strcmp(seqinicialpartida[i],baralhosstrauxcominv[j])==0)
                        {

                            strcpy(baralhosstrauxcominv[j],"-");
                            cont++;

                            for(r=0; strcmp(baralhosstrauxcominv[r],"9|9")!=0; r++)
                            {

                                if(strcmp(inverterstr(seqinicialpartida[i],pecasstrinv),baralhosstrauxcominv[r])==0)
                                {

                                    strcpy(baralhosstrauxcominv[r],"-");

                                }


                            }


                        }


                    }


                }


                if(cont!=tamsubseq || k==1)
                {

                    printf("A sequequencia nao e valida!!\n\n");

                    //volta a carregar o pecasstraus com as pecas todas e esvazia o array da sequencia inicial partida
                    for(i=0; i<LIN; i++)
                    {

                        strcpy(pecasstraux[i],pecasstr[i]);

                    }
                    k=0;
                    op2='2';


                }
                else
                {

                    numdeseq=seqcomseqincial(baralhosstr,seqstr,num,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                    numdeseq=separarseqinvertidas(seqstr,numdeseq);
                    tam=retiraseqinitrepetida(seqstr,numdeseq,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=numdeseq-tam;
                    printseqstr(seqstr,0,numdeseq);

                    mostrarjogosstr(baralhosstr,jogosaimprimir);
                    contseq=2;
                    op='3';

                }

                break;

            case '0':

                op='1';

                break;

            case '3':

                if(num<2)
                {

                    printf("O numero de baralhos para esta opcao tem de ser no minimo (2)");
                    op='0';

                }
                else
                {

                    op='4';

                }

                break;


            case '4':

                jogosaimprimir=remover(&p,pecasstr,num);
                mostrarjogosstrstruct(p,jogosaimprimir);

                break;

            case '5':

                printf("String para inteiro || Esvazia o baralho (string) || Inteiro para string\n");
                jogosaimprimir=convertestrtoint(&p,num);
                mostrarjogosintstruct(p,jogosaimprimir);

                esvaziabaralhostrstruct(&p);
                mostrarjogosstrstruct(p,jogosaimprimir);

                jogosaimprimir=converteinttostr(&p,num);
                mostrarjogosstrstruct(p,jogosaimprimir);

                break;

            default:

                printf("OPCAO INVALIDA\n");
                mostrarjogosstr(baralhosstr,jogosaimprimir);

                break;

            }



            break;

        case '3':

            printf("\n\n--MENU--\n\n");
            printf("1- Procurar subsequencias\n");
            printf("2- Substituir padroes nas sequencias\n");
            printf("3- Gravar para ficheiro txt\n");
            printf("4- Gravar para ficheiro binario\n");


            printf("0- Voltar ao menu principal\n\n");

            scanf(" %c",&op3);
            system("CLS");

            switch(op3)
            {

            case '4':

                save_jogo_bin(p,"DOMINO.BIN");

            break;

            case '1':

                if(contseq==1)
                {

                    //numdeseq=seq(baralhosstr,seqstr,num);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                    numdeseq=separarseqinvertidas(seqstr,numdeseq);
                    printseqstr(seqstr,0,numdeseq);
                    printf("\n");

                    mostrarjogosstr(baralhosstr,jogosaimprimir);

                }

                if(contseq==2)
                {

                    numdeseq=seqcomseqincial(baralhosstr,seqstr,num,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                    numdeseq=separarseqinvertidas(seqstr,numdeseq);
                    tam=retiraseqinitrepetida(seqstr,numdeseq,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=numdeseq-tam;
                    printseqstr(seqstr,0,numdeseq);

                    mostrarjogosstr(baralhosstr,jogosaimprimir);

                }


                k=0;
                printf("Qual a sub sequencia a procurar:\n");
                scanf("%s",subseq);

                //fazemos uma copia da subseq
                strcpy(subseqaux,subseq);
                //reinicia os contadores e variavies
                esvaziaseqstr(seqinicialpartida,LINSEQ);
                esvaziaseqstr(baralhosstrauxcominv,LINSEQ);
                cont=0;


                //copia para array auxiliar
                for(i=0; strcmp(baralhosstr[i],"9|9")!=0; i++)
                {

                    strcpy(baralhosstrauxcominv[i],baralhosstr[i]);

                }

                //copia invertidas para array auxiliar
                for(j=0; strcmp(baralhosstr[j],"9|9")!=0; j++)
                {
                    if(baralhosstr[j][0]!=baralhosstr[j][2])
                    {

                        strcpy(baralhosstrauxcominv[i++],inverterstr(baralhosstr[j],auxinv));

                    }


                }

                //se tivermos a usar uma sequencia inicial ao procurar uma subsequencia temos de também poder procurar pelas peças usadas na sequencia inicial

                if(strcmp(seqinicial,"9|9")!=0)
                {

                    strtoque(seqinicialpartida,seqinicial,'-');

                    for(j=0; strcmp(seqinicialpartida[j],"9|9")!=0; j++)
                    {

                        strcpy(baralhosstrauxcominv[i++],seqinicialpartida[j]);

                    }

                    for(j=0; strcmp(seqinicialpartida[j],"9|9")!=0; j++)
                    {

                        if(seqinicialpartida[j][0]!=seqinicialpartida[j][2])
                        {

                            strcpy(baralhosstrauxcominv[i++],inverterstr(baralhosstrauxcominv[j],auxinv));

                        }

                    }

                }

                //esvaziamos o array de strings da sequencia inicial partida para podermos partir a subsequencia

                esvaziaseqstr(seqinicialpartida,LINSEQ);

                tamsubseq=strtoque(seqinicialpartida,subseqaux,'-');


                //verifico de o padrao novo possui pecas repetidas ou nao

                for(i=0; strcmp(seqinicialpartida[i],"9|9")!=0; i++)
                {

                    for(j=0; strcmp(baralhosstrauxcominv[j],"9|9")!=0; j++)
                    {
                        //printf("%s == %s\n",seqpadraoaux[i],baralhosstrauxcominvnovopadraonovo[j]);
                        if(strcmp(seqinicialpartida[i],baralhosstrauxcominv[j])==0)
                        {

                            strcpy(baralhosstrauxcominv[j],"-");
                            cont++;

                            for(r=0; strcmp(baralhosstrauxcominv[r],"9|9")!=0; r++)
                            {

                                if(strcmp(inverterstr(seqinicialpartida[i],pecasstrinv),baralhosstrauxcominv[r])==0)
                                {

                                    strcpy(baralhosstrauxcominv[r],"-");

                                }


                            }


                        }


                    }


                }


                if(k==1 || tamsubseq!=cont)
                {

                    printf("A sequequencia nao e valida!!\n\n");

                    //volta a carregar o pecasstraus com as pecas todas e esvazia o array da sequencia inicial partida
                    for(i=0; i<LIN; i++)
                    {

                        strcpy(pecasstraux[i],pecasstr[i]);

                    }

                    esvaziaseqstr(seqinicialpartida,LINSEQ);
                    esvaziaseqstr(baralhosstrauxcominv,LINSEQ);
                    cont=0;
                    k=0;
                    op2='2';


                }


                if(verificasequencia(subseq)==0)
                {

                    //procura sub-sequencia normal na sequencia e se ecnontrar guarda indicena primeir posicao de uma matriz
                    //e na segundaposição da matriz guarda a primeira peça em que fez o match
                    for(i=0; i<numdeseq; i++)
                    {

                        if(procsubseq_ausar(seqstr,i,subseq)!=-1)
                        {

                            matrizprocurasub[k][0]=i;
                            matrizprocurasub[k][1]=procsubseq_ausar(seqstr,i,subseq);
                            k++;


                        }


                    }
                    //procura sub-sequencia invertida na sequencia e se ecnontrar guarda indicena primeir posicao de uma matriz
                    //e na segundaposição da matriz guarda a primeira peça em que fez o match

                    inverterstr(subseq,subseqinv);

                    for(i=0; i<numdeseq; i++)
                    {

                        if(procsubseq_ausar(seqstr,i,subseqinv)!=-1)
                        {

                            matrizprocurasub[k][0]=i;
                            matrizprocurasub[k][1]=procsubseq_ausar(seqstr,i,subseqinv);
                            k++;

                        }


                    }

                    ordernarmatrizinteiros(matrizprocurasub,k);

                    for(i=0; i<k; i++)
                    {

                        printf("[%d] %s --->  %d\n",matrizprocurasub[i][0],seqstr[matrizprocurasub[i][0]],matrizprocurasub[i][1]);

                    }

                    //esvaziaseqstr(seqfpadrao,LINSEQ);

                }
                else
                {

                    op3='1';

                }

                break;

            case '2':

                if(contseq==1)
                {

                    //numdeseq=seq(baralhosstr,seqstr,num);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                    numdeseq=separarseqinvertidas(seqstr,numdeseq);
                    printseqstr(seqstr,0,numdeseq);
                    printf("\n");

                    mostrarjogosstr(baralhosstr,jogosaimprimir);
                    //contseq=0;

                }

                else if(contseq==2)
                {

                    numdeseq=seqcomseqincial(baralhosstr,seqstr,num,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                    numdeseq=separarseqinvertidas(seqstr,numdeseq);
                    tam=retiraseqinitrepetida(seqstr,numdeseq,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    printseqstr(seqstr,0,numdeseq-tam);

                    mostrarjogosstr(baralhosstr,jogosaimprimir);
                    //contseq=0;
                }
                else
                {

                    mostrarjogosstr(baralhosstr,jogosaimprimir);

                }

                k=0;
                printf("Qual o padrao que pretende substituir:\n");
                scanf("%s",padrao);

                //fazemos uma copia do padrao
                strcpy(padraoaux,padrao);
                //reinicia os contadores e variavies
                esvaziaseqstr(seqinicialpartida,LINSEQ);
                esvaziaseqstr(baralhosstrauxcominv,LINSEQ);
                cont=0;

                //copia para array auxiliar
                for(i=0; strcmp(baralhosstr[i],"9|9")!=0; i++)
                {

                    strcpy(baralhosstrauxcominv[i],baralhosstr[i]);

                }

                //copia invertidas para array auxiliar
                for(j=0; strcmp(baralhosstr[j],"9|9")!=0; j++)
                {
                    if(baralhosstr[j][0]!=baralhosstr[j][2])
                    {

                        strcpy(baralhosstrauxcominv[i++],inverterstr(baralhosstr[j],auxinv));

                    }

                }

                //se tivermos a usar uma sequencia inicial ao procurar uma subsequencia temos de também poder procurar pelas peças usadas na sequencia inicial

                if(strcmp(seqinicial,"9|9")!=0)
                {

                    strtoque(seqinicialpartida,seqinicial,'-');

                    for(j=0; strcmp(seqinicialpartida[j],"9|9")!=0; j++)
                    {

                        strcpy(baralhosstrauxcominv[i++],seqinicialpartida[j]);

                    }

                    for(j=0; strcmp(seqinicialpartida[j],"9|9")!=0; j++)
                    {

                        if(seqinicialpartida[j][0]!=seqinicialpartida[j][2])
                        {

                            strcpy(baralhosstrauxcominv[i++],inverterstr(seqinicialpartida[j],auxinv));

                        }

                    }

                }



                //guardo o array de baralhos, baralhos invertidos e sequencia inicial se existir num array auxiliar

                for(i=0; strcmp(baralhosstrauxcominv[i],"9|9")!=0; i++)
                {

                    strcpy(baralhosstrauxcominvnovo[i],baralhosstrauxcominv[i]);

                }

                for(i=0; strcmp(seqstr[i],"9|9")!=0; i++)
                {

                    esvaziaseqstr(seqpadraoaux,LINSEQ);
                    strtoque(seqpadraoaux,seqstr[i],'-');

                    for(j=0; strcmp(seqpadraoaux[j],"9|9")!=0; j++)
                    {

                        for(k=0; strcmp(baralhosstrauxcominv[k],"9|9")!=0; k++)
                        {

                            if(strcmp(seqpadraoaux[j],baralhosstrauxcominv[k])==0)
                            {

                                strcpy(baralhosstrauxcominv[k],"-");

                            }

                        }

                    }

                    esvaziaseqstr(seqpadraoaux,LINSEQ);

                }

                //retiro no array auxiliar as pecas que nao sairam nas sequencias e essas nao podem estar contidas no padrao a substituir

                for(i=0; strcmp(baralhosstrauxcominv[i],"9|9")!=0; i++)
                {

                    if(strcmp(baralhosstrauxcominvnovo[i],baralhosstrauxcominv[i])==0)
                    {

                        strcpy(baralhosstrauxcominvnovo[k],"-");

                    }

                }

                //retiro as pecas que nao utilizei nas sequencias

                for(j=0; strcmp(baralhosstrauxcominvnovo[j],"9|9")!=0 ; j++)
                {

                    if(strcmp(baralhosstrauxcominv[j],"-")!=0)
                    {

                        strcpy(baralhosstrauxcominvnovo[j],"-");

                    }

                }

                //verifico quais as pecas que podem ter troca de padrao e guardo no array com as suas respetivas invertidas
                cont=0;
                for(i=0; strcmp(baralhosstrauxcominv[i],"9|9")!=0; i++)
                {

                    if(strcmp(baralhosstrauxcominv[i],"-")!=0)
                    {

                        for(j=0; strcmp(baralhosstrauxcominvnovo[j],"9|9")!=0 ; j++)
                        {

                            if(strcmp(inverterstr(baralhosstrauxcominv[i],auxinv),baralhosstrauxcominvnovo[j])==0)
                            {

                                for(k=0; strcmp(baralhosstrauxcominvnovo[k],"9|9")!=0 ; k++)
                                {

                                    if(strcmp(baralhosstrauxcominvnovo[k],"-")==0 && cont==0)
                                    {

                                        strcpy(baralhosstrauxcominvnovo[k],baralhosstrauxcominv[i]);
                                        cont++;

                                    }

                                }
                                cont=0;

                            }

                        }

                    }

                }



                //se for 1 é porque nao é válida o padrao
                if(verificasequencia(padrao)==1)
                {

                    k=1;

                }

                //faz uma copia das pecas que podem ser usadas no padrao a substituir


                for(i=0; strcmp(baralhosstrauxcominvnovo[i],"9|9")!=0; i++)
                {

                    strcpy(baralhosstrauxcominvnovopadraonovo[i],baralhosstrauxcominvnovo[i]);

                }

                //verifica se a peca do padrao a substituir já está a ser usada para nao haver repetidas

                tamsubseq=strtoque(seqpadraoaux,padraoaux,'-');
                cont=0;


                for(i=0; strcmp(seqpadraoaux[i],"9|9")!=0; i++)
                {

                    for(j=0; strcmp(baralhosstrauxcominvnovopadraonovo[j],"9|9")!=0; j++)
                    {
                        //printf("%s == %s\n",seqpadraoaux[i],baralhosstrauxcominvnovopadraonovo[j]);
                        if(strcmp(seqpadraoaux[i],baralhosstrauxcominvnovopadraonovo[j])==0)
                        {

                            strcpy(baralhosstrauxcominvnovopadraonovo[j],"-");
                            cont++;

                            for(r=0; strcmp(baralhosstrauxcominvnovopadraonovo[r],"9|9")!=0; r++)
                            {

                                if(strcmp(inverterstr(seqpadraoaux[i],pecasstrinv),baralhosstrauxcominvnovopadraonovo[r])==0)
                                {

                                    strcpy(baralhosstrauxcominvnovopadraonovo[r],"-");

                                }


                            }


                        }


                    }


                }

                if(k==1 || tamsubseq!=cont)
                {

                    printf("O padrao nao e valido!!\n\n");

                    esvaziaseqstr(seqinicialpartida,LINSEQ);
                    esvaziaseqstr(baralhosstrauxcominv,LINSEQ);
                    esvaziaseqstr(baralhosstrauxcominvnovo,LINSEQ);
                    esvaziaseqstr(baralhosstrauxcominvnovopadraonovo,LINSEQ);
                    cont=0;
                    k=0;
                    op2='2';


                }
                else
                {

                    //Verifico o padrao novo

                    esvaziaseqstr(seqfpadrao,LINSEQ);
                    esvaziaseqstr(baralhosstrauxcominvnovopadraonovo,LINSEQ);
                    esvaziaseqstr(baralhosstrauxcominv,LINSEQ);
                    //faz uma copia das pecas que NAO podem ser usadas no padrao a substituir

                    for(i=0; strcmp(baralhosstrauxcominvnovo[i],"9|9")!=0; i++)
                    {

                        strcpy(baralhosstrauxcominvnovopadraonovo[i],baralhosstrauxcominvnovo[i]);

                    }

                    //pecas iniciais e invertidas
                    for(i=0; i<LIN; i++)
                    {

                        strcpy(baralhosstrauxcominv[i],pecasstr[i]);

                    }

                    for(j=0; j<LIN; j++)
                    {

                        if(pecasstr[j][0]!=pecasstr[j][2])
                        {

                            strcpy(baralhosstrauxcominv[i++],inverterstr(pecasstr[j],auxinv));

                        }

                    }

                    for(i=0; strcmp(baralhosstrauxcominv[i],"9|9")!=0; i++)
                    {

                        for(j=0; strcmp(baralhosstrauxcominvnovopadraonovo[j],"9|9")!=0; j++)
                        {

                            if(strcmp(baralhosstrauxcominv[i],baralhosstrauxcominvnovopadraonovo[j])==0)
                            {

                                strcpy(baralhosstrauxcominv[i],"-");

                            }


                        }

                    }

                    printf("\n\n");


                    printf("Qual o padrao novo:\n");
                    scanf("%s",padraonovo);


                    tamsubseq=strtoque(seqpadraoaux,padraonovo,'-');
                    cont=0;


                    if(verificasequencia(padraonovo)==1)
                    {

                        k=1;

                    }

                    //verifico de o padrao novo possui pecas repetidas ou nao

                    for(i=0; strcmp(seqpadraoaux[i],"9|9")!=0; i++)
                    {

                        for(j=0; strcmp(baralhosstrauxcominv[j],"9|9")!=0; j++)
                        {
                            //printf("%s == %s\n",seqpadraoaux[i],baralhosstrauxcominvnovopadraonovo[j]);
                            if(strcmp(seqpadraoaux[i],baralhosstrauxcominv[j])==0)
                            {

                                strcpy(baralhosstrauxcominv[j],"-");
                                cont++;

                                for(r=0; strcmp(baralhosstrauxcominv[r],"9|9")!=0; r++)
                                {

                                    if(strcmp(inverterstr(seqpadraoaux[i],pecasstrinv),baralhosstrauxcominv[r])==0)
                                    {

                                        strcpy(baralhosstrauxcominv[r],"-");

                                    }


                                }


                            }


                        }


                    }


                    if(k==1 || cont!=tamsubseq)
                    {

                        printf("O padrao novo nao e valido!!\n\n");
                        esvaziaseqstr(seqpadraoaux,LINSEQ);
                        esvaziaseqstr(baralhosstrauxcominv,LINSEQ);
                        esvaziaseqstr(baralhosstrauxcominvnovo,LINSEQ);
                        esvaziaseqstr(baralhosstrauxcominvnovopadraonovo,LINSEQ);

                        cont=0;
                        k=0;
                        op2='2';


                    }
                    else //se for valido substitui pelo padrao novo
                    {

                        inverterstr(padrao,padraoinv);
                        inverterstr(padraonovo,padraonovoinv);

                        //SE QUISERMOS SUBSTITUIR A STRING TODA FAZEMOS ESTE CICLO no fim acrescentamos ao array de seq de padroes
                        for(i=0; strcmp(seqstr[i],"9|9")!=0; i++)
                        {

                            if(strcmp(seqstr[i],padrao)==0 || strcmp(padraoinv,seqstr[i])==0)
                            {

                                strcpy(padraototal,padraonovo);

                            }

                        }

                        //envia o padrao e o paadrao novo normal e invertido

                        trocapadrao(seqstr,numdeseq,padrao,padraonovo,seqfpadrao,&sizeseqfpadrao);
                        trocapadrao(seqstr,numdeseq,padrao,padraonovoinv,seqfpadrao,&sizeseqfpadrao);
                        trocapadrao(seqstr,numdeseq,padraoinv,padraonovo,seqfpadrao,&sizeseqfpadrao);
                        trocapadrao(seqstr,numdeseq,padraoinv,padraonovoinv,seqfpadrao,&sizeseqfpadrao);



                        strcpy(seqfpadrao[sizeseqfpadrao],padraototal);


                        cont=0;
                        for(i=0; strcmp(seqfpadrao[i],"9|9")!=0; i++)
                        {

                            for(j=0; strcmp(seqfpadrao[j],"9|9")!=0; j++)
                            {


                                if(i!=j)
                                {
                                    if(strcmp(seqfpadrao[i],seqfpadrao[j])==0)
                                    {

                                        strcpy(seqfpadrao[i],"-");

                                    }

                                }

                            }

                            cont++;
                        }

                        ordernarsequencias(seqfpadrao,cont);
                        cont=tirartracosinvertidos(seqfpadrao,cont);


                        printseqstr(seqfpadrao,0,cont);


                        esvaziaseqstr(seqfpadrao,LINSEQ);
                        sizeseqfpadrao=0;

                    }

                }

                break;

             case '3':

                save_txt_jogo(p,filename);

            break;


            case '0':

                mostrarjogosstr(baralhosstr,jogosaimprimir);
                op='2';

                break;

            default:

                if(contseq==1)
                {

                    //numdeseq=seq(baralhosstr,seqstr,num);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                    numdeseq=separarseqinvertidas(seqstr,numdeseq);
                    printseqstr(seqstr,0,numdeseq);
                    printf("\n");

                    mostrarjogosstr(baralhosstr,jogosaimprimir);
                    //contseq=0;

                }

                else if(contseq==2)
                {

                    numdeseq=seqcomseqincial(baralhosstr,seqstr,num,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                    numdeseq=separarseqinvertidas(seqstr,numdeseq);
                    tam=retiraseqinitrepetida(seqstr,numdeseq,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    printseqstr(seqstr,0,numdeseq-tam);

                    mostrarjogosstr(baralhosstr,jogosaimprimir);
                    //contseq=0;
                }
                else
                {

                    mostrarjogosstr(baralhosstr,jogosaimprimir);

                }

                break;

            }

            break;

        case '4':

            printf("\n\n--MENU--\n\n");
            printf("1- Começar com uma sequencia\n");
            printf("2- Começar sem sequencia\n");
            printf("0- Voltar ao menu principal\n\n");

            scanf(" %c",&op4);
            system("CLS");

            switch(op4)
            {


            case '1':
                k=0;
                mostrarjogosstr(baralhosstr,jogosaimprimir);
                esvaziaseqstr(seqinicialpartida,LINSEQ);
                cont=0;
                printf("Insira a sequencia inicial:\n");
                scanf("%s",seqinicial);

                if(verificasequencia(seqinicial)==1)
                {

                    k=1;

                }

                //copia as pecas iniciais para o baralho vazio

                for(i=0; i<LIN; i++)
                {

                    strcpy(baralhosstrauxcominv[i],pecasstr[i]);

                }

                //copio as respetivas invertidas para o baralho auxiliar

                for(j=0; j<LIN; j++)
                {

                    if(pecasstr[j][0]!=pecasstr[j][2])
                    {

                        strcpy(baralhosstrauxcominv[i++],inverterstr(pecasstr[j],auxinv));

                    }

                }


                for(i=0; strcmp(baralhosstrauxcominv[i],"9|9")!=0; i++)
                {

                    for(j=0; strcmp(baralhosstr[j],"9|9")!=0; j++)
                    {

                        if(strcmp(baralhosstrauxcominv[i],baralhosstr[j])==0 || strcmp(baralhosstrauxcominv[i],inverterstr(baralhosstr[j],pecasstrinv))==0)
                        {

                            strcpy(baralhosstrauxcominv[i],"-");

                        }


                    }

                }


                //partimos a sequencia inicial partida e guardamos no array auxiliar
                strcpy(seqinicialaux,seqinicial);
                tamsubseq=strtoque(seqinicialpartida,seqinicialaux,'-');

                //verifico de o padrao novo possui pecas repetidas ou nao

                for(i=0; strcmp(seqinicialpartida[i],"9|9")!=0; i++)
                {

                    for(j=0; strcmp(baralhosstrauxcominv[j],"9|9")!=0; j++)
                    {
                        //printf("%s == %s\n",seqpadraoaux[i],baralhosstrauxcominvnovopadraonovo[j]);
                        if(strcmp(seqinicialpartida[i],baralhosstrauxcominv[j])==0)
                        {

                            strcpy(baralhosstrauxcominv[j],"-");
                            cont++;

                            for(r=0; strcmp(baralhosstrauxcominv[r],"9|9")!=0; r++)
                            {

                                if(strcmp(inverterstr(seqinicialpartida[i],pecasstrinv),baralhosstrauxcominv[r])==0)
                                {

                                    strcpy(baralhosstrauxcominv[r],"-");

                                }


                            }


                        }


                    }


                }


                if(cont!=tamsubseq || k==1)
                {

                    printf("A sequequencia nao e valida!!\n\n");

                    //volta a carregar o pecasstraus com as pecas todas e esvazia o array da sequencia inicial partida
                    for(i=0; i<LIN; i++)
                    {

                        strcpy(pecasstraux[i],pecasstr[i]);

                    }
                    k=0;
                    op2='2';


                }
                else
                {

                    for(i=0; i<LIN; i++)
                    {

                        strcpy(pecasstraux[i],pecasstr[i]);

                    }

                    numdeseq=jogoadois(baralhosstr,seqstr,num,seqinicial);
                    ordernarsequencias(seqstr,numdeseq);
                    numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                    numdeseq=separarseqinvertidas(seqstr,numdeseq);
                    printseqstr(seqstr,0,numdeseq);

                    mostrarjogosstr(baralhosstr,jogosaimprimir);
                    contseq=2;
                    op='3';

                }

                break;

            case '2':

                strcpy(seqinicial,"9|9");

                numdeseq=jogoadois(baralhosstr,seqstr,num,seqinicial);
                ordernarsequencias(seqstr,numdeseq);
                numdeseq=tirartracosinvertidos(seqstr,numdeseq);
                numdeseq=separarseqinvertidas(seqstr,numdeseq);
                printseqstr(seqstr,0,numdeseq);

                mostrarjogosstr(baralhosstr,jogosaimprimir);
                contseq=3;
                op='3';

                break;

            case '0':

                op='4';

                break;

            default:

                printf("OPCAO INVALIDA\n");

                break;

            }


            break;

        }

    }

    return 0;

}

/** \brief Função save_jogo_bin*/

void save_jogo_bin(PECASINIT p, char fname[])
{

    /**
    \details função para guardar jogos
    \param char fname[] nome do ficheiro a guardar
    \param PECASINIT p estrutura deste tipo
    */

    PECA *paux=NULL;
    SEQ *paux2=NULL;

    paux=p.pfirst;
    paux2=p.seqf;

    FILE *fp=NULL;

    int size=0;
    int i=0;

    if((fp=fopen(fname,"wb"))!=NULL)
    {

        fwrite(&p.npecas,sizeof(int),1,fp);
        //gravar o numero de pecas


        while(paux!=NULL)
        {

            size=strlen((p.pfirst)->str)+1;
            fwrite(&size,sizeof(int),1,fp);
            fwrite(paux->str,sizeof(char),size,fp);
            paux=paux->pnext;

        }



        for(i=0;i<p.nseqf;i++)
        {

            size=strlen((p.seqf+i)->seqstr)+1;
            fwrite(&size,sizeof(int),1,fp);
            fwrite((paux2+i)->seqstr,sizeof(char),size,fp);

        }
fclose(fp);
    }


}

/** \brief Load do ficheiro binario*/

void load_jogo_bin(PECASINIT *p, char fname[])
{
    /**
    \details funcão para carregar um ficheiro binario
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param char fname[] nome do ficheiro a carregar
    */

    //SE QUISERMOS GUARDAR TODA A ESTRUTURA NUM FICHEIRO
    //fwrite(&t,sizeof(t),1,fp);
    FILE *fp=NULL;

    char nome[50];
    int size=0;
    int i=0;
    int n=0;

    if((fp=fopen(fname,"rb"))!=NULL)
    {

        fread(&(p->npecas),sizeof(int),1,fp);
        n=p->npecas;
        p->npecas=0;


        for(i=0;i<n;i++)
        {


            fread(&size,sizeof(int),1,fp);
            fread(nome,sizeof(char),size,fp);
            inserir_peca(p,nome);


        }

        fclose(fp);

    }

}

/** \brief Load do ficheiro txt*/

void load_txt_jogo(PECASINIT *p, char fname[])
{

  /**
    \details funcão para carregar um ficheiro txt
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param char fname[] nome do ficheiro a carregar
    */

    FILE *fp=NULL;
    char nome[50];
    char ignora[50];
    char njogos[1];
    int i=0;
    int n=0;
    /*%[^:] -> ler até ':'
    %*[:] -> ignorar ':'
    %[^,] -> ler até ';'
    %*[,] -> ignorar ','
    %[^:] -> ler até ':'
    %*[:] -> ignorar ':'
    %d    -> ler inteiro*/

    if((fp=fopen(fname,"r"))==NULL)
    {

        printf("... ERRO ...");
        return;

    }

    //gravo o numero de jogos
    fscanf(fp,"%[^ ]",njogos);
    n=atoi(njogos);

    //nao gravo a palavra jogos
    fscanf(fp,"%[^-] %*[-] %*[\n]",ignora);
    //pecas


    for(i=0;i<n*7;i++)
    {

        fscanf(fp,"%[^\n] %*[ ]",nome);
        inserir_peca(p,nome);

    }


}


/** \brief Função save_jogo_txt*/

void save_txt_jogo(PECASINIT p, char fname[])
{

     /**
    \details função para guardar jogos txt
    \param char fname[] nome do ficheiro a guardar
    \param PECASINIT p estrutura deste tipo
    */


    FILE *fp=NULL;
    int i=0;

    if ((fp = fopen(fname, "w")) == NULL)
    {

        printf("save_txt_jogo(): Erro abrir ficheiro %s\n",fname);
        return;

    }

    int j=0;
    int fim=7;

    PECA *paux=NULL;
    paux=p.pfirst;

    //guarda os jogos no ficheiro

    fprintf(fp,"JOGOS\n\n");

    for(i=0;i<p.npecas/7;i++)
    {

        fprintf(fp,"JOGO %d\n",i+1);

        while(paux!=NULL && j<fim)
        {

            fprintf(fp,"%s\n",paux->str);
            paux=paux->pnext;
            j++;

        }
        j=j+7;
        fim=fim+7;
    }

    //guarda as sequencias

    fprintf(fp,"\n");

    for(i=0; i<p.nseqf; i++)
    {
        if((p.seqf+i)->seqstr!=NULL)
        {

            fprintf(fp,"i=[%d] %s\n",i,(p.seqf+i)->seqstr);

        }


    }


    fclose(fp);

}



/** \brief Criar array dinamico de sequencias*/


void create_array_baralhoaux(PECASINIT *p, int n)
{

    /**
    \details funcão para colocar sequencias no array dinâmico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int n contem a qtde a alocar
    */

    SEQ *pnew=NULL;
    SEQ *paux=NULL;

    int i=0;
    int j=0;

    if(p->baralhoaux==NULL||p->nbaralhoaux==0)
    {

        pnew=(SEQ*)malloc(sizeof(SEQ)*n);
        p->nbaralhoaux=n;

        for(i=0; i<n; i++)
        {

            (pnew+i)->seqstr=NULL;

        }

        p->baralhoaux=pnew;

    }
    else
    {

        p->nbaralhoaux=n;
        pnew=(SEQ*)malloc(sizeof(SEQ)*n);
        paux=p->baralhoaux;

        for(i=0;i<(p->nbaralhoaux-2);i++)
        {

            (pnew+i)->seqstr=(paux+i)->seqstr;


        }

        for(j=i;j<(p->nbaralhoaux);j++)
        {

            (pnew+j)->seqstr=NULL;

        }

        p->baralhoaux=pnew;

    }

}


/** \brief Criar array dinamico de sequencias*/

void create_array_seqss(PECASINIT *p, int n)
{

    /**
    \details funcão para colocar sequencias no array dinâmico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int n contem a qtde a alocar
    */

    SEQ *pnew=NULL;
    SEQ *paux=NULL;

    int i=0;
    int j=0;

    if(p->seqss==NULL||p->nseqss==0)
    {

        pnew=(SEQ*)malloc(sizeof(SEQ)*n);
        p->nseqss=n;

        for(i=0; i<n; i++)
        {

            (pnew+i)->seqstr=NULL;

        }

        p->seqss=pnew;

    }
    else
    {

        p->nseqss=n;
        pnew=(SEQ*)malloc(sizeof(SEQ)*n);
        paux=p->seqss;

        for(i=0;i<(p->nseqss-2);i++)
        {

            (pnew+i)->seqstr=(paux+i)->seqstr;


        }

        for(j=i;j<(p->nseqss);j++)
        {

            (pnew+j)->seqstr=NULL;

        }

        p->seqss=pnew;

    }

}


/** \brief Criar array dinamico de sequencias*/


void create_array_ordenaseq(PECASINIT *p, int n)
{

     /**
    \details funcão para colocar sequencias no array dinâmico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int n contem a qtde a alocar
    */

    ORDENA *pnew=NULL;
    ORDENA *paux=NULL;

    int i=0;
    int j=0;

    if(p->ordenaseq==NULL||p->nordena==0)
    {

        pnew=(ORDENA*)malloc(sizeof(ORDENA)*n);
        p->nordena=n;

        for(i=0; i<n; i++)
        {

            (pnew+i)->indice=0;
            (pnew+i)->tamanho=0;

        }

        p->ordenaseq=pnew;

    }
    else
    {

        p->nordena=n;
        pnew=(ORDENA*)malloc(sizeof(ORDENA)*n);
        paux=p->ordenaseq;

        for(i=0;i<(p->nordena-2);i++)
        {

            (pnew+i)->tamanho=(paux+i)->tamanho;
            (pnew+i)->indice=(paux+i)->indice;


        }

        for(j=i;j<(p->nordena);j++)
        {

            (pnew+j)->tamanho=0;
            (pnew+j)->indice=0;

        }

        p->ordenaseq=pnew;

    }

}

/** \brief Criar array dinamico de sequencias*/

void create_array_seqssaux(PECASINIT *p, int n)
{

    /**
    \details funcão para colocar sequencias no array dinâmico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int n contem a qtde a alocar
    */

    SEQ *pnew=NULL;
    SEQ *paux=NULL;

    int i=0;
    int j=0;

    if(p->seqssaux==NULL||p->nseqssaux==0)
    {

        pnew=(SEQ*)malloc(sizeof(SEQ)*n);
        p->nseqssaux=n;

        for(i=0; i<n; i++)
        {

            (pnew+i)->seqstr=NULL;

        }

        p->seqssaux=pnew;

    }
    else
    {

        p->nseqssaux=n;
        pnew=(SEQ*)malloc(sizeof(SEQ)*n);
        paux=p->seqssaux;

        for(i=0;i<(p->nseqssaux-2);i++)
        {

            (pnew+i)->seqstr=(paux+i)->seqstr;


        }

        for(j=i;j<(p->nseqssaux);j++)
        {

            (pnew+j)->seqstr=NULL;

        }

        p->seqssaux=pnew;

    }

}

/** \brief Criar array dinamico de sequencias*/

void create_array_seqf(PECASINIT *p, int n)
{

    /**
    \details funcão para colocar sequencias no array dinâmico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int n contem a qtde a alocar
    */

    SEQ *pnew=NULL;
    SEQ *paux=NULL;

    int i=0;
    int j=0;

    if(p->seqf==NULL||p->nseqf==0)
    {

        pnew=(SEQ*)malloc(sizeof(SEQ)*n);
        p->nseqf=n;

        for(i=0; i<n; i++)
        {

            (pnew+i)->seqstr=NULL;

        }

        p->seqf=pnew;

    }
    else
    {

        p->nseqf=n;
        pnew=(SEQ*)malloc(sizeof(SEQ)*n);
        paux=p->seqf;

        for(i=0;i<(p->nseqf-2);i++)
        {

            (pnew+i)->seqstr=(paux+i)->seqstr;


        }

        for(j=i;j<(p->nseqf);j++)
        {

            (pnew+j)->seqstr=NULL;

        }

        p->seqf=pnew;

    }

}


/** \brief Criar string dinamica*/

char * create_dyn_string(char str[])
{

    /**
    \details funcão para criar string dinamica
    \param char str[] string a tornar dinamica
    */

    char *paux=NULL;
    int slen = strlen(str)+1;

    paux=(char*)malloc(sizeof(char)*slen);

    strcpy(paux,str);

    return paux;

}

/** \brief Inserir pecas inteiras na lista ligada do baralho*/


void inserir_pecaint(PECASINIT *p, int dir, int esq)
{

    /**
    \details funcão para inserir pecas inteiras nas listas ligadas
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int dir que contem lado direito da peca nova a inserir
    \param int dir que contem lado esquerdo da peca nova a inserir
    */

    PECAINT *pnew = (PECAINT*)malloc(sizeof(PECAINT));
    PECAINT *paux = NULL;

    pnew->direito=dir;
    pnew->esquerdo=esq;
    pnew->pnext=NULL;

    paux=p->pfirstint;

    if(p->pfirstint==NULL)
    {

        p->pfirstint=pnew;
        p->npecasint++;

    }
    else
    {

        //cauda
        while(paux->pnext!=NULL)
        {

            paux=paux->pnext;

        }

        paux->pnext=pnew;
        p->npecasint++;

        return;

    }

}


/** \brief Inserir sequencias de pecas no array dinamico da funçao ordenar*/

void inserir_ordenaseq(PECASINIT *p, int tam, int index)
{

/**
    \details funcão para inserir pecas no array dinâmico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int tam strlen das sequencias
    \param int index indice da sequencia
    */

    ORDENA *paux=NULL;
    paux=p->ordenaseq;

    while(paux!=NULL && paux->tamanho!=0 && (paux - (p->ordenaseq)) < p->nordena)
    {

        paux++;

    }

    if((paux-(p->ordenaseq))==p->nordena)
    {

        create_array_ordenaseq(p,p->nordena+2);
        paux = p->ordenaseq+p->nordena-2;
        paux->tamanho=tam;
        paux->indice=index;

    }else
    {

        paux->tamanho=tam;
        paux->indice=index;

    }

}


/** \brief Inserir pecas na lista ligada do baralho*/

void inserir_peca(PECASINIT *p, char pecanova[COLSTR])
{

    /**
    \details funcão para inserir pecas nas listas ligadas
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param char pecanova[COLSTR] que contem a peca nova a inserir
    */
    //printf("%s\n",pecanova);
    PECA *pnew = (PECA*)malloc(sizeof(PECA));
    PECA *paux = NULL;

    pnew->str = create_dyn_string(pecanova);
    pnew->pnext=NULL;

    paux=p->pfirst;

    if(p->pfirst==NULL)
    {

        p->pfirst=pnew;
        p->npecas++;
        //printf("PRIMEIRA %s  ----   INSERIDAS: %d \n",pnew->str,p->npecas);

    }
    else
    {

        //cauda
        while(paux->pnext!=NULL)
        {

            paux=paux->pnext;

        }

        paux->pnext=pnew;
        p->npecas++;
        //printf("CAUDA %s  ----   INSERIDAS: %d \n",pnew->str,p->npecas);
        return;

    }

}


int preenchebaralhosstruct(char pecass[][COLSTR], PECASINIT *p, int n)
{

    /**
    \details funcão para inserir os baralhos dos jogadores manualmente
    \param int pecass[][COLSTR] array que possui as pecas todas do jogo
    \param PECASINIT *p estrutura do tipo struct
    \param int n numero de jogos a preencher manualmente
    */
    //funcão para inserir os baralhos dos jogadores
    int i=0;
    int jogos=0;
    char aux[4];
    int existe=0;
    int elimina=0;
    int tam=0;
    int cont=0;
    int begin=0;
    char pecasaux[LIN][COLSTR];

    tam=LIN;
    jogos=n*7;
    //guardo as pecas num array auxiliar
    for(i=0; i<tam; i++)
    {

        strcpy(pecasaux[i],pecass[i]);

    }

    printf("SELECIONE %d JOGOS DE (7 PECAS) DA LISTA: (ex: 5|2 )\n\n",n);
    //de 0 até ao numero de jogos a inserir., inserem-se peças peças


        for(i=begin; i<jogos; i++)
        {

            printpecasstr(pecasaux,0,tam);
            scanf("%s",aux);
            system("CLS");

            //Verifica as pecas todas
            for(existe=0; existe<tam; existe++)
            {
                //Se a peca existe nas pecas a escolher então copia-se para o baralho da pessoa
                if(strcmp(pecasaux[existe],aux)==0)
                {


                    inserir_peca(p,pecasaux[existe]);

                    //strcpy(baralhoss[i],pecasaux[existe]);

                    //Coloco todas as peças para cima
                    for(elimina=existe; elimina<(tam-1); elimina++)
                    {

                        strcpy(pecasaux[elimina],pecasaux[elimina+1]);

                    }

                    cont++;

                }
            }
            //se guarda uma peca no baralho da proxima vez já não pode escolher essa peça
            if(cont==1)
            {
                tam--;
                cont=0;

            }
            else
            {
                //Se a peça não existe escreve a mensagem que não é válida
                printf("NAO E VALIDO!\n");
                printf("SELECIONE DA LISTA: (ex: 5|2 )\n\n");
                i--;
            }
        }


    return n*7;

}







/** \brief Função verificasequencia */

int verificasequencia(char seq[])
{


    /**
        \details verifica se a sequência é possível juntar ex:2|3-3|4  estas pecas encaixam e esta funcao faz esta verificação
        \param char seq[] recebe a sequência de peças
        \return Retorna 0 se for possível e 1 se não for
    */

    int cont=0;
    int i=0;

    for(i=0; i<strlen(seq); i++)
    {

        if(seq[i]=='-')
        {

            if(seq[i+1]!=seq[i-1])
            {

                cont++;

            }

        }

    }

    if(cont==0)
    {

        return 0;

    }
    else
    {

        return 1;

    }

}






/** \brief Função eliminarep*/

int* eliminarep(int *pv, PECASINIT *p)
{

    /**
        \details função eliminarep, serve para eliminar as sequencias repetidas, recebe os indices das sequencias e a quantidade de sequencias e remove as repetidas que são as que contém -1 e aloca espaco para as que não sao repetidas e retorna essa quantidade para imprimir só as que não são repetidas
        \param int *pv apontador para um array de inteiros que contém os indices das sequencias
        \param int PECASINIT *p estrutura do tipo PECASINIT *p
        \return retorna o novo tamanho do array de inteiros para depois apenas imprimir as sequências que possuem os indices com sequencias que não são repetidas
    */
    int i=0;
    int j=0;
    int cont=0;
    int k=0;
    int *vaux=NULL;

    for(i=0; i<(p->nseqss); i++)
    {
        if(*(pv+i)!=-1)
        {

            for(j=0; j<(p->nseqss); j++)
            {

                if(*(pv+i)==*(pv+j))
                {

                    cont++;

                }

                if(*(pv+i)==*(pv+j)&&cont>1)
                {

                    *(pv+j)=-1;

                }

            }

            cont=0;

        }

    }

    for(i=0; i<(p->nseqss); i++)
    {

        if(*(pv+i)==-1)
        {

            cont++;

        }

    }

    vaux = (int*)malloc(sizeof(int)*(p->nseqss)-cont);

    for(i=0; i<(p->nseqss); i++)
    {

        //printf("%d ",*(pv+i));
        if(*(pv+i)!=-1)
        {

            *(vaux+k)=*(pv+i);
            k++;
        }

    }

    p->nseqss=(p->nseqss-cont);

    return vaux;

}


/** \brief Função separarseqinvertidas struct*/

int separarseqinvertidasstruct(PECASINIT *p)
{

    /**
    \details função que distingue as sequencias iguais lidas da esquerda para a direita às lidas da direita para a esquerda e chama a funcao elimina rep para retirar as que sao iguais escritas ao contrário
    \param PECASINIT *p estrutura deste tipo
    \return retorna o numero de sequencias
    */

    int i=0;
    int j=0;
    int v[LINSEQ];
    int *vseqs=NULL;
    int nseq=0;

    //esvaziar auxiliar
    nseq=p->nseqss;

    for(i=0;i<nseq;i++)
    {

        remove_seqss(p);

    }

    nseq=p->nseqssaux;

    for(i=0;i<nseq;i++)
    {

        remove_seqssaux(p);

    }

    //inverte as sequencias

    for(i=0;i<p->nseqf;i++)
    {

        inserir_seqss(p,((p->seqf+i)->seqstr));
        while(((p->seqf+i)->seqstr[j])!='\0')
        {

            (p->seqss+i)->seqstr[strlen((p->seqf+i)->seqstr)-1-j]=(p->seqf+i)->seqstr[j];
            j++;

        }
        (p->seqss+i)->seqstr[strlen((p->seqf+i)->seqstr)]='\0';
        j=0;
        v[i]=-1;

    }



    /**dou indices ás sequencias invertidas e ás sequencias normais para dps eliminar os duplicados**/

    for(i=0; i<p->nseqf; i++)
    {

        for(j=0; j<p->nseqf; j++)
        {

            if(strcmp((p->seqf+i)->seqstr,(p->seqf+j)->seqstr)==0 && v[j] == -1)
            {

                v[j]=i;

            }

        }

        for(j=0; j<p->nseqf; j++)
        {

            if(strcmp((p->seqss+i)->seqstr,(p->seqf+j)->seqstr)==0 && v[j] == -1)
            {

                v[j]=i;

            }

        }

    }

    //eliminar repetidos

    vseqs=eliminarep(v,p);

    for(i=0; i<p->nseqss; i++)
    {

        inserir_seqssaux(p,(p->seqf+(*(vseqs+i)))->seqstr);

    }
    free(vseqs);

    nseq=p->nseqf;

    for(i=0;i<nseq;i++)
    {

        remove_seqf(p);

    }

    for(i=0; i<p->nseqss; i++)
    {

        inserir_seqf(p,(p->seqssaux+i)->seqstr);

    }

    return 0;

}


/** \brief Função separarseqinvertidas*/

int separarseqinvertidas(char seqf[][COLSEQ], int numdeseq)
{

    /**
    \details função que distingue as sequencias iguais lidas da esquerda para a direita às lidas da direita para a esquerda e chama a funcao elimina rep para retirar as que sao iguais escritas ao contrário
    \param char seqf[][COLSEQ] array de sequencias
    \param int numdeseq guarda o numero de sequencias
    \return retorna o numero de sequencias
    */

    int i=0;
    int j=0;
    int v[LINSEQ];
    char auxseqinvertidas[LINSEQ][COLSEQ];
    char seqaux[LINSEQ][COLSEQ];
    int *vseqs=NULL;


    //inverte as sequencias
    esvaziaseqstr(auxseqinvertidas,LINSEQ);
    esvaziaseqstr(seqaux,LINSEQ);


    for(i=0; i<numdeseq; i++)
    {

        while(seqf[i][j]!='\0')
        {
            auxseqinvertidas[i][strlen(seqf[i])-1-j]=seqf[i][j];
            j++;

        }
        auxseqinvertidas[i][strlen(seqf[i])]='\0'; // mete um '\0' no fim de string
        j=0;
        v[i]=-1;

    }

    /**dou indices ás sequencias invertidas e ás sequencias normais para dps eliminar os duplicados**/

    for(i=0; i<numdeseq; i++)
    {

        for(j=0; j<numdeseq; j++)
        {

            if(strcmp(seqf[i],seqf[j])==0 && v[j] == -1)
            {

                v[j]=i;

            }

        }


        for(j=0; j<numdeseq; j++)
        {

            if(strcmp(auxseqinvertidas[i],seqf[j])==0 && v[j] == -1)
            {

                v[j]=i;

            }

        }

    }

    //eliminar repetidos

    //vseqs=eliminarep(v,&numdeseq);


    for(i=0; i<numdeseq; i++)
    {

        strcpy(seqaux[i],seqf[*(vseqs+i)]);

    }
    free(vseqs);

    esvaziaseqstr(seqf,LINSEQ);

    for(i=0; i<numdeseq; i++)
    {

        strcpy(seqf[i],seqaux[i]);

    }

    return numdeseq;

}








/** \brief Função criapecasint*/

void criapecasint(int pecasi[][COL], int size)
{

    /**
    \details função que cria as pecas em inteiros
    \param char pecass[][COLSTR] array que guarda as pecas em int
    \param int size contém o numero de pecas a ser guardadas
    */


    int dominomax=6;
    int cont=0;
    int linha=0;
    int coluna=0;


    //percorre 28 vezes para fornecer as 28 peças
    for(linha=0; linha<size; linha++)
    {

        for(coluna=0; coluna<COL; coluna++)
        {

            if (coluna==0)
            {
                //Comeca com o maior lado esquerdo na peça e vai decrementando
                pecasi[linha][coluna]=dominomax;
                //printf("[%d][%d] = %d | ",linha,coluna,pecasi[linha][coluna]);

            }
            if (coluna==1)
            {

                //comeca com o menor lado direito e vai incrementando
                pecasi[linha][coluna]=cont;
                //printf("%d = [%d][%d]\n",pecasi[linha][coluna],linha,coluna);
                cont++;

            }
            if (cont>dominomax)
            {

                dominomax--;
                cont=0;

            }

        }

    }

}

/** \brief Função criapecasstr*/

void criapecasstr(char pecass[][COLSTR], int s)
{

    /**
    \details função que cria as pecas em strings
    \param char pecass[][COLSTR] array que guarda as pecas em string
    \param int s contém o numero de pecas a ser guardadas
    */

    //defino as pecas 28 em string estáticamente
    strcpy(pecass[0],"6|0");
    strcpy(pecass[1],"6|1");
    strcpy(pecass[2],"6|2");
    strcpy(pecass[3],"6|3");
    strcpy(pecass[4],"6|4");
    strcpy(pecass[5],"6|5");
    strcpy(pecass[6],"6|6");
    strcpy(pecass[7],"5|0");
    strcpy(pecass[8],"5|1");
    strcpy(pecass[9],"5|2");
    strcpy(pecass[10],"5|3");
    strcpy(pecass[11],"5|4");
    strcpy(pecass[12],"5|5");
    strcpy(pecass[13],"4|0");
    strcpy(pecass[14],"4|1");
    strcpy(pecass[15],"4|2");
    strcpy(pecass[16],"4|3");
    strcpy(pecass[17],"4|4");
    strcpy(pecass[18],"3|0");
    strcpy(pecass[19],"3|1");
    strcpy(pecass[20],"3|2");
    strcpy(pecass[21],"3|3");
    strcpy(pecass[22],"2|0");
    strcpy(pecass[23],"2|1");
    strcpy(pecass[24],"2|2");
    strcpy(pecass[25],"1|0");
    strcpy(pecass[26],"1|1");
    strcpy(pecass[27],"0|0");

}




/** \brief Função entregarbaralhos*/

int entregarbaralhos(char pecass[][COLSTR], PECASINIT *p, int n)
{

    /**
    \details função que entrega os baralhos aos jogadores aleatóriamente sem pecas repetidas para cada jogador  (baralhos de 7 pecas e máximo de 4 jogadores)
    \param pecass[][COLSTR] array de string que contém as pecas todas
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int n numero de jogos entregues
    */

    int pecas=0;
    //int verifica=0;
    int aux=0;
    int verify=0;
    PECA *paux=NULL;
    paux=p->pfirst;

    srand( (unsigned)time(NULL) );

    //Entrega 4 baralhos
    if (n>4)
    {

        printf("Nao e possivel entregar mais de 4 baralhos\n");

    }
    else
    {
        n=n*7;

        for(pecas=0; pecas<n; pecas++)
        {
            //guardo um valor aleatório entre 0 e 28
            aux=rand() % 28 + 0;

            if(pecas!=0)
            {
                //ciclo para verificar se já existe, senao volta a ter outro numero aleatorio para verificar
                paux=p->pfirst;

                while(paux!=NULL)
                {

                    if(strcmp(paux->str,pecass[aux])==0)
                    {

                        pecas--;
                        verify--;

                    }

                    paux=paux->pnext;

                }

            }
            else
            {
                //na primeira vez insere a peca sem problema
                inserir_peca(p,pecass[aux]);

            }

            //verifica se não é a primeira peca, se não está repetida.
            if(verify==0 && pecas!=0)
            {
                //se a peca a inserir é diferente de todas das outras já inseridas, insiro
                inserir_peca(p,pecass[aux]);

            }
            verify=0;

        }


    }

    return n;

}





/** \brief Função printpecasint*/

void printpecasint(int pecasi[][COL], int l, int c, int inicio)
{

    /**
    \details função que imprime as pecas inteiras
    \param int pecasi[][COL] pecas total inteiras
    \param int l linhas da matriz
    \param int c colunas da matriz
    \param int inicio variavel que contem o numero a partir do qual queremos imprimir
    */

    int i=0;
    int j=0;

    for(i=inicio; i<l; i++)
    {
        for(j=0; j<c; j++)
        {

            printf("%d",pecasi[i][j]);

            if(j==0)
            {

                printf("|");

            }
        }
        printf("\n");
    }

}

/** \brief Função printpecasintstruct*/

void printpecasintstruct(PECASINIT p, int inicio, int fim)
{

    /**
    \details função para imprimir peças inteiras
    \param int inicio desde quando é que queremos imprimir
    \param int fim até onde queremos imprimir
    \param PECASINIT p estrutura deste tipo
    */

    int i=0;

    PECA *paux=NULL;
    paux=p.pfirst;

    while(paux!=NULL && i<fim)
    {

        if(i>=inicio)
        {

            printf("%s\n",paux->str);

        }

        paux=paux->pnext;
        i++;

    }

}

/** \brief Função printpecasintstruct*/

void printpecasstrstruct(PECASINIT p, int inicio, int fim)
{

    /**
    \details função para imprimir peças string
    \param int inicio desde quando é que queremos imprimir
    \param int fim até onde queremos imprimir
    \param PECASINIT p estrutura deste tipo
    */

    int i=0;

    PECA *paux=NULL;
    paux=p.pfirst;

    while(paux!=NULL && i<fim)
    {

        if(i>=inicio)
        {

            printf("%s\n",paux->str);

        }

        paux=paux->pnext;
        i++;

    }

}

/** \brief Função printpecasstr*/

void printpecasstr(char pecass[][COLSTR], int inicio, int fim)
{
    /**
    \details função para imprimir peças string
    \param int inicio desde quando é que queremos imprimir
    \param int fim até onde queremos imprimir
    */
    int i=0;

    for(i=inicio; i<fim; i++)
    {

        printf("%s\n",pecass[i]);

    }

}


/** \brief Função printseqstr*/

void printseqstr(char seqss[][COLSEQ], int inicio, int fim)
{
    /**
    \details função para imprimir sequencias
    \param int inicio desde quando é que queremos imprimir
    \param int fim até onde queremos imprimir
    */

    //funcao para imprimir sequencias de strings
    int i=0;

    for(i=inicio; i<fim; i++)
    {

        printf("i=[%d] %s\n",i,seqss[i]);

    }

}

/** \brief Função printpecasstruct*/

void printseqstrstruct(PECASINIT p)
{
    /**
    \details função para imprimir sequencias
    \param int inicio desde quando é que queremos imprimir
    \param int fim até onde queremos imprimir
     \param PECASINIT p estrutura deste tipo
    */

    //funcao para imprimir sequencias de strings
    int i=0;

    for(i=0; i<p.nseqf; i++)
    {
        if((p.seqf+i)->seqstr!=NULL)
        {

            printf("i=[%d] %s\n",i,(p.seqf+i)->seqstr);

        }


    }

}


/** \brief Função mostrarjogosstrstruct*/

void mostrarjogosstrstruct(PECASINIT p, int njogos)
{
    /**
    \details Funcao que recebe o numero de jogos a imprimir em string e os jogos dos jogadores e imprime separadamente os jogos dos jogadores
    \param PECASINIT p estrutura deste tipo
    \param int njogos numero de jogos a imprimir
    */
    switch(njogos)
    {

    case 7:
        printf("JOGO 1:\n");
        printpecasstrstruct(p,0,14);
        printf("\n");

        break;

    case 14:
        printf("JOGO 1:\n");
        printpecasstrstruct(p,0,7);
        printf("JOGO 2:\n");
        printpecasstrstruct(p,7,14);
        printf("\n");

        break;

    case 21:
        printf("JOGO 1:\n");
        printpecasstrstruct(p,0,7);
        printf("JOGO 2:\n");
        printpecasstrstruct(p,7,14);
        printf("JOGO 3:\n");
        printpecasstrstruct(p,14,21);
        printf("\n");

        break;

    case 28:
        printf("JOGO 1:\n");
        printpecasstrstruct(p,0,7);
        printf("JOGO 2:\n");
        printpecasstrstruct(p,7,14);
        printf("JOGO 3:\n");
        printpecasstrstruct(p,14,21);
        printf("JOGO 4:\n");
        printpecasstrstruct(p,21,28);
        printf("\n");

        break;

    }

}

void mostrarjogosstr(char baralhoss[][COLSTR], int njogos)
{

    /**
    \details Funcao que recebe o numero de jogos a imprimir em string e os jogos dos jogadores e imprime separadamente os jogos dos jogadores
    \param char baralhoss[][COLSTR] array de strings que guarda os jogos dos jogadores
    \param int njogos numero de jogos a imprimir
    */

    switch(njogos)
    {

    case 7:
        printf("JOGO 1:\n");
        printpecasstr(baralhoss,0,7);
        printf("\n");

        break;

    case 14:
        printf("JOGO 1:\n");
        printpecasstr(baralhoss,0,7);
        printf("JOGO 2:\n");
        printpecasstr(baralhoss,7,14);
        printf("\n");

        break;

    case 21:
        printf("JOGO 1:\n");
        printpecasstr(baralhoss,0,7);
        printf("JOGO 2:\n");
        printpecasstr(baralhoss,7,14);
        printf("JOGO 3:\n");
        printpecasstr(baralhoss,14,21);
        printf("\n");

        break;

    case 28:
        printf("JOGO 1:\n");
        printpecasstr(baralhoss,0,7);
        printf("JOGO 2:\n");
        printpecasstr(baralhoss,7,14);
        printf("JOGO 3:\n");
        printpecasstr(baralhoss,14,21);
        printf("JOGO 4:\n");
        printpecasstr(baralhoss,21,28);
        printf("\n");

        break;

    }

}


/** \brief Função mostrarjogosstr*/

void mostrarjogosintstruct(PECASINIT p, int njogos)
{
    /**
    \details Funcao que recebe o numero de jogos a imprimir em string e os jogos dos jogadores e imprime separadamente os jogos dos jogadores
    \param PECASINIT p estrutura deste tipo
    \param int njogos numero de jogos a imprimir
    */
    switch(njogos)
    {

    case 7:
        printf("JOGO 1:\n");
        printpecasintstruct(p,0,7);
        printf("\n");

        break;

    case 14:
        printf("JOGO 1:\n");
        printpecasintstruct(p,0,7);
        printf("JOGO 2:\n");
        printpecasintstruct(p,7,14);
        printf("\n");

        break;

    case 21:
        printf("JOGO 1:\n");
        printpecasintstruct(p,0,7);
        printf("JOGO 2:\n");
        printpecasintstruct(p,7,14);
        printf("JOGO 3:\n");
        printpecasintstruct(p,14,21);
        printf("\n");

        break;

    case 28:
        printf("JOGO 1:\n");
        printpecasintstruct(p,0,7);
        printf("JOGO 2:\n");
        printpecasintstruct(p,7,14);
        printf("JOGO 3:\n");
        printpecasintstruct(p,14,21);
        printf("JOGO 4:\n");
        printpecasintstruct(p,21,28);
        printf("\n");

        break;

    }

}

/** \brief Função mostrarjogosint*/

void mostrarjogosint(int baralhosi[][COL], int njogos)
{
    /**
    \details Funcao que recebe o numero de jogos a imprimir em inteiros e os jogos dos jogadores e imprime separadamente os jogos dos jogadores
    \param int baralhosi[][COL] array de inteiros que guarda os jogos dos jogadores
    \param int njogos numero de jogos a imprimir
    */
    switch(njogos)
    {

    case 7:
        printf("JOGO 1:\n");
        printpecasint(baralhosi,7,2,0);
        printf("\n");

        break;

    case 14:
        printf("JOGO 1:\n");
        printpecasint(baralhosi,7,2,0);
        printf("JOGO 2:\n");
        printpecasint(baralhosi,14,2,7);
        printf("\n");

        break;

    case 21:
        printf("JOGO 1:\n");
        printpecasint(baralhosi,7,2,0);
        printf("JOGO 2:\n");
        printpecasint(baralhosi,14,2,7);
        printf("JOGO 3:\n");
        printpecasint(baralhosi,21,2,14);
        printf("\n");

        break;

    case 28:
        printf("JOGO 1:\n");
        printpecasint(baralhosi,7,2,0);
        printf("JOGO 2:\n");
        printpecasint(baralhosi,14,2,7);
        printf("JOGO 3:\n");
        printpecasint(baralhosi,21,2,14);
        printf("JOGO 4:\n");
        printpecasint(baralhosi,28,2,21);
        printf("\n");

        break;

    }
}


/** \brief Função esvaziabaralhoint*/

void esvaziabaralhoint(int baralhosi[][COL], int lin, int col)
{

    /**
    \details esta funcao coloca o baralho de inteiros vazio
    \param int baralhosi[][COL] baralhos de pecas dos jogadores em inteiros
    \param int lin linhas do baralho a esvaziar
    \param int col colunas do baralho a esvaziar
    */

    //esta funcao coloca o baralho de inteiros vazio
    int i=0;
    int j=0;


    for(i=0; i<lin; i++)
    {

        for(j=0; j<col; j++)
        {

            baralhosi[i][j]=9;

        }

    }

}

/** \brief Função esvaziabaralhostr*/
void esvaziabaralhostrstruct(PECASINIT *p)
{

    /**
    \details esta funcao coloca o baralho de strings vazio
    \param char baralhoss[][COLSTR] baralhos de pecas dos jogadores em strings
    \param int size tamanho do baralho

    */
    //esta funcao coloca o baralho de strings vazio
    PECA *paux=NULL;

    paux=p->pfirst;

    while(paux!=NULL)
    {

        paux->str=NULL;
        p->npecas--;

        paux=paux->pnext;

    }

}



/** \brief Função esvaziabaralhostr*/
void esvaziabaralhostr(char baralhoss[][COLSTR], int size)
{

    /**
    \details esta funcao coloca o baralho de strings vazio
    \param char baralhoss[][COLSTR] baralhos de pecas dos jogadores em strings
    \param int size tamanho do baralho

    */
    //esta funcao coloca o baralho de strings vazio
    int i=0;

    for(i=0; i<size; i++)
    {

        strcpy(baralhoss[i],"9|9");

    }

}



/** \brief Função esvaziaseqstr*/
void esvaziaseqstr(char seqss[][COLSEQ], int size)
{

    /**
    \details esta funcao coloca o array das sequencias vazias
    \param char seqss[][COLSEQ] array de strings das sequencias
    \param int size numero de sequencias inseridas

    */
    //esvazia as sequencias de peças
    int i=0;

    for(i=0; i<size; i++)
    {

        strcpy(seqss[i],"9|9");

    }

}

/** \brief Função convertestrtoint*/

int convertestrtoint(PECASINIT *p, int num)
{

    /**
    \details esta funcao converte as pecas do jogador de string para inteiros
    \param  PECASINIT *p estrutura do tipo PECASINIT
    \param int num numero de jogos a converter
    \return retorna o numero de jogos a imprimir
    */

    //converte as peças dos jogadores de strings paras inteiros

    char aux1[4];
    char aux2[4];

    num=num*7;

    PECA *paux=NULL;

    paux=p->pfirst;
    while(paux!=NULL)
    {

        strcpy(aux1,paux->str);
        strcpy(aux2,paux->str);
        aux1[1]='\0';
        aux2[0]=aux2[2];
        aux2[1]='\0';
        inserir_pecaint(p,atoi(aux1),atoi(aux2));

        paux=paux->pnext;

    }



    return num;


}




/** \brief Função  converteinttostr*/
int converteinttostr(PECASINIT *p, int num)
{
    /**
    \details esta funcao converte as peças inteiras em string
    \param  PECASINIT *p estrutura do tipo PECASINIT
    \param int num numero de jogos a converter
    \return retorna o numero de jogos a imprimir
    */
    //converte as peças inteiras em string

    char aux[4];
    int i=0;
    num=num*7;

    PECAINT *paux=NULL;

    paux=p->pfirstint;

    while(i<(p->npecasint))
    {
        aux[0]='0'+paux->direito;
        aux[1]='|';
        aux[2]='0'+paux->esquerdo;

        inserir_peca(p,aux);

        paux=paux->pnext;

        i++;
    }

    return num;

}

/** \brief Função  remover*/

int remover(PECASINIT *p, char pecass[][COLSTR], int num)
{
    /**
    \details esta funcao remove as pecas inseridas
    \param char baralhoss[][COLSTR] baralhos do jogador em string
    \param char pecass[][COLSTR] pecas todas do jogo em strings
    \param int num numero de jogos a converter
    \return retorna o numero de jogos a remover
    */
    int i=0;
    int n=num;
    char aux[4];
    char remove[4];
    int pecasaremover=0;
    n=n*7;

    PECA *pfind=NULL;


    do
    {

        mostrarjogosstrstruct(*p,n);
        printf("\nQUANTAS PECAS PRETENDE REMOVER?\n");
        scanf("%d",&pecasaremover);
        system("CLS");

        if(pecasaremover>n)
        {

            printf("NAO PODE REMOVER ESSE NUMERO DE PECAS!!!\n\n");
            mostrarjogosstrstruct(*p,n);

        }

    }
    while(pecasaremover>n);

    system("CLS");

    for(i=0; i<pecasaremover; i++)
    {

        mostrarjogosstrstruct(*p,n);
        printf("QUAL A PECA A REMOVER:\n");
        scanf("%s",aux);
        system("CLS");

        pfind=find_peca_baralho(p,aux);

        if(pfind==NULL)
        {

            printf("A PECA QUE ESCOLHEU NAO E VALIDA!\n");

            if(i==0)
            {

                i=0;

            }

            else
            {

                i--;

            }

        }
        else
        {

            strcpy(remove,pfind->str);
            remove_peca(p,remove);

        }

    }

    printf("INSIRA AS %d PECAS NOVAS\n",pecasaremover);
    for(i=0; i<pecasaremover; i++)
    {
        mostrarjogosstrstruct(*p,n);
        scanf("%s",aux);
        pfind=find_peca_baralho(p,aux);

        if(pfind!=NULL)
        {

            printf("A PECA QUE ESCOLHEU NAO E VALIDA!\n");

            if(i==0)
            {

                i=0;

            }

            else
            {

                i--;

            }

        }else
        {

            inserir_peca(p,aux);

        }



    }

    return n;

}

void remove_seqf(PECASINIT *p)
{

    SEQ *paux=NULL;
    paux=p->seqf;

    //cabeca
    p->seqf=paux+1;
    p->nseqf--;
    return;

}

void remove_seqss(PECASINIT *p)
{

    SEQ *paux=NULL;
    paux=p->seqss;

    //cabeca
    p->seqss=paux+1;
    p->nseqss--;
    return;

}

void remove_seqssaux(PECASINIT *p)
{

    SEQ *paux=NULL;
    paux=p->seqssaux;

    //cabeca
    p->seqssaux=paux+1;
    p->nseqssaux--;
    return;

}

/** \brief Remover pecas dos jogos*/

void remove_peca(PECASINIT *p, char remove[])
{

    /**
    \details funcão para remover pecas nas listas ligadas
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param int n numero de jogos a preencher manualmente
    */

    PECA *paux=NULL;
    PECA *pant=NULL;

    paux=p->pfirst;

    //cabeca
    if(strcmp(paux->str,remove)==0)
    {

        p->pfirst=paux->pnext;
        p->npecas--;
        return;

    }

    //cauda
    paux=p->pfirst;
    while(paux->pnext!=NULL)
    {

        pant=paux;
        paux=paux->pnext;

    }

    if(strcmp(paux->str,remove)==0)
    {

        pant->pnext=NULL;
        p->npecas--;
        return;

    }
    //meio
    paux=p->pfirst;
    while(paux->pnext!=NULL)
    {

        pant=paux;
        paux=paux->pnext;

        if(strcmp(paux->str,remove)==0)
        {

            pant->pnext=paux->pnext;
            p->npecas--;
            return;
        }

    }

}

/** \brief Procurar peca no baralho*/

PECA* find_peca_baralho(PECASINIT *p, char aux[])
{

    /**
    \details funcão para procurar e retornar a peca se encontrar e null se nao encontrar
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param char aux[] peca a procurar
    */

    PECA *paux=NULL;
    paux=p->pfirst;


    while(paux!=NULL)
    {

        if(strcmp(paux->str,aux)==0)
        {

            return paux;

        }

        paux=paux->pnext;

    }

    return NULL;

}



/** \brief Inserir sequencias no array dinamico das seqs auxiliares*/

void inserir_seqss(PECASINIT *p, char sequencia[])
{

    /**
    \details funcão para inserir sequencias no array dinamico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param char sequencia[] contem sequencia a inserir
    */

    SEQ *paux=NULL;
    paux=p->seqss;

    while(paux!=NULL && paux->seqstr!=NULL && (paux - (p->seqss)) < p->nseqss)
    {

        paux++;

    }

    if((paux-(p->seqss))==p->nseqss)
    {

        create_array_seqss(p,p->nseqss+2);
        paux = p->seqss+p->nseqss-2;
        paux->seqstr=create_dyn_string(sequencia);

    }else
    {

        paux->seqstr=create_dyn_string(sequencia);

    }

}


/** \brief Inserir sequencias no array dinamico das seqs auxiliares 2*/

void inserir_seqssaux(PECASINIT *p, char sequencia[])
{

     /**
    \details funcão para inserir sequencias no array dinamico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param char sequencia[] contem sequencia a inserir
    */

    SEQ *paux=NULL;
    paux=p->seqssaux;

    while(paux!=NULL && paux->seqstr!=NULL && (paux - (p->seqssaux)) < p->nseqssaux)
    {

        paux++;

    }

    if((paux-(p->seqssaux))==p->nseqssaux)
    {

        create_array_seqssaux(p,p->nseqssaux+2);
        paux = p->seqssaux+p->nseqssaux-2;
        paux->seqstr=create_dyn_string(sequencia);

    }else
    {

        paux->seqstr=create_dyn_string(sequencia);

    }

}

/** \brief Inserir sequencias no array dinamico das seqs*/

void inserir_seqf(PECASINIT *p, char sequencia[])
{

    /**
    \details funcão para inserir sequencias no array dinamico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param char sequencia[] contem sequencia a inserir
    */

    SEQ *paux=NULL;
    paux=p->seqf;

    while(paux!=NULL && paux->seqstr!=NULL && (paux - (p->seqf)) < p->nseqf)
    {

        paux++;

    }

    if((paux-(p->seqf))==p->nseqf)
    {

        create_array_seqf(p,p->nseqf+2);
        paux = p->seqf+p->nseqf-2;
        paux->seqstr=create_dyn_string(sequencia);

    }else
    {

        paux->seqstr=create_dyn_string(sequencia);

    }

}

/** \brief Inserir sequencias de pecas no array dinamico*/

void inserir_baralhoaux(PECASINIT *p, char sequencia[])
{

/**
    \details funcão para inserir pecas no array dinâmico
    \param PECASINIT *p estrutura do tipo PECASINIT
    \param char sequencia[] contem a sequencia a inserir
    */

    SEQ *paux=NULL;
    paux=p->baralhoaux;

    while(paux!=NULL && paux->seqstr!=NULL && (paux - (p->baralhoaux)) < p->nbaralhoaux)
    {

        paux++;

    }

    if((paux-(p->baralhoaux))==p->nbaralhoaux)
    {

        create_array_baralhoaux(p,p->nbaralhoaux+2);
        paux = p->baralhoaux+p->nbaralhoaux-2;
        paux->seqstr=create_dyn_string(sequencia);

    }else
    {

        paux->seqstr=create_dyn_string(sequencia);

    }

}


/** \brief Função  seq*/

int seq(PECASINIT *p, int num)
{

    /**
    \details função para criar as sequencias de peças existentes
    \param PECASINIT *p estrutura deste tipo
    \param int num numero de jogos a calcular sequencias
    \return retorna o numero de sequencias que encontrou
    */
    //função para criar as sequencias de peças existentes
    /*char seqss[LINSEQ][COLSEQ];
    char baralhoaux[LINSEQ][COLSTR];
    char seqssaux[LINSEQ][COLSEQ];
    int l=0;
    int i=0;
    int j=0;
    int k=0;

    int cont=0;
    int invertidos=0;


    char aux[2000];
    char *s=NULL;
    int contadorfinal=0;
    char auxdir='0';*/
    int nseq=0;
    int fimdastring=0;
    int iguais=0;
    char *s=NULL;
    char aux[2000];
    char auxseqf[2000];
    int n=0;
    int i=0;
    int j=0;
    int k=0;
    int cont=0;
    int invertidos=0;
    PECA *paux=NULL;
    char auxdir='0';

    paux=p->pfirst;

    n=num*7;
    while(paux!=NULL)
    {

        inserir_seqss(p,paux->str);
        paux=paux->pnext;

    }



    for(i=0;i<p->nseqss;i++)
    {

        if((p->seqss+i)->seqstr!=NULL)
        {

             invertidos++;

        }

    }

    p->nseqss=invertidos;
    n=invertidos;

    while(j<n)
    {

        if(((p->seqss+j)->seqstr)[0]==((p->seqss+j)->seqstr)[2])
        {

            j++;

        }
        else
        {

            inserir_seqss(p,((p->seqss+j)->seqstr));
            auxdir=((p->seqss+j)->seqstr)[0];
            ((p->seqss+invertidos)->seqstr)[0]=((p->seqss+invertidos)->seqstr)[2];
            ((p->seqss+invertidos)->seqstr)[2]=auxdir;
            invertidos++;
            j++;

        }

    }

    for(i=0;i<invertidos;i++)
    {

        inserir_baralhoaux(p,(p->seqss+i)->seqstr);

    }

    p->nbaralhoaux=invertidos;


    n=invertidos;

    do{
        cont=0;

        for(i=0; i<invertidos; i++)
        {

            for(j=0; j<p->nseqss; j++)
            {

                if(k!=0)
                {

                   // strcpy(aux,seqss[j]);
                    strcpy(aux,(p->seqss+j)->seqstr);

                    s = strtok (aux,"-");

                    while (s!= NULL)
                    {

                        if(strcmp((p->baralhoaux+i)->seqstr,s)==0 || (s[2]==((p->baralhoaux+i)->seqstr[0]) && s[0]==((p->baralhoaux+i)->seqstr[2])))
                        {

                            iguais++;

                        }

                        s = strtok (NULL, "-");

                    }

                    strcpy(aux,"");
                }


                //se for uma peça diferente das que são usadas nas sequencias já inseridas
                if(iguais==0)
                {

                    //verifico o tamanho da sequencia já existente
                    fimdastring=strlen((p->seqss+j)->seqstr)-1;

                    //se houver encaixe entre a peça ou sequencias de peças e a peça for diferente da que já está guardada
                    if((((p->seqss+j)->seqstr)[fimdastring])==((p->baralhoaux+i)->seqstr)[0] && strcmp(((p->seqss+j)->seqstr),((p->baralhoaux+i)->seqstr))!=0)
                    {
                        //se já nao vou montar sequencias pela primeira vez e se há encaixe possivel normal ou invertidamente
                        if(k==0 && (((p->seqss+j)->seqstr)[fimdastring])==((p->baralhoaux+i)->seqstr)[0] && ((p->seqss+j)->seqstr)[0]==((p->baralhoaux+i)->seqstr)[2])
                        {


                        }
                        else
                        {

                            cont++;
                            strcpy(auxseqf,((p->seqss+j)->seqstr));
                            strcat(auxseqf,"-");
                            strcat(auxseqf,((p->baralhoaux+i)->seqstr));
                            inserir_seqf(p,auxseqf);
                            //guardo a sequencia que fiz num array final e incremento a variavel que vou testar no final do ciclo todo para ver se houve posivbilidade montar sequencias ou não

                        }


                    }

                }
                iguais=0;

            }

        }

        //faço as mesmas verificações acima para aumentar o array de sequencias auxiliar para as ultimas sequencias feitas
        //para tentar da proxima vez fazer sequencias novas com as sequencias já obtidas
        for(i=0; i<invertidos; i++)
        {

            for(j=0; j<p->nseqss; j++)
            {

                if(k!=0)
                {

                    strcpy(aux,(p->seqss+j)->seqstr);

                    s = strtok (aux,"-");

                    while (s!= NULL)
                    {

                        if(strcmp((p->baralhoaux+i)->seqstr,s)==0 || (s[2]==((p->baralhoaux+i)->seqstr[0]) && s[0]==((p->baralhoaux+i)->seqstr[2])))
                        {

                            iguais++;

                        }

                        s = strtok (NULL, "-");

                    }

                    strcpy(aux,"");

                    if(iguais==0)
                    {

                        fimdastring=strlen((p->seqss+j)->seqstr)-1;


                        if((((p->seqss+j)->seqstr)[fimdastring])==((p->baralhoaux+i)->seqstr)[0] && strcmp(((p->seqss+j)->seqstr),((p->baralhoaux+i)->seqstr))!=0)
                        {

                            strcpy(auxseqf,((p->seqss+j)->seqstr));
                            strcat(auxseqf,"-");
                            strcat(auxseqf,((p->baralhoaux+i)->seqstr));
                            inserir_seqssaux(p,auxseqf);

                        }

                    }

                }

                else
                {

                    fimdastring=strlen((p->seqss+j)->seqstr)-1;

                    if((((p->seqss+j)->seqstr)[fimdastring])==((p->baralhoaux+i)->seqstr)[0] && strcmp(((p->seqss+j)->seqstr),((p->baralhoaux+i)->seqstr))!=0)
                    {


                        if((((p->seqss+j)->seqstr)[fimdastring])==((p->baralhoaux+i)->seqstr)[0] && ((p->seqss+j)->seqstr)[0]==((p->baralhoaux+i)->seqstr)[2])
                        {


                        }
                        else
                        {

                            strcpy(auxseqf,((p->seqss+j)->seqstr));
                            strcat(auxseqf,"-");
                            strcat(auxseqf,((p->baralhoaux+i)->seqstr));
                            inserir_seqssaux(p,auxseqf);

                        }

                    }

                }
                iguais=0;
            }

        }


        //por fim colocamos o array de seqss auxiliar vazio e preencho-o com as novas sequencias feitas

        nseq=p->nseqss;

        for(i=0;i<nseq;i++)
        {

            remove_seqss(p);

        }


        for(i=0;i<p->nseqssaux;i++)
        {

            inserir_seqss(p,(p->seqssaux+i)->seqstr);

        }

        nseq=p->nseqssaux;

        for(i=0;i<nseq;i++)
        {

            remove_seqssaux(p);

        }

        k++;

    }
    //faço tudo isto até não haver possibilidades de fazer combinações de sequencias,
    //porque quando não houver sequencias a fazer é sinal que o ciclo tem de acabar
    while(cont>0);

    //retorno o numero de sequencias feitas
    return 0;

}


/** \brief Função  inverterstr*/

char* inverterstr(char str1[], char str2[])
{

    /**
    \details função para inverter uma sequencia
    \param char str1[] string a inverter
    \param char str2[] string invertida a retornar
    \return retorna a string invertida
    */

    //funcao que retorna uma sequencia de peças invertida
    int invertidas=0;

    for(invertidas=0; str1[invertidas]!='\0'; invertidas++)
    {

        str2[invertidas]=str1[strlen(str1)-1-invertidas];

    }

    return str2;

}




/** \brief Função  procsubseq_ausar*/
int procsubseq_ausar(char seqf[][COLSEQ], int size, char subs[])
{

    /**
    \details função para procurar uma substring numa string
    \param char seqf[][COLSEQ] array final de strings
    \param int size numero da linha do array de strings final que vamos querer procurar uma substring
    \param char subs[] sub string a procurar
    \return retorna a posicao em que encontrou a substring
    */
    //esta função procura sequencias de peças noutras sequencias, ou peças em sequencias
    int i=0;
    int k=0;
    int cont=0;
    int pos=0;
    int x=0;
    int v[LINSEQ];
    int tamstr1=0;
    int tamstr2=0;
    char arrayseq[LINSEQ][COLSEQ];
    char arraysub[LINSEQ][COLSEQ];

    //o size neste caso é a linha do array de strings

    //faço o strtok da sequencias de peças
    tamstr1=strtoque(arrayseq,seqf[size],'-');
    //faço o strtok da sequencia a procurar
    tamstr2=strtoque(arraysub,subs,'-');

    for (i=0; i<tamstr1; i++)
    {
        //enquanto não estiver no fim da sequencia e houver igualdades entre a sequencia e a sub sequencia vou comparando a proxima peça da subsequencia com a peça da sequencia
        if(strcmp(arrayseq[i],arraysub[k])==0)
        {
            if(k==0)
            {
                //guardo a posição em que encontrei a primeira igualdade entre a subsequencia e a sequencia
                pos=i;
            }
            cont++;
            k++;


            //se a sub sequencia e a sequencia são iguais então guardo a posição num array de inteiros e procuro outra igualdade
            //se é que existe entre a subsequencia e a sequencia de peças

            if(cont==k && cont==tamstr2)
            {
                v[x]=pos;
                x++;
                k=0;
                cont=0;
                pos=0;

            }
        }
        else
        {

            k=0;
            cont=0;
            pos=0;

        }
    }
    if(x==0)
    {

        return -1;

    }
    else
    {

        return v[0];

    }

    //se quisermos imprimir as varias ocorrencias

    //imprime as posiçoes nas quais encontrou o inicio da igualdade entre as subsequencias e as sequencias
    /*for(i=0;i<x;i++)
    {

        printf("%d\n",v[i]);

    }*/

}



/** \brief Função procsubseq*/

int procsubseq(char seqf[][COLSEQ], int size, char subs[])
{
    /**
    \details função para procurar uma substring numa string
    \param char seqf[][COLSEQ] array final de strings
    \param int size numero da linha do array de strings final que vamos querer procurar uma substring
    \param char subs[] sub string a procurar
    \return retorna a posicao em que encontrou a substring
    */

    //esta função procura sequencias de peças noutras sequencias, ou peças em sequencias
    int i=0;
    int k=0;
    int cont=0;
    int pos=0;
    int x=0;
    int v[LINSEQ];
    int tamstr1=0;
    int tamstr2=0;
    char arrayseq[LINSEQ][COLSEQ];
    char arraysub[LINSEQ][COLSEQ];

    //o size neste caso é a linha do array de strings

    //faço o strtok da sequencias de peças
    tamstr1=strtoque(arrayseq,seqf[size],'-');
    //faço o strtok da sequencia a procurar
    tamstr2=strtoque(arraysub,subs,'-');

    for (i=0; i<tamstr1; i++)
    {
        //enquanto não estiver no fim da sequencia e houver igualdades entre a sequencia e a sub sequencia vou comparando a proxima peça da subsequencia com a peça da sequencia
        if(strcmp(arrayseq[i],arraysub[k])==0)
        {
            if(k==0)
            {
                //guardo a posição em que encontrei a primeira igualdade entre a subsequencia e a sequencia
                pos=i;
            }
            cont++;
            k++;


            //se a sub sequencia e a sequencia são iguais então guardo a posição num array de inteiros e procuro outra igualdade
            //se é que existe entre a subsequencia e a sequencia de peças

            if(cont==k && cont==tamstr2)
            {
                v[x]=pos;
                x++;
                k=0;
                cont=0;
                pos=0;

            }
        }
        else
        {

            k=0;
            cont=0;
            pos=0;

        }
    }

    return x;
    //se quisermos imprimir as varias ocorrencias

    //imprime as posiçoes nas quais encontrou o inicio da igualdade entre as subsequencias e as sequencias
    for(i=0; i<x; i++)
    {

        printf("%d\n",v[i]);

    }

}


/** \brief Função strtoque*/

int strtoque(char stra[][COLSEQ], char str[], char car)
{

    /**
    \details esta função recebe um array de strings, uma string e o carater pelo qual vai partir e faz o strtok()
    \param char stra[][COLSEQ] array de strings na qual vamos guardar as strings partidas
    \param char str[] string que queremos partir
    \param char car carater pelo qual partimos
    \return retorna o numero de pecas partidas
    */
    //esta função recebe um array de strings, uma string e o carater pelo qual vai partir e faz o strtok()
    int k=0,i=0,j=0;
    for (i=0; str[i]!='\0'; i++)
    {
        if (str[i]!=car)
        {
            stra[k][j]=str[i];
            j++;
        }
        else
        {
            stra[k][j]='\0';
            k++;
            j=0;
        }
    }
    return k+1;

}



/** \brief Função ordernarmatrizinteiros*/
void ordernarmatrizinteiros(int m[][2], int size)
{

    /**
    \details esta função recebe uma matriz e ordena crescente ou decrescente
    \param int m[][2] matriz a ordenar
    \param int size tamanho da matriz
    */
    //FAÇO A ORDENAÇAO DE UMA MATRIZ
    int aux=0;
    int aux2=0;
    int j=0;
    int i=0;

    for(j=0; j<size; j++)
    {

        for(i=0; i<size; i++)
        {
            //TROCANDO O SINAL FAÇO ORDEM CRESCENTE OU DECRESCENTE
            if(m[j][0]<m[i][0])
            {

                aux=m[j][0];
                aux2=m[j][1];

                m[j][0]=m[i][0];
                m[j][1]=m[i][1];

                m[i][0]=aux;
                m[i][1]=aux2;

            }

        }

    }

}




/** \brief Função ordernarsequencias*/
void ordernarsequencias(char seqf[][COLSEQ], int size)
{
    /**
    \details esta função ordena as sequenciass por ordem decrescente
    \param seqf[][COLSEQ] array de strings das sequencias finais a ordenar
    \param int size numero de sequencias finais
    */
    //esta função ordena as sequenciass por ordem decrescente
    char seqss[LINSEQ][COLSEQ];
    int tamanhos[LINSEQ][2];
    int i=0;
    int j=0;
    int aux=0;
    int aux2=0;

    //esvazio a sequencia de strings
    esvaziaseqstr(seqss,size);


    //guardo o tamanho da seq na primeira posição de uma matriz e na segunda posição guardo qual a posiçao da sequencia do array de sequencias
    for(i=0; i<size; i++)
    {

        tamanhos[i][0]=strlen(seqf[i]);
        tamanhos[i][1]=i;

    }


    //faço o selection sort para ordenar decrescentemente
    for(j=0; j<size; j++)
    {

        for(i=0; i<size; i++)
        {

            if(tamanhos[j][0]>tamanhos[i][0])
            {

                aux=tamanhos[j][0];
                aux2=tamanhos[j][1];

                tamanhos[j][0]=tamanhos[i][0];
                tamanhos[j][1]=tamanhos[i][1];

                tamanhos[i][0]=aux;
                tamanhos[i][1]=aux2;

            }

        }

    }

    /*for(i=0;i<size;i++){

         for(j=0;j<2;j++){

             printf("%d|",tamanhos[i][j]);

         }

         printf("\n");

     }*/


    for(i=0; i<size; i++)
    {

        strcpy(seqss[i],seqf[tamanhos[i][1]]);

    }

    esvaziaseqstr(seqf,size);


    for(i=0; i<size; i++)
    {

        strcpy(seqf[i],seqss[i]);

    }

    //printseqstr(seqf,0,size);


}

/** \brief Função ordernarsequencias struct*/
void ordernarsequenciasstruct(PECASINIT *p)
{
    /**
    \details esta função ordena as sequenciass por ordem decrescente
    \param PECASINIT *p estrutura do tipo struct

    */
    //esta função ordena as sequenciass por ordem decrescente
    int i=0;
    int j=0;
    int aux=0;
    int aux2=0;
    int nseq=0;

    //esvazio a sequencia de strings

    nseq=p->nseqss;

    for(i=0;i<nseq;i++)
    {

        remove_seqss(p);

    }


    //guardo o tamanho da seq na primeira posição de uma matriz e na segunda posição guardo qual a posiçao da sequencia do array de sequencias
    for(i=0; i<p->nseqf; i++)
    {

        inserir_ordenaseq(p,strlen((p->seqf+i)->seqstr),i);

    }


    //faço o selection sort para ordenar decrescentemente
    for(i=0; i<p->nseqf; i++)
    {

        for(j=0; j<p->nseqf; j++)
        {
            if((p->ordenaseq+j)->tamanho<(p->ordenaseq+i)->tamanho)
            {

                aux=(p->ordenaseq+j)->tamanho;
                aux2=(p->ordenaseq+j)->indice;

                (p->ordenaseq+j)->tamanho=(p->ordenaseq+i)->tamanho;
                (p->ordenaseq+j)->indice=(p->ordenaseq+i)->indice;

                (p->ordenaseq+i)->tamanho=aux;
                (p->ordenaseq+i)->indice=aux2;

            }

        }

    }


    for(i=0;i<p->nseqf;i++)
    {

        inserir_seqss(p,(p->seqf+((p->ordenaseq+i)->indice))->seqstr);

    }

    nseq=p->nseqf;

    for(i=0;i<nseq;i++)
    {

        remove_seqf(p);

    }

    for(i=0;i<p->nseqss;i++)
    {

        inserir_seqf(p,(p->seqss+i)->seqstr);

    }

}


/** \brief Função procsubseq_trocapadrao*/
int procsubseq_trocapadrao(char seqf[][COLSEQ], int size, char subs[LIN], int l)
{

    /**
    \details função para procurar uma substring numa string (utilizei esta variante na torca de padrao)
    \param char seqf[][COLSEQ] array final de strings
    \param int size numero da linha do array de strings final que vamos querer procurar uma substring
    \param char subs[] sub string a procurar
    \param int l numero da string que vamos procurar uma substring
    \return retorna a posicao em que encontrou a substring
    */

    char auxsub[LINSEQ];
    char auxseq[LINSEQ];
    char arrayseq[LINSEQ][COLSEQ];
    char arraysub[LINSEQ][COLSEQ];
    char *sub;
    char *seq;
    int contsub=0;
    int contseq=0;
    int i=0;
    int j=0;
    int k=0;
    int cont=0;
    int posicao=0;
    int sequencia=0;
    int imprime=0;
    int volta=0;

    //todas as sequencias do array seqf
    for(sequencia=0; sequencia<size; sequencia++)
    {

        esvaziaseqstr(arrayseq,LINSEQ);
        esvaziaseqstr(arraysub,LINSEQ);

        strcpy(auxsub,subs);
        sub = strtok (auxsub,"-");

        while (sub != NULL)
        {

            strcpy(arraysub[contsub],sub);
            contsub++;
            sub = strtok (NULL, "-");

        }

        strcpy(auxseq,seqf[sequencia]);
        seq = strtok (auxseq,"-");
        i=0;

        while (seq != NULL)
        {

            strcpy(arrayseq[contseq],seq);
            contseq++;
            seq = strtok (NULL, "-");

        }

        /*printseqstr(arrayseq,0,contseq);
        printf("\n\n");
        printseqstr(arraysub,0,contsub);*/



        for(i=0; i<contsub; i++)
        {

            for(j=l; j<contseq; j++)
            {
                //comparo ate encontrar a primeira peca da sub sequencia
                if(strcmp(arraysub[k],arrayseq[j])==0)
                {

                    if(cont==0)
                    {

                        posicao=j;
                        cont++;

                    }
                    //se o cont for igual ás pecas da subseq e se estiverem seguidas a volta tem de ser 0 para estarem seguidas
                    if(cont==contsub&&volta==0)
                    {

                        imprime=1;

                    }

                    k++;

                }

                if(cont>0)
                {

                    cont++;

                }

            }

            volta++;

        }

        if (imprime==1)
        {
            //retorna a posiçao na qual encontrou a subsequencia para permitir na função trocar padrao fazer a troca por um padrao diferente
            return posicao;
            //printf("%s --> %d\n",seqf[sequencia],posicao);

        }
        else
        {

            return -1;

        }
        posicao=0;
        k=0;
        cont=0;
        contsub=0;
        contseq=0;
        imprime=0;
        volta=0;

    }
    return 0;
}

/** \brief Função trocapadrao*/

void trocapadrao(char seqf[][COLSEQ], int size, char padrao[], char padraon[], char seqfpadrao[][COLSEQ], int *sizeseqfpadrao)
{

    /**
    \details função para procurar uma substring numa string (utilizei esta variante na torca de padrao)
    \param char seqf[][COLSEQ] array final de strings
    \param int size numero da linha do array de strings final que vamos querer procurar uma substring
    \param char padrao[] string a substituir
    \param char padraon[] string substituta
    \param char seqfpadrao[][COLSEQ]
    \param int *sizeseqfpadrao indice da sequencia padrao na qual vou trocar o padrao
    */

    int tampadrao=0;
    int tampadraon=0;
    char *s;
    char *p;
    char auxseq[LINSEQ][COLSEQ];
    char auxpad[COLSEQ];
    int contseq=0;
    int encontrasub=0;
    int i=0;
    int k=0;
    int sequencia=0;
    int posini=0;
    int contpad=0;
    int vetorpadrao[COLSEQ];
    int vposition[COLSEQ];
    char padraoasubstaux[LINSEQ];
    char auxpadraon[LINSEQ];
    int contfim=0;
    int troca=0;
    int r=0;
    /*printf("%s\n\n",seqf[0]);
    printf("%s\n\n",padrao);
    printf("%s\n\n",padraon);*/
    strcpy(auxpadraon,padraon);
    for(sequencia=0; sequencia<size; sequencia++)
    {

        esvaziaseqstr(auxseq,size);


        //fazemos o strtok() da sequencia, do padrão a trocar e do padrão novo
        for(i=0; i<size; i++)
        {

            strcpy(auxseq[i],seqf[i]);

        }

        s = strtok (auxseq[sequencia],"-");

        while (s != NULL)
        {

            contseq++;

            s = strtok (NULL, "-");

        }

        //partir o padrao

        strcpy(auxpad,padrao);

        p = strtok (auxpad,"-");

        while (p != NULL)
        {

            contpad++;

            p = strtok (NULL, "-");

        }

        for(i=0; i<contseq; i++)
        {
            //chamo a função procurar sub string e mando o endereço porque eu envio só aquela sequencia
            // o size é o numero de sequencias a fazer trocas

            encontrasub=procsubseq_trocapadrao(&seqf[sequencia],size,padrao,i);

            if(encontrasub!=-1)
            {

                if(i==0)
                {

                    vetorpadrao[k]=encontrasub;
                    k++;

                }
                else
                {
                    if(vetorpadrao[k-1]!=encontrasub)
                    {

                        vetorpadrao[k]=encontrasub;
                        k++;

                    }

                }

            }

        }


        //k sao os padroes encontrados que guardo num array
        if(k==0)
        {

            //printf("O padrao nao foi encontrado, logo nao pode substituir!  ");

        }
        else
        {

            /**CICLO DAS OCURRENCIAS DO PADRAO por indices da string**/

            for(i=0; i<k; i++)
            {

                tampadrao = strlen(padrao);
                tampadrao--;
                tampadraon = strlen(padraon);
                tampadraon--;

                if(vetorpadrao[i]==0)
                {
                    posini=0;

                }
                else
                {
                    if(i==0)
                    {

                        posini=vetorpadrao[i]*4;

                    }
                    else
                    {
                        //depois de tirar pecas as posicoes alteram e isto prevê essas trocas
                        //multiplicar por quatro dame o carater tipo 16 carater 4*4
                        contpad=contpad*4;
                        posini=vetorpadrao[i]*4;

                    }

                }

                vposition[i]=posini;

            }

        }

        for(i=(k-1); i>=0; i--)
        {

            //se for uma substituição do padrao no fim
            if(seqf[sequencia][vposition[i]+tampadrao+1]=='\0')
            {

                if(padraon[0]==seqf[sequencia][strlen(seqf[sequencia])-1-tampadrao-2])
                {

                    //printf("i-> %d   pos-> %d\n",i,vposition[i]);
                    seqf[sequencia][vposition[i]-1]='\0';
                    strcat(seqf[sequencia],"-");
                    strcat(seqf[sequencia],padraon);
                    contfim++;
                    troca++;

                }

            }


            //se for uma substituição do padrao no inicio
            if(vposition[i]==0)
            {

                if(padraon[strlen(padraon)-1]==seqf[sequencia][tampadrao+2])
                {

                    //printf("i-> %d   pos-> %d\n",i,vposition[i]);
                    strcpy(seqf[sequencia],&seqf[sequencia][vposition[i]+tampadrao+2]);
                    strcat(padraon,"-");
                    strcat(padraon,seqf[sequencia]);
                    strcpy(seqf[sequencia],padraon);
                    troca++;


                }

            }


            //se for uma substituição do padrao no meio
            if(seqf[sequencia][vposition[i]+tampadrao+1]!='\0' && vposition[i]!=0 && contfim==0)
            {

                if(seqf[sequencia][vposition[i]+tampadrao+2]==padraon[strlen(padraon)-1] && seqf[sequencia][vposition[i]-2]==padraon[0])
                {

                    //printf("i-> %d   pos-> %d\n",i,vposition[i]);
                    strcpy(padraoasubstaux,&seqf[sequencia][vposition[i]+tampadrao+1]);
                    seqf[sequencia][vposition[i]]='\0';
                    strcat(seqf[sequencia],padraon);
                    strcat(seqf[sequencia],padraoasubstaux);
                    troca++;

                }

            }
            contfim=0;

        }

        r=*sizeseqfpadrao;
        if(troca==1)
        {

            strcpy(seqfpadrao[r],seqf[sequencia]);
            //printf("[%d] ---> %s\n",sequencia,seqfpadrao[*sizeseqfpadrao]);
            r++;
        }
        *sizeseqfpadrao=r;
        troca=0;
        k=0;
        contseq=0;
        contpad=0;
        strcpy(padraon,auxpadraon);

    }

}

/** \brief Função tirartracosinvertidos*/

int tirartracosinvertidos(char seqf[][COLSEQ], int numdeseq)
{

    /**
    \details esta função serve para eliminar as sequencias que ão repetidas mas que estão escritas da direita para a esquerda, nas quais coloquei um "-" e agora elimino-as e puxo as outras para ci
    \param char seqf[][COLSEQ] array final de strings
    \param int numdeseq numero de sequencias
    \return retorna o numero de sequencias menos as que estavam escritas da esquerda para a direita
    */
    //esta função serve para eliminar as sequencias que ão repetidas mas que estão escritas da direita para a esquerda
    //mas quais coloquei um "-" e agora elimino-as e puxo as outras para cima

    int i=0;
    int cont=0;

    while(strcmp(seqf[i],"9|9")!=0)
    {

        if(strcmp(seqf[i],"-")==0)
        {

            cont++;

        }


        i++;

    }

    return numdeseq-cont;


}

/** \brief Função  seqcomseqincial*/

int seqcomseqincial(char baralhoss[][COLSTR], char seqf[][COLSEQ], int num, char seqinit[])
{
    /**
    \details esta funcao é igual à função das sequencias, só que nestas começo inicialmente com uma sequencia
    \param char baralhoss[][COLSTR] baralhos do jogador em string
    \param char seqf[][COLSEQ] array final onde vou guardar as sequencias todas possiveis
    \param int num numero de jogos a converter
    \param char seqinit[] sequencia inicial
    \return retorna o numero de sequencias que encontrou
    */
    //esta funcao é igual à função das sequencias, só que nestas começo inicialmente com uma sequencia
    char seqss[LINSEQ][COLSEQ];
    char baralhoaux[LINSEQ][COLSEQ];
    char invertidas[LINSEQ][COLSEQ];
    char vinvertidas[LINSEQ][COLSEQ];
    char auxinv[COLSTR];
    char invfinal[COLSTR];
    int i=0;
    int j=0;
    int k=0;
    int tam=LINSEQ;
    int n=0;
    int cont=0;
    int fimdastring=0;
    int decont=LINSEQ-1;
    int iguais=0;
    char aux[2000];
    char *s;
    char *inv;
    char *invseq;
    int invertidos=0;
    int contadorfinal=0;
    char auxdir='0';
    int contapecasvinvertidas=0;
    int seqinitexiste=0;
    /*a variavel ok acrescentada para apenas passar para o array secundário o que foi passado para o final sem concatenar
    peças mal*/
    int ok=0;


    //n=num*7;
    n=num*7;

    esvaziaseqstr(seqss,LINSEQ);
    esvaziaseqstr(baralhoaux,LINSEQ);

    for(i=0; i<n; i++)
    {

        strcpy(seqss[i],baralhoss[i]);

    }

    invertidos=n;


    //acresecentar pecas ao contrario

    while(j<n)
    {

        if(seqss[j][0]==seqss[j][2])
        {

            j++;
            cont++;

        }
        else
        {

            strcpy(seqss[invertidos],seqss[j]);
            auxdir=seqss[invertidos][0];
            seqss[invertidos][0]=seqss[invertidos][2];
            seqss[invertidos][2]=auxdir;
            strcpy(invertidas[k],seqss[invertidos]);
            invertidos++;
            j++;

        }
    }

    /*printf("\nINVERTIDAS\n");
    for(i=0;i<k;i++){

        printf("%s\n",invertidas[i]);

    }
    printf("\n");*/


    for(i=0; i<(invertidos); i++)
    {

        strcpy(seqf[i],seqss[i]);

    }

    for(i=0; i<(invertidos); i++)
    {

        strcpy(baralhoaux[i],seqss[i]);

    }

    strcpy(baralhoaux[invertidos],seqinit);

    for(i=0; i<strlen(seqinit); i++)
    {

        baralhoaux[invertidos+1][i]=seqinit[strlen(seqinit)-1-i];

    }
    //sequencia normal e invertidas acrescento ao array
    invertidos=invertidos+2;

    for(i=0; i<invertidos-2; i++)
    {
        if(strcmp(seqinit,baralhoaux[i])==0)
        {

            seqinitexiste++;

        }

    }

    //copiar sequencia inicial para dentro dos arrays de string, tanto o final como o aux

    strcpy(seqss[invertidos-2],baralhoaux[invertidos-2]);
    strcpy(seqss[invertidos-1],baralhoaux[invertidos-1]);

    strcpy(seqf[invertidos-2],baralhoaux[invertidos-2]);
    strcpy(seqf[invertidos-1],baralhoaux[invertidos-1]);


    n=invertidos;
    k=0;

    /**VERIFICA QUANTIDADE DE CORRESPONDENCIAS**/

    do
    {
        cont=0;
        for(i=0; i<invertidos; i++)
        {

            for(j=0; j<tam; j++)
            {

                if(k!=0)
                {

                    strcpy(aux,seqss[j]);

                    s = strtok (aux,"-");

                    while (s!= NULL)
                    {

                        if(strcmp(baralhoaux[i],s)==0 || (s[2]==baralhoaux[i][0] && s[0]==baralhoaux[i][2]))
                        {

                            iguais++;

                        }

                        s = strtok (NULL, "-");

                    }

                    strcpy(aux,"");
                }

                if(iguais==0)
                {

                    /*Ve o tamanho da string*/
                    fimdastring=strlen(seqss[j])-1;
                    /*compara as strings iniciasi e invertidas com aquelas que vamos aumentar*/

                    if(seqss[j][fimdastring]==baralhoaux[i][0] && i!=j && strcmp(seqss[i],"9|9")!=0)
                    {

                        cont++;
                        strcpy(seqf[contadorfinal],seqss[j]);
                        strcat(seqf[contadorfinal],"-");
                        strcat(seqf[contadorfinal],baralhoaux[i]);

                        contadorfinal++;
                        ok++;
                        //este array é o array final
                    }

                }
                iguais=0;

            }

        }


        /**JUNTA AS CORRESPONDENCIAS**/

        for(i=0; i<invertidos; i++)
        {

            for(j=0; j<ok; j++)
            {

                if(k!=0)
                {

                    strcpy(aux,seqss[j]);

                    s = strtok (aux,"-");
                    //parte para ver se a sequencia já montada contem a peca que vamos tentar inserir
                    while (s!= NULL)
                    {

                        if(strcmp(baralhoaux[i],s)==0 || (s[2]==baralhoaux[i][0] && s[0]==baralhoaux[i][2]))
                        {

                            iguais++;

                        }

                        s = strtok (NULL, "-");

                    }

                    strcpy(aux,"");

                    if(iguais==0)
                    {

                        fimdastring=strlen(seqss[j])-1;

                        if(seqss[j][fimdastring]==baralhoaux[i][0] && i!=j && strcmp(seqss[i],"9|9")!=0)
                        {

                            strcpy(seqss[decont],seqss[j]);
                            strcat(seqss[decont],"-");
                            strcat(seqss[decont],baralhoaux[i]);
                            decont--;

                        }
                    }

                }

                else
                {

                    for(fimdastring=0; seqss[j][fimdastring]!='\0'; fimdastring++);
                    fimdastring--;

                    if(seqss[j][fimdastring]==baralhoaux[i][0] && i!=j && strcmp(seqss[i],"9|9")!=0)
                    {

                        strcpy(seqss[decont],seqss[j]);
                        strcat(seqss[decont],"-");
                        strcat(seqss[decont],baralhoaux[i]);
                        //printf("%s == %s  | JUNTA --> %s\n\n",seqss[j],baralhoaux[i],seqss[decont]);
                        decont--;

                    }

                }

                iguais=0;

            }

        }

        //Agora limpa o array seqss em cima e assa de baixo para cima para continuar a juntar
        i=0;

        while (strcmp(seqss[i],"9|9")!=0)
        {

            strcpy(seqss[i],"9|9");
            i++;

        }

        decont=LINSEQ-1;
        i=0;

        //apaga array em baixo

        while (strcmp(seqss[decont],"9|9")!=0)
        {

            strcpy(seqss[i],seqss[decont]);
            strcpy(seqss[decont],"9|9");
            decont--;
            i++;

        }

        tam=(LINSEQ-decont-1);
        decont=LINSEQ-1;
        k++;

    }

    while(cont>0);

    //verifica se contem invertidas e normais e retira-as
    cont=0;
    i=0;

    while(strcmp(seqf[cont],"9|9")!=0)
    {
        strcpy(seqss[i],seqf[cont]);
        cont++;
        i++;

    }

    esvaziaseqstr(invertidas,LINSEQ);

    for(i=0; i<cont; i++)
    {

        strcpy(invertidas[i],seqss[i]);

    }

    j=0;
    for(i=0; i<cont; i++)
    {

        invseq = strtok (invertidas[i],"-");

        while (invseq != NULL)
        {

            strcpy(vinvertidas[j],invseq);
            j++;
            invseq = strtok (NULL, "-");

        }
        contapecasvinvertidas=j;
        j=0;
        inv = strtok (seqss[i],"-");

        while (inv != NULL)
        {

            strcpy(auxinv,inv);

            invfinal[2]=auxinv[0];
            invfinal[1]=auxinv[1];
            invfinal[0]=auxinv[2];

            if(invfinal[2]!=invfinal[0])
            {

                for(k=0; k<contapecasvinvertidas; k++)
                {

                    if(strcmp(invfinal,vinvertidas[k])==0)
                    {

                        strcpy(seqf[i],"-");

                    }

                }

            }

            inv = strtok (NULL, "-");

        }
        esvaziaseqstr(vinvertidas,LINSEQ);
        j=0;
    }

    contadorfinal=0;
    i=0;

    while(i<LINSEQ)
    {

        if(strcmp(seqf[i],"9|9")!=0)
        {

            contadorfinal++;

        }

        i++;
    }

    if(seqinitexiste>0)
    {

        contadorfinal=-1;

    }
    return contadorfinal;

}

/** \brief Função  retiraseqinitrepetida*/

int retiraseqinitrepetida(char seqf[][COLSEQ], int size, char seqinit[])
{

    /**
    \details Nesta funcao verifico se encontro a sequencia inicial ou a inicial invertida repetida na mesma sequencia para poder eliminá-la

    \param char seqf[][COLSEQ] array final onde vou guardar as sequencias todas possiveis
    \param int size numero de jogos a retirar sequencias com sequencias iniciais repetidas
    \param char seqinit[] sequencia inicial
    \return retorna o numero de sequencias que encontrou
    */
    int i=0;
    int cont=0;
    char seqinitinv[LINSEQ];

    for(i=0; seqinit[i]!='\0'; i++)
    {

        seqinitinv[strlen(seqinit)-1-i]=seqinit[i];

    }

    //aqui verifico se encontro a sequencia inicial ou a inicial invertida repetida na mesma sequencia para poder eliminá-la
    //visto que considero a sequencia inicial ou a sequencia invertida como se fosse uma peça tomando apenas em consideração
    //as extremidades

    for(i=0; i<size; i++)
    {

        if(procsubseq(seqf,i,seqinit)>1)
        {

            strcpy(seqf[i],"9|9");
            cont++;

        }
        if(procsubseq(seqf,i,seqinitinv)>1)
        {

            strcpy(seqf[i],"9|9");
            cont++;

        }


    }

    return cont;

}




/** \brief Função jogoadois*/

int jogoadois(char baralhoss[][COLSTR], char seqf[][COLSEQ], int num, char seqinit[])
{

    /**
    \details esta funcao é igual à função das sequencias, só que nestas posso começar inicialmente com uma sequencia on nao e os jogadores jogam à vez de cada baralho
    \param char baralhoss[][COLSTR] baralhos do jogador em string
    \param char seqf[][COLSEQ] array final onde vou guardar as sequencias todas possiveis
    \param int num numero de jogos a calcular sequencias
    \param char seqinit[] sequencia inicial
    \return retorna o numero de sequencias que encontrou
    */
    //esta função é igual à função de sequencias com a particularidade que os jogadores jogam alternadamente para fazerem sequencias

    char seqss[LINSEQ][COLSEQ];
    char baralhoaux[LINSEQ][COLSEQ];
    char invertidas[LINSEQ][COLSEQ];
    char vinvertidas[LINSEQ][COLSEQ];
    char auxinv[COLSTR];
    char invfinal[COLSTR];
    int i=0;
    int j=0;
    int k=0;
    int tam=LINSEQ;
    int cont=0;
    int fimdastring=0;
    int decont=LINSEQ-1;
    int iguais=0;
    char aux[2000];
    char seqinitinvertida[200];
    char *s;
    char *inv;
    char *invseq=NULL;
    int contadorfinal=0;
    int contapecasvinvertidas=0;
    int numero=1;
    int tambaralhosaux=0;
    /*a variavel ok acrescentada para apenas passar para o array secundário o que foi passado para o final sem concatenar
    peças mal*/
    int ok=0;

    esvaziaseqstr(seqss,LINSEQ);
    esvaziaseqstr(baralhoaux,LINSEQ);

    //se nao tiver uma sequencia inicial, comecao com o primeiro jogo

    tambaralhosaux=baralhoausar(baralhoss,baralhoaux,numero);

    if(strcmp(seqinit,"9|9")==0)
    {

        for(i=0; i<tambaralhosaux; i++)
        {

            strcpy(seqss[i],baralhoaux[i]);


        }

        tambaralhosaux=baralhoausar(baralhoss,baralhoaux,++numero);

    }
    else
    {

        strcpy(seqss[1],seqinit);
        for(i=0; seqinit[i]!='\0'; i++)
        {

            seqinitinvertida[i]=seqinit[strlen(seqinit)-1-i];

        }
        strcpy(seqss[0],seqinitinvertida);

    }


    /**VERIFICA QUANTIDADE DE CORRESPONDENCIAS**/

    do
    {

        cont=0;
        for(i=0; i<tambaralhosaux; i++)
        {

            for(j=0; j<tam; j++)
            {

                if(k!=0)
                {

                    strcpy(aux,seqss[j]);

                    s = strtok (aux,"-");

                    while (s!= NULL)
                    {

                        if(strcmp(baralhoaux[i],s)==0 || (s[2]==baralhoaux[i][0] && s[0]==baralhoaux[i][2]))
                        {

                            iguais++;

                        }

                        s = strtok (NULL, "-");

                    }

                    strcpy(aux,"");
                }

                if(iguais==0)
                {

                    /*Ve o tamanho da string*/

                    for(fimdastring=0; seqss[j][fimdastring]!='\0'; fimdastring++);
                    fimdastring--;

                    /*compara as strings iniciasi e invertidas com aquelas que vamos aumentar*/


                    if(seqss[j][fimdastring]==baralhoaux[i][0] && i!=j)
                    {


                        cont++;
                        strcpy(seqf[contadorfinal],seqss[j]);
                        strcat(seqf[contadorfinal],"-");
                        strcat(seqf[contadorfinal],baralhoaux[i]);
                        contadorfinal++;
                        ok++;

                    }

                }
                iguais=0;

            }

        }


        /**JUNTA AS CORRESPONDENCIAS**/

        for(i=0; i<tambaralhosaux; i++)
        {

            for(j=0; j<ok; j++)
            {

                if(k!=0)
                {

                    strcpy(aux,seqss[j]);

                    s = strtok (aux,"-");

                    while (s!= NULL)
                    {

                        if(strcmp(baralhoaux[i],s)==0 || (s[2]==baralhoaux[i][0] && s[0]==baralhoaux[i][2]))
                        {

                            iguais++;

                        }

                        s = strtok (NULL, "-");

                    }

                    strcpy(aux,"");

                    if(iguais==0)
                    {

                        for(fimdastring=0; seqss[j][fimdastring]!='\0'; fimdastring++);
                        fimdastring--;


                        if(seqss[j][fimdastring]==baralhoaux[i][0] && i!=j)
                        {

                            strcpy(seqss[decont],seqss[j]);
                            strcat(seqss[decont],"-");
                            strcat(seqss[decont],baralhoaux[i]);
                            decont--;

                        }
                    }

                }

                else
                {

                    for(fimdastring=0; seqss[j][fimdastring]!='\0'; fimdastring++);
                    fimdastring--;

                    if(seqss[j][fimdastring]==baralhoaux[i][0] && i!=j)
                    {

                        strcpy(seqss[decont],seqss[j]);
                        strcat(seqss[decont],"-");
                        strcat(seqss[decont],baralhoaux[i]);
                        decont--;

                    }

                }

                iguais=0;

            }

        }

        //Agora limpa o array seqss em cima e assa de baixo para cima para continuar a juntar
        i=0;

        while (strcmp(seqss[i],"9|9")!=0)
        {

            strcpy(seqss[i],"9|9");
            i++;

        }

        decont=LINSEQ-1;
        i=0;

        //apaga array em baixo

        while (strcmp(seqss[decont],"9|9")!=0)
        {

            strcpy(seqss[i],seqss[decont]);
            strcpy(seqss[decont],"9|9");
            decont--;
            i++;

        }

        tam=(LINSEQ-decont-1);
        decont=LINSEQ-1;
        k++;

        //aqui faço com que o baralho auxiliar a usar seja usado alternadamente ou seja, na primeira vez
        //comparo o baralhoaux do jogador 1 mas na segunda vez comparo com o baralho auxilidar do jogador dois de modo
        // a fazer sequencias com os baralhos dos jogadores alternadamente

        if(numero<num)
        {

            tambaralhosaux=baralhoausar(baralhoss,baralhoaux,++numero);

        }
        else
        {

            numero=1;
            tambaralhosaux=baralhoausar(baralhoss,baralhoaux,numero);

        }

    }

    while(cont>0);

    //verifica se contem invertidas e normais e retira-as
    cont=0;
    i=0;

    while(strcmp(seqf[cont],"9|9")!=0)
    {
        strcpy(seqss[i],seqf[cont]);
        cont++;
        i++;

    }

    esvaziaseqstr(invertidas,LINSEQ);

    for(i=0; i<cont; i++)
    {

        strcpy(invertidas[i],seqss[i]);

    }

    j=0;
    for(i=0; i<cont; i++)
    {

        invseq = strtok (invertidas[i],"-");

        while (invseq != NULL)
        {

            strcpy(vinvertidas[j],invseq);
            j++;
            invseq = strtok (NULL, "-");

        }
        contapecasvinvertidas=j;
        j=0;
        inv = strtok (seqss[i],"-");

        while (inv != NULL)
        {

            strcpy(auxinv,inv);

            invfinal[2]=auxinv[0];
            invfinal[1]=auxinv[1];
            invfinal[0]=auxinv[2];

            if(invfinal[2]!=invfinal[0])
            {

                for(k=0; k<contapecasvinvertidas; k++)
                {

                    if(strcmp(invfinal,vinvertidas[k])==0)
                    {

                        strcpy(seqf[i],"-");

                    }

                }

            }

            inv = strtok (NULL, "-");

        }
        esvaziaseqstr(vinvertidas,LINSEQ);
        j=0;
    }

    contadorfinal=0;
    i=0;

    while(i<LINSEQ)
    {

        if(strcmp(seqf[i],"9|9")!=0)
        {

            contadorfinal++;

        }

        i++;
    }

    return contadorfinal;

}



/** \brief Função  baralhoausar*/

int baralhoausar(char baralhoss[][COLSTR], char baralhoaux[][COLSEQ], int numero)
{

    /**
    \details esta funcao recebe as pecas de um baralho e acrescenta as invertidas
    \param char baralhoss[][COLSTR] baralhos do jogador em string
    \param char baralhoaux[][COLSEQ]baralhos do jogador em string auxiliar na qual guardo também as peças invertidas
    \param int numero contém o numero do baralho ao qual vamos acrescentar as pecas invertidas também
    \return retorna o numero de pecas do baralho do jogador com as pecas invertidas incluidas e retirando as repetidas
    */

    int i=0;
    char auxdir=' ';
    int invertidos=0;
    int k=0;
    int init=0;

    esvaziaseqstr(baralhoaux,LINSEQ);

    for(i=1; i<numero; i++)
    {

        init=init+7;

    }

    for(i=init; i<(numero*7); i++)
    {

        strcpy(baralhoaux[k],baralhoss[i]);
        k++;

    }

    invertidos=7;

    //acresecentar pecas ao contrario
    i=0;
    while(i<7)
    {

        if(baralhoaux[i][0]==baralhoaux[i][2])
        {

            i++;

        }
        else
        {

            strcpy(baralhoaux[invertidos],baralhoaux[i]);
            auxdir=baralhoaux[invertidos][0];
            baralhoaux[invertidos][0]=baralhoaux[invertidos][2];
            baralhoaux[invertidos][2]=auxdir;
            invertidos++;
            i++;

        }
    }

    return invertidos;

}
