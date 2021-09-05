add_subdirectory(./seq)

add_executable(pp_test pp_test.cpp)
target_link_libraries(pp_test PRIVATE ${SOURCE} range-v3 range-v3-meta range-v3::meta range-v3-concepts)

add_executable(asm_test asm_test.cpp)
target_link_libraries(asm_test PRIVATE ${SOURCE})