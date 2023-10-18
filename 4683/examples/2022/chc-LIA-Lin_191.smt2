; ./vmt/./lustre/DRAGON_1_e1_14612_e2_2653_e7_4370_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Int Int Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Bool) (O Int) (P Bool) (Q Int) (R Bool) (S Int) (T Bool) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Bool) (F1 Bool) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Bool) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Bool) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Bool) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Bool) (C3 Int) (D3 Bool) (E3 Int) (F3 Bool) (G3 Bool) (H3 Bool) (I3 Int) (J3 Bool) (K3 Int) (L3 Bool) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Bool) (R3 Int) (S3 Int) (T3 Int) (U3 Bool) (V3 Int) (W3 Int) (X3 Bool) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) ) 
    (=>
      (and
        (let ((a!1 (= F1 (and E1 (not (<= Z 0)))))
      (a!2 (= (or (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       U3)
                  (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       Q3
                       (not U3))
                  (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       G3
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       U1
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       I1
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       G
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       D
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       (not T2)
                       (not P1)
                       (not C4)
                       A
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       (not T2)
                       (not P1)
                       C4
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       (not T2)
                       P1
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and (not X3)
                       T2
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3))
                  (and X3
                       (not T2)
                       (not P1)
                       (not C4)
                       (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not U1)
                       (not G3)
                       (not Q3)
                       (not U3)))
              E1)))
  (and (= (or (not A2) (not Z1)) Y1)
       (= Z3 (<= 2 C2))
       (= Z3 N2)
       (= N2 A2)
       a!1
       (= F1 Z1)
       (= K2 K)
       (= K2 J2)
       (= G2 F2)
       (= J 0)
       (= L K)
       (= A1 Z)
       (= A1 L)
       (= B1 0)
       (= B1 C2)
       (= C1 0)
       (= C1 E2)
       (= D1 0)
       (= D1 G2)
       (= C2 B2)
       (= E2 D2)
       (= I2 H2)
       (= I2 J)
       (or (not U3) (= T3 V3))
       (or (not U3) (= P3 Q))
       (or (= P3 R1) U3)
       (or (= W3 T3) U3)
       (or (= T3 E3) Q3)
       (or (not Q3) (= E3 S3))
       (or (= K3 W1) Q3)
       (or (not Q3) (= K3 R3))
       (or (= P3 O3) G3)
       (or (= M3 Y2) G3)
       (or (not G3) (= M C3))
       (or (= S2 H1) G3)
       (or (not G3) (= S2 I3))
       (or (not G3) (= Y2 X2))
       (or (not G3) (= A3 O))
       (or (= E3 C3) G3)
       (or (= K3 A3) G3)
       (or (not G3) (= O3 N3))
       (or (not U1) (= M1 Y))
       (or (= M1 B4) U1)
       (or (not U1) (= G1 V1))
       (or (= N1 E4) U1)
       (or (not U1) (= N1 X1))
       (or (= S1 C) U1)
       (or (not U1) (= S1 V))
       (or (= T1 G1) U1)
       (or (= W1 F) U1)
       (or (not U1) (= W1 X))
       (or (= H1 G1) I1)
       (or (not I1) (= H1 J1))
       (or (= L1 M1) I1)
       (or (not I1) (= L1 K1))
       (or (not T) (= U 1))
       (or (not R) (= S 0))
       (or (not P) (= Q 0))
       (or (not N) (= O 0))
       (or (not N) (= M 0))
       (or (not G) (= F E))
       (or (not G) (= I H))
       (or (not D) (= C B))
       (or (= O2 I) D)
       (or (not D) (= O2 Q2))
       (or (not A) (= E4 D4))
       (or (not A) (= L2 P2))
       (or (= O2 L2) A)
       (or (not C4) (= B4 A4))
       (or (not C4) (= T1 M2))
       (or C4 (= L2 T1))
       (or (not W) (= Y 0))
       (or (not W) (= V 1))
       (or (not W) (= X 0))
       (or P1 (= O1 N1))
       (or (not P1) (= O1 Q1))
       (or (not P1) (= R1 U))
       (or P1 (= R1 S1))
       (or (not T2) (= W2 V2))
       (or (not T2) (= R2 U2))
       (or T2 (= S2 R2))
       (or T2 (= A3 W2))
       (or (not X3) (= M3 S))
       (or X3 (= M3 O1))
       (or (not X3) (= W3 Y3))
       (or X3 (= W3 L1))
       a!2))
      )
      (state F1
       Z1
       G3
       T2
       Q3
       U3
       X3
       P1
       I1
       U1
       C4
       A
       D
       G
       E1
       A1
       L
       Z3
       N2
       K2
       K
       I2
       J
       D1
       G2
       C1
       E2
       B1
       C2
       W3
       L1
       Y3
       M3
       S
       O1
       T3
       V3
       P3
       Q
       R1
       E3
       S3
       K3
       R3
       W1
       O3
       N3
       Y2
       X2
       A3
       O
       S2
       H1
       I3
       M
       C3
       W2
       V2
       R2
       U2
       O2
       Q2
       I
       L2
       P2
       A2
       T1
       M2
       J2
       H2
       F2
       D2
       B2
       Y1
       M1
       B4
       Y
       S1
       C
       V
       N1
       E4
       X1
       F
       X
       G1
       V1
       U
       Q1
       K1
       J1
       Z
       W
       T
       R
       P
       N
       H
       E
       B
       D4
       A4
       Z2
       B3
       D3
       F3
       H3
       J3
       L3)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Bool) (O Int) (P Bool) (Q Int) (R Bool) (S Int) (T Bool) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Bool) (F1 Bool) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Bool) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Bool) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Bool) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Bool) (C3 Int) (D3 Bool) (E3 Int) (F3 Bool) (G3 Bool) (H3 Bool) (I3 Int) (J3 Bool) (K3 Int) (L3 Bool) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Bool) (R3 Int) (S3 Int) (T3 Int) (U3 Bool) (V3 Int) (W3 Int) (X3 Bool) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Bool) (C4 Int) (D4 Int) (E4 Bool) (F4 Int) (G4 Int) (H4 Bool) (I4 Int) (J4 Int) (K4 Bool) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Bool) (S4 Int) (T4 Bool) (U4 Int) (V4 Bool) (W4 Int) (X4 Bool) (Y4 Int) (Z4 Bool) (A5 Int) (B5 Bool) (C5 Int) (D5 Bool) (E5 Bool) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Int) (K5 Bool) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Bool) (Q5 Int) (R5 Bool) (S5 Int) (T5 Int) (U5 Bool) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Bool) (M6 Bool) (N6 Int) (O6 Int) (P6 Bool) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Bool) (V6 Int) (W6 Int) (X6 Int) (Y6 Bool) (Z6 Int) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Bool) (P7 Int) (Q7 Int) (R7 Bool) (S7 Int) (T7 Int) (U7 Bool) (V7 Int) (W7 Int) (X7 Int) (Y7 Bool) (Z7 Int) (A8 Bool) (B8 Int) (C8 Bool) (D8 Bool) (E8 Int) (F8 Int) (G8 Int) (H8 Bool) (I8 Int) (J8 Int) ) 
    (=>
      (and
        (state F1
       Z1
       G3
       T2
       Q3
       U3
       X3
       P1
       I1
       U1
       H8
       A
       D
       G
       E1
       A1
       L
       Z3
       N2
       K2
       K
       I2
       J
       D1
       G2
       C1
       E2
       B1
       C2
       W3
       L1
       Y3
       M3
       S
       O1
       T3
       V3
       P3
       Q
       R1
       E3
       S3
       K3
       R3
       W1
       O3
       N3
       Y2
       X2
       A3
       O
       S2
       H1
       I3
       M
       C3
       W2
       V2
       R2
       U2
       O2
       Q2
       I
       L2
       P2
       A2
       T1
       M2
       J2
       H2
       F2
       D2
       B2
       Y1
       M1
       G8
       Y
       S1
       C
       V
       N1
       J8
       X1
       F
       X
       G1
       V1
       U
       Q1
       K1
       J1
       Z
       W
       T
       R
       P
       N
       H
       E
       B
       I8
       F8
       Z2
       B3
       D3
       F3
       H3
       J3
       L3)
        (let ((a!1 (= (or (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4))
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       B4)
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       E4
                       (not B4))
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       H4
                       (not E4)
                       (not B4))
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       K4
                       (not H4)
                       (not E4)
                       (not B4))
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       P6
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4))
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       U6
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4))
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       Y6
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4))
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       (not U7)
                       R7
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4))
                  (and (not C8)
                       (not A8)
                       (not Y7)
                       U7
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4))
                  (and (not C8)
                       (not A8)
                       Y7
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4))
                  (and (not C8)
                       A8
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4))
                  (and C8
                       (not A8)
                       (not Y7)
                       (not U7)
                       (not R7)
                       (not Y6)
                       (not U6)
                       (not P6)
                       (not K4)
                       (not H4)
                       (not E4)
                       (not B4)))
              L6))
      (a!2 (= (or (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8))
                  (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       H8)
                  (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       X3
                       (not H8))
                  (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       U3
                       (not X3)
                       (not H8))
                  (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       Q3
                       (not U3)
                       (not X3)
                       (not H8))
                  (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       G3
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8))
                  (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       T2
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8))
                  (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       U1
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8))
                  (and (not A)
                       (not D)
                       (not G)
                       (not I1)
                       P1
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8))
                  (and (not A)
                       (not D)
                       (not G)
                       I1
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8))
                  (and (not A)
                       (not D)
                       G
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8))
                  (and (not A)
                       D
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8))
                  (and A
                       (not D)
                       (not G)
                       (not I1)
                       (not P1)
                       (not U1)
                       (not T2)
                       (not G3)
                       (not Q3)
                       (not U3)
                       (not X3)
                       (not H8)))
              E1))
      (a!3 (and (<= 1 K2) (= C2 0) (= E2 0) (= G2 0) (= I2 0)))
      (a!4 (and (<= 1 K2) (<= 1 (+ I2 G2 E2 C2))))
      (a!5 (or Z1 (and L6 (not (<= K6 0)))))
      (a!6 (or (not R4) (= (+ K2 (* (- 1) Q4)) 1)))
      (a!7 (or (not R4) (= (+ C2 (* (- 1) H5)) (- 1))))
      (a!8 (or (not T4) (= (+ I2 G2 (* (- 1) S5)) 0)))
      (a!9 (or (not T4) (= (+ E2 C2 (* (- 1) M5)) (- 1))))
      (a!10 (or (not T4) (= (+ K2 (* (- 1) S4)) 1)))
      (a!11 (or (not V4) (= (+ K2 (* (- 1) U4)) 1)))
      (a!12 (or (not V4) (= (+ I2 (* (- 1) B6)) (- 1))))
      (a!13 (or (not X4) (= (+ I2 G2 E2 C2 (* (- 1) N5)) 0)))
      (a!14 (or (not X4) (= (+ K2 (* (- 1) W4)) 1)))
      (a!15 (or (not Z4) (= (+ K2 (* (- 1) Y4)) (- 1))))
      (a!16 (or (not Z4) (= (+ I2 (* (- 1) C4)) 1)))
      (a!17 (or (not B5) (= (+ K2 (* (- 1) A5)) (- 1))))
      (a!18 (or (not B5) (= (+ E2 (* (- 1) F4)) 1)))
      (a!19 (or (not D5) (= (+ K2 (* (- 1) C5)) (- 1))))
      (a!20 (or (not D5) (= (+ G2 (* (- 1) I4)) 1)))
      (a!21 (or (not E5) (= (+ K2 (* (- 1) L4)) (- 1))))
      (a!22 (or (not E5) (= (+ C2 (* (- 1) M4)) 1)))
      (a!23 (or (not K5) (= (+ I2 (* (- 1) X5)) (- 1))))
      (a!24 (or (not K5) (= (+ C2 (* (- 1) J5)) 1)))
      (a!25 (or (not P5) (= (+ I2 (* (- 1) A6)) (- 1))))
      (a!26 (or (not R5) (= (+ G2 E2 (* (- 1) Q5)) 1)))
      (a!27 (or (not U5) (= (+ I2 (* (- 1) Z5)) (- 1)))))
  (and (= (<= 1 G2) D5)
       (= (<= 1 E2) B5)
       (= (<= 1 C2) E5)
       (= (<= 1 C2) K5)
       a!1
       a!2
       (= (or (not C7) (not B7)) A7)
       (= (or (not Z1) (not A2)) Y1)
       (= a!3 R4)
       (= a!3 V4)
       (= a!4 T4)
       (= a!4 X4)
       (= P5 (and (= E2 1) (= G2 0)))
       (= R5 (<= 2 (+ G2 E2)))
       (= U5 (and (= E2 0) (= G2 1)))
       (= M6 a!5)
       (= B7 M6)
       (= O7 C7)
       (= O7 D8)
       (= D8 (<= 2 E7))
       (= Z3 (<= 2 C2))
       (= Z3 N2)
       (= N2 A2)
       (= F1 Z1)
       (= P4 O4)
       (= P4 K7)
       (= G5 F5)
       (= G5 M7)
       (= F6 E6)
       (= H6 G6)
       (= J6 I6)
       (= E7 F6)
       (= E7 D7)
       (= G7 H6)
       (= G7 F7)
       (= I7 J6)
       (= I7 H7)
       (= K7 J7)
       (= M7 L7)
       (= E8 D6)
       (= K2 J2)
       (= K2 K)
       (= I2 H2)
       (= I2 J)
       (= G2 F2)
       (= E2 D2)
       (= C2 B2)
       (= D1 G2)
       (= C1 E2)
       (= B1 C2)
       (= A1 L)
       (= L D6)
       (or H8 (= L2 T1))
       (or (not H8) (= T1 M2))
       (or (not B4) (= A4 C4))
       (or (not B4) (= Y4 X6))
       (or B4 (= N7 X6))
       (or B4 (= I2 A4))
       (or (not E4) (= D4 F4))
       (or (not E4) (= A5 N7))
       (or E4 (= P7 N7))
       (or E4 (= E2 D4))
       (or (not H4) (= G4 I4))
       (or (not H4) (= C5 P7))
       (or H4 (= P7 J4))
       (or H4 (= G2 G4))
       (or (not K4) (= J4 L4))
       (or (not K4) (= N4 M4))
       (or K4 (= K2 J4))
       (or K4 (= C2 N4))
       a!6
       a!7
       (or R4 (= K2 Q4))
       (or R4 (= C2 H5))
       a!8
       a!9
       a!10
       (or (not T4) (= I5 0))
       (or (not T4) (= Y5 0))
       (or T4 (= K2 S4))
       (or T4 (= I2 Y5))
       (or T4 (= G2 S5))
       (or T4 (= E2 M5))
       (or T4 (= C2 I5))
       a!11
       a!12
       (or V4 (= K2 U4))
       (or V4 (= I2 B6))
       a!13
       a!14
       (or (not X4) (= L5 0))
       (or (not X4) (= W5 1))
       (or (not X4) (= C6 0))
       (or X4 (= K2 W4))
       (or X4 (= I2 C6))
       (or X4 (= G2 W5))
       (or X4 (= E2 N5))
       (or X4 (= C2 L5))
       a!15
       a!16
       (or Z4 (= K2 Y4))
       (or Z4 (= I2 C4))
       a!17
       a!18
       (or B5 (= K2 A5))
       (or B5 (= E2 F4))
       a!19
       a!20
       (or D5 (= K2 C5))
       (or D5 (= G2 I4))
       a!21
       a!22
       (or E5 (= K2 L4))
       (or E5 (= C2 M4))
       a!23
       a!24
       (or K5 (= I2 X5))
       (or K5 (= C2 J5))
       a!25
       (or (not P5) (= O5 0))
       (or P5 (= I2 A6))
       (or P5 (= E2 O5))
       a!26
       (or (not R5) (= V5 1))
       (or R5 (= G2 V5))
       (or R5 (= E2 Q5))
       a!27
       (or (not U5) (= T5 0))
       (or U5 (= I2 Z5))
       (or U5 (= G2 T5))
       (or (not P6) (= O6 U4))
       (or P6 (= O6 N6))
       (or (not P6) (= Q6 B6))
       (or P6 (= Q6 R6))
       (or (not U6) (= T6 Q5))
       (or U6 (= T6 S6))
       (or (not U6) (= V6 V5))
       (or U6 (= V6 W6))
       (or Y6 (= A4 R6))
       (or Y6 (= D4 S6))
       (or Y6 (= G4 W6))
       (or (not Y6) (= W4 N6))
       (or (not Y6) (= R6 C6))
       (or (not Y6) (= S6 N5))
       (or (not Y6) (= W6 W5))
       (or Y6 (= X6 N6))
       (or Y6 (= Z6 N4))
       (or (not Y6) (= Z6 L5))
       (or (not R7) (= Q4 F5))
       (or (not R7) (= E6 H5))
       (or R7 (= Q7 F5))
       (or R7 (= S7 E6))
       (or (not U7) (= O4 Y5))
       (or (not U7) (= G6 M5))
       (or (not U7) (= I6 S5))
       (or U7 (= O6 Q7))
       (or (not U7) (= Q7 S4))
       (or (not U7) (= S7 I5))
       (or U7 (= T7 O4))
       (or U7 (= V7 S7))
       (or U7 (= W7 G6))
       (or U7 (= X7 I6))
       (or (not Y7) (= J5 V7))
       (or (not Y7) (= T7 X5))
       (or Y7 (= V7 Z6))
       (or Y7 (= Z7 T7))
       (or (not A8) (= T5 X7))
       (or A8 (= X7 V6))
       (or (not A8) (= Z7 Z5))
       (or A8 (= B8 Z7))
       (or (not C8) (= O5 W7))
       (or C8 (= Q6 B8))
       (or C8 (= W7 T6))
       (or (not C8) (= B8 A6))
       (or (not X3) (= W3 Y3))
       (or X3 (= W3 L1))
       (or X3 (= M3 O1))
       (or (not X3) (= M3 S))
       (or U3 (= W3 T3))
       (or (not U3) (= T3 V3))
       (or U3 (= P3 R1))
       (or (not U3) (= P3 Q))
       (or Q3 (= T3 E3))
       (or (not Q3) (= K3 R3))
       (or Q3 (= K3 W1))
       (or (not Q3) (= E3 S3))
       (or G3 (= P3 O3))
       (or (not G3) (= O3 N3))
       (or G3 (= M3 Y2))
       (or G3 (= K3 A3))
       (or G3 (= E3 C3))
       (or (not G3) (= A3 O))
       (or (not G3) (= Y2 X2))
       (or (not G3) (= S2 I3))
       (or G3 (= S2 H1))
       (or (not G3) (= M C3))
       (or T2 (= A3 W2))
       (or (not T2) (= W2 V2))
       (or T2 (= S2 R2))
       (or (not T2) (= R2 U2))
       (or (not U1) (= W1 X))
       (or U1 (= W1 F))
       (or U1 (= T1 G1))
       (or (not U1) (= S1 V))
       (or U1 (= S1 C))
       (or U1 (= N1 J8))
       (or (not U1) (= N1 X1))
       (or U1 (= M1 G8))
       (or (not U1) (= M1 Y))
       (or (not U1) (= G1 V1))
       (or P1 (= R1 S1))
       (or (not P1) (= R1 U))
       (or (not P1) (= O1 Q1))
       (or P1 (= O1 N1))
       (or I1 (= L1 M1))
       (or (not I1) (= L1 K1))
       (or (not I1) (= H1 J1))
       (or I1 (= H1 G1))
       (or (not D) (= O2 Q2))
       (or D (= O2 I))
       (or A (= O2 L2))
       (or (not A) (= L2 P2))
       (= (<= 1 I2) Z4)))
      )
      (state M6
       B7
       U7
       R7
       Y7
       A8
       C8
       U6
       P6
       Y6
       B4
       E4
       H4
       K4
       L6
       D6
       E8
       D8
       O7
       M7
       G5
       K7
       P4
       J6
       I7
       H6
       G7
       F6
       E7
       B8
       Q6
       A6
       W7
       O5
       T6
       Z7
       Z5
       X7
       T5
       V6
       T7
       X5
       V7
       J5
       Z6
       I6
       S5
       G6
       M5
       S7
       I5
       Q7
       O6
       S4
       Y5
       O4
       E6
       H5
       F5
       Q4
       P7
       C5
       J4
       N7
       A5
       C7
       X6
       Y4
       L7
       J7
       H7
       F7
       D7
       A7
       R6
       A4
       C6
       W6
       G4
       W5
       S6
       D4
       N5
       N4
       L5
       N6
       W4
       V5
       Q5
       B6
       U4
       K6
       X4
       R5
       P5
       U5
       T4
       L4
       M4
       I4
       F4
       C4
       R4
       K5
       V4
       Z4
       B5
       D5
       E5)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Bool) (O Int) (P Bool) (Q Int) (R Bool) (S Int) (T Bool) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Bool) (F1 Bool) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Bool) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Bool) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Bool) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Bool) (C3 Int) (D3 Bool) (E3 Int) (F3 Bool) (G3 Bool) (H3 Bool) (I3 Int) (J3 Bool) (K3 Int) (L3 Bool) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Bool) (R3 Int) (S3 Int) (T3 Int) (U3 Bool) (V3 Int) (W3 Int) (X3 Bool) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) ) 
    (=>
      (and
        (state F1
       Z1
       G3
       T2
       Q3
       U3
       X3
       P1
       I1
       U1
       C4
       A
       D
       G
       E1
       A1
       L
       Z3
       N2
       K2
       K
       I2
       J
       D1
       G2
       C1
       E2
       B1
       C2
       W3
       L1
       Y3
       M3
       S
       O1
       T3
       V3
       P3
       Q
       R1
       E3
       S3
       K3
       R3
       W1
       O3
       N3
       Y2
       X2
       A3
       O
       S2
       H1
       I3
       M
       C3
       W2
       V2
       R2
       U2
       O2
       Q2
       I
       L2
       P2
       A2
       T1
       M2
       J2
       H2
       F2
       D2
       B2
       Y1
       M1
       B4
       Y
       S1
       C
       V
       N1
       E4
       X1
       F
       X
       G1
       V1
       U
       Q1
       K1
       J1
       Z
       W
       T
       R
       P
       N
       H
       E
       B
       D4
       A4
       Z2
       B3
       D3
       F3
       H3
       J3
       L3)
        (not Y1)
      )
      false
    )
  )
)

(check-sat)
(exit)
