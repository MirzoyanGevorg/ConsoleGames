cmake_minimum_required(VERSION 3.0.0)
project(durak VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(durak main.cpp card.cpp deck.cpp 
                game.cpp humanPlayer.cpp smartAI.cpp stupidAI.cpp)
set_property(TARGET durak PROPERTY CXX_STANDARD 20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
