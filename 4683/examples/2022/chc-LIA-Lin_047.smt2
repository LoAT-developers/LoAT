; ./aeval-unsafe/./unsafe/s_split_07_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (not (<= D C)) (not (<= C B)) (= A 0))
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
        (and (= C (+ 3 F)) (= B (+ 2 H)) (= A (ite (<= F G) E (+ 1 E))) (= D (+ 1 G)))
      )
      (inv D C B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv B D C A)
        (let ((a!1 (not (<= (+ C (* (- 1) B)) 72531))))
  (and (not (<= A 0)) a!1))
      )
      false
    )
  )
)

(check-sat)
(exit)
