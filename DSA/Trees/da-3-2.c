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
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf(" %d ",root->val);
        inorder(root->right);
    }
}
int height_of_binary_tree(struct node *node)
{
    if(node == NULL)
        return 0;
    else
    {
        int left_side;
        int right_side;
        left_side = height_of_binary_tree(node -> left);
        right_side = height_of_binary_tree(node -> right);
        if(left_side > right_side)
            return left_side+1;
        else
            return right_side+1;
    }
}
int main()
{
    struct node *root = NULL;
    // sample-1
    // root = insert(root,3);
    // insert(root,5);
    // insert(root,4);
    // insert(root,2);
    // insert(root,6);
    // insert(root,1);
    // insert(root,7);

    // sample-2
    root = insert(root,4);
    insert(root,6);
    insert(root,2);
    insert(root,3);
    insert(root,7);
    insert(root,5);
    insert(root,1);
    
    printf("\n");
    printf(" BST: ");
    inorder(root);
    printf("\n Height of the tree: %d",height_of_binary_tree(root)-1);
    return 0;
}