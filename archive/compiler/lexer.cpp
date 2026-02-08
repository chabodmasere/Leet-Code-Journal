#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& source) 
    : source(source), position(0), line(1), column(1) {
    currentChar = source.empty() ? '\0' : source[0];
}

void Lexer::advance() {
    if (currentChar == '\n') {
        line++;
        column = 1;
    } else {
        column++;
    }
    
    position++;
    if (position >= source.length()) {
        currentChar = '\0';
    } else {
        currentChar = source[position];
    }
}

char Lexer::peek(int offset) const {
    size_t peekPos = position + offset;
    if (peekPos >= source.length()) {
        return '\0';
    }
    return source[peekPos];
}

void Lexer::skipWhitespace() {
    while (currentChar != '\0' && std::isspace(currentChar)) {
        advance();
    }
}

void Lexer::skipComment() {
    if (currentChar == '/' && peek() == '/') {
        // Single-line comment
        while (currentChar != '\0' && currentChar != '\n') {
            advance();
        }
    } else if (currentChar == '/' && peek() == '*') {
        // Multi-line comment
        advance(); // skip '/'
        advance(); // skip '*'
        while (currentChar != '\0') {
            if (currentChar == '*' && peek() == '/') {
                advance(); // skip '*'
                advance(); // skip '/'
                break;
            }
            advance();
        }
    }
}

Token Lexer::number() {
    int startLine = line;
    int startColumn = column;
    std::string num;
    bool isFloat = false;
    
    while (currentChar != '\0' && (std::isdigit(currentChar) || currentChar == '.')) {
        if (currentChar == '.') {
            if (isFloat) break; // Second dot, stop
            isFloat = true;
        }
        num += currentChar;
        advance();
    }
    
    return Token(isFloat ? TokenType::FLOAT : TokenType::INTEGER, 
                 num, startLine, startColumn);
}

Token Lexer::string() {
    int startLine = line;
    int startColumn = column;
    std::string str;
    
    advance(); // skip opening quote
    
    while (currentChar != '\0' && currentChar != '"') {
        if (currentChar == '\\') {
            advance();
            switch (currentChar) {
                case 'n': str += '\n'; break;
                case 't': str += '\t'; break;
                case 'r': str += '\r'; break;
                case '\\': str += '\\'; break;
                case '"': str += '"'; break;
                default: str += currentChar;
            }
        } else {
            str += currentChar;
        }
        advance();
    }
    
    if (currentChar == '"') {
        advance(); // skip closing quote
    }
    
    return Token(TokenType::STRING, str, startLine, startColumn);
}

Token Lexer::character() {
    int startLine = line;
    int startColumn = column;
    std::string ch;
    
    advance(); // skip opening quote
    
    if (currentChar == '\\') {
        advance();
        switch (currentChar) {
            case 'n': ch = "\n"; break;
            case 't': ch = "\t"; break;
            case 'r': ch = "\r"; break;
            case '\\': ch = "\\"; break;
            case '\'': ch = "'"; break;
            default: ch = std::string(1, currentChar);
        }
        advance();
    } else if (currentChar != '\'') {
        ch = std::string(1, currentChar);
        advance();
    }
    
    if (currentChar == '\'') {
        advance(); // skip closing quote
    }
    
    return Token(TokenType::CHAR, ch, startLine, startColumn);
}

Token Lexer::identifier() {
    int startLine = line;
    int startColumn = column;
    std::string id;
    
    while (currentChar != '\0' && (std::isalnum(currentChar) || currentChar == '_')) {
        id += currentChar;
        advance();
    }
    
    // Check if it's a keyword
    auto it = keywords.find(id);
    if (it != keywords.end()) {
        return Token(it->second, id, startLine, startColumn);
    }
    
    return Token(TokenType::IDENTIFIER, id, startLine, startColumn);
}

Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        if (std::isspace(currentChar)) {
            skipWhitespace();
            continue;
        }
        
        if (currentChar == '/' && (peek() == '/' || peek() == '*')) {
            skipComment();
            continue;
        }
        
        int startLine = line;
        int startColumn = column;
        
        // Numbers
        if (std::isdigit(currentChar)) {
            return number();
        }
        
        // Identifiers and keywords
        if (std::isalpha(currentChar) || currentChar == '_') {
            return identifier();
        }
        
        // String literals
        if (currentChar == '"') {
            return string();
        }
        
        // Character literals
        if (currentChar == '\'') {
            return character();
        }
        
        // Two-character operators
        if (currentChar == '+') {
            advance();
            if (currentChar == '+') {
                advance();
                return Token(TokenType::INCREMENT, "++", startLine, startColumn);
            } else if (currentChar == '=') {
                advance();
                return Token(TokenType::PLUS_ASSIGN, "+=", startLine, startColumn);
            }
            return Token(TokenType::PLUS, "+", startLine, startColumn);
        }
        
        if (currentChar == '-') {
            advance();
            if (currentChar == '-') {
                advance();
                return Token(TokenType::DECREMENT, "--", startLine, startColumn);
            } else if (currentChar == '=') {
                advance();
                return Token(TokenType::MINUS_ASSIGN, "-=", startLine, startColumn);
            } else if (currentChar == '>') {
                advance();
                return Token(TokenType::ARROW, "->", startLine, startColumn);
            }
            return Token(TokenType::MINUS, "-", startLine, startColumn);
        }
        
        if (currentChar == '=') {
            advance();
            if (currentChar == '=') {
                advance();
                return Token(TokenType::EQUAL, "==", startLine, startColumn);
            }
            return Token(TokenType::ASSIGN, "=", startLine, startColumn);
        }
        
        if (currentChar == '!') {
            advance();
            if (currentChar == '=') {
                advance();
                return Token(TokenType::NOT_EQUAL, "!=", startLine, startColumn);
            }
            return Token(TokenType::NOT, "!", startLine, startColumn);
        }
        
        if (currentChar == '<') {
            advance();
            if (currentChar == '=') {
                advance();
                return Token(TokenType::LESS_EQUAL, "<=", startLine, startColumn);
            } else if (currentChar == '<') {
                advance();
                return Token(TokenType::LSHIFT, "<<", startLine, startColumn);
            }
            return Token(TokenType::LESS, "<", startLine, startColumn);
        }
        
        if (currentChar == '>') {
            advance();
            if (currentChar == '=') {
                advance();
                return Token(TokenType::GREATER_EQUAL, ">=", startLine, startColumn);
            } else if (currentChar == '>') {
                advance();
                return Token(TokenType::RSHIFT, ">>", startLine, startColumn);
            }
            return Token(TokenType::GREATER, ">", startLine, startColumn);
        }
        
        if (currentChar == '&') {
            advance();
            if (currentChar == '&') {
                advance();
                return Token(TokenType::AND, "&&", startLine, startColumn);
            }
            return Token(TokenType::UNKNOWN, "&", startLine, startColumn);
        }
        
        if (currentChar == '|') {
            advance();
            if (currentChar == '|') {
                advance();
                return Token(TokenType::OR, "||", startLine, startColumn);
            }
            return Token(TokenType::UNKNOWN, "|", startLine, startColumn);
        }
        
        if (currentChar == ':') {
            advance();
            if (currentChar == ':') {
                advance();
                return Token(TokenType::SCOPE, "::", startLine, startColumn);
            }
            return Token(TokenType::UNKNOWN, ":", startLine, startColumn);
        }
        
        // Single-character tokens
        char ch = currentChar;
        advance();
        
        switch (ch) {
            case '*': return Token(TokenType::MULTIPLY, "*", startLine, startColumn);
            case '/': return Token(TokenType::DIVIDE, "/", startLine, startColumn);
            case '%': return Token(TokenType::MODULO, "%", startLine, startColumn);
            case '(': return Token(TokenType::LPAREN, "(", startLine, startColumn);
            case ')': return Token(TokenType::RPAREN, ")", startLine, startColumn);
            case '{': return Token(TokenType::LBRACE, "{", startLine, startColumn);
            case '}': return Token(TokenType::RBRACE, "}", startLine, startColumn);
            case '[': return Token(TokenType::LBRACKET, "[", startLine, startColumn);
            case ']': return Token(TokenType::RBRACKET, "]", startLine, startColumn);
            case ';': return Token(TokenType::SEMICOLON, ";", startLine, startColumn);
            case ',': return Token(TokenType::COMMA, ",", startLine, startColumn);
            case '.': return Token(TokenType::DOT, ".", startLine, startColumn);
            default: return Token(TokenType::UNKNOWN, std::string(1, ch), startLine, startColumn);
        }
    }
    
    return Token(TokenType::END_OF_FILE, "", line, column);
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    Token token = getNextToken();
    
    while (token.type != TokenType::END_OF_FILE) {
        tokens.push_back(token);
        token = getNextToken();
    }
    
    tokens.push_back(token); // Add EOF token
    return tokens;
}
