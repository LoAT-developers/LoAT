; ./extra-small-lia/./s_multipl_22_000.smt2
(set-logic HORN)

(declare-fun |FUN| ( Int Int ) Bool)
(declare-fun |SAD| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 0) (= B 0))
      )
      (FUN A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (FUN A B)
        (and (= C (+ 1 A)) (= D (+ B C)))
      )
      (FUN C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (FUN A B)
        (and (= C A) (not (<= A 0)) (= D (+ 1 B)))
      )
      (SAD C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (SAD A B)
        (and (= C (+ (- 1) A)) (not (<= B 0)) (= D (+ B (* (- 1) C))))
      )
      (SAD C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (SAD B A)
        (and (<= A 0) (<= 0 B))
      )
      false
    )
  )
)

(check-sat)
(exit)
