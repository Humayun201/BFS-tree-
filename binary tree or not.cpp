#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *left, *right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

bool isBst(Node* root, Node* min = NULL, Node* max = NULL) {
	if (root == NULL) {
		return true;
	}
	if (min != NULL && root->data <= min->data) {
		return false;
	}
	if (max != NULL && root->data > max->data) {
		return false;
	}
	bool leftValid = isBst(root->left, min, root);
	bool rightValid = isBst(root->right, root, max);
	return leftValid && rightValid;
}

int main() {
	Node* root1 = new Node(1);
	root1->left = new Node(2);
	root1->right = new Node(3);
	if (isBst(root1, NULL, NULL)) {
		cout << " valid Bst" << endl;
	}
	else {
		cout << " invalid bst " << endl;
	}

	return 0;
}