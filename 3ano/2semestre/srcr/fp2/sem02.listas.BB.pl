%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SIST. REPR. CONHECIMENTO E RACIOCINIO - MiEI/3

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Operacoes sobre listas.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado pertence: Elemento,Lista -> {V,F}

pertence( X,[X|L] ).
pertence( X,[Y|L] ) :-
    X \= Y,
    pertence( X,L ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado comprimento: Lista,Comprimento -> {V,F}

comprimento( [],0 ).
comprimento( [X|L],N ) :-
    comprimento( L,N1 ),
    N is N1+1.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado diferentes: Lista,Comprimento -> {V,F}

diferentes([],0).
diferentes([H|T],N):- diferentes(T,N1), (pertence(H,T) ->  N is N1; N is N1+1).


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado apagar: Elemento,Lista,Resultado -> {V,F}

apagar(X,[X|T],T).
apagar(X,[Y|T],[Y|R]):- X/=Y, apagar(X,T,R). 



%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado apagatudo: Elemento,Lista,Resultado -> {V,F}

apagarOco(X,[],[]).
apagarOco(X,[X|T],R):- apagar(X,T,R).
apagarOco(X,[Y|T],[Y|R]):- X/=Y, apagar(X,T,R). 


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado adicionar: Elemento,Lista,Resultado -> {V,F}

adicionar(X,L,L):- pertence(X,L).
adicionar(X,L,[X|L]).


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado concatenar: Lista1,Lista2,Resultado -> {V,F}


concatenar(L1,[],L1).
concatenar([],L2,L2).
concatenar([H1|T1],L2,[H1|R]):- concatenar(T1,L2,R).


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado inverter: Lista,Resultado -> {V,F}


inverter([],[]).
inverter([H|T],R):- inverter(T,R1), R is [H|R1].  % ???


%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado sublista: SubLista,Lista -> {V,F}






