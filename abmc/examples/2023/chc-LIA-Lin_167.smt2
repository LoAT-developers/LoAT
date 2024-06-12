; ./prepared/vmt/./lustre/rtp_5_e7_3972_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Bool) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Int) (F2 Int) (G2 Int) (H2 Bool) (I2 Bool) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Bool) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Bool) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Int) (A4 Bool) (B4 Int) (C4 Int) ) 
    (=>
      (and
        (let ((a!1 (= J1 (and I1 (not (<= 32767 H1)))))
      (a!2 (= (or (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       S)
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       W3
                       (not S))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       P3
                       (not W3)
                       (not S))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       Q2
                       (not P3)
                       (not W3)
                       (not S))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       D2
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       X
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       P
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S))
                  (and (not A)
                       (not D)
                       (not G)
                       (not J)
                       M
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S))
                  (and (not A)
                       (not D)
                       (not G)
                       J
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S))
                  (and (not A)
                       (not D)
                       G
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S))
                  (and (not A)
                       D
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S))
                  (and A
                       (not D)
                       (not G)
                       (not J)
                       (not M)
                       (not P)
                       (not X)
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)
                       (not S)))
              I1)))
  (and (= (or (not I2) (<= 0 H1)) H2)
       (= G3 I2)
       (= F3 E3)
       a!1
       (= J1 G3)
       (= A4 (<= 2 K2))
       (= A4 F3)
       (= Z2 Y2)
       (= F1 0)
       (= F1 X2)
       (= D1 0)
       (= D1 P2)
       (= B1 0)
       (= B1 M2)
       (= Y 0)
       (= Z 0)
       (= A1 1)
       (= A1 K2)
       (= C1 0)
       (= C1 N2)
       (= E1 0)
       (= E1 V2)
       (= G1 0)
       (= G1 Z2)
       (= K2 J2)
       (= M2 L2)
       (= N2 H1)
       (= P2 O2)
       (= V2 U2)
       (= X2 W2)
       (= B3 Y)
       (= B3 A3)
       (= D3 Z)
       (= D3 C3)
       (or (not S) (= R Q))
       (or (not S) (= U T))
       (or (= Z3 C4) W3)
       (or (not W3) (= Z3 Y3))
       (or (not W3) (= U3 X3))
       (or (= U3 C) W3)
       (or (= S3 W) P3)
       (or (not P3) (= S3 R3))
       (or (= N3 R) P3)
       (or (not P3) (= N3 Q3))
       (or (not Q2) (= G2 R2))
       (or Q2 (= G2 F))
       (or (= T2 I) Q2)
       (or (not Q2) (= T2 S2))
       (or (not D2) (= O1 E2))
       (or (not D2) (= L1 F2))
       (or (= C2 O1) D2)
       (or D2 (= G2 L1))
       (or X (= U3 T3))
       (or (not X) (= T3 V3))
       (or (not X) (= W V))
       (or (not P) (= O N))
       (or (not P) (= M3 O3))
       (or (= N3 M3) P)
       (or (not M) (= L K))
       (or (= J3 U) M)
       (or (not M) (= J3 L3))
       (or (not J) (= I H))
       (or (not J) (= C2 K3))
       (or (= J3 C2) J)
       (or G (= H3 L))
       (or (not G) (= H3 I3))
       (or (not G) (= F E))
       (or (= O1 N1) D)
       (or (not D) (= C B))
       (or (not D) (= N1 P1))
       (or (= L1 K1) A)
       (or (not A) (= C4 B4))
       (or (not A) (= K1 M1))
       a!2))
      )
      (state J1
       G3
       P3
       P
       X
       W3
       D
       A
       D2
       Q2
       G
       J
       M
       S
       I1
       A4
       F3
       D3
       Z
       B3
       Y
       G1
       Z2
       F1
       X2
       E1
       V2
       D1
       P2
       C1
       N2
       B1
       M2
       A1
       K2
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
       C2
       K3
       H3
       I3
       L
       I2
       E3
       C3
       A3
       Y2
       W2
       U2
       T2
       I
       S2
       G2
       R2
       F
       O2
       H1
       L2
       J2
       H2
       L1
       F2
       O1
       E2
       N1
       P1
       K1
       M1
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
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Bool) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Int) (F2 Int) (G2 Int) (H2 Bool) (I2 Bool) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Bool) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Bool) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Int) (A4 Bool) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) (F4 Bool) (G4 Int) (H4 Int) (I4 Bool) (J4 Int) (K4 Int) (L4 Bool) (M4 Int) (N4 Int) (O4 Bool) (P4 Int) (Q4 Int) (R4 Bool) (S4 Int) (T4 Int) (U4 Bool) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Bool) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Bool) (F5 Int) (G5 Bool) (H5 Int) (I5 Bool) (J5 Int) (K5 Bool) (L5 Bool) (M5 Int) (N5 Int) (O5 Bool) (P5 Int) (Q5 Int) (R5 Bool) (S5 Int) (T5 Bool) (U5 Int) (V5 Int) (W5 Bool) (X5 Int) (Y5 Bool) (Z5 Int) (A6 Int) (B6 Int) (C6 Bool) (D6 Bool) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Bool) (V6 Bool) (W6 Int) (X6 Int) (Y6 Int) (Z6 Bool) (A7 Int) (B7 Bool) (C7 Bool) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Bool) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Bool) (W7 Bool) (X7 Bool) (Y7 Int) (Z7 Int) (A8 Bool) (B8 Int) (C8 Bool) (D8 Bool) (E8 Int) (F8 Int) ) 
    (=>
      (and
        (state J1
       G3
       P3
       P
       X
       W3
       D
       A
       D2
       Q2
       G
       J
       M
       S
       I1
       A4
       F3
       D3
       Z
       B3
       Y
       G1
       Z2
       F1
       X2
       E1
       V2
       D1
       P2
       C1
       N2
       B1
       M2
       A1
       K2
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
       C2
       K3
       H3
       I3
       L
       I2
       E3
       C3
       A3
       Y2
       W2
       U2
       T2
       I
       S2
       G2
       R2
       F
       O2
       H1
       L2
       J2
       H2
       L1
       F2
       O1
       E2
       N1
       P1
       K1
       M1
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       Z6
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
                       K7
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not K7)
                       (not Z6)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       Q2
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
                       D2
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
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
                       (not D2)
                       (not Q2)
                       (not P3)
                       (not W3)))
              I1))
      (a!3 (or G3 (and U6 (not (<= 32767 T6)))))
      (a!4 (or (not E5) (= (+ D3 (* (- 1) D5)) (- 1))))
      (a!5 (or (not E5) (= (+ P2 (* (- 1) G4)) 1)))
      (a!6 (or (not G5) (= (+ D3 (* (- 1) F5)) (- 1))))
      (a!7 (or (not G5) (= (+ X2 (* (- 1) A6)) 1)))
      (a!8 (or (not I5) (= (+ D3 (* (- 1) H5)) (- 1))))
      (a!9 (or (not I5) (= (+ Z2 (* (- 1) M4)) 1)))
      (a!10 (or (not K5) (= (+ D3 (* (- 1) J5)) (- 1))))
      (a!11 (or (not K5) (= (+ B3 (* (- 1) P4)) 1)))
      (a!12 (or (not L5) (= (+ D3 (* (- 1) V4)) 1)))
      (a!13 (or (not L5) (= (+ M2 (* (- 1) W4)) (- 1))))
      (a!14 (or (not O5) (= (+ M2 (* (- 1) P5)) (- 1))))
      (a!15 (or (not O5) (= (+ K2 (* (- 1) S4)) 1)))
      (a!16 (or (not R5) (= (+ N2 (* (- 1) S5)) (- 1))))
      (a!17 (or (not R5) (= (+ M2 (* (- 1) Q5)) 1)))
      (a!18 (or (not T5) (= (+ P2 (* (- 1) U5)) (- 1))))
      (a!19 (or (not T5) (= (+ N2 (* (- 1) A5)) 1)))
      (a!20 (or (not W5) (= (+ V2 (* (- 1) X5)) (- 1))))
      (a!21 (or (not W5) (= (+ P2 (* (- 1) V5)) 1)))
      (a!22 (or (not Y5) (= (+ X2 (* (- 1) Z5)) (- 1))))
      (a!23 (or (not Y5) (= (+ V2 (* (- 1) D4)) 1)))
      (a!24 (or (not C6) (= (+ Z2 (* (- 1) E6)) (- 1))))
      (a!25 (or (not C6) (= (+ X2 (* (- 1) B6)) 1)))
      (a!26 (or (not D6) (= (+ B3 (* (- 1) F6)) (- 1))))
      (a!27 (or (not D6) (= (+ X2 (* (- 1) J4)) 1))))
  (and (= (<= 1 B3) K5)
       (= (<= 1 Z2) I5)
       (= (<= 1 X2) G5)
       (= (<= 1 X2) C6)
       (= (<= 1 X2) D6)
       (= (<= 1 V2) Y5)
       (= (<= 1 P2) E5)
       (= (<= 1 P2) W5)
       (= (<= 1 N2) T5)
       (= (<= 1 M2) R5)
       (= (<= 1 K2) O5)
       a!1
       a!2
       (= (or (not C7) (<= 0 T6)) B7)
       (= (or (not I2) (<= 0 H1)) H2)
       (= V6 a!3)
       (= W7 V7)
       (= W7 D8)
       (= X7 V6)
       (= X7 C7)
       (= D8 (<= 2 E7))
       (= A4 (<= 2 K2))
       (= A4 F3)
       (= G3 I2)
       (= F3 E3)
       (= J1 G3)
       (= C5 B5)
       (= C5 S7)
       (= N5 M5)
       (= N5 U7)
       (= G6 Q4)
       (= I6 H6)
       (= K6 J6)
       (= M6 L6)
       (= O6 N6)
       (= Q6 P6)
       (= S6 R6)
       (= E7 G6)
       (= E7 D7)
       (= G7 I6)
       (= G7 F7)
       (= H7 K6)
       (= H7 T6)
       (= J7 M6)
       (= J7 I7)
       (= M7 O6)
       (= M7 L7)
       (= O7 Q6)
       (= O7 N7)
       (= Q7 S6)
       (= Q7 P7)
       (= S7 R7)
       (= U7 T7)
       (= D3 C3)
       (= D3 Z)
       (= B3 A3)
       (= B3 Y)
       (= Z2 Y2)
       (= X2 W2)
       (= V2 U2)
       (= P2 O2)
       (= N2 H1)
       (= M2 L2)
       (= K2 J2)
       (= G1 Z2)
       (= F1 X2)
       (= E1 V2)
       (= D1 P2)
       (= C1 N2)
       (= B1 M2)
       (= A1 K2)
       (or (not C4) (= B4 D4))
       (or (not C4) (= Z5 P6))
       (or C4 (= W6 P6))
       (or C4 (= V2 B4))
       (or (not F4) (= E4 G4))
       (or (not F4) (= D5 M5))
       (or F4 (= X6 M5))
       (or F4 (= P2 E4))
       (or (not I4) (= H4 J4))
       (or I4 (= B5 N4))
       (or (not I4) (= F6 B5))
       (or I4 (= X2 H4))
       (or (not L4) (= K4 M4))
       (or (not L4) (= H5 Y6))
       (or L4 (= Y7 Y6))
       (or L4 (= Z2 K4))
       (or (not O4) (= N4 P4))
       (or (not O4) (= J5 Y7))
       (or O4 (= Y7 T4))
       (or O4 (= B3 N4))
       (or (not R4) (= Q4 S4))
       (or (not R4) (= P5 H6))
       (or R4 (= Z7 H6))
       (or R4 (= K2 Q4))
       (or (not U4) (= T4 V4))
       (or (not U4) (= X4 W4))
       (or U4 (= D3 T4))
       (or U4 (= M2 X4))
       (or (not Z4) (= Y4 A5))
       (or (not Z4) (= U5 L6))
       (or Z4 (= B8 L6))
       (or Z4 (= N2 Y4))
       a!4
       a!5
       (or E5 (= D3 D5))
       (or E5 (= P2 G4))
       a!6
       a!7
       (or G5 (= D3 F5))
       (or G5 (= X2 A6))
       a!8
       a!9
       (or I5 (= D3 H5))
       (or I5 (= Z2 M4))
       a!10
       a!11
       (or K5 (= D3 J5))
       (or K5 (= B3 P4))
       a!12
       a!13
       (or L5 (= D3 V4))
       (or L5 (= M2 W4))
       a!14
       a!15
       (or O5 (= M2 P5))
       (or O5 (= K2 S4))
       a!16
       a!17
       (or R5 (= N2 S5))
       (or R5 (= M2 Q5))
       a!18
       a!19
       (or T5 (= P2 U5))
       (or T5 (= N2 A5))
       a!20
       a!21
       (or W5 (= V2 X5))
       (or W5 (= P2 V5))
       a!22
       a!23
       (or Y5 (= X2 Z5))
       (or Y5 (= V2 D4))
       a!24
       a!25
       (or C6 (= Z2 E6))
       (or C6 (= X2 B6))
       a!26
       a!27
       (or D6 (= B3 F6))
       (or D6 (= X2 J4))
       (or (not Z6) (= F5 X6))
       (or (not Z6) (= W6 A6))
       (or Z6 (= Y6 X6))
       (or Z6 (= A7 W6))
       (or K7 (= K4 R6))
       (or (not K7) (= B6 A7))
       (or (not K7) (= R6 E6))
       (or K7 (= A7 H4))
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
       (or (not Q2) (= T2 S2))
       (or Q2 (= T2 I))
       (or (not Q2) (= G2 R2))
       (or Q2 (= G2 F))
       (or D2 (= G2 L1))
       (or D2 (= C2 O1))
       (or (not D2) (= O1 E2))
       (or (not D2) (= L1 F2))
       (or X (= U3 T3))
       (or (not X) (= T3 V3))
       (or P (= N3 M3))
       (or (not P) (= M3 O3))
       (or (not M) (= J3 L3))
       (or M (= J3 U))
       (or J (= J3 C2))
       (or (not J) (= C2 K3))
       (or (not G) (= H3 I3))
       (or G (= H3 L))
       (or D (= O1 N1))
       (or (not D) (= N1 P1))
       (or A (= L1 K1))
       (or (not A) (= K1 M1))
       (= (<= 1 D3) L5)))
      )
      (state V6
       X7
       A8
       R4
       Z4
       C8
       F4
       C4
       Z6
       K7
       I4
       L4
       O4
       U4
       U6
       D8
       W7
       U7
       N5
       S7
       C5
       S6
       Q7
       Q6
       O7
       O6
       M7
       M6
       J7
       K6
       H7
       I6
       G7
       G6
       E7
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
       Y6
       H5
       B5
       F6
       N4
       C7
       V7
       T7
       R7
       P7
       N7
       L7
       R6
       K4
       E6
       A7
       B6
       H4
       I7
       T6
       F7
       D7
       B7
       W6
       A6
       X6
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
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Bool) (K Int) (L Int) (M Bool) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Int) (W Int) (X Bool) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Int) (F2 Int) (G2 Int) (H2 Bool) (I2 Bool) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Bool) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Bool) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Int) (A4 Bool) (B4 Int) (C4 Int) ) 
    (=>
      (and
        (state J1
       G3
       P3
       P
       X
       W3
       D
       A
       D2
       Q2
       G
       J
       M
       S
       I1
       A4
       F3
       D3
       Z
       B3
       Y
       G1
       Z2
       F1
       X2
       E1
       V2
       D1
       P2
       C1
       N2
       B1
       M2
       A1
       K2
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
       C2
       K3
       H3
       I3
       L
       I2
       E3
       C3
       A3
       Y2
       W2
       U2
       T2
       I
       S2
       G2
       R2
       F
       O2
       H1
       L2
       J2
       H2
       L1
       F2
       O1
       E2
       N1
       P1
       K1
       M1
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
        (not H2)
      )
      false
    )
  )
)

(check-sat)
(exit)
