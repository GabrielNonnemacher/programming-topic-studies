#include <stdio.h>

int main()
{
    int topic, resultScan;

    printf("\n--------------- Escolha um topico: ---------------\n\n");
    printf("1 - Vectors And Matrices \n");
    printf("2 - Linked Lists \n");
    printf("3 - Stacks \n");
    printf("4 - Queues \n");
    printf("5 - Sair \n");

    resultScan = scanf("%d", &topic);

    if (resultScan != 1)
    {
        printf("\n!!!!!!!!!Erro: voce deve digitar um numero inteiro e valido!!!!!!!!!! \n\n");
        while (getchar() != '\n');
        main();
        return 1;
    }

    switch (topic)
    {
    case 1:
        exerciseVectorsAndMatrices();
        break;
    case 2:
        exerciseLinkedLists();
        break;
    case 3:
        exerciseStacks();
        break;
    case 4:
        exerciseQueues();
        break;
    case 5:
        printf("\nSaindo do programa...\n\n");
        break;
    default:
        printf("\nOpcao invalida! Tente novamente.\n\n");
    }

    printf("\n--------------- PROGRAMA FINALIZADO ---------------\n\n");
    return 0;
}
