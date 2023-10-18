; ./vmt/./lustre/car_6_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Int Int Int Bool Bool Bool Bool Bool Int Int ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Bool) ) 
    (=>
      (and
        (and (= (<= 4 K) D)
     (= (<= 3 M) B)
     (not (= (and A1 Z) I1))
     (= U T)
     (= S R)
     (= Q P)
     (= F E)
     (= D C)
     (= J1 I1)
     (= J1 W)
     (= E1 Q)
     (= D1 S)
     (= C1 O)
     (= B1 U)
     (= B A)
     (= W V)
     (= M I)
     (= K J)
     (= H G)
     (= H1 0)
     (= H1 K)
     (= G1 0)
     (= G1 M)
     (= F1 0)
     (= F1 H)
     (or (= Y X) (not Q) S)
     (or (= Y 0) (and Q (not S)))
     (= E1 true)
     (not D1)
     (= C1 true)
     (not B1)
     (= (= H 10) F))
      )
      (state J1
       W
       A1
       Z
       I1
       B1
       U
       D1
       S
       E1
       Q
       Y
       X
       H1
       K
       G1
       M
       F1
       H
       F
       D
       B
       V
       T
       R
       P
       J
       I
       G
       E
       C
       A
       C1
       O
       L
       N)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Int) (G1 Int) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Int) (Q2 Int) (R2 Int) (S2 Bool) (T2 Bool) ) 
    (=>
      (and
        (state T2
       W
       A1
       Z
       S2
       L2
       U
       N2
       S
       O2
       Q
       Y
       X
       R2
       K
       Q2
       M
       P2
       H
       F
       D
       B
       V
       T
       R
       P
       J
       I
       G
       E
       C
       A
       M2
       O
       L
       N)
        (let ((a!1 (or (not D1) (not C1) (= (+ M (* (- 1) F1)) (- 1))))
      (a!2 (or (not D1) (not C1) (= (+ H (* (- 1) B1)) (- 1))))
      (a!3 (or (not H1) (= (+ K (* (- 1) G1)) (- 1)))))
  (and (= (= H 10) F)
       (= (<= 4 F2) X1)
       (= (<= 4 K) D)
       (= (<= 3 D2) V1)
       (= (<= 3 M) B)
       (not (= (and J1 I1) R1))
       (not (= (and Z A1) S2))
       (= T2 W)
       (= O2 Q)
       (= N2 S)
       (= M2 O)
       (= L2 U)
       (= C1 M1)
       (= C1 G2)
       (= D1 K1)
       (= D1 I2)
       (= H1 L1)
       (= H1 H2)
       (= I1 L1)
       (= K1 (and J1 (not I1)))
       (= M1 (and (not B) (not D) (not F) Q))
       (= S1 (and W R1))
       (= T1 E1)
       (= V1 U1)
       (= X1 W1)
       (= Z1 Y1)
       (= K2 S1)
       (= K2 J2)
       (= W V)
       (= U T)
       (= S R)
       (= Q P)
       (= F E)
       (not (= E E1))
       (= D C)
       (= B A)
       (= R2 K)
       (= Q2 M)
       (= P2 H)
       (= N1 B1)
       (= P1 O1)
       (= Q1 G1)
       (= B2 N1)
       (= B2 A2)
       (= D2 O1)
       (= D2 C2)
       (= F2 Q1)
       (= F2 E2)
       (= M I)
       (= K J)
       (= H G)
       a!1
       a!2
       (or H1 (= P1 F1) (not C1))
       (or S (= Y X) (not Q))
       (or (and D1 C1) (= M F1))
       (or (= H B1) (and D1 C1))
       (or (= P1 0) (and (not H1) C1))
       (or (= Y 0) (and Q (not S)))
       a!3
       (or H1 (= K G1))
       (= (= B2 10) Z1)))
      )
      (state S1
       K2
       I1
       J1
       R1
       K1
       D1
       L1
       H1
       M1
       C1
       P1
       F1
       Q1
       F2
       O1
       D2
       N1
       B2
       Z1
       X1
       V1
       J2
       I2
       H2
       G2
       E2
       C2
       A2
       Y1
       W1
       U1
       E1
       T1
       B1
       G1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Bool) ) 
    (=>
      (and
        (state J1
       W
       A1
       Z
       I1
       B1
       U
       D1
       S
       E1
       Q
       Y
       X
       H1
       K
       G1
       M
       F1
       H
       F
       D
       B
       V
       T
       R
       P
       J
       I
       G
       E
       C
       A
       C1
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
