; ./extra-small-lia/./menlo_park_term_simpl_2_000.smt2
(set-logic HORN)

(declare-fun |inv| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 1) (>= D A) (not (<= B 1)) (not (<= A 0)) (= (mod B 2) 0))
      )
      (inv A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) ) 
    (=>
      (and
        (inv A B C D)
        (and (= G (* (- 1) C))
     (= F (+ B (* (- 1) C)))
     (= E (+ A (* (- 1) B)))
     (not (<= A 0))
     (= H (+ (- 1) D)))
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
        (and (not (<= C 0)) (not (<= 0 D)))
      )
      false
    )
  )
)

(check-sat)
(exit)
