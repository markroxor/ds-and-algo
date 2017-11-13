#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int compare(const void *a, const void *b)
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
        
        char arr[n][1000];
        int count[n][27],cnt[n];
        for(int i=0;i<n;i++)
        {
            for(int c=0;c<27;c++)
                count[i][c]=0;
            cnt[i]=0;

            scanf("%s",arr[i]);
            
            for(int k=0;arr[i][k]!='\0';k++)
                count[i][arr[i][k]-'a']=1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(cnt[i]==-1)
                    continue;

                int flag=1;
                for(int c=0;c<26;c++)
                {
                    if(count[i][c]!=count[j][c])
                    {
                        flag=0;
                        break;
                    }
                }

                if(flag)
                    cnt[i]++,cnt[j]=-1;

                
            }
        }
        qsort(cnt, n, sizeof(int), compare);
        for(int i=0;i<n;i++)
            if(cnt[i]!=-1)
            printf("%d ",cnt[i]+1);
        printf("\n");

    }
	return 0;
}
