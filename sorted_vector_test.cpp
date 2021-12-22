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
    
    int length=4;
    for (int i=length; i>0; i--)
        svec.push_back(i);                   // push_back some elements
    
    cout<<"vector:"<< svec.vector() <<endl; // print in sequence
    cout<<"set   :"<< svec.set()    <<endl; // print in sorted order

    // sorting will be kept up to date when:
    svec.update( svec.size()/2, -10);          // update element at index
    svec.insert( ++svec.vector().begin(), 99); // insert element at iterator
    svec.erase( svec.vector().begin() );       // erase element at iterator
    svec.pop_back();                           // pop element at the back
    
    cout<<"vector:"<< svec.vector() <<endl; // print in sequence
    cout<<"set   :"<< svec.set()    <<endl; // print in sorted order
}
/* output:
vector: 4 3 2 1
set   : 1 2 3 4
vector: 99 3 -10
set   : -10 3 99
*/
