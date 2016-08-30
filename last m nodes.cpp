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
    //code for substituting last m nodes at the beginning of the list
    int m;
    cin>>m;
    node *p1,*p2;
    p1=start;
    for(int i=1;i<=m;i++)
    {
        p1=p1->next;
    }
    p2=p1;
    p1=start;
    while(p2->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
    /*p1 is pointing to the element just before the element which will be our new start,p2 is pointing to last element
    in original list
    example 1 2 3 4 5 6 7 so if we want to subtitute last 3 nodes at beginning then p1 is pointing to 4 and p2 to 7.
    p1 is pointing to 4 because we need to make 4 waale ka next =NULL and 5 is our new start point */
    p2->next=start;
    start=p1->next;
    p1->next=NULL;
    tempi=start;
    while(tempi!=NULL)
    {
        cout<<tempi->data<<endl;
        tempi=tempi->next;
    }

}
