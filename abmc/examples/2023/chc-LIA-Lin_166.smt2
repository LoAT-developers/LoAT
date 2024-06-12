; ./prepared/vmt/./lustre/car_all_e3_1068_e6_790_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Int Int Int Bool Bool Bool Bool Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Int) (X Int) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Bool) (I1 Bool) ) 
    (=>
      (and
        (let ((a!1 (or (not A) (and (<= 0 G1) (<= 0 B) (not (<= 11 G1)) (not (<= 4 B)))))
      (a!2 (= I1 (and H1 (not (<= 32767 G1))))))
  (and (= (<= 3 M) D)
       (= (<= 4 K) F)
       (= a!1 O)
       (not (= (and Z Y) H1))
       (= V A)
       (= U T)
       (= S R)
       (= F E)
       (= D C)
       a!2
       (= I1 V)
       (= C1 Q)
       (= B1 S)
       (= A1 U)
       (= H G)
       (= Q P)
       (= I G1)
       (= M B)
       (= K J)
       (= F1 0)
       (= F1 K)
       (= E1 0)
       (= E1 M)
       (= D1 0)
       (= D1 I)
       (or (= X W) (not Q) S)
       (or (= X 0) (and Q (not S)))
       (= C1 true)
       (not B1)
       (not A1)
       (= (= I 10) H)))
      )
      (state I1
       V
       Z
       Y
       H1
       A1
       U
       B1
       S
       C1
       Q
       X
       W
       F1
       K
       E1
       M
       D1
       I
       H
       F
       D
       A
       T
       R
       P
       J
       B
       G1
       G
       E
       C
       O
       L
       N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Int) (X Int) (Y Bool) (Z Bool) (A1 Int) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Int) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Bool) ) 
    (=>
      (and
        (state R2
       V
       Z
       Y
       Q2
       J2
       U
       K2
       S
       L2
       Q
       X
       W
       O2
       K
       N2
       M
       M2
       I
       H
       F
       D
       A
       T
       R
       P
       J
       B
       P2
       G
       E
       C
       O
       L
       N)
        (let ((a!1 (or (not T1)
               (and (<= 0 U1) (<= 0 P1) (not (<= 11 P1)) (not (<= 4 U1)))))
      (a!2 (or (not A) (and (<= 0 B) (<= 0 P2) (not (<= 11 P2)) (not (<= 4 B)))))
      (a!3 (= R1 (and V Q1 (not (<= 32767 P1)))))
      (a!4 (or (not C1) (not B1) (= (+ M (* (- 1) A1)) (- 1))))
      (a!5 (or (not C1) (not B1) (= (+ I (* (- 1) D1)) (- 1))))
      (a!6 (or (not F1) (= (+ K (* (- 1) E1)) (- 1)))))
  (and (= (= I 10) H)
       (= (<= 3 C2) W1)
       (= (<= 3 M) D)
       (= (<= 4 E2) Y1)
       (= (<= 4 K) F)
       (= a!1 S1)
       (= a!2 O)
       (not (= (and H1 G1) Q1))
       (not (= (and Y Z) Q2))
       (= R2 V)
       (= L2 Q)
       (= K2 S)
       (= J2 U)
       (= B1 K1)
       (= B1 F2)
       (= C1 I1)
       (= C1 H2)
       (= F1 J1)
       (= F1 G2)
       (= G1 J1)
       (= I1 (and H1 (not G1)))
       (= K1 (and (not D) (not F) (not H) Q))
       a!3
       (= W1 V1)
       (= Y1 X1)
       (= A2 Z1)
       (= I2 R1)
       (= I2 T1)
       (= V A)
       (= U T)
       (= S R)
       (= Q P)
       (= H G)
       (= F E)
       (= D C)
       (= O2 K)
       (= N2 M)
       (= M2 I)
       (= L1 D1)
       (= N1 M1)
       (= O1 E1)
       (= B2 L1)
       (= B2 P1)
       (= C2 M1)
       (= C2 U1)
       (= E2 O1)
       (= E2 D2)
       (= M B)
       (= K J)
       (= I P2)
       a!4
       a!5
       (or F1 (= N1 A1) (not B1))
       (or S (= X W) (not Q))
       (or (= M A1) (and C1 B1))
       (or (and C1 B1) (= I D1))
       (or (= N1 0) (and (not F1) B1))
       (or (= X 0) (and Q (not S)))
       a!6
       (or F1 (= K E1))
       (= (= B2 10) A2)))
      )
      (state R1
       I2
       G1
       H1
       Q1
       I1
       C1
       J1
       F1
       K1
       B1
       N1
       A1
       O1
       E2
       M1
       C2
       L1
       B2
       A2
       Y1
       W1
       T1
       H2
       G2
       F2
       D2
       U1
       P1
       Z1
       X1
       V1
       S1
       D1
       E1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Int) (X Int) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Bool) (I1 Bool) ) 
    (=>
      (and
        (state I1
       V
       Z
       Y
       H1
       A1
       U
       B1
       S
       C1
       Q
       X
       W
       F1
       K
       E1
       M
       D1
       I
       H
       F
       D
       A
       T
       R
       P
       J
       B
       G1
       G
       E
       C
       O
       L
       N)
        (not O)
      )
      false
    )
  )
)

(check-sat)
(exit)
