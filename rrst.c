#include<stdio.h> 
int main() 
{ 
  int choice, wait_time=0,turnaround_time=0, n, at[10], bt[10], rt[10], count,  time_quantum,i,j,time,remain,flag=0, smallest, c;
  double end;
  printf("Enter Total Process:\t "); 
          scanf("%d",&n); 
          remain=n; 
          for(count=0;count<n;count++) 
          { 
            printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
            scanf("%d",&at[count]); 
            scanf("%d",&bt[count]); 
            rt[count]=bt[count];
        }
     printf("ENTER YOUR CHOICE?\n\t1. ROUND ROBIN\n\t2. SRT\n\t3. EXIT");
  scanf("%d", &choice);
 if(choice==1)
  {
  printf("Enter Time Quantum:\t"); 
          scanf("%d",&time_quantum); 
          printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
          for(time=0,count=0;remain!=0;) 
          { 
            if(rt[count]<=time_quantum && rt[count]>0) 
            { 
              time+=rt[count]; 
              rt[count]=0; 
              flag=1; 
            } 
            else if(rt[count]>0) 
            { 
              rt[count]-=time_quantum; 
              time+=time_quantum; 
            } 
            if(rt[count]==0 && flag==1) 
            { 
              remain--; 
              printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
              wait_time+=time-at[count]-bt[count]; 
              turnaround_time+=time-at[count]; 
              flag=0; 
            } 
            if(count==n-1) 
              count=0; 
            else if(at[count+1]<=time) 
              count++; 
            else 
              count=0; 
          } 
        }
        else if(choice==2)
        {
    bt[9]=9999;
      for(time=0;c!=n;time++)
     {
       smallest=9;
      for(count=0;count<n;count++)
      {
       if(at[count]<=time && bt[count]<bt[smallest] && bt[count]>0 )
       smallest=count;
      }
      bt[smallest]--;
      if(bt[smallest]==0)
      {
       c++;
       end=time+1;
       wait_time= wait_time + end - at[smallest] - rt[smallest];
       turnaround_time= turnaround_time + end - at[smallest];
      }
     }
    } 
      printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
      printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
}

