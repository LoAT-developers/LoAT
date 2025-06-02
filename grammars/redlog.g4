grammar redlog;

// entry point
main    :       formula;

// arithmetic expressions
expr    :       VAR | INT | LPAR MINUS expr RPAR | LPAR binop expr expr RPAR | LPAR caop expr* RPAR;
caop    :       TIMES | PLUS;
binop   :       EXP | MINUS;

// formulas
formula :       TRUE | FALSE | lit | LPAR boolop formula* RPAR;
lit     :       LPAR relop expr expr RPAR;
boolop  :       AND | OR;
relop   :       LT | LEQ | EQ | GT | GEQ | NEQ;

// lexer stuff
PLUS	:	'plus';
MINUS	:	'minus';
TIMES	:	'times';
EXP     :       'expt';
LPAR 	:	'(';
RPAR	:	')';
AND	:	'and';
OR      :       'or';
LT	:	'lessp';
LEQ     :       'leq';
EQ      :       'equal';
NEQ     :       'neq';
GEQ     :       'geq';
GT      :       'greaterp';
TRUE    :       'true';
FALSE   :       'false';
VAR     :       ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_'|'.'|'\'')*;
INT     :       '0'..'9'+;
WS      :       (' ' | '\t' | '\r' | '\n')+ -> skip;