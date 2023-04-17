; ./extra-small-lia/./s_multipl_07_000.smt2
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
        (and (= C (+ 1 A)) (not (<= 1000 B)) (= D (+ 1 B)))
      )
      (FUN C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (FUN B A)
        (and (= C B) (>= A 1000) (= D 0))
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
        (and (= C (+ 1 A)) (not (<= 1000 B)) (= D (+ 1 B)))
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
        (and (not (<= 2000 B)) (>= A 1000))
      )
      false
    )
  )
)

(check-sat)
(exit)
