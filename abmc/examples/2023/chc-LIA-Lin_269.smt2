; ./prepared/aeval/./multi-phase/s_split_06_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int ) Bool)
(declare-fun |fail| ( ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (and (= B 0) (= C 0) (= A 1))
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
        (and (= E (ite (<= B 0) A (+ 1 A)))
     (= F (ite (<= B 0) (+ 1 C) C))
     (= D (* (- 1) B)))
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
        (and (= A 1) (= B 342341341) (not (= 342341341 C)))
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
