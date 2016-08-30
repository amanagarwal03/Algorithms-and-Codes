#include<iostream>
#include<map>
#include<queue>
using namespace std;
struct node
{
    struct node *left;
    struct node *right;
    int data;
    int hd;
};
node* newNode(int data)
{
    node *temp=new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    return temp;
}
void topview(node* root)
{
    if(root==NULL)
    return;
    queue<node*>q;
    map<int,int>m;
    root->hd=0;
    int hd=0;
    q.push(root);
    while(q.size())
    {
        node *temp=q.front();
        q.pop();
        hd=temp->hd;
        if(m.count(hd)==0)
        m[hd]=temp->data;
        if(temp->left)
        {
            temp->left->hd=hd+1;
            q.push(temp->left);
        }
        if(temp->right)
        {
            temp->right->hd=hd-1;
            q.push(temp->right);
        }
    }
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<" ";
    }
}
int main()
{
    node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    topview(root);
}

