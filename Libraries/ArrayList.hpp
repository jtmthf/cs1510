////////////////////////////////////////////////////////////////////// 
/// @file ArrayList.hpp
/// @author Jack Moore CLASS_SECTION
/// @brief Implementation of ArrayList data type. Similar in function to
/// std::vector
//////////////////////////////////////////////////////////////////////



#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP



#include <climits>



const int ARRAYLIST_GROWTH_RATE  = 2;



template <class T>
class ArrayList
{
  T *m_data;
  int m_size;
  int m_capacity;
public:

  //Constructors

  ArrayList();

  ArrayList(const ArrayList<T> & rhs);

  ArrayList(const int size, const T & value);

  ArrayList(const int size, const T *array);

  //Destructor

  ~ArrayList();

  //Assignment

  ArrayList<T> & operator =(const ArrayList<T> & rhs);

  //Capacity

  int size() {return m_size;}

  int max_size() {return INT_MAX;}

  void resize(const int size);

  int capacity() {return m_capacity;}

  bool empty() {if (m_size == 0) return true; else return false;}

  void reserve(const int size);

  void shrink_to_fit();

  //Element access

  T & operator [](const int index) {return m_data[index];}

  T & at(const int index);

  T & front() {return m_data[0];}

  T & back() {return m_data[m_size-1];}

  T* data() {return m_data;}

  //Modifiers

  void assign(const int size, const T & value);

  void assign(const int size, const T *begin);

  void push_back(const T & value);

  void pop_back() {--m_size;}

  void insert(const int index, const T & value);

  void insert(const int index, const int size, const T & value);

  void insert(const int index, const T *begin, const T *end);

  void erase(const int index);

  void erase(const int start, const int end);

  void swap(ArrayList<T> & x);

  void clear();
};

template <class T>
bool operator ==(const ArrayList<T> & lhs, const ArrayList<T> & rhs);

template <class T>
bool operator !=(const ArrayList<T> & lhs, const ArrayList<T> & rhs);

template <class T>
bool operator <(const ArrayList<T> & lhs, const ArrayList<T> & rhs);

template <class T>
bool operator >(const ArrayList<T> & lhs, const ArrayList<T> & rhs);

template <class T>
bool operator <=(const ArrayList<T> & lhs, const ArrayList<T> & rhs);

template <class T>
bool operator >=(const ArrayList<T> & lhs, const ArrayList<T> & rhs);



#include "ArrayList.cpp"



#endif