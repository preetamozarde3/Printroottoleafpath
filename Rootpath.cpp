// Printroottoleafpath
#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int key;
    struct Node *left, *right;
};
 
// Function to create a new node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
 
 
void printPathsUtil(Node* current, int sum,
             int pathSum, vector<int> &path)
{
    if (current == NULL)
        return;
 
    pathSum += current->key;
 
    path.push_back(current->key);
 
    // print the required path
    if (pathSum == sum )
    {
        for (int i=0; i<path.size(); i++)
            cout << path[i] << " ";
 
        cout << endl;
    }
 
    // if left child exists
    if (current->left != NULL)
        printPathsUtil(current->left, sum, pathSum, path);
 
    // if right child exists
    if (current->right != NULL)
        printPathsUtil(current->right, sum, pathSum, path);
 
    path.pop_back();
}
 
void printPaths(Node *root, int sum)
{
    vector<int> path;
    printPathsUtil(root, sum, 0, path);
}
 
int main ()
{
    /* Constructed binary tree is
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
  */
    Node *root = newNode(5);
  root->left        = newNode(4);
  root->right       = newNode(8);
  root->left->left  = newNode(11);
  root->right->left = newNode(13);
  root->right->right = newNode(4);
  root->left->left->left = newNode(7);
  root->left->left->right = newNode(2);
  root->right->right->left = newNode(5);
  root->right->right->right = newNode(1);
 
    int sum = 22;
 
    printPaths(root, sum);
 
    return 0;
}
