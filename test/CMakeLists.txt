add_executable(registers_test registers_test.cpp)
target_link_libraries(registers_test PRIVATE ${SOURCE})

add_executable(dmemory_test dmemory_test.cpp)
target_link_libraries(dmemory_test PRIVATE ${SOURCE})

add_executable(y86_test y86_test.cpp)
target_link_libraries(y86_test PRIVATE ${SOURCE})

add_executable(pc_test pc_test.cpp)
target_link_libraries(pc_test PRIVATE ${SOURCE})

add_executable(status_test status_test.cpp)
target_link_libraries(status_test PRIVATE ${SOURCE})

add_executable(run_test run_test.cpp)
target_link_libraries(run_test PRIVATE ${SOURCE})
