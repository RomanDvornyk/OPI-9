cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

# Опция для выбора типа библиотеки
option(USE_SHARED "Build shared library instead of static" OFF)

# Вывод выбранного типа библиотеки
message(STATUS "USE_SHARED: ${USE_SHARED}")

# Установка исходников
set(SOURCES
    lib/game.cpp
)

# Создание библиотеки
if(USE_SHARED)
    add_library(game SHARED ${SOURCES})
else()
    add_library(game STATIC ${SOURCES})
endif()

# Включаем заголовки
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Создание исполняемого файла
add_executable(tictactoe main.cpp)

# Линкуем игру с библиотекой
target_link_libraries(tictactoe PRIVATE game)
