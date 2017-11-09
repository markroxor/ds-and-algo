#include <stdio.h>
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
        int n,s;
        scanf("%d%d",&n,&s);
        
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        heapSort(arr,n);

        //for(int i=1;i<n;i++)
        //    arr[i]+=arr[i-1];

        //printArr(arr,n);
        int c=0;

        for(int i=0;i<n-2;i++)
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(arr[i]+arr[j]+arr[k]>=s)
                {
                    k--;
                }
                else
                {
                    c += k-j;
                    j++;
                }
            }
        }
        printf("%d\n",c);
        //printArr(arr,n);
        //printArr(arr,n);
    }
	return 0;
}

