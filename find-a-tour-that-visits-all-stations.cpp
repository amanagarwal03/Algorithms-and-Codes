#include<iostream>
using namespace std;
struct petrolpump
{
    int petrol,dist;
};
int printTour(struct petrolpump arr[],int n)
{
    int start=0,ends=1;
    int curr_petrol=arr[start].petrol-arr[start].dist;
    while(start!=ends||curr_petrol<0)
    {
        while(start!=ends&&curr_petrol<0)
        {
            curr_petrol-=arr[start].petrol-arr[start].dist;
            start=(start+1)%n;
            if(start==0)
            return -1;
        }
        curr_petrol+=arr[ends].petrol-arr[ends].dist;
        ends=(ends+1)%n;
    }
    return start;
}
int main()
{
    struct petrolpump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);
    cout<<start<<endl;
}
