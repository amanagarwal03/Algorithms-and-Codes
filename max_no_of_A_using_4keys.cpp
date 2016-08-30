#include<iostream>
#include<string.h>
using namespace std;
//Recursive method
int findmaxrec(int n)
{
    if(n<=6)
    return n;
    int best=0;
    for(int b=n-3;b>=1;b--)
    {
        int curr=(n-b-1)*findmaxrec(b);
        if(curr>best)
        best=curr;
    }
    return best;
}
//Dynamic programming method
int findmaxdp(int N)
{
    if(N<=6)
    return N;
    int arr[N];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=6;i++)
    arr[i-1]=i;
    for(int n=7;n<=N;n++)
    {
        for(int b=n-3;b>=1;b--)
        {
            int curr=(n-b-1)*arr[b-1];
            if(curr>arr[N-1])
            arr[N-1]=curr;
        }
    }
    return arr[N-1];
}

int main()
{
    int n;
    cin>>n;
    int ans=findmaxrec(n);
    cout<<ans<<endl;
    cout<<findmaxdp(n);
}

