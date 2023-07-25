#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int cnt;
// Function to perform Bubble Sort
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) 
    {   bool flag=false;
        for (int j = 0; j < size - i - 1; ++j) 
        { cnt++;
            if (arr[j] > arr[j + 1]) 
            {   flag=true;
                swap(arr[j],arr[j+1]);
                // Swap the elements if they are in the wrong order
                /*int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;*/
            }
        }
        if(!flag)
           break;
    }
}

int main() {
    /*int size;
     cout << "Enter the number of elements: ";
    cin >> size;
    // Dynamically allocate memory for the array
    int* arr = new int[size];
    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    // Call Bubble Sort function
    bubbleSort(arr, size);
    cout << "Sorted array in ascending order:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    // Deallocate memory for the array
    delete[] arr;*/
    // analysis
    FILE *fp1,*fp2;
    fp1=fopen("bestbub.txt","w+");
    fp2=fopen("worstbub.txt","w+");

    for(int m=10;m<=25;m++)
    {
        int* arr= new int[m];
        // best case
        for(int i=0;i<m;i++)
            arr[i]=i+1;
        cnt=0;
        bubbleSort(arr,m);
        cout<<m<<"\t\t"<<cnt;
        fprintf(fp1,"%d\t\t%d\n",m,cnt);
        // worst case
        for(int i=0;i<m;i++)
               arr[i]=m-i;
        cnt=0;
          bubbleSort(arr,m);
          fprintf(fp2,"%d\t\t%d\n",m,cnt);
        
        delete[] arr;
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
