; ./prepared/aeval-unsafe/./unsafe/s_split_15_000.smt2
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
        (and (= B (+ 1 F)) (= A (ite (<= 500 E) D (+ 2 D))) (= C (mod (+ 1 E) 1000)))
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
        (and (= B A) (not (<= B 0)) (= C 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
