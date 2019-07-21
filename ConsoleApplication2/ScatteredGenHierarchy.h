#pragma once
#include "Typelists.h"

template<class AtomicType>
struct TupleAtom {
	AtomicType element;
	void setValue(const AtomicType& val) {
		element = val;
	}
};

template<class TypeList, template<class> class AtomicClass>
struct ScatteredGenHierarchy;

template<class AtomicType, class TList, template<class> class AtomicClass>
struct ScatteredGenHierarchy<DrownTeam::Typelist<AtomicType, TList>, AtomicClass> :
	public ScatteredGenHierarchy<TList, AtomicClass>, AtomicClass<AtomicType> {
	
	typedef ScatteredGenHierarchy<TList, AtomicClass> Base;
	typedef AtomicClass<AtomicType> Holder;

	ScatteredGenHierarchy(const AtomicType& tVal, Args... arg) : Base(arg) {
		Holder::SetValue(tVal);
	}
};


template<class TList> class Tuple;

template<class AtomicType, class... Types>
struct Tuple : public ScatteredGenHierarchy<AtomicType, TList, TupleAtom> {

	typedef Typelist DrownTeam::Typelist<AtomicType>

	Tuple(Args... arg) : Base(arg) {
	}

	AtomicType value;
};


