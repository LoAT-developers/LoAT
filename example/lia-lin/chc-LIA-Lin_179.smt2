; ./vmt/./ctigar/simple_nest.c_000.smt2
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
        (let ((a!1 (and F (not E) (not D) C (= H G) (= J I) (= L K)))
      (a!2 (and (not F) (not E) (not D) C (= H G) (= J I) (= L K)))
      (a!3 (and (not F) E D C (= J I) (= L K) (= (+ (* 2 H) (* (- 1) G)) 0)))
      (a!4 (and (not F) E (not D) C (= H G) (= L K) (= (+ J (* (- 1) I)) 1)))
      (a!5 (and (not F) (not E) (not D) (not C) (= H G) (= J I) (= L K))))
  (and (or M
           N
           (not B)
           (not A)
           (not (<= L H))
           (and F (not E) D (not C) (= H G) (= J I) (= L K)))
       (or B N (not M) (not A) (not (<= H 0)) a!1)
       (or A
           B
           M
           (not N)
           (not (<= J 0))
           (and F (not E) (not D) (not C) (= H G) (= J I) (= L K)))
       (or A
           B
           M
           (not N)
           (<= J 0)
           (and (not F) (not E) D C (= H G) (= J I) (= L K)))
       (or M N (not B) (not A) (<= L H) a!2)
       (or A M (not N) (not B) a!3)
       (or B M (not N) (not A) a!4)
       (or A N (not M) (not B) (and F E D (not C) (= H G) (= J I) (= L K)))
       (or A B (not M) (not N) a!1)
       (or A B N (not M) (and (not F) E D (not C) (= H G) (= J I) (= L K)))
       (or M (not N) (not B) (not A) a!2)
       (or A B M N a!5)
       (or N (not M) (not B) (not A) a!5)
       (or B
           M
           N
           (not A)
           (and (not F) E (not D) (not C) (= G 1) (= J I) (= L K)))
       (or A M N (not B) (and (not F) E D (not C) (= I 10) (= H G) (= L K)))
       (or B
           N
           (not M)
           (not A)
           (<= H 0)
           (and F E (not D) (not C) (= H G) (= J I) (= L K)))))
      )
      (state E D C F G I K)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Bool) ) 
    (=>
      (and
        (state B A G F C D E)
        (and (not A) (= G true) (= F true) (not B))
      )
      false
    )
  )
)

(check-sat)
(exit)
