#pragma once

#include <cmath>
#include <limits>

namespace sj
{

template <typename T>
inline double average(const T &container)
{
    double avg = 0.0;
    typename T::const_iterator it;
    for(it = container.begin(); it != container.end(); it++)
    {
        avg += *it;
    }
    avg /= container.size();
    return avg;
}

template <typename T>
inline double std(const T &container)
{
    double avg = average(container);

    return std(container, avg);
}

template <typename T>
inline double std(const T &container, const double &avg)
{
    double res = 0.0;

    typename T::const_iterator it;
    for(it = container.begin(); it != container.end(); it++)
    {
        double diff = *it - avg;
        res += diff * diff;
    }
    return std::sqrt(res / container.size());
}

template <class T>
inline bool equals(T x, T y)
{
	typedef std::numeric_limits<T> lt;
	return std::abs(x - y) < lt::epsilon();
}

// rounding to nearest "ticksize"

template <class T>
inline T round(T x, T nearest)
{
    return std::round(x / nearest) * nearest;
}

template <class T>
inline T floor(T x, T nearest)
{
    return std::floor(x / nearest) * nearest;
}

template <class T>
inline T ceiling(T x, T nearest)
{
    return std::ceil(x / nearest) * nearest;
}





} // namespace sj
