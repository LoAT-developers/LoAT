; ./prepared/aeval/./multi-phase/s_split_22_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 767976) (= C 0) (= A 0))
      )
      (inv A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv A B C)
        (let ((a!1 (= (mod (+ A (* (- 1) B)) 3) 1)))
  (and (= E (+ (- 1) B)) (= F (ite a!1 (+ 3 C) C)) (= D (+ 1 A))))
      )
      (inv D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv B A C)
        (and (not (>= C 280275)) (>= B 280275))
      )
      fail
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        fail
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
