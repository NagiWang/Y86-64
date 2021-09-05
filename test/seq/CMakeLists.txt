add_executable(seq_reg_test seq_reg_test.cpp)
target_link_libraries(seq_reg_test PRIVATE ${SOURCE})

add_executable(seq_dmem_test seq_dmem_test.cpp)
target_link_libraries(seq_dmem_test PRIVATE ${SOURCE})

add_executable(seq_pc_test seq_pc_test.cpp)
target_link_libraries(seq_pc_test PRIVATE ${SOURCE})

add_executable(seq_test seq_test.cpp)
target_link_libraries(seq_test PRIVATE ${SOURCE})

add_executable(seq_status_test seq_status_test.cpp)
target_link_libraries(seq_status_test PRIVATE ${SOURCE})
