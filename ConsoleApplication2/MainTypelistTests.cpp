// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ImplicitConversionTest.h"
#include "Typelists.h"
#include "LinearizedTypelist.h"


class A {
public:
	A() = default;
	virtual ~A() = default;
	int a;
};

class B : public A {
public:
	B() = default;
	~B() = default;

	int b;
};

class C {
public:
	C() = default;
	C(const B& b) : m_B(b) {
	}

	B m_B;
};

int main()
{
	// Test the implicit conversion check
	static_assert(ImplicitTypeCheck<A, B>::Type::isImplicit, "NO convertible");
	static_assert(ImplicitTypeCheck<C, B>::Type::isImplicit, "NO convertible");
	static_assert(!ImplicitTypeCheck<B, C>::Type::isImplicit, "Convertible");

	// Test typelist length calculation
	static_assert(DrownTeam::TL::Length<TYPELIST_5(A, B, int, float, double)>::value == 5, "Length is incorrect");

	// Using the field value type interfce
	typedef typename DrownTeam::TL::FieldValue<TYPELIST_6(double, int, float, float, int, A, B, double)>::At<3>::result someType1; // expect float
	someType1 length_f = 2.f;

	typedef TYPELIST_6(double, int, float, float, A, double) Tuple6;
	static_assert(DrownTeam::TL::IsFound<Tuple6, A>::value, "Type A does not exist in the list");

	// Delete type at an index
	typedef typename DrownTeam::TL::DeleteAtIdx<4, TYPELIST_6(double, int, float, float, A, double)>::result someType2;
	static_assert(!DrownTeam::TL::IsFound<someType2, A>::value, "Type A does exist in the list");


	// Using the AtIndex directly
	typedef typename DrownTeam::TL::AtIndex<4, DrownTeam::TL::DeleteAtIdx<4, TYPELIST_6(double, int, float, float, A, double)>::result>::result someType3; // expect double
	someType3 length_d = 2.1;

	// Types as expected? 
	static_assert(std::is_same<decltype(length_f), float>::value, "length is not a float type");
	static_assert(std::is_same<decltype(length_d), double>::value, "length is not a double type");
}