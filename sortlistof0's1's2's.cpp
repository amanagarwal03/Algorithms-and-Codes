#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
void push (struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =new node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}
void printList(struct node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}
void sort012(struct node **head)
{
    struct node *zerohead,*onehead,*twohead,*prevzero,*prevone,*prevtwo,*curr;
    curr=prevone=prevtwo=prevzero=NULL;
    curr=*head;
    while(curr)
    {
        if(curr->data==0)
        {
            if(prevzero==NULL)
            {
                prevzero=zerohead=curr;
            }
            else
            {
                prevzero->next=curr;
                prevzero=curr;
            }
        }
        if(curr->data==1)
        {
            if(prevone==NULL)
            {
                prevone=onehead=curr;
            }
            else
            {
                prevone->next=curr;
                prevone=curr;
            }
        }
        if(curr->data==2)
        {
            if(prevtwo==NULL)
            {
                prevtwo=twohead=curr;
            }
            else
            {
                prevtwo->next=curr;
                prevtwo=curr;
            }
        }
        curr=curr->next;
    }
    prevzero->next=onehead;
    prevone->next=twohead;
    prevtwo->next=NULL;
    *head=zerohead;
}
int main()
{
	struct node *head = NULL;
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 2);
	push(&head, 1);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);
	push(&head, 2);

	cout<<("Linked List Before Sorting\n");
	printList(head);

	sort012(&head);

	cout<<("Linked List After Sorting\n");
	printList(head);

	return 0;
}
