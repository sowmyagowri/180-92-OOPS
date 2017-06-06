#include "TimedContainer.h"

TimedContainer::TimedContainer() : elapsed_time(0)
{
}

TimedContainer::~TimedContainer()
{
}

long TimedContainer::get_elapsed_time() const { return elapsed_time; }
void TimedContainer::reset_elapsed_time() { elapsed_time = 0; }
void TimedContainer::increment_elapsed_time(const long usec) { elapsed_time += usec; }
