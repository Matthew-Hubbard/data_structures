#include "btree.h"

using namespace std;

void BST::insert(int to_add)
{
  return insert(root, to_add);
}

void BST::insert(node *& root, int to_add)
{
  if(!root) //add at leaf
  {
    root = new node(to_add);
    return;
  }
  if(to_add < root->data) //if to_add < root->data, traverse left
    return insert(root->left, to_add);
  else //else traverse right
    return insert(root->right, to_add);
}

void BST::build()
{
  srand(time(0));
  int num_nodes = rand() % MAX_NODES;
  int add = 0;
  for(int i = 0; i < num_nodes; ++i)
  {
    add = rand() % (MAX_DATA + 1) + MIN_DATA;
    cout << add << " ";
    insert(add);
  }
}

void BST::remove_all()
{
  return remove_all(root);
} 

void BST::remove_all(node *& root)
{
  if(!root)
    return;
  remove_all(root->left);
  remove_all(root->right);
  if(root)
  {
    delete root;
    root = nullptr;
  }
}

void BST::in_order() const
{
  return in_order(root);
}

void BST::in_order(node * root) const
{
  if(!root)
    return;
  in_order(root->left); 
  cout << root->data << " ";
  return in_order(root->right); 
}

void BST::pre_order() const
{
  return pre_order(root);
}

void BST::pre_order(node * root) const
{
  if(!root)
    return;
  cout << root->data << " ";
  pre_order(root->left); 
  return pre_order(root->right); 
}

void BST::post_order() const
{
  return post_order(root);
}

void BST::post_order(node * root) const
{
  if(!root)
    return;
  post_order(root->left); 
  post_order(root->right); 
  cout << root->data << " ";
  return;
}

void BST::level_order() const
{
  queue <node *> q; 
  return level_order(root, q);
}

void BST::level_order(node * root, queue <node *> & q) const
{
  if(!root)
    return;
  node * current = root;
  while(current)
  {
    cout << current->data << " ";
    if(current->left)
      q.push(current->left);
    if(current->right)
      q.push(current->right);
    current = q.front();
    q.pop();
  }
}

