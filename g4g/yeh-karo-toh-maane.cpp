#include <stdio.h>
using namespace std;

long long int nthFib(long long int n)
{
    //return n;
    printf("%lld\n",n);

    if(n<3)
        return 1;
    if(n&1)
    {
        n = (n+1)/2;
        return (nthFib(n)*nthFib(n) + nthFib(n-1)*nthFib(n-1));
    }

    n/=2;
    return ((2*nthFib(n-1) + nthFib(n))*nthFib(n)); 
}

int main() {
    freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        n%=300;
        printf("%lld\n",n);
        printf("%lld\n",nthFib(n));//%100);
//        if(temp%2==0)
//            sum+=temp;
//        n++;
    }
    //printf("%d\n",sum);
    return 0;
}
