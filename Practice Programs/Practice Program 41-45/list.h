#include <string>
#include <stdexcept>

using namespace std;

class List
{
public:
   virtual bool isEmpty() const = 0;
   virtual string head() const = 0;
   virtual const List& tail() const = 0;
};

class EList : public List
{
public:
   virtual bool isEmpty() const { return true; }
   virtual string head() const { throw logic_error("Empty list has no head"); }
   virtual const List& tail() const { throw logic_error("Empty list has no tail"); }
};

class NEList : public List
{
public:
   NEList(string h, const List& t) : data(h), next(t) {}
   virtual bool isEmpty() const { return false; }
   virtual string head() const { return data; }
   virtual const List& tail() const { return next; }
private:
   string data;
   const List& next;
};

inline NEList operator+=(string h, const List& t) { return NEList(h, t); }
