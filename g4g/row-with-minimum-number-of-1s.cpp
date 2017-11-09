#include <stdio.h>
#include <limits.h>

int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int r,c;
        scanf("%d %d",&r,&c);
        
        int tsum=0,arr[r][c],gmin=INT_MAX,sum=0,ind=-1;
        for(int i=0;i<r;i++)
		{
			int sum=0;
			for(int j=0;j<c;j++)
				{
            		scanf("%d",&arr[i][j]);
                    tsum+=arr[i][j];
					sum+=arr[i][j];		
				}
            if(sum!=0 and sum<gmin)
            {
                ind = i;
			    gmin = sum<gmin?sum:gmin;
            }
		}
		if(tsum==0)
			ind=-1;
		printf("%d\n",ind);
    }
	return 0;
}
