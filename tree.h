#include <queue>
#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val)
    {
        data = val;
        right = left = nullptr;
    }
};

struct BSTNode
{
    int data;
    BSTNode* right;
    BSTNode* left;
    BSTNode(int val)
    {
        data = val;
        right = left = nullptr;
    }
};

// Function to insert a new node in the binary tree
void insert(TreeNode* root, int key) {
   
    // Create a queue for level order traversal
    queue<TreeNode*> q;
    q.push(root);

    // Do level order traversal until we find an empty place
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        // If left child is empty, insert the new node here
        if (temp->left == nullptr) {
            temp->left = new TreeNode(key);
            break;
        } else {
            q.push(temp->left);
        }
        // If right child is empty, insert the new node here
        if (temp->right == nullptr) {
            temp->right = new TreeNode(key);
            break;
        } else {
            q.push(temp->right);
        }
    }
}

// Function to insert new node into a binary search tree
void insert(BSTNode* root, int key)
{
    BSTNode* newNode = new BSTNode(key);

    queue<BSTNode*> q;
    q.push(root);

    while (true)
    {
        BSTNode* curr = q.front();
        q.pop();

        if (key < curr->data)
        {
            if (!curr->left)
            {
                curr->left = newNode;
                return;
            }
            else
                q.push(curr->left);
        }
        else if (key > curr->data)
            if (!curr->right)
            {
                curr->right = newNode;
                return;
            }
            else
                q.push(curr->right);
        else
            return;
    }
}

// Removes Node containing key from the Tree. Return true upon
// success, false if key does not exist in the tree.
bool remove(TreeNode* root, int target)
{

}

// Removes Node containing key from the BST. Return true upon
// success, false if key does not exist in the tree.
bool remove(BSTNode* root, int target)
{

}
