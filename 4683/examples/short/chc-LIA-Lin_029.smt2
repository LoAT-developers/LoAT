; ./prepared/aeval-unsafe/./unsafe/s_split_36_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 0) (= B (- 10000)))
      )
      (inv B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv D C)
        (and (= A (ite (>= C D) (* (- 1) D) (+ 2 C))) (= B (ite (>= C D) (+ 1 D) D)))
      )
      (inv B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (inv B A)
        (and (>= B (+ (- 1) A)) (>= B 0))
      )
      false
    )
  )
)

(check-sat)
(exit)
