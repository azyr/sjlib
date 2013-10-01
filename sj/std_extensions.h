#ifndef STD_EXTENSIONS_H
#define STD_EXTENSIONS_H

#include <memory>

namespace std
{

// this will be included in future version of std...
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

} // namespace sj

#endif // STD_EXTENSIONS_H
