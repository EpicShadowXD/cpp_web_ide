#include "compile_run.h"
#include <fstream>
#include <cstdlib>

std::string compile_and_run(const std::string& code) {
    // Save code to a file
    std::ofstream out("code.cpp");
    out << code;
    out.close();

    // Compile the code
    int compile_status = system("g++ code.cpp -o code.out 2> compile_errors.txt");
    if (compile_status != 0) {
        std::ifstream error_file("compile_errors.txt");
        std::string errors((std::istreambuf_iterator<char>(error_file)), std::istreambuf_iterator<char>());
        return "Compilation Error:\n" + errors;
    }

    // Run the compiled code
    std::string result;
    FILE* fp = popen("./code.out", "r");
    if (fp) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
            result += buffer;
        }
        pclose(fp);
    }
    return result;
}
