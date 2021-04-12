%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SIST. REPR. CONHECIMENTO E RACIOCINIO - MiEI/3

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Programacao em logica estendida
% Representacao de conhecimento imperfeito

%--------------------------------- - - - - - - - - - -  -  -  -  -   -


%--------------------------------- - - - - - - - - - -  -  -  -  -   -


:- op( 900,xfy,'::' ).
:- dynamic servico/2.
:- dynamic ato/4.


%-------------------------------------------------
% Aplicação do PMF

-servico(Servico, Nome) :- 
    nao(servico(Servico, Nome)), 
    nao(excecao(servico(Servico, Nome))).
	
-ato(Ato, Prestador, Utente, Dia) :- 
    nao(ato(Ato, Prestador, Utente, Dia)), 
    nao(excecao(ato(Ato, Prestador, Utente, Dia))).

%--------------------------------- - - - - - - - - - -  -

servico(ortopedia, amelia).
servico(obstetricia, ana).
servico(obstetricia, maria).
servico(obstetricia, mariana).
servico(geriatria, sofia).
servico(geriatria, susana).

servico(c007, teodora).
excecao(servico(_,Nome)) :- servico(c007,Nome).
					

servico(atNP9, zulmira).
excecao(servico(_, Nome)) :- servico(atNP9, Nome).

nulo(atNP9).
+servico(Servico, Nome) :: 
    (solucoes(Servico, (servico(Servico, zulmira), nao(nulo(Servico))), S),
    comprimento(S,N), N == 0).


%- -- - - - --- -- --  -- -- -


+ato(_,_,_,Dia) :: nao(feriado(Dia)).

%- -- - - - --- -- --  -- -- -

-servico(_,Nome) :: (solucoes(Nome, ato(_,Nome,_,_), S),
                     comprimento(S,N), N == 0).


%- -- - - - --- -- --  -- -- -

ato(penso,ana,joana,sabado).
ato(gesso,amelia,jose,domingo).
ato(domicilio,susana,[joao,jose],segunda).

ato(c017,mariana,joaquina,domingo).
excecao(ato(_,NomeE,NomeU,Dia)) :- ato(c017,NomeE,NomeU,Dia).

ato(domicilio,maria,c121,c251).
excecao(ato(Ato,NomeE,_,_)) :- ato(Ato,NomeE,c121,c251).

excecao(ato(domicilio,susana,NomeU,segunda)):- pertence(NomeU,[joao,josue]).

ato(sutura,c313,josue,segunda).
excecao(ato(Ato,_,NomeU,Dia)) :- ato(Ato,c313,NomeU,Dia).

excecao(ato(sutura,NomeE,josefa,Dia)):- pertence(NomeE,[maria,mariana]), pertence(Dia,[terca,sexta]).

excecao(ato(penso,ana,jacinta,Dia)):- pertence(Dia, [segunda,terca,quarta,quinta,sexta,sabado,domingo]).

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
% Extensão do predicado que permite a involucao do conhecimento

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



pertence( X,[X|L] ).
pertence( X,[Y|L] ) :-
    X \= Y,
    pertence( X,L ).


					

				 


