#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef struct process
{
    int at,ct,tat,bt,wt,id;
} pro;

int sort(pro* p,int n)
{
    for (int i = 0; i <n-1; i++)
    {   bool flag=false;
        for(int j=0;j<n-i-1;j++)
        {
           if(p[j].at>p[j+1].at)
           {
            pro temp= p[j];
            p[j]=p[j+1];
            p[j+1]= temp;
            flag=true;
           }
        }
        if(!flag)
          break;
    }
    
}

int main()
{
    cout<<"enter the number of process"<<endl;
    int n;float avg_tat=0,avg_wt=0;
    cin>>n;
    pro p[n];
    cout<<"enter the details of the process \n at\tbt"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i].at;
        cin>>p[i].bt;
        p[i].id=i+1;
    }
    sort(p,n);
    p[0].wt=0;
    p[0].ct=p[0].at+p[0].bt;
    for(int i=1;i<n;i++)
    {
       if(p[i].at>p[i-1].ct)  
       {
        p[i].ct=p[i-1].ct+(p[i].at-p[i-1].ct)+p[i].bt;
       }
       else 
        p[i].ct=p[i-1].ct+p[i].bt;
    }

    // finding tat
    for (int i = 0; i < n; i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        avg_tat+= p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        avg_wt += p[i].wt;
    }
     avg_tat/=n;
     avg_wt=avg_wt/n;
 // printing gantt chart
     if(p[0].at!=0)
        cout<<"|idle(0,"<<p[0].at<<")|";
      cout<<"|P("<<p[0].at<<","<<p[0].ct<<")|";
       
   for (int i = 1; i < n; i++)
   {
        if(p[i].at>p[i-1].ct)
        {
            cout<<"|idle("<<p[i].at-p[i-1].ct<<","<<p[i].at<<")|";
        }
        else
           cout<<"|P("<<p[i].at<<","<<p[i].ct<<")|";

   }
   
   // for printing the values
   cout<<endl<<"id\tAT\tBT\tCT\tTAT\tWT"<<endl;
   for (int i = 0; i < n; i++)
   {
       cout<<p[i].id<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
   }
   cout<<"avg Tat="<<avg_tat<<endl;
   cout<<"avg_wt="<<avg_wt<<endl;
}
