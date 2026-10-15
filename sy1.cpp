#include "sy1.h"

#include <iostream>
#include <cstdlib>

void init_array(SqList &L)
{
  L.data = nullptr;
  L.length = 0;
  L.capacity = 0;
}

void input_num(SqList &L)
{
  int num;
  std::cout << "请输入输入数字的数量：";
  std::cin >> num;
  if (num <= 0)
  {
    std::cout << "输入非法！";
  }
  L.data = (int *)malloc(sizeof(int) * num);
  if (L.data = nullptr)
  {
    std::cout << "内存分配失败！";
    return;
  }
  L.capacity = num;
  L.length = 0;
  for (int i = 0; i < num; i++)
  {
    std::cin >> L.data[i];
    L.length++;
  }
}