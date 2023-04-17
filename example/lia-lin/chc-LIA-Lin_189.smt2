; ./vmt/./lustre/DRAGON_all2_e8_5504_e7_579_000.smt2
(set-logic HORN)

(declare-fun |state| ( Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Bool Int Bool Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Int Bool Bool Bool Bool Bool Bool Bool Int Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Int) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Int) (K Bool) (L Int) (M Bool) (N Int) (O Bool) (P Int) (Q Int) (R Bool) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Bool) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Bool) (C2 Bool) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Int) (C3 Bool) (D3 Bool) (E3 Bool) (F3 Int) (G3 Bool) (H3 Bool) (I3 Bool) (J3 Int) (K3 Bool) (L3 Int) (M3 Bool) (N3 Int) (O3 Bool) (P3 Bool) (Q3 Int) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Bool) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Bool) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Bool) (U4 Int) (V4 Int) (W4 Bool) (X4 Bool) (Y4 Int) (Z4 Int) (A5 Bool) (B5 Int) (C5 Int) (D5 Bool) (E5 Int) ) 
    (=>
      (and
        (let ((a!1 (or (not D3)
               (= (+ B3
                     (* (- 1) X2)
                     (* (- 1) V2)
                     (* (- 1) T2)
                     (* (- 1) R2)
                     (* (- 1) P2))
                  0)))
      (a!2 (or (not D3) (and (not (<= 1 V2)) (not (<= 1 R2)))))
      (a!3 (= A1 (and Z (not (<= U 0)))))
      (a!4 (= (or (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4))
                  (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       N4)
                  (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       H4
                       (not N4))
                  (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       S3
                       (not H4)
                       (not N4))
                  (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       Y1
                       (not S3)
                       (not H4)
                       (not N4))
                  (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       T1
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4))
                  (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       N1
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4))
                  (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       I1
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4))
                  (and (not H3)
                       (not W4)
                       (not A5)
                       (not D5)
                       B
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4))
                  (and (not H3)
                       (not W4)
                       (not A5)
                       D5
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4))
                  (and (not H3)
                       (not W4)
                       A5
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4))
                  (and (not H3)
                       W4
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4))
                  (and H3
                       (not W4)
                       (not A5)
                       (not D5)
                       (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not S3)
                       (not H4)
                       (not N4)))
              Z)))
  (and (= a!1 E2)
       (= (or (not D3) (<= 0 X2)) L2)
       (= (or (not D3) (<= 0 T2)) J2)
       (= (or (not D3) (<= 0 P2)) I2)
       (= (or (not D3) (<= 0 R2)) H2)
       (= (or (not D3) (<= 0 V2)) K2)
       (= (or (not D3) (<= X2 X3)) P3)
       (= (or (not D3) (<= T2 V3)) N2)
       (= (or (not D3) (<= R2 Q3)) M2)
       (= (or (not D3) (<= V2 1)) F2)
       (= (or (not D3) (<= V2 W3)) O2)
       (= a!2 G2)
       (= (or (not D3) (not Z2)) C2)
       (= (or (not D3) X4) D2)
       (= (and P3 H2 G2 C2 D2 E2 F2 I2 J2 K2 L2 M2 N2 O2) B2)
       (= T4 (<= 2 Q2))
       (= T4 Y3)
       (= Z3 D3)
       a!3
       (= A1 Z3)
       (= Y3 Z2)
       (= F1 X3)
       (= F1 U)
       (= Y 0)
       (= Y U2)
       (= W 0)
       (= W Q2)
       (= E 0)
       (= G F)
       (= V U)
       (= V G)
       (= X 0)
       (= X S2)
       (= B1 B3)
       (= B1 U)
       (= C1 Q3)
       (= C1 U)
       (= D1 U)
       (= D1 V3)
       (= E1 U)
       (= E1 W3)
       (= Q2 P2)
       (= S2 R2)
       (= U2 T2)
       (= W2 E)
       (= W2 V2)
       (= Y2 X2)
       (= Y2 F)
       (or (not N4) (= S4 R4))
       (or (= S4 K1) N4)
       (or (not N4) (= L4 J))
       (or (= L4 Q1) N4)
       (or (= G4 N3) N4)
       (or (not N4) (= G4 O4))
       (or (not N4) (= H M4))
       (or (= M4 M1) N4)
       (or (not N4) (= Q4 P4))
       (or (= Q4 V1) N4)
       (or (= L4 K4) H4)
       (or (not H4) (= K4 J4))
       (or (= G4 F4) H4)
       (or (not H4) (= F4 I4))
       (or (= R3 A3) S3)
       (or (= F3 V4) S3)
       (or (not S3) (= F3 T))
       (or (not S3) (= R1 S))
       (or (= R1 A) S3)
       (or (= X1 Z4) S3)
       (or (not S3) (= X1 U3))
       (or (not S3) (= A2 Q))
       (or (= A2 C5) S3)
       (or (not S3) (= A3 T3))
       (or (not Y1) (= L1 P))
       (or (not Y1) (= W1 Z1))
       (or (= X1 W1) Y1)
       (or (= A2 L1) Y1)
       (or (= S1 H1) T1)
       (or (not T1) (= U1 H1))
       (or (not T1) (= V1 N))
       (or (= V1 W1) T1)
       (or (= M1 G1) N1)
       (or (not N1) (= M1 O1))
       (or (not N1) (= Q1 P1))
       (or (= Q1 R1) N1)
       (or (not I1) (= K1 L))
       (or (= K1 L1) I1)
       (or (not I1) (= G1 J1))
       (or (= H1 G1) I1)
       (or (not R) (= S 0))
       (or (not R) (= Q 1))
       (or (not R) (= T 0))
       (or (not K) (= L 0))
       (or (not I) (= H 0))
       (or (not I) (= J 0))
       (or (not B) (= A E5))
       (or (not B) (= D C))
       (or (not D5) (= C5 B5))
       (or D5 (= C4 D))
       (or (not D5) (= C4 E4))
       (or (not A5) (= A4 D4))
       (or (not A5) (= Z4 Y4))
       (or A5 (= C4 A4))
       (or W4 (= A4 R3))
       (or (not W4) (= R3 B4))
       (or (not W4) (= V4 U4))
       (or (not M) (= N 0))
       (or (not O) (= P 1))
       (or (not H3) (= N3 L3))
       (or H3 (= N3 A3))
       (or (not H3) (= J3 S1))
       (or H3 (= F3 S1))
       (= X4 true)
       a!4))
      )
      (state F1
       X3
       E1
       W3
       D1
       V3
       C1
       Q3
       B1
       B3
       A1
       Z3
       N4
       H4
       N1
       I1
       T1
       Y1
       H3
       S3
       W4
       A5
       D5
       B
       Z
       V
       G
       T4
       Y3
       Y2
       F
       W2
       E
       Y
       U2
       X
       S2
       W
       Q2
       S4
       K1
       R4
       Q4
       V1
       P4
       L4
       Q1
       J
       G4
       N3
       O4
       H
       M4
       M1
       K4
       J4
       F4
       I4
       C4
       E4
       D
       A4
       D4
       R3
       B4
       D3
       Z2
       X2
       P3
       V2
       O2
       T2
       N2
       F3
       V4
       T
       A2
       C5
       Q
       X1
       Z4
       U3
       R1
       A
       S
       A3
       T3
       R2
       M2
       L2
       K2
       J2
       P2
       I2
       H2
       G2
       F2
       E2
       X4
       D2
       L3
       J3
       S1
       C2
       B2
       L1
       P
       W1
       Z1
       N
       U1
       H1
       P1
       O1
       G1
       L
       J1
       U
       R
       O
       M
       K
       I
       C
       E5
       B5
       Y4
       U4
       C3
       E3
       G3
       I3
       K3
       M3
       O3)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Int) (K Bool) (L Int) (M Bool) (N Int) (O Bool) (P Int) (Q Int) (R Bool) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Bool) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Bool) (C2 Bool) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Int) (C3 Bool) (D3 Bool) (E3 Bool) (F3 Int) (G3 Bool) (H3 Bool) (I3 Bool) (J3 Int) (K3 Bool) (L3 Int) (M3 Bool) (N3 Int) (O3 Bool) (P3 Bool) (Q3 Int) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Bool) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Bool) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Bool) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Bool) (A5 Int) (B5 Bool) (C5 Int) (D5 Int) (E5 Bool) (F5 Int) (G5 Int) (H5 Bool) (I5 Int) (J5 Int) (K5 Bool) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Bool) (S5 Int) (T5 Bool) (U5 Int) (V5 Bool) (W5 Int) (X5 Bool) (Y5 Int) (Z5 Bool) (A6 Int) (B6 Bool) (C6 Int) (D6 Bool) (E6 Bool) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Bool) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Bool) (Q6 Int) (R6 Bool) (S6 Int) (T6 Int) (U6 Bool) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Bool) (M7 Bool) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Bool) (V7 Int) (W7 Int) (X7 Int) (Y7 Bool) (Z7 Int) (A8 Int) (B8 Int) (C8 Bool) (D8 Int) (E8 Int) (F8 Int) (G8 Bool) (H8 Int) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Bool) (O8 Bool) (P8 Bool) (Q8 Bool) (R8 Bool) (S8 Bool) (T8 Bool) (U8 Bool) (V8 Bool) (W8 Bool) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Bool) (D9 Bool) (E9 Int) (F9 Bool) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Bool) (M9 Int) (N9 Int) (O9 Int) (P9 Bool) (Q9 Bool) (R9 Int) (S9 Int) (T9 Int) (U9 Bool) (V9 Int) (W9 Bool) (X9 Bool) (Y9 Int) (Z9 Int) (A10 Int) (B10 Bool) (C10 Bool) (D10 Int) (E10 Int) (F10 Bool) (G10 Int) (H10 Int) (I10 Bool) (J10 Int) ) 
    (=>
      (and
        (state F1
       X3
       E1
       W3
       D1
       V3
       C1
       Q3
       B1
       B3
       A1
       Z3
       N4
       H4
       N1
       I1
       T1
       Y1
       H3
       S3
       B10
       F10
       I10
       B
       Z
       V
       G
       T4
       Y3
       Y2
       F
       W2
       E
       Y
       U2
       X
       S2
       W
       Q2
       S4
       K1
       R4
       Q4
       V1
       P4
       L4
       Q1
       J
       G4
       N3
       O4
       H
       M4
       M1
       K4
       J4
       F4
       I4
       C4
       E4
       D
       A4
       D4
       R3
       B4
       D3
       Z2
       X2
       P3
       V2
       O2
       T2
       N2
       F3
       A10
       T
       A2
       H10
       Q
       X1
       E10
       U3
       R1
       A
       S
       A3
       T3
       R2
       M2
       L2
       K2
       J2
       P2
       I2
       H2
       G2
       F2
       E2
       C10
       D2
       L3
       J3
       S1
       C2
       B2
       L1
       P
       W1
       Z1
       N
       U1
       H1
       P1
       O1
       G1
       L
       J1
       U
       R
       O
       M
       K
       I
       C
       J10
       G10
       D10
       Z9
       C3
       E3
       G3
       I3
       K3
       M3
       O3)
        (let ((a!1 (= (or (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5))
                  (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       B5)
                  (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       E5
                       (not B5))
                  (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       H5
                       (not E5)
                       (not B5))
                  (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       K5
                       (not H5)
                       (not E5)
                       (not B5))
                  (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       U7
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5))
                  (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       Y7
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5))
                  (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       C8
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5))
                  (and (not W9)
                       (not U9)
                       (not L9)
                       (not F9)
                       G8
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5))
                  (and (not W9)
                       (not U9)
                       (not L9)
                       F9
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5))
                  (and (not W9)
                       (not U9)
                       L9
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5))
                  (and (not W9)
                       U9
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5))
                  (and W9
                       (not U9)
                       (not L9)
                       (not F9)
                       (not G8)
                       (not C8)
                       (not Y7)
                       (not U7)
                       (not K5)
                       (not H5)
                       (not E5)
                       (not B5)))
              L7))
      (a!2 (= (or (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10))
                  (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       I10)
                  (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       F10
                       (not I10))
                  (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       B10
                       (not F10)
                       (not I10))
                  (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       N4
                       (not B10)
                       (not F10)
                       (not I10))
                  (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       H4
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10))
                  (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       S3
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10))
                  (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       H3
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10))
                  (and (not B)
                       (not I1)
                       (not N1)
                       (not T1)
                       Y1
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10))
                  (and (not B)
                       (not I1)
                       (not N1)
                       T1
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10))
                  (and (not B)
                       (not I1)
                       N1
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10))
                  (and (not B)
                       I1
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10))
                  (and B
                       (not I1)
                       (not N1)
                       (not T1)
                       (not Y1)
                       (not H3)
                       (not S3)
                       (not H4)
                       (not N4)
                       (not B10)
                       (not F10)
                       (not I10)))
              Z))
      (a!3 (or (not D9)
               (= (+ I9
                     (* (- 1) Y4)
                     (* (- 1) X4)
                     (* (- 1) W4)
                     (* (- 1) V4)
                     (* (- 1) U4))
                  0)))
      (a!4 (or (not D9) (and (not (<= 1 X4)) (not (<= 1 V4)))))
      (a!5 (or (not D3)
               (= (+ B3
                     (* (- 1) X2)
                     (* (- 1) V2)
                     (* (- 1) T2)
                     (* (- 1) R2)
                     (* (- 1) P2))
                  0)))
      (a!6 (or (not D3) (and (not (<= 1 R2)) (not (<= 1 V2)))))
      (a!7 (and (<= 1 Y2) (= Q2 0) (= S2 0) (= U2 0) (= W2 0)))
      (a!8 (and (<= 1 Y2) (<= 1 (+ W2 U2 S2 Q2))))
      (a!9 (= Z4
              (= (+ X2
                    V2
                    T2
                    R2
                    P2
                    (* (- 1) Y4)
                    (* (- 1) X4)
                    (* (- 1) W4)
                    (* (- 1) V4)
                    (* (- 1) U4))
                 0)))
      (a!10 (or Z3 (and L7 (not (<= K7 0)))))
      (a!11 (or (not R5) (= (+ Y2 (* (- 1) Q5)) 1)))
      (a!12 (or (not R5) (= (+ Q2 (* (- 1) H6)) (- 1))))
      (a!13 (or (not T5) (= (+ W2 U2 (* (- 1) S6)) 0)))
      (a!14 (or (not T5) (= (+ S2 Q2 (* (- 1) M6)) (- 1))))
      (a!15 (or (not T5) (= (+ Y2 (* (- 1) S5)) 1)))
      (a!16 (or (not V5) (= (+ Y2 (* (- 1) U5)) 1)))
      (a!17 (or (not V5) (= (+ W2 (* (- 1) B7)) (- 1))))
      (a!18 (or (not X5) (= (+ W2 U2 S2 Q2 (* (- 1) N6)) 0)))
      (a!19 (or (not X5) (= (+ Y2 (* (- 1) W5)) 1)))
      (a!20 (or (not Z5) (= (+ Y2 (* (- 1) Y5)) (- 1))))
      (a!21 (or (not Z5) (= (+ W2 (* (- 1) C5)) 1)))
      (a!22 (or (not B6) (= (+ Y2 (* (- 1) A6)) (- 1))))
      (a!23 (or (not B6) (= (+ S2 (* (- 1) F5)) 1)))
      (a!24 (or (not D6) (= (+ Y2 (* (- 1) C6)) (- 1))))
      (a!25 (or (not D6) (= (+ U2 (* (- 1) I5)) 1)))
      (a!26 (or (not E6) (= (+ Y2 (* (- 1) L5)) (- 1))))
      (a!27 (or (not E6) (= (+ Q2 (* (- 1) M5)) 1)))
      (a!28 (or (not K6) (= (+ W2 (* (- 1) X6)) (- 1))))
      (a!29 (or (not K6) (= (+ Q2 (* (- 1) J6)) 1)))
      (a!30 (or (not P6) (= (+ W2 (* (- 1) A7)) (- 1))))
      (a!31 (or (not R6) (= (+ U2 S2 (* (- 1) Q6)) 1)))
      (a!32 (or (not U6) (= (+ W2 (* (- 1) Z6)) (- 1)))))
  (and (= (<= 1 U2) D6)
       (= (<= 1 S2) B6)
       (= (<= 1 Q2) E6)
       (= (<= 1 Q2) K6)
       a!1
       a!2
       (= a!3 L8)
       (= (or (not D9) (<= 0 U4)) P8)
       (= (or (not D9) (<= 0 V4)) O8)
       (= (or (not D9) (<= 0 W4)) Q8)
       (= (or (not D9) (<= 0 X4)) R8)
       (= (or (not D9) (<= 0 Y4)) S8)
       (= (or (not D9) (<= V4 J9)) T8)
       (= (or (not D9) (<= W4 M9)) U8)
       (= (or (not D9) (<= X4 1)) M8)
       (= (or (not D9) (<= X4 N9)) V8)
       (= (or (not D9) (<= Y4 O9)) W8)
       (= a!4 N8)
       (= (or (not D9) Z4) K8)
       (= (or (not D9) (not C9)) J8)
       (= a!5 E2)
       (= (or (not D3) (<= 0 X2)) L2)
       (= (or (not D3) (<= 0 V2)) K2)
       (= (or (not D3) (<= 0 T2)) J2)
       (= (or (not D3) (<= 0 R2)) H2)
       (= (or (not D3) (<= 0 P2)) I2)
       (= (or (not D3) (<= X2 X3)) P3)
       (= (or (not D3) (<= V2 1)) F2)
       (= (or (not D3) (<= V2 W3)) O2)
       (= (or (not D3) (<= T2 V3)) N2)
       (= (or (not D3) (<= R2 Q3)) M2)
       (= a!6 G2)
       (= (or (not D3) C10) D2)
       (= (or (not Z2) (not D3)) C2)
       (= (and W8 V8 U8 T8 S8 R8 Q8 P8 O8 N8 M8 L8 K8 J8) I8)
       (= (and C2 D2 E2 F2 G2 H2 I2 J2 K2 L2 M2 N2 O2 P3) B2)
       (= a!7 R5)
       (= a!7 V5)
       (= a!8 T5)
       (= a!8 X5)
       a!9
       (= P6 (and (= S2 1) (= U2 0)))
       (= R6 (<= 2 (+ U2 S2)))
       (= U6 (and (= S2 0) (= U2 1)))
       (= M7 a!10)
       (= P9 C9)
       (= P9 X9)
       (= Q9 M7)
       (= Q9 D9)
       (= X9 (<= 2 X8))
       (= T4 (<= 2 Q2))
       (= T4 Y3)
       (= Z3 D3)
       (= Y3 Z2)
       (= A1 Z3)
       (= P5 O5)
       (= P5 A9)
       (= G6 F6)
       (= G6 B9)
       (= F7 E7)
       (= H7 G7)
       (= J7 I7)
       (= X8 U4)
       (= X8 F7)
       (= Y8 V4)
       (= Y8 H7)
       (= Z8 W4)
       (= Z8 J7)
       (= A9 X4)
       (= B9 Y4)
       (= I9 N7)
       (= J9 O7)
       (= M9 P7)
       (= N9 Q7)
       (= O9 R7)
       (= Y9 D7)
       (= X3 R7)
       (= W3 Q7)
       (= V3 P7)
       (= Q3 O7)
       (= B3 N7)
       (= Y2 X2)
       (= Y2 F)
       (= W2 V2)
       (= W2 E)
       (= U2 T2)
       (= S2 R2)
       (= Q2 P2)
       (= F1 X3)
       (= E1 W3)
       (= D1 V3)
       (= C1 Q3)
       (= B1 B3)
       (= Y U2)
       (= X S2)
       (= W Q2)
       (= V G)
       (= G D7)
       (or (not I10) (= C4 E4))
       (or I10 (= C4 D))
       (or F10 (= C4 A4))
       (or (not F10) (= A4 D4))
       (or B10 (= A4 R3))
       (or (not B10) (= R3 B4))
       (or (not B5) (= A5 C5))
       (or (not B5) (= Y5 K9))
       (or B5 (= R9 K9))
       (or B5 (= W2 A5))
       (or (not E5) (= D5 F5))
       (or (not E5) (= A6 R9))
       (or E5 (= S9 R9))
       (or E5 (= S2 D5))
       (or (not H5) (= G5 I5))
       (or (not H5) (= C6 S9))
       (or H5 (= S9 J5))
       (or H5 (= U2 G5))
       (or (not K5) (= J5 L5))
       (or (not K5) (= N5 M5))
       (or K5 (= Y2 J5))
       (or K5 (= Q2 N5))
       a!11
       a!12
       (or R5 (= Y2 Q5))
       (or R5 (= Q2 H6))
       a!13
       a!14
       a!15
       (or (not T5) (= I6 0))
       (or (not T5) (= Y6 0))
       (or T5 (= Y2 S5))
       (or T5 (= W2 Y6))
       (or T5 (= U2 S6))
       (or T5 (= S2 M6))
       (or T5 (= Q2 I6))
       a!16
       a!17
       (or V5 (= Y2 U5))
       (or V5 (= W2 B7))
       a!18
       a!19
       (or (not X5) (= L6 0))
       (or (not X5) (= W6 1))
       (or (not X5) (= C7 0))
       (or X5 (= Y2 W5))
       (or X5 (= W2 C7))
       (or X5 (= U2 W6))
       (or X5 (= S2 N6))
       (or X5 (= Q2 L6))
       a!20
       a!21
       (or Z5 (= Y2 Y5))
       (or Z5 (= W2 C5))
       a!22
       a!23
       (or B6 (= Y2 A6))
       (or B6 (= S2 F5))
       a!24
       a!25
       (or D6 (= Y2 C6))
       (or D6 (= U2 I5))
       a!26
       a!27
       (or E6 (= Y2 L5))
       (or E6 (= Q2 M5))
       a!28
       a!29
       (or K6 (= W2 X6))
       (or K6 (= Q2 J6))
       a!30
       (or (not P6) (= O6 0))
       (or P6 (= W2 A7))
       (or P6 (= S2 O6))
       a!31
       (or (not R6) (= V6 1))
       (or R6 (= U2 V6))
       (or R6 (= S2 Q6))
       a!32
       (or (not U6) (= T6 0))
       (or U6 (= W2 Z6))
       (or U6 (= U2 T6))
       (or (not U7) (= S7 Z6))
       (or U7 (= T7 S7))
       (or (not U7) (= V7 T6))
       (or U7 (= V7 W7))
       (or (not Y7) (= X7 X6))
       (or Y7 (= X7 S7))
       (or (not Y7) (= Z7 J6))
       (or Y7 (= Z7 A8))
       (or (not C8) (= T7 A7))
       (or C8 (= B8 T7))
       (or (not C8) (= D8 O6))
       (or C8 (= D8 E8))
       (or (not G8) (= Q6 E8))
       (or (not G8) (= W7 V6))
       (or G8 (= F8 E8))
       (or G8 (= H8 W7))
       (or (not F9) (= B8 B7))
       (or F9 (= E9 B8))
       (or (not F9) (= G9 U5))
       (or F9 (= G9 H9))
       (or L9 (= A5 E9))
       (or L9 (= D5 F8))
       (or L9 (= G5 H8))
       (or L9 (= N5 A8))
       (or (not L9) (= W5 H9))
       (or (not L9) (= A8 L6))
       (or (not L9) (= F8 N6))
       (or (not L9) (= H8 W6))
       (or (not L9) (= E9 C7))
       (or L9 (= K9 H9))
       (or (not U9) (= Q5 F6))
       (or (not U9) (= E7 H6))
       (or U9 (= T9 F6))
       (or U9 (= V9 E7))
       (or (not W9) (= O5 Y6))
       (or W9 (= O5 X7))
       (or (not W9) (= G7 M6))
       (or (not W9) (= I7 S6))
       (or W9 (= V7 I7))
       (or W9 (= Z7 V9))
       (or W9 (= D8 G7))
       (or W9 (= G9 T9))
       (or (not W9) (= T9 S5))
       (or (not W9) (= V9 I6))
       (or (not N4) (= S4 R4))
       (or N4 (= S4 K1))
       (or (not N4) (= Q4 P4))
       (or N4 (= Q4 V1))
       (or N4 (= M4 M1))
       (or N4 (= L4 Q1))
       (or (not N4) (= L4 J))
       (or (not N4) (= G4 O4))
       (or N4 (= G4 N3))
       (or (not N4) (= H M4))
       (or H4 (= L4 K4))
       (or (not H4) (= K4 J4))
       (or H4 (= G4 F4))
       (or (not H4) (= F4 I4))
       (or S3 (= R3 A3))
       (or S3 (= F3 A10))
       (or (not S3) (= F3 T))
       (or (not S3) (= A3 T3))
       (or S3 (= A2 H10))
       (or (not S3) (= A2 Q))
       (or S3 (= X1 E10))
       (or (not S3) (= X1 U3))
       (or (not S3) (= R1 S))
       (or S3 (= R1 A))
       (or (not H3) (= N3 L3))
       (or H3 (= N3 A3))
       (or (not H3) (= J3 S1))
       (or H3 (= F3 S1))
       (or Y1 (= A2 L1))
       (or Y1 (= X1 W1))
       (or (not Y1) (= W1 Z1))
       (or (not Y1) (= L1 P))
       (or T1 (= V1 W1))
       (or (not T1) (= V1 N))
       (or (not T1) (= U1 H1))
       (or T1 (= S1 H1))
       (or N1 (= Q1 R1))
       (or (not N1) (= Q1 P1))
       (or (not N1) (= M1 O1))
       (or N1 (= M1 G1))
       (or I1 (= K1 L1))
       (or (not I1) (= K1 L))
       (or I1 (= H1 G1))
       (or (not I1) (= G1 J1))
       (= (<= 1 W2) Z5)))
      )
      (state R7
       O9
       Q7
       N9
       P7
       M9
       O7
       J9
       N7
       I9
       M7
       Q9
       W9
       U9
       Y7
       U7
       C8
       G8
       F9
       L9
       B5
       E5
       H5
       K5
       L7
       D7
       Y9
       X9
       P9
       B9
       G6
       A9
       P5
       J7
       Z8
       H7
       Y8
       F7
       X8
       I7
       V7
       S6
       G7
       D8
       M6
       V9
       Z7
       I6
       T9
       G9
       S5
       Y6
       O5
       X7
       E7
       H6
       F6
       Q5
       S9
       C6
       J5
       R9
       A6
       K9
       Y5
       D9
       C9
       Y4
       W8
       X4
       V8
       W4
       U8
       E9
       A5
       C7
       H8
       G5
       W6
       F8
       D5
       N6
       A8
       N5
       L6
       H9
       W5
       V4
       T8
       S8
       R8
       Q8
       U4
       P8
       O8
       N8
       M8
       L8
       Z4
       K8
       U5
       B7
       B8
       J8
       I8
       W7
       V6
       E8
       Q6
       O6
       A7
       T7
       J6
       X6
       S7
       T6
       Z6
       K7
       X5
       R6
       P6
       U6
       T5
       L5
       M5
       I5
       F5
       C5
       R5
       K6
       V5
       Z5
       B6
       D6
       E6)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Bool) (J Int) (K Bool) (L Int) (M Bool) (N Int) (O Bool) (P Int) (Q Int) (R Bool) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Bool) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Bool) (C2 Bool) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Int) (C3 Bool) (D3 Bool) (E3 Bool) (F3 Int) (G3 Bool) (H3 Bool) (I3 Bool) (J3 Int) (K3 Bool) (L3 Int) (M3 Bool) (N3 Int) (O3 Bool) (P3 Bool) (Q3 Int) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Bool) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Bool) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Bool) (U4 Int) (V4 Int) (W4 Bool) (X4 Bool) (Y4 Int) (Z4 Int) (A5 Bool) (B5 Int) (C5 Int) (D5 Bool) (E5 Int) ) 
    (=>
      (and
        (state F1
       X3
       E1
       W3
       D1
       V3
       C1
       Q3
       B1
       B3
       A1
       Z3
       N4
       H4
       N1
       I1
       T1
       Y1
       H3
       S3
       W4
       A5
       D5
       B
       Z
       V
       G
       T4
       Y3
       Y2
       F
       W2
       E
       Y
       U2
       X
       S2
       W
       Q2
       S4
       K1
       R4
       Q4
       V1
       P4
       L4
       Q1
       J
       G4
       N3
       O4
       H
       M4
       M1
       K4
       J4
       F4
       I4
       C4
       E4
       D
       A4
       D4
       R3
       B4
       D3
       Z2
       X2
       P3
       V2
       O2
       T2
       N2
       F3
       V4
       T
       A2
       C5
       Q
       X1
       Z4
       U3
       R1
       A
       S
       A3
       T3
       R2
       M2
       L2
       K2
       J2
       P2
       I2
       H2
       G2
       F2
       E2
       X4
       D2
       L3
       J3
       S1
       C2
       B2
       L1
       P
       W1
       Z1
       N
       U1
       H1
       P1
       O1
       G1
       L
       J1
       U
       R
       O
       M
       K
       I
       C
       E5
       B5
       Y4
       U4
       C3
       E3
       G3
       I3
       K3
       M3
       O3)
        (not B2)
      )
      false
    )
  )
)

(check-sat)
(exit)
