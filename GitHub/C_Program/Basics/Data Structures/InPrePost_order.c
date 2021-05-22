#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree * insert(struct tree * ,int);
void preorder(struct tree *);
void inorder(struct tree *);
void postorder(struct tree *);

int main()
{
    int ch,item;
    struct tree *root =NULL;
    system("clear");
    while(1)
    {
        printf("\n  1. Insert");
        printf("\n  2. Pre-Order traversal");
        printf("\n  3. InOrder traversal");
        printf("\n  4. Post-Order traversal");
        printf("\n  5. Exit");
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n Enter the element");
                    scanf("%d",&item);
                    root=insert(root,item);
                    break;
            case 2: if(root==NULL)
                    {
                        printf("\n Binary search tree empty");
                    }
                    else
                    {
                        printf("Pre-Order Traversal");
                        preorder(root);   
                    }
                    break;     
            case 3: if(root==NULL)
                    {
                        printf("\n Binary search tree empty");
                    }
                    else
                    {
                        printf("In-Order Traversal");
                        inorder(root);  
                    } 
                    break;     
            case 4: if(root==NULL)
                    {
                        printf("\n Binary search tree empty");
                    }
                    else
                    {
                        printf("Post-Order Traversal");
                        postorder(root);  
                    } 
                    break;
            case 5: free(root);
                    return 0;
            default : printf("\n Invalid Choice");
                      printf("\n\n Enter Y to Continue");
                      while(getchar()!='Y');
        }
    }
}

struct tree *insert( struct tree *root, int item)
{
    if(root==NULL)
    {
        root=malloc((sizeof(struct tree)));
        root->data=item;
        root->left= root->right =NULL;
        printf("\n %d insert",item);
        return(root);
    }
    if(root->data > item)
    {
        root->left =insert(root->left,item);
    }
    else if(root->data < item)
    {
        root->right=insert(root->right,item);
    }
    else
    {
        printf("\n %d already exists", item);
    }
    return(root);
}

void preorder(struct tree *root)
{
    if(root!=NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct tree *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void postorder(struct tree *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}