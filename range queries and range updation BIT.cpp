#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int arr[100010],BIT1[100010],BIT2[100010],n;
void update(int * ft,int index,int val)
{
	while(index<=n)
	{
		ft[index]+=val;
		index=index+(index&(-index));
	}
}
int query(int *ft,int index)
{
	int ans=0;
	while(index>=1)
	{
		int count=ft[index];
		int value=arr[index];
		for(int i=0;i<count;i++)
		{
			value=sqrt(value);
		}
		ans+=value;
	}
	return ans;
}
int query(int index)
{
	return (query(BIT1,index)*index-query(BIT2,index));
}
void range_update(int a,int b)
{
	update(BIT1,a,1);
	update(BIT1,b+1,-1);
	update(BIT1,a,a-1);
	update(BIT2,b+1,-b);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(b>c)
		swap(b,c);
		if(a)
		{
			int res=query(c)-query(a-1);
			cout<<res<<endl;
		}
		else
		{
			range_update(b,c);
		}
	}
}
