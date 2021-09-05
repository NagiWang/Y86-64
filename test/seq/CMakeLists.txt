add_executable(registers_test seq_reg_test.cpp)
target_link_libraries(registers_test PRIVATE ${SOURCE})

add_executable(dmemory_test seq_dmem_test.cpp)
target_link_libraries(dmemory_test PRIVATE ${SOURCE})

add_executable(seq_test seq_test.cpp)
target_link_libraries(seq_test PRIVATE ${SOURCE})

add_executable(pc_test seq_pc_test.cpp)
target_link_libraries(pc_test PRIVATE ${SOURCE})

add_executable(status_test seq_status_test.cpp)
target_link_libraries(status_test PRIVATE ${SOURCE})

add_executable(pp_test pp_test.cpp)
target_link_libraries(pp_test PRIVATE ${SOURCE} range-v3 range-v3-meta range-v3::meta range-v3-concepts)

add_executable(asm_test asm_test.cpp)
target_link_libraries(asm_test PRIVATE ${SOURCE})