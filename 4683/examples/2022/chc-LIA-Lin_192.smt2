; ./vmt/./lustre/ticket3i_1_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Int Bool Bool Bool Int Bool Bool Bool Int Bool Bool Bool Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Bool) (M Int) (N Bool) (O Int) (P Bool) (Q Bool) (R Int) (S Bool) (T Int) (U Bool) (V Bool) (W Int) (X Bool) (Y Int) (Z Bool) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Bool) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Bool) (G3 Int) (H3 Bool) (I3 Int) (J3 Int) (K3 Bool) ) 
    (=>
      (and
        (let ((a!1 (or Z2 (and (not (<= 3 X1)) (not (<= 3 T1)) (not (<= 3 G2)))))
      (a!2 (= (or (and (not V1)
                       (not F3)
                       (not H3)
                       (not K3)
                       (not C)
                       (not F)
                       (not I)
                       (not P2)
                       (not W2))
                  (and (not V1)
                       (not F3)
                       (not H3)
                       (not K3)
                       (not C)
                       (not F)
                       (not I)
                       (not P2)
                       W2)
                  (and (not V1)
                       (not F3)
                       (not H3)
                       (not K3)
                       (not C)
                       (not F)
                       (not I)
                       P2
                       (not W2))
                  (and (not V1)
                       (not F3)
                       (not H3)
                       (not K3)
                       (not C)
                       (not F)
                       I
                       (not P2)
                       (not W2))
                  (and (not V1)
                       (not F3)
                       (not H3)
                       (not K3)
                       (not C)
                       F
                       (not I)
                       (not P2)
                       (not W2))
                  (and (not V1)
                       (not F3)
                       (not H3)
                       (not K3)
                       C
                       (not F)
                       (not I)
                       (not P2)
                       (not W2))
                  (and (not V1)
                       (not F3)
                       (not H3)
                       K3
                       (not C)
                       (not F)
                       (not I)
                       (not P2)
                       (not W2))
                  (and (not V1)
                       (not F3)
                       H3
                       (not K3)
                       (not C)
                       (not F)
                       (not I)
                       (not P2)
                       (not W2))
                  (and (not V1)
                       F3
                       (not H3)
                       (not K3)
                       (not C)
                       (not F)
                       (not I)
                       (not P2)
                       (not W2))
                  (and V1
                       (not F3)
                       (not H3)
                       (not K3)
                       (not C)
                       (not F)
                       (not I)
                       (not P2)
                       (not W2)))
              N1)))
  (and (= (or (not R1) (not Q1)) P1)
       (= J2 R1)
       (= O1 (and N1 (<= 0 L1) (<= 0 J1) (<= 0 H1) (<= 0 D1)))
       (= O1 Q1)
       (= Z2 J2)
       (= G2 W1)
       (= C2 B2)
       (= A2 Z1)
       (= A1 0)
       (= A1 T1)
       (= B1 0)
       (= B1 G2)
       (= C1 0)
       (= C1 X1)
       (= E1 D1)
       (= E1 F1)
       (= F1 Y1)
       (= G1 A2)
       (= G1 F1)
       (= I1 C2)
       (= I1 H1)
       (= K1 J1)
       (= K1 E2)
       (= M1 L1)
       (= M1 H2)
       (= T1 S1)
       (= X1 I2)
       (= E2 D2)
       (= H2 F2)
       (or (not Z2) (<= 3 T1) (<= 3 G2) (<= 3 X1))
       (or (not W2) (= U2 T))
       (or (= U2 E) W2)
       (or (not P2) (= L2 O))
       (or (= L2 J3) P2)
       (or (not X) (= Y 2))
       (or (not V) (= W 1))
       (or (not S) (= T 2))
       (or (not Q) (= R 1))
       (or (not N) (= O 2))
       (or (not L) (= M 1))
       (or (not I) (= Y2 W))
       (or (= Y2 U1) I)
       (or (not I) (= H G))
       (or (not I) (= K J))
       (or (not F) (= E D))
       (or (= R2 E3) F)
       (or (not F) (= R2 X2))
       (or (not C) (= B A))
       (or (not C) (= O2 V2))
       (or (= O2 K) C)
       (or (not C) (= T2 R))
       (or (= U2 T2) C)
       (or (not K3) (= J3 I3))
       (or (not K3) (= Q2 S2))
       (or K3 (= R2 Q2))
       (or (not H3) (= B3 A3))
       (or (not H3) (= K2 M))
       (or H3 (= L2 K2))
       (or (not H3) (= N2 M2))
       (or H3 (= O2 N2))
       (or (not F3) (= E3 G3))
       (or (not F3) (= D3 C3))
       (or (not P) (= I3 0))
       (or (not U) (= D 0))
       (or (not Z) (= C3 0))
       (or (not V1) (= U1 Y))
       (or V1 (= U1 D3))
       a!1
       a!2))
      )
      (state O1
       Q1
       P2
       H3
       K3
       C
       W2
       F
       I
       V1
       F3
       N1
       Z2
       J2
       M1
       H2
       K1
       E2
       I1
       C2
       G1
       A2
       E1
       F1
       C1
       X1
       B1
       G2
       A1
       T1
       Y2
       W
       U1
       R2
       X2
       E3
       U2
       T
       E
       O2
       K
       V2
       T2
       R
       Q2
       S2
       L2
       O
       J3
       N2
       M2
       K2
       M
       R1
       F2
       D2
       B2
       Z1
       Y1
       I2
       W1
       Y
       D3
       S1
       P1
       D1
       L1
       J1
       H1
       C3
       Z
       X
       V
       D
       U
       S
       Q
       I3
       P
       N
       L
       J
       H
       G
       B
       A
       B3
       A3
       G3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Bool) (M Int) (N Bool) (O Int) (P Bool) (Q Bool) (R Int) (S Bool) (T Int) (U Bool) (V Bool) (W Int) (X Bool) (Y Int) (Z Bool) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Bool) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Bool) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Bool) (H3 Int) (I3 Int) (J3 Bool) (K3 Int) (L3 Int) (M3 Bool) (N3 Int) (O3 Int) (P3 Bool) (Q3 Int) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Bool) (Y3 Int) (Z3 Bool) (A4 Bool) (B4 Int) (C4 Bool) (D4 Int) (E4 Bool) (F4 Bool) (G4 Int) (H4 Bool) (I4 Int) (J4 Bool) (K4 Bool) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Int) (F5 Int) (G5 Bool) (H5 Int) (I5 Int) (J5 Int) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Int) (P5 Int) (Q5 Int) (R5 Bool) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Bool) (E6 Int) (F6 Int) (G6 Bool) (H6 Int) (I6 Int) (J6 Bool) (K6 Bool) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Bool) (R6 Int) (S6 Bool) (T6 Int) (U6 Int) (V6 Bool) ) 
    (=>
      (and
        (state O1
       Q1
       P2
       S6
       V6
       C
       W2
       F
       I
       V1
       Q6
       N1
       Z2
       J2
       M1
       H2
       K1
       E2
       I1
       C2
       G1
       A2
       E1
       F1
       C1
       X1
       B1
       G2
       A1
       T1
       Y2
       W
       U1
       R2
       X2
       P6
       U2
       T
       E
       O2
       K
       V2
       T2
       R
       Q2
       S2
       L2
       O
       U6
       N2
       M2
       K2
       M
       R1
       F2
       D2
       B2
       Z1
       Y1
       I2
       W1
       Y
       O6
       S1
       P1
       D1
       L1
       J1
       H1
       N6
       Z
       X
       V
       D
       U
       S
       Q
       T6
       P
       N
       L
       J
       H
       G
       B
       A
       M6
       L6
       R6)
        (let ((a!1 (= (or (and (not J6)
                       (not G6)
                       (not R5)
                       (not S3)
                       (not P3)
                       (not M3)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not J6)
                       (not G6)
                       (not R5)
                       (not S3)
                       (not P3)
                       (not M3)
                       (not J3)
                       (not G3)
                       B3)
                  (and (not J6)
                       (not G6)
                       (not R5)
                       (not S3)
                       (not P3)
                       (not M3)
                       (not J3)
                       G3
                       (not B3))
                  (and (not J6)
                       (not G6)
                       (not R5)
                       (not S3)
                       (not P3)
                       (not M3)
                       J3
                       (not G3)
                       (not B3))
                  (and (not J6)
                       (not G6)
                       (not R5)
                       (not S3)
                       (not P3)
                       M3
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not J6)
                       (not G6)
                       (not R5)
                       (not S3)
                       P3
                       (not M3)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not J6)
                       (not G6)
                       (not R5)
                       S3
                       (not P3)
                       (not M3)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not J6)
                       (not G6)
                       R5
                       (not S3)
                       (not P3)
                       (not M3)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not J6)
                       G6
                       (not R5)
                       (not S3)
                       (not P3)
                       (not M3)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and J6
                       (not G6)
                       (not R5)
                       (not S3)
                       (not P3)
                       (not M3)
                       (not J3)
                       (not G3)
                       (not B3)))
              G5))
      (a!2 (= (or (and (not C)
                       (not F)
                       (not I)
                       (not V1)
                       (not P2)
                       (not W2)
                       (not Q6)
                       (not S6)
                       (not V6))
                  (and (not C)
                       (not F)
                       (not I)
                       (not V1)
                       (not P2)
                       (not W2)
                       (not Q6)
                       (not S6)
                       V6)
                  (and (not C)
                       (not F)
                       (not I)
                       (not V1)
                       (not P2)
                       (not W2)
                       (not Q6)
                       S6
                       (not V6))
                  (and (not C)
                       (not F)
                       (not I)
                       (not V1)
                       (not P2)
                       (not W2)
                       Q6
                       (not S6)
                       (not V6))
                  (and (not C)
                       (not F)
                       (not I)
                       (not V1)
                       (not P2)
                       W2
                       (not Q6)
                       (not S6)
                       (not V6))
                  (and (not C)
                       (not F)
                       (not I)
                       (not V1)
                       P2
                       (not W2)
                       (not Q6)
                       (not S6)
                       (not V6))
                  (and (not C)
                       (not F)
                       (not I)
                       V1
                       (not P2)
                       (not W2)
                       (not Q6)
                       (not S6)
                       (not V6))
                  (and (not C)
                       (not F)
                       I
                       (not V1)
                       (not P2)
                       (not W2)
                       (not Q6)
                       (not S6)
                       (not V6))
                  (and (not C)
                       F
                       (not I)
                       (not V1)
                       (not P2)
                       (not W2)
                       (not Q6)
                       (not S6)
                       (not V6))
                  (and C
                       (not F)
                       (not I)
                       (not V1)
                       (not P2)
                       (not W2)
                       (not Q6)
                       (not S6)
                       (not V6)))
              N1))
      (a!3 (or (not Z3) (= (+ F1 (* (- 1) L4)) (- 1))))
      (a!4 (or (not A4) (= (+ A2 (* (- 1) N4)) (- 1))))
      (a!5 (or (not E4) (= (+ F1 (* (- 1) M4)) (- 1))))
      (a!6 (or (not F4) (= (+ A2 (* (- 1) O4)) (- 1))))
      (a!7 (or (not J4) (= (+ F1 (* (- 1) T3)) (- 1))))
      (a!8 (or (not K4) (= (+ A2 (* (- 1) D3)) (- 1))))
      (a!9 (or K6 (and (not (<= 3 V5)) (not (<= 3 T5)) (not (<= 3 P5)))))
      (a!10 (or Z2 (and (not (<= 3 T1)) (not (<= 3 X1)) (not (<= 3 G2))))))
  (and (= (= X1 2) K4)
       (= (= T1 2) A4)
       a!1
       a!2
       (= (or (not N5) (not M5)) L5)
       (= (or (not Q1) (not R1)) P1)
       (= X3 (and (<= P4 A2) (= T1 1)))
       (= Z3 (= T1 0))
       (= C4 (and (<= Q4 A2) (= G2 1)))
       (= E4 (= G2 0))
       (= H4 (and (<= R4 A2) (= X1 1)))
       (= J4 (= X1 0))
       (= K5 (and Q1 G5 (<= 0 J5) (<= 0 I5) (<= 0 H5) (<= 0 F5)))
       (= M5 K5)
       (= D6 N5)
       (= D6 K6)
       (= Z2 J2)
       (= J2 R1)
       (= O1 Q1)
       (= P4 C5)
       (= P4 A6)
       (= Q4 D5)
       (= Q4 B6)
       (= R4 E5)
       (= R4 C6)
       (= T4 S4)
       (= V4 U4)
       (= X4 W4)
       (= Z4 Y4)
       (= B5 A5)
       (= C5 F3)
       (= D5 L3)
       (= E5 V3)
       (= P5 T4)
       (= P5 O5)
       (= T5 V4)
       (= T5 S5)
       (= V5 X4)
       (= V5 U5)
       (= X5 Z4)
       (= X5 W5)
       (= Z5 B5)
       (= Z5 Y5)
       (= H2 F2)
       (= G2 W1)
       (= E2 D2)
       (= C2 B2)
       (= A2 Z1)
       (= X1 I2)
       (= T1 S1)
       (= M1 H2)
       (= K1 E2)
       (= I1 C2)
       (= G1 A2)
       (= F1 Y1)
       (= E1 F1)
       (= C1 X1)
       (= B1 G2)
       (= A1 T1)
       (or (not K6) (<= 3 V5) (<= 3 T5) (<= 3 P5))
       (or (not Z2) (<= 3 T1) (<= 3 G2) (<= 3 X1))
       (or V6 (= R2 Q2))
       (or (not V6) (= Q2 S2))
       (or S6 (= O2 N2))
       (or (not S6) (= N2 M2))
       (or S6 (= L2 K2))
       (or (not S6) (= K2 M))
       (or (not B3) (= A3 C3))
       (or (not B3) (= E3 D3))
       (or B3 (= A2 E3))
       (or B3 (= X1 A3))
       (or (not G3) (= F3 H3))
       (or (not G3) (= Y3 S4))
       (or (not G3) (= Y4 L4))
       (or G3 (= E6 S4))
       (or G3 (= F6 Y4))
       (or G3 (= C2 F3))
       (or (not J3) (= I3 K3))
       (or (not J3) (= N4 A5))
       (or J3 (= H6 A5))
       (or J3 (= T1 I3))
       (or (not M3) (= L3 N3))
       (or M3 (= R3 F6))
       (or (not M3) (= D4 U4))
       (or (not M3) (= F6 M4))
       (or M3 (= I6 U4))
       (or M3 (= E2 L3))
       (or (not P3) (= O3 Q3))
       (or (not P3) (= O4 H6))
       (or P3 (= H6 E3))
       (or P3 (= G2 O3))
       (or (not S3) (= R3 T3))
       (or (not S3) (= V3 U3))
       (or (not S3) (= I4 W4))
       (or S3 (= W4 Q5))
       (or S3 (= H2 V3))
       (or S3 (= F1 R3))
       (or (not X3) (= W3 2))
       (or X3 (= T1 W3))
       a!3
       (or (not Z3) (= Y3 1))
       (or Z3 (= C2 H3))
       (or Z3 (= T1 Y3))
       (or (not Z3) (= F1 H3))
       (or Z3 (= F1 L4))
       a!4
       (or (not A4) (= K3 0))
       (or A4 (= A2 N4))
       (or A4 (= T1 K3))
       (or (not C4) (= B4 2))
       (or C4 (= G2 B4))
       a!5
       (or (not E4) (= D4 1))
       (or E4 (= G2 D4))
       (or E4 (= E2 N3))
       (or (not E4) (= F1 N3))
       (or E4 (= F1 M4))
       a!6
       (or (not F4) (= Q3 0))
       (or F4 (= G2 Q3))
       (or F4 (= A2 O4))
       (or (not H4) (= G4 2))
       (or H4 (= X1 G4))
       a!7
       (or (not J4) (= I4 1))
       (or J4 (= H2 U3))
       (or J4 (= X1 I4))
       (or J4 (= F1 T3))
       (or (not J4) (= F1 U3))
       a!8
       (or (not K4) (= C3 0))
       (or K4 (= A2 D3))
       (or K4 (= X1 C3))
       (or R5 (= Q5 A3))
       (or (not R5) (= Q5 G4))
       (or (not G6) (= W3 E6))
       (or G6 (= E6 I3))
       (or (not J6) (= B4 I6))
       (or J6 (= I6 O3))
       a!9
       a!10
       (or (not W2) (= U2 T))
       (or W2 (= U2 E))
       (or P2 (= L2 U6))
       (or (not P2) (= L2 O))
       (or V1 (= U1 O6))
       (or (not V1) (= U1 Y))
       (or I (= Y2 U1))
       (or (not I) (= Y2 W))
       (or F (= R2 P6))
       (or (not F) (= R2 X2))
       (or C (= U2 T2))
       (or (not C) (= T2 R))
       (or (not C) (= O2 V2))
       (or C (= O2 K))
       (= (= G2 2) F4)))
      )
      (state K5
       M5
       G6
       G3
       J3
       M3
       J6
       P3
       S3
       R5
       B3
       G5
       K6
       D6
       E5
       R4
       D5
       Q4
       C5
       P4
       B5
       Z5
       Z4
       X5
       X4
       V5
       V4
       T5
       T4
       P5
       W4
       I4
       Q5
       H6
       O4
       E3
       I6
       B4
       O3
       F6
       R3
       M4
       U4
       D4
       A5
       N4
       E6
       W3
       I3
       Y4
       L4
       S4
       Y3
       N5
       C6
       B6
       A6
       Y5
       W5
       U5
       S5
       G4
       A3
       O5
       L5
       J5
       I5
       H5
       F5
       C3
       K4
       H4
       J4
       Q3
       F4
       C4
       E4
       K3
       A4
       X3
       Z3
       T3
       V3
       U3
       L3
       N3
       F3
       H3
       D3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Bool) (M Int) (N Bool) (O Int) (P Bool) (Q Bool) (R Int) (S Bool) (T Int) (U Bool) (V Bool) (W Int) (X Bool) (Y Int) (Z Bool) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Bool) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Bool) (G3 Int) (H3 Bool) (I3 Int) (J3 Int) (K3 Bool) ) 
    (=>
      (and
        (state O1
       Q1
       P2
       H3
       K3
       C
       W2
       F
       I
       V1
       F3
       N1
       Z2
       J2
       M1
       H2
       K1
       E2
       I1
       C2
       G1
       A2
       E1
       F1
       C1
       X1
       B1
       G2
       A1
       T1
       Y2
       W
       U1
       R2
       X2
       E3
       U2
       T
       E
       O2
       K
       V2
       T2
       R
       Q2
       S2
       L2
       O
       J3
       N2
       M2
       K2
       M
       R1
       F2
       D2
       B2
       Z1
       Y1
       I2
       W1
       Y
       D3
       S1
       P1
       D1
       L1
       J1
       H1
       C3
       Z
       X
       V
       D
       U
       S
       Q
       I3
       P
       N
       L
       J
       H
       G
       B
       A
       B3
       A3
       G3)
        (not P1)
      )
      false
    )
  )
)

(check-sat)
(exit)
