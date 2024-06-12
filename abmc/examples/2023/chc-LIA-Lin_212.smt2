; ./prepared/vmt/./lustre/rtp_vt_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Bool Bool Bool Bool Int Int Int Int Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Bool) (I Int) (J Int) (K Bool) (L Bool) (M Int) (N Int) (O Bool) (P Int) (Q Int) (R Bool) (S Int) (T Int) (U Bool) (V Int) (W Int) (X Int) (Y Int) (Z Bool) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Bool) (L3 Bool) (M3 Bool) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Bool) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) (F4 Int) (G4 Bool) (H4 Int) (I4 Int) ) 
    (=>
      (and
        (let ((a!1 (= (or (not F3) (not (<= 2 P2))) H2))
      (a!2 (= (or (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       C4)
                  (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       V3
                       (not C4))
                  (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       G3
                       (not V3)
                       (not C4))
                  (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       J2
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       G
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       D
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       A
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not Z)
                       (not U)
                       (not R)
                       (not O)
                       K
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not Z)
                       (not U)
                       (not R)
                       O
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not Z)
                       (not U)
                       R
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not Z)
                       U
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and Z
                       (not U)
                       (not R)
                       (not O)
                       (not K)
                       (not A)
                       (not D)
                       (not G)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4)))
              J1)))
  (and a!1
       (= (or (not F3) (<= 0 P2)) F2)
       (= (or (not F3) L) G2)
       (= (or (not F3) H) E2)
       (= (and E2 F2 G2 H2) D2)
       (= M3 F3)
       (= L3 K3)
       (= K1 M3)
       (= K1 J1)
       (= G4 (<= 2 O2))
       (= G4 L3)
       (= A3 Z2)
       (= Y2 X2)
       (= U2 T2)
       (= I1 0)
       (= I1 A3)
       (= G1 0)
       (= G1 W2)
       (= E1 0)
       (= E1 S2)
       (= A1 0)
       (= B1 0)
       (= C1 1)
       (= C1 O2)
       (= D1 0)
       (= D1 Q2)
       (= F1 0)
       (= F1 U2)
       (= H1 0)
       (= H1 Y2)
       (= O2 N2)
       (= Q2 P2)
       (= S2 R2)
       (= W2 V2)
       (= C3 B3)
       (= C3 A1)
       (= E3 D3)
       (= E3 B1)
       (or (= F4 I4) C4)
       (or (not C4) (= F4 E4))
       (or (not C4) (= A4 D4))
       (or (= A4 C) C4)
       (or (not V3) (= Y3 X3))
       (or (= Y3 Y) V3)
       (or (not V3) (= T3 W3))
       (or (= T3 T) V3)
       (or (= M2 F) G3)
       (or (not G3) (= M2 H3))
       (or (= J3 J) G3)
       (or (not G3) (= J3 I3))
       (or (not J2) (= M1 L2))
       (or (not J2) (= P1 K2))
       (or (= I2 P1) J2)
       (or J2 (= M2 M1))
       (or (not G) (= F E))
       (or (= N3 N) G)
       (or (not G) (= N3 O3))
       (or (not D) (= O1 C2))
       (or (not D) (= C B))
       (or (= P1 O1) D)
       (or (not A) (= L1 N1))
       (or (not A) (= I4 H4))
       (or (= M1 L1) A)
       (or (not K) (= J I))
       (or (not K) (= I2 Q3))
       (or K (= P3 I2))
       (or (not O) (= N M))
       (or O (= P3 W))
       (or (not O) (= P3 R3))
       (or (not R) (= Q P))
       (or (not R) (= S3 U3))
       (or R (= T3 S3))
       (or (not U) (= T S))
       (or (not U) (= W V))
       (or Z (= A4 Z3))
       (or (not Z) (= Z3 B4))
       (or (not Z) (= Y X))
       (= L true)
       (= H true)
       a!2))
      )
      (state K1
       M3
       V3
       R
       Z
       C4
       D
       A
       J2
       G3
       G
       K
       O
       U
       J1
       G4
       L3
       E3
       B1
       C3
       A1
       I1
       A3
       H1
       Y2
       G1
       W2
       F1
       U2
       E1
       S2
       D1
       Q2
       C1
       O2
       F4
       I4
       E4
       A4
       D4
       C
       Z3
       B4
       Y3
       Y
       X3
       T3
       W3
       T
       S3
       U3
       P3
       R3
       W
       I2
       Q3
       N3
       O3
       N
       F3
       K3
       P2
       H2
       L
       G2
       F2
       J3
       J
       I3
       M2
       H3
       F
       H
       E2
       D3
       B3
       Z2
       X2
       V2
       T2
       R2
       N2
       M1
       L2
       P1
       K2
       D2
       O1
       C2
       L1
       N1
       X
       V
       S
       Q
       P
       M
       I
       E
       B
       H4
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
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Bool) (I Int) (J Int) (K Bool) (L Bool) (M Int) (N Int) (O Bool) (P Int) (Q Int) (R Bool) (S Int) (T Int) (U Bool) (V Int) (W Int) (X Int) (Y Int) (Z Bool) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Bool) (L3 Bool) (M3 Bool) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Bool) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) (F4 Int) (G4 Bool) (H4 Int) (I4 Bool) (J4 Int) (K4 Int) (L4 Bool) (M4 Int) (N4 Int) (O4 Bool) (P4 Int) (Q4 Int) (R4 Bool) (S4 Int) (T4 Bool) (U4 Int) (V4 Bool) (W4 Int) (X4 Bool) (Y4 Int) (Z4 Int) (A5 Bool) (B5 Int) (C5 Int) (D5 Bool) (E5 Int) (F5 Int) (G5 Int) (H5 Int) (I5 Bool) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Bool) (O5 Int) (P5 Bool) (Q5 Int) (R5 Bool) (S5 Int) (T5 Bool) (U5 Bool) (V5 Int) (W5 Int) (X5 Bool) (Y5 Int) (Z5 Int) (A6 Bool) (B6 Int) (C6 Bool) (D6 Int) (E6 Int) (F6 Bool) (G6 Int) (H6 Bool) (I6 Int) (J6 Int) (K6 Int) (L6 Bool) (M6 Bool) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Bool) (D7 Bool) (E7 Int) (F7 Int) (G7 Bool) (H7 Bool) (I7 Bool) (J7 Bool) (K7 Bool) (L7 Int) (M7 Bool) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Int) (L8 Int) (M8 Bool) (N8 Int) (O8 Bool) (P8 Bool) (Q8 Int) (R8 Int) ) 
    (=>
      (and
        (state K1
       M3
       V3
       R
       Z
       C4
       D
       A
       J2
       G3
       G
       K
       O
       U
       J1
       G4
       L3
       E3
       B1
       C3
       A1
       I1
       A3
       H1
       Y2
       G1
       W2
       F1
       U2
       E1
       S2
       D1
       Q2
       C1
       O2
       F4
       R8
       E4
       A4
       D4
       C
       Z3
       B4
       Y3
       Y
       X3
       T3
       W3
       T
       S3
       U3
       P3
       R3
       W
       I2
       Q3
       N3
       O3
       N
       F3
       K3
       P2
       H2
       L
       G2
       F2
       J3
       J
       I3
       M2
       H3
       F
       H
       E2
       D3
       B3
       Z2
       X2
       V2
       T2
       R2
       N2
       M1
       L2
       P1
       K2
       D2
       O1
       C2
       L1
       N1
       X
       V
       S
       Q
       P
       M
       I
       E
       B
       Q8
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
        (let ((a!1 (= (or (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4))
                  (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       I4)
                  (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       L4
                       (not I4))
                  (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       O4
                       (not L4)
                       (not I4))
                  (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       T4
                       (not O4)
                       (not L4)
                       (not I4))
                  (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       X4
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4))
                  (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       A5
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4))
                  (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       D5
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4))
                  (and (not O8)
                       (not M8)
                       (not G8)
                       (not M7)
                       I5
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4))
                  (and (not O8)
                       (not M8)
                       (not G8)
                       M7
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4))
                  (and (not O8)
                       (not M8)
                       G8
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4))
                  (and (not O8)
                       M8
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4))
                  (and O8
                       (not M8)
                       (not G8)
                       (not M7)
                       (not I5)
                       (not D5)
                       (not A5)
                       (not X4)
                       (not T4)
                       (not O4)
                       (not L4)
                       (not I4)))
              C7))
      (a!2 (= (or (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       C4)
                  (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       V3
                       (not C4))
                  (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       G3
                       (not V3)
                       (not C4))
                  (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       J2
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       Z
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       U
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       R
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not A)
                       (not D)
                       (not G)
                       (not K)
                       O
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not A)
                       (not D)
                       (not G)
                       K
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not A)
                       (not D)
                       G
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and (not A)
                       D
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4))
                  (and A
                       (not D)
                       (not G)
                       (not K)
                       (not O)
                       (not R)
                       (not U)
                       (not Z)
                       (not J2)
                       (not G3)
                       (not V3)
                       (not C4)))
              J1))
      (a!3 (= (or (not F8) (not (<= 2 Q4))) K7))
      (a!4 (= (or (not F3) (not (<= 2 P2))) H2))
      (a!5 (= R4 (or (not (<= 0 P2)) (<= 0 Q4))))
      (a!6 (= V4 (or (<= 2 P2) (not (<= 2 Q4)))))
      (a!7 (or (not N5) (= (+ E3 (* (- 1) M5)) (- 1))))
      (a!8 (or (not N5) (= (+ U2 (* (- 1) M4)) 1)))
      (a!9 (or (not P5) (= (+ E3 (* (- 1) O5)) (- 1))))
      (a!10 (or (not P5) (= (+ Y2 (* (- 1) J6)) 1)))
      (a!11 (or (not R5) (= (+ E3 (* (- 1) Q5)) (- 1))))
      (a!12 (or (not R5) (= (+ A3 (* (- 1) U4)) 1)))
      (a!13 (or (not T5) (= (+ E3 (* (- 1) S5)) (- 1))))
      (a!14 (or (not T5) (= (+ C3 (* (- 1) Y4)) 1)))
      (a!15 (or (not U5) (= (+ E3 (* (- 1) E5)) 1)))
      (a!16 (or (not U5) (= (+ Q2 (* (- 1) F5)) (- 1))))
      (a!17 (or (not X5) (= (+ Q2 (* (- 1) Y5)) (- 1))))
      (a!18 (or (not X5) (= (+ O2 (* (- 1) B5)) 1)))
      (a!19 (or (not A6) (= (+ S2 (* (- 1) B6)) (- 1))))
      (a!20 (or (not A6) (= (+ Q2 (* (- 1) Z5)) 1)))
      (a!21 (or (not C6) (= (+ U2 (* (- 1) D6)) (- 1))))
      (a!22 (or (not C6) (= (+ S2 (* (- 1) J5)) 1)))
      (a!23 (or (not F6) (= (+ W2 (* (- 1) G6)) (- 1))))
      (a!24 (or (not F6) (= (+ U2 (* (- 1) E6)) 1)))
      (a!25 (or (not H6) (= (+ Y2 (* (- 1) I6)) (- 1))))
      (a!26 (or (not H6) (= (+ W2 (* (- 1) J4)) 1)))
      (a!27 (or (not L6) (= (+ A3 (* (- 1) N6)) (- 1))))
      (a!28 (or (not L6) (= (+ Y2 (* (- 1) K6)) 1)))
      (a!29 (or (not M6) (= (+ C3 (* (- 1) O6)) (- 1))))
      (a!30 (or (not M6) (= (+ Y2 (* (- 1) P4)) 1))))
  (and (= (<= 1 C3) T5)
       (= (<= 1 A3) R5)
       (= (<= 1 Y2) P5)
       (= (<= 1 Y2) L6)
       (= (<= 1 Y2) M6)
       (= (<= 1 W2) H6)
       (= (<= 1 U2) N5)
       (= (<= 1 U2) F6)
       (= (<= 1 S2) C6)
       (= (<= 1 Q2) A6)
       (= (<= 1 O2) X5)
       a!1
       a!2
       a!3
       (= (or (not F8) (<= 0 Q4)) I7)
       (= (or (not F8) R4) H7)
       (= (or (not F8) V4) J7)
       a!4
       (= (or (not F3) (<= 0 P2)) F2)
       (= (or L (not F3)) G2)
       (= (or H (not F3)) E2)
       (= (and K7 J7 I7 H7) G7)
       (= (and E2 F2 G2 H2) D2)
       a!5
       a!6
       (= D7 (and M3 C7))
       (= I8 H8)
       (= I8 P8)
       (= J8 D7)
       (= J8 F8)
       (= P8 (<= 2 P7))
       (= G4 (<= 2 O2))
       (= G4 L3)
       (= M3 F3)
       (= L3 K3)
       (= K1 M3)
       (= L5 K5)
       (= L5 C8)
       (= W5 V5)
       (= W5 E8)
       (= P6 Z4)
       (= R6 Q6)
       (= T6 S6)
       (= V6 U6)
       (= X6 W6)
       (= Z6 Y6)
       (= B7 A7)
       (= P7 P6)
       (= P7 O7)
       (= Q7 Q4)
       (= Q7 R6)
       (= S7 T6)
       (= S7 R7)
       (= U7 V6)
       (= U7 T7)
       (= W7 X6)
       (= W7 V7)
       (= Y7 Z6)
       (= Y7 X7)
       (= A8 B7)
       (= A8 Z7)
       (= C8 B8)
       (= E8 D8)
       (= E3 D3)
       (= E3 B1)
       (= C3 B3)
       (= C3 A1)
       (= A3 Z2)
       (= Y2 X2)
       (= W2 V2)
       (= U2 T2)
       (= S2 R2)
       (= Q2 P2)
       (= O2 N2)
       (= I1 A3)
       (= H1 Y2)
       (= G1 W2)
       (= F1 U2)
       (= E1 S2)
       (= D1 Q2)
       (= C1 O2)
       (or (not I4) (= H4 J4))
       (or (not I4) (= I6 Y6))
       (or I4 (= E7 Y6))
       (or I4 (= W2 H4))
       (or (not L4) (= K4 M4))
       (or (not L4) (= M5 V5))
       (or L4 (= F7 V5))
       (or L4 (= U2 K4))
       (or (not O4) (= N4 P4))
       (or O4 (= K5 W4))
       (or (not O4) (= O6 K5))
       (or O4 (= Y2 N4))
       (or (not T4) (= S4 U4))
       (or (not T4) (= Q5 L7))
       (or T4 (= K8 L7))
       (or T4 (= A3 S4))
       (or (not X4) (= W4 Y4))
       (or (not X4) (= S5 K8))
       (or X4 (= K8 C5))
       (or X4 (= C3 W4))
       (or (not A5) (= Z4 B5))
       (or (not A5) (= Y5 Q6))
       (or A5 (= L8 Q6))
       (or A5 (= O2 Z4))
       (or (not D5) (= C5 E5))
       (or (not D5) (= G5 F5))
       (or D5 (= E3 C5))
       (or D5 (= Q2 G5))
       (or (not I5) (= H5 J5))
       (or (not I5) (= D6 U6))
       (or I5 (= N8 U6))
       (or I5 (= S2 H5))
       a!7
       a!8
       (or N5 (= E3 M5))
       (or N5 (= U2 M4))
       a!9
       a!10
       (or P5 (= E3 O5))
       (or P5 (= Y2 J6))
       a!11
       a!12
       (or R5 (= E3 Q5))
       (or R5 (= A3 U4))
       a!13
       a!14
       (or T5 (= E3 S5))
       (or T5 (= C3 Y4))
       a!15
       a!16
       (or U5 (= E3 E5))
       (or U5 (= Q2 F5))
       a!17
       a!18
       (or X5 (= Q2 Y5))
       (or X5 (= O2 B5))
       a!19
       a!20
       (or A6 (= S2 B6))
       (or A6 (= Q2 Z5))
       a!21
       a!22
       (or C6 (= U2 D6))
       (or C6 (= S2 J5))
       a!23
       a!24
       (or F6 (= W2 G6))
       (or F6 (= U2 E6))
       a!25
       a!26
       (or H6 (= Y2 I6))
       (or H6 (= W2 J4))
       a!27
       a!28
       (or L6 (= A3 N6))
       (or L6 (= Y2 K6))
       a!29
       a!30
       (or M6 (= C3 O6))
       (or M6 (= Y2 P4))
       (or (not M7) (= O5 F7))
       (or (not M7) (= E7 J6))
       (or M7 (= L7 F7))
       (or M7 (= N7 E7))
       (or G8 (= S4 A7))
       (or (not G8) (= K6 N7))
       (or (not G8) (= A7 N6))
       (or G8 (= N7 N4))
       (or M8 (= H5 S6))
       (or (not M8) (= Z5 L8))
       (or (not M8) (= S6 B6))
       (or M8 (= L8 G5))
       (or O8 (= H4 W6))
       (or (not O8) (= E6 N8))
       (or (not O8) (= W6 G6))
       (or O8 (= N8 K4))
       (or C4 (= F4 R8))
       (or (not C4) (= F4 E4))
       (or (not C4) (= A4 D4))
       (or C4 (= A4 C))
       (or (not V3) (= Y3 X3))
       (or V3 (= Y3 Y))
       (or (not V3) (= T3 W3))
       (or V3 (= T3 T))
       (or (not G3) (= J3 I3))
       (or G3 (= J3 J))
       (or (not G3) (= M2 H3))
       (or G3 (= M2 F))
       (or J2 (= M2 M1))
       (or J2 (= I2 P1))
       (or (not J2) (= P1 K2))
       (or (not J2) (= M1 L2))
       (or Z (= A4 Z3))
       (or (not Z) (= Z3 B4))
       (or R (= T3 S3))
       (or (not R) (= S3 U3))
       (or (not O) (= P3 R3))
       (or O (= P3 W))
       (or K (= P3 I2))
       (or (not K) (= I2 Q3))
       (or (not G) (= N3 O3))
       (or G (= N3 N))
       (or D (= P1 O1))
       (or (not D) (= O1 C2))
       (or A (= M1 L1))
       (or (not A) (= L1 N1))
       (= (<= 1 E3) U5)))
      )
      (state D7
       J8
       M8
       A5
       I5
       O8
       L4
       I4
       M7
       G8
       O4
       T4
       X4
       D5
       C7
       P8
       I8
       E8
       W5
       C8
       L5
       B7
       A8
       Z6
       Y7
       X6
       W7
       V6
       U7
       T6
       S7
       R6
       Q7
       P6
       P7
       W6
       H4
       G6
       N8
       E6
       K4
       U6
       D6
       S6
       H5
       B6
       L8
       Z5
       G5
       Q6
       Y5
       K8
       S5
       C5
       L7
       Q5
       K5
       O6
       W4
       F8
       H8
       Q4
       K7
       V4
       J7
       I7
       A7
       S4
       N6
       N7
       K6
       N4
       R4
       H7
       D8
       B8
       Z7
       X7
       V7
       T7
       R7
       O7
       E7
       J6
       F7
       O5
       G7
       V5
       M5
       Y6
       I6
       J5
       E5
       F5
       Z4
       B5
       Y4
       U4
       P4
       M4
       J4
       X5
       A6
       C6
       F6
       N5
       H6
       P5
       L6
       M6
       R5
       T5
       U5)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Bool) (H Bool) (I Int) (J Int) (K Bool) (L Bool) (M Int) (N Int) (O Bool) (P Int) (Q Int) (R Bool) (S Int) (T Int) (U Bool) (V Int) (W Int) (X Int) (Y Int) (Z Bool) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Bool) (L3 Bool) (M3 Bool) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Bool) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) (F4 Int) (G4 Bool) (H4 Int) (I4 Int) ) 
    (=>
      (and
        (state K1
       M3
       V3
       R
       Z
       C4
       D
       A
       J2
       G3
       G
       K
       O
       U
       J1
       G4
       L3
       E3
       B1
       C3
       A1
       I1
       A3
       H1
       Y2
       G1
       W2
       F1
       U2
       E1
       S2
       D1
       Q2
       C1
       O2
       F4
       I4
       E4
       A4
       D4
       C
       Z3
       B4
       Y3
       Y
       X3
       T3
       W3
       T
       S3
       U3
       P3
       R3
       W
       I2
       Q3
       N3
       O3
       N
       F3
       K3
       P2
       H2
       L
       G2
       F2
       J3
       J
       I3
       M2
       H3
       F
       H
       E2
       D3
       B3
       Z2
       X2
       V2
       T2
       R2
       N2
       M1
       L2
       P1
       K2
       D2
       O1
       C2
       L1
       N1
       X
       V
       S
       Q
       P
       M
       I
       E
       B
       H4
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
        (not D2)
      )
      false
    )
  )
)

(check-sat)
(exit)
