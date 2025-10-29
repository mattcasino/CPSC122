#include <iostream>
using namespace std;

#include "2-List.h"


//Constructor
List::List()
{       
 length = 0;
 head = NULL;
 tail = NULL;
}

List::List(List &LstIn)
{
  length = 0;
  node* cur = LstIn.head;
  while(cur != nullptr) {
    PutItemT(cur->item);
    cur = cur->next;
  }
}

List::~List()
{
  while(!IsEmpty()) {
    DeleteItemH();
  }
}

void List::PutItemH(itemType itemIn)
{
 node* tmp = new node{itemIn, nullptr};
 tmp->item = itemIn;
 if (!IsEmpty()) {
   tmp->next = head;
 } else {
   tail = tmp;
 }
 head = tmp;
 length++;
}

itemType List::GetItemH() {
  return head->item;
}

void List::DeleteItemH() {
  node* tmp = head;
  head = head->next;
  --length;
  delete tmp;
  tmp = nullptr;
}

void List::PutItemT(itemType itemIn) {
  if(IsEmpty()) { 
    PutItemH(itemIn); 
    return;
  }
  tail->next = new node{itemIn, nullptr};
  tail = tail->next;
  length++;
}

itemType List::GetItemT() {
  return tail->item;
}

void List::DeleteItemT() {
  node* cur = head;
  if(length == 1) {
    DeleteItemH();
    return;
  }
  while(cur->next->next != nullptr) 
    cur = cur->next;
  delete cur->next;
  tail = cur;
  length--;
  cur->next = nullptr;
}

bool List::IsEmpty()
{
  if (length == 0)
    return true;
  return false;
}

int List::GetLength() {
  return length;
}

void List::Print()
{
 node* cur = head;
 while(cur != NULL)
  {
   cout << cur->item << endl;
   cur = cur->next;
  }
}

int List::Find(itemType target) {
  int count = 0;
  node* cur = head;
  while(cur != nullptr) {
    if(cur->item == target) ++count;
    cur = cur->next;
  }
  return count;
}

int List::DeleteItem(itemType target) {
  int res;
  node* cur = FindPtrTo(target, head);
  while( cur != nullptr ) {
    node* newnext = nullptr;
    if(cur->next->next != nullptr)
      newnext = cur->next->next;

    delete cur->next;
    cur->next = newnext;
    length--;
    res++;
    cur = FindPtrTo(target, cur);
  }
  return res;
}

void List::InsertItem(int pos, itemType itemIn) {
  node* cur = head;
  if(pos == 0) {
    PutItemH(itemIn);
    return;
  }
  while(pos > 1) {
    cur = cur->next;
    pos--;
  }
  node* tmp = cur->next;
  cur->next = new node{itemIn, tmp};
  length++;
}


node* List::FindPtrTo(itemType t, node* offset) {
  node* cur = offset;
  while(cur->next != nullptr) {
    if(cur->next->item == t) return cur;
    cur = cur->next;
  }
  if(cur->next == nullptr) return nullptr;
  return cur;
}
