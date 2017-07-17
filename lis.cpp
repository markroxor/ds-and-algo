#include<stdio.h>
#include<limits.h>

int max(int a,int b)
{return a>b?a:b;}

int lis(int arr[],int n)
{
    int dp[n+1];
    for(int i=0;i<n;i++)
        dp[i]=1;

    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
                dp[i] = max(dp[i],dp[j]+1);
        }

    int maxi = INT_MIN;
    for(int i=0;i<n;i++)
        maxi = max(dp[i],maxi);

    return maxi;

}

/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n",
    lis( arr, n ));
    return 0;
}
