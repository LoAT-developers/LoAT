; ./prepared/vmt/./lustre/car_5_e7_244_e1_823_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Int Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Int Int Int Bool Bool Bool Bool Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Bool) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Int) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) ) 
    (=>
      (and
        (and (= Q F)
     (= P 0)
     (= P D)
     (= B C1)
     (= D C)
     (= F E)
     (= K 0)
     (= K B)
     (= (= B 10) A)
     (= (<= 4 F) I1)
     (= (<= 3 D) G1)
     (= (or (not B1) (<= C1 9) (not E1) (not D1)) A1)
     (not (= (and W X) Y))
     (= V M)
     (= U I)
     (= T G)
     (= I1 H1)
     (= G1 F1)
     (= A O)
     (= G D1)
     (= I H)
     (= J B1)
     (= M E1)
     (= Z J)
     (= Z Y)
     (or I (= S R) (not G))
     (or (= S 0) (and (not I) G))
     (not V)
     (not U)
     (= T true)
     (= Q 0))
      )
      (state Z
       Y
       Q
       P
       K
       U
       V
       T
       J
       X
       W
       M
       I
       G
       S
       R
       F
       D
       B
       A
       I1
       G1
       B1
       E1
       H
       D1
       E
       C
       C1
       O
       H1
       F1
       A1
       L
       N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Bool) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Int) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Int) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Int) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Bool) (Q2 Bool) (R2 Bool) ) 
    (=>
      (and
        (state Z
       Y
       Q
       P
       K
       U
       V
       T
       J
       X
       W
       M
       I
       G
       S
       R
       F
       D
       B
       A
       R2
       P2
       K2
       N2
       H
       M2
       E
       C
       L2
       O
       Q2
       O2
       J2
       L
       N)
        (let ((a!1 (or (not C1) (not B1) (= (+ D (* (- 1) A1)) (- 2))))
      (a!2 (or (not C1) (not B1) (= (+ B (* (- 1) D1)) (- 1))))
      (a!3 (or (not F1) (= (+ F (* (- 1) E1)) (- 1)))))
  (and (= N1 M1)
       (= O1 E1)
       (= C2 L1)
       (= C2 T1)
       (= E2 M1)
       (= E2 D2)
       (= G2 O1)
       (= G2 F2)
       (= Q F)
       (= P D)
       (= K B)
       (= F E)
       (= D C)
       (= B L2)
       (= (= C2 10) B2)
       (= (= B 10) A)
       (= (<= 4 G2) Z1)
       (= (<= 4 F) R2)
       (= (<= 3 E2) X1)
       (= (<= 3 D) P2)
       (= (or (not K2) (<= L2 9) (not N2) (not M2)) J2)
       (= (or (not V1) (not U1) (not S1) (<= T1 9)) R1)
       (not (= (and H1 G1) P1))
       (not (= (and W X) Y))
       (= R2 Q2)
       (= P2 O2)
       (= B1 K1)
       (= B1 U1)
       (= C1 I1)
       (= C1 V1)
       (= F1 J1)
       (= F1 H2)
       (= G1 J1)
       (= I1 (and H1 (not G1)))
       (= K1 (and (not A) G (not P2) (not R2)))
       (= Q1 (or J P1))
       (= X1 W1)
       (= Z1 Y1)
       (= B2 A2)
       (= I2 Q1)
       (= I2 S1)
       (= Z J)
       (= V M)
       (= U I)
       (= T G)
       (= M N2)
       (= J K2)
       (= I H)
       (= G M2)
       (= A O)
       a!1
       a!2
       (or F1 (= N1 A1) (not B1))
       (or I (= S R) (not G))
       (or (= D A1) (and C1 B1))
       (or (and C1 B1) (= B D1))
       (or (= N1 0) (and (not F1) B1))
       (or (= S 0) (and G (not I)))
       a!3
       (or F1 (= F E1))
       (= L1 D1)))
      )
      (state Q1
       P1
       O1
       M1
       L1
       J1
       I1
       K1
       I2
       G1
       H1
       C1
       F1
       B1
       N1
       A1
       G2
       E2
       C2
       B2
       Z1
       X1
       S1
       V1
       H2
       U1
       F2
       D2
       T1
       A2
       Y1
       W1
       R1
       D1
       E1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Bool) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Int) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) ) 
    (=>
      (and
        (state Z
       Y
       Q
       P
       K
       U
       V
       T
       J
       X
       W
       M
       I
       G
       S
       R
       F
       D
       B
       A
       I1
       G1
       B1
       E1
       H
       D1
       E
       C
       C1
       O
       H1
       F1
       A1
       L
       N)
        (not A1)
      )
      false
    )
  )
)

(check-sat)
(exit)
