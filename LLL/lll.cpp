#include "lll.h"

lll::lll() : head(nullptr), total(0){}

lll::~lll()
{
  remove_all(head);
}

int lll::add_at_front(int data)
{
  node * add = new node(data);    
  add->next = head;
  head = add;
  ++total;
  return 0;
}

int lll::build(int num_to_add)
{
  if(num_to_add < 0)
    return -1;
  srand(time(NULL));
  for(int i = 0; i < num_to_add; ++i)
    add_at_front(rand() % 20 + 1);
  return 0;
}

void lll::display()
{
  if(!head)
  {
    std::cout << "Empty list.\n";
    return; 
  }
  display(head);
  std::cout << "Total number of nodes: " << total << std::endl;
  return;
}

void lll::display(node * head)
{
  if(!head)
    return;
  std::cout << head->data;
  if(head->next)
    std::cout << " -> ";
  else
    std::cout << std::endl;
  display(head->next);
  return;
}

void lll::display_iterative()
{
  node * current = head;
  while(current->next)
  {
    std::cout << current->data << " -> ";
    current = current->next;
  }
  std::cout << head->data << std::endl;
  return;
}

int lll::remove_all()
{
  return remove_all(head);
}

int lll::remove_all(node *& head) 
{
  if(!head)
    return 0;
  int count = remove_all(head->next) + 1;
  delete head;
  head = NULL;
  return count;
}

int lll::remove(int to_remove)
{
  return remove(to_remove, head);
}
int lll::remove(int to_remove, node *& head)
{
  if(!head)
    return -1;
  if(head->data == to_remove)
  {
    node * temp = head;
    head = head->next;
    delete temp;
    --total;
    return 0;
  }
  return remove(to_remove, head->next);
}

int lll::sort()
{
  return merge_sort(head);
}

int lll::merge_sort(node *& head)
{

    return 0;
}




