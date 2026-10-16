#include "sy1.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

SqList::SqList()
{
  data = nullptr;
  length = 0;
  capacity = 0;
}

SqList::~SqList()
{
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
  std::cout << "内存释放成功";
}

void input_num(SqList &L)
{
  int nums;
  std::cout<<"输入数字数量";
  std::cin>>nums;
  L.data=

}
