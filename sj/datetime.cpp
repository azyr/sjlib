#include "datetime.h"

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace boost::local_time;

const ptime EPOCH(date(1970, 1, 1));

sj::time_of_day::time_of_day(boost::posix_time::time_duration time,
                         boost::local_time::time_zone_ptr tz,
                         boost::optional<bool> dst)
    : _time(time)
    , _tz(tz)
    , _dst(dst)
{
    assert(time >= time_duration() && time < time_duration(hours(24)));
    static time_duration zerodur = time_duration(hours(0));

    // following code is only to check if dst parameter is neccessary
    if (dst)
    {
        return;
    }

    if (tz->dst_offset() < zerodur)
    {
        std::stringstream ss;
        ss << "irrational timezone: " << tz->std_zone_name()
           << " DST offset: " << tz->dst_offset();
        throw std::invalid_argument(ss.str());
    }

    static date sampledate(2000, 1, 15);

    ptime sampletime(sampledate, time);
    time_duration tz_starttime = tz->dst_local_start_time(2000).time_of_day();
    time_duration tz_endtime = tz->dst_local_end_time(2000).time_of_day();
    ptime startsample(sampledate, tz_starttime);
    if (startsample > sampletime)
    {
        startsample -= days(1);
    }
    ptime endsample(sampledate, tz_endtime);
    if (endsample < sampletime)
    {
        endsample += days(1);
    }

    time_period tpd1(startsample, tz->dst_offset());
    time_period tpd2(endsample - tz->dst_offset(), tz->dst_offset());

    if (tpd1.contains(sampletime) || tpd2.contains(sampletime))
    {
        std::stringstream ss;
        ss << "time_of_day(): dst setting is required for "
           << "tz: " << tz->std_zone_name() << " time: " << time;
        throw std::invalid_argument(ss.str());
    }
}

sj::weekday_period::weekday_period(weekday_period::weekdays start_day,
                               time_of_day start_time,
                               weekday_period::weekdays end_day,
                               time_of_day end_time)
    : _sday(start_day)
    , _stime(start_time)
    , _eday(end_day)
    , _etime(end_time)
{
    using namespace boost::posix_time;
    using namespace boost::local_time;
    using namespace boost::gregorian;

    assert(start_day >= weekdays::Sunday && start_day <= weekdays::Saturday);
    assert(end_day >= weekdays::Sunday && end_day <= weekdays::Saturday);
    if (start_day == end_day)
    {
        bool sametime = start_time.time() == end_time.time();
        bool sametz = start_time.timezone() == end_time.timezone();
        assert(!(sametime && sametz));
    }

    static date sampledate(2000, 1, 15);


    date sample_start_date = next_weekday(sampledate, greg_weekday(_sday));
    date sample_end_date = next_weekday(sample_start_date, greg_weekday(_eday));
    ptime sample_start_time(sample_start_date, _stime.time() -
                            _stime.timezone()->base_utc_offset());
    ptime sample_end_time(sample_end_date, _etime.time() -
                          _etime.timezone()->base_utc_offset());

    time_duration totaloffsets = _stime.timezone()->dst_offset() +
            _etime.timezone()->dst_offset();

    // *TODO* in certain conditions the rules need not be this strict!
    // this will be only issue when start_time and end_time are very close
    // to each other

    if (sample_end_time - sample_start_time <= totaloffsets)
    {
        throw std::invalid_argument("weekday_period(): start and end too close "
                                    "to each other");
    }

}

bool sj::weekday_period::contains(const ptime& time) const
{
    time_period tp = get_relevant_period(time);
    return tp.contains(time);
}

time_duration sj::weekday_period::passed_distance_to(const ptime& time) const
{
    static time_duration zerodur(hours(0));

    time_period tp = get_relevant_period(time);
    if (tp.contains(time))
    {
        return zerodur;
    }
    else
    {
        time_duration res = time - tp.last();
        if (res <= zerodur)
        {
            throw std::logic_error("weekday_period::distance_to(ptime): "
                                   "res <= zeroperiod, shouldn't happen");
        }
        return res;
    }
}

time_period sj::weekday_period::get_relevant_period(const ptime& time) const
{
    ptime start_time;
    day_iterator ditr(time.date() + days(1), 1);
    for (int i = 0; i < 14; i++)
    {
        if (ditr->day_of_week() == _sday)
        {
            local_date_time ldt(not_a_date_time);
            if (_stime.dst())
            {
                ldt = local_date_time(*ditr, _stime.time(), _stime.timezone(),
                                      _stime.dst().get());
            }
            else
            {
                static local_date_time::DST_CALC_OPTIONS ERR =
                        local_date_time::EXCEPTION_ON_ERROR;
                ldt = local_date_time(*ditr, _stime.time(), _stime.timezone(),
                                      ERR);
            }
            ptime start_time_candidate = ldt.utc_time();
            if (start_time_candidate < time)
            {
                start_time = start_time_candidate;
                break;
            }
        }
        --ditr;
    }
    if (start_time.is_not_a_date_time())
    {
        throw std::logic_error("weekday_period::contains(): start_time "
                               "could not be determined");
    }

    ptime end_time;
    ditr = day_iterator(start_time.date() - days(1), 1);
    for (int i = 0; i < 9; i++)
    {
        if (ditr->day_of_week() == _eday)
        {
            local_date_time ldt(not_a_date_time);
            if (_etime.dst())
            {
                ldt = local_date_time(*ditr, _etime.time(), _etime.timezone(),
                                      _etime.dst().get());
            }
            else
            {
                static local_date_time::DST_CALC_OPTIONS ERR =
                        local_date_time::EXCEPTION_ON_ERROR;
                ldt = local_date_time(*ditr, _etime.time(), _etime.timezone(),
                                      ERR);
            }
            ptime end_time_candidate = ldt.utc_time();
            if (end_time_candidate > start_time)
            {
                end_time = end_time_candidate;
                break;
            }
        }
        ++ditr;
    }
    if (end_time.is_not_a_date_time())
    {
        throw std::logic_error("weekday_period::contains(): end_time "
                               "could not be determined");
    }

    return time_period(start_time, end_time);
}

boost::posix_time::ptime sj::round(boost::posix_time::ptime dt,
                                   boost::posix_time::time_duration dur)
{
    time_duration dt_dur = dt - EPOCH;
    time_duration::tick_type dt_ms = dt_dur.total_microseconds();
    time_duration::tick_type dur_ms = dur.total_microseconds();
    time_duration::tick_type modified = (dt_ms + (dur_ms / 2) + 1) / dur_ms;
    return EPOCH + microsec(modified * dur_ms);
}


boost::posix_time::ptime sj::floor(boost::posix_time::ptime dt,
                                   boost::posix_time::time_duration dur)
{
    time_duration dt_dur = dt - EPOCH;
    time_duration::tick_type dt_ms = dt_dur.total_microseconds();
    time_duration::tick_type dur_ms = dur.total_microseconds();
    time_duration::tick_type modified = dt_ms / dur_ms;
    return EPOCH + microsec(modified * dur_ms);
}


boost::posix_time::ptime sj::ceiling(boost::posix_time::ptime dt,
                                     boost::posix_time::time_duration dur)
{
    time_duration dt_dur = dt - EPOCH;
    time_duration::tick_type dt_ms = dt_dur.total_microseconds();
    time_duration::tick_type dur_ms = dur.total_microseconds();
    time_duration::tick_type modified = (dt_ms + dur_ms - 1) / dur_ms;
    return EPOCH + microsec(modified * dur_ms);
}
