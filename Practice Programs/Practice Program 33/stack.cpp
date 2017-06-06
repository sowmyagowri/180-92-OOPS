#include <iostream>
#include <cstddef>
#include "stack.h"
using namespace std;
//Uses cstddef:
Stack::Stack( ) : top(NULL)
{
   //Body intentionally empty.
}

Stack::~Stack( )
{
   int next;
   while (! empty( ))
      next = pop( );//pop calls delete.
}

bool Stack::empty( ) const
{
   return (top == NULL);
}

void Stack::push(int the_symbol)
{
   StackFramePtr new_frame = new StackFrame;
   new_frame->data = the_symbol;
   new_frame->link = top;
   top = new_frame;
}

int Stack::pop( )
{
   if (empty( ))
   {
      cout << "Error: popping an empty stack.\n";
      exit(1);
   }
   int result = top->data;
   StackFramePtr temp_ptr;
   temp_ptr = top;
   top = top->link;
   delete temp_ptr;
   return result;
}
