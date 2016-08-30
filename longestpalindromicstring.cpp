#include<iostream>
#include<string.h>
#include<string>
using namespace std;
void lps(string s)
{
    int l=s.length();
    bool arr[l][l];
    int maxlength=1,start=0;
    memset(arr,0,sizeof(arr));
    for(int i=0;i<l;i++)
    arr[i][i]=true;
    for(int i=0;i<l-1;i++)
    {
        if(s[i]==s[i+1])
        {
            start=i;
            maxlength=2;
            arr[i][i+1]=true;
        }
    }
    for(int k=3;k<=l;k++)
    {
        for(int i=0;i<l-k+1;i++)
        {
            int j=i+k-1;
            if(arr[i+1][j-1]&&s[i]==s[j])
            {
                arr[i][j]=true;
                if(k>maxlength)
                {
                    maxlength=k;
                    start=i;
                }
            }
        }

    }
    cout<<maxlength<<endl;
    for(int i=start;i<(start+maxlength);i++)
    cout<<s[i];
    cout<<endl;
}
int main()
{
    string s;
    cin>>s;
    lps(s);
}
