#include <iostream>
#include "btree.h"

using namespace std;

int main()
{
  //cout << "hello world";
  BST tree;

  cout << "Insert order: \n";
  tree.build();
  cout << endl;

  cout << "Pre order: \n";
  tree.pre_order();
  cout << endl;

  cout << "In order: \n";
  tree.in_order();
  cout << endl;


  cout << "Post order: \n";
  tree.post_order();
  cout << endl;

  cout << "Level order: \n";
  tree.level_order();

  return 0;
}