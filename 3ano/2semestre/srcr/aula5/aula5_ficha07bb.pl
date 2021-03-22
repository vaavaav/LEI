%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Programacao em logica estendida
% Representacao de conhecimento imperfeito

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Definicoes iniciais

:- op( 900,xfy,'::' ).
:- dynamic jogo/3.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado jogo: Jogo,Arbitro,Ajudas -> {V,F,D}

-jogo( Jogo,Arbitro,Ajudas ) :-
    nao( jogo( Jogo,Arbitro,Ajudas ) ),
    nao( excecao( jogo( Jogo,Arbitro,Ajudas ) ) ).


jogo( 1,aa,500 ).

jogo( 2,bb,xpto0123 ).

excecao( jogo( 3,cc,500)).
excecao( jogo( 3,cc,2000)).

excecao( jogo(4,dd,R)):- R >= 250, R =< 750.

excecao( jogo(5,ee,xpto765)).


excecao( jogo( Jogo,Arbitro,Ajudas ) ) :-
    jogo( Jogo,Arbitro,xpto0123 ).
excecao( jogo( Jogo,Arbitro,Ajudas ) ) :-
    jogo( Jogo,Arbitro,xpto765 ).

nulo(xpto765).

+jogo(J,A,C) :: (solucoes(Ajudas,(jogo(5,ee,Ajudas),
                nao(nulo(Ajudas ))), S),
                comprimento(S,N),
                N == 0).

jogo(6,ff,250).
excecao( jogo(6,ff,R)):- R > 5000.

-jogo(7,gg,2500).
jogo(7,gg,xpto0123).



%--------------------------------- - - - - - - - - - -  -  -  -  -   -

evolucao( Termo ) :-
    solucoes( Invariante,+Termo::Invariante,Lista ),
    insercao( Termo ),
    teste( Lista ).

insercao( Termo ) :-
    assert( Termo ).
insercao( Termo ) :-
    retract( Termo ),!,fail.

teste( [] ).
teste( [R|LR] ) :-
    R,
    teste( LR ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado que permite a involucao do conhecimento

involucao( Termo ) :-
    solucoes( Invariante,-Termo::Invariante,Lista ),
    remocao( Termo ),
    teste( Lista ).

remocao( Termo ) :-
    retract( Termo ).
remocao( Termo ) :-
    assert( Termo ),!,fail.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do meta-predicado demo: Questao,Resposta -> {V,F}
%                            Resposta = { verdadeiro,falso,desconhecido }

demo( Questao,verdadeiro ) :-
    Questao.
demo( Questao,falso ) :-
    -Questao.
demo( Questao,desconhecido ) :-
    nao( Questao ),
    nao( -Questao ).



%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do meta-predicado nao: Questao -> {V,F}

nao( Questao ) :-
    Questao, !, fail.
nao( Questao ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -

solucoes( X,Y,Z ) :-
    findall( X,Y,Z ).

comprimento( S,N ) :-
    length( S,N ).

