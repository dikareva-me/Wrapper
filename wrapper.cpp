#include "wrapper.h"

std::vector<int> Wrapper::extractArgs(const map_args& args) {
    std::vector<int> extracted_args;
    extracted_args.reserve(default_args.size());

    for (auto it = default_args.begin(); it != default_args.end(); it++) {
        auto check_iter = args.find(it->first);
        if (args.end() != check_iter)
            extracted_args.emplace_back(check_iter->second);
        else
            extracted_args.emplace_back(it->second);
    }
    return extracted_args;
}

bool Wrapper::checkArgsNames(const vector_pair& args) {
    for (int i = 0; i < args.size(); i++)
        for (int j = i + 1; j < args.size(); j++)
            if (args[i].first == args[j].first)
                return false;
    return true;
}