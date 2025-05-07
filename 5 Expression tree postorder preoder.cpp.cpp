#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int longestPath(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int leftHeight = longestPath(root->left);
    int rightHeight = longestPath(root->right);
    
    return max(leftHeight, rightHeight) + 1;
}

int findMin(Node* root) {
    Node* current = root;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

void swapChildren(Node* root) {
    if (root == nullptr) return;
    
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    swapChildren(root->left);
    swapChildren(root->right);
}

bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Insert a new node" << endl;
    cout << "2. Find the number of nodes in the longest path from root" << endl;
    cout << "3. Find the minimum data value in the tree" << endl;
    cout << "4. Swap left and right pointers at every node" << endl;
    cout << "5. Search for a value in the tree" << endl;
    cout << "6. Inorder Traversal of the tree" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    Node* root = nullptr;
    int n, value, choice;

    cout << "Enter the number of values you want to insert: ";
    cin >> n;
    
    cout << "Enter the values to insert into the binary search tree:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter a new node value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Node inserted." << endl;
                break;

            case 2:
                cout << "Longest path from root has " << longestPath(root) << " nodes." << endl;
                break;

            case 3:
                cout << "Minimum data value in the tree: " << findMin(root) << endl;
                break;

            case 4:
                swapChildren(root);
                cout << "Inorder traversal after swapping children: ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 5:
                cout << "Enter a value to search in the tree: ";
                cin >> value;
                if (search(root, value)) {
                    cout << "Value " << value << " found in the tree." << endl;
                } else {
                    cout << "Value " << value << " not found in the tree." << endl;
                }
                break;

            case 6:
                cout << "Inorder Traversal of the tree: ";
                inorderTraversal(root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 7);

    return 0;
}


