#include <stdio.h>
using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int arr[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
		
        int m_till_now = arr[n-1]-1;
        int ind=-1;
        
        int parr[n],k=0;
		for(int i=n-1;i>=0;i--)
		{
            if(m_till_now<arr[i])
            {
                ind = i;
                parr[k++] = arr[i];
                //printf("%d ",arr[i]);
                m_till_now = arr[i];
            }
            else if (m_till_now==arr[i])
                ind = -1;
		}
        for(int i=k-1;i>=0;i--)
            printf("%d ",parr[i]);

        printf("\n");
        if(ind != -1)
            printf("%d\n",arr[ind]);
        else
            printf("-1\n");
    }
	return 0;
}
