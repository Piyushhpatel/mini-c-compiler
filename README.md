# C Compiler

## About Project
This is a Basic C compiler that supports basic c constructs such as variables, conditionals and iterations. It takes c files as input and convert the source code into assembly code with printing the symbol table, inorder traversal of parse tree and intermediate code as three address code while giving syntax and semantic errors.

## What is LEX?
LEX is a tool used to generate a lexical analyzer. The input is a set of regular expressions in addition to actions. The output is a table driven scanner called lex.yy.c.

## What is YACC?
YACC (Yet Another Compiler Compiler) is a tool used to generate a parser. It parses the input file and does semantic analysis on the stream of tokens produced by the LEX file. YACC translates a given Context Free Grammar (CFG) specifications into a C implementation y.tab.c. This C program when compiled, yields an executable parser.

## Features of the Compiler

- Symbol Table
- Parse Tree and AST
- Semantic Analysis
- Intermediate Code Generation
- Code Generation

## What the Compiler accepts?

- Simple C programs - declaration and assignment, printf, scanf and arithmetic operations ( + , - , * , / )
- Simple for loops and if-else statements (no else if)
- Nested for loops and if-else 

## Phases of the Compiler

The final parser takes a C program with nested for loops or if-else blocks and performs lexical, syntax, and semantic analysis and then intermediate code generation. Let’s look at the implementation of each phase in detail:

### Lexer and Context-Free Grammar

The first step was to code the lexer file to take the stream of characters from the input programs and identify the tokens defined with the help of regular expressions. Next, the yacc file was created, which contained the context-free grammar that accepts a complete C program constituting headers, main function, variable declarations, and initializations, nested for loops, if-else constructs, and expressions of the form of binary arithmetic and unary operations. At this stage, the parser will accept a program with the correct structure and throw a syntax error if the input program is not derived from the CFG.

### Lexical Analysis

A struct was defined with the attributes id_name, data_type (int, float, char, etc.), type (keyword, identifier, constant, etc.), and line_no to generate a symbol table. The symbol table is an array of the above-defined struct. Whenever the program encounters a header, keyword, a constant or a variable declaration, the add function is called, which takes the type of the symbol as a parameter. In the add function, we first check if the element is already present in the symbol table. If it is not present, a new entry is created using the value of yytext as id_name, datatype from the global variable type in case of variables, type from the passed parameter, and line_no. After the CFG accepts the program, the symbol table is printed. 

### Syntax Analysis

For the syntax analysis phase, a struct was declared that represented the node for the binary tree that is to be generated. The struct node has attributes left, right, and a token which is a character array. All the tokens are declared to be of type nam, a struct with attributes node and name, representing the token’s name. To generate the syntax tree, a node is created for each token and linked to the nodes of the tokens, which occur to its left and right semantically. The inorder traversal of the generated syntax tree should recreate the program logically. 

### Semantic Analysis

The semantic analyzer handles three types of static checks. 
1. Variables should be declared before use. For this, we use the check_declaration function that checks if the identifier passed as a parameter is present in the symbol table. If it is not, an informative error message is printed. The check declaration function is called every time an identifier is encountered in a statement apart from a declarative statement. 
2. Variables cannot be redeclared. Since our compiler assumes a single scope, variables cannot be redeclared even within loops. For this check, the add function is changed to check if the symbol is present in the symbol table before inserting it. If the symbol is already present, and it is of the type variable, the user is attempting to redeclare it, and an error message is printed. 
3. Pertains to type checking of variables in an arithmetic expression. For this, the check_types function is used, which takes the types of both variables as input. If the types match, nothing is done. If one variable needs to be converted to another type, the corresponding type conversion node is inserted in the syntax tree (inttofloat or floattoint). 
The type field was added to the struct representing value and expression tokens to keep track of the type of the compound expressions that are not present in the symbol table. The output of this phase is the annotated syntax tree.

### Intermediate Code Generation

For intermediate code generation, the three address code representation was used. Variables were used to keep track of the next temporary variable and label to be generated. The condition statements of if and for were also declared to store the labels to goto in case the condition is satisfied or not satisfied. The output of this step is the intermediate code.

## Summary
This is a basic compiler with basic construct that compile source code in C into assembly if you want to see the compiler in action you can take the parser.tab.c file, compile it you will get executable file and you can pass our provide input files as test cases. 
### Use this command after creating a.exe file
'''
a<input.c
'''
Furthur more we are providing link for resource that might help you learn about lex , bison and compiler making
[Jonathan Engelsma.](https://www.youtube.com/watch?v=54bo1qaHAfk)
[Brian Robert Callahan](https://briancallahan.net/blog/20210814.html)
[Nora Sandler](https://norasandler.com/2017/11/29/Write-a-Compiler.html)