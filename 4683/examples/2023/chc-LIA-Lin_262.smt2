; ./prepared/aeval/./multi-phase/s_split_24_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (or (= A 0) (= A 1)) (or (= B 0) (= B 1)) (= C 0))
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
        (let ((a!1 (= F (ite (= (mod A 2) (mod B 2)) (+ 1 C) C))))
  (and (= E (+ 3 B)) a!1 (= D (+ 2 A))))
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
        (and (not (<= B 400)) (not (>= C 100)))
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
