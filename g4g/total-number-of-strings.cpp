#include <stdio.h>
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
        
		n = 1 + n + n + n*(n-1)/2 + n*(n-1)*(n-2)/2 +n*(n-1);
		printf("%d\n",n);
    }
	return 0;
}
