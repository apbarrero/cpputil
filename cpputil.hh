#if !defined(__CPPUTIL__)
#define __CPPUTIL__

namespace cpputil
{
    template<typename T>
    struct DereferenceDelete
    {
        void operator()(T* t)
        {
            delete t;
        }
    };
}

#endif

