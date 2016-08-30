#include<iostream>
#include<string>
int arr[100010];
using namespace std;
int kadane(int n,int *temp)
{
    int min_ending_here=0,min_so_far=0;
    *temp=0;
    for(int i=0;i<n;i++)
    {
        min_ending_here+=arr[i];
        if(min_ending_here>0)
        {
            min_ending_here=0;
        }
        if(min_ending_here<min_so_far)
        {
            min_so_far=min_ending_here;
            *temp=i;
        }
    }
    return min_so_far;
}
int main()
{
    int n,temp;
    cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    if(arr[i]==0)
    arr[i]=-1;
  }
  int ans=kadane(n,&temp);
  cout<<temp<<endl;
  cout<<ans<<endl;
}
