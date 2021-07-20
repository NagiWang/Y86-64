add_executable(registers_test registers_test.cpp)
target_link_libraries(registers_test PRIVATE ${SOURCE})

add_executable(dmemory_test dmemory_test.cpp)
target_link_libraries(dmemory_test PRIVATE ${SOURCE})
