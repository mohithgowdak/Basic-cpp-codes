#include <iostream>
#include<cstdlib>

using namespace std;
int cnt;
// Function to perform insertion sort
void insertionSort(int* arr, int size) 
{
    for (int i = 1; i < size; i++) 
    {
        int j = i - 1;
        int key=arr[i];
        while (j >= 0 ) 
        {  cnt++;
            if(arr[j] >key)
            {
               arr[j + 1] = arr[j];
                j--;
            }
            else
             break;
        }

        arr[j + 1] = key;
    }
}

int main() {
    /*int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    // Dynamic memory allocation for the array
    int* arr = new int[size];
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    insertionSort(arr, size);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    // Deallocate the dynamically allocated memory
    delete[] arr;*/

    FILE *fp1,*fp2;
    fp1=fopen("bestis.txt","w");
    fp2=fopen("worstis.txt","w");
    for(int m=5;m<=15;m++)
    {   int* a= new int(m);
        // best case
        cnt=0;
        int i;
        for( i=0;i<m;i++)
          a[i]=i+1;
        insertionSort(a,m);
        fprintf(fp1,"%d\t\t%d\n",m,cnt);
        cout<<m<<"\t\t"<<cnt<<endl;

        // worst case
         cnt=0;
        for( i=0;i<m;i++)
         a[i]=m-i;
         insertionSort(a,m);
         fprintf(fp2,"%d\t\t%d\n",m,cnt);
          cout<<m<<"\t\t"<<cnt<<endl;
         delete[] a;
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}