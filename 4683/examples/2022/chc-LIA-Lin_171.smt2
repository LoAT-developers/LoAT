; ./vmt/./ctigar/dillig15.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Int Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Bool) ) 
    (=>
      (and
        (and (= A true) (not H) (not G) (not B))
      )
      (state B A H G C D E F)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) ) 
    (=>
      (and
        (state B A P O H J L N)
        (let ((a!1 (or A
               O
               (not P)
               (not B)
               (<= (+ J (* (- 1) N)) (- 1))
               (and F (not E) D (not C) (= H G) (= J I) (= L K) (= N M))))
      (a!2 (not (<= (+ J (* (- 1) N)) (- 1))))
      (a!3 (and F
                (not E)
                (not D)
                (not C)
                (= H G)
                (= L K)
                (= N M)
                (= (+ J (* (- 1) I)) (- 1))))
      (a!4 (and F
                (not E)
                (not D)
                C
                (= H G)
                (= J I)
                (= N M)
                (= (+ L (* (- 1) K)) 1)))
      (a!5 (and F E D C (= H G) (= J I) (= L K) (= N M)))
      (a!6 (and (not F) (not E) (not D) (not C) (= H G) (= J I) (= L K) (= N M))))
  (and (or A
           B
           (not O)
           (not P)
           (<= L (- 1))
           (and F E (not D) C (= H G) (= J I) (= L K) (= N M)))
       (or A
           P
           (not O)
           (not B)
           (not (<= N J))
           (and F E (not D) (not C) (= H G) (= J I) (= L K) (= N M)))
       (or A
           P
           (not O)
           (not B)
           (<= N J)
           (and F (not E) D C (= H G) (= J I) (= L K) (= N M)))
       a!1
       (or A
           O
           (not P)
           (not B)
           a!2
           (and (not F) E D C (= H G) (= J I) (= L K) (= N M)))
       (or O
           P
           (not B)
           (not A)
           (not (<= N L))
           (and (not F) E (not D) C (= H G) (= J I) (= L K) (= N M)))
       (or O
           P
           (not B)
           (not A)
           (<= N L)
           (and (not F) E (not D) (not C) (= H G) (= J I) (= L K) (= N M)))
       (or B
           O
           P
           (not A)
           (not (<= 1 N))
           (and (not F) (not E) D C (= H G) (= J I) (= L K) (= N M)))
       (or B
           O
           P
           (not A)
           (<= 1 N)
           (and (not F) (not E) D (not C) (= H G) (= J I) (= L K) (= N M)))
       (or O (not P) (not B) (not A) a!3)
       (or A B P (not O) a!4)
       (or (not O) (not P) (not B) (not A) a!5)
       (or B
           (not O)
           (not P)
           (not A)
           (and F E D (not C) (= H G) (= J I) (= L K) (= N M)))
       (or B
           P
           (not O)
           (not A)
           (and (not F) E D (not C) (= H G) (= J I) (= L K) (= N M)))
       (or A B O P a!6)
       (or A B O (not P) a!6)
       (or A O P (not B) a!6)
       (or A (not O) (not P) (not B) a!6)
       (or P (not O) (not B) (not A) a!6)
       (or B
           O
           (not P)
           (not A)
           (and (not F) E D (not C) (= I 0) (= H G) (= L K) (= N M)))
       (or A B (not O) (not P) (not (<= L (- 1))) a!5)))
      )
      (state D C E F G I K M)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Bool) ) 
    (=>
      (and
        (state B A H G C D E F)
        (and (= A true) (= H true) (= G true) (= B true))
      )
      false
    )
  )
)

(check-sat)
(exit)
