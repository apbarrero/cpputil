#include <cpputil.hh>
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace cpputil;

TEST(DeletorTests, DeleteSinglePointer_Works)
{
    int *pointer = new int;

    deletor<int> deleter;
    deleter(pointer);
    SUCCEED();
}

TEST(DeletorTests, DeleteContainer_Works)
{
    std::vector<int*> v;
    for (unsigned int i = 0; i < 10; ++i) v.push_back(new int);

    std::for_each(v.begin(), v.end(), deletor<int>());
    SUCCEED();
}

TEST(StaredLessTests, CompareTwoPointers_Works)
{
    int* a = new int(1);
    int* b = new int(2);

    stared_less<int> lessCompare;
    EXPECT_TRUE(lessCompare(a, b));
    EXPECT_FALSE(lessCompare(b, a));
}

TEST(StaredLessTests, SortVector_Works)
{
    std::vector<int*> v;
    for (unsigned int i = 10; i > 0; --i)
    {
        v.push_back(new int(i));
    }

    std::sort(v.begin(), v.end(), stared_less<int>());

    EXPECT_EQ(1, *v.front());
    EXPECT_EQ(10, *v.back());
}

TEST(StaredLessTests, KeepSetSorted_Works)
{
    std::set<int*, stared_less<int> > v;
    for (unsigned int i = 10; i > 0; --i)
    {
        v.insert(new int(i));
    }

    EXPECT_EQ(1, **v.begin());
    EXPECT_EQ(10, **v.rbegin());
}
