#include<stdio.h>
#include<malloc.h>


struct node{

   int data;
   struct node* left;
   struct node* right;
   
};

struct node* cr(int data){

struct node* n;
n=(struct node*)malloc(sizeof(struct node));
n->data=data;
n->left=NULL;
n->right=NULL;

return n;

};

void Preorder(struct node* root){

if(root!=NULL){
printf("%d\t",root->data);
Preorder(root->left);
Preorder(root->right);
  }
};


void Postorder(struct node* root){

if(root!=NULL){
Postorder(root->left);
Postorder(root->right);
printf("%d\t",root->data);
  }
};



void Inorder(struct node* root){

if(root!=NULL){
Inorder(root->left);
printf("%d\t",root->data);
Inorder(root->right);

  }
};

int isbst(struct node* root)
{
static struct node *prev=NULL;
 
if (root != NULL)
{
if(!isbst(root->left))
return 0;

if(prev!=NULL && root-> data <= prev-> data){
return 0;
}
   prev = root;
return isbst(root->right);
}
else
return 1;

};

int main(){

struct node *p=cr(1);
struct node *p1=cr(2);
struct node *p2=cr(3);
struct node *p3=cr(4);
struct node *p4=cr(5);
struct node *p5=cr(6);
struct node *p6=cr(7);
struct node *p7=cr(8);

p->left=p1;
p->right=p2;
p1->left=p3;
p1->right=p4;
p2->left=p5;
p2->right=p6;
p3->left=p7;

printf("\nPreorder traversal is : ");
Preorder(p);

printf("\nPostorder traversal is : ");
Postorder(p);

printf("\nInorder traversal is : ");
Inorder(p);

printf("%d\n",isbst(p));

return 0;
}
