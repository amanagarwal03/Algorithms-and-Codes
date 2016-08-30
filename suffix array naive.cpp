#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int l=s.length();
	map<string,int>m;
	vector<string>v;
	for(int i=0;i<l;i++)
	{
		m[s.substr(i,l-i)]=i;
		v.push_back(s.substr(i,l-i));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		cout<<m[v[i]]<<endl;
	}
}
