'''
    listas_yacc.py
    aula7: 2021-04-13

    Listas heterogéneas: inteiros e alfanuméricos

    [78]
    [1,2,3]
    [121,asa,c45]

    T = {number, '[', ']', alfanum, ','}

    N = {Lista, Elementos, Elemento}

    p1: Lista -> '[' Elementos ']'
    p1.5: Lista -> '[' ']'

    p2: Elementos -> Elemento 
    p3: Elementos -> Elementos ',' Elemento  

    p4, p5: Elemento -> alfanum | number 

'''

import ply.yacc as yacc
from listas_lex import tokens

def p_grammar(p):
    """
    Lista : PA PF
          | PA Elementos PF

    Elementos : Elemento
              | Elementos VIRG Elemento
    
    Elemento : alfanum 
             | number
    """

def p_error(p):
    print('Erro sintático: ', p)
    parser.success = False

# Build the parser
parser = yacc.yacc()

# Read input and parse it by line 
import sys

for linha in sys.stdin:
    parser.success = True
    parser.parse(linha)

    if parser.success:
        print("Frase válida reconhecida: ", linha)
    else:
        print("Frase inválida. Corrija e tente de novo...")



