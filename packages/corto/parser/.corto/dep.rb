require 'rake/clean'

# Clobber generated header files

CLOBBER.include("include/BaseParser.h")
CLOBBER.include("include/BaseVisitor.h")
CLOBBER.include("include/BinaryExpressionNode.h")
CLOBBER.include("include/CommaExpressionNode.h")
CLOBBER.include("include/ConditionalExpressionNode.h")
CLOBBER.include("include/ExpressionNode.h")
CLOBBER.include("include/ExpressionStatementNode.h")
CLOBBER.include("include/Node.h")
CLOBBER.include("include/PrintVisitor.h")
CLOBBER.include("include/ProgramNode.h")
CLOBBER.include("include/SimpleParser.h")
CLOBBER.include("include/StatementNode.h")
CLOBBER.include(".corto/dep.rb")
