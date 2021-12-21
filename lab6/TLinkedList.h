#ifndef HLIST_H
#define HLIST_H
#include <iostream>
#include "HListItem.h"
#include "pentagon.h"
#include <memory>

template <class T> class TLinkedList {
public:
  TLinkedList();
  int size_of_list;
  size_t Length();
  std::shared_ptr<Pentagon>& First();
  std::shared_ptr<Pentagon>& Last();
  std::shared_ptr<Pentagon>& GetItem(size_t idx);
  bool Empty();
  TLinkedList(const std::shared_ptr<TLinkedList> &other);
  void InsertFirst(const std::shared_ptr<Pentagon> &&pentagon);
  void InsertLast(const std::shared_ptr<Pentagon> &&pentagon);
  void RemoveLast();
  void RemoveFirst();
  void Insert(const std::shared_ptr<Pentagon> &&pentagon, size_t position);
  void Remove(size_t position);
  void Clear();
  template <class A> friend std::ostream& operator<<(std::ostream& os, TLinkedList<A>& list);
  ~TLinkedList(); 
private:
  std::shared_ptr<HListItem<T>> front;
  std::shared_ptr<HListItem<T>> back;
};
#include "TLinkedList.cpp"
#endif 

