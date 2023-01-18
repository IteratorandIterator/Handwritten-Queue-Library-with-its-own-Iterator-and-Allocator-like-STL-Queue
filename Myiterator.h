#pragma once
#ifndef _MYITERATOR_H_
#define _MYITERATOR_H_

struct input_iterator_tag_ {};

struct output_iterator_tag_ {};

struct forward_iterator_tag_ : input_iterator_tag_ {};

struct bidirectional_iterator_tag_ : forward_iterator_tag_ {};

struct random_access_iterator_tag_ : bidirectional_iterator_tag_ {};

template <class _Category, class _Ty, class _Distance = ptrdiff_t,
	class _Pointer = _Ty*, class _Reference = _Ty&>
struct iterator
{
	typedef _Category iterator_category;
	typedef _Ty value_type;
	typedef _Pointer pointer;
	typedef _Reference reference;
	typedef _Distance difference_type;
};

template <class _iterator>
struct iterator_traits
{
	typedef typename _iterator::iterator_category  iterator;
	typedef typename _iterator::value_type  value_type;
	typedef typename _iterator::pointer  pointer;
	typedef typename _iterator::reference  reference;
	typedef typename _iterator::difference_type  difference_type;
};

template <class _Ty>
struct iterator_traits<_Ty*>
{
	typedef random_access_iterator_tag_  iterator;
	typedef _Ty  value_type;
	typedef _Ty* pointer;
	typedef _Ty& reference;
	typedef ptrdiff_t difference_type;
};

template <class _Ty>
struct iterator_traits<const _Ty*>
{
	typedef random_access_iterator_tag_  iterator;
	typedef _Ty  value_type;
	typedef const _Ty* pointer;
	typedef const _Ty& reference;
	typedef ptrdiff_t difference_type;
};

#endif