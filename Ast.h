// Ast.h

// Function call expression
struct FunCallExpr : public Expression{
    std::string funcName;
    std::vector<Expression*> args;
};

// Base class
struct AstNode {
    explicit AstNode(int line, int column) : line(line), column(column) {}
    virtual ~AstNode() = default;

    virtual std::string astString() { return "AstNode()"; }

    int line = -1;
    int column = -1;
};

// Expression
struct Expression : public AstNode {
    using AstNode::AstNode;

    virtual ~Expression() = default;

    virtual Value eval(Runtime* rt, std::deque<Context*> ctxChain);

    std::string astString() override;
};

// Assign Expression
struct AssignExpr {
    Expression* lhs;
    Token opt;
    Expression* rhs;
}

// Bool Expression
struct BoolExpr : public Expression {
    explicit BoolExpr(int line, int column) : Expression(line, column) {}
    bool literal;

    Value value(Runtime* rt, std::deque<Context*> ctxChain) override;
    std::string() override;
};
