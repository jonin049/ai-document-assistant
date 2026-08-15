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

        if (line.find("budget is") != std::string::npos) {
            budget = line;
        }

        if (line.find("completion deadline") != std::string::npos) {
            deadline = line;
        }
    }

    file.close();

    std::cout << "Document Analysis" << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "Company: " << company << std::endl;
    std::cout << "Project: " << project << std::endl;
    std::cout << "Budget: " << budget << std::endl;
    std::cout << "Deadline: " << deadline << std::endl;

    return 0;
}
