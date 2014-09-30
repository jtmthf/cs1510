////////////////////////////////////////////////////////////////////// 
/// @file fishbomb.cpp
/// @author Jack Moore CLASS_SECTION
/// @brief fishbomb takes grids of fish as input and using that data determines
/// where to drop a bomb to catch the most fish, this bomb destroys the whole
/// row and column of where it is placed. A variable number of grids and grid
/// sizes may be used.  
//////////////////////////////////////////////////////////////////////



#include <iostream>



////////////////////////////////////////////////////////////////////// 
/// @fn create2DintArray
/// @brief Allocates a 2D array given a size
/// @pre width and height must be positive integers
/// @post A 2D array is allocated with undefined data
/// @param width how wide the array is
/// @param height how tall the array is
/// @return Returns an int** to an allocated 2D array
//////////////////////////////////////////////////////////////////////
int **create2DintArray(const int width, const int height);


////////////////////////////////////////////////////////////////////// 
/// @fn addData
/// @brief Fills array with integers using whitespace separated input from 
/// std::cin
/// @pre width and height must be size of passed array
/// @post Array is filled with data
/// @param array a 2D array
/// @param width the width of the array
/// @param height the height of the array
//////////////////////////////////////////////////////////////////////
void addData(int **const array, const int width, const int height);

////////////////////////////////////////////////////////////////////// 
/// @fn findBestLocation
/// @brief Finds x any y coordinate to the row and column with the greatest sum
/// @pre width and height must be size of passed array
/// @post x and y set to locations of grid with highest combined sum
/// @param array a 2D array
/// @param width the width of the array
/// @param height the height of the array
/// @param x pointer to be set with greatest combined column index
/// @param y pointer to be set with greatest combined row index
/// @return sum of the selected combined row and column
//////////////////////////////////////////////////////////////////////
int findBestLocation(int **array, const int width, const int height, 
  int *const x, int *const y);


////////////////////////////////////////////////////////////////////// 
/// @fn destroy2DintArray
/// @brief destroys a 2D array of a given width
/// @pre width must be width of the array
/// @post A 2D array is destroyed
/// @param array a 2D array
/// @param width how wide the array is
/// @return Returns NULL
//////////////////////////////////////////////////////////////////////
int **destroy2DintArray(int **const array, const int width);



int main()
{
  int numberOfGrids, width, height, x, y, sum;
  std::cin >> numberOfGrids;
  for (int i = 0; i < numberOfGrids; ++i)
  {
    std::cin >> width >> height;
    int ** grid = create2DintArray(width, height);
    addData(grid, width, height);
    sum = findBestLocation(grid, width, height, &x, &y);
    std::cout << '#' << i << ": (" << x << ',' << y << ") " << sum << std::endl;
    grid = destroy2DintArray(grid, width);
  }
  return 0;
}


int **create2DintArray(const int width, const int height)
{
  int **array = new int*[width];
  for (int i = 0; i < width; ++i)
  {
    array[i] = new int[height];
  }
  return array;
}


void addData(int **const array, const int width, const int height)
{
  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < width; ++j)
    {
      std::cin >> array[j][i];
    }
  }
  return;
}


int findBestLocation(int **array, const int width, const int height, 
  int *const x, int *const y)
{
  int tempSum, greatestSum = 0;

  // Temporarily save the total sum of each row and column
  int *columns = new int[width];
  int *rows = new int[height];
  for (int i = 0; i < width; ++i)
  {
    columns[i] = 0;
    for (int j = 0; j < height; ++j)
    {
      columns[i] += array[i][j];
    }
  }
  for (int i = 0; i < height; ++i)
  {
    rows[i] = 0;
    for (int j = 0; j < width; ++j)
    {
      rows[i] += array[j][i];
    }
  }

  // Sum up each combined row and column combo
  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < width; ++j)
    {
      tempSum = columns[j] + rows[i] - array[j][i];
      if (tempSum > greatestSum)
      {
        greatestSum = tempSum;
        *x = j;
        *y = i;
      }
    }
  }

  //Destroy arrays and return sum
  delete []columns;
  delete []rows;
  return greatestSum;
}


int **destroy2DintArray(int **const array, const int width)
{
  for (int i = 0; i < width; ++i)
  {
    delete []array[i];
  }
  delete []array;
  return NULL;
}
