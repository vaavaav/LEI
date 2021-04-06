#
# Somador on/off com condições de contexto
#    - semáforo está on de início
#    - lê do input
#    - reagir a estímulos:
#           r'[oO][nN]' --> ligar o semáforo
#           r'(o|O)(n|N)'
#           r'[oO][fF]{2}' --> desligar o semáforo
#           r'(o|O)(f|F)(f|F)'
#           r'='  --> escrever o valor acumulado
#           r'\d+' --> acrescentar o valor lido ao acumulado se semáforo ligado
#           qq outra coisa --> descartar

import ply.lex as lex
import sys

# Context conditions declaration
states = (
    ('off', 'inclusive'),
)

# Rules for initial state

# tokens declarations
tokens = (
    'ON', 'OFF',
    'PRINT','NUM'
)

# Token regex
# token with some action code

def t_ON(t):
    r'[Oo][Nn]'
    t.lexer.skip(len(t.value))

def t_OFF(t):
    r'[Oo][Ff]{2}'
    t.lexer.begin('off')

def t_PRINT(t):
    r'='
    print("soma = ",t.lexer.soma)


def t_NUM(t):
    r'\d+'
    t.lexer.soma += int(t.value)

#tracking line numbers
def t_newline(t):
    r'\n+'
    t.lexer.lineno += len(t.value)

#characters to be ignored
t_ignore = " \t"

# errors
def t_error(t):
    t.lexer.skip(1)


# Rules for the off state

def t_off_ON(t):
    r'[Oo][Nn]'
    t.lexer.begin('INITIAL')

def t_off_NUM(t):
    r'\d+'
    t.lexer.skip(len(t.value))

# build the lexer
lexer = lex.lex()

# My state
lexer.soma = 0


# reading input
for linha in sys.stdin:
    lexer.input(linha)
    for tok in lexer:
        pass