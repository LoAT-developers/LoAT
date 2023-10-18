; ./aeval/./multi-phase/s_split_50_000.smt2
(set-logic HORN)

(declare-fun |fail| ( ) Bool)
(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B 0) (= C 0) (= D 0) (= A 0))
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
        (and (= F (+ 1 A))
     (= G (ite (<= 1000 C) B (+ 1 B)))
     (= H (ite (>= C 1000) (+ 1 D) D))
     (= E (mod (+ 1 C) 2000)))
      )
      (inv E F G H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv A B C D)
        (let ((a!1 (not (= 1000 (+ C (* (- 1) D))))))
  (and (= B 999000) a!1))
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
