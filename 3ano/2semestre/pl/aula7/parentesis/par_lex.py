'''
    par_lex.py
    aula7: 2021-04-13

    linguagem dos parentesis

'''

import ply.lex as lex

tokens = ['PA', 'PF']

t_PA = r'\('

t_PF = r'\)'

t_ignore = " \t\n"

def t_error(t):
    print("Caráter ilegal: ", t.value[0])
    t.lexer.skip(1)

lexer = lex.lex()