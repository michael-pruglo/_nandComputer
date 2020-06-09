//
// Created by Michael on 06/09/20.
//

#ifndef NANDCOMPUTER_RANDOM_HPP
#define NANDCOMPUTER_RANDOM_HPP

#include <random>

template<typename T>
class Random
{
    std::random_device dev;
    std::mt19937 rng = std::mt19937(dev());
    std::uniform_int_distribution<T> dist;
public:
    T get() { return dist(rng); }
};


#endif //NANDCOMPUTER_RANDOM_HPP
