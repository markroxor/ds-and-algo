#include <stdio.h>
using namespace std;

int max(int a,int b)
{return a>b?a:b;}

void bitonic(int arr[],int n)
{
    int lis[n],lds[n];
    
    for(int i=0;i<n;i++)
        lis[i]=1,lds[i]=1;

    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
                lis[i] = max(lis[i],lis[j]+1);
        }

    for(int i=n-1;i>=0;i--)
        for(int j=n-1;j>i;j--)
        {
            if(arr[i]>arr[j])
                lds[i] = max(lds[i],lds[j]+1);
        }

    int maxi=1;
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi,lis[i]+lds[i]-1);
    }

    printf("%d\n",maxi);
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
        
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        bitonic(arr,n);
    }
	return 0;
}
