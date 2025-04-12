#include <stdlib.h>
#include <string.h>
#define MAX_ITENS 5
#define MAX_NOME 30

typedef struct
{
    int itens[MAX_ITENS];
    int frente, tras;
} Fila;

typedef struct
{
    int itens[MAX_ITENS];
    int frente, tras;
} FilaCircular;

typedef struct No
{
    char nome[MAX_NOME];
    struct No* prox;
} No;

typedef struct
{
    No* inicio;
    No* fim;
} FilaDinamica;


void exerciseQueues()
{
    int numExercice, resultScan;

    printf("\n--------------- Escolha um exercicio ---------------\n\n");
    printf("1 - Exercicio 1 - Fila Linear com Vetor \n");
    printf("2 - Exercicio 2 - Fila Circular com Vetor\n");
    printf("3 - Exercicio 3 - Fila Dinâmica com Ponteiros\n");
    printf("4 - Sair\n");

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
        exerciseQueues1();
        break;
    case 2:
        exerciseQueues2();
        break;
    case 3:
        exerciseQueues3();
        break;
    case 4:
        printf("\nSaindo do programa...\n");
        break;
    default:
        printf("\nOpcao invalida! Tente novamente.\n");
    }
}

void exerciseQueues1()
{
    int a, b, c, d, e;
    Fila f;

    inicializarFila(&f);

    printf("insira 5 numeros \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);

    enfileirar(&f,a);
    enfileirar(&f,b);
    enfileirar(&f,c);
    enfileirar(&f,d);
    enfileirar(&f,e);

    exibirFila(&f);
}

void exerciseQueues2()
{
    FilaCircular f;

    inicializarFilaCircular(&f);

    perguntaFilaCircular(&f);
}

void exerciseQueues3()
{
    FilaDinamica fila;
    inicializarFilaDinamica(&fila);

    enfileirarFilaDinamica(&fila, "Alice");
    enfileirarFilaDinamica(&fila, "Bruno");
    enfileirarFilaDinamica(&fila, "Carla");

    desenfileirarFilaDinamica(&fila);

    printf("Nomes restantes na fila:\n");
    imprimirFilaDinamica(&fila);
}

//------------ Auxiliary Methods 1 --------------------

void inicializarFila(Fila *f)
{
    f->frente = 0;
    f->tras = -1;
}

void enfileirar(Fila *f, int valor)
{
    if (estaCheia(f))
    {
        printf("Fila cheia!\n");
        return;
    }
    f->tras++;
    f->itens[f->tras] = valor;
}

void exibirFila(Fila *f)
{
    if (estaVazia(f))
    {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    for (int i = f->frente; i <= f->tras; i++)
    {
        printf("%d ", f->itens[i]);
    }
    printf("\n");
}

int estaCheia(Fila *f)
{
    return f->tras == MAX_ITENS - 1;
}

int estaVazia(Fila *f)
{
    return f->frente > f->tras;
}

//------------ Auxiliary Methods 2 --------------------

int estaCheiaCircular(FilaCircular *f)
{
    return (f->tras + 1) % MAX_ITENS == f->frente;
}

int estaVaziaCircular(FilaCircular *f)
{
    return f->frente == f->tras;
}

void inicializarFilaCircular(FilaCircular *f)
{
    f->frente = 0;
    f->tras = 0;
}

void enfileirarCircular(FilaCircular *f, int valor)
{
    if (estaCheiaCircular(f))
    {
        printf("Fila cheia!\n");
        return;
    }
    f->itens[f->tras] = valor;
    f->tras = (f->tras + 1) % MAX_ITENS;
}


int desenfileirarCircular(FilaCircular *f)
{
    if (estaVaziaCircular(f))
    {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX_ITENS;
    return valor;
}

void exibirFilaCircular(FilaCircular *f)
{
    if (estaVaziaCircular(f))
    {
        printf("\nFila vazia!\n\n");
        return;
    }
    printf("\nFila Circular: ");
    int i = f->frente;
    while (i != f->tras)
    {
        printf("%d ", f->itens[i]);
        i = (i + 1) % MAX_ITENS;
    }
    printf("\n\n");
}

void perguntaFilaCircular(FilaCircular *f)
{
    int a, b, c, d, resultScan, acao;
    printf("Escolha a acao: \n");
    printf("1 - Inserir \n");
    printf("2 - Remover \n");
    printf("3 - Imprimir \n");
    printf("4 - Sair \n");
    resultScan = scanf("%d", &acao);

    if (resultScan != 1)
    {
        printf("\n!!!!!!!!!Erro: voce deve digitar um numero inteiro!!!!!!!!!! \n\n");
        while (getchar() != '\n');
        perguntaFilaCircular(f);
        return 1;
    }

    switch (acao)
    {
    case 1:
        printf("insira 4 numeros \n");
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        scanf("%d", &d);
        enfileirarCircular(f,a);
        enfileirarCircular(f,b);
        enfileirarCircular(f,c);
        enfileirarCircular(f,d);
        printf("Numeros adicionados com Sucesso!\n\n");
        perguntaFilaCircular(f);
        break;
    case 2:
        desenfileirarCircular(f);
        desenfileirarCircular(f);
        perguntaFilaCircular(f);
        break;
    case 3:
        exibirFilaCircular(f);
        perguntaFilaCircular(f);
        break;
    case 4:
        printf("\nSaindo do programa...\n");
        break;
    default:
        printf("\nOpcao invalida! Tente novamente.\n");
        perguntaFilaCircular(f);
    }
}

//------------ Auxiliary Methods 3 --------------------

void inicializarFilaDinamica(FilaDinamica *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}

void enfileirarFilaDinamica(FilaDinamica* fila, const char* nome)
{
    No* novo = (No*)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }

    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (fila->fim == NULL)
    {
        fila->inicio = novo;
    }
    else
    {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

void desenfileirarFilaDinamica(FilaDinamica* fila)
{
    if (fila->inicio == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }

    No* temp = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL)
    {
        fila->fim = NULL;
    }

    free(temp);
}

void imprimirFilaDinamica(FilaDinamica* fila)
{
    No* atual = fila->inicio;
    while (atual != NULL)
    {
        printf("%s\n", atual->nome);
        atual = atual->prox;
    }
}
