; ./extra-small-lia/./dtuc_000.smt2
(set-logic HORN)

(declare-fun |FUN| ( Int Int Int Int ) Bool)
(declare-fun |SAD| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= A 0) (= C 0))
      )
      (FUN A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (FUN A D B F)
        (and (= C (+ 1 A)) (not (<= F A)) (= E (+ 1 B)))
      )
      (FUN C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (FUN B A D E)
        (and (= B E) (= C E))
      )
      (SAD B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (SAD C B A F)
        (and (= D (+ (- 1) B)) (not (<= B 0)) (= E (+ (- 1) A)))
      )
      (SAD C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (SAD A C D B)
        (and (not (<= C 0)) (<= D 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
