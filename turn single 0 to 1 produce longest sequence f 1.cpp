#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l=s.length();
	int pre=-1,pre_pre=-1,max=0,max_index;
	for(int curr=0;curr<l;curr++)
	{
		//cout<<"Yes"<<endl;
		if(s[curr]=='0')
		{
			cout<<curr<<" "<<pre<<" "<<pre_pre<<curr-pre_pre<<endl;
			if(curr-pre_pre>max)
			{
				max=curr-pre_pre;
				max_index=pre;
			}
			pre_pre=pre;
			pre=curr;
		}
	}
	if(l-pre_pre>max)
	{
		max=l-pre_pre;
		max_index=pre;
	}
	cout<<max<<" "<<max_index<<endl;
}
