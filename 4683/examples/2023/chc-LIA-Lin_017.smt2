; ./prepared/extra-small-lia/./half_true_modif_m_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int Int ) Bool)
(declare-fun |inv1| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 0) (= A 0) (>= B 0) (= D 0))
      )
      (inv1 A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv1 B A D E)
        (= C (+ 1 A))
      )
      (inv1 B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv1 B A D E)
        (= C (+ 52 A))
      )
      (inv B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv B E A C)
        (and (= F (ite (= C 0) (+ 1 A) A))
     (= D (+ 1 B))
     (not (<= (* 2 E) B))
     (= G (ite (= C 0) 1 0)))
      )
      (inv D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv B D C A)
        (and (>= B (* 2 D)) (not (= C D)))
      )
      false
    )
  )
)

(check-sat)
(exit)
