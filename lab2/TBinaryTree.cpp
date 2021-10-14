#include "TBinaryTree.h"

TBinaryTree::TBinaryTree () {
    root = NULL;
}

TBinaryTreeItem* copy (TBinaryTreeItem* root) {
    if (!root) {
        return NULL;
    }
    TBinaryTreeItem* root_copy = new TBinaryTreeItem (root->pentagon);
    root_copy->left = copy (root->left);
    root_copy->right = copy (root->right);
    return root_copy;
}

TBinaryTree::TBinaryTree (const TBinaryTree &other) {
    root = copy(other.root);
}

void Print (std::ostream& os, TBinaryTreeItem* node){
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
    root = new TBinaryTreeItem(pentagon);
    }
    else if (root->pentagon == pentagon) {
        root->counter++;
    }
    else {
        TBinaryTreeItem* parent = root;
        TBinaryTreeItem* current;
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
        current = new TBinaryTreeItem(pentagon);
        if (childInLeft == true) {
            parent->left = current;
        }
        else {
            parent->right = current;
        }
    }
}

TBinaryTreeItem* FMRST(TBinaryTreeItem* root) {
    if (root->left == NULL) {
        return root;
    }
    return FMRST(root->left);
}

TBinaryTreeItem* TBinaryTree:: Pop(TBinaryTreeItem* root, Pentagon &pentagon) {
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
            delete root;
            root = NULL;
            return root;
        }
        //second case of deleting - we are deleting a verex with only one child
        else if (root->left == NULL && root->right != NULL) {
            TBinaryTreeItem* pointer = root;
            root = root->right;
            delete pointer;
            return root;
        }
        else if (root->right == NULL && root->left != NULL) {
            TBinaryTreeItem* pointer = root;
            root = root->left;
            delete pointer;
            return root;
        }
        //third case of deleting 
        else {
            TBinaryTreeItem* pointer = FMRST(root->right);
            root->pentagon.area = pointer->pentagon.GetArea();
            root->right = Pop(root->right, pointer->pentagon);
        }
    }
}

void RecursiveCount(double minArea, double maxArea, TBinaryTreeItem* current, int& ans) {
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

Pentagon& TBinaryTree::GetItemNotLess(double area, TBinaryTreeItem* root) {
    if (root->pentagon.GetArea() >= area) {
        return root->pentagon;
    }
    else {
        GetItemNotLess(area, root->right);
    }
}

void RecursiveClear(TBinaryTreeItem* current){
    if (current!= NULL){
        RecursiveClear(current->left);
        RecursiveClear(current->right);
            delete current;
            current = NULL;
    }
}

void TBinaryTree::Clear(){
    RecursiveClear(root);
    delete root;
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