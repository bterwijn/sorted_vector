# sorted_vector
C++ vector that can be accessed as a normal vector and in sorted
order. Stores all data both in a std::vector and std::set and keeps
the std::set in sync when the vector is manipulated. As a result the
time complexity of push_back/update/insert/erase/pop_back operations
is now at least O(log n).

To preserve the invariance all iterators are const_iterators only.
The [] operator now only gives constant references. Instead write to a
specific index using member function:
```c++
void update(int index,const T& value)
```

## example code
```c++
#include "sorted_vector.h"

#include <iostream>
using namespace std;

// print vector
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec)
{ for (const auto& i : vec) os<<' '<<i; return os; }
// print set
template<typename T,typename Compare> ostream& operator<<(ostream& os,const set<T,Compare>& set)
{ for (const auto& i : set) os<<' '<<i; return os; }

int main()
{
    sorted_vector<int> svec; // type (int) requires operators: '==','<'
    svec.push_back(4);       // push_back some elements
    svec.push_back(3);       //
    svec.push_back(2);       //
    svec.push_back(1);       //
    
    cout<<"vector:"<< svec.vector() <<endl; // print in sequence
    cout<<"set   :"<< svec.set()    <<endl; // print in sorted order

    // sorting will be kept in sync when:
    svec.update( svec.size()/2, -10);          // update element at index
    svec.insert( ++svec.vector().begin(), 99); // insert element at iterator
    svec.erase( svec.vector().begin() );       // erase element at iterator
    svec.pop_back();                           // pop element at the back
    
    cout<<"vector:"<< svec.vector() <<endl; // print in sequence
    cout<<"set   :"<< svec.set()    <<endl; // print in sorted order
}
```

output: 
```
vector: 4 3 2 1 
set   : 1 2 3 4 
vector: 99 3 -10
set   : -10 3 99
```
