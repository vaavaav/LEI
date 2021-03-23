import ply.lex as lex
import sys

# tokens declarations
tokens = (
    'PA', 'PF',
    'ADD', 'SUB',
    'MUL', 'DIV',
    'NUM'
)

# Token regex

t_PA = r'\('
t_PF = r'\)'
t_ADD = r'\+'
t_SUB = r'-'
t_MUL = r'\*'
t_DIV = r'/'

# token with some action code

def t_NUM(t):
    r'\d+'
    t.value = int(t.value)
    return t

#tracking line numbers
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

#characters to be ignored
t_ignore = " \t"

# errors
def t_error(t):
    print(f"Caráter errado {t.value[0]}")
    t.lexer.skip(1)

# build the lexer 
lexer = lex.lex()


# reading input
for linha in sys.stdin:
    lexer.input(linha)
    for tok in lexer:
        print(tok)



