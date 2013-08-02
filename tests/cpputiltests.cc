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

TEST(DereferenceLessTests, CompareTwoPointers_Works)
{
    int* a = new int(1);
    int* b = new int(2);

    DereferenceLess<int> lessCompare;
    EXPECT_TRUE(lessCompare(a, b));
    EXPECT_FALSE(lessCompare(b, a));
}

TEST(DereferenceLessTests, SortVector_Works)
{
    std::vector<int*> v;
    for (unsigned int i = 10; i > 0; --i)
    {
        v.push_back(new int(i));
    }

    std::sort(v.begin(), v.end(), DereferenceLess<int>());

    EXPECT_EQ(1, *v.front());
    EXPECT_EQ(10, *v.back());
}

TEST(DereferenceLessTests, KeepSetSorted_Works)
{
    std::set<int*, DereferenceLess<int> > v;
    for (unsigned int i = 10; i > 0; --i)
    {
        v.insert(new int(i));
    }

    EXPECT_EQ(1, **v.begin());
    EXPECT_EQ(10, **v.rbegin());
}
