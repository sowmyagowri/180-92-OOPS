//File Name: Practice Program 14.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Practice Program: 14
//Description: 
//Last Changed: Feb 12, 2017

#include <vector>
#include "png.h"

using namespace std;

int main(int argc, char *argv[])
{
  vector<vector<int>> image = readGrayscaleImage("blimp.png");
  int leftover = 0;
  for(int i=0; i<image.size(); i++)
  {
    for(int j=6-leftover; j<image[i].size(); j += 7)
    {
      image[i][j] = 0;
      leftover = image[i].size() - 1 - j;
    }
  }
  writeGrayscaleImage("out.png", image);
}
