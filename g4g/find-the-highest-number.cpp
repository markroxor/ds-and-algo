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
        
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        
        int i=1;
        while(i< n and arr[i]>arr[i-1])
            i++;

        printf("%d\n",arr[i-1]);
    }
	return 0;
}
