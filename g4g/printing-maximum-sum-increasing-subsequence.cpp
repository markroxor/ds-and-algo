#include <stdio.h>
using namespace std;


int lis(int arr[],int n)
{
    int LIS[n+1],maxi=0;
    for(int i=0;i<n;i++)
    {
        LIS[i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] and LIS[i]<1+LIS[j])
                LIS[i]=LIS[j]+1,maxi=maxi>LIS[i]?maxi:LIS[i];
        }
    }

    return LIS[n-1];
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
        
        printf("%d\n",lis(arr,n));
    }
	return 0;
}
