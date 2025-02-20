#include<stdio.h>

void main() 
{
    int pid[20], at[20], bt[20], ct[20], tt[20], wt[20],tem[20],prt[20], i, j, n, time = 0, count = 0, sb = 0, temp;
    float att = 0, awt = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the process details:\n");
    for (i = 0; i < n; i++) {
        printf("Process No.%d \n", i + 1);
        printf("Enter the process id: ");
        scanf("%d", &pid[i]);
        printf("Enter the Arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter the burst time: ");
        scanf("%d", &bt[i]);
        tem[i]=bt[i];
        sb += bt[i];
        printf("Enter the Priority: ");
        scanf("%d",&prt[i]);
        printf("\n");
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && prt[i] > prt[j])) {

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
 		temp = prt[i];
                prt[i] = prt[j];
                prt[j] = temp;
 		
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
                
                temp = tem[i];
                tem[i] = tem[j];
                tem[j] = temp;
            }
        }
    }


    for (time = 0; count < n;) 
    {
        int high_p = 9999, idx = -1;

        for (i = 0; i < n; i++) 
        {
            if (at[i] <= time && bt[i] != -1 && prt[i] < high_p)
            {
                high_p = prt[i];
                idx = i;
            }
        }

        if (idx != -1) 
        {
            ct[idx] = time + bt[idx];
            time = ct[idx];  
            tt[idx] = ct[idx] - at[idx];
            wt[idx] = tt[idx] - bt[idx];
            att += tt[idx];
            awt += wt[idx];

            bt[idx] = -1;  
            count++;
        } else {
            time++;  
        }
    }


    printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], tem[i], ct[i], tt[i], wt[i]);
    }


    printf("\nAverage Turnaround Time: %f", att/n);
    printf("Average Waiting Time: %f", awt/n);
}
