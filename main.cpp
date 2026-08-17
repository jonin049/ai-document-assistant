#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("sample-data/example-document.txt");

    if (!file.is_open()) {
        std::cout << "Could not open the document." << std::endl;
        return 1;
    }

    std::string line;

    std::string company;
    std::string project;
    std::string budget;
    std::string deadline;

    while (std::getline(file, line)) {

        if (line.find("Company:") == 0) {
            company = line.substr(9);
        }

        if (line.find("Project:") == 0) {
            project = line.substr(9);
        }

        if (line.find("budget is ") != std::string::npos) {
            size_t position = line.find("budget is ");
            budget = line.substr(position + 10);

            if (!budget.empty() && budget.back() == '.') {
                budget.pop_back();
            }
        }

        if (line.find("deadline is ") != std::string::npos) {
            size_t position = line.find("deadline is ");
            deadline = line.substr(position + 12);

            if (!deadline.empty() && deadline.back() == '.') {
                deadline.pop_back();
            }
        }
    }

    file.close();

    std::cout << "{" << std::endl;
    std::cout << "  \"company\": \"" << company << "\"," << std::endl;
    std::cout << "  \"project\": \"" << project << "\"," << std::endl;
    std::cout << "  \"budget\": \"" << budget << "\"," << std::endl;
    std::cout << "  \"deadline\": \"" << deadline << "\"" << std::endl;
    std::cout << "}" << std::endl;

    return 0;
}
