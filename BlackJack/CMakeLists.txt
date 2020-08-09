cmake_minimum_required(VERSION 3.0.0)
project(blackJack VERSION 0.1.0)

include(CTest)
enable_testing()

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(blackJack main.cpp card.cpp deck.cpp player.cpp gameLogic.cpp)
set_property(TARGET blackJack PROPERTY CXX_STANDARD 17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
