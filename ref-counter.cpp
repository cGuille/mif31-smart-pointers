#include "ref-counter.hpp"
#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>

void RefCounter::use(const void* const address) {
    try {
        counters.at(address)++;
    } catch (const std::out_of_range& oor) {
        counters[address] = 1;
    }
}

bool RefCounter::unuse(const void* const address) {
    try {
        return --counters.at(address) == 0;
    } catch (const std::out_of_range& oor) {
        cerr << "Trying to unuse an unused address: " << address << endl;
    }
    return false;
}

unsigned int RefCounter::getCountingFor(const void* const address) {
    try {
        return counters.at(address);
    } catch (const std::out_of_range& oor) {
        cerr << "Trying to get the counting of an unused address: " << address << endl;
    }
    return 0;
}

bool RefCounter::isUsed(const void* const address) {
    try {
        return counters.at(address) > 0;
    } catch (const std::out_of_range& oor) {}
    return false;
}
