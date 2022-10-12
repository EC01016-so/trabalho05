#include<stdio.h>  
    
int main()  
{  
    // Inicializa o nome da variável 
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float media_wt, media_tat;  
    printf("Número total de processos no sistema: ");  
    scanf("%d", &NOP);  
    // Atribui o número do processo à variável y 
    y = NOP;
    
    // Loop para exibir as informações dos processos, entre a Arrival time (hora da chegada) e o Burst time (tempo de execução)
    for(i = 0; i < NOP; i++)  
    {  
        printf("\n Insira o Arrival time e Burst time[%d]\n", i+1);  
        // Insere o Arrival time  
        printf("Arrival time: \t");
        scanf("%d", &at[i]);  
        // Insere o Burst time 
        printf(" \n Burst time: \t");
        scanf("%d", &bt[i]);  
        // Armazena o tempo de intermitência na matriz temp
        temp[i] = bt[i];  
    }  
    // Insere o Time Quantum
    printf("Insira o Time Quantum para o processo: \t");  
    scanf("%d", &quant);  
    
    // Exibe o processo Num, Burst time (tempo de execução), TurnAround (tempo de retorno) e o Waiting Time (tempo de espera)
    printf("\n Processo Num \t\t Burst Time \t\t TurnAround \t\t Waiting Time ");  
    for(sum = 0, i = 0; y!=0; )  
    {     
        if(temp[i] <= quant && temp[i] > 0) // define as condições   
        {  
            sum = sum + temp[i];  
            temp[i] = 0;  
            count=1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - quant;  
            sum = sum + quant;    
        }  
        if(temp[i]==0 && count==1)  
        {  
            // Decrementa o nº do processo 
            y--;
            printf("\nProcesso Num[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
            wt = wt+sum-at[i]-bt[i];  
            tat = tat+sum-at[i];  
            count =0;     
        }  
        if(i==NOP-1)  
        {  
            i=0;  
        }  
        else if(at[i+1]<=sum)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  
    // Exibe o tempo médio de espera e de retorno 
    media_wt = wt * 1.0/NOP;  
    media_tat = tat * 1.0/NOP;  
    printf("\n Média do Turn Around Time: \t%f", media_wt);  
    printf("\n Média do Waiting Time: \t%f", media_tat);  
}  