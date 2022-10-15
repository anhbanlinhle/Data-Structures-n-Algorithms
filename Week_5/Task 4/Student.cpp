#include "Student.h"

Student::Student() {
  id = "0";
  name = "NA";
  cLass = "NA";
}

Student::~Student() {
}

Student::Student(std::string id, std::string name, std::string cLass) {
  this->id = id;
  this->name = name;
  this->cLass = cLass;
}

std::string Student::info() {
  return name + "," + cLass;
}

