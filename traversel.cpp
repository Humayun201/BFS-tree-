#include <iostream>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode *left, *right;
  TreeNode(int data) {
    this->data = data;
    left = right = NULL;
  }
};

class Tree {
public:
  TreeNode *root;

 public:
  // Preorder traversal
  void preorderTraversal(TreeNode* node) {
    if (node == NULL)
      return;

    cout << node->data << "->";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
  }

  // Postorder traversal
  void postorderTraversal(TreeNode* node) {
    if (node == NULL)
      return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << "->";
  }

  // Inorder traversal
  void inorderTraversal(TreeNode* node) {
    if (node == NULL)
      return;

    inorderTraversal(node->left);
    cout << node->data << "->";
    inorderTraversal(node->right);
  }
};

int main() {
  Tree tree;
  tree.root = new TreeNode(1);
  tree.root->left = new TreeNode(12);
  tree.root->right = new TreeNode(9);
  tree.root->left->left = new TreeNode(5);
  tree.root->left->right = new TreeNode(6);

  cout << "Inorder traversal ";
  tree.inorderTraversal(tree.root);

  cout << "\nPreorder traversal ";
  tree.preorderTraversal(tree.root);

  cout << "\nPostorder traversal ";
  tree.postorderTraversal(tree.root);
}