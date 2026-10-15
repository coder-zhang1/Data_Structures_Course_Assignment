#include "sy1.h"

#include <iostream>
#include <cstdlib>

void init_array(SqList &L)
{
  L.data = (int *)malloc(sizeof(int) * 4);
  if (L.data == nullptr)
  {
    std::cout << "创建失败！";
    return;
  }
  L.length = 0;
  L.capacity = 4;
  std::cout << "数组创建成功！";
}

void input_num(SqList &L)
{
  

  
}