import ply.yacc as yacc
import sys

from capicua_binaria_lex import tokens

## incio da GIC

def p_Comando_ler(p):
    "Comando : '?' ID"
    p[0] = ("(read " + p[2] + ")")

def p_Comando_escrever(p):
    "Comando : '!' Exp"
    p[0] = ("(print " + p[2] + ")")

def p_Comando_atrib(p):
    "Comando : ID '=' Exp"
    p[0] = ("(set " + p[1] + " " + p[3] + ")")

def p_Comando_despejar(p):
    "Comando : '!' '!'"
    p[0] = ("dump")

def p_Exp_add(p):
    "Exp : Exp '+' Termo"
    p[0] = ("(add " + p[1] + " " + p[3] + ")")

def p_Exp_sub(p):
    "Exp : Exp '-' Termo"
    p[0] = ("(sub " + p[1] + " " + p[3] + ")")

def p_Exp_termo(p):
    "Exp : Termo"
    p[0] = p[1]

def p_Termo_mul(p):
    "Exp : Termo '*' Termo"
    p[0] = ("(mul " + p[1] + " " + p[3] + ")")

def p_Termo_div(p):
    "Exp : Termo '/' Termo"
    p[0] = ("(div " + p[1] + " " + p[3] + ")")

def p_Factor_group(p):
    "Factor : '(' Exp ')'"
    p[0] = p[2]

def p_Factor_num(p):
    "Factor : num"
    p[0] = p[1]



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
   
