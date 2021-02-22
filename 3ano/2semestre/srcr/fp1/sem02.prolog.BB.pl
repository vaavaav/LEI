%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SIST. REPR. CONHECIMENTO E RACIOCINIO - MiEI/3

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Base de Conhecimento com informacao genealogica.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado filho: Filho,Pai -> {V,F}

filho( joao,jose ).
filho( jose,manuel ).
filho( carlos,jose ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado pai: Pai,Filho -> {V,F}

pai(paulo, filipe).
pai(paulo, maria).
pai(paulo,jose).


pai( P,F ) :- filho( F,P ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado avo: Avo,Neto -> {V,F}

avo(antonio, nadia).
avo(ana, nuno).


avo(A, N) :- filho(A, F), filho(F, N).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado bisavo: Bisavo,Bisneto -> {V,F}


bisavo(BA, BN) :- filho(BA, A), avo(A, BN).


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado descendente: Descendente,Ascendente -> {V,F}

desc(D,A) :- pai(A,D).
desc(D,A) :- avo(D,A).
desc(D,A) :- bisavo(D,A).
desc(D,A) :- pai(P,D), desc(P,A).


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado descendente: Descendente,Ascendente,Grau -> {V,F}

desc(D,A,0) :- pai(A,D).
desc(D,A,1) :- avo(D,A).
desc(D,A,2) :- bisavo(D,A).
desc(D,A,N) :- pai(P,D), desc(P,A,N-1).




