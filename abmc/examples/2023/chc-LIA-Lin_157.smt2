; ./prepared/vmt/./lustre/car_1_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Int Int Int Bool Bool Bool Bool Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Int) (X Int) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Bool) (I1 Bool) ) 
    (=>
      (and
        (let ((a!1 (= I1 (and H1 (not (<= 32767 G1))))))
  (and (= (<= 4 K) E)
       (= (<= 3 M) C)
       (= (or (not A) (<= 0 G1)) O)
       (not (= (and Z Y) H1))
       (= V A)
       (= U T)
       (= S R)
       (= G F)
       (= E D)
       (= C B)
       a!1
       (= I1 V)
       (= C1 Q)
       (= B1 S)
       (= A1 U)
       (= Q P)
       (= K J)
       (= M I)
       (= H G1)
       (= F1 0)
       (= F1 K)
       (= E1 0)
       (= E1 M)
       (= D1 0)
       (= D1 H)
       (or (= X W) (not Q) S)
       (or (= X 0) (and Q (not S)))
       (= C1 true)
       (not B1)
       (not A1)
       (= (= H 10) G)))
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
       H
       G
       E
       C
       A
       T
       R
       P
       J
       I
       G1
       F
       D
       B
       O
       L
       N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Int) (X Int) (Y Bool) (Z Bool) (A1 Int) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Bool) ) 
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
       H
       G
       E
       C
       A
       T
       R
       P
       J
       I
       P2
       F
       D
       B
       O
       L
       N)
        (let ((a!1 (= R1 (and V Q1 (not (<= 32767 P1)))))
      (a!2 (or (not C1) (not B1) (= (+ M (* (- 1) A1)) (- 1))))
      (a!3 (or (not C1) (not B1) (= (+ H (* (- 1) D1)) (- 1))))
      (a!4 (or (not F1) (= (+ K (* (- 1) E1)) (- 1)))))
  (and (= (= H 10) G)
       (= (<= 4 E2) X1)
       (= (<= 4 K) E)
       (= (<= 3 C2) V1)
       (= (<= 3 M) C)
       (= (or (not T1) (<= 0 P1)) S1)
       (= (or (not A) (<= 0 P2)) O)
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
       (= K1 (and (not C) (not E) (not G) Q))
       a!1
       (= V1 U1)
       (= X1 W1)
       (= Z1 Y1)
       (= I2 R1)
       (= I2 T1)
       (= V A)
       (= U T)
       (= S R)
       (= Q P)
       (= G F)
       (= E D)
       (= C B)
       (= O2 K)
       (= N2 M)
       (= M2 H)
       (= L1 D1)
       (= N1 M1)
       (= O1 E1)
       (= A2 L1)
       (= A2 P1)
       (= C2 M1)
       (= C2 B2)
       (= E2 O1)
       (= E2 D2)
       (= M I)
       (= K J)
       (= H P2)
       a!2
       a!3
       (or F1 (= N1 A1) (not B1))
       (or S (= X W) (not Q))
       (or (= M A1) (and C1 B1))
       (or (and C1 B1) (= H D1))
       (or (= N1 0) (and (not F1) B1))
       (or (= X 0) (and Q (not S)))
       a!4
       (or F1 (= K E1))
       (= (= A2 10) Z1)))
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
       A2
       Z1
       X1
       V1
       T1
       H2
       G2
       F2
       D2
       B2
       P1
       Y1
       W1
       U1
       S1
       D1
       E1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Int) (X Int) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Bool) (I1 Bool) ) 
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
       H
       G
       E
       C
       A
       T
       R
       P
       J
       I
       G1
       F
       D
       B
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
