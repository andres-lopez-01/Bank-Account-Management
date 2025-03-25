#ifndef OVERDRAWEXCEPTION_H
#define OVERDRAWEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class OverdrawException : public runtime_error {
public:
    OverdrawException(const string& message)
        : runtime_error(message) {}
};

#endif
