#ifndef QTUTILS_H
#define QTUTILS_H

#include <QVariant>

namespace sj
{

template <typename T>
T* QVariantToVPtr(QVariant v)
{
    return (T*)v.value<void*>();
}

template <typename T>
QVariant VPtrToQVariant(T* ptr)
{
    return qVariantFromValue((void*)ptr);
}

} // namespace sj

#endif // QTUTILS_H
