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
        
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);

        int inc=arr[0],exc=0;
        for(int i=1;i<n;i++)
        {
            int texc =exc;
            exc = exc>inc?exc:inc;
            inc = texc + arr[i];
        }
        printf("%d\n",exc>inc?exc:inc);
    }
	return 0;
}
