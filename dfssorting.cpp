#include<iostream>
#include<cstdlib>
using namespace std;
int v[40],p[40],g[40][40],sta[40],top=-1,cnt=0;bool flag=false;
void dfs(int n,int st,int pt)
{
  v[st]=1;
  p[st]=1;
  for(int i=0;i<n;i++)
  {  cnt++;
    if( i != pt && v[i] && p[i] && g[st][i])
    { 
       flag=true;
       return;
    }
    else
    {
       if (!v[i] && g[st][i] )
       { 
         dfs(n,i,st);
       }
       
    }
    
  }

  p[st]=0;
  sta[++top]=st;
}

int main(void)
{  int n;
    cout<<"enter the number of vertices "<<endl<<"enter the adjacency matrix";
    cin>>n;
    for(int i=0;i<n;i++)
    {
      for (int j = 0; j < n;j++)
      {
         cin>>g[i][j];
         v[i]=0;
         p[i]=0;
      }
    }
    FILE* fp;
    for (int i = 0; i < n; i++)
    { if(!v[i])
      dfs(n,i,-1);
    }
    fp=fopen("xx.txt","a+");
    fprintf(fp,"%d\t\t%d\n",n,cnt);
    fclose(fp);
    if (flag==true)
      cout<<"the graph is cyclic\n";
    else
    { cout<<"toplogical order is"<<endl;
      for(int i=top;i>=0;i--)
       cout<<sta[i]+65<<"--->";
    }
    
  return 0;  
}