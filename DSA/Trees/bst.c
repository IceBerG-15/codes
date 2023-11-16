// binary search tree.
#include<stdio.h>
#include<stdlib.h>
// node definition
struct node{
    int val;
    struct node *left,*right;
};
// creating new node
struct node* newNode(int x)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
// insertion of value in the tree
struct node* insert(struct node* root,int x)
{
    if(root == NULL) 
        return newNode(x);
    if(x>root->val)
        root->right = insert(root->right,x); // connecting root's right with the new node
    else if(x<root->val)
        root->left = insert(root->left,x); // connecting root's left with the new node
    return root;
}
//searching the tree
void search(struct node* root,int x)
{
    if(root->val==x)
        printf("\n%d found.",x);
    else{
        if(root != NULL)
        {
            if(x>root->val && root->right!=NULL)
                search(root->right,x);
            else if(x<root->val && root->left!=NULL)
                search(root->left,x);
            else
                printf("\n%d not found.",x);
        }
    }
}
// inorder of the bst
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ",root->val);
        inorder(root->right);
    }
}
// preorder of the bst
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
// postorder of the bst
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ",root->val);
    }    
}
// main function
int main()
{
    struct node *root = NULL;
    root = insert(root,4);
    insert(root,2);
    insert(root,3);
    insert(root,1);
    insert(root,5);
    printf("\n");
    search(root,3);
    search(root,5);
    printf("\n");
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}