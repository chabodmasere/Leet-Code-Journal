#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <memory>
#include <map>

// Forward declarations
class ASTVisitor;

// Base AST Node
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void accept(ASTVisitor& visitor) = 0;
};

// Expression Nodes
class Expression : public ASTNode {
public:
    virtual ~Expression() = default;
};

class IntegerLiteral : public Expression {
public:
    int value;
    IntegerLiteral(int value) : value(value) {}
    void accept(ASTVisitor& visitor) override;
};

class FloatLiteral : public Expression {
public:
    float value;
    FloatLiteral(float value) : value(value) {}
    void accept(ASTVisitor& visitor) override;
};

class StringLiteral : public Expression {
public:
    std::string value;
    StringLiteral(const std::string& value) : value(value) {}
    void accept(ASTVisitor& visitor) override;
};

class BoolLiteral : public Expression {
public:
    bool value;
    BoolLiteral(bool value) : value(value) {}
    void accept(ASTVisitor& visitor) override;
};

class Identifier : public Expression {
public:
    std::string name;
    Identifier(const std::string& name) : name(name) {}
    void accept(ASTVisitor& visitor) override;
};

class BinaryOp : public Expression {
public:
    std::string op;
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    
    BinaryOp(const std::string& op, std::unique_ptr<Expression> left, 
             std::unique_ptr<Expression> right)
        : op(op), left(std::move(left)), right(std::move(right)) {}
    void accept(ASTVisitor& visitor) override;
};

class UnaryOp : public Expression {
public:
    std::string op;
    std::unique_ptr<Expression> operand;
    
    UnaryOp(const std::string& op, std::unique_ptr<Expression> operand)
        : op(op), operand(std::move(operand)) {}
    void accept(ASTVisitor& visitor) override;
};

class FunctionCall : public Expression {
public:
    std::string name;
    std::vector<std::unique_ptr<Expression>> arguments;
    
    FunctionCall(const std::string& name) : name(name) {}
    void accept(ASTVisitor& visitor) override;
};

// Statement Nodes
class Statement : public ASTNode {
public:
    virtual ~Statement() = default;
};

class VariableDeclaration : public Statement {
public:
    std::string type;
    std::string name;
    std::unique_ptr<Expression> initializer;
    
    VariableDeclaration(const std::string& type, const std::string& name,
                       std::unique_ptr<Expression> initializer = nullptr)
        : type(type), name(name), initializer(std::move(initializer)) {}
    void accept(ASTVisitor& visitor) override;
};

class Assignment : public Statement {
public:
    std::string name;
    std::unique_ptr<Expression> value;
    
    Assignment(const std::string& name, std::unique_ptr<Expression> value)
        : name(name), value(std::move(value)) {}
    void accept(ASTVisitor& visitor) override;
};

class IfStatement : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::unique_ptr<Statement> thenBranch;
    std::unique_ptr<Statement> elseBranch;
    
    IfStatement(std::unique_ptr<Expression> condition,
                std::unique_ptr<Statement> thenBranch,
                std::unique_ptr<Statement> elseBranch = nullptr)
        : condition(std::move(condition)), 
          thenBranch(std::move(thenBranch)),
          elseBranch(std::move(elseBranch)) {}
    void accept(ASTVisitor& visitor) override;
};

class WhileStatement : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::unique_ptr<Statement> body;
    
    WhileStatement(std::unique_ptr<Expression> condition,
                   std::unique_ptr<Statement> body)
        : condition(std::move(condition)), body(std::move(body)) {}
    void accept(ASTVisitor& visitor) override;
};

class ForStatement : public Statement {
public:
    std::unique_ptr<Statement> init;
    std::unique_ptr<Expression> condition;
    std::unique_ptr<Statement> increment;
    std::unique_ptr<Statement> body;
    
    ForStatement(std::unique_ptr<Statement> init,
                 std::unique_ptr<Expression> condition,
                 std::unique_ptr<Statement> increment,
                 std::unique_ptr<Statement> body)
        : init(std::move(init)), condition(std::move(condition)),
          increment(std::move(increment)), body(std::move(body)) {}
    void accept(ASTVisitor& visitor) override;
};

class ReturnStatement : public Statement {
public:
    std::unique_ptr<Expression> value;
    
    ReturnStatement(std::unique_ptr<Expression> value = nullptr)
        : value(std::move(value)) {}
    void accept(ASTVisitor& visitor) override;
};

class ExpressionStatement : public Statement {
public:
    std::unique_ptr<Expression> expression;
    
    ExpressionStatement(std::unique_ptr<Expression> expression)
        : expression(std::move(expression)) {}
    void accept(ASTVisitor& visitor) override;
};

class Block : public Statement {
public:
    std::vector<std::unique_ptr<Statement>> statements;
    
    Block() {}
    void accept(ASTVisitor& visitor) override;
};

class CoutStatement : public Statement {
public:
    std::vector<std::unique_ptr<Expression>> expressions;
    
    CoutStatement() {}
    void accept(ASTVisitor& visitor) override;
};

class CinStatement : public Statement {
public:
    std::vector<std::string> variables;
    
    CinStatement() {}
    void accept(ASTVisitor& visitor) override;
};

// Function Declaration
class FunctionDeclaration : public ASTNode {
public:
    std::string returnType;
    std::string name;
    std::vector<std::pair<std::string, std::string>> parameters; // (type, name)
    std::unique_ptr<Block> body;
    
    FunctionDeclaration(const std::string& returnType, const std::string& name)
        : returnType(returnType), name(name) {}
    void accept(ASTVisitor& visitor) override;
};

// Program (root node)
class Program : public ASTNode {
public:
    std::vector<std::unique_ptr<FunctionDeclaration>> functions;
    std::vector<std::unique_ptr<Statement>> globalStatements;
    
    Program() {}
    void accept(ASTVisitor& visitor) override;
};

// Visitor interface
class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;
    
    virtual void visit(IntegerLiteral& node) = 0;
    virtual void visit(FloatLiteral& node) = 0;
    virtual void visit(StringLiteral& node) = 0;
    virtual void visit(BoolLiteral& node) = 0;
    virtual void visit(Identifier& node) = 0;
    virtual void visit(BinaryOp& node) = 0;
    virtual void visit(UnaryOp& node) = 0;
    virtual void visit(FunctionCall& node) = 0;
    virtual void visit(VariableDeclaration& node) = 0;
    virtual void visit(Assignment& node) = 0;
    virtual void visit(IfStatement& node) = 0;
    virtual void visit(WhileStatement& node) = 0;
    virtual void visit(ForStatement& node) = 0;
    virtual void visit(ReturnStatement& node) = 0;
    virtual void visit(ExpressionStatement& node) = 0;
    virtual void visit(Block& node) = 0;
    virtual void visit(CoutStatement& node) = 0;
    virtual void visit(CinStatement& node) = 0;
    virtual void visit(FunctionDeclaration& node) = 0;
    virtual void visit(Program& node) = 0;
};

#endif // AST_H
