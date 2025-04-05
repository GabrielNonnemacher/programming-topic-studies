#include <stdio.h>

int main()
{
    int topic;
    int resultScan;

    printf("Escolha o topico: \n");
    printf("1 - Vectors And Matrices: \n");
    printf("2 -: \n");
    printf("3 -: \n");
    printf("4 -: \n");

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
        break;
    case 3:
        break;
    default:
        break;
    }

    return 0;
}
