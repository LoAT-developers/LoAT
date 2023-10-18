; ./aeval-unsafe/./unsafe/s_split_18_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 1) (= B 1))
      )
      (inv B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv C D)
        (and (= A (ite (<= 16 D) (mod C 16) (* 2 D))) (= B (* 2 C)))
      )
      (inv B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv B A)
        (and (not (<= B 16)) (= 0 A))
      )
      false
    )
  )
)

(check-sat)
(exit)
