"""

"""

import ply.lex as lex

tokens = ('NUM','ID')
literals = ['*','/','+','-','=','(',')','!','?']

t_NUM = r'[0-9]+'
t_ID = r'[a-zA-Z]'

t_ignore = ' \n\t'

def t_error(t):
    print('Illegal character: %s', t.value[0])

lexer = lex.lex()
