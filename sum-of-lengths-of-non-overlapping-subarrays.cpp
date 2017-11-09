#include <stdio.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int arr[n],ct[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]),ct[i]=0;
        
        int k;
        scanf("%d",&k);
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==k)
            {
                //printf("%d ",k);
                sum++;
                int l=i-1,r=i+1;
                while(l>=0 and arr[l]<k and ct[l]==0)
                {
                    //printf("%d ",arr[l]);
                    sum++;
                    ct[l]=1;
                    l--;
                }
                while(r<n and arr[r]<k and ct[r]==0)
                {
                    //printf("%d ",arr[r]);
                    sum++;
                    ct[r]=1;
                    r++;
                }
            //printf("\n");
            }
        }
        printf("%d\n",sum);
    }
	return 0;
}
