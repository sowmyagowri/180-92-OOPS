/**
 * An implementation of the binary search tree and its operations.
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>
#include "BinaryNode.h"

using namespace std;

class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& rhs);
    virtual ~BinarySearchTree();

    BinaryNode *getRoot() const;
    int height() const;

    void clear();
    bool contains(const int data);
    void insert(const int data);
    void remove(const int data);

    // Count variables.
    long probe_count;
    long comparison_count;
    long elapsed_time;

    // Access and reset the values of the count variables.
    long get_probe_count() const;
    long get_comparison_count() const;
    long get_elapsed_time() const;

    void reset();
    void increment_elapsed_time(const long msec);

protected:
    virtual int height(const BinaryNode *ptr) const;
    virtual void insert(const int data, BinaryNode* &ptr);

private:
    BinaryNode *root;

    void clear(BinaryNode* &ptr);
    bool contains(const int data, BinaryNode *ptr);
};


#endif // BINARY_TREE_CHECKER_H
