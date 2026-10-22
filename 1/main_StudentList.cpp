#include <iostream>
#include <windows.h>
#include "StudentList.h"

int main()
{
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);
  StudentList L;
  L.load_file("student.txt");
  L.menu();
  L.save_file("student.txt");
  return 0;
}
