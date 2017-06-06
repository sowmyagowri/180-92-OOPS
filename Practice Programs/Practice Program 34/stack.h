#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

struct StackFrame
{
   string data;
   StackFrame *link;
};
typedef StackFrame* StackFramePtr;
class Stack
{
 public:
   Stack( );
   //Initializes the object to an empty stack.
   ~Stack( );
   //Destroys the stack and returns all the memory to the freestore.
   void push(string the_symbol);
   //Postcondition: the_symbol has been added to the stack.
   string pop( );
   //Precondition: The stack is not empty.
   //Returns the top symbol on the stack and removes that
   //top symbol from the stack.
   bool empty( ) const;
   //Returns true if the stack is empty. Returns false otherwise.
 private:
   //Copy constructor.
   Stack(const Stack& a_stack);
   StackFramePtr top;
};

#endif
