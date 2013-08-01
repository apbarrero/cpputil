#include <cpputil.hh>
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace cpputil;

TEST(DereferenceDeleteTests, DeleteSinglePointer_Works)
{
    int *pointer = new int;

    DereferenceDelete<int> deleter;
    deleter(pointer);
    SUCCEED();
}

TEST(DereferenceDeleteTests, DeleteContainer_Works)
{
    std::vector<int*> v;
    for (unsigned int i = 0; i < 10; ++i) v.push_back(new int);

    std::for_each(v.begin(), v.end(), DereferenceDelete<int>());
    SUCCEED();
}

