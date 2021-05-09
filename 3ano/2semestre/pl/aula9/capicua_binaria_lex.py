"""
Strings binarias capicua

Exemplo:
0
11
010
00111100
01011010
"""

import ply.lex as lex

tokens = ('ZERO', 'ONE', 'NL')

t_ZERO = r'0'
t_ONE = r'1'
t_NL = r'\n'

t_ignore = ' \n\t'

def t_error(t):
    print('Illegal character: %s', t.value[0])

lexer = lex.lex()
