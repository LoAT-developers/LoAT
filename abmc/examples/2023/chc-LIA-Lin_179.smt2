; ./prepared/vmt/./lustre/FIREFLY_7_000.smt2
(set-logic HORN)


(declare-fun |state| ( Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Int Int Int Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Bool) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Bool) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Int) (Y1 Int) (Z1 Int) (A2 Bool) (B2 Int) (C2 Bool) (D2 Int) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Int) (I2 Bool) (J2 Int) (K2 Bool) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Bool) (S2 Int) (T2 Int) (U2 Bool) (V2 Int) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Int) (A3 Int) ) 
    (=>
      (and
        (let ((a!1 (= R2 (and U2 (<= 0 J) (not (<= 5 J)))))
      (a!2 (= (or (and (not F2)
                       (not N1)
                       (not H1)
                       (not D)
                       (not X2)
                       (not Y)
                       (not R1)
                       (not W1))
                  (and (not F2)
                       (not N1)
                       (not H1)
                       (not D)
                       (not X2)
                       (not Y)
                       (not R1)
                       W1)
                  (and (not F2)
                       (not N1)
                       (not H1)
                       (not D)
                       (not X2)
                       (not Y)
                       R1
                       (not W1))
                  (and (not F2)
                       (not N1)
                       (not H1)
                       (not D)
                       (not X2)
                       Y
                       (not R1)
                       (not W1))
                  (and (not F2)
                       (not N1)
                       (not H1)
                       (not D)
                       X2
                       (not Y)
                       (not R1)
                       (not W1))
                  (and (not F2)
                       (not N1)
                       (not H1)
                       D
                       (not X2)
                       (not Y)
                       (not R1)
                       (not W1))
                  (and (not F2)
                       (not N1)
                       H1
                       (not D)
                       (not X2)
                       (not Y)
                       (not R1)
                       (not W1))
                  (and (not F2)
                       N1
                       (not H1)
                       (not D)
                       (not X2)
                       (not Y)
                       (not R1)
                       (not W1))
                  (and F2
                       (not N1)
                       (not H1)
                       (not D)
                       (not X2)
                       (not Y)
                       (not R1)
                       (not W1)))
              U2)))
  (and (= (or (not R) (<= P T)) K2)
       (= S R)
       a!1
       (= R2 S)
       (= J2 T)
       (= L M2)
       (= T2 0)
       (= T2 Q)
       (= S2 J2)
       (= S2 J)
       (= Q2 P2)
       (= K J)
       (= K M)
       (= M L)
       (= N 0)
       (= N O2)
       (= O 0)
       (= O Q2)
       (= Q P)
       (= M2 L2)
       (= O2 N2)
       (or (= V1 G1) W1)
       (or (not W1) (= G1 X1))
       (or (not W1) (= M1 H))
       (or (= M1 C) W1)
       (or (not R1) (= L1 T1))
       (or (not R1) (= Q1 S1))
       (or (= Q1 W2) R1)
       (or (= U1 L1) R1)
       (or (not Y) (= D2 Z))
       (or (= X D2) Y)
       (or (not Y) (= B1 A1))
       (or (= C1 B1) Y)
       (or (not Y) (= E1 D1))
       (or (= F1 E1) Y)
       (or (not G) (= H 1))
       (or (not E) (= F 0))
       (or (not X2) (= Z2 Y2))
       (or (not X2) (= W2 V2))
       (or (not X2) (= A A3))
       (or D (= V1 Z2))
       (or (not D) (= V1 Y1))
       (or (not D) (= C B))
       (or (not D) (= U1 Z1))
       (or D (= U1 A))
       (or (not I) (= V2 0))
       (or H1 (= G1 X))
       (or (not H1) (= W F))
       (or (not H1) (= X I1))
       (or (not H1) (= F1 K1))
       (or H1 (= J1 W))
       (or H1 (= L1 F1))
       (or (not N1) (= C1 O1))
       (or (not N1) (= J1 P1))
       (or N1 (= M1 C1))
       (or N1 (= Q1 J1))
       (or F2 (= D2 B2))
       (or (not F2) (= V U))
       (or F2 (= W V))
       (or (not F2) (= B2 H2))
       a!2))
      )
      (state S2
       J2
       R2
       S
       Y
       F2
       H1
       N1
       R1
       W1
       D
       X2
       U2
       K
       M
       T2
       Q
       O
       Q2
       N
       O2
       L
       M2
       N2
       L2
       T
       P
       R
       K2
       U1
       A
       Z1
       V1
       Y1
       Z2
       M1
       C
       H
       G1
       X1
       L1
       T1
       Q1
       S1
       W2
       J1
       P1
       C1
       O1
       F1
       K1
       W
       F
       X
       I1
       E1
       D1
       B1
       A1
       D2
       Z
       V
       U
       B2
       H2
       P2
       J
       V2
       I
       G
       E
       B
       A3
       Y2
       A2
       C2
       E2
       G2
       I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Bool) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Bool) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Int) (Y1 Int) (Z1 Int) (A2 Bool) (B2 Int) (C2 Bool) (D2 Int) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Int) (I2 Bool) (J2 Int) (K2 Bool) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Int) (A3 Bool) (B3 Int) (C3 Bool) (D3 Int) (E3 Bool) (F3 Int) (G3 Bool) (H3 Int) (I3 Bool) (J3 Bool) (K3 Int) (L3 Int) (M3 Bool) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Bool) (I4 Bool) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Bool) (P4 Bool) (Q4 Int) (R4 Int) (S4 Int) (T4 Bool) (U4 Int) (V4 Int) (W4 Bool) (X4 Int) (Y4 Int) (Z4 Int) (A5 Bool) (B5 Int) (C5 Int) (D5 Int) (E5 Bool) (F5 Int) (G5 Bool) (H5 Int) (I5 Int) (J5 Bool) (K5 Bool) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Bool) (T5 Int) (U5 Int) (V5 Bool) (W5 Int) (X5 Int) (Y5 Bool) (Z5 Int) (A6 Int) (B6 Int) ) 
    (=>
      (and
        (state T5
       J2
       S5
       S
       Y
       F2
       H1
       N1
       R1
       W1
       D
       Y5
       V5
       K
       M
       U5
       Q
       O
       R5
       N
       O2
       L
       M2
       N2
       L2
       T
       P
       R
       K2
       U1
       A
       Z1
       V1
       Y1
       A6
       M1
       C
       H
       G1
       X1
       L1
       T1
       Q1
       S1
       X5
       J1
       P1
       C1
       O1
       F1
       K1
       W
       F
       X
       I1
       E1
       D1
       B1
       A1
       D2
       Z
       V
       U
       B2
       H2
       Q5
       J
       W5
       I
       G
       E
       B
       B6
       Z5
       A2
       C2
       E2
       G2
       I2)
        (let ((a!1 (= (or (and (not J5)
                       (not G5)
                       (not E5)
                       (not A5)
                       (not W4)
                       (not T4)
                       (not X2)
                       (not Q2))
                  (and (not J5)
                       (not G5)
                       (not E5)
                       (not A5)
                       (not W4)
                       (not T4)
                       (not X2)
                       Q2)
                  (and (not J5)
                       (not G5)
                       (not E5)
                       (not A5)
                       (not W4)
                       (not T4)
                       X2
                       (not Q2))
                  (and (not J5)
                       (not G5)
                       (not E5)
                       (not A5)
                       (not W4)
                       T4
                       (not X2)
                       (not Q2))
                  (and (not J5)
                       (not G5)
                       (not E5)
                       (not A5)
                       W4
                       (not T4)
                       (not X2)
                       (not Q2))
                  (and (not J5)
                       (not G5)
                       (not E5)
                       A5
                       (not W4)
                       (not T4)
                       (not X2)
                       (not Q2))
                  (and (not J5)
                       (not G5)
                       E5
                       (not A5)
                       (not W4)
                       (not T4)
                       (not X2)
                       (not Q2))
                  (and (not J5)
                       G5
                       (not E5)
                       (not A5)
                       (not W4)
                       (not T4)
                       (not X2)
                       (not Q2))
                  (and J5
                       (not G5)
                       (not E5)
                       (not A5)
                       (not W4)
                       (not T4)
                       (not X2)
                       (not Q2)))
              H4))
      (a!2 (= (or (and (not D)
                       (not Y)
                       (not H1)
                       (not N1)
                       (not R1)
                       (not W1)
                       (not F2)
                       (not Y5))
                  (and (not D)
                       (not Y)
                       (not H1)
                       (not N1)
                       (not R1)
                       (not W1)
                       (not F2)
                       Y5)
                  (and (not D)
                       (not Y)
                       (not H1)
                       (not N1)
                       (not R1)
                       (not W1)
                       F2
                       (not Y5))
                  (and (not D)
                       (not Y)
                       (not H1)
                       (not N1)
                       (not R1)
                       W1
                       (not F2)
                       (not Y5))
                  (and (not D)
                       (not Y)
                       (not H1)
                       (not N1)
                       R1
                       (not W1)
                       (not F2)
                       (not Y5))
                  (and (not D)
                       (not Y)
                       (not H1)
                       N1
                       (not R1)
                       (not W1)
                       (not F2)
                       (not Y5))
                  (and (not D)
                       (not Y)
                       H1
                       (not N1)
                       (not R1)
                       (not W1)
                       (not F2)
                       (not Y5))
                  (and (not D)
                       Y
                       (not H1)
                       (not N1)
                       (not R1)
                       (not W1)
                       (not F2)
                       (not Y5))
                  (and D
                       (not Y)
                       (not H1)
                       (not N1)
                       (not R1)
                       (not W1)
                       (not F2)
                       (not Y5)))
              V5))
      (a!3 (and (<= 1 M2) (= Q 0) (= O2 0) (= R5 0)))
      (a!4 (= (and (<= 1 M2) (<= 1 (+ Q R5))) E3))
      (a!5 (= J3 (and (<= 1 M2) (<= 1 (+ Q R5)))))
      (a!6 (= I4 (and S H4 (<= 0 G4) (not (<= 5 G4)))))
      (a!7 (or (not A3) (= (+ R5 (* (- 1) O3)) (- 1))))
      (a!8 (or (not A3) (= (+ M2 (* (- 1) Z2)) 1)))
      (a!9 (or (not C3) (= (+ O2 (* (- 1) K3)) 1)))
      (a!10 (or (not C3) (= (+ M2 (* (- 1) B3)) 1)))
      (a!11 (or (not C3) (= (+ Q (* (- 1) U3)) (- 2))))
      (a!12 (or (not E3) (= (+ Q R5 (* (- 1) T3)) (- 1))))
      (a!13 (or (not E3) (= (+ M2 (* (- 1) D3)) 1)))
      (a!14 (or (not G3) (= (+ M2 (* (- 1) F3)) 1)))
      (a!15 (or (not I3) (= (+ O2 (* (- 1) Y2)) 1)))
      (a!16 (or (not I3) (= (+ M2 (* (- 1) H3)) 1)))
      (a!17 (or (not I3) (= (+ Q (* (- 1) W3)) (- 2))))
      (a!18 (or (not J3) (= (+ Q R5 (* (- 1) U2)) (- 1))))
      (a!19 (or (not J3) (= (+ M2 (* (- 1) R2)) 1)))
      (a!20 (or (not M3) (= (+ R5 (* (- 1) Q3)) 1)))
      (a!21 (or (not M3) (= (+ O2 (* (- 1) L3)) (- 1))))
      (a!22 (or (not S3) (= (+ R5 (* (- 1) R3)) (- 1)))))
  (and a!1
       a!2
       (= (or (not O4) (<= M4 Q4)) K5)
       (= (or (not R) (<= P T)) K2)
       (= a!3 A3)
       a!4
       (= (and (<= 1 M2) (<= 1 O2)) C3)
       (= (and (<= 1 M2) (<= 1 O2)) I3)
       (= S5 S)
       (= G3 a!3)
       a!5
       (= S3 (= Q 1))
       a!6
       (= P4 I4)
       (= P4 O4)
       (= S R)
       (= U5 Q)
       (= T5 J2)
       (= R5 Q5)
       (= Z3 Y3)
       (= B4 A4)
       (= D4 C4)
       (= F4 E4)
       (= L4 D4)
       (= L4 K4)
       (= N4 F4)
       (= N4 M4)
       (= R4 J4)
       (= R4 Q4)
       (= M5 Z3)
       (= M5 L5)
       (= O5 B4)
       (= O5 N5)
       (= P5 X3)
       (= O2 N2)
       (= M2 L2)
       (= J2 J4)
       (= J2 T)
       (= Q P)
       (= O R5)
       (= N O2)
       (= M X3)
       (= L M2)
       (= K M)
       (or Q2 (= R5 T2))
       (or (not Q2) (= P2 R2))
       (or (not Q2) (= T2 S2))
       (or (not Q2) (= V2 U2))
       (or Q2 (= M2 P2))
       (or Q2 (= Q V2))
       (or X2 (= V2 H5))
       (or (not X2) (= W2 Y2))
       (or (not X2) (= H3 I5))
       (or (not X2) (= H5 W3))
       (or X2 (= I5 P2))
       (or X2 (= O2 W2))
       a!7
       a!8
       (or A3 (= R5 O3))
       (or A3 (= M2 Z2))
       a!9
       a!10
       a!11
       (or C3 (= O2 K3))
       (or C3 (= M2 B3))
       (or C3 (= Q U3))
       a!12
       a!13
       (or E3 (= R5 P3))
       (or (not E3) (= P3 0))
       (or E3 (= M2 D3))
       (or E3 (= Q T3))
       a!14
       (or (not G3) (= N3 1))
       (or G3 (= O2 N3))
       (or G3 (= M2 F3))
       a!15
       a!16
       a!17
       (or I3 (= O2 Y2))
       (or I3 (= M2 H3))
       (or I3 (= Q W3))
       a!18
       a!19
       (or J3 (= R5 S2))
       (or (not J3) (= S2 0))
       (or J3 (= M2 R2))
       (or J3 (= Q U2))
       a!20
       a!21
       (or M3 (= R5 Q3))
       (or M3 (= O2 L3))
       a!22
       (or S3 (= R5 R3))
       (or (not S3) (= V3 0))
       (or S3 (= Q V3))
       (or (not T4) (= Z2 Y3))
       (or (not T4) (= C4 O3))
       (or T4 (= S4 Y3))
       (or T4 (= U4 C4))
       (or (not W4) (= B3 S4))
       (or (not W4) (= A4 K3))
       (or (not W4) (= E4 U3))
       (or W4 (= V4 S4))
       (or W4 (= X4 A4))
       (or W4 (= Y4 E4))
       (or (not A5) (= D3 V4))
       (or (not A5) (= U4 P3))
       (or (not A5) (= Y4 T3))
       (or A5 (= Z4 V4))
       (or A5 (= B5 U4))
       (or A5 (= C5 Y4))
       (or (not E5) (= L3 X4))
       (or (not E5) (= B5 Q3))
       (or E5 (= D5 X4))
       (or E5 (= F5 B5))
       (or (not G5) (= R3 F5))
       (or (not G5) (= C5 V3))
       (or G5 (= F5 T2))
       (or G5 (= H5 C5))
       (or J5 (= W2 D5))
       (or (not J5) (= F3 Z4))
       (or (not J5) (= D5 N3))
       (or J5 (= I5 Z4))
       (or F2 (= D2 B2))
       (or (not F2) (= B2 H2))
       (or F2 (= W V))
       (or (not F2) (= V U))
       (or W1 (= V1 G1))
       (or (not W1) (= M1 H))
       (or W1 (= M1 C))
       (or (not W1) (= G1 X1))
       (or R1 (= U1 L1))
       (or R1 (= Q1 X5))
       (or (not R1) (= Q1 S1))
       (or (not R1) (= L1 T1))
       (or N1 (= Q1 J1))
       (or N1 (= M1 C1))
       (or (not N1) (= J1 P1))
       (or (not N1) (= C1 O1))
       (or H1 (= L1 F1))
       (or H1 (= J1 W))
       (or H1 (= G1 X))
       (or (not H1) (= F1 K1))
       (or (not H1) (= X I1))
       (or (not H1) (= W F))
       (or (not Y) (= D2 Z))
       (or Y (= F1 E1))
       (or (not Y) (= E1 D1))
       (or Y (= C1 B1))
       (or (not Y) (= B1 A1))
       (or Y (= X D2))
       (or D (= V1 A6))
       (or (not D) (= V1 Y1))
       (or (not D) (= U1 Z1))
       (or D (= U1 A))
       (= (<= 1 R5) M3)))
      )
      (state J4
       R4
       I4
       P4
       W4
       T4
       A5
       E5
       G5
       J5
       X2
       Q2
       H4
       X3
       P5
       F4
       N4
       D4
       L4
       B4
       O5
       Z3
       M5
       N5
       L5
       Q4
       M4
       O4
       K5
       H5
       V2
       W3
       I5
       H3
       P2
       D5
       W2
       N3
       Z4
       F3
       C5
       V3
       F5
       R3
       T2
       B5
       Q3
       X4
       L3
       Y4
       T3
       U4
       P3
       V4
       D3
       E4
       U3
       A4
       K3
       S4
       B3
       C4
       O3
       Y3
       Z2
       K4
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
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Bool) (F Int) (G Bool) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Bool) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Int) (Y1 Int) (Z1 Int) (A2 Bool) (B2 Int) (C2 Bool) (D2 Int) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Int) (I2 Bool) (J2 Int) (K2 Bool) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Bool) (S2 Int) (T2 Int) (U2 Bool) (V2 Int) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Int) (A3 Int) ) 
    (=>
      (and
        (state S2
       J2
       R2
       S
       Y
       F2
       H1
       N1
       R1
       W1
       D
       X2
       U2
       K
       M
       T2
       Q
       O
       Q2
       N
       O2
       L
       M2
       N2
       L2
       T
       P
       R
       K2
       U1
       A
       Z1
       V1
       Y1
       Z2
       M1
       C
       H
       G1
       X1
       L1
       T1
       Q1
       S1
       W2
       J1
       P1
       C1
       O1
       F1
       K1
       W
       F
       X
       I1
       E1
       D1
       B1
       A1
       D2
       Z
       V
       U
       B2
       H2
       P2
       J
       V2
       I
       G
       E
       B
       A3
       Y2
       A2
       C2
       E2
       G2
       I2)
        (not K2)
      )
      false
    )
  )
)

(check-sat)
(exit)
