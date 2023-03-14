#ifndef BOUNDED_VECTOR_H // include guard
#define BOUNDED_VECTOR_H
 
#include <cstddef>
#include <iostream>
#include <iterator>
 
namespace mycollection {
    template <typename T>
    class vector {
    public:
        // Type alises
        using value_type = T;
        using iterator = T*;
        using const_iterator = const T*;
 
        // Special Member Functions
        vector(size_t capacity = 10);
        ~vector();
 
        // Element Access
        value_type& at(size_t index);
        value_type& front();
        value_type& back();
 
        const value_type& at(size_t index) const;
        const value_type& front() const;
        const value_type& back() const;
     
        // Iterators
        iterator begin();
        iterator end();
 
        const_iterator begin() const;
        const_iterator end() const;
 
        // Capacity
        bool empty() const;
        size_t size() const;
        size_t capacity() const;
 
        // Modifiers
        void clear();
        iterator insert(iterator pos, const value_type& value);
        iterator erase(iterator pos);
        void push_back(const value_type& value);
        void pop_back();
 
        // Operators (as member functions)
        vector<T>& operator+=(const T& element);
        vector<T>& operator+=(const vector<T>& other);
         
        // For Debugging Only
        void debug() const;
 
        // An odd ball just for the sake of an example
        // Very common mistake is to use the same name for the 
        // function template parameter and the class template parameter
        template <typename InputIt>
        void swap_elements(InputIt first, InputIt last);
 
        void reserve(size_t n);
    private:
        value_type* _elems;
        size_t _capacity;
        size_t _size;
 
        // Operators (as non-member functions but friends)
        // Optional: Rewrite the << operator as a friend!
    };
}
 
using mycollection::vector;
 
// Operators (as non-member functions)
template <typename T>
vector<T> operator+(const vector<T>& lhs, const T& rhs) {
    vector<T> copy = lhs;
    copy += rhs;
    return copy;
}
 
template <typename T>
vector<T> operator+(const T& lhs, const vector<T>& rhs) {
    vector<T> copy = rhs;
    copy += lhs;
    return copy;
}
 
template <typename T_>
std::ostream& operator<<(std::ostream& out, const vector<T_>& rhs) {
    std::copy(rhs.begin(), rhs.end(), std::ostream_iterator<T_>(out, " "));
    out << '\n';
    return out;
}
 
// #include "vector.cpp"
using namespace mycollection;
// using namespace std;
 
template <typename T>
vector<T>::vector(size_t capacity) {
    _capacity = capacity;
    _size = 0;
    _elems = new T[_capacity];
}
 
template <typename T>
vector<T>::~vector() {
    delete[] _elems;
}
 
// Element Access
template <typename T>
typename vector<T>::value_type& vector<T>::at(size_t index) {
    return const_cast<typename vector<T>::value_type&>(
            static_cast<const vector<T>*>(this)->at(index)
    );
}
 
template <typename T>
typename vector<T>::value_type& vector<T>::front() {
    return const_cast<typename vector<T>::value_type&>(
            static_cast<const vector<T>*>(this)->front()
    );
}
 
template <typename T>
typename vector<T>::value_type& vector<T>::back() {
    return const_cast<typename vector<T>::value_type&>(
            static_cast<const vector<T>*>(this)->back()
    );
}
 
template <typename T>
const typename vector<T>::value_type& vector<T>::at(size_t index) const {
    if (index < 0 || index >= _size) 
        throw std::out_of_range("Out of bounds!");
    return _elems[index];
}
 
template <typename T>
const typename vector<T>::value_type& vector<T>::front() const {
    return *begin();
}
 
template <typename T>
const typename vector<T>::value_type& vector<T>::back() const {
    return *(end()-1);
}
     
// Iterators
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
    return _elems;
}
 
template <typename T>
typename vector<T>::iterator vector<T>::end() {
    return _elems + size();
}
 
template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const {
    return _elems;
}
 
template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
    return _elems + size();
}
 
// Capacity
 
template <typename T>
bool vector<T>::empty() const {
    return size() == 0;
}
 
template <typename T>
size_t vector<T>::size() const {
    return _size;
}
 
template <typename T>
size_t vector<T>::capacity() const {
    return _capacity;
}
 
// Modifiers
 
template <typename T>
void vector<T>::clear() {
    _size = 0;
}
 
template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos, const value_type& value) {
    if (size() == capacity()) 
        throw std::length_error("Exceeded maximum capacity!");
    std::copy_backward(pos, end(), end()+1);
    *pos = value;
    ++_size;
    return pos;
}
 
template <typename T>
typename vector<T>::iterator vector<T>::erase(iterator pos) {
    std::copy(pos+1, end(), pos);
    --_size;
    return pos;
}
 
template <typename T>
void vector<T>::push_back(const value_type& value) {
    if (size() == capacity()) 
        throw std::length_error("Exceeded maximum capacity!");
    insert(end(), value);
}
 
template <typename T>
void vector<T>::pop_back() {
    --_size;
}
 
// Operators (as member functions)
template <typename T>
vector<T>& vector<T>::operator+=(const T& element) {
    push_back(element);
    return *this;
}
 
template <typename T>
vector<T>& vector<T>::operator+=(const vector<T>& other) {
    for (const T& val : other) push_back(val);
    return *this;
}
 
// Debugging
template <typename T>
void vector<T>::debug() const {
    std::cout << *this;
}
 
template <typename T>
template <typename InputIt>
void vector<T>::swap_elements(InputIt first, InputIt last) {
    if (std::distance(first, last) != static_cast<int>(size())) 
        throw std::length_error("Can't swap vector with a range of different size");
    std::swap_ranges(first, last, begin());
}
 
// TODO - if n > capacity, then resize the underlying array
// so that the capcity is n.
// if n <= capcity, don't do anything
template <typename T>
void vector<T>::reserve(size_t n) {
    (void) n;
    // depends on if we have time
}

#endif /* BOUNDED_VECTOR */