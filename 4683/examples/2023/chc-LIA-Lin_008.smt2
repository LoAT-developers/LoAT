; ./prepared/extra-small-lia/./s_mutants_16_m_000.smt2
(set-logic HORN)


(declare-fun |itp| ( Int Int Int ) Bool)
(declare-fun |itp1| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= A 0) (not (<= 5 C)) (not (<= C 0)) (= B (* 3 C)))
      )
      (itp A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (itp A B E)
        (and (= C (+ 1 A)) (not (<= 100 A)) (= D (+ 1 B)))
      )
      (itp C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (itp A B C)
        (<= 100 A)
      )
      (itp1 A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (itp1 A B E)
        (and (= C (+ 1 A)) (not (<= 120 A)) (= D (+ 1 B)))
      )
      (itp1 C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (itp1 B C A)
        (and (or (not (<= C 132)) (not (>= C 3))) (<= 120 B))
      )
      false
    )
  )
)

(check-sat)
(exit)
