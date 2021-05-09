import ply.yacc as yacc
import sys

from to_sexp_lex import tokens

## incio da GIC

def p_Comando_ler(p):
    "Comando : '(' READ id ')'"
    valor = input("Introduza um valor inteiro: ")
    p.parser.registers.update({p[3]: int(valor)})

def p_Comando_escrever(p):
    "Comando : '(' PRINT Exp ')'"
    p[0] = p[3]

def p_Comando_atrib(p):
    "Comando : '(' SET id Exp ')'"
    p.parser.registers.update({p[3]: p[4]})

def p_Comando_despejar(p):
    "Comando : DUMP"
    print(p.parser.registers)

def p_Exp_add(p):
    "Exp : '(' ADD Exp Termo ')' "
    p[0] = p[3] + p[4]

def p_Exp_sub(p):
    "Exp : '(' SUB Exp Termo ')' "
    p[0] = p[3] - p[4]

def p_Exp_termo(p):
    "Exp : Termo"
    p[0] = p[1]

def p_Termo_mul(p):
    "Termo : '(' MUL Termo Termo ')' "
    p[0] = p[3] * p[4]

def p_Termo_div(p):
    "Termo : '(' DIV Termo Termo ')' "
    if(p[4] != 0):
        p[0] = p[3] / p[4]
    else:
        print("DIV#0, a continuar com o dividendo: ", p[3])
        p[0] = p[3]

def p_Termo_Factor(p):
    "Termo : Factor"
    p[0] = p[1]

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


for linha in sys.stdin:
    parser.parse(linha)


if parser.success:
   print('Parsing completed!')
   
