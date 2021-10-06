#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* takeInput(){
    int choice;
    printf("Enter the no of nodes:");
    scanf("%d",&choice);
    int value;
    struct node* head=NULL;
    struct node* temp=NULL;
    struct node* newnode=NULL;

    if(head==NULL){
        head=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node:\n");
        scanf("%d",&value);
        head->data=value;
        head->next=NULL;
        temp=head;
    }


    while((choice-1)>0)
    {
         newnode=(struct node*)malloc(sizeof(struct node));
         scanf("%d",&value);
         newnode->data=value;
         newnode->next=NULL;
         temp->next=newnode;
         temp=newnode;
         choice--;
    }
    temp=head;
    return temp;
}
struct node* insertanywhere(struct node* r,int pos,int value)
{
    int count=0;
    struct node* t=r;
    struct node* a;
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=value;
    if(pos==0)
    {
        nn->next=t;
        return nn;
    }
    while(count<pos-1 && t!=NULL)
    {
        t=t->next;
        count++;
    }
    if(t!=NULL)
    {
        a=t->next;
        t->next=nn;
        nn->next=a;
    }
    return r;
}
struct node* del(struct node* r,int pos)
{
   int count=0;
   struct node* t=r;
   struct node* a;
   struct node* b;
   if(pos==0)
   {
       a=t;
       t=t->next;
       return t;
   }
   while(count<pos-1 && t!=NULL)
   {
       t=t->next;
       count++;
   }
   if(t!=NULL)
   {
       a=t->next;
       b=a->next;
       t->next=b;
   }
   return r;
}

void printLinkedList(struct node* root){
    struct node* temp=root;
     while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
int main()
{

    struct node* root=takeInput();
    printLinkedList(root);
    printf("\nEnter the value need to be inserted and the position where it will be inserted:\n");
      int val,i;
    scanf("%d %d",&val,&i);
    struct node* root2=insertanywhere(root,i,val);
    printf("\n");
    printLinkedList(root2);
    printf("\nEnter the position where the node will be deleted:\n");
     int k;
     scanf("%d",&k);
     struct node* root3=del(root2,k);
     printLinkedList(root3);

}
