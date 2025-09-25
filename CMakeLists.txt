# CMakeList.txt: проект CMake для Project1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Project1 "Project1.cpp" "Project1.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Project1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
