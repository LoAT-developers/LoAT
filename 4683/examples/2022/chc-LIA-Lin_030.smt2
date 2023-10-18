; ./aeval-unsafe/./unsafe/s_split_25_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 10) (= A 0) (= C 0))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv F E D)
        (and (= B (mod (+ 9 E) 10))
     (= A (ite (= F E) 0 (+ 1 D)))
     (= C (mod (+ 1 F) 10)))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv C B A)
        (<= A 5)
      )
      false
    )
  )
)

(check-sat)
(exit)
