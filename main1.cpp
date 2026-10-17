#include <iostream>
#include <windows.h>
#include "sy1.h"

int main()
{
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);
  SqList L;
  L.load_file("data1.txt");
  L.output_array();
  L.menu();
  L.save_file("data1.txt");
}