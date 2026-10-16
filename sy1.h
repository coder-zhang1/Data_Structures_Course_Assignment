#ifndef SY1_H
#define SY1_H

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

  void input_num(SqList &L);
  void delete_num(SqList &L);
  void output_array(SqList &L);
  void insert_num(SqList &L, int pos);

  void save_file(const char *filename);
  void load_file(const char *filename);
};

#endif