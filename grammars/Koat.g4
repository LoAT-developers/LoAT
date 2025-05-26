grammar Koat;

// entry point
main    :       goal? start sink? vardecl transs;

// aliases for ID
fs      :       ID;
var     :       ID;

// top-level elements
goal    :       LPAR GOAL (CPX | TERM) RPAR;
start   :       LPAR START LPAR FS fs RPAR RPAR;
sink    :       LPAR SINK LPAR FS fs RPAR RPAR;
vardecl :       LPAR VAR ID+ RPAR;
transs  :       LPAR RULES trans* RPAR;

// transitions
trans   :       lhs to com cond?;
lhs     :       fs LPAR (var (COMMA var)*)? RPAR;
com     :       COM LPAR (rhs (COMMA rhs)*)? RPAR | rhs;
rhs     :       fs LPAR (expr (COMMA expr)*)? RPAR;
to      :       TO | MINUS LCURL lb COMMA ub RCURL GT | MINUS LCURL lb RCURL GT;
lb      :       expr;
ub      :       expr;
cond    :       CONDSEP formula | LBRACK formula RBRACK;

// arithmetic expressions
expr    :       LPAR expr RPAR | MINUS expr | expr EXP expr | expr TIMES expr | expr PLUS expr | expr MINUS expr | var | INT;

// formulas
formula :       LPAR formula RPAR | formula AND formula | formula OR formula | lit;
lit     :       expr relop expr;
relop   :       LT | LEQ | EQ | GT | GEQ | NEQ;

// lexer stuff
COM     :       'Com_' '0'..'9'+;
GOAL    :       'GOAL';
CPX     :       'COMPLEXITY';
TERM    :       'TERMINATION';
START   :       'STARTTERM';
SINK    :       'SINKTERM';
FS      :       'FUNCTIONSYMBOLS';
VAR     :       'VAR';
RULES   :       'RULES';
PLUS	:	'+';
MINUS	:	'-';
TIMES	:	'*';
EXP     :       '^' | '**';
LPAR 	:	'(';
RPAR	:	')';
RBRACK	:	']';
LBRACK 	:	'[';
LCURL   :       '{';
RCURL   :       '}';
TO	:	'->';
COMMA	:	',';
AND	:	'/\\' | '&&';
OR      :       '\\/' | '||';
LT	:	'<';
LEQ     :       '<=';
EQ      :       '==' | '=';
NEQ     :       '!=';
GEQ     :       '>=';
GT      :       '>' ;
CONDSEP :       ':|:';
ID      :       ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_'|'.'|'\'')*;
INT     :       '0'..'9'+;
WS      :       (' ' | '\t' | '\r' | '\n')+ -> skip;
COMMENT :       '#' .*? ('\r'? '\n' | '\r') -> skip;