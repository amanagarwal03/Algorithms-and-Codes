#include<iostream>
using namespace std;
struct node
{
    int key;
    struct node* left;
    struct node* right;
    int height;
};
struct node* newnode(int key)
{
     struct node* n1=new node;
     n1->key=key;
     n1->left=NULL;
     n1->right=NULL;
     n1->height=1;
     return n1;
}
int height(struct node* N)
{
    if(N==NULL)
    return 0;
    else
    return N->height;
}
int heightbalanced(struct node* N)
{
    if(N==NULL)
    return 0;
    else
    return (height(N->left)-height(N->right));
}
struct node* rightrotate(struct node* y)
{
    struct node* x=y->left;
    struct node* T2=x->right;
    x->right=y;
    y->left=T2;
    x->height=max((x->left->height),(x->right->height))+1;
    y->height=max((y->left->height),(y->right->height))+1;
    return x;
}
struct node* leftrotate(struct node* x)
{
    struct node* y=x->right;
    struct node* T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max((x->left->height),(x->right->height))+1;
    y->height=max((y->left->height),(y->right->height))+1;
    return y;
}
struct node* insertion(struct node* n,int key)
{
    if(n==NULL)
    return(newnode(key));
    if(n->key<key)
    n->right=insertion(n->right,key);
    else
    n->left=insertion (n->left,key);
    n->height=max(n->left->height,n->right->height)+1;
    int balance=heightbalanced(n);
    //left-left case
    if(balance>1&&(n->left->key)>key)
    return(rightrotate(n));
    if(balance<-1&&n->right->key<key)//right-right case
    return(leftrotate(n));
    if(balance>1&&n->left->key<key)
    {
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }
    if(balance<-1&&n->right->key>key)//right-left
    {
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }
    return n;
}
void preorder(struct node* n)
{
if(n!=NULL)
{    cout<<n->key;
    preorder(n->left);
    preorder(n->right);
    }
}
int main()
{
    struct node* root=NULL;
  root = insertion(root, 10);
  root = insertion(root, 20);
  root = insertion(root, 30);
  root = insertion(root, 40);
  root = insertion(root, 50);
  root = insertion(root, 25);
  preorder(root);
}
