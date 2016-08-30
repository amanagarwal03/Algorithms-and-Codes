#include<iostream>
#define ll long long
using namespace std;
ll maxSubArraySum(ll a[], ll size,ll m)
{
   ll max_so_far = a[0]%m;
   ll curr_max = a[0]%m;
 
   for (ll i = 1; i < size; i++)
   {
        curr_max = max(a[i]%m, (curr_max+a[i])%m);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
   	ll n;
   	cin>>n;
   	ll m;
   	cin>>m;
   	ll arr[100010];
   	for(ll i=0;i<n;i++)
   	cin>>arr[i];
   	ll ans=maxSubArraySum(arr,n,m);
   	cout<<ans<<endl;
   }
}
