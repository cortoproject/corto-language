require 'rake/clean'

# Clobber generated header files

CLOBBER.include("include/Point.h")
CLOBBER.include("include/TestCortoLanguage.h")
CLOBBER.include("include/TestDeclarationVisitor.h")
CLOBBER.include("include/TestPrintVisitor.h")
CLOBBER.include(".corto/dep.rb")
