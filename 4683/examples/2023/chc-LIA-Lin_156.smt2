; ./prepared/vmt/./lustre/twisted_counters_000.smt2
(set-logic HORN)


(declare-fun |state| ( Int Bool Bool Bool Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Int) (Q Int) ) 
    (=>
      (and
        (and (= I H)
     (= (= H 5) O)
     (= (or (not K) (= M L)) J)
     (= (and C B) N)
     (= O M)
     (= N L)
     (= D B)
     (= F E)
     (= G C)
     (not D)
     (not F)
     (not G)
     (= I 0))
      )
      (state I G F D H O C E B N M L K J P Q A)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Bool) (K Int) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Int) (H1 Int) ) 
    (=>
      (and
        (state I G F D H F1 C E B E1 D1 C1 B1 A1 G1 H1 A)
        (let ((a!1 (= J (or (and C E) (and B (not C) B1))))
      (a!2 (= L (or (and B (not B1)) (not (= E C)))))
      (a!3 (or (= H 4) (= (+ H (* (- 1) N)) (- 1)))))
  (and (= Z P)
       (= I H)
       (= (= Z 5) V)
       (= (= H 5) F1)
       (= (or (not B1) (= D1 C1)) A1)
       (= (or (not R) (= T S)) Q)
       (= (and X W) U)
       (= (and B C) E1)
       (= F1 D1)
       (= E1 C1)
       a!1
       a!2
       (= U S)
       (= V T)
       (= W J)
       (= X M)
       (= Y L)
       (= G C)
       (= F E)
       (= D B)
       (not (= C M))
       a!3
       (or (not (= H 4)) (= N K))
       (or (not (= H 5)) (= O 2))
       (or (= H 5) (= O N))
       (or B1 (= K 3))
       (or (not B1) (= K 5))
       (= P O)))
      )
      (state P M L J Z V X Y W U T S R Q K N O)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Int) (Q Int) ) 
    (=>
      (and
        (state I G F D H O C E B N M L K J P Q A)
        (not J)
      )
      false
    )
  )
)

(check-sat)
(exit)
