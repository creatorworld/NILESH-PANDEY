// code to apply LRTF
for(i=0;i<n;i++)
    {
        pos=i; 
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]>burst_time[pos])
                pos=j;
        }
  
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
  
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }
  //First process has 0 waiting time 
    waiting_time[0]=0;           
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
  
        total+=waiting_time[i];
    }
