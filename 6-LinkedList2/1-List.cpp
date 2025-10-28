#include <iostream>
using namespace std;

#include "1-List.h"

//Constructor
List::List()
{       
 length = 0;
 head = NULL;
}
//Destructor
List::~List()
{
  while(!IsEmpty()) {
    DeleteItemH();
  }
}

void List::PutItemH(itemType itemIn)
{
 node* tmp = new node;
 tmp->item = itemIn;
 tmp->next = head;
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

bool List::IsEmpty() {
  return head == nullptr || length == 0;
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

void List::PutItemT(itemType item) {
  node* tail = GetT();
  tail->next = new node{item};
  length++;
}
itemType List::GetItemT() {
  return GetT()->item;
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
  length--;
  cur->next = nullptr;
}

node* List::GetT() {
  node* cur = head;
  while(cur->next != nullptr)
    cur = cur->next;
  return cur;
}
