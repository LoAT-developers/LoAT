; ./vmt/./ctigar/simple_if.c_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Int Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Bool) ) 
    (=>
      (and
        (and (= A true) (not G) (not F) (not B))
      )
      (state B A G F C D E)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) ) 
    (=>
      (and
        (state B A N M H J L)
        (let ((a!1 (and (not F) E D C (= J I) (= L K) (= (+ (* 3 H) (* (- 1) G)) 0)))
      (a!2 (and (not F)
                E
                (not D)
                C
                (= J I)
                (= L K)
                (= (+ (* 2 H) (* (- 1) G)) 0)))
      (a!3 (and F (not E) D C (= H G) (= J I) (= L K)))
      (a!4 (and (not F) (not E) (not D) (not C) (= H G) (= J I) (= L K))))
  (and (or A
           B
           N
           (not M)
           (<= H 0)
           (and F (not E) (not D) C (= H G) (= J I) (= L K)))
       (or A
           M
           N
           (not B)
           (not (<= L H))
           (and F (not E) (not D) (not C) (= H G) (= J I) (= L K)))
       (or M
           N
           (not B)
           (not A)
           (not (<= J 0))
           (and (not F) E D (not C) (= H G) (= J I) (= L K)))
       (or M
           N
           (not B)
           (not A)
           (<= J 0)
           (and (not F) E (not D) (not C) (= H G) (= J I) (= L K)))
       (or A
           M
           N
           (not B)
           (<= L H)
           (and (not F) (not E) D C (= H G) (= J I) (= L K)))
       (or A M (not N) (not B) a!1)
       (or A B M (not N) a!2)
       (or N (not M) (not B) (not A) a!3)
       (or B
           N
           (not M)
           (not A)
           (and F (not E) D (not C) (= H G) (= J I) (= L K)))
       (or M
           (not N)
           (not B)
           (not A)
           (and (not F) E (not D) C (= H G) (= J I) (= L K)))
       (or B
           M
           (not N)
           (not A)
           (and (not F) (not E) D (not C) (= H G) (= J I) (= L K)))
       (or A B M N a!4)
       (or A N (not M) (not B) a!4)
       (or B
           M
           N
           (not A)
           (and (not F) (not E) D (not C) (= G 1) (= J I) (= L K)))
       (or A B N (not M) (not (<= H 0)) a!3)))
      )
      (state D C E F G I K)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Bool) ) 
    (=>
      (and
        (state B A G F C D E)
        (and (= A true) (not G) (= F true) (= B true))
      )
      false
    )
  )
)

(check-sat)
(exit)
