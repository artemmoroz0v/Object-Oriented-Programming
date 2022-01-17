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
std::shared_ptr<TBinaryTreeItem> TBinaryTreeItem::GetLeft(){
    return this->left;
}
std::shared_ptr<TBinaryTreeItem> TBinaryTreeItem::GetRight(){
    return this->right;
}


void TBinaryTreeItem::SetLeft(std::shared_ptr<TBinaryTreeItem> item) {
    if (this != NULL){
        this->left = item;
    }
}

void TBinaryTreeItem::SetRight(std::shared_ptr<TBinaryTreeItem> item) {
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
    std::cout << "Destructor TBinaryTreeItem was called\n";
}


