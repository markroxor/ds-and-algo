#include <stdio.h>
using namespace std;

class Pair
{
    public:
    int a,b;
};

int max(Pair p)
{
    return p.a>p.b?p.a:p.b;
}

void swap(Pair &a, Pair &b)
{
	Pair c=a;
	a = b;
	b = c;
}
/*
int partition(int arr[], int st, int ed)
{
	int piv = arr[ed];
	int j = st;

	for(int i=st;i<ed;i++)
	{
		if(arr[i] > piv)
		{
			swap(arr[i],arr[j++]);				
		}
	}
	swap(arr[j],arr[ed]);
	return j;
}

void quicksort(int p[],int st,int ed)
{
	if(st<ed)
	{
		int piv = partition(p,st,ed);
	}
}
*/
int heapify(Pair arr[],int n,int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    //for(int i=0;i<n;i++)
    //{
        if(left<n and max(arr[left]) < max(arr[largest]))
        {
            //swap(arr[left],arr[largest]);
            largest = left;
        }    
        if(right<n and max(arr[right]) < max(arr[largest]))
        {
            //swap(arr[right],arr[largest]);
            largest = right;
        }
    //}
    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(Pair arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }

    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int printArray(Pair arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d %d,",arr[i].a,arr[i].b);
    printf("\n");
}

int main() {
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        int n,x,y;
        scanf("%d %d %d",&n,&x,&y);
        
        Pair p[n];
        for(int i=0;i<n;i++)
            scanf("%d",&p[i].a);

        for(int i=0;i<n;i++)
           scanf("%d",&p[i].b);

		heapSort(p,n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(x and p[i].a>p[i].b)
            {
                sum+=p[i].a;
                //printf("%d ",p[i].a);
                x--;
            }
            else
            {
                sum+=p[i].b;
                //printf("%d ",p[i].b);
                y--;
            }
        }
        printf("%d\n",sum);
        //printArray(p,n);
    }
	return 0;
}
