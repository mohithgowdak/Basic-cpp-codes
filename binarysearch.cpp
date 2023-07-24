#include <iostream>
#include<cstdlib>
using namespace std;
int cnt;
// Function for binary search using recursion
int binarySearchRecursive(int* arr, int low, int high, int key) {
    if (low <= high) 
    {
        int mid = (high+low) / 2;

        if (arr[mid] == key)
         {
          cnt+=1;  
          return mid; // Key found, return the index
         } else if (arr[mid] < key) 
         {
           cnt+=1;
            return binarySearchRecursive(arr, mid + 1, high, key); // Search in the right half
         } else 
         {
            cnt+=1;
            return binarySearchRecursive(arr, low, mid - 1, key); // Search in the left half
        }
    }

    return -1; // Key not found
}

int main() {


    FILE *fp1,*fp2;
    fp1 =fopen("best.txt","w+");
    fp2 =fopen("worst.txt","w+");

    for(int m=10;m<=10000;(m<100)?m+=10:m+=100)
    {
        int* arr= new int[m];
        for ( int i = 0; i < m; i++)
        {
            arr[i]=0;
        }
        //best case
        cnt=0;
        arr[(m-1)/2]=99;
        binarySearchRecursive(arr, 0, m-1, 99);
        fprintf(fp1,"%d\t\t%d\n",m,cnt);
        //worst caes
         cnt=0;
        binarySearchRecursive(arr, 0, m-1, -1);
        fprintf(fp2,"%d\t\t%d\n",m,cnt);
         delete[] arr;
    }
    fclose(fp1);
    fclose(fp2);
     
      
 /*  // for checking correct ness
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    // Dynamically allocate memory for the array using a pointer
    int* arr = new int[n];

    // Input the elements (assuming the array is sorted)
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    int index = binarySearchRecursive(arr, 0, n - 1, key);

    if (index != -1) {
        cout << "Element found "<< endl;
    } else {
        cout << "Element not found " <<endl;
    }

    // Don't forget to release the memory when you're done using the array.
    delete[] arr;*/

    return 0;
}
