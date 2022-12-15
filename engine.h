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

    void registerCommand(Wrapper* wrapper, const std::string& commandName);

    int execute(const std::string& commandName, const map_args& args);

private:
    std::map<std::string, Wrapper*> commands;
};
