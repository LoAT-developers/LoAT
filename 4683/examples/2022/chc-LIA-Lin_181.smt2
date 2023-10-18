; ./vmt/./ctigar/nested1.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Bool) ) 
    (=>
      (and
        (and (= A true) (not H) (not G) (not B))
      )
      (state B A H G F E D C)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) ) 
    (=>
      (and
        (state B A P O N L J H)
        (let ((a!1 (and F (not E) D C (= H G) (= J I) (= L K) (= N M)))
      (a!2 (and F
                (not E)
                D
                (not C)
                (= J I)
                (= L K)
                (= N M)
                (= (+ H (* (- 1) G)) (- 1))))
      (a!3 (and F
                E
                (not D)
                C
                (= H G)
                (= L K)
                (= N M)
                (= (+ J (* (- 1) I)) (- 1))))
      (a!4 (and (not F) (not E) (not D) (not C) (= H G) (= J I) (= L K) (= N M))))
  (and (or A
           O
           (not P)
           (not B)
           (not (<= N H))
           (and F E (not D) (not C) (= H G) (= J I) (= L K) (= N M)))
       (or O (not P) (not B) (not A) (<= 1 J) a!1)
       (or O
           (not P)
           (not B)
           (not A)
           (not (<= 1 J))
           (and F (not E) (not D) (not C) (= H G) (= J I) (= L K) (= N M)))
       (or A
           O
           (not P)
           (not B)
           (<= N H)
           (and (not F) E D C (= H G) (= J I) (= L K) (= N M)))
       (or A
           B
           O
           (not P)
           (<= N J)
           (and (not F) E (not D) C (= H G) (= J I) (= L K) (= N M)))
       (or B
           O
           P
           (not A)
           (<= L 0)
           (and (not F) (not E) D C (= H G) (= J I) (= L K) (= N M)))
       (or B
           O
           P
           (not A)
           (not (<= L 0))
           (and (not F) (not E) D (not C) (= H G) (= J I) (= L K) (= N M)))
       (or B P (not O) (not A) a!2)
       (or B
           O
           (not P)
           (not A)
           (and (not F) E D (not C) (= J I) (= L K) (= L G) (= N M)))
       (or A B (not O) (not P) a!3)
       (or P (not O) (not B) (not A) a!1)
       (or A
           B
           P
           (not O)
           (and F (not E) (not D) C (= H G) (= J I) (= L K) (= N M)))
       (or A
           P
           (not O)
           (not B)
           (and (not F) E D (not C) (= H G) (= J I) (= L K) (= N M)))
       (or B
           (not O)
           (not P)
           (not A)
           (and (not F) E (not D) (not C) (= H G) (= J I) (= L K) (= N M)))
       (or A B O P a!4)
       (or A O P (not B) a!4)
       (or A (not O) (not P) (not B) a!4)
       (or O
           P
           (not B)
           (not A)
           (and (not F) E (not D) (not C) (= I 1) (= H G) (= L K) (= N M)))
       (or A
           B
           O
           (not P)
           (not (<= N J))
           (and F E D (not C) (= H G) (= J I) (= L K) (= N M)))))
      )
      (state D C E F M K I G)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Bool) ) 
    (=>
      (and
        (state B A H G F E D C)
        (and (= A true) (not H) (= G true) (= B true))
      )
      false
    )
  )
)

(check-sat)
(exit)
