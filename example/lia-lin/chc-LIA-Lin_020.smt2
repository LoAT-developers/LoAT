; ./extra-small-lia/./dillig32_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (= B C) (= A 100) (or (= E 0) (= E 1)) (= D 0))
      )
      (inv A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (inv E A B D C)
        (and (= H (+ 1 D))
     (= G (ite (= C 0) B (+ 1 B)))
     (= F (ite (= C 0) (+ 1 A) A))
     (not (<= (* 2 E) D))
     (= I (ite (= C 0) 1 0)))
      )
      (inv E F G H I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv C D E B A)
        (and (= B (* 2 C)) (not (= D E)))
      )
      false
    )
  )
)

(check-sat)
(exit)
