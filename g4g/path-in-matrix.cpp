#include <stdio.h>
#include <limits.h>
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
        
        int arr[n][n];
        int maxs[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&arr[i][j]),maxs[i][j]=INT_MIN;

        int maxi=INT_MIN;
        for(int r=0;r<n;r++)
            for(int c=0;c<n;c++)
            {
                if(r==0)
                {
                    maxs[r][c] = arr[r][c];
                    continue;
                }
                if(c-1>=0 and maxs[r][c]<maxs[r-1][c-1]+arr[r][c])
                    maxs[r][c] = maxs[r-1][c-1]+arr[r][c];
                if(c+1<n and maxs[r][c]<maxs[r-1][c+1]+arr[r][c])
                    maxs[r][c] = maxs[r-1][c+1]+arr[r][c];
                if(maxs[r][c]<maxs[r-1][c]+arr[r][c])
                    maxs[r][c] = maxs[r-1][c]+arr[r][c];

                if(r==n-1)
                    maxi=maxi>maxs[r][c]?maxi:maxs[r][c];
            }
        printf("%d\n",maxi);
    }
	return 0;
}
