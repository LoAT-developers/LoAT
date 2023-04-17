; ./vmt/./lustre/rtp_all_e7_2500_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Bool) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Bool) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Bool) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Bool) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Int) (A4 Bool) (B4 Int) (C4 Int) ) 
    (=>
      (and
        (let ((a!1 (= (or (not Q2)
                  (and (not R2)
                       (<= H1 1)
                       (<= 0 C2)
                       (<= 0 P1)
                       (<= 0 N1)
                       (<= 0 M1)
                       (<= 0 K1)
                       (<= 0 J1)
                       (<= 0 H1)
                       (<= 0 L1)
                       (<= 0 O1)))
              P2))
      (a!2 (= D2
              (and I1
                   (not (<= 32767 C2))
                   (not (<= 32767 P1))
                   (not (<= 32767 N1))
                   (not (<= 32767 M1))
                   (not (<= 32767 K1))
                   (not (<= 32767 J1))
                   (not (<= 32767 H1))
                   (not (<= 32767 L1))
                   (not (<= 32767 O1)))))
      (a!3 (= (or (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       M)
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       W3
                       (not M))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       P3
                       (not W3)
                       (not M))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       W2
                       (not P3)
                       (not W3)
                       (not M))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       L2
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       X
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       S
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       P
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M))
                  (and (not A)
                       (not D)
                       (not G)
                       J
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M))
                  (and (not A)
                       (not D)
                       G
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M))
                  (and (not A)
                       D
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M))
                  (and A
                       (not D)
                       (not G)
                       (not J)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)
                       (not M)))
              I1)))
  (and a!1
       (= F3 R2)
       a!2
       (= D2 G3)
       (= G3 Q2)
       (= A4 (<= 2 S2))
       (= A4 F3)
       (= E3 Z)
       (= E3 C2)
       (= A3 M1)
       (= F1 0)
       (= F1 B3)
       (= D1 0)
       (= D1 V2)
       (= B1 0)
       (= B1 T2)
       (= Y 0)
       (= Z 0)
       (= A1 1)
       (= A1 S2)
       (= C1 0)
       (= C1 U2)
       (= E1 0)
       (= E1 A3)
       (= G1 0)
       (= G1 C3)
       (= S2 H1)
       (= T2 J1)
       (= U2 K1)
       (= V2 L1)
       (= B3 N1)
       (= C3 O1)
       (= D3 Y)
       (= D3 P1)
       (or (not M) (= L K))
       (or (= J3 U) M)
       (or (not M) (= J3 L3))
       (or (= Z3 C4) W3)
       (or (not W3) (= Z3 Y3))
       (or (= U3 C) W3)
       (or (not W3) (= U3 X3))
       (or (= N3 R) P3)
       (or (not P3) (= N3 Q3))
       (or (= S3 W) P3)
       (or (not P3) (= S3 R3))
       (or (= O2 F) W2)
       (or (not W2) (= O2 X2))
       (or (= Z2 I) W2)
       (or (not W2) (= Z2 Y2))
       (or (not L2) (= F2 N2))
       (or (not L2) (= I2 M2))
       (or (= K2 I2) L2)
       (or L2 (= O2 F2))
       (or (= U3 T3) X)
       (or (not X) (= T3 V3))
       (or (not X) (= W V))
       (or (not S) (= R Q))
       (or (not S) (= U T))
       (or (= N3 M3) P)
       (or (not P) (= O N))
       (or (not P) (= M3 O3))
       (or (not J) (= I H))
       (or (not J) (= K2 K3))
       (or (= J3 K2) J)
       (or (= H3 L) G)
       (or (not G) (= H3 I3))
       (or (not G) (= F E))
       (or (not D) (= C B))
       (or (not D) (= H2 J2))
       (or (= I2 H2) D)
       (or (not A) (= C4 B4))
       (or (not A) (= E2 G2))
       (or (= F2 E2) A)
       a!3))
      )
      (state D2
       G3
       P3
       P
       X
       W3
       D
       A
       L2
       W2
       G
       J
       M
       S
       I1
       A4
       F3
       E3
       Z
       D3
       Y
       G1
       C3
       F1
       B3
       E1
       A3
       D1
       V2
       C1
       U2
       B1
       T2
       A1
       S2
       Z3
       C4
       Y3
       U3
       X3
       C
       T3
       V3
       S3
       W
       R3
       N3
       Q3
       R
       M3
       O3
       J3
       L3
       U
       K2
       K3
       H3
       I3
       L
       Q2
       R2
       C2
       P1
       O1
       N1
       M1
       Z2
       I
       Y2
       O2
       X2
       F
       L1
       K1
       J1
       H1
       P2
       F2
       N2
       I2
       M2
       H2
       J2
       E2
       G2
       V
       T
       Q
       O
       N
       K
       H
       E
       B
       B4
       Q1
       R1
       S1
       T1
       U1
       V1
       W1
       X1
       Y1
       Z1
       A2
       B2)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Bool) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Bool) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Bool) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Bool) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Int) (A4 Bool) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) (F4 Bool) (G4 Int) (H4 Int) (I4 Bool) (J4 Int) (K4 Int) (L4 Bool) (M4 Int) (N4 Int) (O4 Bool) (P4 Int) (Q4 Int) (R4 Bool) (S4 Int) (T4 Int) (U4 Bool) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Bool) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Bool) (F5 Int) (G5 Bool) (H5 Int) (I5 Bool) (J5 Int) (K5 Bool) (L5 Bool) (M5 Int) (N5 Int) (O5 Bool) (P5 Int) (Q5 Int) (R5 Bool) (S5 Int) (T5 Bool) (U5 Int) (V5 Int) (W5 Bool) (X5 Int) (Y5 Bool) (Z5 Int) (A6 Int) (B6 Int) (C6 Bool) (D6 Bool) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Bool) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Bool) (E7 Int) (F7 Int) (G7 Int) (H7 Bool) (I7 Int) (J7 Bool) (K7 Bool) (L7 Bool) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Bool) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Bool) (X7 Bool) (Y7 Int) (Z7 Int) (A8 Bool) (B8 Int) (C8 Bool) (D8 Bool) (E8 Int) (F8 Int) ) 
    (=>
      (and
        (state D2
       G3
       P3
       P
       X
       W3
       D
       A
       L2
       W2
       G
       J
       M
       S
       I1
       A4
       F3
       E3
       Z
       D3
       Y
       G1
       C3
       F1
       B3
       E1
       A3
       D1
       V2
       C1
       U2
       B1
       T2
       A1
       S2
       Z3
       F8
       Y3
       U3
       X3
       C
       T3
       V3
       S3
       W
       R3
       N3
       Q3
       R
       M3
       O3
       J3
       L3
       U
       K2
       K3
       H3
       I3
       L
       Q2
       R2
       C2
       P1
       O1
       N1
       M1
       Z2
       I
       Y2
       O2
       X2
       F
       L1
       K1
       J1
       H1
       P2
       F2
       N2
       I2
       M2
       H2
       J2
       E2
       G2
       V
       T
       Q
       O
       N
       K
       H
       E
       B
       E8
       Q1
       R1
       S1
       T1
       U1
       V1
       W1
       X1
       Y1
       Z1
       A2
       B2)
        (let ((a!1 (= (or (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4))
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       C4)
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       F4
                       (not C4))
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       I4
                       (not F4)
                       (not C4))
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       L4
                       (not I4)
                       (not F4)
                       (not C4))
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       O4
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4))
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       R4
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4))
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       U4
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4))
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       (not H7)
                       Z4
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4))
                  (and (not C8)
                       (not A8)
                       (not Q7)
                       H7
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4))
                  (and (not C8)
                       (not A8)
                       Q7
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4))
                  (and (not C8)
                       A8
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4))
                  (and C8
                       (not A8)
                       (not Q7)
                       (not H7)
                       (not Z4)
                       (not U4)
                       (not R4)
                       (not O4)
                       (not L4)
                       (not I4)
                       (not F4)
                       (not C4)))
              U6))
      (a!2 (= (or (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       W3)
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       P3
                       (not W3))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       W2
                       (not P3)
                       (not W3))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       L2
                       (not W2)
                       (not P3)
                       (not W3))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       X
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       S
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       P
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       M
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3))
                  (and (not A)
                       (not D)
                       (not G)
                       J
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3))
                  (and (not A)
                       (not D)
                       G
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3))
                  (and (not A)
                       D
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3))
                  (and A
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not S)
                       (not X)
                       (not L2)
                       (not W2)
                       (not P3)
                       (not W3)))
              I1))
      (a!3 (= (or (not K7)
                  (and (not L7)
                       (<= T6 1)
                       (<= 0 C7)
                       (<= 0 B7)
                       (<= 0 A7)
                       (<= 0 Z6)
                       (<= 0 Y6)
                       (<= 0 X6)
                       (<= 0 W6)
                       (<= 0 V6)
                       (<= 0 T6)))
              J7))
      (a!4 (= (or (not Q2)
                  (and (not R2)
                       (<= H1 1)
                       (<= 0 H1)
                       (<= 0 J1)
                       (<= 0 K1)
                       (<= 0 L1)
                       (<= 0 M1)
                       (<= 0 N1)
                       (<= 0 O1)
                       (<= 0 P1)
                       (<= 0 C2)))
              P2))
      (a!5 (or G3
               (and U6
                    (not (<= 32767 C7))
                    (not (<= 32767 B7))
                    (not (<= 32767 A7))
                    (not (<= 32767 Z6))
                    (not (<= 32767 Y6))
                    (not (<= 32767 X6))
                    (not (<= 32767 W6))
                    (not (<= 32767 V6))
                    (not (<= 32767 T6)))))
      (a!6 (or (not E5) (= (+ E3 (* (- 1) D5)) (- 1))))
      (a!7 (or (not E5) (= (+ V2 (* (- 1) G4)) 1)))
      (a!8 (or (not G5) (= (+ E3 (* (- 1) F5)) (- 1))))
      (a!9 (or (not G5) (= (+ B3 (* (- 1) A6)) 1)))
      (a!10 (or (not I5) (= (+ E3 (* (- 1) H5)) (- 1))))
      (a!11 (or (not I5) (= (+ C3 (* (- 1) M4)) 1)))
      (a!12 (or (not K5) (= (+ E3 (* (- 1) J5)) (- 1))))
      (a!13 (or (not K5) (= (+ D3 (* (- 1) P4)) 1)))
      (a!14 (or (not L5) (= (+ E3 (* (- 1) V4)) 1)))
      (a!15 (or (not L5) (= (+ T2 (* (- 1) W4)) (- 1))))
      (a!16 (or (not O5) (= (+ T2 (* (- 1) P5)) (- 1))))
      (a!17 (or (not O5) (= (+ S2 (* (- 1) S4)) 1)))
      (a!18 (or (not R5) (= (+ U2 (* (- 1) S5)) (- 1))))
      (a!19 (or (not R5) (= (+ T2 (* (- 1) Q5)) 1)))
      (a!20 (or (not T5) (= (+ V2 (* (- 1) U5)) (- 1))))
      (a!21 (or (not T5) (= (+ U2 (* (- 1) A5)) 1)))
      (a!22 (or (not W5) (= (+ A3 (* (- 1) X5)) (- 1))))
      (a!23 (or (not W5) (= (+ V2 (* (- 1) V5)) 1)))
      (a!24 (or (not Y5) (= (+ B3 (* (- 1) Z5)) (- 1))))
      (a!25 (or (not Y5) (= (+ A3 (* (- 1) D4)) 1)))
      (a!26 (or (not C6) (= (+ C3 (* (- 1) E6)) (- 1))))
      (a!27 (or (not C6) (= (+ B3 (* (- 1) B6)) 1)))
      (a!28 (or (not D6) (= (+ D3 (* (- 1) F6)) (- 1))))
      (a!29 (or (not D6) (= (+ B3 (* (- 1) J4)) 1))))
  (and (= (<= 1 D3) K5)
       (= (<= 1 C3) I5)
       (= (<= 1 B3) G5)
       (= (<= 1 B3) C6)
       (= (<= 1 B3) D6)
       (= (<= 1 A3) Y5)
       (= (<= 1 V2) E5)
       (= (<= 1 V2) W5)
       (= (<= 1 U2) T5)
       (= (<= 1 T2) R5)
       (= (<= 1 S2) O5)
       a!1
       a!2
       a!3
       a!4
       (= D7 a!5)
       (= W7 L7)
       (= W7 D8)
       (= X7 D7)
       (= X7 K7)
       (= D8 (<= 2 M7))
       (= A4 (<= 2 S2))
       (= A4 F3)
       (= G3 Q2)
       (= F3 R2)
       (= D2 G3)
       (= C5 B5)
       (= C5 U7)
       (= N5 M5)
       (= N5 V7)
       (= G6 Q4)
       (= I6 H6)
       (= K6 J6)
       (= M6 L6)
       (= O6 N6)
       (= Q6 P6)
       (= S6 R6)
       (= M7 G6)
       (= M7 T6)
       (= N7 I6)
       (= N7 V6)
       (= O7 K6)
       (= O7 W6)
       (= P7 M6)
       (= P7 X6)
       (= R7 O6)
       (= R7 Y6)
       (= S7 Q6)
       (= S7 Z6)
       (= T7 S6)
       (= T7 A7)
       (= U7 B7)
       (= V7 C7)
       (= E3 C2)
       (= E3 Z)
       (= D3 P1)
       (= D3 Y)
       (= C3 O1)
       (= B3 N1)
       (= A3 M1)
       (= V2 L1)
       (= U2 K1)
       (= T2 J1)
       (= S2 H1)
       (= G1 C3)
       (= F1 B3)
       (= E1 A3)
       (= D1 V2)
       (= C1 U2)
       (= B1 T2)
       (= A1 S2)
       (or (not C4) (= B4 D4))
       (or (not C4) (= Z5 P6))
       (or C4 (= E7 P6))
       (or C4 (= A3 B4))
       (or (not F4) (= E4 G4))
       (or (not F4) (= D5 M5))
       (or F4 (= F7 M5))
       (or F4 (= V2 E4))
       (or (not I4) (= H4 J4))
       (or I4 (= B5 N4))
       (or (not I4) (= F6 B5))
       (or I4 (= B3 H4))
       (or (not L4) (= K4 M4))
       (or (not L4) (= H5 G7))
       (or L4 (= Y7 G7))
       (or L4 (= C3 K4))
       (or (not O4) (= N4 P4))
       (or (not O4) (= J5 Y7))
       (or O4 (= Y7 T4))
       (or O4 (= D3 N4))
       (or (not R4) (= Q4 S4))
       (or (not R4) (= P5 H6))
       (or R4 (= Z7 H6))
       (or R4 (= S2 Q4))
       (or (not U4) (= T4 V4))
       (or (not U4) (= X4 W4))
       (or U4 (= E3 T4))
       (or U4 (= T2 X4))
       (or (not Z4) (= Y4 A5))
       (or (not Z4) (= U5 L6))
       (or Z4 (= B8 L6))
       (or Z4 (= U2 Y4))
       a!6
       a!7
       (or E5 (= E3 D5))
       (or E5 (= V2 G4))
       a!8
       a!9
       (or G5 (= E3 F5))
       (or G5 (= B3 A6))
       a!10
       a!11
       (or I5 (= E3 H5))
       (or I5 (= C3 M4))
       a!12
       a!13
       (or K5 (= E3 J5))
       (or K5 (= D3 P4))
       a!14
       a!15
       (or L5 (= E3 V4))
       (or L5 (= T2 W4))
       a!16
       a!17
       (or O5 (= T2 P5))
       (or O5 (= S2 S4))
       a!18
       a!19
       (or R5 (= U2 S5))
       (or R5 (= T2 Q5))
       a!20
       a!21
       (or T5 (= V2 U5))
       (or T5 (= U2 A5))
       a!22
       a!23
       (or W5 (= A3 X5))
       (or W5 (= V2 V5))
       a!24
       a!25
       (or Y5 (= B3 Z5))
       (or Y5 (= A3 D4))
       a!26
       a!27
       (or C6 (= C3 E6))
       (or C6 (= B3 B6))
       a!28
       a!29
       (or D6 (= D3 F6))
       (or D6 (= B3 J4))
       (or (not H7) (= F5 F7))
       (or (not H7) (= E7 A6))
       (or H7 (= G7 F7))
       (or H7 (= I7 E7))
       (or Q7 (= K4 R6))
       (or (not Q7) (= B6 I7))
       (or (not Q7) (= R6 E6))
       (or Q7 (= I7 H4))
       (or A8 (= Y4 J6))
       (or (not A8) (= Q5 Z7))
       (or (not A8) (= J6 S5))
       (or A8 (= Z7 X4))
       (or C8 (= B4 N6))
       (or (not C8) (= V5 B8))
       (or (not C8) (= N6 X5))
       (or C8 (= B8 E4))
       (or W3 (= Z3 F8))
       (or (not W3) (= Z3 Y3))
       (or (not W3) (= U3 X3))
       (or W3 (= U3 C))
       (or (not P3) (= S3 R3))
       (or P3 (= S3 W))
       (or (not P3) (= N3 Q3))
       (or P3 (= N3 R))
       (or (not W2) (= Z2 Y2))
       (or W2 (= Z2 I))
       (or (not W2) (= O2 X2))
       (or W2 (= O2 F))
       (or L2 (= O2 F2))
       (or L2 (= K2 I2))
       (or (not L2) (= I2 M2))
       (or (not L2) (= F2 N2))
       (or X (= U3 T3))
       (or (not X) (= T3 V3))
       (or P (= N3 M3))
       (or (not P) (= M3 O3))
       (or (not M) (= J3 L3))
       (or M (= J3 U))
       (or J (= J3 K2))
       (or (not J) (= K2 K3))
       (or (not G) (= H3 I3))
       (or G (= H3 L))
       (or D (= I2 H2))
       (or (not D) (= H2 J2))
       (or A (= F2 E2))
       (or (not A) (= E2 G2))
       (= (<= 1 E3) L5)))
      )
      (state D7
       X7
       A8
       R4
       Z4
       C8
       F4
       C4
       H7
       Q7
       I4
       L4
       O4
       U4
       U6
       D8
       W7
       V7
       N5
       U7
       C5
       S6
       T7
       Q6
       S7
       O6
       R7
       M6
       P7
       K6
       O7
       I6
       N7
       G6
       M7
       N6
       B4
       X5
       B8
       V5
       E4
       L6
       U5
       J6
       Y4
       S5
       Z7
       Q5
       X4
       H6
       P5
       Y7
       J5
       T4
       G7
       H5
       B5
       F6
       N4
       K7
       L7
       C7
       B7
       A7
       Z6
       Y6
       R6
       K4
       E6
       I7
       B6
       H4
       X6
       W6
       V6
       T6
       J7
       E7
       A6
       F7
       F5
       M5
       D5
       P6
       Z5
       A5
       V4
       W4
       Q4
       S4
       P4
       M4
       J4
       G4
       D4
       O5
       R5
       T5
       W5
       E5
       Y5
       G5
       C6
       D6
       I5
       K5
       L5)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Bool) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Bool) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Bool) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Bool) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Int) (A4 Bool) (B4 Int) (C4 Int) ) 
    (=>
      (and
        (state D2
       G3
       P3
       P
       X
       W3
       D
       A
       L2
       W2
       G
       J
       M
       S
       I1
       A4
       F3
       E3
       Z
       D3
       Y
       G1
       C3
       F1
       B3
       E1
       A3
       D1
       V2
       C1
       U2
       B1
       T2
       A1
       S2
       Z3
       C4
       Y3
       U3
       X3
       C
       T3
       V3
       S3
       W
       R3
       N3
       Q3
       R
       M3
       O3
       J3
       L3
       U
       K2
       K3
       H3
       I3
       L
       Q2
       R2
       C2
       P1
       O1
       N1
       M1
       Z2
       I
       Y2
       O2
       X2
       F
       L1
       K1
       J1
       H1
       P2
       F2
       N2
       I2
       M2
       H2
       J2
       E2
       G2
       V
       T
       Q
       O
       N
       K
       H
       E
       B
       B4
       Q1
       R1
       S1
       T1
       U1
       V1
       W1
       X1
       Y1
       Z1
       A2
       B2)
        (not P2)
      )
      false
    )
  )
)

(check-sat)
(exit)
