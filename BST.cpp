#include <iostream>
using namespace std;
struct node{
  int data;
  struct node *lchild;
  struct node *rchild;
  struct node *parent;

};
struct stack 
{
  struct node* value[100];
  int top=-1;
};
void push(struct stack *s,struct node *t)
{
  s->top++;
  s->value[s->top]=t;
}
struct node* pop(struct stack *s)
{
  struct node *t = s->value[s->top];
  s->top--;
  return t;
}

/*void preorder(struct node *temp)
{
  if (temp!=NULL)
  {
    cout<<temp->data<<" ";
    preorder(temp->lchild);
    preorder(temp->rchild);
  }
}*/

/*void inorder(struct node* temp)
{
  if (temp!=NULL)
  {
    inorder(temp->lchild);
    cout<<temp->data<<" ";
    inorder(temp->rchild);
  }
}*/

/*void postorder(struct node* temp)
{
  if(temp!=nullptr)
  {
    postorder(temp->lchild);
    postorder(temp->rchild);
    cout<<temp->data<<" ";
    
  }
}*/


// Inorder using iterative
void inorder(struct node* t)
{
  struct stack st;
  while(t!=NULL || st.top!=-1)
    {
      if(t!=NULL)
      {
        push(&st,t);
        t=t->lchild;
      }
      else
      {
        t=pop(&st);
        printf(" %d ",t->data);
        t=t->rchild;
      }
        
    }
  
}

void preorder(struct node* t)
{
  struct stack st;
  while(t!=nullptr || st.top!=-1)
    {
      if(t!=nullptr){
        printf(" %d ",t->data);
        push(&st,t);
        t=t->lchild;
      }
      else
      {
        t=pop(&st);
        t=t->rchild;
      }
      
    }
}

struct node* makechild(int x)
{
  struct node *temp = new node;
  temp->data=x;
  temp->lchild=nullptr;
  temp->rchild=nullptr;
  temp->parent=nullptr;
  return temp;
}

struct node* insert(struct node* root, int data)
{
  struct node*z = makechild(data);
  struct node *x,*y;
  x=root;
  y=nullptr;
  while(x!=nullptr)
    {
      y=x;
      if (z->data < x->data)
        x=x->lchild;
      else
        x=x->rchild;
    }
  z->parent=y;
  if(y==nullptr)
  {
    root=z;
    return root;
  }
  if (z->data < y->data)
    y->lchild=z;
  else
    y->rchild=z;
  return y;  
}
int main()
{
  struct node *root=NULL;
 
  root = insert(root,4);
  insert(root,2);
  insert(root,6);
  insert(root,1);
  insert(root,3);
  insert(root,5);
  preorder(root);
  cout<<endl;
  inorder(root);
  //cout<<endl;
  //postorder(root);
  
  return 0;
}