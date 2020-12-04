;; Name: Kevyn Higbee
;; File: 12B.lisp
;; Assignment: ex12b
;; Date: Nov. 19 2020

(setf (get 'Spot 'age) 7)
(setf (get 'Spot 'color) 'tan)
(setf (get 'Spot 'species) 'dog)


(defun main ()
    (prog(x)
        (princ "Ask for a property of Spot. Properties are 'age', 'color', and 'species'. Enter 'done' to quit.")
        (terpri)
        (setq x (read))
        (loop while(not (string-equal "done" x)) do
            (princ (get 'Spot x))
            (terpri)
            (princ "Ask for a property of Spot. Properties are 'age', 'color', and 'species'. Enter 'done' to quit.")
            (terpri)
            (setq x (read))
        )
    )
)

(main)