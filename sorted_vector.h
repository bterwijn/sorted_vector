#include <vector>
#include <set>
#include <cassert>

template<typename T,typename Compare = std::less<T> >
class sorted_vector
{
    std::vector<T> m_vector;
    std::set<T,Compare> m_set;

    typedef typename std::vector<T>::iterator iterator;
    typedef typename std::vector<T>::const_iterator const_iterator;
 public:

    const std::vector<T>& vector()
    { return m_vector; }

    const std::set<T,Compare>& set()
    { return m_set; }
    
    void push_back(const T& value)
    {
        m_set.insert(value);
        m_vector.push_back(value);
    }

    void update(int index,const T& value)
    {
        auto found=m_set.find(m_vector[index]);
        assert(found!=m_set.end());
        m_set.erase(found);
        m_set.insert(value);
        m_vector[index]=value;
    }

    const_iterator insert(const_iterator pos,const T& value)
    {
        m_set.insert(value);
        return m_vector.insert(pos,value);
    }

    void clear()
    {
        m_set.clear();
        m_vector.clear();
    }

    iterator erase(const_iterator pos)
    {
        auto found=m_set.find(*pos);
        assert(found!=m_set.end());
        m_set.erase(found);
        return m_vector.erase(pos);
    }

    void pop_back()
    {
        auto found=m_set.find(m_vector.back());
        assert(found!=m_set.end());
        m_set.erase(found);
        m_vector.pop_back();
    }
    
    // just for convenience, also accesible via vector() method
    const T& operator[](int i) const   { return m_vector[i]; }
    const T& at(int i) const           { return m_vector.at(i); }
    const T& front() const             { return m_vector.front(); }
    const T& back() const              { return m_vector.back(); }
    size_t size() const                { return m_vector.size(); }
    bool  empty() const                { return m_vector.empty(); }
    size_t max_size() const            { return m_vector.max_size(); }
    void reserve(size_t new_cap )      { m_vector.reserve(new_cap); }
    size_t capacity() const            { return m_vector.capacity(); }
    void shrink_to_fit()              { m_vector.shrink_to_fit(); }
};

template<typename T,typename Compare = std::less<T> >
bool operator==(const sorted_vector<T,Compare>& sv1,
                const sorted_vector<T,Compare>& sv2)
{ return sv1.vector()==sv2.vector();}
