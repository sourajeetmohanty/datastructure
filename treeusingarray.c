#include<stdio.h>
#include<stdlib.h>
int arr[100];
int p;
void create(int x)
{   int val;
    printf("Enter data (-1 for no data): ");
    scanf("%d",&val);
    arr[x]=val;

    if(val==-1)
    {   p=x;
        return;
    }
    printf("Enter left child %d:\n",arr[x]);
    create(2*x+1);
    printf("Enter right child %d:\n",arr[x]);
    create(2*x+2);

}
void preorder(int k)
{
    if(arr[k]!=-1)
    {
        printf("\n%d",arr[k]);
        preorder(2*k+1);
        preorder(2*k+2);
    }
}
void inorder(int k)
{   if(k>p)
    return;
    if(arr[k]!=-1)
    {
        inorder(2*k+1);
        printf("\n%d",arr[k]);
        inorder(2*k+2);
    }
}
void postorder(int k)
{   if(k>p)
    return;
    if(arr[k]!=-1)
    {
        postorder(2*k+1);
        postorder(2*k+2);
        printf("\n%d",arr[k]);
    }
}
void main()
{  int i;
    create(0);
    //for(i=0;i<p+1;i++)
        //printf("\n%d",arr[i]);
    printf("\n The preorder traversal of tree is:\n");
    preorder(0);
    printf("\n The inorder traversal of tree is:\n");
    inorder(0);
    printf("\n The postorder traversal of tree is:\n");
    postorder(0);
}
