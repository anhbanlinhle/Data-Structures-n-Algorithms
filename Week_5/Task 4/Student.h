#ifndef STUDENT_H
#define STUDENT_H
#include "Libs.h"

class Student {
  public:
    std::string id;
    std::string name;
    std::string cLass;

    Student();
    ~Student();

    Student(std::string id, std::string name, std::string cLass);
    std::string info();
};

#endif