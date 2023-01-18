#pragma once
#ifndef _MYALLOCATOR_H_
#define _MYALLOCATOR_H_
#define NODISCARD [[nodiscard]]
typedef unsigned int   size_t;
typedef int   ptrdiff_t;

template <class _Ty>
class myallocator
{
public:
	using value_type = _Ty;

	typedef _Ty*   pointer;
	typedef const _Ty*   const_pointer;
	typedef _Ty&   reference;
	typedef const _Ty&   const_reference;

	using size_type = size_t;
	using difference_type = ptrdiff_t;

	template <class _Other>
	struct _rebind{
		typedef myallocator<_Other>  _other;
	};

	constexpr myallocator() noexcept = default;
     ~myallocator() noexcept = default;

	NODISCARD pointer allocate(const size_type cont_) {
		return static_cast<pointer>(::operator new((size_type)(sizeof(value_type) * cont_)));
	}

	NODISCARD pointer allocate(const size_type cont_, const void*) {
		return allocate(cont_);
	}

	void deallocate(pointer const _ptr, const size_type cont_) {
		::operator delete(_ptr);
	}

	NODISCARD size_type max_size() const noexcept {
		return static_cast<unsigned int>(-1) / sizeof(value_type);
	}
};

#endif