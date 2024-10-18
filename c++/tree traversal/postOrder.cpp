#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    postOrderTraversal(root->left);

    // Traverse the right subtree
    postOrderTraversal(root->right);

    // Visit the current node
    cout << root->val << " ";
}

// Function to deallocate the tree nodes
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);  // Corrected function calls
    deleteTree(root->right); // Corrected function calls
    delete root;             // Free the current node
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform post-order traversal
    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;  // Print a new line after the traversal output

    // Deallocate the tree nodes
    deleteTree(root);
    return 0;
}
