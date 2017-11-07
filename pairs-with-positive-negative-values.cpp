#include<stdio.h>

void swap(int &a, int &b)
{
    int c=a;
    a=b;
    b=c;
}

void printArr(int arr[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[],int st,int ed)
{
    int p = arr[ed];
    int j = st;

    for(int i=st;i<ed;i++)
    {
        if(arr[i]<p)
            swap(arr[i], arr[j++]);
    }
    swap(arr[ed], arr[j]);
    return j;
}

void qsort(int arr[], int st, int ed)
{
    if(st<ed)
    {
        int p = partition(arr, st, ed);
        qsort(arr, st, p-1);
        qsort(arr, p+1, ed);
    }
}

int abs(int a)
{
    return (a<0)?-a:a;
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
       int n;
       scanf("%d", &n);
        


       int arr[n];
       for(int i=0;i<n;i++)
           scanf("%d",&arr[i]);
       
       qsort(arr, 0, n-1);
       
       //printf("\n");
       //printArr(arr,n);
       //printf("\n"); 
       
       int l=0,r=n-1;
       int act=0;

       int outAr[n];
       int i=0;

       while(l<r)
       {
        //   printf("%d %d %d %d\n",l,r, abs(arr[l]), abs(arr[r]));
           if(arr[l]==-arr[r])
           {
               act=1;
        //       printf("%d-",i);
        //       printf("%d %d, ",arr[l],arr[r]);
               outAr[i++] = -arr[l];
               l++;r--;
           }
           else if (abs(arr[l]) > abs(arr[r]))
               l++;
           else if (abs(arr[l]) < abs(arr[r]))
               r--;
           else
               l++,r--;
       }
 //      printf("\n%d %d %d %d\n",l,r,arr[l],i);
       for(int j=i-1;j>=0;j--)
           printf("%d %d ",-outAr[j],outAr[j]);
        
//       printf("\n%d\n",outAr[103]);
       if(!act)
           printf("0");
       
       printf("\n");
    }
}
