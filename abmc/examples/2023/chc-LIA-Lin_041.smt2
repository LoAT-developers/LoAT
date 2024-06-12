; ./prepared/aeval-unsafe/./unsafe/s_split_52_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B A) (= A 5000) (= C 0))
      )
      (inv C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv E D A)
        (and (= C (+ 1 E)) (= B (ite (>= E A) (+ 1 D) (+ (- 1) D))))
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
        (and (= B A) (= C (* 2 A)))
      )
      false
    )
  )
)

(check-sat)
(exit)
