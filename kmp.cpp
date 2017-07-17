#include<stdio.h>
#include<cstring>
using namespace std;

int *printLCS(char str[])
{
    int len = strlen(str);
    int *lcs = new int[len];
    lcs[0] = 0;
    for(int i=1;i<len;i++)
    {
        if(str[i]==str[lcs[i-1]])
            lcs[i] = lcs[i-1]+1;
        else if(str[i]==str[i-1])
            lcs[i] = lcs[i-1];
        else
            lcs[i] = 0;
    }

    return lcs;
}

void kmp(char str[], char pat[])
{
    int n = strlen(str);
    int m = strlen(pat);
    int *lcs = printLCS(pat);
    for(int i=0;i<strlen(pat);i++)printf("%d ",lcs[i]);

    int i=0,j=0;
    int st=-1;
    printf("\n");
    while(i<n and j!=m)
    {
        printf("i=%d j=%d lcs[j]=%d\n",i,j,lcs[j]);
        if(str[i]==pat[j])
        {
            if(st==-1)
                st=i;
            printf("same %c\n",str[i]);
            i++;
            j++;
        }
        else
        {
            if(j)
            {j = lcs[j-1];}
            else
            {
            st=-1;
            i++;
            }
        }

    }

    if(j==m)
        printf("Found at i %d\n",st);
    else
        printf("Not found\n");
}

int main()
{
    char str[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    char str1[] = "jhaksjkjlkdjslkjljlkjdlkjasljdlkjasldjljjdlksajdlksajdyuiwqoupoklajhjhj";//"I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN";
    char pat1[] = "jlkjdlkj";//"SEVENTY SEVEN";
    kmp(str1, pat1);
    return 0;
}
