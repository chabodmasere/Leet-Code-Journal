#include "interpreter.h"
#include <iostream>
#include <cmath>

Interpreter::Interpreter() : hasReturned(false) {}

void Interpreter::interpret(Program* program) {
    program->accept(*this);
}

Value Interpreter::evaluate(Expression* expr) {
    expr->accept(*this);
    return currentValue;
}

void Interpreter::execute(Statement* stmt) {
    stmt->accept(*this);
}

bool Interpreter::isTruthy(const Value& value) {
    if (std::holds_alternative<bool>(value)) {
        return std::get<bool>(value);
    }
    if (std::holds_alternative<int>(value)) {
        return std::get<int>(value) != 0;
    }
    if (std::holds_alternative<float>(value)) {
        return std::get<float>(value) != 0.0f;
    }
    if (std::holds_alternative<std::string>(value)) {
        return !std::get<std::string>(value).empty();
    }
    return false;
}

Value Interpreter::add(const Value& left, const Value& right) {
    if (std::holds_alternative<int>(left) && std::holds_alternative<int>(right)) {
        return std::get<int>(left) + std::get<int>(right);
    }
    if (std::holds_alternative<float>(left) || std::holds_alternative<float>(right)) {
        float l = std::holds_alternative<float>(left) ? std::get<float>(left) : std::get<int>(left);
        float r = std::holds_alternative<float>(right) ? std::get<float>(right) : std::get<int>(right);
        return l + r;
    }
    if (std::holds_alternative<std::string>(left) || std::holds_alternative<std::string>(right)) {
        return valueToString(left) + valueToString(right);
    }
    throw RuntimeError("Invalid operands for addition");
}

Value Interpreter::subtract(const Value& left, const Value& right) {
    if (std::holds_alternative<int>(left) && std::holds_alternative<int>(right)) {
        return std::get<int>(left) - std::get<int>(right);
    }
    if (std::holds_alternative<float>(left) || std::holds_alternative<float>(right)) {
        float l = std::holds_alternative<float>(left) ? std::get<float>(left) : std::get<int>(left);
        float r = std::holds_alternative<float>(right) ? std::get<float>(right) : std::get<int>(right);
        return l - r;
    }
    throw RuntimeError("Invalid operands for subtraction");
}

Value Interpreter::multiply(const Value& left, const Value& right) {
    if (std::holds_alternative<int>(left) && std::holds_alternative<int>(right)) {
        return std::get<int>(left) * std::get<int>(right);
    }
    if (std::holds_alternative<float>(left) || std::holds_alternative<float>(right)) {
        float l = std::holds_alternative<float>(left) ? std::get<float>(left) : std::get<int>(left);
        float r = std::holds_alternative<float>(right) ? std::get<float>(right) : std::get<int>(right);
        return l * r;
    }
    throw RuntimeError("Invalid operands for multiplication");
}

Value Interpreter::divide(const Value& left, const Value& right) {
    if (std::holds_alternative<int>(left) && std::holds_alternative<int>(right)) {
        int r = std::get<int>(right);
        if (r == 0) throw RuntimeError("Division by zero");
        return std::get<int>(left) / r;
    }
    if (std::holds_alternative<float>(left) || std::holds_alternative<float>(right)) {
        float l = std::holds_alternative<float>(left) ? std::get<float>(left) : std::get<int>(left);
        float r = std::holds_alternative<float>(right) ? std::get<float>(right) : std::get<int>(right);
        if (r == 0.0f) throw RuntimeError("Division by zero");
        return l / r;
    }
    throw RuntimeError("Invalid operands for division");
}

Value Interpreter::modulo(const Value& left, const Value& right) {
    if (std::holds_alternative<int>(left) && std::holds_alternative<int>(right)) {
        int r = std::get<int>(right);
        if (r == 0) throw RuntimeError("Modulo by zero");
        return std::get<int>(left) % r;
    }
    throw RuntimeError("Invalid operands for modulo");
}

bool Interpreter::equal(const Value& left, const Value& right) {
    if (left.index() != right.index()) return false;
    
    if (std::holds_alternative<int>(left)) {
        return std::get<int>(left) == std::get<int>(right);
    }
    if (std::holds_alternative<float>(left)) {
        return std::get<float>(left) == std::get<float>(right);
    }
    if (std::holds_alternative<std::string>(left)) {
        return std::get<std::string>(left) == std::get<std::string>(right);
    }
    if (std::holds_alternative<bool>(left)) {
        return std::get<bool>(left) == std::get<bool>(right);
    }
    return false;
}

bool Interpreter::less(const Value& left, const Value& right) {
    if (std::holds_alternative<int>(left) && std::holds_alternative<int>(right)) {
        return std::get<int>(left) < std::get<int>(right);
    }
    if (std::holds_alternative<float>(left) || std::holds_alternative<float>(right)) {
        float l = std::holds_alternative<float>(left) ? std::get<float>(left) : std::get<int>(left);
        float r = std::holds_alternative<float>(right) ? std::get<float>(right) : std::get<int>(right);
        return l < r;
    }
    throw RuntimeError("Invalid operands for comparison");
}

bool Interpreter::greater(const Value& left, const Value& right) {
    if (std::holds_alternative<int>(left) && std::holds_alternative<int>(right)) {
        return std::get<int>(left) > std::get<int>(right);
    }
    if (std::holds_alternative<float>(left) || std::holds_alternative<float>(right)) {
        float l = std::holds_alternative<float>(left) ? std::get<float>(left) : std::get<int>(left);
        float r = std::holds_alternative<float>(right) ? std::get<float>(right) : std::get<int>(right);
        return l > r;
    }
    throw RuntimeError("Invalid operands for comparison");
}

std::string Interpreter::valueToString(const Value& value) {
    if (std::holds_alternative<int>(value)) {
        return std::to_string(std::get<int>(value));
    }
    if (std::holds_alternative<float>(value)) {
        return std::to_string(std::get<float>(value));
    }
    if (std::holds_alternative<std::string>(value)) {
        return std::get<std::string>(value);
    }
    if (std::holds_alternative<bool>(value)) {
        return std::get<bool>(value) ? "true" : "false";
    }
    return "";
}

// Visitor implementations
void Interpreter::visit(IntegerLiteral& node) {
    currentValue = node.value;
}

void Interpreter::visit(FloatLiteral& node) {
    currentValue = node.value;
}

void Interpreter::visit(StringLiteral& node) {
    currentValue = node.value;
}

void Interpreter::visit(BoolLiteral& node) {
    currentValue = node.value;
}

void Interpreter::visit(Identifier& node) {
    if (variables.find(node.name) == variables.end()) {
        throw RuntimeError("Undefined variable: " + node.name);
    }
    currentValue = variables[node.name];
}

void Interpreter::visit(BinaryOp& node) {
    Value left = evaluate(node.left.get());
    Value right = evaluate(node.right.get());
    
    if (node.op == "+") {
        currentValue = add(left, right);
    } else if (node.op == "-") {
        currentValue = subtract(left, right);
    } else if (node.op == "*") {
        currentValue = multiply(left, right);
    } else if (node.op == "/") {
        currentValue = divide(left, right);
    } else if (node.op == "%") {
        currentValue = modulo(left, right);
    } else if (node.op == "==") {
        currentValue = equal(left, right);
    } else if (node.op == "!=") {
        currentValue = !equal(left, right);
    } else if (node.op == "<") {
        currentValue = less(left, right);
    } else if (node.op == ">") {
        currentValue = greater(left, right);
    } else if (node.op == "<=") {
        currentValue = less(left, right) || equal(left, right);
    } else if (node.op == ">=") {
        currentValue = greater(left, right) || equal(left, right);
    } else if (node.op == "&&") {
        currentValue = isTruthy(left) && isTruthy(right);
    } else if (node.op == "||") {
        currentValue = isTruthy(left) || isTruthy(right);
    } else {
        throw RuntimeError("Unknown binary operator: " + node.op);
    }
}

void Interpreter::visit(UnaryOp& node) {
    Value operand = evaluate(node.operand.get());
    
    if (node.op == "-") {
        if (std::holds_alternative<int>(operand)) {
            currentValue = -std::get<int>(operand);
        } else if (std::holds_alternative<float>(operand)) {
            currentValue = -std::get<float>(operand);
        } else {
            throw RuntimeError("Invalid operand for unary minus");
        }
    } else if (node.op == "!") {
        currentValue = !isTruthy(operand);
    } else {
        throw RuntimeError("Unknown unary operator: " + node.op);
    }
}

void Interpreter::visit(FunctionCall& node) {
    if (functions.find(node.name) == functions.end()) {
        throw RuntimeError("Undefined function: " + node.name);
    }
    
    FunctionDeclaration* func = functions[node.name];
    
    // Check argument count
    if (node.arguments.size() != func->parameters.size()) {
        throw RuntimeError("Function " + node.name + " expects " + 
                          std::to_string(func->parameters.size()) + " arguments");
    }
    
    // Save current variables
    auto savedVars = variables;
    
    // Bind arguments to parameters
    for (size_t i = 0; i < node.arguments.size(); i++) {
        Value argValue = evaluate(node.arguments[i].get());
        variables[func->parameters[i].second] = argValue;
    }
    
    // Execute function body
    hasReturned = false;
    execute(func->body.get());
    
    // Get return value
    if (hasReturned) {
        currentValue = returnValue;
    } else {
        currentValue = 0; // Default return value
    }
    
    // Restore variables
    variables = savedVars;
    hasReturned = false;
}

void Interpreter::visit(VariableDeclaration& node) {
    Value value = 0; // Default value
    
    if (node.initializer) {
        value = evaluate(node.initializer.get());
    }
    
    variables[node.name] = value;
}

void Interpreter::visit(Assignment& node) {
    Value value = evaluate(node.value.get());
    
    if (variables.find(node.name) == variables.end()) {
        throw RuntimeError("Undefined variable: " + node.name);
    }
    
    variables[node.name] = value;
}

void Interpreter::visit(IfStatement& node) {
    Value condition = evaluate(node.condition.get());
    
    if (isTruthy(condition)) {
        execute(node.thenBranch.get());
    } else if (node.elseBranch) {
        execute(node.elseBranch.get());
    }
}

void Interpreter::visit(WhileStatement& node) {
    while (isTruthy(evaluate(node.condition.get()))) {
        execute(node.body.get());
        if (hasReturned) break;
    }
}

void Interpreter::visit(ForStatement& node) {
    if (node.init) {
        execute(node.init.get());
    }
    
    while (true) {
        if (node.condition && !isTruthy(evaluate(node.condition.get()))) {
            break;
        }
        
        execute(node.body.get());
        if (hasReturned) break;
        
        if (node.increment) {
            execute(node.increment.get());
        }
    }
}

void Interpreter::visit(ReturnStatement& node) {
    if (node.value) {
        returnValue = evaluate(node.value.get());
    } else {
        returnValue = 0;
    }
    hasReturned = true;
}

void Interpreter::visit(ExpressionStatement& node) {
    evaluate(node.expression.get());
}

void Interpreter::visit(Block& node) {
    for (auto& stmt : node.statements) {
        execute(stmt.get());
        if (hasReturned) break;
    }
}

void Interpreter::visit(CoutStatement& node) {
    for (auto& expr : node.expressions) {
        Value value = evaluate(expr.get());
        std::cout << valueToString(value);
    }
}

void Interpreter::visit(CinStatement& node) {
    for (const auto& varName : node.variables) {
        if (variables.find(varName) == variables.end()) {
            throw RuntimeError("Undefined variable: " + varName);
        }
        
        std::string input;
        std::cin >> input;
        
        // Try to parse as int, then float, otherwise string
        try {
            variables[varName] = std::stoi(input);
        } catch (...) {
            try {
                variables[varName] = std::stof(input);
            } catch (...) {
                variables[varName] = input;
            }
        }
    }
}

void Interpreter::visit(FunctionDeclaration& node) {
    functions[node.name] = &node;
}

void Interpreter::visit(Program& node) {
    // First pass: register all functions
    for (auto& func : node.functions) {
        func->accept(*this);
    }
    
    // Execute global statements
    for (auto& stmt : node.globalStatements) {
        execute(stmt.get());
    }
    
    // Call main function if it exists
    if (functions.find("main") != functions.end()) {
        FunctionCall mainCall("main");
        visit(mainCall);
    }
}
