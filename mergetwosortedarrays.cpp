#include<iostream>
using namespace std;
void mergetwo(int arr1[],int arr2[],int n1,int n2)
{
    for(int i=n2-1;i>=0;i--)
    {
        int item=arr1[n1-1],j=0;
        for(j=n1-1;j>=0&&arr1[j]>arr2[i];j--)
        {
            arr1[j+1]=arr1[j];
        }
        if(j!=n1-1)
        {
            arr1[j+1]=arr2[i];
            arr2[i]=item;
        }
    }
}
int main()
{
    int n1,n2;
    cin>>n1;;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++)cin>>arr1[i];
    cin>>n2;
    for(int i=0;i<n2;i++)cin>>arr2[i];
    mergetwo(arr1,arr2,n1,n2);
    cout<<"After merging"<<endl;
    for(int i=0;i<n1;i++)cout<<arr1[i]<<" ";
    cout<<endl;
    for(int j=0;j<n2;j++)
    cout<<arr2[j]<<" ";
    cout<<endl;
}
