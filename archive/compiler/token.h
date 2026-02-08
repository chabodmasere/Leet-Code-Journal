#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <map>

enum class TokenType {
    // Literals
    INTEGER,
    FLOAT,
    STRING,
    CHAR,
    TRUE,
    FALSE,
    
    // Identifiers and Keywords
    IDENTIFIER,
    INT,
    FLOAT_TYPE,
    CHAR_TYPE,
    BOOL,
    VOID,
    IF,
    ELSE,
    WHILE,
    FOR,
    RETURN,
    COUT,
    CIN,
    ENDL,
    
    // Operators
    PLUS,           // +
    MINUS,          // -
    MULTIPLY,       // *
    DIVIDE,         // /
    MODULO,         // %
    ASSIGN,         // =
    EQUAL,          // ==
    NOT_EQUAL,      // !=
    LESS,           // <
    GREATER,        // >
    LESS_EQUAL,     // <=
    GREATER_EQUAL,  // >=
    AND,            // &&
    OR,             // ||
    NOT,            // !
    INCREMENT,      // ++
    DECREMENT,      // --
    PLUS_ASSIGN,    // +=
    MINUS_ASSIGN,   // -=
    
    // Delimiters
    LPAREN,         // (
    RPAREN,         // )
    LBRACE,         // {
    RBRACE,         // }
    LBRACKET,       // [
    RBRACKET,       // ]
    SEMICOLON,      // ;
    COMMA,          // ,
    DOT,            // .
    ARROW,          // ->
    SCOPE,          // ::
    LSHIFT,         // <<
    RSHIFT,         // >>
    
    // Special
    END_OF_FILE,
    UNKNOWN
};

class Token {
public:
    TokenType type;
    std::string value;
    int line;
    int column;
    
    Token(TokenType type, const std::string& value, int line, int column)
        : type(type), value(value), line(line), column(column) {}
    
    std::string toString() const;
    static std::string typeToString(TokenType type);
};

// Keyword map
static const std::map<std::string, TokenType> keywords = {
    {"int", TokenType::INT},
    {"float", TokenType::FLOAT_TYPE},
    {"char", TokenType::CHAR_TYPE},
    {"bool", TokenType::BOOL},
    {"void", TokenType::VOID},
    {"if", TokenType::IF},
    {"else", TokenType::ELSE},
    {"while", TokenType::WHILE},
    {"for", TokenType::FOR},
    {"return", TokenType::RETURN},
    {"true", TokenType::TRUE},
    {"false", TokenType::FALSE},
    {"cout", TokenType::COUT},
    {"cin", TokenType::CIN},
    {"endl", TokenType::ENDL}
};

#endif // TOKEN_H
