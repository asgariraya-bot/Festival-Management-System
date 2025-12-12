#pragma once
#include <cstdint>
#include <stdexcept>

using namespace std;

// Exception for re-assigning an ID
class ReAssignmentOfId : public runtime_error 
{
public:
    ReAssignmentOfId() : runtime_error("Re-assignment of id") {}
};

// Auto-increment ID for any data type
template<typename dataType>
class AutoIncremental 
{
public:
    static int64_t last; // last assigned ID
    int64_t value;       // current ID

    AutoIncremental() : value(-1) {}

    bool isAssigned() const { return value != -1; }

    void assignNext() 
    {
        if (isAssigned()) throw ReAssignmentOfId();
        value = ++last; // assign next ID
    }

    operator int64_t() const { return value; }
};

template<typename dataType>
int64_t AutoIncremental<dataType>::last = 0; // start IDs from 1
