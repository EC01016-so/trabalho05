#include <stdio.h>

int main()
{
/* Matriz para armazenar ID de processo, Tempo de disparo de rajada,
Tempo Médio de Espera e Tempo médio de resposta. */

    int A[100][4];

    int i, j, n, total = 0, index, temp;
    float media_wt, media_tat;
    printf("Digite o número do processo: ");
    scanf("%d", &n);
    printf("Digite o tempo de disparo:\n");
    
    // Tempo de intermitência da entrada do usuário e atribuição do ID do processo.
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;
    }
    
    // Ordenação dos vetores de acordo com o Burst Time.
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++)
            if (A[j][1] < A[index][1])
                index = j;
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;
 
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
    A[0][2] = 0;
    
    // Cálculo de tempos de espera
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];
        total += A[i][2];
    }
    
    media_wt = (float)total / n;
    total = 0;
    printf("Processo|  BT    | espera | TurnAround\n");
    printf("______________________________________\n");
    
    // Cálculo do tempo de retorno (turnAround) e exibição dos valores
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2];
        total += A[i][3];
        printf("|  P%d   |    %d   |   %d    |   %d   |\n", A[i][0],
               A[i][1], A[i][2], A[i][3]);
    }
    
    media_tat = (float)total / n;
    printf("Tempo médio de espera = %f", media_wt);
    printf("\nTempo médio de retorno= %f", media_tat);
}