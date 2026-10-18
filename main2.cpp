#include <iostream>
#include <windows.h>
#include "LinkList.h"

int main()
{
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);
  LinkList L;
  L.load_file("data2.txt");
  L.menu();
  L.save_file("data2.txt");
}