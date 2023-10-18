; ./prepared/aeval/./multi-phase/s_split_21_000.smt2
(set-logic HORN)


(declare-fun |fail| ( ) Bool)
(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B 1) (= C 0) (= D 1) (= A 0))
      )
      (inv A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv A B D C)
        (let ((a!1 (ite (= (mod (+ A B) 2) C) (+ 1 D) 0)))
  (and (= F (+ 2 B)) (= G a!1) (= H (+ 1 (* (- 1) C))) (= E (+ 1 A))))
      )
      (inv E F G H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv D A C B)
        (and (= D 10) (not (= C D)))
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
