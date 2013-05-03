#ifndef __REF_COUNTER_HPP_INCLUDED__
#define __REF_COUNTER_HPP_INCLUDED__ 

#include "usingio.hpp"
#include <map>

class RefCounter {
public:
    static RefCounter& getInstance() {
        static RefCounter instance;
        return instance;
    }

    /* Signal that you hold a reference to 
     * the given address. */
    void use(const void* const address);

    /* Signal that you don't use anymore 
     * the value at this address.
     * Return true if nobody uses the address
     * anymore. */
    bool unuse(const void* const address);

    unsigned int getCountingFor(const void* const address);
    bool isUsed(const void* const address);

private:
    std::map<const void* const, unsigned int> counters;
    RefCounter() {}

    // Do not implement:
    RefCounter(RefCounter const&);
    void operator=(RefCounter const&);
};

#endif
