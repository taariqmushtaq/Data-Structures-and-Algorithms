#include <iostream>
using namespace std;

class AVLNode
{
public:
    int data;
    int height;
    AVLNode *left;
    AVLNode *right;

    AVLNode(int value) : data(value), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree
{
private:
    AVLNode *root;

    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int height(AVLNode *node)
    {
        return (node == nullptr) ? 0 : node->height;
    }

    int getBalance(AVLNode *node)
    {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVLNode *insertNode(AVLNode *node, int value)
    {
        if (node == nullptr)
        {
            return new AVLNode(value);
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }
        else
        {
            // Duplicate values are not allowed in AVL trees
            return node;
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorderTraversal(AVLNode *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertNode(root, value);
    }

    void displayInorder()
    {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    AVLTree avl;

    // Insert values into the AVL tree
    avl.insert(9);
    avl.insert(5);
    avl.insert(10);
    avl.insert(0);
    avl.insert(6);
    avl.insert(11);
    avl.insert(-1);
    avl.insert(1);
    avl.insert(2);

    // Display the AVL tree
    avl.displayInorder();

    return 0;
}
