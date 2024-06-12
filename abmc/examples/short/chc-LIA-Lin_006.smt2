; ./prepared/extra-small-lia/./s_multipl_24_000.smt2
(set-logic HORN)


(declare-fun |FUN| ( Int Int Int Int ) Bool)
(declare-fun |SAD| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) ) 
    (=>
      (and
        (and (= C 0) (= B 0) (not (<= D 0)) (= D (+ 1 (* 2 A))) (= 0 v_4))
      )
      (FUN B C v_4 D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (FUN A C B G)
        (and (= E (ite (= B 0) (+ 1 C) C))
     (= D (+ 1 A))
     (not (<= G A))
     (= F (ite (= B 0) 1 0)))
      )
      (FUN D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (v_6 Int) ) 
    (=>
      (and
        (FUN A C B F)
        (and (= D 0) (>= C F) (= E C) (= 0 v_6))
      )
      (SAD D E v_6 F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (SAD A C B G)
        (and (= E (ite (= B 1) (+ 1 C) C))
     (= D (+ 1 A))
     (not (<= G A))
     (= F (ite (= B 0) 1 0)))
      )
      (SAD D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (SAD B D A C)
        (and (>= B C) (not (= C D)))
      )
      false
    )
  )
)

(check-sat)
(exit)
