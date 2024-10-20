cmake_minimum_required(VERSION 3.5)

project(01_01_binary_gap LANGUAGES C)

add_executable(01_01_binary_gap main.c)

include(GNUInstallDirs)
target_link_libraries(${PROJECT_NAME} -lunity)
install(TARGETS 01_01_binary_gap
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
