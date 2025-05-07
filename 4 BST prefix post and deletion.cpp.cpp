#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* constructExpressionTree(const string& expr) {
    stack<Node*> stk;
    
    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];
        
        if (isalpha(c) || isdigit(c)) {
            stk.push(new Node(c));
        } else {
            Node* node = new Node(c);
            node->left = stk.top(); stk.pop();
            node->right = stk.top(); stk.pop();
            stk.push(node);
        }
    }
    
    return stk.top();
}

void postOrderTraversal(Node* root) {
    stack<Node*> stk1, stk2;
    stk1.push(root);
    
    while (!stk1.empty()) {
        Node* current = stk1.top();
        stk1.pop();
        stk2.push(current);
        
        if (current->left) stk1.push(current->left);
        if (current->right) stk1.push(current->right);
    }
    
    while (!stk2.empty()) {
        cout << stk2.top()->data << " ";
        stk2.pop();
    }
    cout << endl;
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Construct expression tree" << endl;
    cout << "2. Perform post-order traversal" << endl;
    cout << "3. Delete the entire tree" << endl;
    cout << "4. Exit" << endl;
}

int main() {
    Node* root = nullptr;
    string expr;
    int choice;
    
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter prefix expression: ";
                cin >> expr;
                root = constructExpressionTree(expr);
                cout << "Expression tree constructed." << endl;
                break;
                
            case 2:
                if (root) {
                    cout << "Post-order traversal: ";
                    postOrderTraversal(root);
                } else {
                    cout << "Tree is empty." << endl;
                }
                break;
                
            case 3:
                if (root) {
                    deleteTree(root);
                    root = nullptr;
                    cout << "Tree deleted." << endl;
                } else {
                    cout << "Tree is empty." << endl;
                }
                break;
                
            case 4:
                cout << "Exiting program." << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}

