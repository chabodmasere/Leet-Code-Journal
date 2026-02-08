#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>
#include <vector>

class Lexer {
private:
    std::string source;
    size_t position;
    size_t line;
    size_t column;
    char currentChar;
    
    void advance();
    void skipWhitespace();
    void skipComment();
    char peek(int offset = 1) const;
    
    Token number();
    Token string();
    Token character();
    Token identifier();
    
public:
    Lexer(const std::string& source);
    Token getNextToken();
    std::vector<Token> tokenize();
};

#endif // LEXER_H
