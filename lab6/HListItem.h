#ifndef HLISTITEM_H
#define HLISTITEM_H
#include <iostream>
#include "pentagon.h"
#include <memory>

template <class T> class HListItem {
public:
  HListItem(const std::shared_ptr<Pentagon> &pentagon);
  template <class A> friend std::ostream& operator<<(std::ostream& os, HListItem<A> &obj);
  ~HListItem();
  std::shared_ptr<T> pentagon;
  std::shared_ptr<HListItem<T>> next;
};
#include "HListItem.cpp"
#endif
