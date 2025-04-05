float matriz[3][4];
float m00, m10, m20, m21, m11, m22;

void exerciseVectorsAndMatrices()
{
    int numExercice;
    int resultScan;

    printf("Escolha o exercicio: \n");
    printf("1 - Exercicio 1: \n");
    printf("2 - Exercicio 2: \n");
    printf("3 - Exercicio 3: \n");
    printf("4 - Exercicio 4: \n");

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
        exercise1();
        break;
    case 2:
        exercise2();
        break;
    case 3:
        exercise3();
        break;
    default:
        exercise4();
        break;
    }
}

void exercise1()
{
    int vet[10];

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Posicao %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    printf("\nValores triplicados:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d x 3 = %d\n", vet[i], vet[i] * 3);
    }
}

void exercise2()
{
    int matriz[3][3];

    printf("Digite 9 numeros inteiros para preencher a matriz 3x3:\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\nMatriz com valores duplicados:\n");

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d\t", matriz[i][j] * 2);
            }
            printf("\n");
        }
    }
}

void exercise3()
{
    printf("Digite 12 números inteiros para preencher a matriz 3x4:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Posição [%d][%d]: ", i, j);
            scanf("%e", &matriz[i][j]);
        }
    }

    imprimeMatriz();
    esperarTecla();

    m00=matriz[0][0];
    m10=matriz[1][0];

    for (int j = 0; j < 4; j++)
    {
        matriz[0][j] = matriz[0][j]*m10;
    }

    for (int j = 0; j < 4; j++)
    {
        matriz[1][j] = matriz[1][j]*m00;
    }

    for (int j = 0; j < 4; j++)
    {
        matriz[1][j] = matriz[0][j] - matriz[1][j];
    }

    imprimeMatriz();
    esperarTecla();

    m00=matriz[0][0];
    m20=matriz[2][0];

    for (int j = 0; j < 4; j++)
    {
        matriz[0][j] = matriz[0][j]*m20;
    }

    for (int j = 0; j < 4; j++)
    {
        matriz[2][j] = matriz[2][j]*m00;
    }

    for (int j = 0; j < 4; j++)
    {
        matriz[2][j] = matriz[0][j] - matriz[2][j];
    }

    imprimeMatriz();
    esperarTecla();

    m11=matriz[1][1];
    m21=matriz[2][1];

    for (int j = 0; j < 4; j++)
    {
        matriz[1][j] = matriz[1][j]*m21;
    }

    for (int j = 0; j < 4; j++)
    {
        matriz[2][j] = matriz[2][j]*m11;
    }

    for (int j = 0; j < 4; j++)
    {
        matriz[2][j] = matriz[1][j] - matriz[2][j];
    }

    imprimeMatriz();
    esperarTecla();
    printf("\nDeixando a diagonal principal unitária:");

    m00=1/matriz[0][0];
    m11=1/matriz[1][1];
    m22=1/matriz[2][2];

    for (int j = 0; j < 4; j++)
    {
        matriz[0][j] = matriz[0][j]*m00;
        matriz[1][j] = matriz[1][j]*m11;
        matriz[2][j] = matriz[2][j]*m22;
    }
    imprimeMatriz();
}


void exercise4()
{
    int qtdElements;

    printf("Digite a quantidade de elementos do vetor:\n");
    scanf("%d", &qtdElements);

    int vet[qtdElements];

    printf("Digite os numeros inteiros:\n");

    for (int i = 0; i < qtdElements; i++)
    {
        printf("Posicao %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    ordena(vet, qtdElements);

    printf("\nVetor ordenado em ordem crescente:\n");
    for (int i = 0; i < qtdElements; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");
}

//------------ Auxiliary Methods --------------------

void ordena(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void imprimeMatriz()
{
    printf("\nMatriz alterada:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(matriz[i][j]==0.)
                printf(" . \t");
            else
                printf("%10.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void esperarTecla()
{
    printf("Aperte qualquer tecla para continuar...\n");
    getchar();
    getchar();
}
