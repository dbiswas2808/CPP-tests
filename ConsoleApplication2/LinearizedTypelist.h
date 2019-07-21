#pragma once
#include "Typelists.h"

using namespace DrownTeam;

#define TYPELIST_1(T1) Typelist<T1, Nulltype>
#define TYPELIST_2(T1, T2) Typelist<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3) Typelist<T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4) Typelist<T1, TYPELIST_3(T2, T3, T4) >
#define TYPELIST_5(T1, T2, T3, T4, T5) Typelist<T1, TYPELIST_4(T2, T3, T4, T5) >
#define TYPELIST_6(T1, T2, T3, T4, T5, T6) Typelist<T1, TYPELIST_5(T2, T3, T4, T5, T6) >


#define GET_MACRO(_1,_2,_3, _4, _5, _6, NAME,...) NAME
#define TYPELIST(...) GET_MACRO(__VA_ARGS__, TYPELIST_6, TYPELIST_5, TYPELIST_4, TYPELIST_3, TYPELIST_2, TYPELIST_1)(__VA_ARGS__)