#include<stdio.h>
#include<limits.h>

int min(int a,int b)
{
    return a<b?a:b;
}

int MatrixChainOrder(int arr[],int n){
    int matrix[n][n];
    for(int i=0;i<n;i++) matrix[i][i]=0;
    
    for(int link=2;link<n;link++)
    {
        for(int i=1;i+link-1<n;i++)
        {
            int j = i+link-1;
            matrix[i][j] = INT_MAX;
            for(int k=i;k<j;k++)
            {
                matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k+1][j] + arr[i-1]*arr[k]*arr[j]);
            }
        }
    }
    return matrix[1][n-1];
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Minimum number of Multiplications is %d ",
    MatrixChainOrder(arr, size));
    
    getchar();
    return 0;
}
