/* @file intbox.cpp
 * @author Jack Moore
 * @brief Implementation file for IntBox class
 */



#include "intbox.h"



IntBox::IntBox(int s, int a) : m_boxsize(s)
{
  m_ints = new int[s];
  for(int i = 0; i < s; ++i)
    m_ints[i] = a;
}

IntBox::~IntBox()
{
  delete []m_ints;
  m_ints = NULL;
  m_boxsize = 0;
}

const IntBox& IntBox::operator=(const IntBox& rhs)
{
  if (this != &rhs)
  {
    delete []m_ints;
    m_ints = new int[rhs.m_boxsize];
    m_boxsize = rhs.m_boxsize;
    for (int i = 0; i < rhs.m_boxsize; ++i)
      m_ints[i] = rhs.m_ints[i];
  }
  return *this;
}

IntBox::IntBox(const IntBox& rhs) : m_boxsize(0)
{
  m_ints = NULL;
  *this = rhs;
}

void IntBox::set( int i, int x)
{
  if (i >= 0 && i < m_boxsize)
    m_ints[i] = x;
}

std::ostream& operator<< (std::ostream& out, const IntBox& box)
{
  out << "[ ";
  for (int i = 0; i < box.m_boxsize; ++i)
    out << box.m_ints[i] << ", ";
  out << ']';
  return out;
}
