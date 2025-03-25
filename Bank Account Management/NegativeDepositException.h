#ifndef NEGATIVEDEPOSITEXCEPTION_H
#define NEGATIVEDEPOSITEXCEPTION_H

#include <stdexcept>
#include <string>
using namespace std;

class NegativeDepositException : public runtime_error {
public:
    NegativeDepositException(const string& message)
        : runtime_error(message) {}
};

#endif
