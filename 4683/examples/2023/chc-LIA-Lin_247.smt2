; ./prepared/aeval/./multi-phase/s_split_07_000.smt2
(set-logic HORN)


(declare-fun |fail| ( ) Bool)
(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (not (<= A B)) (not (<= B C)) (= D 0))
      )
      (inv A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv B C A D)
        (and (= F (+ 3 C)) (= G (+ 2 A)) (= H (ite (<= C B) D (+ 1 D))) (= E (+ 1 B)))
      )
      (inv E F G H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv C A B D)
        (let ((a!1 (not (<= (+ B (* (- 1) C)) 72531))))
  (and (<= D 0) a!1))
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
