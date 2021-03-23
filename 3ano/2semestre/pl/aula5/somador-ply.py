import ply.lex as lex
import sys

# tokens declarations
tokens = (
    'ON', 'OFF',
    'PRINT','NUM'
)

# Token regex
# token with some action code

def t_ON(t):
    r'[Oo][Nn]'
    t.lexer.semaforo = True

def t_OFF(t):
    r'[Oo][Ff]{2}'
    t.lexer.semaforo = False

def t_PRINT(t):
    r'='
    print("soma = ",t.lexer.soma)


def t_NUM(t):
    r'\d+'
    if t.lexer.semaforo:
        t.lexer.soma += int(t.value)

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

# my state
lexer.soma = 0
lexer.semaforo = True

# reading input
for linha in sys.stdin:
    lexer.input(linha)
    for tok in lexer:
        print(tok) # ou pass para não dar print mas iterar


