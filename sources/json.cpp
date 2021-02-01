// Copyright 2020 Your Name <your_email>

#include <json.hpp>
#include "student.hpp"
#include <string>



void list::parsing_file(const std::string& path_file)
{
  std::ifstream file(path_file, std::ifstream::in);
  if (!file) {
    throw std::string ("Wrong path: " + path_file);
  }
  nlohmann::json data;
  file >> data;
  if (!data.at("items").is_array()) {
    throw std::string ("Items is not array\n");
  }
  if (data.at("items").size() != data.at("_meta").at("count")) {
    throw std::string ("Items don't equal meta\n");
  }

  for (auto i = data.at("items").cbegin();i < data.at("items").cend();i++)
  {
    all_students.push_back(student(i.value()));
  }
}
std::string list::print()
{
  std::string string;
  string = "|name | group|  avg | debt | \n";
  for (auto i = all_students.cbegin(); i < all_students.cend(); i++) {
    string += i->print_str();
    string += "\n";
  }
  return string;
}

std::ostream& operator << (std::ostream& os, const list& l)
{
  os << "|name | group|  avg | debt | " << std::endl;
  for (size_t i = 0; i < l.all_students.size(); i++) {
    os << l.all_students[i] << std::endl;
  }
  return os;
}

list::list()
{}

