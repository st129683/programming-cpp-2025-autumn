#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>

double evaluateRPN(const std::string& expr)
{
    std::istringstream iss(expr);
    std::stack<double> st;
    std::string token;

    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);
        }
        else
        {
            st.push(std::stod(token));
        }
    }
    return st.top();
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::string line;

    while (std::getline(input, line)) {
        double result = evaluateRPN(line);
        output << line << " = " << result << std::endl;
    }

    return 0;
}
