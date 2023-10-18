; ./vmt/./lustre/FIREFLY_rt_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Bool Int Bool Bool Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Int Int Int Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Bool) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Bool) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Bool) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Bool) (D2 Int) (E2 Bool) (F2 Int) (G2 Bool) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Int) (U2 Bool) (V2 Int) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Int) (A3 Int) ) 
    (=>
      (and
        (let ((a!1 (= (or (and (not N1)
                       (not J1)
                       (not D)
                       (not X2)
                       (not S)
                       (not U)
                       (not D1)
                       (not S1))
                  (and (not N1)
                       (not J1)
                       (not D)
                       (not X2)
                       (not S)
                       (not U)
                       (not D1)
                       S1)
                  (and (not N1)
                       (not J1)
                       (not D)
                       (not X2)
                       (not S)
                       (not U)
                       D1
                       (not S1))
                  (and (not N1)
                       (not J1)
                       (not D)
                       (not X2)
                       (not S)
                       U
                       (not D1)
                       (not S1))
                  (and (not N1)
                       (not J1)
                       (not D)
                       (not X2)
                       S
                       (not U)
                       (not D1)
                       (not S1))
                  (and (not N1)
                       (not J1)
                       (not D)
                       X2
                       (not S)
                       (not U)
                       (not D1)
                       (not S1))
                  (and (not N1)
                       (not J1)
                       D
                       (not X2)
                       (not S)
                       (not U)
                       (not D1)
                       (not S1))
                  (and (not N1)
                       J1
                       (not D)
                       (not X2)
                       (not S)
                       (not U)
                       (not D1)
                       (not S1))
                  (and N1
                       (not J1)
                       (not D)
                       (not X2)
                       (not S)
                       (not U)
                       (not D1)
                       (not S1)))
              U2))
      (a!2 (= (or (not Q2) (not (<= 2 S2))) X1)))
  (and a!1
       a!2
       (= (and P2 W1 X1) Z1)
       (= P Q2)
       (= R2 (and U2 (<= 0 J)))
       (= R2 P)
       (= P2 (<= 0 S2))
       (= L J2)
       (= T2 0)
       (= T2 O2)
       (= K J)
       (= K M)
       (= M L)
       (= N 0)
       (= N K2)
       (= O 0)
       (= O M2)
       (= J2 I2)
       (= K2 S2)
       (= M2 L2)
       (= O2 N2)
       (or (not S1) (= C1 T1))
       (or (not S1) (= I1 H))
       (or (= I1 C) S1)
       (or (= R1 C1) S1)
       (or (not D1) (= F2 F))
       (or D1 (= H1 B1))
       (or (not D1) (= T E1))
       (or (not D1) (= B1 G1))
       (or (= C1 T) D1)
       (or D1 (= F1 F2))
       (or (not U) (= R V))
       (or (= T R) U)
       (or (not U) (= X W))
       (or (= Y X) U)
       (or (not U) (= A1 Z))
       (or (= B1 A1) U)
       (or (= F2 D2) S)
       (or (not S) (= D2 B2))
       (or (= R Q) S)
       (or (not S) (= Q H2))
       (or (not G) (= H 1))
       (or (not E) (= F 0))
       (or (not X2) (= Z2 Y2))
       (or (not X2) (= W2 V2))
       (or (not X2) (= A A3))
       (or D (= Q1 A))
       (or (not D) (= Q1 V1))
       (or (not D) (= C B))
       (or (not D) (= R1 U1))
       (or D (= R1 Z2))
       (or (not I) (= V2 0))
       (or (not J1) (= Y K1))
       (or (not J1) (= F1 L1))
       (or J1 (= I1 Y))
       (or J1 (= M1 F1))
       (or N1 (= Q1 H1))
       (or (not N1) (= H1 P1))
       (or N1 (= M1 W2))
       (or (not N1) (= M1 O1))
       (= (<= 0 L2) W1)))
      )
      (state R2
       P
       U
       S
       D1
       J1
       N1
       S1
       D
       X2
       U2
       K
       M
       T2
       O2
       O
       M2
       N
       K2
       L
       J2
       L2
       W1
       S2
       Q2
       X1
       N2
       I2
       P2
       Z1
       Q1
       A
       V1
       R1
       U1
       Z2
       I1
       C
       H
       C1
       T1
       H1
       P1
       M1
       O1
       W2
       F1
       L1
       Y
       K1
       B1
       G1
       F2
       F
       T
       E1
       A1
       Z
       X
       W
       R
       V
       D2
       B2
       Q
       H2
       J
       V2
       I
       G
       E
       B
       A3
       Y2
       Y1
       A2
       C2
       E2
       G2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Bool) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Bool) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Bool) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Bool) (D2 Int) (E2 Bool) (F2 Int) (G2 Bool) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Int) (A3 Bool) (B3 Int) (C3 Bool) (D3 Int) (E3 Bool) (F3 Int) (G3 Bool) (H3 Int) (I3 Bool) (J3 Bool) (K3 Int) (L3 Int) (M3 Bool) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Bool) (I4 Bool) (J4 Int) (K4 Bool) (L4 Bool) (M4 Bool) (N4 Int) (O4 Bool) (P4 Int) (Q4 Int) (R4 Bool) (S4 Int) (T4 Int) (U4 Int) (V4 Bool) (W4 Int) (X4 Int) (Y4 Int) (Z4 Bool) (A5 Int) (B5 Bool) (C5 Int) (D5 Int) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Int) (U5 Int) (V5 Bool) (W5 Int) (X5 Int) (Y5 Bool) (Z5 Int) (A6 Int) (B6 Int) ) 
    (=>
      (and
        (state S5
       P
       U
       S
       D1
       J1
       N1
       S1
       D
       Y5
       V5
       K
       M
       U5
       O2
       O
       M2
       N
       K2
       L
       J2
       L2
       W1
       T5
       R5
       X1
       N2
       I2
       Q5
       Z1
       Q1
       A
       V1
       R1
       U1
       A6
       I1
       C
       H
       C1
       T1
       H1
       P1
       M1
       O1
       X5
       F1
       L1
       Y
       K1
       B1
       G1
       F2
       F
       T
       E1
       A1
       Z
       X
       W
       R
       V
       D2
       B2
       Q
       H2
       J
       W5
       I
       G
       E
       B
       B6
       Z5
       Y1
       A2
       C2
       E2
       G2)
        (let ((a!1 (= (or (and (not E5)
                       (not B5)
                       (not Z4)
                       (not V4)
                       (not R4)
                       (not O4)
                       (not X2)
                       (not Q2))
                  (and (not E5)
                       (not B5)
                       (not Z4)
                       (not V4)
                       (not R4)
                       (not O4)
                       (not X2)
                       Q2)
                  (and (not E5)
                       (not B5)
                       (not Z4)
                       (not V4)
                       (not R4)
                       (not O4)
                       X2
                       (not Q2))
                  (and (not E5)
                       (not B5)
                       (not Z4)
                       (not V4)
                       (not R4)
                       O4
                       (not X2)
                       (not Q2))
                  (and (not E5)
                       (not B5)
                       (not Z4)
                       (not V4)
                       R4
                       (not O4)
                       (not X2)
                       (not Q2))
                  (and (not E5)
                       (not B5)
                       (not Z4)
                       V4
                       (not R4)
                       (not O4)
                       (not X2)
                       (not Q2))
                  (and (not E5)
                       (not B5)
                       Z4
                       (not V4)
                       (not R4)
                       (not O4)
                       (not X2)
                       (not Q2))
                  (and (not E5)
                       B5
                       (not Z4)
                       (not V4)
                       (not R4)
                       (not O4)
                       (not X2)
                       (not Q2))
                  (and E5
                       (not B5)
                       (not Z4)
                       (not V4)
                       (not R4)
                       (not O4)
                       (not X2)
                       (not Q2)))
              H4))
      (a!2 (= (or (and (not D)
                       (not S)
                       (not U)
                       (not D1)
                       (not J1)
                       (not N1)
                       (not S1)
                       (not Y5))
                  (and (not D)
                       (not S)
                       (not U)
                       (not D1)
                       (not J1)
                       (not N1)
                       (not S1)
                       Y5)
                  (and (not D)
                       (not S)
                       (not U)
                       (not D1)
                       (not J1)
                       (not N1)
                       S1
                       (not Y5))
                  (and (not D)
                       (not S)
                       (not U)
                       (not D1)
                       (not J1)
                       N1
                       (not S1)
                       (not Y5))
                  (and (not D)
                       (not S)
                       (not U)
                       (not D1)
                       J1
                       (not N1)
                       (not S1)
                       (not Y5))
                  (and (not D)
                       (not S)
                       (not U)
                       D1
                       (not J1)
                       (not N1)
                       (not S1)
                       (not Y5))
                  (and (not D)
                       (not S)
                       U
                       (not D1)
                       (not J1)
                       (not N1)
                       (not S1)
                       (not Y5))
                  (and (not D)
                       S
                       (not U)
                       (not D1)
                       (not J1)
                       (not N1)
                       (not S1)
                       (not Y5))
                  (and D
                       (not S)
                       (not U)
                       (not D1)
                       (not J1)
                       (not N1)
                       (not S1)
                       (not Y5)))
              V5))
      (a!3 (= (or (not R5) (not (<= 2 T5))) X1))
      (a!4 (= (or (not L4) (not (<= 2 J4))) H5))
      (a!5 (and (<= 1 J2) (= K2 0) (= M2 0) (= O2 0)))
      (a!6 (= (and (<= 1 J2) (<= 1 (+ O2 M2))) E3))
      (a!7 (= J3 (and (<= 1 J2) (<= 1 (+ O2 M2)))))
      (a!8 (or (not A3) (= (+ M2 (* (- 1) O3)) (- 1))))
      (a!9 (or (not A3) (= (+ J2 (* (- 1) Z2)) 1)))
      (a!10 (or (not C3) (= (+ O2 (* (- 1) U3)) (- 2))))
      (a!11 (or (not C3) (= (+ K2 (* (- 1) K3)) 1)))
      (a!12 (or (not C3) (= (+ J2 (* (- 1) B3)) 1)))
      (a!13 (or (not E3) (= (+ O2 M2 (* (- 1) T3)) (- 1))))
      (a!14 (or (not E3) (= (+ J2 (* (- 1) D3)) 1)))
      (a!15 (or (not G3) (= (+ J2 (* (- 1) F3)) 1)))
      (a!16 (or (not I3) (= (+ O2 (* (- 1) W3)) (- 2))))
      (a!17 (or (not I3) (= (+ K2 (* (- 1) Y2)) 1)))
      (a!18 (or (not I3) (= (+ J2 (* (- 1) H3)) 1)))
      (a!19 (or (not J3) (= (+ O2 M2 (* (- 1) U2)) (- 1))))
      (a!20 (or (not J3) (= (+ J2 (* (- 1) R2)) 1)))
      (a!21 (or (not M3) (= (+ M2 (* (- 1) Q3)) 1)))
      (a!22 (or (not M3) (= (+ K2 (* (- 1) L3)) (- 1))))
      (a!23 (or (not S3) (= (+ M2 (* (- 1) R3)) (- 1)))))
  (and (= (<= 0 L5) G5)
       (= (<= 0 L2) W1)
       a!1
       a!2
       a!3
       a!4
       (= a!5 A3)
       (= (and H5 G5 K4) F5)
       (= (and W1 X1 Q5) Z1)
       a!6
       (= (and (<= 1 J2) (<= 1 K2)) C3)
       (= (and (<= 1 J2) (<= 1 K2)) I3)
       (= S5 P)
       (= Q5 (<= 0 T5))
       (= G3 a!5)
       a!7
       (= S3 (= O2 1))
       (= I4 (and P H4 (<= 0 G4)))
       (= K4 (<= 0 J4))
       (= M4 I4)
       (= M4 L4)
       (= P R5)
       (= U5 O2)
       (= Z3 Y3)
       (= B4 A4)
       (= D4 C4)
       (= F4 E4)
       (= J5 Z3)
       (= J5 I5)
       (= K5 B4)
       (= K5 J4)
       (= M5 D4)
       (= M5 L5)
       (= O5 F4)
       (= O5 N5)
       (= P5 X3)
       (= O2 N2)
       (= M2 L2)
       (= K2 T5)
       (= J2 I2)
       (= O M2)
       (= N K2)
       (= M X3)
       (= L J2)
       (= K M)
       (or (not Q2) (= P2 R2))
       (or (not Q2) (= T2 S2))
       (or (not Q2) (= V2 U2))
       (or Q2 (= O2 V2))
       (or Q2 (= M2 T2))
       (or Q2 (= J2 P2))
       (or X2 (= V2 C5))
       (or (not X2) (= W2 Y2))
       (or (not X2) (= H3 D5))
       (or (not X2) (= C5 W3))
       (or X2 (= D5 P2))
       (or X2 (= K2 W2))
       a!8
       a!9
       (or A3 (= M2 O3))
       (or A3 (= J2 Z2))
       a!10
       a!11
       a!12
       (or C3 (= O2 U3))
       (or C3 (= K2 K3))
       (or C3 (= J2 B3))
       a!13
       a!14
       (or (not E3) (= P3 0))
       (or E3 (= O2 T3))
       (or E3 (= M2 P3))
       (or E3 (= J2 D3))
       a!15
       (or (not G3) (= N3 1))
       (or G3 (= K2 N3))
       (or G3 (= J2 F3))
       a!16
       a!17
       a!18
       (or I3 (= O2 W3))
       (or I3 (= K2 Y2))
       (or I3 (= J2 H3))
       a!19
       a!20
       (or (not J3) (= S2 0))
       (or J3 (= O2 U2))
       (or J3 (= M2 S2))
       (or J3 (= J2 R2))
       a!21
       a!22
       (or M3 (= M2 Q3))
       (or M3 (= K2 L3))
       a!23
       (or (not S3) (= V3 0))
       (or S3 (= O2 V3))
       (or S3 (= M2 R3))
       (or (not O4) (= Z2 Y3))
       (or (not O4) (= C4 O3))
       (or O4 (= N4 Y3))
       (or O4 (= P4 C4))
       (or (not R4) (= B3 N4))
       (or (not R4) (= A4 K3))
       (or (not R4) (= E4 U3))
       (or R4 (= Q4 N4))
       (or R4 (= S4 A4))
       (or R4 (= T4 E4))
       (or (not V4) (= D3 Q4))
       (or (not V4) (= P4 P3))
       (or (not V4) (= T4 T3))
       (or V4 (= U4 Q4))
       (or V4 (= W4 P4))
       (or V4 (= X4 T4))
       (or (not Z4) (= L3 S4))
       (or (not Z4) (= W4 Q3))
       (or Z4 (= Y4 S4))
       (or Z4 (= A5 W4))
       (or (not B5) (= R3 A5))
       (or (not B5) (= X4 V3))
       (or B5 (= A5 T2))
       (or B5 (= C5 X4))
       (or E5 (= W2 Y4))
       (or (not E5) (= F3 U4))
       (or (not E5) (= Y4 N3))
       (or E5 (= D5 U4))
       (or S1 (= R1 C1))
       (or (not S1) (= I1 H))
       (or S1 (= I1 C))
       (or (not S1) (= C1 T1))
       (or N1 (= Q1 H1))
       (or N1 (= M1 X5))
       (or (not N1) (= M1 O1))
       (or (not N1) (= H1 P1))
       (or J1 (= M1 F1))
       (or J1 (= I1 Y))
       (or (not J1) (= F1 L1))
       (or (not J1) (= Y K1))
       (or (not D1) (= F2 F))
       (or D1 (= H1 B1))
       (or D1 (= F1 F2))
       (or D1 (= C1 T))
       (or (not D1) (= B1 G1))
       (or (not D1) (= T E1))
       (or U (= B1 A1))
       (or (not U) (= A1 Z))
       (or U (= Y X))
       (or (not U) (= X W))
       (or U (= T R))
       (or (not U) (= R V))
       (or S (= F2 D2))
       (or (not S) (= D2 B2))
       (or S (= R Q))
       (or (not S) (= Q H2))
       (or D (= R1 A6))
       (or (not D) (= R1 U1))
       (or (not D) (= Q1 V1))
       (or D (= Q1 A))
       (= (<= 1 M2) M3)))
      )
      (state I4
       M4
       R4
       O4
       V4
       Z4
       B5
       E5
       X2
       Q2
       H4
       X3
       P5
       F4
       O5
       D4
       M5
       B4
       K5
       Z3
       J5
       L5
       G5
       J4
       L4
       H5
       N5
       I5
       K4
       F5
       C5
       V2
       W3
       D5
       H3
       P2
       Y4
       W2
       N3
       U4
       F3
       X4
       V3
       A5
       R3
       T2
       W4
       Q3
       S4
       L3
       T4
       T3
       P4
       P3
       Q4
       D3
       E4
       U3
       A4
       K3
       N4
       B3
       C4
       O3
       Y3
       Z2
       G4
       S2
       J3
       G3
       E3
       Y2
       U2
       R2
       A3
       C3
       M3
       S3
       I3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Bool) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Bool) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Bool) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Bool) (D2 Int) (E2 Bool) (F2 Int) (G2 Bool) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Int) (U2 Bool) (V2 Int) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Int) (A3 Int) ) 
    (=>
      (and
        (state R2
       P
       U
       S
       D1
       J1
       N1
       S1
       D
       X2
       U2
       K
       M
       T2
       O2
       O
       M2
       N
       K2
       L
       J2
       L2
       W1
       S2
       Q2
       X1
       N2
       I2
       P2
       Z1
       Q1
       A
       V1
       R1
       U1
       Z2
       I1
       C
       H
       C1
       T1
       H1
       P1
       M1
       O1
       W2
       F1
       L1
       Y
       K1
       B1
       G1
       F2
       F
       T
       E1
       A1
       Z
       X
       W
       R
       V
       D2
       B2
       Q
       H2
       J
       V2
       I
       G
       E
       B
       A3
       Y2
       Y1
       A2
       C2
       E2
       G2)
        (not Z1)
      )
      false
    )
  )
)

(check-sat)
(exit)
