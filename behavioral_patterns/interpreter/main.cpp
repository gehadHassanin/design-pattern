#include <iostream>
#include <string>
#include "calculator.h"

int main() {
    std::string expression = "1 + 2 * 4";

    // interpreter
    Context context;
    Interpreter interpreter(context);

    // Interpret expression
    int32_t result =  interpreter.interpret(expression);
    std::cout << "the result = " << result << std::endl;

    return 0;
}