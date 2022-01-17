#ifndef TBINARYTREE_ITEM_H
#define TBINARYTREE_ITEM_H
#include "pentagon.h"

class TBinaryTreeItem {
public:
TBinaryTreeItem(const Pentagon& pentagon);
TBinaryTreeItem(const TBinaryTreeItem& other);
Pentagon& GetPentagon();
void SetPentagon(Pentagon& pentagon);
std::shared_ptr<TBinaryTreeItem> GetLeft();
std::shared_ptr<TBinaryTreeItem> GetRight();
void SetLeft(std::shared_ptr<TBinaryTreeItem> item);
void SetRight(std::shared_ptr<TBinaryTreeItem> item);
void SetPentagon(const Pentagon& pentagon);
void IncreaseCounter();
void DecreaseCounter();
int ReturnCounter();
virtual ~TBinaryTreeItem();

private:
Pentagon pentagon;
std::shared_ptr<TBinaryTreeItem> left;
std::shared_ptr<TBinaryTreeItem> right;
int counter;
};
#endif