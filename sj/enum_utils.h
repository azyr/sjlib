#ifndef ENUM_UTILS_H
#define ENUM_UTILS_H

#include <sstream>
#include <unordered_map>
#include <type_traits>
#include <stdexcept>
#include <algorithm>

namespace sj
{

template <typename T>
struct enum_hasher
{
    size_t operator()(T e) const
    {
        return static_cast<typename std::underlying_type<T>::type>(e);
    }
};

template <typename T>
struct enum_strings
{
    typedef const std::unordered_map<T, std::string,
        enum_hasher<T>> maptype;
    static maptype data;
};

template <typename T>
typename std::enable_if<std::is_enum<T>::value, std::string>::type
enum_to_string(T e)
{
    return enum_strings<T>::data.at(e);
}

template <typename T>
typename std::enable_if<std::is_enum<T>::value, T>::type
string_to_enum(const std::string& str)
{
    auto& map = enum_strings<T>::data;
    auto got = std::find_if(map.begin(), map.end(),
    [&](const std::pair<T, std::string>& x) { return x.second == str; });

    if (got != map.end())
    {
        return got->first;
    }
    std::stringstream ss;
    ss << "conversion from " << str << " to enum failed";
    throw std::invalid_argument(ss.str());
}


} // namespace sj

/******* OPERATORS ON GLOBAL NS ********/

template <typename T>
typename std::enable_if<std::is_enum<T>::value, std::ostream&>::type
operator<<(std::ostream& os, T e)
{
    return os << sj::enum_strings<T>::data.at(e);
}

//// other non-investigated implementation options would be:
//// bi-directional map or two separate maps
//template <typename T>
//typename std::enable_if<std::is_enum<T>::value, std::string&>::type
//operator>>(std::string& value, T& e)
//{
//    bool found = false;

//    for (auto itr : sj::enum_strings<T>::data)
//    {
//        if (itr.second == value)
//        {
//            e = itr.first;
//            found = true;
//        }
//    }

//    if (found)
//        return value;

//    std::stringstream ss;
//    ss << "conversion from " << value << " to enum failed";
//    throw std::invalid_argument(ss.str());
//}

//template <typename T>
//typename std::enable_if<std::is_enum<T>::value, std::istream&>::type
//operator>>(std::istream& str, T& e)
//{
//    std::string value;
//    str >> value;
//    value >> e;
//    return str;
//}

/****** QT SPECIFIC EXTENSIONS ********/

#ifdef QT_VERSION

#include <QString>

namespace sj
{

template <typename T>
typename std::enable_if<std::is_enum<T>::value, QString>::type
enum_to_qstring(T e)
{
    return QString::fromStdString(enum_strings<T>::data.at(e));
}

} // namespace sj
#endif


#endif // ENUM_UTILS_H
