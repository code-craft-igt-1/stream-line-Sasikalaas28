cmake_minimum_required(VERSION 3.14)
project(bms-monitor)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(DOWNLOAD_DIR "${CMAKE_BINARY_DIR}/downloads")

# Create the download directory if it doesn't exist
file(MAKE_DIRECTORY ${DOWNLOAD_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP true
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_DIR ${DOWNLOAD_DIR}
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB SOURCES "*.cpp")
add_executable(
    sender
  ${SOURCES}
)
target_link_libraries(
    sender
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(sender)
