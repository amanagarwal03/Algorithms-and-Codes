#include<iostream>
#include<string>
using namespace std;
int a=0,b=0;
int lcs(string s1,string s2)
{
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s1,s2,s[5000];
		int l=0,num=0,len[5000];
		cin>>s1;
		l=s1.length();
		for(int i=0;i<l;i++)
		{
			for(int j=1;j<=l-i;j++)
			{
				s[num]=s1.substr(i,j);
				len[num]=j;
				num++;
			}
		}
		int res[num+10];
		for(int i=1;i<n;i++)
		{
			cin>>s2;
			for(int j=0;j<num;j++)
			{
				size_t pos;
				pos=s2.find(s[j]);
				if(pos!=std::string::npos)
				{
					res[j]+=1;
					//cout<<"yes"<<endl;
				}
				else
				{
					res[j]+=1;
					//cout<<"No"<<endl;
				}
			}
		}
		int mx=0;
		for(int i=0;i<num;i++)
		{
			if(res[i]==(n-1))
			{
				if(len[i]>mx)
				mx=len[i];
			}
		}
		cout<<mx<<endl;
	}
}
