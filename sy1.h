#ifndef SY1_H
#define SY1_H

// 数组结构体
typedef struct
{
  int *data;    // 动态数组首地址
  int length;   // 有效元素数量
  int capacity; // 总容量
} SqList;

// 5个基本操作和两个文件操作
void init_array(SqList &L);
void input_num(SqList &L);
void insert_num(SqList &L, int &pos, int &num);
void delete_num(SqList &L, int &pos);
void output_array(SqList &L);
void save_file(SqList &L, const char *filename);
void load_file(SqList &L, const char *filename);

#endif