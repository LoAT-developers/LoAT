; ./prepared/extra-small-lia/./dillig22_m_000.smt2
(set-logic HORN)


(declare-fun |inv| ( Int Int Int Int ) Bool)
(declare-fun |inv1| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (and (= C 0) (= B 0) (= A 0) (= D 0))
      )
      (inv1 A B C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv1 B C D A)
        (= E (+ 14 A))
      )
      (inv1 B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv1 B C D A)
        (= E (+ 2 A))
      )
      (inv B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (inv B C A G)
        (let ((a!1 (= D (ite (= (mod A 2) 0) (+ 1 B) B))))
  (and (= E (+ 1 C)) a!1 (not (<= G C)) (= F (+ D E))))
      )
      (inv D E F G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv D B A C)
        (and (= B C) (not (= C D)))
      )
      false
    )
  )
)

(check-sat)
(exit)
