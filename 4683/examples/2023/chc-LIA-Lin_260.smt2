; ./prepared/aeval/./multi-phase/s_split_53_000.smt2
(set-logic HORN)


(declare-fun |fail| ( ) Bool)
(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= B 0) (= C 0) (= D 500) (= A 0))
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
     (= G (ite (<= 500 C) (+ (- 1) B) (+ 1 B)))
     (= H (ite (>= C 500) (+ 1 D) (+ (- 1) D)))
     (= E (mod (+ 1 C) 1000)))
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
        (and (not (= C D)) (= B 2250))
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
