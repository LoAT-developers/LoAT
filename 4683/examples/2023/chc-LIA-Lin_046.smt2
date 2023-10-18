; ./prepared/aeval-unsafe/./unsafe/s_split_04_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 0) (= A 0) (= C 0))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv E F D)
        (and (= B (+ F E)) (= A (ite (<= F E) D (+ 1 D))) (= C (+ 1 E)))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv B C A)
        (and (not (<= A 0)) (>= B 3452365))
      )
      false
    )
  )
)

(check-sat)
(exit)
