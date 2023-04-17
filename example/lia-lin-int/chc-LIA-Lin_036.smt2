; ./aeval-unsafe/./unsafe/s_split_30_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 97) (= B (- 76)) (= A 0) (= D 52))
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
        (let ((a!1 (= A (ite (<= B 0) E (+ E (* (- 1) F))))))
  (and (= C (+ 54 (* (- 2) H)))
       (= B (+ (- 8754) (* (- 5) F) (* 3 H) (* 4 G)))
       a!1
       (= D (+ 13 (* (- 7) F)))))
      )
      (inv D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv D B C A)
        (and (not (<= A 0)) (>= B 80914))
      )
      false
    )
  )
)

(check-sat)
(exit)
