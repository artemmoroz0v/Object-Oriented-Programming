#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "pentagon.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Pentagon& pentagon);
TBinaryTreeItem(const TBinaryTreeItem& other);
virtual ~TBinaryTreeItem();
Pentagon pentagon;
TBinaryTreeItem *left;
TBinaryTreeItem *right;
int counter;
};
#endif