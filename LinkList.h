#ifndef LINKLIST_H
#define LINKLIST_H

#include<string>

struct Node
{
  int data;
  Node *next;
  Node(int val);
};
class LinkList
{
private:
  Node *head;
  int length;

public:
  LinkList();
  ~LinkList();

  void input_num();
  void append_num();
  void clear_linklist();
  void delete_num_by_pos();
  void delete_num_by_val();
  void insert_head();
  void insert_tail();
  void insert_pos();
  void output_linklist();

  void save_file(const std::string &filename);
  void load_file(const std::string &filename);

  void menu();

  LinkList(const LinkList &) = delete;            // 禁用拷贝构造
  LinkList &operator=(const LinkList &) = delete; // 禁用拷贝赋值
};

#endif