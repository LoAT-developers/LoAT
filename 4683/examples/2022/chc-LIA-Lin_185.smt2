; ./vmt/./lustre/_6countern_000.smt2
(set-logic HORN)

(declare-fun |state| ( Int Int Bool Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (= E B) (not (= (<= 0 B) A)) (= E 0))
      )
      (state E B A C D)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Int) ) 
    (=>
      (and
        (state E B A C D)
        (let ((a!1 (or (= B 5) (= (+ B (* (- 1) G)) (- 1)))))
  (and (= J H)
       (= E B)
       (not (= (<= 0 J) I))
       (not (= (<= 0 B) A))
       a!1
       (or (not (= B 5)) (= G 0))
       (= H G)))
      )
      (state H J I G F)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (state E B A C D)
        (not A)
      )
      false
    )
  )
)

(check-sat)
(exit)
