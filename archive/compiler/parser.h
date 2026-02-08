#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "ast.h"
#include <vector>
#include <memory>
#include <stdexcept>

class Parser {
private:
    std::vector<Token> tokens;
    size_t position;
    Token currentToken;
    
    void advance();
    Token peek(int offset = 1) const;
    bool match(TokenType type);
    bool check(TokenType type) const;
    void expect(TokenType type, const std::string& message);
    
    // Parsing methods
    std::unique_ptr<Program> parseProgram();
    std::unique_ptr<FunctionDeclaration> parseFunctionDeclaration();
    std::unique_ptr<Statement> parseStatement();
    std::unique_ptr<Block> parseBlock();
    std::unique_ptr<Statement> parseVariableDeclaration();
    std::unique_ptr<Statement> parseIfStatement();
    std::unique_ptr<Statement> parseWhileStatement();
    std::unique_ptr<Statement> parseForStatement();
    std::unique_ptr<Statement> parseReturnStatement();
    std::unique_ptr<Statement> parseCoutStatement();
    std::unique_ptr<Statement> parseCinStatement();
    std::unique_ptr<Statement> parseExpressionStatement();
    
    std::unique_ptr<Expression> parseExpression();
    std::unique_ptr<Expression> parseLogicalOr();
    std::unique_ptr<Expression> parseLogicalAnd();
    std::unique_ptr<Expression> parseEquality();
    std::unique_ptr<Expression> parseComparison();
    std::unique_ptr<Expression> parseAddition();
    std::unique_ptr<Expression> parseMultiplication();
    std::unique_ptr<Expression> parseUnary();
    std::unique_ptr<Expression> parsePrimary();
    std::unique_ptr<Expression> parsePostfix();
    
public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<Program> parse();
};

class ParseError : public std::runtime_error {
public:
    ParseError(const std::string& message) : std::runtime_error(message) {}
};

#endif // PARSER_H
