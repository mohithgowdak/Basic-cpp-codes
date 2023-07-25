#include <iostream> 
#include <bits/stdc++.h>
#include<time.h>
using namespace std;
int cnt;
void selectionSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) 
        {   cnt++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != arr[i]) {
            // Swap the elements at min_index and i
            /*int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;*/
            swap(arr[i],arr[min_index]);
        }
    }
}

int main() {
    /*int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) 
    {
     cin >> arr[i];
    }


    selectionSort(arr, size);
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
    }
    cout << "\n";

    delete[] arr; // Free the dynamically allocated memory*/
    // to analysis
    FILE *fp;
    fp=fopen("selct.txt","w+");
    for (int m = 5; m<=15;m++)
    {
        int *arr=new int(m);
        cnt=0;
        for (int i = 0; i < m; i++)
           arr[i]=i+1;
        selectionSort(arr,m);
        fprintf(fp,"%d\t\t%d\n",m,cnt);
        delete[] arr;

    }
    fclose(fp);
    
    return 0;
}
