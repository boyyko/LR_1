//
// Created by ubuntu on 28.01.2021.
//

#ifndef TEMPLATE_STUDENT_HPP
#define TEMPLATE_STUDENT_HPP


#include <iostream>
#include <any>
#include <string>
#include "nlohmann/json.hpp"

using namespace nlohmann;

class student
{
 public:
  student(const json& j);

  auto get_name(const json& j) -> std::string;
  auto get_avg(const json& j) -> std::any;
  auto get_debt(const json& j) -> std::any;
  auto get_group(const json& j) -> std::any;
  void from_json_file(const json& j);

  std::string print_str() const;
  std::string group_str() const;
  std::string debt_str() const;
  std::string avg_str() const;

  friend std::ostream& operator << (std::ostream& os, const student& s);

 private:
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;

};


#endif  // TEMPLATE_STUDENT_HPP
