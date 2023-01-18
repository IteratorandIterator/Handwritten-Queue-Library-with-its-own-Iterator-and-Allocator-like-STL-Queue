#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
#pragma pack(push, 4)
#include"Myallocator.h"
#include"Myiterator.h"

//-----------------------------队列的节点--------------------------------
template<class _Ty >      
struct _queue_node
{
	_Ty value;
	_queue_node<_Ty>* next;

	_queue_node(const _queue_node&) = delete;
	_queue_node& operator=(const _queue_node&) = delete;

};
//-----------------------------队列的节点--------------------------------

//-----------------------------自己尝试给对列类添加的迭代器--------------------------------
template<class _Ty>
struct _queue_iterator
{
	typedef forward_iterator_tag_  iterator_category;
	using pointer = _Ty*;
	using reference = _Ty&;
	using value_type = _Ty;
	typedef _queue_node<_Ty>* _nodeptr;
	typedef ptrdiff_t difference_type;

	_nodeptr nodeptr;

	_queue_iterator() {}
	_queue_iterator(_nodeptr _P) : nodeptr(_P) {}
	_queue_iterator(const _queue_iterator& _ite) : nodeptr(_ite.nodeptr) {}

	bool operator==(const _queue_iterator<_Ty>& _ite) const { return nodeptr == _ite.nodeptr; }
	bool operator!=(const _queue_iterator<_Ty>& _ite) const { return nodeptr != _ite.nodeptr; }

	NODISCARD reference operator*() const noexcept {
		return (*nodeptr).value;
	}

	NODISCARD pointer operator->() const noexcept {
		return &(operator*());
	}

	_queue_iterator<_Ty>& operator++() noexcept {
		nodeptr = (_nodeptr)((*nodeptr).next);
		return *this;
	}

	_queue_iterator<_Ty> operator++(int) noexcept {
		_queue_node<_Ty> _temp = *this;
		++* this;
		return _temp;
	}
	//----------------------------双向链表才有的操作符重载，队列没有，只是写上不影响-------------
	_queue_iterator<_Ty>& operator--() {
		nodeptr = (_nodeptr)(*nodeptr.prev);
		return *this;
	}
	_queue_iterator<_Ty> operator--(int) {
		_queue_node<_Ty> _temp = *this;
		--* this;
		return _temp;
	}
	//----------------------------双向链表才有的操作符重载，队列没有，只是写上不影响-------------
};
//-----------------------------自己尝试给对列类添加的迭代器--------------------------------


//-----------------------------队列类象的大小比较，同字符串一样---------------------------------
template<class type_, class Allo_ = myallocator<type_> >
class queue;

template<class type_, class Allo_ = myallocator<type_> >
NODISCARD bool operator== (const queue<type_, Allo_>& _left, const queue<type_, Allo_>& _right) {
	typename queue<type_, Allo_>::_nodeptr start_l = (_left._front)->next ;
	typename queue<type_, Allo_>::_nodeptr start_r = (_right._front)->next;
	if (_left._size != _right._size) { return 0; }
	while (start_l != _left.rear) {
		if (start_l->value != start_r->value) { return 0; }
	    start_l = start_l->next;
		start_r = start_r->next;
	}
	return 1;
}

template<class type_, class Allo_>
NODISCARD bool operator<= (const queue<type_, Allo_>& _left, const queue<type_, Allo_>& _right) {
	typename queue<type_, Allo_>::_nodeptr start_l = (_left._front)->next;
	typename queue<type_, Allo_>::_nodeptr start_r = (_right._front)->next;
	if (_left._size < _right._size) { return 1; }
	if (_left._size > _right._size) { return 0; }
	while (start_l != _left.rear) {
		if (start_l->value > start_r->value) { return 0; }
		start_l = start_l->next;
		start_r = start_r->next;
	}
	return 1;
}
template<class type_, class Allo_>
NODISCARD bool operator>= (const queue<type_, Allo_>& _left, const queue<type_, Allo_>& _right) {
	typename queue<type_, Allo_>::_nodeptr start_l = (_left._front)->next;
	typename queue<type_, Allo_>::_nodeptr start_r = (_right._front)->next;
	if (_left._size < _right._size) { return 0; }
	if (_left._size > _right._size) { return 1; }
	while (start_l != _left.rear) {
		if (start_l->value < start_r->value) { return 0; }
		start_l = start_l->next;
		start_r = start_r->next;
	}
	return 1;
}

template<class type_, class Allo_>
NODISCARD bool operator!= (const queue<type_, Allo_>& _left, const queue<type_, Allo_>& _right) {
	/*typename queue<type_, Allo_>::_nodeptr start_l = _left._front;
	typename queue<type_, Allo_>::_nodeptr start_r = _right._front;
	if (_left._size != _right._size) { return 1; }
	if (start_l->value != start_r->value ) { return 1; }
	while (start_l->next != 0) {
		start_l = start_l->next;
		start_r = start_r->next;
		if (start_l->value != start_r->value) { return 0; }
	} 
	return 0;*/
	return !(_left == _right); //注释部分是未优化前的代码就，此代码是优化过的代码
}

template<class type_, class Allo_>
NODISCARD bool operator<  (const queue<type_, Allo_>& _left, const queue<type_, Allo_>& _right) {
	/*typename queue<type_, Allo_>::_nodeptr start_l = _left._front;
	typename queue<type_, Allo_>::_nodeptr start_r = _right._front;
	if (_left._size < _right._size) { return 1; }
	if (_left._size > _right._size) { return 0; }
	if (start_l->value < start_r->value ) { return 1; }
	while (start_l->next != 0){
		start_l = start_l->next;
		start_r = start_r->next;
		if (start_l->value < start_r->value) { return 1; }
	}
	return 0;*/
	return !(_left >= _right);//注释部分是未优化前的代码就，此代码是优化过的代码
}
template<class type_, class Allo_>
NODISCARD bool operator>  (const queue<type_, Allo_>& _left, const queue<type_, Allo_>& _right) { 
	/*typename queue<type_, Allo_>::_nodeptr start_l = _left._front;
	typename queue<type_, Allo_>::_nodeptr start_r = _right._front;
	if (_left._size < _right._size) { return 0; }
	if (_left._size > _right._size) { return 1; }
	if (start_l->value > start_r->value) { return 1; }
	while (start_l->next != 0){
		start_l = start_l->next;
		start_r = start_r->next;
		if (start_l->value > start_r->value) { return 1; }
	}
	return 0;*/
	return !(_left <= _right);  //注释部分是未优化前的代码就，此代码是优化过的代码
}
//-----------------------------队列类象的大小比较，同字符串一样---------------------------------

//-----------------------------队列类--------------------------------------------------------
template<class type_, class Allo_ = myallocator<type_> >
class queue
{
protected:
	typedef _queue_node<type_>  queue_node;
	typedef typename myallocator<type_>::_rebind<queue_node>::_other  Allo_node;
	Allo_node Anode;
public:
	using value_type = type_;
	using reference = type_&;
	using const_reference = const type_&;
	using size_type = size_t;
	using difference_type = ptrdiff_t;

	using Allocator_type = Allo_;
	typedef queue_node* _nodeptr;
	typedef _queue_iterator<type_>  iterator;

private:
	size_type _size;
	_nodeptr _front;
	_nodeptr rear;
public:
	queue() :_size(0), _front(Initialize_ptr()), rear(Initialize_ptr()){}
	~queue() noexcept {}
private:
	NODISCARD _nodeptr Initialize_ptr() {
		_nodeptr nodeptr = Anode.allocate(1);
		nodeptr->next = nodeptr;
		return nodeptr;
	}
	 NODISCARD _nodeptr node_creat() {
		 if (_size == 0) {
			 _nodeptr nodeptr = Anode.allocate(1);
			 rear->next = nodeptr;
			 nodeptr->next = rear;
			 _front->next = nodeptr;
			 ++_size;
			 return nodeptr;
		 }
		 else if(_size > 0) {
			 _nodeptr nodeptr = Anode.allocate(1);
			 (rear->next)->next = nodeptr;
			 rear->next = nodeptr;
			 nodeptr->next = rear;
			 ++_size;
			 return nodeptr;
		 }
	 }
public:
	 NODISCARD size_type size() noexcept {
		 return _size;
	 }
	 NODISCARD reference front() noexcept( noexcept(_size != 0)) {
		 return (_front->next)->value;
	 }
	 NODISCARD const_reference const_front() noexcept(noexcept(_size != 0)) {
		 return (_front->next)->value;
	 }
	 NODISCARD reference back() noexcept (noexcept(_size != 0)) {
		 return (rear->next)->value;
	 }
	 NODISCARD const_reference const_back() noexcept (noexcept(_size != 0)) {
		 return (rear->next)->value;
	 }
	 NODISCARD bool empty() const {
		 return _size == 0;
	 }
	 void push(reference val){
		 _nodeptr nodeptr = node_creat();
		 nodeptr->value = val;
	 }
	 void push(const_reference val){
		 _nodeptr nodeptr = node_creat();
		 nodeptr->value = val;
	 }
	 void pop() {
		 _nodeptr _temp = _front->next;
		 if (rear->next == _front->next) {
			 rear->next = rear;
			 _front->next = _front;
			 --_size;
		 }
		 else{
			 _front->next = (_front->next)->next;
			 --_size;
		 }
		 Anode.deallocate(_temp, 1);
	 }
	 NODISCARD value_type pop_value() noexcept (noexcept(_size != 0)) {
		 _nodeptr _temp = _front->next;
		 value_type _temp2 = _temp->value;
		 if (rear->next == _front->next) {
			 rear->next = rear;
			 _front->next = _front;
			 --_size;
		 }
		 else {
			 _front->next = (_front->next)->next;
			 --_size;
		 }
		 Anode.deallocate(_temp, 1);
		 return _temp2;
	 }

	 void erase() {
		 while (this->_front->next  != this->_front) {
			 this->pop();
		 }
	 }

	 friend bool operator== <>(const queue&, const queue&);
	 friend bool operator!= <>(const queue&, const queue&);
	 friend bool operator<  <>(const queue&, const queue&);
	 friend bool operator>  <>(const queue&, const queue&);
	 friend bool operator<= <>(const queue&, const queue&);
	 friend bool operator>= <>(const queue&, const queue&);

public:
	NODISCARD iterator begin() noexcept {
		return iterator(_front->next);
	}


	NODISCARD iterator end() noexcept {
		return iterator (rear);
	}

};
//-----------------------------队列类--------------------------------------------------------
#endif
#pragma pack(pop)
