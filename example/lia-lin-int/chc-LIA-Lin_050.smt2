; ./aeval-unsafe/./unsafe/s_split_17_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= A 0) (not (<= D C)) (= B 0))
      )
      (inv D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv G F H E)
        (and (= C (+ 2 F))
     (= B (ite (<= F G) H (+ 1 H)))
     (= A (ite (<= F G) (+ 1 E) E))
     (= D (+ 1 G)))
      )
      (inv D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv D C B A)
        (and (not (<= A 0)) (not (<= B 1000)))
      )
      false
    )
  )
)

(check-sat)
(exit)
