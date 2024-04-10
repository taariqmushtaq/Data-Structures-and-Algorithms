#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    TreeNode *root;

    TreeNode *insertNode(TreeNode *node, int value)
    {
        if (node == nullptr)
        {
            return new TreeNode(value);
        }

        if (value < node->data)
        {
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertNode(node->right, value);
        }
        return node;
    }

    bool searchNode(TreeNode *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }

        if (value == node->data)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchNode(node->left, value);
        }
        else
        {
            return searchNode(node->right, value);
        }
    }

    TreeNode *deleteNode(TreeNode *node, int value)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        else
        {
            if (node->left == nullptr)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            TreeNode *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    TreeNode *findMin(TreeNode *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void inorderTraversal(TreeNode *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertNode(root, value);
        displayInorder();
    }

    bool search(int value)
    {
        bool result = searchNode(root, value);
        displayInorder();
        return result;
    }

    void remove(int value)
    {
        root = deleteNode(root, value);
        displayInorder();
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
    BinarySearchTree bst;

    int option;
    int value;

    do
    {
        cout << "\n1. Insert a node\n2. Search a node\n3. Delete a node\n4. Exit\nEnter option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bst.insert(value);
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (bst.search(value))
            {
                cout << "Value " << value << " found in the BST." << endl;
            }
            else
            {
                cout << "Value " << value << " not found in the BST." << endl;
            }
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            bst.remove(value);
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (option != 4);

    return 1;
}
