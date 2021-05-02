cmake_minimum_required(VERSION 3.17)
project(Blackjack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/chioma/Qt/6.0.2/clang_64/lib/cmake/")
find_package(Qt6Widgets REQUIRED)

add_executable(Blackjack main.cpp cards.cpp cards.h Deck.cpp Deck.h Player.cpp Player.h)
target_link_libraries(Blackjack Qt6::Widgets)


if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else ()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif ()