#include <stdio.h>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int comp(const void *a,const void *b)
{return *(long long int *)a-*(long long int *)b;}

int comp1(const void *b,const void *a)
{return *(long long int *)a-*(long long int *)b;}

int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        scanf("%d",&n);
        
        long long int arr[n],vis[n];
        for(int i=0;i<n;i++)
            scanf("%lld",&arr[i]),vis[i]=0;

        qsort(arr,n,sizeof(long long int),comp);
        printf("%lld d\n",arr[0]); 
        long long int ind=-1,sum=0;
        for(int i=1;i<n;i++)
        {

            //printf("%d %lld \n",i,arr[i-1]);
            if(arr[i]*arr[i-1]>=0 and vis[i]!=1 and vis[i-1]!=1)
            {
                sum=(sum+(arr[i]*arr[i-1])%MOD)%MOD;
                
               // printf("%d %d\n",arr[i],arr[i-1]);
                vis[i]=1;
                vis[i-1]=1;
                //i++;
            }
            else if (arr[i]*arr[i-1]<0)
            {   
              //  ind = i-1;
                break;
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            //printf("i %d %d \n",arr[i],arr[i-1]);
            if(arr[i]*arr[i+1]>0 and vis[i]!=1 and vis[i+1]!=1)
            {
                sum=(sum+(arr[i]*arr[i+1])%MOD)%MOD;
                
                //printf("%d %d\n",arr[i],arr[i-1]);
                vis[i]=1;
                vis[i+1]=1;
                //i--;
            }
            else if (arr[i]*arr[i+1]<0)
            {
            //    ind = i;
                break;
            }
        }
        printf("\n");
        long long int viss=1,flag=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                flag=1;
//                sum=(sum+arr[i])%MOD;
                viss = (viss*arr[i])%MOD;
                printf("%d %lld ",i,arr[i]);
                //break;
            }
        }
        if(flag)
                sum=(sum+viss)%MOD;
        printf("\n");


        //if(ind!=-1)
        //    sum+=arr[ind];
        printf("%lld\n",sum);
    }
	return 0;
}
