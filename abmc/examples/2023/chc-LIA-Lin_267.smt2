; ./prepared/aeval/./multi-phase/s_split_32_000.smt2
(set-logic HORN)


(declare-fun |fail| ( ) Bool)
(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B 0) (= C 1) (or (= D 0) (= D 1)) (= A D))
      )
      (inv A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv B C D A)
        (let ((a!1 (= G (ite (= A (mod B 2)) (+ D C) (+ (- 1) D)))))
  (and (= F (+ (- 3) C B)) a!1 (= H (+ 1 (* (- 1) A))) (= E (+ 1 B))))
      )
      (inv E F G H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv C A D B)
        (and (not (<= C 10)) (not (>= D 0)))
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
