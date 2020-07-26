// Author - Dvir Sadon

#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace itertools;

TEST_CASE("Test range") 
{
    int c = 0;
    for(int num : range(0, 10))
    {
        CHECK(c == num);
        ++c;
    }

    c = -5;
    for(int num : range(-5, 5))
    {
        CHECK(c == num);
        ++c;
    }

    c = -10;
    for(int num : range(-10, 0))
    {
        CHECK(c == num);
        ++c;
    }
}

TEST_CASE("Test accumulate") 
{
    int c[] = {5, 5+6, 5+6+7, 5+6+7+8};
    int i = 0;
    for(int num : accumulate(range(5, 9)))
    {
        CHECK(c[i] == num);
        ++i;
    }

    int ce[] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};
    i = 0;
    for(int num2 : accumulate(range(0, 10)))
    {
        CHECK(ce[i] == num2);
        ++i;
    }

    int che[] = {-10, -19, -27, -34, -40, -45, -49, -52, -54, -55};
    i = 0;
    for(int num3 : accumulate(range(-10, 0)))
    {
        CHECK(che[i] == num3);
        ++i;
    }

    int chec[] = {-10, -1, 7, 14, 20, 25, 29, 32, 34, 35};
    i = 0;
    for(int num : accumulate(range(-10, 0), [](int x, int y){return x-y;}))
    {
        CHECK(chec[i] == num);
        ++i;
    }
}

TEST_CASE("Test filterfalse") 
{
    typedef struct 
    {
        bool operator()(int i) const 
        {
            return i%3 == 0;
        }
    } func;

    typedef struct 
    {
        bool operator()(int i) const 
        {
            return i%3 == 1;
        }
    } func2;

    typedef struct 
    {
        bool operator()(int i) const 
        {
            return i%3 == 2;
        }
    } func3;

    func f;
    for (auto i : filterfalse(f, range(0,20))) 
        CHECK(!f(i));

    func2 f2;
    for (auto i : filterfalse(f2, range(0,20))) 
        CHECK(!f2(i));


    func3 f3;
    for (auto i : filterfalse(f3, range(0,20))) 
        CHECK(!f3(i));
}

TEST_CASE("Test compress") 
{
    auto v1 = vector({true, false, true, false, true, false, true, false, true, false});
    for(auto i : compress(range(0,10), v1))
        CHECK(i%2 == 0);
}