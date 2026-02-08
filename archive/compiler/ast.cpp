#include "ast.h"

// IntegerLiteral
void IntegerLiteral::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// FloatLiteral
void FloatLiteral::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// StringLiteral
void StringLiteral::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// BoolLiteral
void BoolLiteral::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// Identifier
void Identifier::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// BinaryOp
void BinaryOp::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// UnaryOp
void UnaryOp::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// FunctionCall
void FunctionCall::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// VariableDeclaration
void VariableDeclaration::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// Assignment
void Assignment::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// IfStatement
void IfStatement::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// WhileStatement
void WhileStatement::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// ForStatement
void ForStatement::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// ReturnStatement
void ReturnStatement::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// ExpressionStatement
void ExpressionStatement::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// Block
void Block::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// CoutStatement
void CoutStatement::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// CinStatement
void CinStatement::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// FunctionDeclaration
void FunctionDeclaration::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}

// Program
void Program::accept(ASTVisitor& visitor) {
    visitor.visit(*this);
}
