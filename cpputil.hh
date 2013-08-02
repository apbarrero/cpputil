#if !defined(__CPPUTIL__)
#define __CPPUTIL__

namespace cpputil
{
    template<typename T>
    struct deletor
    {
        void operator()(T* t)
        {
            delete t;
        }
    };

    template<typename T>
    struct stared_less
    {
        bool operator()(T* rhs, T* lhs)
        {
            return *rhs < *lhs;
        }
    };
}

#endif

