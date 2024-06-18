#include "crow.h"
#include "compile_run.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/compile").methods("POST"_method)
    ([](const crow::request& req) {
        auto code = req.body;
        auto output = compile_and_run(code);
        return crow::response(output);
    });

    app.port(8080).multithreaded().run();
}
