grammar CHC;

// entry point
main:              LPAR LOGIC RPAR
                   fun_decl+
                   (LPAR ASSERT chc_assert RPAR)*
                   (LPAR ASSERT chc_query RPAR)*
                   LPAR CHECK_SAT RPAR
                   (LPAR EXIT RPAR)?;

fun_decl:          LPAR DECLARE_FUN symbol LPAR sort* RPAR BOOL_SORT RPAR;

chc_assert:        LPAR chc_assert_head chc_assert_body RPAR;
chc_assert_head:   FORALL LPAR var_decl+ RPAR;
chc_assert_body:   LPAR IMPLIES chc_tail chc_head RPAR
                 | chc_head;
chc_tail:          (LPAR AND var_or_atom+ i_formula* RPAR)
                 | var_or_atom
                 | i_formula
                 | u_pred_atom;
chc_head:          u_pred_atom;

chc_query:         LPAR FORALL LPAR var_decl+ RPAR LPAR IMPLIES chc_tail FALSE RPAR RPAR;

var_decl:          LPAR var sort RPAR;

var_or_atom:       var
                 | u_pred_atom;

u_pred_atom:       LPAR symbol var* RPAR
                 | symbol;

let:               LPAR var (i_formula | expr) RPAR;
lets:              LET LPAR let+ RPAR;

expr:              LPAR unaryop expr RPAR
                 | LPAR binaryop expr expr RPAR
                 | LPAR naryop expr+ RPAR
                 | LPAR ITE i_formula expr expr RPAR
                 | var
                 | INT
                 | LPAR expr RPAR
                 | LPAR lets expr RPAR;
unaryop:           MINUS;
binaryop:          MOD
                 | DIV
                 | MINUS;
naryop:            TIMES
                 | PLUS;

i_formula:         LPAR NOT i_formula RPAR
                 | lit
                 | LPAR boolop i_formula+ RPAR
                 | LPAR ITE i_formula i_formula i_formula RPAR
                 | LPAR lets i_formula RPAR
                 | LPAR i_formula RPAR
                 | TRUE
                 | FALSE
                 | var;
boolop:            AND
                 | OR
                 | EQ
                 | NEQ;

lit:               LPAR (
                       EQ var var
                     | NEQ var var
                     | relop expr expr
                   ) RPAR;

relop:             LT | LEQ | EQ | GT | GEQ | NEQ;

symbol:            ID;
sort:              INT_SORT | BOOL_SORT;
var:               ID;

// lexer stuff
LOGIC:             'set-logic HORN';
ASSERT:            'assert';
CHECK_SAT:         'check-sat';
EXIT:              'exit';
DECLARE_FUN:       'declare-fun';
BOOL_SORT:         'Bool';
INT_SORT:          'Int';
FORALL:            'forall';
LET:               'let';
IMPLIES:           '=>';
FALSE:             'false';
TRUE:              'true';
PLUS:		   '+';
MINUS:		   '-';
TIMES:		   '*';
MOD:               'mod';
DIV:               'div';
LPAR: 		   '(';
RPAR:		   ')';
AND:		   'and';
OR:                'or';
NOT:               'not';
ITE:               'ite';
LT:		   '<';
LEQ:               '<=';
EQ:                '=';
NEQ:               '!=';
GEQ:               '>=';
GT:                '>' ;
ID:                (SC | LETTER) (SC | LETTER | ('0'..'9'))*
                 | '|' ~('|')+ '|';
fragment SC:       '~' | '!' | '@' | '$' | '%' | '^' | '&' | '*' | '_' | '-' | '+' | '=' | '<' | '>' | '.' | '?' | '/';
fragment LETTER:   'a'..'z' | 'A'..'Z';
INT:               '0'..'9'+;
WS:                (' ' | '\t' | '\r' | '\n')+ -> skip;
COMMENT:           ';' .*? ('\r'? '\n' | '\r') -> skip;
OTHER:             ~('|');