// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_JSON_HPP_
#define INCLUDE_JSON_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "student.hpp"

class list {
 public:
  list();
  void parsing_file(const std::string& path_file);
  std::string print();

  friend std::ostream& operator<<(std::ostream& os, const list& l);
 private:
  std::vector<student> all_students;
};

#endif // INCLUDE_JSON_HPP_
