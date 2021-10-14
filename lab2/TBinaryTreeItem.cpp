#include "TBinaryTreeItem.h"

TBinaryTreeItem::TBinaryTreeItem(const Pentagon &pentagon) {
    this->pentagon = pentagon;
    this->left = this->right = NULL;
    this->counter = 1;
}

TBinaryTreeItem::TBinaryTreeItem(const TBinaryTreeItem &other) {
    this->pentagon = other.pentagon;
    this->left = other.left;
    this->right = other.right;
    this->counter = other.counter;
}

TBinaryTreeItem::~TBinaryTreeItem() {}


