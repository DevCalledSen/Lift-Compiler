#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";

void error(const std::string &message) {
  std::cout << RED << "Error: " << RESET << message << "\n";
}

void success(const std::string &message) {
  std::cout << GREEN << message << RESET << "\n";
}

void warning(const std::string &message) {
  std::cout << YELLOW << "Warning: " << RESET << message << "\n";
}

void usage() {
  std::cout << CYAN << "Usage:\n"
            << RESET << "  lift --version\n"
            << "  lift new <project-name>\n"
            << "  lift run\n";
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    usage();
    return 1;
  }

  std::string command = argv[1];

  if (command == "--version") {
    std::cout << "Lift compiler v0.1.0\n";
    return 0;
  }

  if (command == "new") {

    if (argc < 3) {
      error("A project name must be provided.");
      std::cout << "Try: lift new <project-name>\n";
      return 1;
    }

    if (argc > 3) {
      error("Too many arguments.");
      std::cout << "Usage: lift new <project-name>\n";
      return 1;
    }

    std::string projectName = argv[2];

    if (std::filesystem::exists(projectName)) {
      error("A file or folder with the name '" + projectName +
            "' already exists.");
      return 1;
    }

    if (!std::filesystem::create_directory(projectName)) {
      error("Unable to create project '" + projectName + "'.");
      return 1;
    }

    std::ofstream libraries(projectName + "/libraries.liftl");
    std::ofstream settings(projectName + "/settings.lifts");
    std::ofstream mainFile(projectName + "/main.lift");

    if (!libraries || !settings || !mainFile) {
      error("Unable to create one or more project files.");

      std::filesystem::remove_all(projectName);

      return 1;
    }

    libraries
        << "--- Add the libraries you want to use in your project here ---\n";

    settings << "--- Here you can modify certain compiler settings ---\n"
             << "compiler.optimization = false;\n";

    mainFile << "outputln(\"Hello, World!\");\n";

    success("Successfully created a new project '" + projectName + "'!");

    return 0;
  }

  if (command == "run") {

    if (!std::filesystem::exists("main.lift")) {
      error("No 'main.lift' file found in the current directory.");
      std::cout << "Make sure you're inside a Lift project.\n";
      return 1;
    }

    std::ifstream file("main.lift");

    if (!file) {
      error("Unable to open 'main.lift'.");
      return 1;
    }

    std::string line;

    while (std::getline(file, line)) {
      std::cout << line << "\n";
    }

    return 0;
  }

  error("Unknown command '" + command + "'.");
  usage();

  return 1;
}
