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
        n++;

        while(n>1 and n%2==0)
            n/=2;
       
        if(n!=1 and n%2==1)
           printf("NO\n");
        else
           printf("YES\n"); 
        
        
    }
	return 0;
}
