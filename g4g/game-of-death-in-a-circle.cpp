#include <stdio.h>
using namespace std;

void josephCircle(int n,int k)
{
//    printf("%d %d\n\n",n,k);
    
    int dp[n+1];
    dp[1]=1;
    //printf("ntab-%d %d\n",dp[1],1);

    for(int i=2;i<=n;i++)
    {
        dp[i] = (dp[i-1]+k-1)%i+1;
        //printf("ntab-%d %d\n",dp[i],i);
    }
    printf("%d\n",dp[n]);
}


int jc(int n,int k)
{
    int soluchan;
    if(n==1)
        soluchan = 1;
    else
        soluchan = (jc(n-1,k)+k-1)%n+1;
    //printf("nr-%d %d\n",soluchan,n);

    return soluchan;
}

int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        
       // printf("\n%d %d\n",n,k);
        josephCircle(n,k);
        //printf("%d\n",jc(n,k));     
    }
	return 0;
}
