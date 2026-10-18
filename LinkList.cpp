#include "LinkList.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void LinkList::menu()
{
  int op;
  bool running = true;
  while (running)
  {
    system("cls");
    std::cout << "1.输入数字覆盖当前链表" << "\n";
    std::cout << "2.在当前链表后追加元素" << "\n";
    std::cout << "3.按位置删除数字" << "\n";
    std::cout << "4.按值删除数字" << "\n";
    std::cout << "5.头插" << "\n";
    std::cout << "6.尾插" << "\n";
    std::cout << "7.指定位置插入" << "\n";
    std::cout << "8.输出当前链表" << "\n";
    std::cout << "0.退出程序" << "\n";
    std::cout << "输入选择:";
    if (!(std::cin >> op))
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "请输入数字\n";
      continue;
    }
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
      insert_head();
      break;
    }
    case 6:
    {
      insert_tail();
      break;
    }
    case 7:
    {
      insert_pos();
      break;
    }
    case 8:
    {
      output_linklist();
      break;
    }
    case 0:
    {
      std::cout << "程序退出成功" << "\n";
      running = false;
      continue;
    }
    default:
    {
      std::cout << "输入非法" << "\n";
    }
    }
    std::cout << "\n按回车继续...";
    std::cin.ignore(10000, '\n');
    std::cin.get();
  }
}
Node::Node(int val) : data(val), next(nullptr) {}

LinkList::LinkList()
{
  head = new Node(0);
  length = 0;
}

LinkList::~LinkList()
{
  clear_linklist();
  delete head;
}

void LinkList::input_num()
{
  int nums;
  std::cout << "输入数字数量：" << "\n";
  std::cin >> nums;
  if (nums <= 0)
  {
    std::cout << "输入非法" << "\n";
    return;
  }
  std::cout << "请依次输入" << nums << "个整数：" << "\n";
  std::vector<int> vals;
  vals.reserve(nums);
  for (int i = 0; i < nums; i++)
  {
    int tmp;
    if (!(std::cin >> tmp))
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "输入中断，原链表保留，未覆盖\n";
      return;
    }
    vals.push_back(tmp);
  }
  clear_linklist();
  Node *p = head;
  for (int x : vals)
  {
    p->next = new Node(x);
    p = p->next;
  }
  length = (int)vals.size();
  output_linklist();
  std::cout << "数字录入完毕" << "\n";
}

void LinkList::append_num()
{
  int nums, cnt = 0;
  std::cout << "输入追加数字数量：" << "\n";
  std::cin >> nums;
  if (nums <= 0)
  {
    std::cout << "输入非法" << "\n";
    return;
  }
  std::cout << "请依次输入" << nums << "个整数：" << "\n";
  Node *p = head;
  while (p->next != nullptr)
  {
    p = p->next;
  }
  for (int i = 0; i < nums; i++)
  {
    int tmp;
    if (!(std::cin >> tmp))
    {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "输入中断，已追加 " << cnt << " 个\n";
      break;
    }
    Node *new_node = new Node(tmp);
    p->next = new_node;
    p = new_node;
    cnt++;
  }
  length += cnt;
  std::cout << "\n";
  output_linklist();
  std::cout << "数字录入完毕" << "\n";
}

void LinkList::clear_linklist()
{
  Node *p = head->next;
  while (p != nullptr)
  {
    Node *tmp = p;
    p = p->next;
    delete tmp;
  }
  head->next = nullptr;
  length = 0;
  return;
}

void LinkList::output_linklist()
{
  if (length == 0)
  {
    std::cout << "链表为空" << "\n";
    return;
  }
  std::cout << "当前长度：" << length << "\n";
  int i = 1;
  for (Node *p = head->next; p; p = p->next, i++)
  {
    std::cout << "[" << i << "] " << p->data << "  ";
  }
  std::cout << "\n";
}

void LinkList::delete_num_by_pos()
{
  if (length == 0)
  {
    std::cout << "链表是空的" << "\n";
    return;
  }
  std::cout << "请输入要删除的位置：" << "\n";
  int pos;
  std::cin >> pos;
  if (pos <= 0 || pos > length)
  {
    std::cout << "输入非法" << "\n";
    return;
  }
  Node *p = head;
  for (int i = 1; i < pos; i++)
  {
    p = p->next;
  }
  Node *del = p->next;
  p->next = del->next;
  delete del;
  length--;
  std::cout << "删除成功" << "\n";
  return;
}

void LinkList::delete_num_by_val()
{
  if (length == 0)
  {
    std::cout << "链表为空" << "\n";
    return;
  }
  std::cout << "请输入要删除的数字：" << "\n";
  int val;
  std::cin >> val;
  Node *p = head;
  bool has_del = false;
  while (p->next != nullptr)
  {
    if (p->next->data == val)
    {
      Node *del = p->next;
      p->next = del->next;
      delete del;
      length--;
      has_del = true;
    }
    else
    {
      p = p->next;
    }
  }
  if (has_del)
  {
    std::cout << "已删除全部为" << val << "的元素" << "\n";
  }
  else
  {
    std::cout << "链表没有该数字" << "\n";
  }
  return;
}

void LinkList::insert_head()
{
  int val;
  std::cout << "输入要插入的数字" << "\n";
  std::cin >> val;
  Node *new_node = new Node(val);
  new_node->next = head->next;
  head->next = new_node;
  length++;
  std::cout << "头插成功" << "\n";
  return;
}

void LinkList::insert_tail()
{
  int val;
  std::cout << "输入要插入的数字" << "\n";
  std::cin >> val;
  Node *p = head;
  while (p->next != nullptr)
  {
    p = p->next;
  }
  Node *new_node = new Node(val);
  p->next = new_node;
  length++;
  std::cout << "尾插成功" << "\n";
  return;
}

void LinkList::insert_pos()
{
  int val, pos;
  std::cout << "输入要插入的数字和位置" << "\n";
  std::cin >> val >> pos;
  if (pos <= 0 || pos > length + 1)
  {
    std::cout << "插入位置非法" << "\n";
    return;
  }
  Node *p = head;
  for (int i = 1; i < pos; i++)
  {
    p = p->next;
  }
  Node *new_node = new Node(val);
  new_node->next = p->next;
  p->next = new_node;
  length++;
  std::cout << "指定位置插入成功" << "\n";
}

void LinkList::save_file(const std::string &filename)
{
  std::ofstream out(filename);
  if (!out.is_open())
  {
    std::cout << "文件打开失败" << "\n";
    return;
  }
  out << length << "\n";
  Node *p = head->next;
  while (p != nullptr)
  {
    out << p->data << " ";
    p = p->next;
  }
  out.close();
  std::cout << "文件保存成功" << "\n";
  return;
}

void LinkList::load_file(const std::string &filename)
{
  std::ifstream in(filename);
  if (!in.is_open())
  {
    std::cout << "文件打开失败" << "\n";
    return;
  }
  int len;
  in >> len;
  if (len < 0)
  {
    std::cout << "文件数据非法" << "\n";
    return;
  }
  int num, cnt = 0;
  Node *p = head;
  for (int i = 0; i < len; i++)
  {
    if (!(in >> num))
    {
      std::cout << "文件元素不足，仅读取 " << cnt << " 个\n";
      break;
    }
    p->next = new Node(num);
    p = p->next;
    cnt++;
  }
  p->next = nullptr;
  length = cnt;
  in.close();
  std::cout << "文件读取成功" << "\n";
}
