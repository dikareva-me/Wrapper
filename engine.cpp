#include "engine.h"


void Engine::registerCommand(Wrapper* wrapper, const std::string& command_name)
{
    if (wrapper == nullptr)
        throw std::exception("Engine exception: Wrapper does not exist");

    if (commands.find(command_name) != commands.end())
        throw std::exception("Engine exception: This command already exists");
    
    commands[command_name] = wrapper;
}

int Engine::execute(const std::string& command_name, const map_args& args)
{
    auto command_iter = commands.find(command_name);
    if (commands.end() == command_iter)
        throw std::exception("Engine exception: Unregistered command");

    return (*command_iter->second)(args);
}