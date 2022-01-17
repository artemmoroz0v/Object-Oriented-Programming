#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "pentagon.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Pentagon& pentagon);
TBinaryTreeItem(const TBinaryTreeItem& other);
Pentagon& GetPentagon();
void SetPentagon(Pentagon& pentagon);
TBinaryTreeItem* GetLeft();
TBinaryTreeItem* GetRight();
void SetLeft(TBinaryTreeItem* item);
void SetRight(TBinaryTreeItem* item);
void SetPentagon(const Pentagon& pentagon);
void IncreaseCounter();
void DecreaseCounter();
int ReturnCounter();
virtual ~TBinaryTreeItem();

private:
Pentagon pentagon;
TBinaryTreeItem *left;
TBinaryTreeItem *right;
int counter;
};
#endif