#include<stdio.h>
#include<iostream>
using namespace std;
double babylonian(int n)
{
    double x=n;
    double y=1;
    double e=0.00001;
    while(x-y>e)
    {
        x=(x+y)/2;
        y=n/x;
    }
    return x;
}
int main()
{
    int n;
    cin>>n;
    double ans=babylonian(n);
    printf("%.4f",ans);
}
