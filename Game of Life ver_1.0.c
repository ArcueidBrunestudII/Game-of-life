 #include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
int random(int i)
{
    time_t tm=time(NULL);
    unsigned int tmx=(tm+i)*(tm+i);
    srand((unsigned int)tmx);
    int x=rand();
    return x;
}
int ranplus(int i)
{
    int r=0,j[1];
    r=random(i);
    if(i<=99999)
    {
        i++;
    }
    else
    {
        i=1;
    }
    if(r%2==0)
    {
        j[0]=0;
    }
    else
    {
        j[0]=1;
    }
    return j[0];
}
int* initialize(int n)
{
    int i=1,j,MAX=n*n,x,y;
    int* p;
    p=(int*)malloc(sizeof(int)*MAX);
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            if(i<=99999)
            {
                i++;
            }
            else
            {
                i=1;
            }
            *(p+x*n+y)=ranplus(i);
        }
    }
    return p;
}
void GL()
{
    int n,x,y,MAX,i=0,t;
    int* p=NULL;
    int* q=NULL;
    scanf("%d",&n);
    MAX=n*n;
    q=malloc(sizeof(int)*MAX);
    p=initialize(n);
    loop:
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            if(y==n-1)
            {
                printf("%d\n",*(p+x*n+y));
            }
            else
            {
                printf("%d ",*(p+x*n+y));
            }
        }
    }
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            if(x==0||x==n-1||y==0||y==n-1)
            {
                *(q+x*n+y)=*(p+x*n+y);
            }
            /*{
                i=*(p+x*n+y-1)+*(p+x*n+y+1)+*(p+(n-1)*n+y)+*(p+(n-1)*n+y+1)+*(p+(n-1)*n+y-1)+*(p+(x+1)*n+y)+*(p+(x+1)*n+y+1)+*(p+(x+1)*n+y-1);
            }
            if(x=n-1)
            {
                i=*(p+x*n+y-1)+*(p+x*n+y+1)+*(p+(x-1)*n+y)+*(p+(x-1)*n+y+1)+*(p+(x-1)*n+y-1)+*(p+y)+*(p+y+1)+*(p+y-1);
            }*/
            else
            {
                i=*(p+x*n+y-1)+*(p+x*n+y+1)+*(p+(x-1)*n+y)+*(p+(x-1)*n+y+1)+*(p+(x-1)*n+y-1)+*(p+(x+1)*n+y)+*(p+(x+1)*n+y+1)+*(p+(x+1)*n+y-1);
                if(*(p+x*n+y)==1)
                {
                    if(i<2||i>3)
                    {
                        *(q+x*n+y)=0;
                    }
                    else
                    {
                        *(q+x*n+y)=1;
                    }
                }
                else
                {
                    if(i==3)
                    {
                        *(q+x*n+y)=1;
                    }
                    else
                    {
                        *(q+x*n+y)=0;
                    }
                }
            }
        }
    }
    for(x=0;x<n;x++)
    {
        for(y=0;y<n;y++)
        {
            *(p+x*n+y)=*(q+x*n+y);
        }
    }
    Sleep(1000);
    system("cls");
    goto loop;
}
int main()
{
    GL();
    return 0;
}
