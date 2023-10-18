; ./extra-small-lia/./s_multipl_25_000.smt2
(set-logic HORN)

(declare-fun |inv2| ( Int Int Int Int ) Bool)
(declare-fun |inv1| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 0) (= B 0) (= A 0) (= D 0))
      )
      (inv1 A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv1 B C A G)
        (and (= E (+ C (* (- 1) F))) (= D (+ B F)) (= F (+ 1 A)))
      )
      (inv1 D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv1 A B C D)
        true
      )
      (inv2 A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv2 B C F A)
        (and (= E (+ C G)) (= D (+ B (* (- 1) G))) (= G (+ 1 A)))
      )
      (inv2 D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv2 C D A B)
        (and (not (<= A B)) (<= C D))
      )
      false
    )
  )
)

(check-sat)
(exit)
