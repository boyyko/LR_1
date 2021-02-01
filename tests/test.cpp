// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include <fstream>
#include <student.hpp>
#include <json.hpp>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Table_output, table_test) {
  std::string file_path = "../files/main.json";
  list l;
  l.parsing_file(file_path);
  std::stringstream out;
  out << l << std::endl;
  std:: string true_table =
      "|name | group|  avg | debt | \n"
      "| Ivanov Petr | 1 | 4.25 | nullptr | \n"
      "| Sidorov Ivan | 31 | 4 | C++ | \n"
      "| Pertov Nikita | IU8-31 | 3.5 | 3 | \n\n";
  EXPECT_EQ(out.str(), true_table);
}


TEST(File_path, mistake_file_path) {
  std::string error1;
  std::string check =
      "Wrong path: ../files/Main.json";
  try {
    std::string file_path = "../files/Main.json";
    list l;
    l.parsing_file(file_path);
    std::stringstream out;
    out << l << std::endl;
  } catch (std::string ERROR){
    error1 = ERROR;
    std::cout << "ERROR: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

TEST(Value_input, test_debt) {
  std::string error1;
  std::string check =
      "Debt is not null, string, array\n";
  try {
    std::string file_path = "../files/debt.json";
    list l;
    l.parsing_file(file_path);
    std::stringstream out;
    out << l << std::endl;
  } catch (std::string ERROR){
    error1 = ERROR;
    std::cout << "ERROR: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1, check);
}

TEST(Value_input, test_name) {
  std::string error1;
  std::string check =
      "Name is not string\n";
  try {
    std::string file_path = "../files/name.json";
    list l;
    l.parsing_file(file_path);
    std::stringstream out;
    out << l << std::endl;
  } catch (std::string ERROR){
    error1 = ERROR;
    std::cout << "ERROR: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

TEST(Value_input, test_group) {
  std::string error1;
  std::string check =
      "Group is not string or int\n";
  try {
    std::string file_path = "../files/group.json";
    list l;
    l.parsing_file(file_path);
    std::stringstream out;
    out << l << std::endl;
  } catch (std::string ERROR){
    error1 = ERROR;
    std::cout << "ERROR: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

TEST(Value_input, test_avg) {
  std::string error1;
  std::string check =
      "Average is not null, string, float, int\n";
  try {
    std::string file_path = "../files/avg.json";
    list l;
    l.parsing_file(file_path);
    std::stringstream out;
    out << l << std::endl;
  } catch (std::string ERROR){
    error1 = ERROR;
    std::cout << "ERROR: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

TEST(Value_input, test_meta) {
  std::string error1;
  std::string check =
      "Items don't equal meta\n";
  try {
    std::string file_path = "../files/meta.json";
    list l;
    l.parsing_file(file_path);
    std::stringstream out;
    out << l << std::endl;
  } catch (std::string ERROR){
    error1 = ERROR;
    std::cout << "ERROR: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}

TEST(Value_input, test_items) {
  std::string error1;
  std::string check =
      "Items is not array\n";
  try {
    std::string file_path = "../files/item.json";
    list l;
    l.parsing_file(file_path);
    std::stringstream out;
    out << l << std::endl;
  } catch (std::string ERROR){
    error1 = ERROR;
    std::cout << "ERROR: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1,check);
}
