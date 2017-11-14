#include <stdio.h>
using namespace std;

int nthFib(int n)
{

    if(n<3)
        return 1;
    if(n&1)
    {
        n = (n+1)/2;
        return nthFib(n)*nthFib(n) + nthFib(n-1)*nthFib(n-1);
    }

    n/=2;
    return (2*nthFib(n-1) + nthFib(n))*nthFib(n); 
}

int main() {
    int n=1,sum=0,temp=1;
    
    while(temp<=4000000)
    {
        temp=nthFib(n);
        if(temp%2==0)
            sum+=temp;
        n++;
    }
    printf("%d\n",sum);
    return 0;
}
