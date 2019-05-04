#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left, *right;
};

struct node* newNode(int data);

int height(struct node* node);

int diameter(struct node * tree)
{
    if (tree == NULL)return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);

    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

/* UTILITY FUNCTIONS TO TEST diameter() FUNCTION */

/*  The function Compute the "height" of a tree. Height is the
    number f nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
   if(node == NULL)
       return 0;
   return 1 + max(height(node->left), height(node->right));
}
node* newNode(int data)
{
  node* temp = new node();
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return(temp);
}
int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  printf("Diameter of the given binary tree is %d\n", diameter(root));
  getchar();
  return 0;
}
