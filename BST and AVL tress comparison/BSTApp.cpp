/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <time.h>
#include <chrono>

#include "BinarySearchTree.h"
#include "AvlTree.h"

using namespace std;
using namespace std::chrono;

const bool DUMP = false;

void testBST();
void testAVL();

void buildTree(BinarySearchTree& tree,
               int size);

void searchTree(BinarySearchTree& tree,
                int size);

void output_tree_stats(BinarySearchTree& tree);

string commafy(long n);

// Number of data items to test.
int SIZES[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};

/**
 * Main.
 */
int main( )
{
    testBST();
    testAVL();
}

/**
 * Run the test with a binary search tree.
 */
void testBST()
{
    cout << endl;
    cout << "**********************" << endl;
    cout << "* BINARY SEARCH TREE *" << endl;
    cout << "**********************" << endl;

    BinarySearchTree  tree;

    for (int n : SIZES)
    {
        cout << endl << "N = " << commafy(n) << endl << endl;
        cout << "---------" << endl;
        cout << "INSERTION" << endl;
        cout << "---------" << endl << endl;
        cout << setw(20) << "PROBE COUNTS" << setw(20) << "COMPARE COUNTS"
             << setw(35) << "ELAPSED TIME (in microseconds)" << endl;

        tree.reset();
        buildTree(tree, n);

        cout << "------" << endl;
        cout << "SEARCH" << endl;
        cout << "------" << endl << endl;
        cout << setw(20) <<"PROBE COUNTS" << setw(20) << "COMPARE COUNTS"
             << setw(35) << "ELAPSED TIME (in microseconds)" << endl;

        tree.reset();
        searchTree(tree, n);
    }
}

/**
 * Run the test with an AVL tree.
 */
void testAVL()
{
    cout << endl;
    cout << "************" << endl;
    cout << "* AVL TREE *" << endl;
    cout << "************" << endl;

    AvlTree tree;

    for (int n : SIZES)
    {
        cout << endl << "N = " << commafy(n) << endl << endl;
        cout << "---------" << endl;
        cout << "INSERTION" << endl;
        cout << "---------" << endl << endl;
        cout << setw(20) << "PROBE COUNTS " << setw(20) << "COMPARE COUNTS"
             << setw(35) << "ELAPSED TIME (in microseconds)" << endl;

        tree.reset();
        buildTree(tree, n);

        cout << "------" << endl;
        cout << "SEARCH" << endl;
        cout << "------" << endl << endl;
        cout << setw(20) << "PROBE COUNTS" << setw(20) << "COMPARE COUNTS"
             << setw(35) << "ELAPSED TIME (in microseconds)" << endl;

        tree.reset();
        searchTree(tree, n);
    }
}

/**
 * Build a binary search tree containing unique random integer data items.
 * @param tree the tree to make.
 * @param maxNodes the maximum number of nodes to generate.
 */
void buildTree(BinarySearchTree& tree, int input_size)
{
    srand(time(NULL));  // seed the random number generator

    for (int i = 1; i < input_size; i++)
    {
        int r = rand() % input_size;
        tree.insert(r);
    }

    output_tree_stats(tree);
}

/**
 * Dismantle a binary tree.
 * @param tree the tree to test.
 * @param checker the binary tree checker to use.
 * @param printer the binary tree printer to use.
 */
void searchTree(BinarySearchTree& tree, int input_size)
{
    srand(time(NULL));  // seed the random number generator

    for (int i = 1; i < input_size; i++)
    {
        int r = rand() % input_size;

        steady_clock::time_point start_time = steady_clock::now();

        tree.contains(r);

        steady_clock::time_point end_time = steady_clock::now();
        long msec = duration_cast<microseconds>(end_time - start_time).count();
        tree.increment_elapsed_time(msec);
    }

    output_tree_stats(tree);
}

/**
 * Output BST or AVL tree's probe and comparison counts and elapsed time.
 * @param tree whose statistics needs to be printed.
 */
void output_tree_stats(BinarySearchTree& tree)
{
    cout << setw(20) << commafy(tree.get_probe_count());
    cout << setw(20) << commafy(tree.get_comparison_count());
    cout << setw(20) << commafy(tree.get_elapsed_time());
    cout << endl << endl;
}

/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
