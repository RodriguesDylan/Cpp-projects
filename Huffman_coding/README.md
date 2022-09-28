# Huffman coding

TP1 :

    Huffman coding in c++
    Binary tree
    Entropy
    Compressing ratio
  
 

## Appendix - Priority queues and priority queue implementations

The Huffman coding algorithm takes as input the probability of occurrence of each symbol
in the alphabet used by an information source, and constructs a tree representing a code for that
information source.

The data structure holding the Huffman forest needs to support these operations : create an
initially empty structure, insert a tree into the structure and delete from the structure, and
return, the tree with the smallest frequency in its root.

We could use an array or a list, but the priority queue is faster. These are exactly the ty-
pical operations provided by the priority queue abstract data type, used in many fundamental
algorithms : create an empty Priority Queue, insert an item into the Priority Queue, delete and
return the item in the priority queue is faster.

A class definition for a Huffman code tree node :
```C++
class Symbol {
  public:
  string name;
  double freq;
  string code;
  bool leaf;
  Symbol *left, *right;
  };
```

The class definition could also have some methods and
constructors for commons operations and initialization. When
building a new node, the fields of child nodes (left and right)
need to be set appropriately. The result is a tree data struc-
ture that is useful both for coding and decoding. For coding,
you should have an array or other table structure of pointers
(`vector<Symbol*>`) to code tree leaf nodes.

A C++ priority_queue is a generic container, and can hold any king of things as specified
with a template parameter when it is created. However, objects in a priority queue must be
comparable to each other for priority. By default, a priority_queue<T> use operator< defined
for objects of type T. So, you could just overload that operator for Symbol.
```C++
class Symbol {
public:
...
bool operator<(Symbol const &) const;
};
```

If you create an STL container such as priority_queue to hold Symbol objects, then adding an
Symbol object to the priority_queue creates a copy of the Symbol object and adds this copy.
Dealing with multiple copies of nodes in a tree can be tricky. So you might want to instead, hold
pointers to Symbol. But there’s a problem : our operator< is a member function of Symbol class.
It is not defined for pointers to Symbol.

Solution : The template for priority_queue takes 3 arguments :
```C++
template < class T, class Container = vector<T>, class Compare = less<typename Container::value_type> > class priority_queue;
```
Compare ⇒ Comparison class ⇒ A class such that the expression comp(a,b), where comp is an
object of this class and a and b are elements of the container, returns true if a is to be placed
earlier than b in a strict weak ordering operation. Here we must define a class implmenting the
function call operator operator() that performs the required comparison. Now we can create
the priority queue as :
```C++
std::priority_queue<Symbol*, std::vector<Symbol*>, myClassPtrComp > pq;
```
