#include <iostream>
#include "lll.h"
#include <cstring>

using namespace std;

const int IGNORE = 100;

int main()
{
  lll list;
  int num_nodes = 0;
  int remove = 0;
  int insert = 0;
  char response = '\0';
  
  cout << "How many nodes to you want?: ";
  cin >> num_nodes;
  cin.ignore(IGNORE, '\n');

  list.build(num_nodes);
  list.display();

  cout << "Do you want to remove a node?(Y/N): ";
  cin >> response;
  cin.ignore(IGNORE, '\n');

  while(toupper(response) == 'Y')
  {
    cout << "What data do you want to remove?: ";
    cin >> remove;
    cin.ignore(IGNORE, '\n');
   
    list.remove(remove);
    list.display();

    cout << "Do you want to remove another node?(Y/N): ";
    cin >> response;
    cin.ignore(IGNORE, '\n');
  }

  cout << "Do you want to insert a node?(Y/N): ";
  cin >> response;
  cin.ignore(IGNORE, '\n');

  while(toupper(response) == 'Y')
  {
    cout << "What data do you want to insert?: ";
    cin >> insert;
    cin.ignore(IGNORE, '\n');
   
    list.add_at_front(insert);
    list.display();

    cout << "Do you want to insert another node?(Y/N): ";
    cin >> response;
    cin.ignore(IGNORE, '\n');
  }

  return 0;
}
