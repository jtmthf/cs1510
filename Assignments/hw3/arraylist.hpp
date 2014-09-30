////////////////////////////////////////////////////////////////////// 
/// @file ArrayList.hpp
/// @author Jack Moore
/// @brief Implementation of ArrayList data type
//////////////////////////////////////////////////////////////////////



ArrayList<T>::~ArrayList()
{
  m_size = m_max = 0;
  delete []m_data;
  return;
}