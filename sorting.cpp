#include<stdio.h>
#include<limits.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void selectionSort(int arr[],int n)
{
    int min=INT_MAX,ind;
   for(int i=0;i<n;i++)
   {
       min = arr[i];
       for(int j=i;j<n;j++)
       {

           if(min>=arr[j])
               min=arr[j],ind=j;
       }
       swap(&arr[i],&arr[ind]);
   }
}

void bubbleSort(int arr[],int n)
{
    int i=0;
    int swapped=0;
    if(n<2)
        return;

    do
    {
        swapped = 0;
        for(int i=0;i<n-1;i++)
            if(arr[i]>arr[i+1])
                swap(&arr[i],&arr[i+1]),swapped=1;
    }
    while(swapped);
}

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j = i-1;
        int key = arr[i];

        while(j>=0 and arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        
        arr[j+1]=key;
    }
}

void merge(int arr[],int l,int m,int r)
{
    int n1 = m-l+1,n2 = r-m;
    int arr1[n1],arr2[n2];
    int k=0;

    for(int i=0;i<n1;i++)
        arr1[k++]=arr[i+l];
    
    k=0;
    for(int i=0;i<n2;i++)
        arr2[k++]=arr[m+1+i];
    
    int i=0,j=0;
    k=l;

    while(i<n1 and j<n2)
    {
        if(arr[i]<arr[j])
            arr[k++]=arr1[i++];
        else
            arr[k++]=arr2[j++];
    }

    while(i<n1)
        arr[k++] = arr1[i++];

    while(i<n2)
        arr[k++] = arr2[j++];

}

void mergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
         mergeSort(arr,l,(l+r)/2);
         mergeSort(arr,(l+r)/2+1,r);
         merge(arr,l,(r+l)/2,r);

    }
}

int partition(int arr[],int l,int r)
{
    int pivot = arr[r];
    int i=l;

    for(int j=l;j<r;j++)
    {
        if(arr[j]<=pivot)
            swap(&arr[j],&arr[i++]);
        
    }
    swap(&arr[i],&arr[r]);
    return i;
}

void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int piv = partition(arr, l,r);
        quickSort(arr,l,piv-1);
        quickSort(arr,piv+1,r);
    }
}

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n and arr[largest]<arr[left])
        largest = left;
    if(right<n and arr[largest]<arr[right])
        largest =right;

    if(largest != i)
    {
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);

    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
