#include "compiler/lexer.h"
#include "compiler/parser.h"
#include "compiler/interpreter.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " [options] <source_file>\n";
    std::cout << "Options:\n";
    std::cout << "  -t, --tokens    Print tokens only\n";
    std::cout << "  -p, --parse     Parse and show AST only\n";
    std::cout << "  -r, --run       Run the program (default)\n";
    std::cout << "  -h, --help      Show this help message\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }
    
    std::string filename;
    bool showTokens = false;
    bool parseOnly = false;
    bool run = true;
    
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return 0;
        } else if (arg == "-t" || arg == "--tokens") {
            showTokens = true;
            run = false;
        } else if (arg == "-p" || arg == "--parse") {
            parseOnly = true;
            run = false;
        } else if (arg == "-r" || arg == "--run") {
            run = true;
        } else if (arg[0] != '-') {
            filename = arg;
        } else {
            std::cerr << "Unknown option: " << arg << std::endl;
            printUsage(argv[0]);
            return 1;
        }
    }
    
    if (filename.empty()) {
        std::cerr << "Error: No source file specified\n";
        printUsage(argv[0]);
        return 1;
    }
    
    try {
        // Read source file
        std::string source = readFile(filename);
        
        // Lexical analysis
        Lexer lexer(source);
        std::vector<Token> tokens = lexer.tokenize();
        
        if (showTokens) {
            std::cout << "=== TOKENS ===\n";
            for (const auto& token : tokens) {
                std::cout << token.toString() << std::endl;
            }
            return 0;
        }
        
        // Parsing
        Parser parser(tokens);
        auto program = parser.parse();
        
        if (parseOnly) {
            std::cout << "=== PARSING SUCCESSFUL ===\n";
            std::cout << "Functions: " << program->functions.size() << std::endl;
            std::cout << "Global statements: " << program->globalStatements.size() << std::endl;
            return 0;
        }
        
        // Interpretation
        if (run) {
            Interpreter interpreter;
            interpreter.interpret(program.get());
        }
        
    } catch (const ParseError& e) {
        std::cerr << "Parse Error: " << e.what() << std::endl;
        return 1;
    } catch (const RuntimeError& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
