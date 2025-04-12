#include <stdlib.h>
#define MAX_TOPO 10

typedef struct
{
    int topo;
    int itens[MAX_TOPO];
} Pilha;

typedef struct No
{
    int dado;
    struct No *prox;
} No;

typedef struct
{
    No *topo;
} PilhaListaEncadeada;

void exerciseStacks()
{
    int numExercice;
    int resultScan;

    printf("\n--------------- Escolha um exercicio ---------------\n\n");
    printf("1 - Exercicio 1 - Implementacao Estatica (com Array): \n");
    printf("2 - Exercicio 2 - Implementacao Dinamica (com Lista Encadeada)\n");
    printf("3 - Sair\n");

    resultScan = scanf("%d", &numExercice);

    if (resultScan != 1)
    {
        printf("\n!!!!!!!!!Erro: voce deve digitar um numero inteiro!!!!!!!!!! \n\n");
        while (getchar() != '\n');
        exerciseVectorsAndMatrices();
        return 1;
    }

    switch (numExercice)
    {
    case 1:
        exerciseStacks1();
        break;
    case 2:
        exerciseStacks2();
        break;
    case 3:
        printf("\nSaindo do programa...\n\n");
        break;
    default:
        printf("\nOpcao invalida! Tente novamente.\n");
    }
}

void exerciseStacks1()
{
    Pilha p;
    inicializar(&p);
    push(&p, 10);
    push(&p, 20);
    printf("Topo: %d\n", peek(&p));
    printf("Removido: %d\n", pop(&p));
    printf("Topo: %d\n", peek(&p));
}

void exerciseStacks2()
{
    PilhaListaEncadeada p;
    inicializarListaEncadeada(&p);
    pushListaEncadeada(&p, 10);
    pushListaEncadeada(&p, 20);
    printf("Topo: %d\n", peekListaEncadeada(&p));
    printf("Removido: %d\n", popListaEncadeada(&p));
    printf("Topo: %d\n", peekListaEncadeada(&p));
    return 0;
}

//------------ Auxiliary Methods 1 --------------------

void inicializar(Pilha *p)
{
    p->topo = -1;
}

int isFull(Pilha *p)
{
    return p->topo == MAX_TOPO - 1;
}

int isEmpty(Pilha *p)
{
    return p->topo == -1;
}

void push(Pilha *p, int valor)
{
    if (isFull(p))
    {
        printf("Pilha cheia!\n");
        return;
    }
    p->itens[++p->topo] = valor;
}

int pop(Pilha *p)
{
    if (isEmpty(p))
    {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->itens[p->topo--];
}

int peek(Pilha *p)
{
    if (isEmpty(p))
    {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->itens[p->topo];
}

//------------ Auxiliary Methods 2 --------------------

void inicializarListaEncadeada(PilhaListaEncadeada *p)
{
    p->topo = NULL;
}

int isEmptyListaEncadeada(PilhaListaEncadeada *p)
{
    return p->topo == NULL;
}

void pushListaEncadeada(PilhaListaEncadeada *p, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro de alocação!\n");
        return;
    }
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

int popListaEncadeada(PilhaListaEncadeada *p)
{
    if (isEmptyListaEncadeada(p))
    {
        printf("Pilha vazia!\n");
        return -1;
    }
    No *temp = p->topo;
    int valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int peekListaEncadeada(PilhaListaEncadeada *p)
{
    if (isEmptyListaEncadeada(p))
    {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->topo->dado;
}
