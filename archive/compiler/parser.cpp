#include "parser.h"
#include <sstream>

Parser::Parser(const std::vector<Token>& tokens) 
    : tokens(tokens), position(0) {
    if (!tokens.empty()) {
        currentToken = tokens[0];
    }
}

void Parser::advance() {
    if (position < tokens.size() - 1) {
        position++;
        currentToken = tokens[position];
    }
}

Token Parser::peek(int offset) const {
    size_t peekPos = position + offset;
    if (peekPos < tokens.size()) {
        return tokens[peekPos];
    }
    return tokens.back(); // Return EOF
}

bool Parser::match(TokenType type) {
    if (check(type)) {
        advance();
        return true;
    }
    return false;
}

bool Parser::check(TokenType type) const {
    return currentToken.type == type;
}

void Parser::expect(TokenType type, const std::string& message) {
    if (!match(type)) {
        std::ostringstream oss;
        oss << "Parse error at line " << currentToken.line 
            << ", column " << currentToken.column << ": " << message
            << ". Got " << Token::typeToString(currentToken.type);
        throw ParseError(oss.str());
    }
}

std::unique_ptr<Program> Parser::parse() {
    return parseProgram();
}

std::unique_ptr<Program> Parser::parseProgram() {
    auto program = std::make_unique<Program>();
    
    while (!check(TokenType::END_OF_FILE)) {
        // Check if it's a function declaration
        if ((check(TokenType::INT) || check(TokenType::VOID) || 
             check(TokenType::FLOAT_TYPE) || check(TokenType::BOOL) ||
             check(TokenType::CHAR_TYPE)) && 
            peek().type == TokenType::IDENTIFIER && 
            peek(2).type == TokenType::LPAREN) {
            program->functions.push_back(parseFunctionDeclaration());
        } else {
            program->globalStatements.push_back(parseStatement());
        }
    }
    
    return program;
}

std::unique_ptr<FunctionDeclaration> Parser::parseFunctionDeclaration() {
    std::string returnType = currentToken.value;
    advance(); // consume return type
    
    std::string name = currentToken.value;
    expect(TokenType::IDENTIFIER, "Expected function name");
    
    auto func = std::make_unique<FunctionDeclaration>(returnType, name);
    
    expect(TokenType::LPAREN, "Expected '(' after function name");
    
    // Parse parameters
    if (!check(TokenType::RPAREN)) {
        do {
            std::string paramType = currentToken.value;
            advance(); // consume type
            std::string paramName = currentToken.value;
            expect(TokenType::IDENTIFIER, "Expected parameter name");
            func->parameters.push_back({paramType, paramName});
        } while (match(TokenType::COMMA));
    }
    
    expect(TokenType::RPAREN, "Expected ')' after parameters");
    
    func->body = parseBlock();
    
    return func;
}

std::unique_ptr<Block> Parser::parseBlock() {
    expect(TokenType::LBRACE, "Expected '{'");
    
    auto block = std::make_unique<Block>();
    
    while (!check(TokenType::RBRACE) && !check(TokenType::END_OF_FILE)) {
        block->statements.push_back(parseStatement());
    }
    
    expect(TokenType::RBRACE, "Expected '}'");
    
    return block;
}

std::unique_ptr<Statement> Parser::parseStatement() {
    if (check(TokenType::INT) || check(TokenType::FLOAT_TYPE) || 
        check(TokenType::CHAR_TYPE) || check(TokenType::BOOL)) {
        return parseVariableDeclaration();
    }
    
    if (check(TokenType::IF)) {
        return parseIfStatement();
    }
    
    if (check(TokenType::WHILE)) {
        return parseWhileStatement();
    }
    
    if (check(TokenType::FOR)) {
        return parseForStatement();
    }
    
    if (check(TokenType::RETURN)) {
        return parseReturnStatement();
    }
    
    if (check(TokenType::LBRACE)) {
        return parseBlock();
    }
    
    if (check(TokenType::COUT)) {
        return parseCoutStatement();
    }
    
    if (check(TokenType::CIN)) {
        return parseCinStatement();
    }
    
    return parseExpressionStatement();
}

std::unique_ptr<Statement> Parser::parseVariableDeclaration() {
    std::string type = currentToken.value;
    advance(); // consume type
    
    std::string name = currentToken.value;
    expect(TokenType::IDENTIFIER, "Expected variable name");
    
    std::unique_ptr<Expression> initializer = nullptr;
    if (match(TokenType::ASSIGN)) {
        initializer = parseExpression();
    }
    
    expect(TokenType::SEMICOLON, "Expected ';' after variable declaration");
    
    return std::make_unique<VariableDeclaration>(type, name, std::move(initializer));
}

std::unique_ptr<Statement> Parser::parseIfStatement() {
    expect(TokenType::IF, "Expected 'if'");
    expect(TokenType::LPAREN, "Expected '(' after 'if'");
    
    auto condition = parseExpression();
    
    expect(TokenType::RPAREN, "Expected ')' after condition");
    
    auto thenBranch = parseStatement();
    
    std::unique_ptr<Statement> elseBranch = nullptr;
    if (match(TokenType::ELSE)) {
        elseBranch = parseStatement();
    }
    
    return std::make_unique<IfStatement>(std::move(condition), 
                                         std::move(thenBranch), 
                                         std::move(elseBranch));
}

std::unique_ptr<Statement> Parser::parseWhileStatement() {
    expect(TokenType::WHILE, "Expected 'while'");
    expect(TokenType::LPAREN, "Expected '(' after 'while'");
    
    auto condition = parseExpression();
    
    expect(TokenType::RPAREN, "Expected ')' after condition");
    
    auto body = parseStatement();
    
    return std::make_unique<WhileStatement>(std::move(condition), std::move(body));
}

std::unique_ptr<Statement> Parser::parseForStatement() {
    expect(TokenType::FOR, "Expected 'for'");
    expect(TokenType::LPAREN, "Expected '(' after 'for'");
    
    std::unique_ptr<Statement> init = nullptr;
    if (!check(TokenType::SEMICOLON)) {
        if (check(TokenType::INT) || check(TokenType::FLOAT_TYPE) || 
            check(TokenType::CHAR_TYPE) || check(TokenType::BOOL)) {
            init = parseVariableDeclaration();
        } else {
            init = parseExpressionStatement();
        }
    } else {
        advance(); // consume semicolon
    }
    
    std::unique_ptr<Expression> condition = nullptr;
    if (!check(TokenType::SEMICOLON)) {
        condition = parseExpression();
    }
    expect(TokenType::SEMICOLON, "Expected ';' after for condition");
    
    std::unique_ptr<Statement> increment = nullptr;
    if (!check(TokenType::RPAREN)) {
        auto expr = parseExpression();
        increment = std::make_unique<ExpressionStatement>(std::move(expr));
    }
    
    expect(TokenType::RPAREN, "Expected ')' after for clauses");
    
    auto body = parseStatement();
    
    return std::make_unique<ForStatement>(std::move(init), std::move(condition),
                                          std::move(increment), std::move(body));
}

std::unique_ptr<Statement> Parser::parseReturnStatement() {
    expect(TokenType::RETURN, "Expected 'return'");
    
    std::unique_ptr<Expression> value = nullptr;
    if (!check(TokenType::SEMICOLON)) {
        value = parseExpression();
    }
    
    expect(TokenType::SEMICOLON, "Expected ';' after return statement");
    
    return std::make_unique<ReturnStatement>(std::move(value));
}

std::unique_ptr<Statement> Parser::parseCoutStatement() {
    expect(TokenType::COUT, "Expected 'cout'");
    
    auto stmt = std::make_unique<CoutStatement>();
    
    while (match(TokenType::LSHIFT)) {
        if (check(TokenType::ENDL)) {
            advance();
            stmt->expressions.push_back(std::make_unique<StringLiteral>("\n"));
        } else {
            stmt->expressions.push_back(parseExpression());
        }
    }
    
    expect(TokenType::SEMICOLON, "Expected ';' after cout statement");
    
    return stmt;
}

std::unique_ptr<Statement> Parser::parseCinStatement() {
    expect(TokenType::CIN, "Expected 'cin'");
    
    auto stmt = std::make_unique<CinStatement>();
    
    while (match(TokenType::RSHIFT)) {
        std::string varName = currentToken.value;
        expect(TokenType::IDENTIFIER, "Expected variable name after '>>'");
        stmt->variables.push_back(varName);
    }
    
    expect(TokenType::SEMICOLON, "Expected ';' after cin statement");
    
    return stmt;
}

std::unique_ptr<Statement> Parser::parseExpressionStatement() {
    // Check for assignment
    if (check(TokenType::IDENTIFIER) && peek().type == TokenType::ASSIGN) {
        std::string name = currentToken.value;
        advance(); // consume identifier
        advance(); // consume '='
        auto value = parseExpression();
        expect(TokenType::SEMICOLON, "Expected ';' after assignment");
        return std::make_unique<Assignment>(name, std::move(value));
    }
    
    auto expr = parseExpression();
    expect(TokenType::SEMICOLON, "Expected ';' after expression");
    return std::make_unique<ExpressionStatement>(std::move(expr));
}

std::unique_ptr<Expression> Parser::parseExpression() {
    return parseLogicalOr();
}

std::unique_ptr<Expression> Parser::parseLogicalOr() {
    auto expr = parseLogicalAnd();
    
    while (match(TokenType::OR)) {
        std::string op = "||";
        auto right = parseLogicalAnd();
        expr = std::make_unique<BinaryOp>(op, std::move(expr), std::move(right));
    }
    
    return expr;
}

std::unique_ptr<Expression> Parser::parseLogicalAnd() {
    auto expr = parseEquality();
    
    while (match(TokenType::AND)) {
        std::string op = "&&";
        auto right = parseEquality();
        expr = std::make_unique<BinaryOp>(op, std::move(expr), std::move(right));
    }
    
    return expr;
}

std::unique_ptr<Expression> Parser::parseEquality() {
    auto expr = parseComparison();
    
    while (check(TokenType::EQUAL) || check(TokenType::NOT_EQUAL)) {
        std::string op = currentToken.value;
        advance();
        auto right = parseComparison();
        expr = std::make_unique<BinaryOp>(op, std::move(expr), std::move(right));
    }
    
    return expr;
}

std::unique_ptr<Expression> Parser::parseComparison() {
    auto expr = parseAddition();
    
    while (check(TokenType::LESS) || check(TokenType::GREATER) ||
           check(TokenType::LESS_EQUAL) || check(TokenType::GREATER_EQUAL)) {
        std::string op = currentToken.value;
        advance();
        auto right = parseAddition();
        expr = std::make_unique<BinaryOp>(op, std::move(expr), std::move(right));
    }
    
    return expr;
}

std::unique_ptr<Expression> Parser::parseAddition() {
    auto expr = parseMultiplication();
    
    while (check(TokenType::PLUS) || check(TokenType::MINUS)) {
        std::string op = currentToken.value;
        advance();
        auto right = parseMultiplication();
        expr = std::make_unique<BinaryOp>(op, std::move(expr), std::move(right));
    }
    
    return expr;
}

std::unique_ptr<Expression> Parser::parseMultiplication() {
    auto expr = parseUnary();
    
    while (check(TokenType::MULTIPLY) || check(TokenType::DIVIDE) || 
           check(TokenType::MODULO)) {
        std::string op = currentToken.value;
        advance();
        auto right = parseUnary();
        expr = std::make_unique<BinaryOp>(op, std::move(expr), std::move(right));
    }
    
    return expr;
}

std::unique_ptr<Expression> Parser::parseUnary() {
    if (check(TokenType::NOT) || check(TokenType::MINUS)) {
        std::string op = currentToken.value;
        advance();
        auto operand = parseUnary();
        return std::make_unique<UnaryOp>(op, std::move(operand));
    }
    
    return parsePostfix();
}

std::unique_ptr<Expression> Parser::parsePostfix() {
    auto expr = parsePrimary();
    
    // Handle function calls
    if (check(TokenType::LPAREN)) {
        if (auto* id = dynamic_cast<Identifier*>(expr.get())) {
            std::string funcName = id->name;
            advance(); // consume '('
            
            auto call = std::make_unique<FunctionCall>(funcName);
            
            if (!check(TokenType::RPAREN)) {
                do {
                    call->arguments.push_back(parseExpression());
                } while (match(TokenType::COMMA));
            }
            
            expect(TokenType::RPAREN, "Expected ')' after function arguments");
            return call;
        }
    }
    
    return expr;
}

std::unique_ptr<Expression> Parser::parsePrimary() {
    if (check(TokenType::INTEGER)) {
        int value = std::stoi(currentToken.value);
        advance();
        return std::make_unique<IntegerLiteral>(value);
    }
    
    if (check(TokenType::FLOAT)) {
        float value = std::stof(currentToken.value);
        advance();
        return std::make_unique<FloatLiteral>(value);
    }
    
    if (check(TokenType::STRING)) {
        std::string value = currentToken.value;
        advance();
        return std::make_unique<StringLiteral>(value);
    }
    
    if (check(TokenType::TRUE)) {
        advance();
        return std::make_unique<BoolLiteral>(true);
    }
    
    if (check(TokenType::FALSE)) {
        advance();
        return std::make_unique<BoolLiteral>(false);
    }
    
    if (check(TokenType::IDENTIFIER)) {
        std::string name = currentToken.value;
        advance();
        return std::make_unique<Identifier>(name);
    }
    
    if (match(TokenType::LPAREN)) {
        auto expr = parseExpression();
        expect(TokenType::RPAREN, "Expected ')' after expression");
        return expr;
    }
    
    throw ParseError("Unexpected token: " + currentToken.value);
}
