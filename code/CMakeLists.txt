cmake_minimum_required(VERSION 3.16)

project(test)

set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/exe)

add_executable(test_hash test_multimap.cpp)

add_executable(test_242 hash_code/test_242.cc)
add_executable(test_349 hash_code/test_349.cc)
add_executable(test_202 hash_code/test_202.cc)

add_executable(test_746 dp_code/test_746.cc)
add_executable(test_343 dp_code/test_343.cc)

add_executable(test_77 back_code/test_77.cc)


add_executable(test_2 list_code/test_2.cc)


