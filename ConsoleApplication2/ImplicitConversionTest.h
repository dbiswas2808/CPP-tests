#pragma once

// Implicit conversion static test
template<class To, class From> 
class ImplicitTypeCheck
{
	struct DummyBigSize {
		char a[2];
	};

static DummyBigSize TestFunctionCall(To t);

static	char TestFunctionCall(...);
public:

	enum Type {
		isImplicit = (sizeof(TestFunctionCall(To())) == sizeof(TestFunctionCall(From())))
	};
};