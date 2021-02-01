//
// Created by ubuntu on 28.01.2021.
//

#include <student.hpp>
using nlohmann::json;

void student::from_json_file(const json& j)
{
  name  = get_name(j.at("name"));
  group = get_group(j.at("group"));
  avg   = get_avg(j.at("avg"));
  debt  = get_debt(j.at("debt"));
}

auto student::get_name(const json& j) -> std::string
{
  if (j.is_string()) {
    return j.get<std::string>();
  }
  else throw (std::string("Name is not string\n"));
}

auto student::get_avg(const json& j) -> std::any
{
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else if (j.is_number_float())
    return j.get<float>();
  else if (j.is_number_integer())
    return j.get<int>();
  else
    throw (std::string("Average is not null, string, float, int\n"));
}

auto student::get_debt(const json& j) -> std::any
{
  if (j.is_null())
    return nullptr;
  else if (j.is_string())
    return j.get<std::string>();
  else if (j.is_array())
    return j.get<std::vector<std::string>>();
  else
    throw (std::string("Debt is not null, string, array\n"));
}
auto student::get_group(const json& j) -> std::any
{
  if (j.is_string())
    return j.get<std::string>();
  else if (j.is_number_integer())
    return j.get<int>();
  else throw (std::string("Group is not string or int\n"));
}

std::string student::print_str() const
{
  std::string str;
  str = "| " + name +" | " + group_str() +" | "
        + avg_str() +" | " + debt_str() + " | ";
  return str;
}

std::string student::group_str() const
{
  if (group.type() == typeid(int))
    return std::to_string(std::any_cast<int>(group));
  else if (group.type() == typeid(float))
  {
    std::string tmp = std::to_string(std::any_cast<float>(group));
    while (tmp.at(tmp.size()-1) == '0')
      tmp.pop_back();
    return tmp;
  } else {
    return std::any_cast<std::string>(group);
  }
}

std::string student::debt_str() const
{
  if (debt.type() == typeid(int))
    return std::to_string(std::any_cast<int>(debt));
  else if (debt.type() == typeid(std::vector<std::string>))
  {
    int size;
    size = std::any_cast<std::vector<std::string>>(debt).size();
    return std::to_string(size);
  } else {
    if (debt.type() == typeid(std::nullptr_t))
    {
      return "nullptr";
    } else {
      return std::any_cast<std::string>(debt);
    }
  }
}

std::string student::avg_str() const
{
  if (avg.type() == typeid(int))
    return std::to_string(std::any_cast<int>(avg));
  else if (avg.type() == typeid(float_t))
  {
    std::string tmp = std::to_string(std::any_cast<float>(avg));
    while (tmp.at(tmp.size()-1) == '0')
      tmp.pop_back();
    return tmp;
  } else {
    return std::any_cast<std::string>(avg);
  }
}

std::ostream& operator<<(std::ostream& os, const student& s)
{
  os << "| " << s.name <<" | " << s.group_str() <<" | "
     << s.avg_str() <<" | " << s.debt_str() << " | ";
  return os;
}

student::student(const json& j)
{
  from_json_file(j);
}
