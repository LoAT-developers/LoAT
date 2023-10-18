; ./extra-small-lia/./phases_m_000.smt2
(set-logic HORN)

(declare-fun |inv2| ( Int Int Int ) Bool)
(declare-fun |inv1| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (= D (* 2 A)) (= C 0) (not (<= E D)) (not (<= D 0)) (= E (+ 1 (* 2 B))))
      )
      (inv1 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv1 A C D)
        (and (not (<= C A)) (= B (ite (<= C A) (+ 2 A) (+ 1 A))))
      )
      (inv1 B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv1 A B C)
        (<= B A)
      )
      (inv2 A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv2 A C D)
        (and (not (<= D A)) (= B (ite (<= C A) (+ 2 A) (+ 1 A))))
      )
      (inv2 B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv2 C A B)
        (and (>= C B) (not (= (mod C 2) 0)))
      )
      false
    )
  )
)

(check-sat)
(exit)
