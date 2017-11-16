#include <stdio.h>
using namespace std;

void printP(int n)
{
    for(int line=1;line<=n;line++)
    {
        int c=1;
        for(int i=1;i<=line;i++)
        {
            if(n==line)
            printf("%d ",c);
            c=c* (line-i)/i;
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
        int n;
        scanf("%d",&n);
        
		printP(n);
    }
	return 0;
}
