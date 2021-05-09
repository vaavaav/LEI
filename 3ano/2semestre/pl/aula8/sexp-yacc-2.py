import ply.yacc as yacc
import sys

from sexp_lex import tokens

## incio da GIC

def p_lisp_grammar(p):
    """lisp : sexp
       sexp : PAL
       sexp : NUM
       sexp : LPAREN sexplist RPAREN
       sexplist : sexp sexplist
       sexplist :  
    """

def p_error(p):
    parser.success = False
    print('Syntax error!')

###inicio do parsing
parser = yacc.yacc()
parser.success = True

fonte = ""
for linha in sys.stdin:
    fonte += linha
     
parser.parse(fonte)
if parser.success:
   print('Parsing completed!')
   
