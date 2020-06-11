//
// Created by Michael on 06/09/20.
//

#ifndef NANDCOMPUTER_TIMER_HPP
#define NANDCOMPUTER_TIMER_HPP

#include <chrono>
#include <utility>

template<typename TimeT = std::chrono::nanoseconds>
class Timer
{
public:
    template<typename F, typename ...Args>
    static auto duration(F&& func, Args&&... args)
    {
        auto start = std::chrono::steady_clock::now();
        std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
        return std::chrono::duration_cast<TimeT>(std::chrono::steady_clock::now()-start);
    }

    template<typename F, typename ...Args>
    static auto durationCounted(F&& func, Args&&... args)
    {
        return duration(func, args...).count();
    }

    template<typename F, typename ...Args>
    static auto exhaustive(int N, F&& func, Args&&... args)
    {
        auto x = duration(func, args...);
        for (int i = 0; i < N-1; ++i)
            x += duration(func, args...);
        x /= N;
        return x.count();
    }


    template<typename F, typename ...Args>
    static auto timens(int N, F&& foo, Args&&... args)
    {
        return Timer<std::chrono::nanoseconds>::exhaustive(N,
                                                           foo, args...);
    }
    template<typename F>
    static auto timens1arg(int N, F&& foo)
    {
        long long res = 0;
        for (auto arg1: {0, 1})
            res += Timer<std::chrono::nanoseconds>::exhaustive(N,
                                                               foo, arg1);
        return res/2;
    }
    template<typename F>
    static auto timens2arg(int N, F&& foo)
    {
        long long res = 0;
        for (auto arg1: {0, 1})
            for (auto arg2: {0, 1})
                res += Timer<std::chrono::nanoseconds>::exhaustive(N,
                                                                   foo, arg1, arg2);
        return res/4;
    }
    template<typename F>
    static auto timens3arg(int N, F&& foo)
    {
        long long res = 0;
        for (auto arg1: {0, 1})
            for (auto arg2: {0, 1})
                for (auto arg3: {0, 1})
                    res += Timer<std::chrono::nanoseconds>::exhaustive(N,
                                                                       foo, arg1, arg2, arg3);
        return res/8;
    }
};


#endif //NANDCOMPUTER_TIMER_HPP
