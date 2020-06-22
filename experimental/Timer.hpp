#ifndef NANDCOMPUTER_TIMER_HPP
#define NANDCOMPUTER_TIMER_HPP


#include <chrono>
#include <utility>

class Timer
{
public:
    template<typename Func, typename ...Args>
    static std::chrono::duration executionTime(Func&& f, Args&&... args)
    {
        auto start = std::chrono::high_resolution_clock::now();
        std::forward<decltype(f)>(f)(std::forward<Args>(args)...);
        return std::chrono::high_resolution_clock::now()-start;
    }
};


#endif //NANDCOMPUTER_TIMER_HPP
