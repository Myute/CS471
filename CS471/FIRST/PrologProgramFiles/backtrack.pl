% Yoshii - Prolog Backtracking example
% Run this with a(What) to find all possible answers.

% gprolog requires the same predicates to be grouped together

d(apple).
d(apricot).

e(orange).

f(apricot).
f(orange).

a(X) :- b(X), c(X).

b(X) :- d(X).
b(X) :- e(X).

c(X) :- f(X).

