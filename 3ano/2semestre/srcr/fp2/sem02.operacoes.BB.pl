%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SIST. REPR. CONHECIMENTO E RACIOCINIO - MiEI/3

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Operacoes aritmeticas e conjuntos (listas).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado soma: X,Y,Soma -> {V,F}

soma( X,Y,Soma ) :-
    Soma is X+Y.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado soma: X,Y,Z,Soma -> {V,F}

soma(X,Y,Z,Soma):-
    Soma is X+Y+Z.


%-------------------------------
% iv. 

op(X,Y,+,Re):- Re is X+Y.
op(X,Y,-,Re):- Re is X-Y.
op(X,Y,*,Re):- Re is X*Y.
op(X,Y,/,Re):- Y /= 0, Re is X/Y.

%-------------------------------
% v. 

op([],+,0).
op([H|T],+,SUM) :- op(T,+,SUM1), SUM is SUM1 + 1.
op([],*,1).
op([H|T],*,PRU) :- op(T,+,PRU1), PRU is PRU1 + 1.

%-------------------------------
% vi.

max(X,Y,X):- X >= Y.
max(X,Y,Y):- X <  Y.

%-------------------------------
% vii.

max(X,Y,Z,M3):- max(X,Y,M1), max(X,Z,M2), max(M1,M2,M3).

%-------------------------------
% vii.