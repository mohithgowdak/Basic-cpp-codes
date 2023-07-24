#include<iostream>
#include<cstdlib>
using namespace std;

int count;
int LinearSearch( int* a,int n,int key)
{   int j=1;
    for(int i=0;i<n;i++)   //i<arr.size();
    {   //cout<<a[i];
        count++;
        if(a[i]==key)
        {
            return i;
        }
    }
    return -1;
}
int main(void)
{
    FILE *fp1=fopen("best.txt","w");
    FILE *fp2=fopen("worst.txt","w");
    
    for(int m=10;m<=1000;m=(m<100)?m+10:m+100)
    {
        count=0;
        int* arr=new int[m];
        for(int i=0;i<=m;i++)
         {
            
         }
         for (int i = 0; i < m; i++)
         {
            arr[i]=i+1;
         }
         
        int pos = LinearSearch(arr,m,1);
        fprintf(fp1,"%d\t\t%d\n",m,count);
        count = 0;
        pos = LinearSearch(arr,m,-1);
        fprintf(fp2,"%d\t\t%d\n",m,count);
        free(arr);
    }
    fclose(fp1);
    fclose(fp2);
}
    //CORRECTNESS
   /*int m;
    cout<<"enter the number of elements";cin>>m;
    cout<<"the elements will be arranged from 1 to"<<m<<endl;
    int *arr=new int(m); // here dynamically vectors couldnt be used for analysis of large array size
                         //vector<int> arr(m);
     for(int i=0;i<m;i++)
    {
       arr[i]=i+1;      //arr.push_back(i+1);
       
    }
    cout<<"enter the key";
    int key; cin>>key;
    int pos = LinearSearch(arr,m,key);
    if(pos==-1)
    cout<<"not found";
    else
    cout<<"found";
    return 0;
}*/