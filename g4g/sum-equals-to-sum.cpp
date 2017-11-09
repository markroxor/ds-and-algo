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
		
        int hesh[n*n+1],k=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                hesh[k++]=arr[i]+arr[j];
            }
        int flag=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(hesh[i]==hesh[j])
                {flag=1;break;}
            }
        if(flag)
            printf("1\n");
        else
            printf("0\n");
    }
	return 0;
}
