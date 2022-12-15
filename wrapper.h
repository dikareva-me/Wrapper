#pragma once


#include <map>
#include <string>
#include <vector>
#include <functional>

using vector_pair = std::vector<std::pair<std::string, int>>;
using map_args = std::map<std::string, int>;

class Wrapper
{
public:
    template<typename Subj, typename... Args>
    Wrapper(Subj* subj, int (Subj::*func)(Args...), const vector_pair& args){
        if (subj == nullptr || func == nullptr || args.size() != sizeof...(Args))
            throw std::exception("Wrapper exception: invalid arguments");

        if (!checkArgsNames(args))
            throw std::exception("Wrapper exception: arguments' names must be unique");

        default_args = args;

        wrapped_func = [subj, func](const std::vector<int>& extractArgs){
            return callFunc(subj, func, extractArgs, std::make_index_sequence<sizeof...(Args)>{});
        };
    }

    int operator()(const map_args& args){
        return wrapped_func(extractArgs(args));
    }


    Wrapper(Wrapper const&) = delete;
    Wrapper& operator=(Wrapper const&) = delete;
    Wrapper(Wrapper&&) = default;
    Wrapper& operator=(Wrapper&&) = default;
    ~Wrapper() = default;


private:
    vector_pair default_args;

    std::function<int(const std::vector<int>&)> wrapped_func;

    std::vector<int> extractArgs(const map_args& args);

    bool checkArgsNames(const vector_pair& args);

    template<typename Subj, typename Function, size_t... Index>
    static int callFunc(Subj* instance, Function func,
        const std::vector<int>& args, std::index_sequence<Index...>)
    {
        return ((instance->*func)(args[Index]...));
    }
};
