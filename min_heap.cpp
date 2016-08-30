#include<iostream>
using namespace std;
struct Minheap
{
	int size;
	int capacity;
	int * arr;
};
struct Minheap* create(int n)
{
	struct Minheap* minheap=new Minheap;
	minheap->size=0;
	minheap->capacity=n;
	minheap->arr=new int[n];
	return minheap;
}
void swap(int *a,int *b)
{
	int temp=*a;
	*b=*a;
	*a=temp;
}
void minheapify(struct Minheap* minheap,int idx)
{
	int smallest=idx;
	int left=(2*idx)+1;
	int right=(2*idx)+2;
	if(left<minheap->size&&minheap->arr[left]<minheap->arr[smallest])
	smallest=left;
	if(right<minheap->size&&minheap->arr[right]<minheap->arr[smallest])
	smallest=right;
	if(smallest!=idx)
	{
		swap(&minheap->arr[smallest],&minheap->arr[idx]);
		minheapify(minheap,smallest);
	}
}
void buildminheap(struct Minheap* minheap)
{
	int n=minheap->size-1;
	int i;
	for(i=(n-1)/2;i>=0;i--)
	{
		minheapify(minheap,i);
	}
}
struct Minheap* createandbuild(int a[],int n)
{
	struct Minheap* minheap=create(n);
	for(int i=0;i<n;i++)
	minheap->arr[i]=a[i];
	minheap->size=n;
	buildminheap(minheap);
	return minheap;
}
int extract_min(struct Minheap* minheap)	
{
	int temp=minheap->arr[0];
	minheap->arr[0]=minheap->arr[minheap->size-1];
	--minheap->size;
	minheapify(minheap,0);
	return temp;
}
void insert(struct Minheap* minheap,int val)
{
	++minheap->size;
	int i=minheap->size-1;
	while(i&(val<minheap->arr[(i-1)/2]))
	{
		minheap->arr[i]=minheap->arr[(i-1)/2];
		i=(i-1)/2;
	}
	minheap->arr[i]=val;
}
bool sizeone(struct Minheap* minheap)
{
	if(minheap->size==1)
	return true;
	else
	return false;
}
int mincost(int a[],int n)
{
	int cost=0;
	struct Minheap * minheap=createandbuild(a,n);
	while(!sizeone(minheap))
	{
		int f=extract_min(minheap);
		int l=extract_min(minheap);
		cost+=(f+l);
		insert(minheap,(f+l));
	}
	return cost;
}
int main()
{
	int n;
	cin>>n;
	int a[100010];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int ans=mincost(a,n);
	cout<<ans<<endl;
}
