#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

const std::string chapters_dir = "src";
const std::string cmake_filename = "CMakeLists.txt";
const std::string main_cpp = "main.cpp";

namespace fs = std::filesystem;

const std::string cmake_template = R"(add_executable({chapter} main.cpp)
target_compile_features({chapter} PRIVATE cxx_std_17)

set_target_properties({chapter} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
)";

void generate_cmakelists(const fs::path &chapter_path, const std::string &chapter_name) {
    fs::path cmake_path = chapter_path / cmake_filename;

    if (fs::exists(cmake_path)) {
        std::cout << "[SKIP] " << cmake_path << " already exists.\n";

        return;
    }

    std::ofstream out(cmake_path);

    if (!out) {
        std::cerr << "[ERROR] Failed to write " << cmake_path << ".\n";

        return;
    }

    std::string content = cmake_template;
    size_t pos;

    while ((pos = content.find("{chapter}")) != std::string::npos) {
        content.replace(pos, 9, chapter_name);
    }

    out << content;
    std::cout << "[GEN]  " << cmake_path << " created.\n";
}

int main() {
    std::regex chapter_pattern("^chapter[0-9]+$");

    for (const auto &entry : fs::directory_iterator(chapters_dir)) {
        if (!entry.is_directory()) {
            continue;
        }

        std::string name = entry.path().filename().string();

        if (!std::regex_match(name, chapter_pattern)) {
            continue;
        }

        fs::path main_path = entry.path() / main_cpp;

        if (!fs::exists(main_path)) {
            std::cout << "[SKIP] " << name << " has no main.cpp.\n";

            continue;
        }

        generate_cmakelists(entry.path(), name);
    }

    return 0;
}
