#include<stdio.h>
#define MAX 2147483647


int graph[100][100] = {{0,0,0,0,0,0},
                   {0,0,2,0,3,8},
                   {0,2,0,5,4,0},
                   {0,0,5,0,6,0},
                   {0,3,4,6,0,7},
                   {0,8,0,0,7,0},};
int A[30] , V[30] = { 0 }, B[30];
int n = 5;


void display()
{
    for(int i=2; i<=n; i++)
    {
        printf("\n%d to %d w = %d", i, B[i], A[i]);

    }
}

int min()
{
    int min = MAX;
    int pos, i;
    for(i=2; i<=n; i++)
    {
        if(V[i]==0 && A[i]<min)
        {
            min = A[i];
            pos = i;
        }
    }
    V[pos] = 1;
    return pos;
}


void dijkstra()
{
    int i, j, ch;
    ch = 1;
    V[1]=1;
    A[1]=0;
    printf("entered Dijk algo\n");
        for(j=2; j<=n; j++)
        {

            if(graph[j][ch]!=0 && graph[j][ch] < A[j])
            {

                A[j] = graph[j][ch];
                B[j] = ch;
            }

        }


    for(i=0; i<n-1;i++)
    {

        ch = min();
        for(j=1; j<=n; j++)
        {
            if(graph[j][ch]!=0 && (graph[j][ch]+A[ch]) < A[j] && V[j]==0)
            {
                A[j] = graph[j][ch] + A[ch];
                B[j] = ch;
            }

        }

    }
    display();

}



int main()
{
    int j;


    for(j=0; j<=n; j++)
    {
       A[j] = 2147483647;
       B[j] = 2147483647;
    }


    dijkstra();

}


