add_executable(chapter1 main.cpp)
target_compile_features(chapter1 PRIVATE cxx_std_17)

set_target_properties(chapter1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
