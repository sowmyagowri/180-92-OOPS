#include <string>
#include "BinarySearchTree.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() : root(nullptr)
{
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree()
{
    clear();
}

/**
 * @return pointer to the root of the tree.
 */
BinaryNode *BinarySearchTree::getRoot() const
{
    return root;
}

/**
 * Public method to return the height of a subtree.
 * @return the height.
 */
int BinarySearchTree::height() const
{
    return height(root);
}

/**
 * Protected method to compute the height of a subtree.
 * @param ptr pointer to the root node of the subtree.
 * @return the height.
 */
int BinarySearchTree::height(const BinaryNode *ptr) const
{
    return ptr == nullptr ? -1
                          : 1 + max(height(ptr->left),
                                    height(ptr->right));
}

/**
 * Public method to empty a subtree.
 */
void BinarySearchTree::clear()
{
    clear(root);
}

/**
 * Private method to empty a subtree.
 * @param ptr pointer to the root node of the subtree.
 */
void BinarySearchTree::clear(BinaryNode* &ptr)
{
    if (ptr != nullptr)
    {
        clear(ptr->left);
        clear(ptr->right);
        delete ptr;
        ptr = nullptr;
    }
}

/**
 * Public method to search for a data item in the tree.
 * @param data the data to search for.
 * @return true if and only if data is in the tree.
 */
bool BinarySearchTree::contains(const int data)
{
    return contains(data, root);
}

/**
 * Private method to search for a data item in a subtree.
 * @param data the data to search for.
 * @param ptr pointer to the root node of the subtree.
 * @return true if and only if data is in the tree.
 */
bool BinarySearchTree::contains(const int data, BinaryNode *ptr)
{
    comparison_count++;
    while (ptr != nullptr)
    {
        comparison_count++;
        if (data < ptr->data)
        {
            probe_count++;
            ptr = ptr->left;
        }
        else if (data > ptr->data)
        {
            probe_count++;
            ptr = ptr->right;
        }
        else
        {
            return true;  // found
        }
    }

    return false;         // not found
}

/**
 * Public method to insert a data item into a subtree
 * and set the new root of the subtree.
 * @param data the data to insert into the tree.
 */
void BinarySearchTree::insert(const int data)
{
    steady_clock::time_point start_time = steady_clock::now();

    insert(data, root);

    steady_clock::time_point end_time = steady_clock::now();
    long msec = duration_cast<microseconds>(end_time - start_time).count();
    this->increment_elapsed_time(msec);
}

/**
 * Protected method to insert a data item into a subtree
 * and set the new root of the subtree.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
void BinarySearchTree::insert(const int data, BinaryNode* &ptr)
{
    probe_count++;
    if (ptr == nullptr)
    {
        ptr = new BinaryNode(data);
    }
    else
    {
        comparison_count++;
        if (data == ptr->data)
            return;
        else
        {
            probe_count++;
            if (data < ptr->data)
            {
                insert(data, ptr->left);
            }
            else
            {
                if (data > ptr->data)
                {
                    insert(data, ptr->right);
                }
            }
        }
    }
}

void BinarySearchTree::reset()
{
    probe_count = 0;
    comparison_count = 0;
    elapsed_time = 0;
}

long BinarySearchTree::get_probe_count() const { return probe_count; }
long BinarySearchTree::get_comparison_count() const { return comparison_count; }
long BinarySearchTree::get_elapsed_time() const { return elapsed_time; }

void BinarySearchTree::increment_elapsed_time(const long msec) { elapsed_time += msec; }
