; ./eldarica-misc/./LIA/reve/024b-horn_000.smt2
(set-logic HORN)

(declare-fun |REC_g_| ( Int Int ) Bool)
(declare-fun |REC_g_g| ( Int Int Int Int Int ) Bool)
(declare-fun |REC__g| ( Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) ) 
    (=>
      (and
        (REC__g F G E)
        (and (= B 0) (= C (+ 1 F)) (<= A 0) (not (<= C 0)) (= (+ C D) G))
      )
      (REC_g_g A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (v_4 Int) ) 
    (=>
      (and
        (and (<= C 0) (<= A 0) (= B 0) (= v_4 D))
      )
      (REC_g_g A B C D v_4)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (REC_g_g G F H I E)
        (and (= (+ C D) I)
     (= A (+ 1 G))
     (= C (+ 1 H))
     (not (<= A 0))
     (not (<= C 0))
     (= (+ A F) B))
      )
      (REC_g_g A B C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (v_6 Int) ) 
    (=>
      (and
        (REC_g_ F E)
        (and (= A (+ 1 F)) (not (<= A 0)) (<= C 0) (= (+ A E) B) (= v_6 D))
      )
      (REC_g_g A B C D v_6)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        (and (<= A 0) (= B 0))
      )
      (REC_g_ A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (REC_g_ D C)
        (and (= A (+ 1 D)) (not (<= A 0)) (= (+ A C) B))
      )
      (REC_g_ A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (v_2 Int) ) 
    (=>
      (and
        (and (<= A 0) (= v_2 B))
      )
      (REC__g A B v_2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (REC__g D E C)
        (and (= A (+ 1 D)) (not (<= A 0)) (= (+ A B) E))
      )
      (REC__g A B C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (REC_g_g D A E C B)
        (and (= C 0) (not (= A B)) (= D E))
      )
      false
    )
  )
)

(check-sat)
(exit)
