
import ply.lex as lex

tokens = ['ADD','SUB', 'PRINT', 'READ', 'SET', 'MUL', 'DIV', 'DUMP', 'num', 'id']
literals = ['(',')']

t_ADD = r'add'
t_SUB = r'sub'
t_PRINT = r'print'
t_READ = r'read'
t_SET = r'set'
t_MUL = r'mul'
t_DIV = r'div'
t_DUMP = r'dump'

t_num = r'\d+'
def t_id(t):
    r'[a-z]+'


t_ignore = ' \n\t'

def t_error(t):
    print('Illegal character: %s', t[0])

lexer = lex.lex()