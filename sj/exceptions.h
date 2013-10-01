#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

namespace sj
{

class not_implemented_error : public std::logic_error
{
public:
    explicit not_implemented_error(const std::string& msg)
        : std::logic_error(msg) {}
};

}

#endif // EXCEPTIONS_H
