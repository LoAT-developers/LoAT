; ./prepared/extra-small-lia/./count_by_2_m_nest_000.smt2
(set-logic HORN)


(declare-fun |itp1| ( Int ) Bool)
(declare-fun |itp2| ( Int Int ) Bool)

(assert
  (forall ( (v_0 Int) ) 
    (=>
      (and
        (and true (= 0 v_0))
      )
      (itp1 v_0)
    )
  )
)
(assert
  (forall ( (A Int) (v_1 Int) ) 
    (=>
      (and
        (itp1 A)
        (and (not (<= 256 A)) (= 0 v_1))
      )
      (itp2 A v_1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (itp2 B A)
        (and (not (<= 16 A)) (= C (+ 2 A)))
      )
      (itp2 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (itp2 A B)
        (and (>= B 16) (= C (+ A B)))
      )
      (itp1 C)
    )
  )
)
(assert
  (forall ( (A Int) ) 
    (=>
      (and
        (itp1 A)
        (and (>= A 256) (not (= A 256)))
      )
      false
    )
  )
)

(check-sat)
(exit)
