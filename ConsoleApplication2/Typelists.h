#pragma once
#include"NullEmpty.h"

namespace DrownTeam {
// Tuple like implementation
template<class T, class U>
class Typelist {
public:
	typedef T Head;
	typedef U Tail;
};


namespace TL {
	// Gets the length of Typelist
	template<class TList> class Length;

	template <> class Length<Nulltype> {
	public:
		enum { value = 0 };
	};

	template <class T, class U>
	class Length< Typelist<T, U> > {
	public:
		enum { value = 1 + Length<U>::value };
	};

	// Gets the type at a 0 based index in the typelist
	template<int idx, class TList> class AtIndex;

	template<int idx> class AtIndex<idx, Nulltype> {
	public:
		struct IndexOutOfBounds {};
		typedef IndexOutOfBounds result;
	};

	template<class T, class U> class AtIndex<0, Typelist<T, U> > {
	public:
		typedef T result;
	};

	template<int idx, class T, class U> class AtIndex<idx, Typelist<T, U> > {
	public:
		enum {
			index = idx
		};

		typedef typename AtIndex<index - 1, U>::result result;
	};
	
	// Returns type at a given index(0 based). Different interface
	template <class TList> class FieldValue;

	template<class T, class U> 
	class FieldValue<Typelist<T, U> > {
	public:
		typedef Typelist<T, U> TList;

		template<int idx>
		struct At {
			enum {
				index = idx
			};

			typedef typename AtIndex<index, TList>::result result;
		};	
	};

	// Removes a type from the list at the given 0 based index
	template <int idx, class TList> class DeleteAtIdx;

	template <class T, class U> class DeleteAtIdx<0, Typelist<T, U> > {
	public:
		typedef U result;
	};

	template <int idx> class DeleteAtIdx<idx, Nulltype > {
	public:
		typedef Nulltype result;
	};

	template <int idx, class T, class U> class DeleteAtIdx<idx, Typelist<T, U> > {
	public:
		typedef Typelist<T, typename DeleteAtIdx<idx - 1, U>::result> result;
	};

	// Figures out if a specific type is in the type list 
	template <class T, class U> class IsFound;
	
	template <class Type> class IsFound<Nulltype, Type> {
	public: 
		enum {
			value = 0
		};
	};

	template <class U, class Type> class IsFound<Typelist<Type, U>, Type> {
	public:
		enum {
			value = 1
		};
	};

	template <class T, class U, class Type> class IsFound<Typelist<T, U>, Type> {
	public: 
		
		enum {
			value = IsFound<U, Type>::value
		};
	};
}
}
