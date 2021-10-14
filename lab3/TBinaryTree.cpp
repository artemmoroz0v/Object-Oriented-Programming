#include "TBinaryTree.h"

TBinaryTree::TBinaryTree () {
    root = NULL;
}

std::shared_ptr<TBinaryTreeItem> copy (std::shared_ptr<TBinaryTreeItem> root) {
    if (!root) {
        return NULL;
    }
    std::shared_ptr<TBinaryTreeItem> root_copy(new TBinaryTreeItem (root->pentagon));
    root_copy->left = copy (root->left);
    root_copy->right = copy (root->right);
    return root_copy;
}

TBinaryTree::TBinaryTree (const TBinaryTree &other) {
    root = copy(other.root);
}

void Print (std::ostream& os, std::shared_ptr<TBinaryTreeItem> node){
    if (!node){
        return;
    }
    if( node->left){
        os << node->pentagon.GetArea() << ": [";
        Print (os, node->left);
        if (node->right){
            if (node->right){
                os << ", ";
                Print (os, node->right);
            }
        }
        os << "]";
    } else if (node->right) {
       os << node->pentagon.GetArea() << ": [";
        Print (os, node->right);
        if (node->left){
            if (node->left){
                os << ", ";
                Print (os, node->left);
            }
        }
        os << "]";
    }
    else {
        os << node->pentagon.GetArea();
    }
}

std::ostream& operator<< (std::ostream& os, TBinaryTree& tree){
    Print(os, tree.root);
    os << "\n";
}

void TBinaryTree::Push (Pentagon &pentagon) {
    if (root == NULL) {
    std::shared_ptr<TBinaryTreeItem> help(new TBinaryTreeItem(pentagon));
    root = help;
    }
    else if (root->pentagon == pentagon) {
        root->counter++;
    }
    else {
        std::shared_ptr<TBinaryTreeItem> parent = root;
        std::shared_ptr<TBinaryTreeItem> current;
        bool childInLeft = true;
        if (pentagon.GetArea() < parent->pentagon.GetArea()) {
            current = root->left;
        }
        else if (pentagon.GetArea() > parent->pentagon.GetArea()) {
            current = root->right;
            childInLeft = false;
        }
        while (current != NULL) {
            if (current->pentagon == pentagon) {
                current->counter++;
            }
            else {
            if (pentagon.GetArea() < current->pentagon.GetArea()) {
                parent = current;
                current = parent->left;
                childInLeft = true;
                }
            else if (pentagon.GetArea() > current->pentagon.GetArea()) {
                parent = current;
                current = parent->right;
                childInLeft = false;
            }
        }
    }
        std::shared_ptr<TBinaryTreeItem> item(new TBinaryTreeItem(pentagon));
        current = item;
        if (childInLeft == true) {
            parent->left = current;
        }
        else {
            parent->right = current;
        }
    }
}

std::shared_ptr<TBinaryTreeItem> FMRST(std::shared_ptr<TBinaryTreeItem> root) { //find minimum value in right subtree
    if (root->left == NULL) {
        return root;
    }
    return FMRST(root->left);
}

std::shared_ptr<TBinaryTreeItem> TBinaryTree:: Pop(std::shared_ptr<TBinaryTreeItem> root, Pentagon &pentagon) {
    if (root == NULL) {
        return root;
    }
    else if (pentagon.GetArea() < root->pentagon.GetArea()) {
        root->left = Pop(root->left, pentagon);
    }
    else if (pentagon.GetArea() > root->pentagon.GetArea()) {
        root->right = Pop(root->right, pentagon);
    }
    else {
        //first case of deleting - we are deleting a list
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            return root;
        }
        //second case of deleting - we are deleting a vertex with only one child
        else if (root->left == NULL && root->right != NULL) {
            std::shared_ptr<TBinaryTreeItem> pointer = root;
            root = root->right;
            return root;
        }
        else if (root->right == NULL && root->left != NULL) {
            std::shared_ptr<TBinaryTreeItem> pointer = root;
            root = root->left;
            return root;
        }
        //third case of deleting 
        else {
            std::shared_ptr<TBinaryTreeItem> pointer = FMRST(root->right);
            root->pentagon.area = pointer->pentagon.GetArea();
            root->right = Pop(root->right, pointer->pentagon);
        }
    }
}

void RecursiveCount(double minArea, double maxArea, std::shared_ptr<TBinaryTreeItem> current, int& ans) {
    if (current != NULL) {
        RecursiveCount(minArea, maxArea, current->left, ans);
        RecursiveCount(minArea, maxArea, current->right, ans);
        if (minArea <= current->pentagon.GetArea() && current->pentagon.GetArea() < maxArea) {
            ans += current->counter;
        }
    }
}

int TBinaryTree::Count(double minArea, double maxArea) {
    int ans = 0;
    RecursiveCount(minArea, maxArea, root, ans);
    return ans;
}

Pentagon& TBinaryTree::GetItemNotLess(double area, std::shared_ptr<TBinaryTreeItem> root) {
    if (root->pentagon.GetArea() >= area) {
        return root->pentagon;
    }
    else {
        GetItemNotLess(area, root->right);
    }
}

void RecursiveClear(std::shared_ptr<TBinaryTreeItem> current){
    if (current!= NULL){
        RecursiveClear(current->left);
        RecursiveClear(current->right);
            current = NULL;
    }
}

void TBinaryTree::Clear(){
    RecursiveClear(root);
    root = NULL;
}

bool TBinaryTree::Empty() {
     if (root == NULL) {
         return true;
     }
     return false;
}

TBinaryTree::~TBinaryTree() {
    Clear();
    std:: cout << "Your tree has been deleted" << std:: endl;
}