//File Name: Practice Program 15.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 15
//Description: 
//Last Changed: Feb 12, 2017

#include <vector>
#include <cmath>
#include "png.h"

using namespace std;

/**
 * Computes the average of the neighbors of v[i][j]. There are
 * eight neighbors if the element is in the interior of the 2D array,
 * fewer if it is on a boundary. The element itself is not contained
 * in the average.
 */
double neighbor_average(const vector<vector<int>>& v, int i, int j)
{
    int count = 0;
    int sum = 0;
    int width = v[0].size();
    int height = v.size();


    for (int di = -1; di <= 1; di++)
       for (int dj = -1; dj <= 1; dj++)
          if ( (!((di==0) && (dj==0))) && ((i+di)>=0) && ((j+dj)>=0) && ((i+di)<height) && ((j+dj)<width) )
          {
            sum = sum + v[i+di][j+dj];
            count = count + 1;
          }

    return sum * 1.0 / count;
}

int main(int argc, char *argv[])
{
  vector<vector<int>> image = readGrayscaleImage("blimp.png");
  int width = image[0].size();
  int height = image.size();

  vector<vector<int>> image2(height);
  for (int i = 0; i < height; i++) {
     image2[i] = image[i];
     for (int j = 0; j < width; j++) {
        if (fabs(neighbor_average(image, i, j) - image[i][j]) > 10)
           image2[i][j] = 0;
        else
           image2[i][j] = 255;
     }
  }

  writeGrayscaleImage("out.png", image2);
}
