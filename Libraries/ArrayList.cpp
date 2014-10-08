////////////////////////////////////////////////////////////////////// 
/// @file ArrayList.tpp
/// @author Jack Moore CLASS_SECTION
/// @brief Implementation of ArrayList data type. Similar in function to
/// std::vector
//////////////////////////////////////////////////////////////////////



#include "ArrayList.hpp"
#include <cstring>



template <class T>
ArrayList<T>::ArrayList() : m_data(NULL), m_size(0), m_capacity(0) {}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T> & rhs)
{
  *this = rhs;
  return;
}

template <class T>
ArrayList<T>::ArrayList(const int size, const T & value)
{
  m_data = new T[size];
  for (int i = 0; i < size; ++i)
    m_data[i] = value;
  return;
}

template <class T>
ArrayList<T>::ArrayList(const int size, const T *array)
{
  m_data = new T[size];
  for (int i = 0; i < size; ++i)
    m_data[i] = array[i];
  return;
}

template <class T>
ArrayList<T>::~ArrayList()
{
  delete []m_data;
  return;
}

template <class T>
ArrayList<T>::ArrayList<T> & operator =(const ArrayList<T> & rhs)
{
  m_size = rhs.m_size;
  m_capacity = rhs.m_capacity;
  m_data = new T[m_capacity];
  memcpy(m_data, rhs.m_data, sizeof(T)*m_size);
  return *this;
}

template <class T>
void ArrayList<T>::resize(const int size)
{
  if (size > m_size && size <= m_capacity)
    m_size = size;
  else if (size > m_capacity)
  {
    m_capacity = size;
    T *tempData = new T[m_capacity];
    memcpy(tempData, m_data, sizeof(T)*m_size);
    m_size = size;
    delete []m_data;
    m_data = tempData;
  }
  else
    m_size = size;
  return;
}

template <class T>
void ArrayList<T>::reserve(const int size)
{
  if (size > m_capacity)
  {
    m_capacity = size;
    T *tempData = new T[m_capacity];
    memcpy(tempData, m_data, sizeof(T)*m_size);
    delete []m_data;
    m_data = tempData;
  }
  return;
}

template <class T>
void ArrayList<T>::shrink_to_fit()
{
  if (m_capacity > m_size)
  {
    T *tempData = new T[m_size];
    memcpy(tempData, m_data, sizeof(T)*m_size);
    delete []m_data;
    m_data = tempData;
    m_capacity = m_size;
  }
  return;
}

template <class T>
T & ArrayList<T>::at(const int index)
{
  if (index > 0 && index < m_size)
    return m_data[index];
  else
    return NULL;
}

template <class T>
void ArrayList<T>::assign(const int size, const T & value)
{
  if (size + m_size > m_capacity)
  {
    m_capacity *= ARRAYLIST_GROWTH_RATE;
    T *tempData = new T[m_capacity];
    memcpy(tempData, m_data, sizeof(T)*m_size);
    delete []m_data;
    m_data = tempData;
  }
  for (int i = 0; i < size; ++i)
    m_data[m_size+i] = value;
  m_size += size;
  return;
}

template <class T>
void ArrayList<T>::assign(const int size, const T *begin)
{
  if (size + m_size > m_capacity)
  {
    m_capacity *= ARRAYLIST_GROWTH_RATE;
    T *tempData = new T[m_capacity];
    memcpy(tempData, m_data, sizeof(T)*m_size);
    delete []m_data;
    m_data = tempData;
  }
  for (int i = 0; i < size; ++i)
    m_data[m_size+i] = begin[i];
  m_size += size;
  return;
}

template <class T>
void ArrayList<T>::push_back(const T & value)
{
  if (m_size == m_capacity)
  {
    m_capacity *= ARRAYLIST_GROWTH_RATE;
    T *tempData = new T[m_capacity];
    memcpy(tempData, m_data, sizeof(T)*m_size);
    delete []m_data;
    m_data = tempData;
  }
  m_data[m_size++] = value;
  return;
}

template <class T>
void ArrayList<T>::insert(const int index, const T & value)
{
  // If insert is at the end of the array and no capacity increase is needed
  if (index == m_size - 1 && m_size != m_capacity)
    m_data[m_size++] = value;
  // If a size increase is needed
  else if (m_size == m_capacity)
    m_capacity *= ARRAYLIST_GROWTH_RATE;
  // Default insert operation
  if (index < m_size)
  {
    T *tempData = new T[m_capacity];
    memcpy(tempData, m_data, sizeof(T)*index);
    tempData[index] = value;
    memcpy(tempData+index+1, m_data+index, sizeof(T)*(m_size-index));
    delete []m_data;
    m_data = tempData;
    ++m_size;
  }
  return;
}

template <class T>
void ArrayList<T>::insert(const int index, const int size, const T & value);
{
  // If insert is at the end of the array and no capacity increase is needed
  if (index == m_size - 1 && m_size + size <= m_capacity)
  {
    for (int i = 0; i < size; ++i)
      m_data[m_size + i] = value;
    m_size += size;
  }
  // If a size increase is needed
  else if (m_size + size > m_capacity)
  {
    do {
      m_capacity *= ARRAYLIST_GROWTH_RATE;
    } while (m_size + size > m_capacity);
  }
  // Default insert operation
  if (index < m_size - size)
}
