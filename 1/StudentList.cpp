#include "StudentList.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

void StudentList::menu()
{
  int op;
  bool running = true;
  while (running)
  {
    system("cls");
    std::cout << "1.录入学生信息" << "\n";
    std::cout << "2.按学号插入学生" << "\n";
    std::cout << "3.按学号删除学生" << "\n";
    std::cout << "4.输出全部学生" << "\n";
    std::cout << "5.按学号查找学生" << "\n";
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
      input_student();
      break;
    case 2:
      insert_student();
      break;
    case 3:
      delete_student();
      break;
    case 4:
      output_student();
      break;
    case 5:
      search_student();
      break;
    case 0:
      std::cout << "程序退出成功\n";
      running = false;
      continue;
    default:
      std::cout << "输入非法\n";
    }
    std::cout << "\n按回车继续...";
    std::cin.ignore(10000, '\n');
    std::cin.get();
  }
}

StudentList::StudentList()
{
  data = new Student[100];
  length = 0;
  capacity = 100;
}

StudentList::~StudentList()
{
  if (data != nullptr)
  {
    delete[] data;
    data = nullptr;
  }
}

int StudentList::binary_search(const std::string &id) const
{
  int left = 0, right = length - 1;
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (data[mid].id == id)
    {
      return mid;
    }
    else if (data[mid].id < id)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return left;
}

void StudentList::expand()
{
  capacity += 100;
  Student *p = new Student[capacity];
  for (int i = 0; i < length; i++)
  {
    p[i] = data[i];
  }
  delete[] data;
  data = p;
}

void StudentList::sort_by_id()
{
  for (int i = 1; i < length; i++)
  {
    Student key = data[i];
    int j = i - 1;
    while (j >= 0 && data[j].id > key.id)
    {
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = key;
  }
}

void StudentList::input_student()
{
  int n;
  std::cout << "输入录入学生数量：\n";
  if (!(std::cin >> n) || n <= 0)
  {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "输入非法\n";
    return;
  }
  std::cout << "请依次输入 学号 姓名 学院 专业 班级 性别 年龄\n";
  for (int k = 0; k < n; k++)
  {
    Student s;
    std::cin >> s.id >> s.name >> s.college >> s.major >> s.cls >> s.sex >> s.age;
    int pos = binary_search(s.id);
    if (pos < length && data[pos].id == s.id)
    {
      std::cout << "学号 " << s.id << " 已存在，跳过\n";
      continue;
    }
    if (length >= capacity)
    {
      expand();
    }
    for (int i = length; i > pos; i--)
    {
      data[i] = data[i - 1];
    }
    data[pos] = s;
    length++;
  }
  std::cout << "录入完毕\n";
  output_student();
}

void StudentList::insert_student()
{
  Student s;
  std::cout << "输入 学号 姓名 学院 专业 班级 性别 年龄\n";
  std::cin >> s.id >> s.name >> s.college >> s.major >> s.cls >> s.sex >> s.age;
  int pos = binary_search(s.id);
  if (pos < length && data[pos].id == s.id)
  {
    std::cout << "该学号已存在\n";
    return;
  }
  if (length >= capacity)
  {
    expand();
  }
  for (int i = length; i > pos; i--)
  {
    data[i] = data[i - 1];
  }
  data[pos] = s;
  length++;
  std::cout << "插入成功\n";
}

void StudentList::delete_student()
{
  if (length == 0)
  {
    std::cout << "无学生记录\n";
    return;
  }
  std::string id;
  std::cout << "输入要删除的学号：\n";
  std::cin >> id;
  int pos = binary_search(id);
  if (pos >= length || data[pos].id != id)
  {
    std::cout << "未找到该学号\n";
    return;
  }
  for (int i = pos; i < length - 1; i++)
  {
    data[i] = data[i + 1];
  }
  length--;
  std::cout << "删除成功\n";
}

void StudentList::search_student()
{
  if (length == 0)
  {
    std::cout << "无学生记录\n";
    return;
  }
  std::string id;
  std::cout << "输入要查找的学号：\n";
  std::cin >> id;
  int pos = binary_search(id);
  if (pos < length && data[pos].id == id)
  {
    std::cout << data[pos].id << " " << data[pos].name << " " << data[pos].college << " "
              << data[pos].major << " " << data[pos].cls << " " << data[pos].sex << " "
              << data[pos].age << "\n";
  }
  else
  {
    std::cout << "未找到该学号\n";
  }
}

void StudentList::output_student()
{
  if (length == 0)
  {
    std::cout << "无学生记录\n";
    return;
  }
  std::cout << "学号 姓名 学院 专业 班级 性别 年龄\n";
  for (int i = 0; i < length; i++)
  {
    std::cout << data[i].id << " " << data[i].name << " " << data[i].college << " "
              << data[i].major << " " << data[i].cls << " " << data[i].sex << " "
              << data[i].age << "\n";
  }
}

void StudentList::save_file(const std::string &filename)
{
  std::ofstream out(filename);
  if (!out.is_open())
  {
    std::cout << "文件打开失败\n";
    return;
  }
  for (int i = 0; i < length; i++)
  {
    out << data[i].id << " " << data[i].name << " " << data[i].college << " "
        << data[i].major << " " << data[i].cls << " " << data[i].sex << " "
        << data[i].age << "\n";
  }
  out.close();
  std::cout << "文件保存成功\n";
}

void StudentList::load_file(const std::string &filename)
{
  std::ifstream in(filename);
  if (!in.is_open())
  {
    std::cout << "文件打开失败\n";
    return;
  }
  Student s;
  int cnt = 0;
  while (in >> s.id >> s.name >> s.college >> s.major >> s.cls >> s.sex >> s.age)
  {
    if (cnt >= capacity)
    {
      expand();
    }
    data[cnt++] = s;
  }
  length = cnt;
  sort_by_id();
  in.close();
  std::cout << "文件读取成功\n";
}
