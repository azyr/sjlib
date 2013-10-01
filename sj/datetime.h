#ifndef DATETIME_H
#define DATETIME_H

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/local_time/local_time.hpp"
#include "boost/optional.hpp"

namespace sj
{

class time_of_day
{
typedef boost::posix_time::time_duration time_duration;
typedef boost::posix_time::hours hours;

public:
    time_of_day(boost::posix_time::time_duration time,
                boost::local_time::time_zone_ptr tz,
                boost::optional<bool> dst = nullptr);

    const boost::local_time::time_zone_ptr timezone() const { return _tz; }
    boost::posix_time::time_duration time() const { return _time; }
    boost::optional<bool> dst() const { return _dst; }

private:
    boost::posix_time::time_duration _time;
    boost::local_time::time_zone_ptr _tz;
    boost::optional<bool> _dst;
};


class weekday_period
{
    typedef boost::posix_time::time_duration time_duration;
    typedef boost::local_time::local_date_time local_date_time;
    typedef boost::posix_time::ptime ptime;
    typedef boost::posix_time::time_period time_period;

public:
    typedef boost::date_time::weekdays weekdays;

    weekday_period(weekdays start_day, time_of_day start_time,
                   weekdays end_day, time_of_day end_time);

    // time must be UTC
    bool contains(const boost::posix_time::ptime& time) const;

    time_duration passed_distance_to(const ptime& time) const;

    /**** GETTERS/SETTERS ****/

    weekdays start_day() const { return _sday; }
    weekdays end_day() const { return _eday; }
    time_of_day start_time() const { return _stime; }
    time_of_day end_time() const { return _etime; }

private:
    time_period get_relevant_period(const ptime& time) const;

    weekdays _sday;
    time_of_day _stime;
    weekdays _eday;
    time_of_day _etime;
};

boost::posix_time::ptime round(boost::posix_time::ptime dt,
                               boost::posix_time::time_duration dur);

boost::posix_time::ptime floor(boost::posix_time::ptime dt,
                               boost::posix_time::time_duration dur);

boost::posix_time::ptime ceiling(boost::posix_time::ptime dt,
                                 boost::posix_time::time_duration dur);

} // namespace sj

#endif // DATETIME_H
