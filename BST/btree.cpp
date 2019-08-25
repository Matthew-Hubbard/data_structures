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
//  insert(10);
//  insert(80);
//  insert(50);
//  insert(60);
  srand(time(0));
  int num_nodes = (rand() % ((MAX_NODES + 1) - MIN_NODES)) + MIN_NODES;
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

/*
int BST::empties()
{
  unordered_map <int, int> empties_map;
  empties_map[0] = 0;
  return empties(root, empties_map);
}

int BST::empties(node * root, unordered_map<int, int> & empties_map)
{
  if(!root)
    return 0;
  return 1;
}
*/

void BST::level_order() const
{
  queue <node *> q; 
  return level_order(root, q);
}

void BST::level_order(node * root, queue <node *> & q) const
{
  cout << endl;
  if(!root)
    return;
  node * current = root;
  unordered_map <int, int> empties_map; //level, number of null nodes on that level
  empties_map[0] = 0;
  int num_nodes = 0; //how many total nodes there should be for this level
  int cur_level = 0; //level of the tree
  int total_empty = 0; //total number of 
  int max_nodes = 1;
  while(current)
  {
    ++num_nodes; //count the node we're on
    cout << "level " << cur_level  << ": " << current->data << "\n";
    //cout << current->data << " ";

    //calculate max number of nodes posible at current level
    max_nodes = pow(2, cur_level + 1) - 1;

    //if no entry for number of empties on next level, set to zero.
    if(empties_map.count(cur_level + 1) == 0)
      empties_map[cur_level + 1] = 0;

    //update total empties found...
    total_empty = calc_empties(empties_map, cur_level);
    cout << "num_nodes: " << num_nodes << ", total_empty: " << total_empty << ", max_nodes: " << max_nodes << endl << endl;

    if(current->left)
      q.push(current->left);
    else
        ++empties_map[cur_level + 1];
    if(current->right)
      q.push(current->right);
    else
        ++empties_map[cur_level + 1];

     if(total_empty + num_nodes >= max_nodes)
     {
      ++cur_level;
      //cout << endl;
     }
  
    current = q.front(); //nullptr when empty
    q.pop();
  }
}

int BST::calc_empties(unordered_map<int, int> & empties_map, int cur_level) const
{
//  cout << "calc_empties: cur_level: " << cur_level << endl;
  int total = 0;
  for(int i = 0; i <= cur_level; ++i)
  {
    total += (pow(2, cur_level - i + 1) - 1) * empties_map[i]; //every level between cur_level and i has twice as many empty slots per level
  }
  return total;
}

