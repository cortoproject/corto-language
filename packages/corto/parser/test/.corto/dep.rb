require 'rake/clean'

# Clobber generated header files

CLOBBER.include("include/TestCortoLanguage.h")
CLOBBER.include(".corto/dep.rb")
