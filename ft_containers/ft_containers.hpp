#ifndef FT_CONTAINERS_HPP
#define FT_CONTAINERS_HPP

#include "Vector.hpp"

namespace ft
{	
	template <bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T>
	{ typedef T type; };

	template <class T>
	class iterator
	{
		private:
			typedef T         	value_type;
			typedef ptrdiff_t	difference_type;
			typedef T*   		pointer;
			typedef T&			reference;

		protected:
			pointer   		ptr;

		public:
			iterator(void) : ptr(NULL) {};
			iterator(T* x) : ptr(x) {};
			iterator(const iterator& mit) {*this = mit;};
			~iterator(void) {};
			iterator& operator=(const iterator& mit)
			{
				if (this != &mit)
					ptr = mit.ptr;
				return *this;
			};

			bool operator==(const iterator& other) const { return ptr == other.ptr; }
			bool operator!=(const iterator& other) const { return ptr != other.ptr; }
			reference operator*() const { return *ptr; }
			pointer operator->() const { return ptr; }
			iterator& operator++() { ++ptr; return *this; }
			iterator operator++(int) { iterator tmp(*this); ++(*this); return tmp; }
			iterator& operator--() { --ptr; return *this; }
			iterator operator--(int) { iterator tmp(*this); --(*this); return tmp; }
			iterator& operator+=(const difference_type other) { ptr += other; return *this; }
			iterator& operator-=(const difference_type other) { ptr -= other; return *this; }
			iterator operator+(const difference_type other) const { return iterator(ptr + other); }
			iterator operator-(const difference_type other) const { return iterator(ptr - other); }
			iterator operator+(const iterator& other) const { return iterator(*this + other.ptr); }
			difference_type operator-(const iterator& other) const { return std::distance(ptr, other.ptr); }
			reference operator[](std::size_t index) const { return ptr[index]; }
			bool operator<(const iterator& other) const { return ptr < other.ptr; }
			bool operator>(const iterator& other) const { return ptr > other.ptr; }
			bool operator<=(const iterator& other) const { return ptr <= other.ptr; }
			bool operator>=(const iterator& other) const { return ptr >= other.ptr; }
	};

	template <class T>
	class r_iterator
	{
		private:
			typedef T         	value_type;
			typedef ptrdiff_t	difference_type;
			typedef T*   		pointer;
			typedef T&			reference;
			
		protected:
			pointer   		ptr;
			
		public:
			r_iterator(void) : ptr(NULL) {};
			r_iterator(T* x) : ptr(x) {};
			r_iterator(const r_iterator& mit) {*this = mit;};
			r_iterator& operator=(const r_iterator& mit)
			{
				if (this != &mit)
					ptr = mit.ptr;
				return *this;
			};

			bool operator==(const r_iterator& other) const { return ptr == other.ptr; }
			bool operator!=(const r_iterator& other) const { return ptr != other.ptr; }
			reference operator*() const { return *ptr; }
			pointer operator->() const { return ptr; }
			r_iterator& operator++() { --ptr; return *this; }
			r_iterator operator++(int) { r_iterator tmp(*this); ++(*this); return tmp; }
			r_iterator& operator--() { ++ptr; return *this; }
			r_iterator operator--(int) { r_iterator tmp(*this); --(*this); return tmp; }
			r_iterator& operator+=(const difference_type other) { ptr -= other; return *this; }
			r_iterator& operator-=(const difference_type other) { ptr += other; return *this; }
			r_iterator operator+(const difference_type other) const { return r_iterator(ptr - other); }
			r_iterator operator-(const difference_type other) const { return r_iterator(ptr + other); }
			r_iterator operator+(const r_iterator& other) const { return r_iterator(*this - other.ptr); }
			difference_type operator-(const r_iterator& other) const { return std::distance(ptr, other.ptr); }
			reference operator[](std::size_t index) const { return ptr[index]; }
			bool operator<(const r_iterator& other) const { return ptr < other.ptr; }
			bool operator>(const r_iterator& other) const { return ptr > other.ptr; }
			bool operator<=(const r_iterator& other) const { return ptr <= other.ptr; }
			bool operator>=(const r_iterator& other) const { return ptr >= other.ptr; }
	};
}

#endif
