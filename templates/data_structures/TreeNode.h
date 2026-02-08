#ifndef TREENODE_H
#define TREENODE_H

#include <vector>
#include <queue>
#include <iostream>

/**
 * Definition for a binary tree node.
 * This is the standard TreeNode structure used in LeetCode problems.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Helper function to create a binary tree from level-order array
 * Usage: TreeNode* root = createTree({1, 2, 3, -1, -1, 4, 5});
 * Note: Use -1 or INT_MIN to represent null nodes
 */
TreeNode* createTree(const std::vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    
    size_t i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Left child
        if (i < values.size() && values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;
        
        // Right child
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

/**
 * Helper function to print tree in level-order
 * Usage: printTree(root);
 */
void printTree(TreeNode* root) {
    if (!root) {
        std::cout << "[]" << std::endl;
        return;
    }
    
    std::queue<TreeNode*> q;
    q.push(root);
    std::cout << "[";
    bool first = true;
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (!first) std::cout << ", ";
        first = false;
        
        if (current) {
            std::cout << current->val;
            q.push(current->left);
            q.push(current->right);
        } else {
            std::cout << "null";
        }
    }
    std::cout << "]" << std::endl;
}

/**
 * Helper function to print tree in-order (sorted for BST)
 * Usage: printInOrder(root);
 */
void printInOrder(TreeNode* root) {
    if (!root) return;
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

/**
 * Helper function to delete a binary tree (free memory)
 * Usage: deleteTree(root);
 */
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

/**
 * Helper function to get the height of a tree
 * Usage: int h = getHeight(root);
 */
int getHeight(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(getHeight(root->left), getHeight(root->right));
}

/**
 * Helper function to count nodes in a tree
 * Usage: int count = countNodes(root);
 */
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

#endif // TREENODE_H
