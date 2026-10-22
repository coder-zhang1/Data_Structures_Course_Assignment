#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>

struct Student
{
  std::string id;
  std::string name;
  std::string college;
  std::string major;
  std::string cls;
  std::string sex;
  int age;
};

class StudentList
{
private:
  Student *data;
  int length;
  int capacity;
  int binary_search(const std::string &id) const;
  void expand();
  void sort_by_id();

public:
  StudentList();
  ~StudentList();

  void input_student();
  void insert_student();
  void delete_student();
  void search_student();
  void output_student();

  void save_file(const std::string &filename);
  void load_file(const std::string &filename);

  void menu();

  StudentList(const StudentList &) = delete;
  StudentList &operator=(const StudentList &) = delete;
};

#endif
