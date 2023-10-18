; ./prepared/aeval/./multi-phase/s_split_45_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (= A 0)
      )
      (inv A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv B A C)
        (let ((a!1 (= E (ite (>= B 765552) (ite (>= B 865552) A (+ 1 A)) 0)))
      (a!2 (= F (ite (>= B 663258) (ite (>= B 763258) C (+ 1 C)) 0))))
  (and a!1 a!2 (= D (+ 1 B))))
      )
      (inv D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (inv A B C)
        (and (>= A 965552) (not (= B C)))
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
