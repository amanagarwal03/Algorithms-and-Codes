#include<iostream>
#define ll long long
using namespace std;
int main()
{
    ll g,c;
    cin>>g>>c;
    if(c%g==0)
    {
        cout<<"0";
    }
    else
    {
        ll req=0;
        req=(c/g)+1;
        req=(req)*g;
        req=req-c;
        cout<<req<<endl;
    }
}
