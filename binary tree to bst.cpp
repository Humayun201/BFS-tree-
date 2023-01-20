#include <iostream>

using namespace std;

class BST {
    // Definition of a node in the BST
    struct Node {
        int val;
        Node *left, *right;
        Node(int v) : val(v), left(NULL), right(NULL) {}
    };

    // The root of the BST
    Node *root;

public:
    // Constructor to create an empty BST
    BST() : root(NULL) {}

    // Function to find the second largest element in the BST
    int secondLargest() {
        // Base case: if the tree is empty, return -1 (invalid value)
        if (!root) return -1;

        Node *node = root;
        Node *prev = NULL;

        // Iterate through the tree, keeping track of the previous node
        while (node->right) {
            prev = node;
            node = node->right;
        }

        // If the node has a left child, the second largest element is the largest element in the left subtree
        if (node->left) {
            return findLargest(node->left);
        }
        // Otherwise, the second largest element is the previous node
        else {
            return prev->val;
        }
    }

    // Helper function to find the largest element in a subtree
    int findLargest(Node *node) {
        // Base case: if the node is NULL, return -1 (invalid value)
        if (!node) return -1;

        // Recursive case: the largest element is in the right subtree
        if (node->right) {
            return findLargest(node->right);
        }
        // Base case: the node has no right child, so it is the largest element
        else {
            return node->val;
        }
    }

    // Other functions to insert, delete, and search for elements in the BST
};

int main() {
    BST bst;

    // Insert some elements into the BST

    cout << "The second largest element in the BST is: " << bst.secondLargest() << endl;
    return 0;
}