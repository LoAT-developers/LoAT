; ./prepared/aeval-unsafe/./unsafe/s_split_53_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 0) (= B 0) (= A 500) (= D 0))
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
     (= B (ite (<= 500 F) (+ (- 1) G) (+ 1 G)))
     (= A (ite (>= F 500) (+ 1 E) (+ (- 1) E)))
     (= D (mod (+ 1 F) 1000)))
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
        (and (= B A) (= C 2250))
      )
      false
    )
  )
)

(check-sat)
(exit)
