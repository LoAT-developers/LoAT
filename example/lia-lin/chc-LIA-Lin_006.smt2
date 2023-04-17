; ./extra-small-lia/./dillig12_m_000.smt2
(set-logic HORN)

(declare-fun |SAD| ( Int Int ) Bool)
(declare-fun |FUN| ( Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (and (= C 0) (= B 0) (= A 0) (= D 0))
      )
      (FUN A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) ) 
    (=>
      (and
        (FUN A B C D J)
        (and (= I (ite (= J 1) (+ E F) E))
     (= H (+ C F))
     (= G (+ 1 B))
     (= F (+ 1 A))
     (= E (+ D G)))
      )
      (FUN F G H I J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (FUN A B E D C)
        (let ((a!1 (= F (ite (= C 1) (+ 2 D (* (- 2) E)) 1))))
  (and a!1 (= G 0)))
      )
      (SAD F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) ) 
    (=>
      (and
        (SAD B A)
        (and (or (= C (+ 1 A)) (= C (+ 2 A))) (<= A B))
      )
      (SAD B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (SAD A B)
        (and (>= B A) (>= B 5))
      )
      false
    )
  )
)

(check-sat)
(exit)
