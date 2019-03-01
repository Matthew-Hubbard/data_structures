#include <iostream>
#include <stdlib.h>
#include <time.h> 

struct node
{
  node() : data(0), next(nullptr) {}
  node(int in) : data(in), next(nullptr) {}
  int data;
  node * next;
};

class lll
{
  public:
    lll();
    ~lll();
    
    int add_at_front(int data);
    int build(int num_to_add);
    void display();
    void display_iterative();
    int remove(int to_remove);
    int remove_all();
    int sort();
  protected:
    void display(node * head);
    int remove(int to_remove, node *& head);
    int remove_all(node *& head);
    int merge_sort(node *& head);
  private:
    node * head;
    int total; //total number of nodes in LLL
};
