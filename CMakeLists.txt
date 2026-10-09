cmake_minimum_required(VERSION 3.16)
project(hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC OFF)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(hello_world main.cpp)
target_link_libraries(hello_world PRIVATE Qt6::Widgets)

if(WIN32)
    set_target_properties(hello_world PROPERTIES WIN32_EXECUTABLE TRUE)

    # windeployqt ships in the Qt bin folder. Qt6_DIR is <qt>/lib/cmake/Qt6, so go up three levels
    find_program(WINDEPLOYQT windeployqt HINTS "${Qt6_DIR}/../../../bin" REQUIRED)

    # After each build, copy the Qt DLLs this exe needs next to it (debug or release set by config)
    add_custom_command(TARGET hello_world POST_BUILD
        COMMAND "${WINDEPLOYQT}" --$<IF:$<CONFIG:Debug>,debug,release> --no-translations "$<TARGET_FILE:hello_world>"
        COMMENT "Copying Qt runtime files next to the exe"
    )
endif()
