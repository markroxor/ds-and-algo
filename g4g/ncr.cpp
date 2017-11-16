#include <stdio.h>
using namespace std;
#define mod 1000000007

void printP(int n,int k)
{
    if(k>n)
    {printf("0\n");return;}
    //for(int line=1;line<=n;line++)
    int line=n;
	{
        int c=1;
        for(int i=1;i<=line;i++)
        {
            if(k==i)
            {
            printf("%d %d\n",c,line-i);
            break;
            }
            c=((c* (line-i)+mod)%mod/i)%mod;
        }
    }
    printf("\n");
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
        
		printP(n+1,k);
    }
	return 0;
}


