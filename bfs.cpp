 #include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    bool visited;
    Node** children;
    int childrenSize;
    Node(int _val) : val(_val), visited(false), children(nullptr), childrenSize(0) {}
};

void BFS(Node* root) {
    if (root == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    root->visited = true;
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
       cout << curr->val << " ";
        for (int i = 0; i < curr->childrenSize; i++) {
            Node* child = curr->children[i];
            if (!child->visited) {
                q.push(child);
                child->visited = true;
            }
        }
    }
}

int main() {
    Node* root = new Node(1);
    int value;
    int child_count;
    cout << "Enter the value of the root node: ";
    cin >> value;
    root->val = value;

    cout << "Enter the number of children for the root node: ";
    cin >> child_count;
    root->children = new Node*[child_count];
    root->childrenSize = child_count;
    for (int i = 0; i < child_count; i++) {
        cout << "Enter the value for child " << i+1 << ": ";
        cin >> value;
        root->children[i] = new Node(value);
    }

    BFS(root);

    return 0;
}