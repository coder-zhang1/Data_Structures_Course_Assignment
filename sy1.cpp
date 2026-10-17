#include "sy1.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

void SqList::menu()
{
  int op;
  bool running = true;
  while (running)
  {
    std::cout << "1.输入数字覆盖当前数组" << "\n";
    std::cout << "2.在当前数组后追加元素" << "\n";
    std::cout << "3.按位置删除数字" << "\n";
    std::cout << "4.按值删除数字" << "\n";
    std::cout << "5.插入数字" << "\n";
    std::cout << "6.输出当前数组" << "\n";
    std::cout << "0.退出程序" << "\n";
    std::cout << "输入选择:";
    std::cin >> op;
    switch (op)
    {
    case 1:
    {
      input_num();
      break;
    }
    case 2:
    {
      append_num();
      break;
    }
    case 3:
    {
      delete_num_by_pos();
      break;
    }
    case 4:
    {
      delete_num_by_val();
      break;
    }
    case 5:
    {
      insert_num();
      break;
    }
    case 6:
    {
      output_array();
      break;
    }
    case 0:
    {
      std::cout << "程序退出成功" << "\n";
      running = false;
      break;
    }
    default:
    {
      std::cout << "输入非法" << "\n";
    }
    }
  }
}

SqList::SqList()
{
  data = nullptr;
  length = 0;
  capacity = 100;
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

void SqList::input_num()
{
  int nums;
  std::cout << "输入数字数量：" << "\n";
  std::cin >> nums;
  if (nums <= 0 || nums > capacity)
  {
    std::cout << "输入非法或者数字过多" << "\n";
    return;
  }
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
  data = new (std::nothrow) int[capacity];
  if (data == nullptr)
  {
    std::cout << "内存分配失败" << "\n";
    length = 0;
    return;
  }
  length = nums;
  std::cout << "请依次输入" << nums << "个整数：" << "\n";
  for (int i = 0; i < nums; i++)
  {
    std::cin >> data[i];
  }
  std::cout << "\n";
  std::cout << "数字录入完毕" << "\n";
}

void SqList::delete_num_by_val()
{
  if (data == nullptr || length == 0)
  {
    std::cout << "顺序表是空的" << "\n";
    return;
  }
  std::cout << "请输入要删除的数字：" << "\n";
  int val;
  std::cin >> val;
  // 双指针删除元素
  int j = 0;
  for (int i = 0; i < length; i++)
  {
    if (data[i] != val)
    {
      data[j++] = data[i];
    }
  }
  length = j;
  std::cout << "已删除全部为" << val << "的元素" << "\n";
  return;
}

void SqList::delete_num_by_pos()
{
  if (data == nullptr || length == 0)
  {
    std::cout << "顺序表是空的" << "\n";
    return;
  }
  std::cout << "请输入要删除的位置：" << "\n";
  int pos;
  std::cin >> pos;
  for (int i = pos; i < length; i++)
  {
    data[i - 1] = data[i];
  }
  length--;
  return;
}

void SqList::output_array()
{
  if (data == nullptr || length == 0)
  {
    std::cout << "顺序表是空的" << "\n";
    return;
  }
  std::cout << "顺序表元素:" << "\n";
  for (int i = 0; i < length; i++)
  {
    std::cout << data[i] << " ";
  }
  std::cout << "\n";
  std::cout << "顺序表输出完毕" << "\n";
}

void SqList::insert_num()
{
  if (length >= capacity)
  {
    std::cout << "顺序表已满，无法插入" << "\n";
    return;
  }
  std::cout << "请输入要插入的位置和值：" << "\n";
  int pos, val;
  std::cin >> pos >> val;
  if (pos <= 0 || pos > length)
  {
    std::cout << "插入位置非法" << "\n";
  }
  for (int i = length; i > pos; i--)
  {
    data[i] = data[i - 1];
  }
  data[pos] = val;
  length++;
}
void SqList::append_num()
{
  if (length >= capacity)
  {
    std::cout << "顺序表已满，无法追加数字" << "\n";
    return;
  }
  int num;
  std::cout << "请输入要追加的数字的数量：";
  std::cin >> num;
  if (num <= 0 || num + length > capacity)
  {
    std::cout << "输入非法或者追加数字过多" << "\n";
    return;
  }
  int new_len = num + length;
  int *new_data = new (std::nothrow) int[new_len];
  if (new_data == nullptr)
  {
    std::cout << "内存分配失败" << "\n";
    return;
  }
  for (int i = 0; i < length; i++)
  {
    new_data[i] = data[i];
  }
  std::cout << "请依次输入要追加的" << num << "个数字：" << "\n";

  for (int i = length; i < new_len; i++)
  {
    std::cin >> new_data[i];
  }
  if (data != nullptr)
  {
    delete[] data;
  }
  data = new_data;
  length = new_len;
}
void SqList::save_file(const char *filename)
{
  if (data == nullptr || length == 0)
  {
    std::cout << "顺序表为空，无法保存" << "\n";
    return;
  }
  std::ofstream out(filename);
  if (!out.is_open())
  {
    std::cout << "文件打开失败" << "\n";
    return;
  }
  out << length << "\n";
  for (int i = 0; i < length; i++)
  {
    out << data[i] << " ";
  }
  out.close();
  std::cout << "文件保存成功" << "\n";
}

void SqList::load_file(const char *filename)
{
  std::ifstream in(filename);
  if (!in.is_open())
  {
    std::cout << "文件打开失败" << "\n";
    return;
  }
  int len;
  in >> len;
  if (len <= 0)
  {
    std::cout << "文件数据非法" << "\n";
    return;
  }
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
  data = new (std::nothrow) int[len];
  if (data == nullptr)
  {
    std::cout << "内存分配失败" << "\n";
    length = 0;
    in.close();
    return;
  }
  length = len;
  for (int i = 0; i < len; i++)
  {
    in >> data[i];
  }
  in.close();
  std::cout << "文件读取成功" << "\n";
  return;
}