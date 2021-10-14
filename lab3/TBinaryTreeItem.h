#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "pentagon.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Pentagon& pentagon);
TBinaryTreeItem(const TBinaryTreeItem& other);
virtual ~TBinaryTreeItem();
Pentagon pentagon;
std::shared_ptr<TBinaryTreeItem> left;
std::shared_ptr<TBinaryTreeItem> right;
int counter;
};
#endif