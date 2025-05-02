add_executable(chapter0 main.cpp)
target_compile_features(chapter0 PRIVATE cxx_std_17)

set_target_properties(chapter0 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
