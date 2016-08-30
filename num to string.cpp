#include<iostream>
#include<stdlib.h>
#include<string>
#include<cstdio>
#include<sstream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	stringstream convert;
	convert<<n;
	s=convert.str();
	cout<<s.length()<<endl;
	cout<<s<<endl;
}
