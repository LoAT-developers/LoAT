; ./aeval-unsafe/./unsafe/s_split_06_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 0) (= A 0) (= C 1))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv E F D)
        (and (= B (ite (<= E 0) F (+ 1 F)))
     (= A (ite (<= E 0) (+ 1 D) D))
     (= C (* (- 1) E)))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv C B A)
        (and (= C 1) (= B 342341341) (= 342341341 A))
      )
      false
    )
  )
)

(check-sat)
(exit)
