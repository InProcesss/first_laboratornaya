# CMakeList.txt: проект CMake для laboratornaya7; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (laboratornaya7 "laboratornaya7.cpp" "laboratornaya7.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET laboratornaya7 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
