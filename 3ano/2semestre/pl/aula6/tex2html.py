# tex2html.py
#

import ply.lex as lex
import sys

# Context conditions 
states = (
    ('section', 'inclusive'),
    ('subsection', 'inclusive'),
    ('subsubsection', 'inclusive'),
)

# Tokens 

tokens = ['bSECTION','eSECTION',
          'bSUBSECTION','eSUBSECTION',
          'bSUBSUBSECTION','eSUBSUBSECTION',
          'CONTENT']

# Rules for initial state

def t_bSECTION(t):
    r'\\section\{'
    print('<h1>',end='')
    t.lexer.push_state('section')

def t_bSUBSECTION(t):
    r'\\subsection\{'
    print('<h2>',end='')
    t.lexer.push_state('subsection')

def t_bSUBSUBSECTION(t):
    r'\\subsubsection\{'
    print('<h3>',end='')
    t.lexer.push_state('subsubsection')

def t_CONTENT(t):
    r'.|\n'
    print(t.value, end='')

# Rules for section state

def t_section_eSECTION(t):
    r'\}'
    print('</h1>')
    t.lexer.pop_state()

# Rules for subsection state

def t_subsection_eSUBSECTION(t):
    r'\}'
    print('</h2>')
    t.lexer.pop_state()

# Rules for subsubsection state

def t_subsubsection_eSUBSUBSECTION(t):
    r'\}'
    print('</h3>')
    t.lexer.pop_state()


# build the lexer

lexer = lex.lex()


# reading input

for linha in sys.stdin:
    lexer.input(linha)
    for tok in lexer:
        pass