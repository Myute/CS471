
% Yoshii - HW5 program

% gprolog requires the same predicates to be grouped together

% the top level goal is find
find(Who) :- wings(Who), write('The answer is: '), write(Who).

wings(X) :- fly(X).

eagle(bill).
airplane(dc10).


fly(mary).
% rules

fly(Y) :- airplane(Y).

fly(X) :- bird(X).

bird(Z) :- eagle(Z).




