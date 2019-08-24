#include <iostream>
#include <queue>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 20 
#define MAX_DATA 99
#define MIN_DATA 1

struct node
{
  int data;
  node * left;
  node * right;
  node () : data(0), left(nullptr), right(nullptr) {};
  node (int add) : data(add), left(nullptr), right(nullptr) {};
};

class BST 
{
  public:
    BST() : root(nullptr) {};
    ~BST() {remove_all();};
    void insert(int to_add);
    void build();
    void remove_all();
    void in_order() const;
    void pre_order() const;
    void post_order() const;
    void level_order() const;

  protected:

  private:
  //data members
    node * root;
  
  //functions
    void insert(node *& root, int to_add);
    void remove_all(node *& root);
    void in_order(node * root) const;
    void pre_order(node * root) const;
    void post_order(node * root) const;
    void level_order(node * root, std::queue <node *> & q) const;
};