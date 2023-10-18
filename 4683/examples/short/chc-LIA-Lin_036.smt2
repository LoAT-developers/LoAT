; ./prepared/aeval-unsafe/./unsafe/s_split_48_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (= A 0) (= B 0))
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
        (let ((a!1 (= A
              (ite (<= 5000 D)
                   (ite (>= D 6000) (+ (- 1) C) (+ (- 4) C))
                   (ite (>= D 4000) (+ 4 C) (+ 1 C))))))
  (and a!1 (= B (+ 1 D))))
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
        (and (= A 0) (= B 10000))
      )
      false
    )
  )
)

(check-sat)
(exit)
