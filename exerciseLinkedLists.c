#include<stdio.h>
#include<stdlib.h>
#define MAX_CONTATOS 100
#define MAX_EMAIL 100
#define MAX_NOME 30
#define MAX_FONE 10
#define ZERO 0

typedef struct cel celula;
struct cel
{
    int dado;
    celula *prox;
};

typedef struct
{
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char fone[MAX_FONE];
} Contato;


void exerciseLinkedLists()
{
    int numExercice, resultScan;

    printf("\n--------------- Escolha um exercicio ----------------\n\n");
    printf("1 - Exercicio 1:  implementacao de uma lista\n");
    printf("2 - Exercicio 2 e 3: implementacao de uma agenda eletronica: \n");
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
        exerciseLinkedLists1();
        break;
    case 2:
        exerciseLinkedLists2And3();
        break;
    case 3:
        printf("\nSaindo do programa...\n");
        break;
    default:
        printf("\nOpcao invalida! Tente novamente.\n");
    }
}

void exerciseLinkedLists1()
{
    int op = -1, valor;
    celula *lista = NULL;
    lista = (celula *) malloc(sizeof(celula));

    while (op != ZERO)
    {
        printf("\n--------------- Opcoes disponiveis ---------------\n\n");
        printf("0 - Encerrar.\n");
        printf("1 - Imprimir lista.\n");
        printf("2 - Inserir novo elemento na lista.\n");
        printf("Entre opcao desejada: ");
        scanf("%d", &op);
        switch(op)
        {
        case 0:
            printf("\n\nTCHAU!\n");
            break;
        case 1:
            imprime(lista);
            break;
        case 2:
            printf("\nEntre valor a ser inserido na lista: ");
            scanf("%d", &valor);
            insere(valor, lista);
            break;
        default:
            printf("\n\nOPCAO INVALIDA!\n");
        }
    }
}

void exerciseLinkedLists2And3()
{
    Contato agenda[MAX_CONTATOS];
    int totalContatos = ZERO;
    int opcao;

    do
    {
        printf("\n--------------- nMenu ---------------\n\n");
        printf("1 - Adicionar novo contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Buscar contato\n");
        printf("4 - Remover contato\n");
        printf("5 - Atualizar contato\n");
        printf("6 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarContato(agenda, &totalContatos);
            break;
        case 2:
            imprimirTodosContatos(agenda, totalContatos);
            break;
        case 3:
            buscarContato(agenda, totalContatos);
            break;
        case 4:
            removerContato(agenda, &totalContatos);
            break;
        case 5:
            atualizarContato(agenda, totalContatos);
            break;
        case 6:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    }
    while (opcao != 6);
}

//------------ Auxiliary Methods --------------------

void insere (int x, celula *p)
{
    celula *nova;
    nova = (celula *) malloc (sizeof(celula));
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
}

void imprime(celula *ini)
{
    celula *p;
    printf("\nValores na lista:\n");
    for (p = ini->prox; p != NULL; p = p->prox)
    {
        printf ("%d\t", p->dado);
    }
    printf ("\n");
}

void adicionarContato(Contato agenda[], int *total)
{
    if (*total >= MAX_CONTATOS)
    {
        printf("\nAgenda cheia! Nao e possivel adicionar mais contatos.\n");
        return;
    }

    printf("\nNome: ");
    scanf(" %[^\n]", agenda[*total].nome);
    printf("E-mail: ");
    scanf(" %[^\n]", agenda[*total].email);
    printf("Telefone: ");
    scanf(" %[^\n]", agenda[*total].fone);

    (*total)++;
    printf("\nContato adicionado com sucesso!\n");
}

void imprimirTodosContatos(Contato agenda[], int total)
{
    if (total == ZERO)
    {
        printf("\nAgenda vazia!\n");
        return;
    }

    printf("\nLista de Contatos:\n");
    for (int i = ZERO; i < total; i++)
    {
        printf("\nContato %d:\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("E-mail: %s\n", agenda[i].email);
        printf("Telefone: %s\n", agenda[i].fone);
    }
}

void buscarContato(Contato agenda[], int total)
{
    if (total == ZERO)
    {
        printf("\nAgenda vazia!\n");
        return;
    }

    char nomeBusca[MAX_NOME];
    printf("\nDigite o nome do contato: ");
    scanf("%s", nomeBusca);

    for (int i = ZERO; i < total; i++)
    {
        if (strcmp(agenda[i].nome, nomeBusca) == ZERO)
        {
            printf("\nContato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Telefone: %s\n", agenda[i].fone);
            return;
        }
    }
    printf("\nContato nao encontrado!\n");
}

void removerContato(Contato agenda[], int *total)
{
    if (*total == ZERO)
    {
        printf("\nAgenda vazia!\n");
        return;
    }

    char nomeRemove[MAX_NOME];
    printf("\nDigite o nome do contato a ser removido: ");
    scanf(" %[^\n]", nomeRemove);

    for (int i = ZERO; i < *total; i++)
    {
        if (strcmp(agenda[i].nome, nomeRemove) == ZERO)
        {
            for (int j = i; j < *total - 1; j++)
            {
                agenda[j] = agenda[j + 1];
            }
            (*total)--;
            printf("\nContato removido com sucesso!\n");
            return;
        }
    }
    printf("\nContato não encontrado!\n");
}

void atualizarContato(Contato agenda[], int total)
{
    if (total == ZERO)
    {
        printf("\nAgenda vazia!\n");
        return;
    }

    char nomeAtualiza[MAX_NOME];
    printf("\nDigite o nome do contato a ser atualizado: ");
    scanf(" %[^\n]", nomeAtualiza);

    for (int i = ZERO; i < total; i++)
    {
        if (strcmp(agenda[i].nome, nomeAtualiza) == ZERO)
        {
            printf("\nDigite os novos dados:\n");
            printf("Nome: ");
            scanf(" %[^\n]", agenda[i].nome);
            printf("E-mail: ");
            scanf(" %[^\n]", agenda[i].email);
            printf("Telefone: ");
            scanf(" %[^\n]", agenda[i].fone);
            printf("\nContato atualizado com sucesso!\n");
            return;
        }
    }
    printf("\nContato não encontrado!\n");
}
