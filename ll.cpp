#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insert(node **start,int key)
{
    node *temp=new node();
    temp->data=key;
    temp->next=NULL;
    if(*start==NULL)
    {
        *start=temp;
    }
    else
    {
        node *p;
        p=*start;
        while(p->next!=NULL)
        p=p->next;
        p->next=temp;
    }
}
int main()
{
    node *start;
    start=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int key;
        cin>>key;
        insert(&start,key);
    }
    node *tempi;
    tempi=start;
    while(tempi!=NULL)
    {
        cout<<tempi->data<<endl;
        tempi=tempi->next;
    }
}
