#include <stdio.h>
#include "sorting.h"
using namespace std;

int printArr(int arr[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int swap(int &a,int &b)
{
    int c= a;
    a=b;
    b=c;
}

int heapify(int arr[],int i,int n)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n and arr[largest]<arr[left])
        largest = left;
    if(right<n and arr[largest]<arr[right])
        largest = right;

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }

}

int heapSort(int arr[], int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,i,n);
    //printArr(arr,n);
    //printf("\n");
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[i], arr[0]);
        heapify(arr,0,i);
        //printArr(arr,n);
    }
}
int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int a[n], b[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]);
        heapSort(a,n);
        heapSort(b,n);

        printArr(a,n);
    }
	return 0;
}
