//Print matrix in spiral
#include<iostream>
using namespace std;
int main()
{
	int arr[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		arr[i][j]=0;
	}
	int row,col;
	cin>>row>>col;
	cout<<row<<col<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cin>>arr[i][j];
		}
	}
	int ar=0,ac=0,i=0;
	while(ar<row&&ac<col)
	{
		//first row
		for(i=ac;i<col;i++)
		{
			cout<<arr[ar][i]<<" ";
		}
		ar++;
		//last column
		for(i=ar;i<row;i++)
		{
			cout<<arr[i][col-1]<<" ";
		}
		col--;
		//last row
		if(ar<row)
		{
		for(i=col-1;i>=ac;i--)
		{
			cout<<arr[row-1][i]<<" ";
		}
		row--;
	}
		//firstcolumn
		if(ac<col)
		{
		
		for(i=row-1;i>=ar;i--)
		cout<<arr[i][ac]<<" ";
		ac++;
	}
	}
	
}
