////////////////////////////////////////////////////////////////////// 
/// @file ArrayList.hpp
/// @author Jack Moore
/// @brief Implementation of ArrayList data type
//////////////////////////////////////////////////////////////////////



const int ARRAYLIST_GROWTH_RATE = 2;



template <typename T>
ArrayList<T>::~ArrayList()
{
  m_size = m_max = 0;
  if (m_data != NULL)
    delete []m_data;
  m_data = NULL;
  return;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  m_size = rhs.m_size;
  m_max = rhs.m_max;
  if (m_data != NULL)
    delete []m_data;
  m_data = new T[m_max];
  for (int i = 0; i < m_size; ++i)
    m_data[i] = rhs.m_data[i];
  return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  if (this != &cpy)
  {
    m_data = NULL;
    *this = cpy;
  }
}

template <typename T>
int ArrayList<T>::size() const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
  if (m_size > 0)
    return m_data[0];
  else
  {  
    std::cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)"
              << std::endl;
    return m_errobj;
  }
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
  if (i < m_size && i >= 0)
    return m_data[i];
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST.[]!!  (index is out of bounds)"
              << std::endl;
    return m_errobj;
  }
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
  if (i < m_size && i >= 0)
    return m_data[i];
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST.[]!!  (index is out of bounds)"
              << std::endl;
    return m_errobj;
  }
}

template <typename T>
int ArrayList<T>::find(const T& x)
{
  int found = -1;
  int i = 0;
  while (i < m_size)
  { 
    if (m_data[i] == x)
    {
      found = i;
      i = m_size;
    }
    i++;
  }
  return found;
}

template <typename T>
void ArrayList<T>::clear()
{
  if (m_data != NULL)
    delete []m_data;
  m_max = m_size = 0;
  m_data = NULL;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  if (m_size == m_max)
  {
    if (m_data != NULL)
      m_max *= ARRAYLIST_GROWTH_RATE;
    else
      m_max = 1;
    T *tempData = new T[m_max];
    for (int i = 0; i < m_size; ++i)
      tempData[i] = m_data[i];
    if (m_data != NULL)
      delete []m_data;
    m_data = tempData;
  }
  m_data[m_size++] = x;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  // Bounds checking
  if (i >= 0 && i <= m_size)
  {
    // If a size increase is required
    if (m_size == m_max)
    {
      if (m_data != NULL)
        m_max *= ARRAYLIST_GROWTH_RATE;
      else
        m_max = 1;
      T *tempData = new T[m_max];
      for (int c = 0; c < i; ++c)
        tempData[c] = m_data[c];
      tempData[i] = x;
      m_size++;
      for (int c = i+1; c < m_size; ++c)
        tempData[c] = m_data[c-1];
      if (m_data != NULL)
        delete []m_data;
      m_data = tempData;
    }
    else
    {
      if (m_data == NULL)
      {
        m_max = 1;
        m_data = new T;
      }
      for (int c = m_size; c > i; --c)
        m_data[c] = m_data[c-1];
      m_data[i] = x;
      m_size++;
    }
  }
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST.insert()!!  (index out of "
                 "bounds)" << std::endl;
  }
}


template <typename T>
void ArrayList<T>::remove(int i)
{
  if (i >= 0 && i < m_size)
  {
    if (m_max / 4 > --m_size)
    {
      m_max /= ARRAYLIST_GROWTH_RATE;
      T *tempData = new T[m_max];
      for (int c = 0; c < i; ++c)
        tempData[c] = m_data[c];
      //Skip removed element
      for (int c = i; c < m_size; ++c)
        tempData[c] = m_data[c+1];
      if (m_data != NULL)
        delete []m_data;
      m_data = tempData;
    }
    // For when no realloc is needed
    else
    {
      for (int c = i; c < m_size; ++c)
        m_data[c] = m_data[c+1];
    }
  }
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST.remove()!!  (index out of "
                 "bounds)" << std::endl;
  }
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if (i >= 0 && i < m_size && k >= 0 && k < m_size)
  {
    T temp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = temp;
  }
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST.swap()!!  (index out of "
                 "bounds)" << std::endl;
  }
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  for (int i = 0; i < alist.size(); ++i)
    insert_back(alist[i]);
}

template <typename T>
void ArrayList<T>::purge()
{
  for (int i = 0; i < m_size-1; ++i)
  {
    for (int j = i+1; j < m_size; ++j)
    {
      if (m_data[i] == m_data[j])
        remove(j);
    }
  } 
}
