import ply.yacc as yacc
import sys

from capicua_binaria_lex import tokens

## incio da GIC

def p_grammar(p):
    """Frases : Frases NL Frase
              | Frase
       Frase  : ONE
              | ZERO
              | ONE Frase ONE
              | ZERO Frase ZERO
              | 
    """
    print("Conjunto de frases válidas; ", p)

def p_error(p):
    parser.success = False
    print('Syntax error!')

###inicio do parsing
parser = yacc.yacc()
parser.success = True

inputText = ""
for linha in sys.stdin:
    inputText += linha
     
parser.parse(inputText)


if parser.success:
   print('Parsing completed!')
   
