#include <stdio.h>

void swap(char *a,char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char str[],int left,int right)
{
    if(left>=right)
        return;

    permute(str,left+1,right);
    for(int i=left+1;i<=right;i++)
    {
        swap(&str[i],&str[left]);
    printf("%s\n",str);
        permute(str,left+1,right);
        swap(&str[i],&str[left]);
    }
}

int main()
{
    char str[] = "ABCD";
    int n = int(sizeof(str)-1);
    //printf("%s\n",str);
    permute(str, 0, n-1);
    return 0;
}
