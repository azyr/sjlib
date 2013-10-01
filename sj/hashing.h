#ifndef HASHING_HPP
#define HASHING_HPP

#include <cstddef>

class QString;

namespace sj
{
    struct hash_cstring_murmur
    {
        size_t operator()(const char* str) const;
    };

    struct cstring_charwise_eq
    {
        bool operator() (const char* s1, const char* s2) const;
    };
}

// TODO: how to do these #ifdefs right on both .cpp and .h file?

//#ifdef QT_VERSION

namespace sj
{
    struct hash_qstring_murmur
    {
        size_t operator()(const QString& str) const;
    };
}

//#endif

#endif // HASHING_HPP
