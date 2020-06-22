#ifndef NANDCOMPUTER_TESTCASES_HPP
#define NANDCOMPUTER_TESTCASES_HPP

#include <tuple>
#include <vector>
#include <functional>

template <typename... Types>
class Input
{
public:
    Input(Types... args) : arguments(std::make_tuple(args...)) {}
    template <typename Output>
    inline Output invoke(std::function<Output(Types...)> function)
    {
        return std::apply(function, arguments);
    }
private:
    std::tuple<Types...> arguments;
};

template <typename Output, typename... InputTypes>
class Benchmark
{
public:
    virtual bool test(std::function<Output(InputTypes...)> f) = 0;
    inline bool assess(const Output& given, const Output& expected)
    {
        return given == expected;
    }
};

template <typename Output, typename... InputTypes> //TODO: reverse the order
class TruthTable : public Benchmark<Output, InputTypes...>
{
public:
    typedef std::vector<std::pair<Input<InputTypes...>, Output>> table_t;
public:
    TruthTable(table_t table) : data(table) {}
    bool test(std::function<Output(InputTypes...)> f) override;
private:
    table_t data;
};

template <typename Output, typename... InputTypes>
class Standard : public Benchmark<Output, InputTypes...>
{
public:
    Standard(std::function<Output(InputTypes...)> standardFunction,
             std::function<Input<InputTypes...>()> inputGenerator,
             int thoroughness) :
        standardf(standardFunction),
        inputGenerator(inputGenerator),
        thoroughness(thoroughness)
    {}
    bool test(std::function<Output(InputTypes...)> f) override;

private:
    std::function<Output(InputTypes...)> standardf;
    std::function<Input<InputTypes...>()> inputGenerator;
    int thoroughness;
};

template <typename Output, typename... InputTypes>
class Testcase
{
public:
                Testcase(std::function<Output(InputTypes...)> function, Benchmark<Output, InputTypes...>* benchmark);
                Testcase(const std::vector<std::function<Output(InputTypes...)>>& functions, //variants of the same function
                         Benchmark<Output, InputTypes...>* benchmark);
    bool        run();
private:
    std::vector<std::function<Output(InputTypes...)>> fvector;
    Benchmark<Output, InputTypes...>* benchmark;
};

///===================================================IMPLEMENTATION===================================================
template<typename Output, typename... InputTypes>
Testcase<Output, InputTypes...>::Testcase(std::function<Output(InputTypes...)> function, Benchmark<Output, InputTypes...>* benchmark) :
    fvector({function}),
    benchmark(benchmark)
{
}

template<typename Output, typename... InputTypes>
Testcase<Output, InputTypes...>::Testcase(const std::vector<std::function<Output(InputTypes...)>>& functions,
                                          Benchmark<Output, InputTypes...>* benchmark) :
    fvector(functions),
    benchmark(benchmark)
{
}

template<typename Output, typename... InputTypes>
bool Testcase<Output, InputTypes...>::run()
{
    bool success = true;
    for (auto& f: fvector)
        success &= benchmark->test(f);
    return success;
}

template<typename Output, typename... InputTypes>
bool TruthTable<Output, InputTypes...>::test(std::function<Output(InputTypes...)> f)
{
    bool success = true;
    for (auto [in, out]: data)
        success &= this->assess(in.invoke(f), out);
    return success;
}

template<typename Output, typename... InputTypes>
bool Standard<Output, InputTypes...>::test(std::function<Output(InputTypes...)> f)
{
    bool success = true;
    for (int i = 0; i < thoroughness; ++i)
    {
        auto in = inputGenerator();
        success &= this->assess(in.invoke(f), in.invoke(standardf));
    }
    return success;
}


#endif //NANDCOMPUTER_TESTCASES_HPP
