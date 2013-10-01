#ifndef RAPI_EXTENSIONS_H
#define RAPI_EXTENSIONS_H

#include "RApi.h"

#include <chrono>
#include <string>
#include <ostream>

namespace RApi
{

typedef tsNCharcb RString;

// these are missing from RApi.h...
/******* CUSTOM DEFINED CONSTANTS *********/

const RString sMARKET_MODE_OPEN = {(char*)"Open", 4};

const RString sTRADEREPLAY_RESULT_OK = {(char*)"ok", 2};
const RString sTRADEREPLAY_RESULT_NO_DATA = {(char*)"no data", 7};


/******************************************/

class RTime
{
    typedef std::chrono::seconds secs;
    typedef std::chrono::microseconds usecs;
    typedef std::chrono::system_clock sysc;
    typedef std::chrono::time_point<sysc, usecs> mytp;
public:
    /***** CONSTRUCTORS ******************/

    RTime(const int ssincepoch, const int microsecs)
        : _tp(secs(ssincepoch) + usecs(microsecs)) {}
    RTime(const RTime& other) : _tp(other._tp) {}
    RTime& operator=(const RTime& other)
    {
        _tp = other._tp;
        return *this;
    }

    /***** OPERATOR OVERLOADS ************/

    mytp operator+(const mytp::duration &dur) const
    {
        return _tp + dur;
    }

    mytp operator-(const mytp::duration &dur) const
    {
        return _tp - dur;
    }
    bool operator==(const mytp &other) const
    {
        return _tp == other;
    }
    bool operator!=(const mytp &other) const
    {
        return _tp != other;
    }
    bool operator<(const mytp &other) const
    {
        return _tp < other;
    }
    bool operator<=(const mytp &other) const
    {
        return _tp <= other;
    }
    bool operator>(const mytp &other) const
    {
        return _tp > other;
    }
    bool operator>=(const mytp &other) const
    {
        return _tp >= other;
    }

    /***** STATIC FUNCTIONS *************/

    static RTime min_value() { return RTime(0, 0); }

    /***** PUBLIC MEMBER FUNCTIONS **************/

    std::string to_string(const char* format) const;
    std::string to_string_usecs() const;
    std::string to_string_long() const;

private:
    mytp _tp;
};

class REngineLockable
{
public:
    REngineLockable(RApi::REngine* engine)
        : _engine(engine)
    {}
    void lock();
    void unlock();

private:
    RApi::REngine* _engine;
};

RString rstrcpy(const RString &rapistr);
RString string_to_rstring(const std::string& str);
void accinfo_cpy(const AccountInfo &accinfo, AccountInfo& res);

bool operator==(const RApi::RString& s1, const RApi::RString& s2);


std::ostream& operator<<(std::ostream& stream, const RApi::TradeInfo* info);
std::ostream& operator<<(std::ostream& stream, const RApi::LineInfo* info);
std::ostream& operator<<(std::ostream& stream, const RApi::OrderFillReport* info);
std::ostream& operator<<(std::ostream& stream, const RApi::PnlInfo* info);
std::ostream& operator<<(std::ostream& stream, const RApi::ProductRmsInfo* info);
std::ostream& operator<<(std::ostream& stream, const RApi::BidInfo* info);
std::ostream& operator<<(std::ostream& stream, const RApi::AskInfo* info);

} // namespace RApi

// I believe this has to be in global namespace because tsNCharcb is defined in it...
std::ostream& operator<<(std::ostream& stream, const RApi::RString& str);


#endif // RAPI_EXTENSIONS_H
