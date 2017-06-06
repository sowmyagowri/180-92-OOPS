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
   string next;
   while (! empty( ))
      next = pop( );//pop calls delete.
}

bool Stack::empty( ) const
{
   return (top == NULL);
}

void Stack::push(string the_symbol)
{
   StackFramePtr new_frame = new StackFrame;
   new_frame->data = the_symbol;
   new_frame->link = top;
   top = new_frame;
}

string Stack::pop( )
{
   if (empty( ))
   {
       cout << "Error: popping an empty stack.\n";
       exit(1);
   }
   string result = top->data;
   StackFramePtr temp_ptr;
   temp_ptr = top;
   top = top->link;
   delete temp_ptr;
   return result;
}
