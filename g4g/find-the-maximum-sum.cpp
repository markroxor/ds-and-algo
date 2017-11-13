#include <stdio.h>
#include <algorithm>
using namespace std;
#define MOD 1000000007
int comp(const void *b,const void *a)
{return *(int *)a-*(int *)b;}

int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        int arr[n],vis[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]),vis[i]=0;

        qsort(arr,n,sizeof(int),comp);
        
        int ind=-1,sum=0;
        for(int i=1;i<n;i++)
        {
           // printf("i %d %d \n",arr[i],arr[i-1]);
            if(arr[i]*arr[i-1]>=0)
            {
                sum=(sum+(arr[i]*arr[i-1])%MOD)%MOD;
                
               // printf("%d %d\n",arr[i],arr[i-1]);
                vis[i]=1;
                vis[i-1]=1;
                i++;
            }
            else
            {   
              //  ind = i-1;
                break;
            }
        }
        for(int i=n-2;i>=1;i--)
        {
            //printf("i %d %d \n",arr[i],arr[i-1]);
            if(arr[i]*arr[i+1]>=0 and vis[i]!=1 and vis[i-1]!=1)
            {
                sum=(sum+(arr[i]*arr[i+1])%MOD)%MOD;
                
                //printf("%d %d\n",arr[i],arr[i-1]);
                vis[i]=1;
                vis[i-1]=1;
                i--;
            }
            else
            {
            //    ind = i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                sum=(sum+arr[i])%MOD;
                break;
            }
        }


        //if(ind!=-1)
        //    sum+=arr[ind];
        printf("%d\n",sum);
    }
	return 0;
}
