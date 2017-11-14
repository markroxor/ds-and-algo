
#include <stdio.h>
using namespace std;


int lis(int arr[],int n)
{
    int LIS[n+1],maxi=0,ind=-1;
    for(int i=0;i<n;i++)
    {
        LIS[i]=arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] and LIS[i]<arr[i]+LIS[j])
                LIS[i]=LIS[j]+arr[i];
        }
        if(maxi<LIS[i])
        {
            ind = i;
            maxi = LIS[i];
        }
    }
    
    return maxi;
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
        
        printf("%d ",lis(arr,n));
        printf("\n");
    }
	return 0;
}
