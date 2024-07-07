#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5;
long int arr[MAX+1], df[MAX+1];
long int n,a,b,q,t;


long int query(long int index)
{
    long int sum=0;
    for(long int i=index;i>0; i-= -i&i)
        sum+=df[i];
    return sum;
}

void update(long int index, long int val)
{
    long int diff=val-arr[index];
    for(long int i=index;i<=n;i += -i&i)
    {
        df[i]+=diff;
    }
    arr[index]=val;
}

int main()
{
    long int j,i;
    
    cin>>n>>q;
    
    for(i=1;i<=n;i++)
    {
        cin>>arr[0];
        update(i,arr[0]);
    }
    
    for(j=0;j<q;j++)
    {
        cin>>t>>a>>b;
        
        if(t==1)
        {
            update(a,b);
        }
        else
        {
            cout<<query(b)-query(a-1)<<endl;
        }
    }
}
