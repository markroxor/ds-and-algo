#include <stdio.h>
using namespace std;

int toBase6(int n,int b)
{
    if(n==0)
        return n;
    return (n%b)+10*toBase6(n/b, b);
}

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);

		printf("%d\n",toBase6(n-1,6));
        
    }
	return 0;
}
