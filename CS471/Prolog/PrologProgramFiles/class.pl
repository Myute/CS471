
% rules for class

topc :- write('give me the cs class: '), read(C),
    classinfo(C, instructor(I), days(D), times(T)),
    write(I), nl, write(D), nl, write(T), nl.

topd :- write('give me the days you want: '), read(D),
    classinfo(C, instructor(I), days(D), times(T)),
    write(C), nl, write(I), nl, write(T), nl.

% class facts
classinfo(cs311, instructor('Rika Yoshii'), days('TR'), times('1:00-2:15')).
classinfo(cs471, instructor('Rika Yoshii'), days('MWF'), times('4:00-5:15')).
classinfo(cs211, instructor('Rika Yoshii'), days('MW'), times('9:00-10:15')).