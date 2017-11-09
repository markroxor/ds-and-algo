#include <stdio.h>
using namespace std;

class Pair
{
    public:
    int i,j;
    //Pair(int a,int b)
    //{i=a;j=b;}
};

class Queue
{
    public:
    int front,rear,size,cap;
    Pair *arr;

    Queue(int cap)
    {
        this->cap = cap;
        //Pair p;//(-1,-1);
        arr = new Pair[cap];
        //for(int i=0;i<cap;i++)
        //    arr[i] = new Pair(-1,-1);

        size = 0;
        front=0;
        rear=0;
    }
    void push(Pair it)
    {
        if(size>=cap)
            return;
        arr[(rear++)%cap]=it;
        size ++;
    }
    Pair pop()
    {
        Pair it;//(-1,-1);
        it.i=-1;
        it.j=-1;
        if(size<=0)
            return it;
       size--; 
        it=arr[(front++)%cap];
        return it;
    }

    bool isFull()
    {return size==cap;}

    bool isEmpty()
    {return size==0;}
};

Pair delim()
{
    Pair p;
    p.i = -1;
    p.j = -1;
    return p;
}

bool isDelim(Pair p)
{
    if(p.i==-1 and p.j==-1)
        return true;
    return false;
}

void pQue(Queue q)
{
    printf("printint q- ");
    while(q.front%q.cap != q.rear%q.cap)
        printf("%d%d ",q.arr[q.front].i,q.arr[q.front].j),q.front++;
    printf("printed q\n");
}

int main() {
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int dirx[] = {1,-1,0,0};
    int diry[] = {0,0,1,-1};
    int t1;
    scanf("%d",&t1);
    
    while(t1--)
    {
        int ones=0,r,c;
        scanf("%d%d",&r,&c);
        
        int mesh[r][c];
        Queue q(r*c+1);

        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                scanf("%d",&mesh[i][j]);
                if(mesh[i][j]==2)
                {
                    Pair p;
                    p.i=i;
                    p.j=j;
                    q.push(p);
                }
                if(mesh[i][j]==1)
                    ones++;
            }
        
        
        q.push(delim());
        //printf("%d\n",isDelim(delim()));
        int t=0;
        while(!q.isEmpty())
        {
            Pair p=q.pop();

            while(!isDelim(p))
            {
           // printf("pop %d%d\n",p.i,p.j);
        //pQue(q);
                //printf("\n");
                for(int i=0;i<4;i++)
                {
                    int nx=dirx[i]+p.i;
                    int ny=diry[i]+p.j;
                    if(nx<r and ny<c and nx>=0 and ny>=0 and mesh[nx][ny]==1)
                    {
                        ones--;
                    //printf("re%d%d ",nx,ny);
                    mesh[nx][ny]=2;
                        Pair pn;//(nx,ny);
                        pn.i = nx;
                        pn.j = ny;
                        q.push(pn);
                    }
                }
                //printf("\n");
                p=q.pop();
                //printf("post while\n");
     //           pQue(q);
            }
            //break;
            //q.pop();
            t++;
            if(!q.isEmpty())
            q.push(delim());
        }
        if(ones==0)
        printf("%d\n",t-1);
        else
            printf("-1\n");
    }
	return 0;
}
