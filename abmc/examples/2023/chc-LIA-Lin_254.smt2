; ./prepared/aeval/./multi-phase/s_split_30_000.smt2
(set-logic HORN)


(declare-fun |fail| ( ) Bool)
(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B 97) (= C (- 76)) (= D 0) (= A 52))
      )
      (inv A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv C A B D)
        (let ((a!1 (= H (ite (<= G 0) D (+ D (* (- 1) C))))))
  (and (= F (+ 54 (* (- 2) A)))
       (= G (+ (- 8754) (* (- 5) C) (* 3 A) (* 4 B)))
       a!1
       (= E (+ 13 (* (- 7) C)))))
      )
      (inv E F G H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv A C B D)
        (and (<= D 0) (>= C 80914))
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
