; ./prepared/extra-small-lia/./bouncy_symmetry_000.smt2
(set-logic HORN)


(declare-fun |itp2| ( Int Int ) Bool)
(declare-fun |itp1| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 0) (= B 0))
      )
      (itp1 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (itp1 A B)
        (and (= C (+ 1 A)) (= D (+ 1 B)))
      )
      (itp1 C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (itp1 A B)
        true
      )
      (itp2 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (itp2 A B)
        (and (= C (+ (- 1) A)) (= D (+ (- 1) B)))
      )
      (itp2 C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (itp2 A B)
        (and (<= A 0) (not (<= B 0)))
      )
      false
    )
  )
)

(check-sat)
(exit)
