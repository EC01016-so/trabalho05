#include<stdio.h>  
    
int main()  
{  
    // inicializa o nome da variável 
    int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  
    printf(" Total number of process in the system: ");  
    scanf("%d", &NOP);  
    y = NOP; // Atribui o número do processo à variável y 
    
    // Use for loop to enter the details of the process like Arrival time and the Burst Time  
    for(i=0; i<NOP; i++)  
    {  
        printf("\n Insira a hora de chegada e explosão do processo[%d]\n", i+1);  
        printf(" Hora de chegada é: \t");  // Aceita hora de chegada  
        scanf("%d", &at[i]);  
        printf(" \nO tempo de rajada: \t"); // Aceitar o tempo de rajada
        scanf("%d", &bt[i]);  
        temp[i] = bt[i]; // armazene o tempo de intermitência na matriz temp  
    }  
    // Aceite o quant de tempo 
    printf("Insira o Time Quantum para o processo: \t");  
    scanf("%d", &quant);  
    // Exibe o processo Não, tempo de rajada, tempo de retorno e o tempo de espera 
    printf("\n Processo Num \t\t Burst Time \t\t TurnAround \t\t Tempo de Espera ");  
    for(sum=0, i = 0; y!=0; )  
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
            y--; //decrementa o nº do processo. 
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
    // representa o tempo médio de espera e o tempo de retorno 
    avg_wt = wt * 1.0/NOP;  
    avg_tat = tat * 1.0/NOP;  
    printf("\n Average Turn Around Time: \t%f", avg_wt);  
    printf("\n Average Waiting Time: \t%f", avg_tat);  
}  