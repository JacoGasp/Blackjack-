cmake_minimum_required(VERSION 3.17)
project(Blackjack)

set(CMAKE_CXX_STANDARD 17)

add_executable(Blackjack main.cpp cards.cpp cards.h Deck.cpp Deck.h Player.cpp Player.h)


if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else ()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif ()