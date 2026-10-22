#ifndef SY1_H
#define SY1_H

#include <string>
// 数组结构体

class SqList
{
private:
  int *data;
  int length;
  int capacity;

public:
  SqList();
  ~SqList();

  void input_num();
  void delete_num_by_val();
  void delete_num_by_pos();
  void output_array();
  void insert_num();
  void append_num();

  void save_file(const std::string &filename);
  void load_file(const std::string &filename);

  void menu();

  SqList(const SqList &) = delete;
  SqList &operator=(const SqList &) = delete;
};

#endif