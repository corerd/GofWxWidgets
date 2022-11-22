# Declare the minimum required CMake version
cmake_minimum_required(VERSION 3.0.0)

# Name the project
project(GofWxWidgets VERSION 0.1.0)

# wxWidgets stuff
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

# Define the list of source files for the project
set(SRC_FILES
    main.cpp
    gui.cpp
    GofEngine.cpp
    )
if(WIN32)
    # Include a RC file for windows
    list(APPEND SRC_FILES resources/sample.rc)
endif()

# Define the build target for the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
