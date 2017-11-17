#include <stdio.h>
using namespace std;
#define mod 1000000007
#define int long long int

int pow(int a,int b)
{
    a%=mod;
    if(b==0)
        return 1;
   
    int res = 1; 
    int half_p = pow(a,b/2);
    if(b&1)
         res = (res*a)%mod;

    return (half_p*half_p)%mod * res%mod;
}

void printP(int n,int r)
{
    if(r>n or r==0)
    {printf("0\n");return;}
    //for(int line=1;line<=n;line++)
    int line=n;
	{
        int c=line;
        for(int i=1;i<=r;i++)
        {
            //printf("u - %lld %lld %lld\n",line-i-1,i,c);
            if(r==i)
            {
            printf("%lld\n",c);
            break;
            }
            //printf("%lld %lld %lld\n",i,pow(i,mod-2),power(i,mod-2,mod));

            c=( (c*(line-i-1)%mod) * (pow(i,(mod-2))%mod))%mod;
            
        }
    }
}

int min(int a,int b)
{return a<b?a:b;} 

int binomialCoeff(int n, int k)
{
    int C[k+1];
    for(int i=0;i<k+1;i++)
        C[i]=0;
//    memset(C, 0, sizeof(C));
 
    C[0] = 1;  // nC0 is 1
    C[1] = 1;
 
    for (int i = 2; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        //for (int j = min(i, k); j > 0; j--)
    //    printf("row - %lld\n",i);
        for (int j = min(k,n); j>0;j--)
            C[j] = (C[j] + C[j-1])%mod;
        
    }
    return C[k];
}

main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%lld",&t);
    
    while(t--)
    {
        int n,k;
        scanf("%lld%lld",&n,&k);
        
        //int i=95;
        //printf("%lld %lld %lld\n",i,pow(i,mod-2),power(i,mod-2,mod));
	//	printP(n,k);
        printf("%lld\n",binomialCoeff(n,k));
    }
	return 0;
}


