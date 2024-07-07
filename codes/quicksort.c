#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n=5;
    int a[10]={10,9,8,7,6};

    quick(a,0,n-1);
    printf("\n");
    for(int j=0;j<n;j++)
    {
        printf("%d->",a[j]);
    }
}
void quick(int a[],int l,int h)
{
    int pivot;
    if(l<h)
    {
        pivot=part(a,l,h);
        quick(a,l,pivot-1);
        quick(a,pivot+1,h);
    }
}
int part(int a[],int l,int h)
{
    int pivot=a[l];
    int temp,i,j;
    i=l+1;
    j=h;
    do{
        while(a[i]<pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    temp=a[l];
    a[l]=a[j];
    a[j]=temp;

    return j;
}

