find_package(SFML COMPONENTS graphics window system REQUIRED)

add_executable(snakeplusplus
    ./main.cpp
    ./gamestate.cpp
    ./snake.cpp
    ./playerinterface.cpp
    ./common.cpp
)

target_include_directories(snakeplusplus PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(snakeplusplus sfml-graphics)

