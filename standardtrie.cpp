#include<iostream>
#include<string>
#define ALPHABET_MAX 26
using namespace std;
struct trie
{
    struct trie *children[ALPHABET_MAX];
    bool isleaf;
};
struct trie *getnode()
{
    struct trie *temp=new trie();
    temp->isleaf=false;
    for(int i=0;i<ALPHABET_MAX;i++)
    temp->children[i]=NULL;
    return temp;
}
void insert(struct trie *root,string s)
{
    struct trie *temp=root;
    int length=s.length();
    for(int level=0;level<length;level++)
    {
        int index=s[level]-97;
        //cout<<index<<endl;
        if(!temp->children[index])
        {
            temp->children[index]=getnode();
        }
        temp=temp->children[index];
    }
    temp->isleaf=true;
}
bool search(struct trie *root,string s)
{
    int length=s.length();
    struct trie *temp=root;
    for(int level=0;level<length;level++)
    {
        int index=s[level]-97;
        if(!temp->children[index])
        {
            return false;
        }
        temp=temp->children[index];
    }
    return (temp!=NULL&&temp->isleaf);
}
int main()
{
    string s[10]={"the", "a", "there", "answer", "any","by", "bye", "their"};
    struct trie *root=getnode();
    for(int i=0;i<8;i++)
    {
        insert(root,s[i]);
    }
    if(search(root,"the"))
    cout<<"Yes the"<<endl;
    if(search(root,"these"))
    cout<<"Yes these"<<endl;
    if(search(root,"their"))
    cout<<"Yes their"<<endl;
    if(search(root,"thaw"))
    cout<<"Yes thaw"<<endl;
}
