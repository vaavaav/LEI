%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Programacao em logica estendida

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% PROLOG: Declaracoes iniciais

:- set_prolog_flag( discontiguous_warnings,off ).
:- set_prolog_flag( single_var_warnings,off ).
:- set_prolog_flag( unknown,fail ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% PROLOG: definicoes iniciais

:- dynamic '-'/1.
:- dynamic mamifero/1.
:- dynamic morcego/1.



%--------------------------------- - - - - - - - - - -  -  -  -  -   -

voa( X ) :-
    ave( X ), nao(excecao(voa(X))).
-voa( tweety ).
-voa( X ) :-
    mamifero( X ), nao(excecao(-voa(X))).

excecao(voa(X)) :-
    avestruz(X).


ave(pitigui).

ave(X) :- canario(X).
ave(X) :- periquito(X).
canario(piupiu).
mamifero(silvestre).
cao(X):- mamifero(X).
gato(X):- mamifero(X).
cao(boby).
ave(X):- avestruz(X).
ave(X):- pinguim(X). 
avestruz(trux).

	

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do meta-predicado nao: Questao -> {V,F}

nao( Questao ) :-
    Questao, !, fail.
nao( Questao ).


%-------------

si(Questao, verdadeiro) :- Questao.
si(Questao, falso) :- -Questao.
si(Questao, desconhecido) :- 
    nao(Questao), nao(-Questao).