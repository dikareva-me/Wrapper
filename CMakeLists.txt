# CMakeList.txt: проект CMake для WraperDZ; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("Wraper")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Wraper "main.cpp"  "wrapper.h" "wrapper.cpp" "Subject.h" "engine.h" "engine.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.