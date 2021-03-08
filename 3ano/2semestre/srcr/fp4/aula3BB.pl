%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% SIST. REPR. CONHECIMENTO E RACIOCINIO - MiEI/3

%--------------------------------- - - - - - - - - - -  -  -  -  -   -

%--------------------------------- - - - - - - - - - -  -  -  -  -   -



%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado par: N -> {V,F}

%par( 0 ).
%par( X ) :-
%    N is X-2,
%    N >= 0,
%    par( N ).
	
par(N):- N mod 2 =:= 0.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do predicado impar: N -> {V,F}

%impar( 1 ).
%impar( X ) :-
%    N is X-2,
%    N >= 1,
%    impar( N ).

impar(N):- N mod 2 =:= 1.

%--------------------------------- - - - - - - - - - -  -  -  -  -   -

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Extensao do meta-predicado nao: Questao -> {V,F}

nao( Questao ) :-
    Questao, !, fail.
nao( Questao ).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Máximo Divisor Comum


mdc(A,B,R):- A > B, A1 is A-B, mdc(A1,B,R).
mdc(A,B,R):- A < B, B1 is B-A, mdc(A,B1,R).
mdc(A,A,A).


%mdc1(A,A,A):- !.
%mdc1(1,B,1):- !.
%mdc1(A,1,1):- !.
%mdc1(A,B,R):- A > B, A1 is A-B, mdc(A1,B,R).
%mdc1(A,B,R):- A < B, B1 is B-A, mdc(A,B1,R).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Divisores


%divisores(_,1,[1]):- !.
%divisores(X,Y,[Y|T]):- X mod Y =:= 0, Y1 is Y-1, divisores(X,Y1,T).
%divisores(X,Y,T):- X mod Y =\= 0, Y1 is Y-1, divisores(X,Y1,T). 

divisores( X,NL ) :-

	XX is X // 2,

	divisores( X,XX,[1],NL ).


divisores( X,1,[H|T],[H|T] ).

divisores( X,Y,[H|T],[Y|L] ) :-

    Y > 1,						 

    X mod Y =:= 0,				 

	YY is Y-1,					

	divisores( X,YY,[H|T],L ).	

divisores( X,Y,[H|T],L ) :-

	Y > 1,

    X mod Y =\= 0,

	YY is Y-1,

	divisores( X,YY,[H|T],L ).


%--------------------------------- - - - - - - - - - -  -  -  -  -   -

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Número primo

primo(X) :- divisores(X,NL), length(NL,1).

%--------------------------------- - - - - - - - - - -  -  -  -  -   -

%--------------------------------- - - - - - - - - - -  -  -  -  -   -
% Fibonnaci

fib(1,0).
fib(1,1).
fib(N,R):- N > 1, fib(N,2,1,1,R).

fib(N,It,A,D,R):- N > It, D1 is D+A, It1 is N+1, fib(N,It1,D,D1,R).  
fib(N,N,A,D,R):- R is A+D.