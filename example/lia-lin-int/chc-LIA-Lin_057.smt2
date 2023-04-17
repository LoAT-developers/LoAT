; ./aeval-unsafe/./unsafe/s_split_51_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 3333) (= A 6666) (= C 0))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv F E D)
        (and (= B (ite (<= 3333 F) (+ 1 E) E))
     (= A (ite (>= E 6666) (+ 1 D) D))
     (= C (+ 1 F)))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv A C B)
        (and (= A 9999) (= B A))
      )
      false
    )
  )
)

(check-sat)
(exit)
