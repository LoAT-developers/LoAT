; ./prepared/extra-small-lia/./const_mod_3_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 0) (= B 0))
      )
      (inv A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv A B)
        (and (= C (+ 1 A)) (= D (ite (= B 0) 1 0)))
      )
      (inv C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv B A)
        (not (ite (= A 1) (= (mod B 2) 1) (= (mod B 2) 0)))
      )
      false
    )
  )
)

(check-sat)
(exit)
