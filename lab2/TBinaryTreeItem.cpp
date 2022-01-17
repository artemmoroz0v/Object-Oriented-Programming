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

Pentagon& TBinaryTreeItem::GetPentagon() {
    return this->pentagon;
}

void TBinaryTreeItem::SetPentagon(const Pentagon& pentagon){
    this->pentagon = pentagon;
}
TBinaryTreeItem* TBinaryTreeItem::GetLeft(){
    return this->left;
}
TBinaryTreeItem* TBinaryTreeItem::GetRight(){
    return this->right;
}


void TBinaryTreeItem::SetLeft(TBinaryTreeItem* item) {
    if (this != NULL){
        this->left = item;
    }
}

void TBinaryTreeItem::SetRight(TBinaryTreeItem* item) {
    if (this != NULL){
        this->right = item;
    }
}

void TBinaryTreeItem::IncreaseCounter() {
    if (this != NULL){
        counter++;
    }
}
void TBinaryTreeItem::DecreaseCounter() {
    if (this != NULL){
        counter--;
    }
}

int TBinaryTreeItem::ReturnCounter() {
    return this->counter;
}

TBinaryTreeItem::~TBinaryTreeItem() {
}


