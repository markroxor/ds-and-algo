#include <stdio.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        
        int arr[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&arr[i][j]);

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                printf("%d ",arr[i][(j+k)%m]);
        printf("\n");

    }
	return 0;
}
