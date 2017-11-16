#include <stdio.h>
#include <limits.h>
using namespace std;

int matmul(int arr[],int n)
{
    int m[n][n];


    for(int l=1;l<n;l++)
    {
        for(int i=0;i+l-1<n;i++)
        {
            int j=i+l-1;
            if(l==1)
            {
                m[i][j]=0;
                continue;
            }
            m[i][j] = INT_MAX;

            for(int k=i;k<j;k++)
            {
                if(m[i][j] > (m[i][k]+m[k+1][j] + arr[i-1]*arr[k]*arr[j]))
                    m[i][j] = m[i][k]+m[k+1][j] + arr[i-1]*arr[k]*arr[j];
            }
        }
    }

    return m[1][n-1];
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

        printf("%d\n",matmul(arr,n));
    }
	return 0;
}
