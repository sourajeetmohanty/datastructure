#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct node *left;
 int data;
 struct node *right;
};

struct node* create()
{

    struct node *p;
    int x;
    printf("Enter data (-1 for no data): ");
    scanf("%d",&x);

    if(x==-1)
    {
        return NULL;
    }

    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;

    printf("Enter left child %d:\n",x);
    p->left=create();

    printf("Enter right child of %d\n",x);
    p->right=create();

    return p;
};
void preorder(struct node *t)
{
    if(t!=NULL)
    {
        printf("\n%d",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(struct node *t)
{
    if(t!=NULL)
    {   inorder(t->left);
        printf("\n%d",t->data);
        inorder(t->right);
    }
}
void postorder(struct node *t)
{

    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("\n%d",t->data);
    }
}

void main()
{
    struct node *root;
    root=create();
    printf("\n The preorder traversal of tree is:\n");
    preorder(root);
    printf("\n The inorder traversal of tree is:\n");
    inorder(root);
    printf("\n The postorder traversal of tree is:\n");
    postorder(root);
}
