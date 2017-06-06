//File Name: MapMaker.cpp
//Author: Sowmya Gowrishankar
//Email Address: sowmya.gowrishankar@sjsu.edu
//Assignment Number: 7
//Description: 
//Last Changed: Mar 17, 2017

#include <iostream>
#include <fstream>
#include <string>
#include "Coordinate.h"
#include "Node.h"
#include "SortedLinkedList.h"

using namespace std;

const string BOUNDARY_FILE_NAME = "boundary-data.csv";
const string CITY_FILE_NAME     = "city-data.csv";

void do_boundary(ifstream& input, SortedLinkedList& list);
void do_cities(ifstream& input, SortedLinkedList& list);

/**
 * The main. Read the boundary data and city data files.
 * Print a map of the U.S. boundary. Print a map of the U.S. with cities.
 */
int main()
{
    ifstream input;         // input stream
    SortedLinkedList list;  // sorted linked list of Node objects

    // Open the boundary data file.
    //input.open(BOUNDARY_FILE_NAME);
    input.open("boundary-data.csv");
    if (input.fail())
    {
        cout << "Failed to open " << BOUNDARY_FILE_NAME << endl;
        return -1;
    }

    // Process the U.S. boundary.
    do_boundary(input, list);
    input.close();

    cout << endl;

    // Open the city data file.
    //input.open(CITY_FILE_NAME);
    input.open("city-data.csv");
    if (input.fail())
    {
        cout << "Failed to open " << CITY_FILE_NAME << endl;
        return -1;
    }

    // Process the U.S. cities.
    do_cities(input, list);
    input.close();

    cout << endl << "Done!" << endl;
    return 0;
}

/**
 * Read and process the boundary data, then print the boundary map.
 */
void do_boundary(ifstream& input, SortedLinkedList& list)
{
    Coordinate coordinate;

    // Loop to input each boundary coordinate
    // and insert it into the sorted linked list.
    while (!input.eof())
    {
        input >> coordinate;
        list.insert(new Node(coordinate));
    }

    // Print the boundary map.
    cout << "=============" << endl;
    cout << "U.S. boundary" << endl;
    cout << "=============" << endl << endl;
    cout << list << endl;
}

/**
 * Read and process the city data, then print the map with cities.
 */
void do_cities(ifstream& input, SortedLinkedList& list)
{
    City city;

    // Loop to input each city and insert it into the sorted linked list.
    // The city nodes will be merged with the boundary coordinate nodes.
    while (!input.eof())
    {
        input >> city;
        list.insert(new Node(city));
    }

    // Print the city map.
    cout << "===========" << endl;
    cout << "U.S. Cities" << endl;
    cout << "===========" << endl << endl;
    cout << list << endl;
}
