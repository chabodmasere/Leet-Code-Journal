#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "ast.h"
#include <map>
#include <string>
#include <vector>
#include <variant>
#include <memory>

// Value type that can hold different types
using Value = std::variant<int, float, std::string, bool>;

class Interpreter : public ASTVisitor {
private:
    // Symbol table for variables
    std::map<std::string, Value> variables;
    
    // Function table
    std::map<std::string, FunctionDeclaration*> functions;
    
    // Current expression result
    Value currentValue;
    
    // Return value handling
    bool hasReturned;
    Value returnValue;
    
    // Helper methods
    Value evaluate(Expression* expr);
    void execute(Statement* stmt);
    bool isTruthy(const Value& value);
    Value add(const Value& left, const Value& right);
    Value subtract(const Value& left, const Value& right);
    Value multiply(const Value& left, const Value& right);
    Value divide(const Value& left, const Value& right);
    Value modulo(const Value& left, const Value& right);
    bool equal(const Value& left, const Value& right);
    bool less(const Value& left, const Value& right);
    bool greater(const Value& left, const Value& right);
    std::string valueToString(const Value& value);
    
public:
    Interpreter();
    
    void interpret(Program* program);
    
    // Visitor methods
    void visit(IntegerLiteral& node) override;
    void visit(FloatLiteral& node) override;
    void visit(StringLiteral& node) override;
    void visit(BoolLiteral& node) override;
    void visit(Identifier& node) override;
    void visit(BinaryOp& node) override;
    void visit(UnaryOp& node) override;
    void visit(FunctionCall& node) override;
    void visit(VariableDeclaration& node) override;
    void visit(Assignment& node) override;
    void visit(IfStatement& node) override;
    void visit(WhileStatement& node) override;
    void visit(ForStatement& node) override;
    void visit(ReturnStatement& node) override;
    void visit(ExpressionStatement& node) override;
    void visit(Block& node) override;
    void visit(CoutStatement& node) override;
    void visit(CinStatement& node) override;
    void visit(FunctionDeclaration& node) override;
    void visit(Program& node) override;
};

class RuntimeError : public std::runtime_error {
public:
    RuntimeError(const std::string& message) : std::runtime_error(message) {}
};

#endif // INTERPRETER_H
