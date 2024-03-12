#include <string>
#include "list.h"

using namespace std;

Node::Node(string element)
{  
   data = element;
   previous = nullptr;
   next = nullptr;
}

List::List()
{  
   first = nullptr;
}

void List::push_back(string element)
{  
   Node* new_node = new Node(element);
   if (first == nullptr) // List is empty
   {  
      first = new_node;
      first->next = first;      // First initializes itself
      first->previous = first;  // as both next and previous
   }
   else
   {  
      Node* temp = first->previous;
      temp->next = new_node;
      new_node->previous = temp;
      new_node->next = first;
      first->previous = new_node;
   }
}

void List::insert(Iterator iter, string element)
{  
   if (iter.position == nullptr)
   {  
      push_back(element);
      return;
   }

   Node* after = iter.position;
   Node* before = after->previous;
   Node* new_node = new Node(element);
   new_node->previous = before;
   new_node->next = after;
   after->previous = new_node;
   if (before == first->previous) // Insert at beginning
   {
      first = new_node;
   }
   else
   {
      before->next = new_node;
   }
}

Iterator List::erase(Iterator iter)
{  
   Node* remove = iter.position;
   Node* before = remove->previous;
   Node* after = remove->next;
   if (remove == first)
   {
      first = after;
   }
   else
   {
      before->next = after;
   }
   if (remove == first->previous)
   {
      first->previous = before;
   }
   else
   {
      after->previous = before;
   }
   delete remove;
   Iterator r;
   r.position = after;
   r.container = this;
   return r;
}

Iterator List::begin()
{  
   Iterator iter;
   iter.position = first;
   iter.container = this;
   return iter;
}

Iterator List::end()
{  
   Iterator iter;
   iter.position = first->previous;
   iter.container = this;
   return iter;
}

Iterator::Iterator()
{  
   position = nullptr;
   container = nullptr;
}

string Iterator::get() const
{  
   return position->data;
}

void Iterator::next()
{ 
   position = position->next;
}

void Iterator::previous()
{  
   position = position->previous;
}

bool Iterator::equals(Iterator other) const
{  
   return position == other.position;
}
