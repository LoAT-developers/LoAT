; ./aeval-unsafe/./unsafe/s_split_50_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 0) (= B 0) (= A 0) (= D 0))
      )
      (inv D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv F H G E)
        (and (= C (+ 1 H))
     (= B (ite (<= 1000 F) G (+ 1 G)))
     (= A (ite (>= F 1000) (+ 1 E) E))
     (= D (mod (+ 1 F) 2000)))
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
        (and (= C 999000) (= 1000 (+ B (* (- 1) A))))
      )
      false
    )
  )
)

(check-sat)
(exit)
