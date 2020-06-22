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
    Output invoke(std::function<Output(Types...)> function)
    {
        return std::apply(function, arguments);
    }
private:
    std::tuple<Types...> arguments;
};

template <typename Output, typename... InputTypes>
class Benchmark { };

template <typename Output, typename... InputTypes> //TODO: reverse the order
struct TruthTable : public Benchmark<Output, InputTypes...>
{
    TruthTable(std::vector<std::pair<Input<InputTypes...>, Output>> table) : data(table) {}
    std::vector<std::pair<Input<InputTypes...>, Output>> data;
};
template <typename Output, typename... InputTypes>
struct Standard : public Benchmark<Output, InputTypes...>
{
    Standard(std::function<Output(InputTypes...)> standardFunction,
             std::function<Input<InputTypes...>()> inputGenerator,
             int thoroughness) :
        f(standardFunction),
        inputGenerator(inputGenerator),
        thoroughness(thoroughness)
    {}
    std::function<Output(InputTypes...)> f;
    std::function<Input<InputTypes...>()> inputGenerator;
    int thoroughness;
};

template <typename Output, typename... InputTypes>
class Testcase
{
public:
                Testcase(std::function<Output(InputTypes...)> function, Benchmark<Output, InputTypes...>&& benchmark);
                Testcase(const std::vector<std::function<Output(InputTypes...)>>& functions, Benchmark<Output, InputTypes...>&& benchmark); //variants of the same function
    bool        run();
private:
    bool        run(std::function<Output(InputTypes...)> f, TruthTable<Output, InputTypes...>& tt);
    bool        run(std::function<Output(InputTypes...)> f, Standard<Output, InputTypes...>& standard);
    inline bool assess(const Output& out1, const Output& out2)
    {
        return out1 == out2;
    }
private:
    std::vector<std::function<Output(InputTypes...)>> fvector;
    Benchmark<Output, InputTypes...>& benchmark;
};

///===================================================IMPLEMENTATION===================================================
template<typename Output, typename... InputTypes>
Testcase<Output, InputTypes...>::Testcase(std::function<Output(InputTypes...)> function, Benchmark<Output, InputTypes...>&& benchmark) :
    fvector({function}),
    benchmark(benchmark)
{
}

template<typename Output, typename... InputTypes>
Testcase<Output, InputTypes...>::Testcase(const std::vector<std::function<Output(InputTypes...)>>& functions,
                                          Benchmark<Output, InputTypes...>&& benchmark) :
    fvector(functions),
    benchmark(benchmark)
{
}

template<typename Output, typename... InputTypes>
bool Testcase<Output, InputTypes...>::run()
{
    bool success = true;
    for (auto& f: fvector)
        success &= run(f, benchmark); //TODO: polymorphism by references?
    return success;
}

template<typename Output, typename... InputTypes>
bool Testcase<Output, InputTypes...>::run(std::function<Output(InputTypes...)> f, TruthTable<Output, InputTypes...>& tt)
{
    bool success = true;
    for (auto& [in, out]: tt.data)
        success &= assess(in.invoke(f), out);
    return success;
}

template<typename Output, typename... InputTypes>
bool Testcase<Output, InputTypes...>::run(std::function<Output(InputTypes...)> f, Standard<Output, InputTypes...>& standard)
{
    bool success = true;
    for (int i = 0; i < standard.thoroughness; ++i)
    {
        auto in = standard.inputGenerator();
        success &= assess(in.invoke(f), in.invoke(standard.f));
    }
    return success;
}



#endif //NANDCOMPUTER_TESTCASES_HPP
