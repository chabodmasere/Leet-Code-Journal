# C++ Compiler Architecture

## System Overview

```
┌─────────────────────────────────────────────────────────────┐
│                     C++ Source Code                          │
│                      (*.cpp file)                            │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│                    LEXER (Tokenizer)                         │
│  ┌────────────────────────────────────────────────────┐     │
│  │ • Character-by-character scanning                  │     │
│  │ • Keyword recognition                              │     │
│  │ • Operator identification                          │     │
│  │ • String/number literal parsing                    │     │
│  │ • Comment removal                                  │     │
│  └────────────────────────────────────────────────────┘     │
│  Files: lexer.h, lexer.cpp, token.h, token.cpp              │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│                    Token Stream                              │
│  [INT, "int"] [IDENTIFIER, "x"] [ASSIGN, "="]               │
│  [INTEGER, "10"] [SEMICOLON, ";"] ...                       │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│                    PARSER                                    │
│  ┌────────────────────────────────────────────────────┐     │
│  │ • Recursive descent parsing                        │     │
│  │ • Operator precedence handling                     │     │
│  │ • Syntax validation                                │     │
│  │ • AST construction                                 │     │
│  │ • Error reporting                                  │     │
│  └────────────────────────────────────────────────────┘     │
│  Files: parser.h, parser.cpp                                │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│              Abstract Syntax Tree (AST)                      │
│                                                              │
│         Program                                              │
│            │                                                 │
│            ├── FunctionDeclaration (main)                   │
│            │      │                                          │
│            │      └── Block                                 │
│            │           ├── VariableDeclaration (x = 10)     │
│            │           ├── VariableDeclaration (y = 20)     │
│            │           └── CoutStatement                     │
│            │                └── BinaryOp (+)                │
│            │                     ├── Identifier (x)         │
│            │                     └── Identifier (y)         │
│            └── ...                                           │
│                                                              │
│  Files: ast.h, ast.cpp                                      │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│                    INTERPRETER                               │
│  ┌────────────────────────────────────────────────────┐     │
│  │ • AST traversal (Visitor pattern)                  │     │
│  │ • Symbol table management                          │     │
│  │ • Expression evaluation                            │     │
│  │ • Statement execution                              │     │
│  │ • Function call handling                           │     │
│  │ • Runtime type checking                            │     │
│  └────────────────────────────────────────────────────┘     │
│  Files: interpreter.h, interpreter.cpp                      │
└──────────────────────┬──────────────────────────────────────┘
                       │
                       ▼
┌─────────────────────────────────────────────────────────────┐
│                    Program Output                            │
│                  (Console/Terminal)                          │
└─────────────────────────────────────────────────────────────┘
```

## Component Details

### 1. Lexer (Lexical Analyzer)

**Purpose**: Convert source code into tokens

**Input**: Raw source code string
```cpp
int x = 10;
```

**Output**: Token stream
```
Token(INT, "int", 1:1)
Token(IDENTIFIER, "x", 1:5)
Token(ASSIGN, "=", 1:7)
Token(INTEGER, "10", 1:9)
Token(SEMICOLON, ";", 1:11)
```

**Key Functions**:
- `advance()` - Move to next character
- `skipWhitespace()` - Skip spaces, tabs, newlines
- `skipComment()` - Remove comments
- `number()` - Parse numeric literals
- `identifier()` - Parse identifiers and keywords
- `getNextToken()` - Get next token from source

### 2. Parser (Syntax Analyzer)

**Purpose**: Build Abstract Syntax Tree from tokens

**Input**: Token stream

**Output**: AST (tree structure)

**Parsing Strategy**: Recursive Descent
- Top-down parsing
- One function per grammar rule
- Operator precedence climbing

**Grammar Hierarchy** (highest to lowest precedence):
```
Expression
  └── LogicalOr (||)
      └── LogicalAnd (&&)
          └── Equality (==, !=)
              └── Comparison (<, >, <=, >=)
                  └── Addition (+, -)
                      └── Multiplication (*, /, %)
                          └── Unary (-, !)
                              └── Postfix (function calls)
                                  └── Primary (literals, identifiers)
```

**Key Functions**:
- `parseProgram()` - Entry point
- `parseFunctionDeclaration()` - Parse functions
- `parseStatement()` - Parse statements
- `parseExpression()` - Parse expressions
- `parseBlock()` - Parse code blocks

### 3. AST (Abstract Syntax Tree)

**Purpose**: Represent program structure

**Node Types**:

**Expressions** (produce values):
- `IntegerLiteral` - Integer numbers
- `FloatLiteral` - Floating-point numbers
- `StringLiteral` - String values
- `BoolLiteral` - Boolean values
- `Identifier` - Variable names
- `BinaryOp` - Binary operations (+, -, *, /, etc.)
- `UnaryOp` - Unary operations (-, !)
- `FunctionCall` - Function invocations

**Statements** (perform actions):
- `VariableDeclaration` - Variable definitions
- `Assignment` - Variable assignments
- `IfStatement` - Conditional execution
- `WhileStatement` - While loops
- `ForStatement` - For loops
- `ReturnStatement` - Function returns
- `ExpressionStatement` - Expression as statement
- `Block` - Code blocks
- `CoutStatement` - Output statements
- `CinStatement` - Input statements

**Declarations**:
- `FunctionDeclaration` - Function definitions
- `Program` - Root node

### 4. Interpreter (Execution Engine)

**Purpose**: Execute the AST

**Key Components**:

**Symbol Table**:
```cpp
map<string, Value> variables;
// "x" -> 10
// "y" -> 20
// "sum" -> 30
```

**Function Table**:
```cpp
map<string, FunctionDeclaration*> functions;
// "main" -> FunctionDeclaration*
// "add" -> FunctionDeclaration*
```

**Value Type**:
```cpp
variant<int, float, string, bool>
// Can hold any of these types
```

**Execution Flow**:
1. Visit Program node
2. Register all functions
3. Execute global statements
4. Call main() if exists
5. Traverse AST using Visitor pattern
6. Evaluate expressions
7. Execute statements
8. Manage variable scopes
9. Handle function calls

## Data Flow Example

**Source Code**:
```cpp
int main() {
    int x = 5;
    int y = 10;
    cout << x + y << endl;
    return 0;
}
```

**Step 1: Lexer Output**
```
INT, IDENTIFIER(main), LPAREN, RPAREN, LBRACE,
INT, IDENTIFIER(x), ASSIGN, INTEGER(5), SEMICOLON,
INT, IDENTIFIER(y), ASSIGN, INTEGER(10), SEMICOLON,
COUT, LSHIFT, IDENTIFIER(x), PLUS, IDENTIFIER(y), LSHIFT, ENDL, SEMICOLON,
RETURN, INTEGER(0), SEMICOLON,
RBRACE, EOF
```

**Step 2: Parser Output (AST)**
```
Program
└── FunctionDeclaration(int, main)
    └── Block
        ├── VariableDeclaration(int, x)
        │   └── IntegerLiteral(5)
        ├── VariableDeclaration(int, y)
        │   └── IntegerLiteral(10)
        ├── CoutStatement
        │   ├── BinaryOp(+)
        │   │   ├── Identifier(x)
        │   │   └── Identifier(y)
        │   └── StringLiteral("\n")
        └── ReturnStatement
            └── IntegerLiteral(0)
```

**Step 3: Interpreter Execution**
```
1. Register function: main
2. Call main()
3. Execute block:
   a. Declare x = 5 → variables["x"] = 5
   b. Declare y = 10 → variables["y"] = 10
   c. Execute cout:
      - Evaluate x + y:
        * Get x → 5
        * Get y → 10
        * Add → 15
      - Print: "15"
      - Print: "\n"
   d. Return 0
4. Exit
```

**Step 4: Output**
```
15
```

## Design Patterns Used

### 1. Visitor Pattern
```cpp
class ASTVisitor {
    virtual void visit(IntegerLiteral& node) = 0;
    virtual void visit(BinaryOp& node) = 0;
    // ... for all node types
};

class Interpreter : public ASTVisitor {
    void visit(IntegerLiteral& node) override {
        currentValue = node.value;
    }
    // ... implementations
};
```

### 2. Recursive Descent
```cpp
Expression* parseExpression() {
    return parseLogicalOr();
}

Expression* parseLogicalOr() {
    auto left = parseLogicalAnd();
    while (match(OR)) {
        auto right = parseLogicalAnd();
        left = new BinaryOp("||", left, right);
    }
    return left;
}
```

### 3. Symbol Table
```cpp
map<string, Value> variables;

void declare(string name, Value value) {
    variables[name] = value;
}

Value lookup(string name) {
    return variables[name];
}
```

## Error Handling

### Lexer Errors
- Unknown characters
- Unterminated strings
- Invalid numbers

### Parser Errors
- Unexpected tokens
- Missing semicolons
- Unmatched braces
- Invalid syntax

### Runtime Errors
- Undefined variables
- Type mismatches
- Division by zero
- Undefined functions

## Memory Management

- **Smart Pointers**: `unique_ptr` for AST nodes
- **RAII**: Automatic cleanup
- **No Manual Memory**: No `new`/`delete` in user code
- **Move Semantics**: Efficient transfers

## Performance Characteristics

| Operation | Complexity |
|-----------|-----------|
| Lexing | O(n) - linear in source size |
| Parsing | O(n) - single pass |
| AST Construction | O(n) - one node per construct |
| Interpretation | O(n) - visit each node once |
| Variable Lookup | O(log n) - map lookup |
| Function Call | O(1) - direct pointer |

## Extension Points

To add new features:

1. **New Operator**:
   - Add token type in `token.h`
   - Add lexer recognition in `lexer.cpp`
   - Add parsing in `parser.cpp`
   - Add evaluation in `interpreter.cpp`

2. **New Statement**:
   - Add AST node in `ast.h`
   - Add parsing in `parser.cpp`
   - Add visitor method in `interpreter.cpp`

3. **New Data Type**:
   - Add to `Value` variant
   - Update type checking
   - Add conversion functions

## Conclusion

This architecture provides:
- ✅ Clear separation of concerns
- ✅ Extensible design
- ✅ Type safety
- ✅ Error handling
- ✅ Memory safety
- ✅ Educational clarity

The modular design makes it easy to understand, modify, and extend!
