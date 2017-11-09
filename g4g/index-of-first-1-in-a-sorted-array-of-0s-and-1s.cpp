#include <stdio.h>
using namespace std;

int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int arr[n],sum=0;
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]),sum+=arr[i];
		if (sum==0)
			sum=n+1;
		printf("%d\n",n-sum);
    }
	return 0;
}
