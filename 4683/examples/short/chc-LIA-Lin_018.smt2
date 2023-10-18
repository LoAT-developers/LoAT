; ./prepared/extra-small-lia/./count_by_2_000.smt2
(set-logic HORN)


(declare-fun |itp2| ( Int Int ) Bool)
(declare-fun |itp1| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 0) (= B 128))
      )
      (itp1 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (itp1 A C)
        (and (not (<= C A)) (= B (+ 2 A)))
      )
      (itp1 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (itp1 B A)
        (and (>= B A) (= C (+ 128 A)))
      )
      (itp2 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (itp2 A C)
        (and (not (<= C A)) (= B (+ 2 A)))
      )
      (itp2 B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (itp2 A B)
        (and (>= A B) (not (= A B)))
      )
      false
    )
  )
)

(check-sat)
(exit)
