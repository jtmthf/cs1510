////////////////////////////////////////////////////////////////////// 
/// @file hw3tester.cpp
/// @author Jack Moore
/// @brief Testing the ArrayList data type
//////////////////////////////////////////////////////////////////////


#include "arraylist.h"
#include <iostream>
#include <sstream>


int main()
{

  //default constructor
  ArrayList<int> array;
  if (array.size() != 0)
    std::cout << "ERROR: ArrayList() size is not equal to 0" << std::endl
              << "size is equal to: " << array.size();
  if (array.max() != 0)
    std::cout << "ERROR: ArrayList() max is not equal to 0" << std::endl
              << "max is equal to: " << array.max();
  std::stringstream ss;
  ss << array;
  if (ss.str() != "[ ]")
    std::cout << "ERROR: ArrayList() output is not equal to [ ]" << std::endl
              << "output is equal to: " << array;


  return 0;
}