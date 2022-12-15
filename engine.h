#pragma once


#include "wrapper.h"

class Engine
{
public:
	Engine() = default;
	Engine(Engine const&) = delete;
	Engine& operator =(Engine const&) = delete;
	Engine(Engine&&) = default;
	Engine& operator =(Engine&&) = default;
	~Engine() = default;

    void registerCommand(Wrapper* wrapper, const std::string& command_name);

    int execute(const std::string& command_name, const map_args& args);

private:
    std::map<std::string, Wrapper*> commands;
};
