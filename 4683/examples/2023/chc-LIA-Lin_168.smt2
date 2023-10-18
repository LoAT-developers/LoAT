; ./prepared/vmt/./lustre/DRAGON_all_000.smt2
(set-logic HORN)


(declare-fun |state| ( Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Int Int Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Int) (R Bool) (S Int) (T Bool) (U Int) (V Bool) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Bool) (C2 Bool) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Bool) (Z2 Int) (A3 Int) (B3 Bool) (C3 Int) (D3 Bool) (E3 Int) (F3 Bool) (G3 Int) (H3 Bool) (I3 Int) (J3 Bool) (K3 Int) (L3 Bool) (M3 Bool) (N3 Bool) (O3 Int) (P3 Int) (Q3 Bool) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Bool) (F4 Int) (G4 Int) (H4 Bool) (I4 Bool) ) 
    (=>
      (and
        (let ((a!1 (and I4
                (not J2)
                (<= 0 D2)
                (= (+ I2
                      (* (- 1) H2)
                      (* (- 1) G2)
                      (* (- 1) F2)
                      (* (- 1) E2)
                      (* (- 1) D2))
                   0)))
      (a!2 (= H1 (and G1 (not (<= B1 0)))))
      (a!3 (= (or (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       Z3)
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       M3
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       Y2
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       V1
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       L1
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       I
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       F
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       (not H4)
                       C
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       (not R1)
                       H4
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       (not Q3)
                       R1
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and (not C4)
                       Q3
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3))
                  (and C4
                       (not Q3)
                       (not R1)
                       (not H4)
                       (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Z3)))
              G1)))
  (and (= (or (not C2) a!1) B2)
       (= E4 (<= 2 K2))
       (= E4 P2)
       (= Q2 C2)
       (= P2 J2)
       a!2
       (= H1 Q2)
       (= O2 M)
       (= O2 H2)
       (= N2 L)
       (= N2 G2)
       (= F1 0)
       (= F1 M2)
       (= D1 0)
       (= D1 K2)
       (= L 0)
       (= N M)
       (= C1 B1)
       (= C1 N)
       (= E1 0)
       (= E1 L2)
       (= I1 B1)
       (= I1 I2)
       (= K2 D2)
       (= L2 E2)
       (= M2 F2)
       (or (not Z3) (= S3 B4))
       (or (= S3 Z1) Z3)
       (or (= Y3 P3) Z3)
       (or (not Z3) (= A4 P3))
       (or (= K1 B) M3)
       (or (not M3) (= K1 A2))
       (or (not M3) (= O1 X))
       (or M3 (= O1 E))
       (or (= U1 G4) M3)
       (or (not M3) (= U1 A1))
       (or (not M3) (= Z1 Z))
       (or (= Z1 H) M3)
       (or (not M3) (= I3 Y1))
       (or (= K3 I3) M3)
       (or (not Y2) (= G3 E3))
       (or (= X2 W2) Y2)
       (or (not Y2) (= W2 C3))
       (or (= Z2 G3) Y2)
       (or (not V1) (= W1 P1))
       (or (= U1 P1) V1)
       (or (not V1) (= O3 X1))
       (or (= O3 I3) V1)
       (or (not L1) (= J1 M1))
       (or (= K1 J1) L1)
       (or (not L1) (= N1 W))
       (or (= N1 O1) L1)
       (or (not Y) (= Z 0))
       (or (not Y) (= X 1))
       (or (not Y) (= A1 0))
       (or (not R) (= S 0))
       (or (not P) (= O 0))
       (or (not P) (= Q 0))
       (or (not I) (= H G))
       (or (not I) (= K J))
       (or (not F) (= E D))
       (or (= T2 K) F)
       (or (not F) (= T2 V2))
       (or (not C) (= B A))
       (or (not C) (= R2 U2))
       (or (= T2 R2) C)
       (or (not H4) (= G4 F4))
       (or H4 (= R2 K3))
       (or (not H4) (= K3 S2))
       (or (not T) (= U 0))
       (or (not V) (= W 1))
       (or (not R1) (= T1 U))
       (or R1 (= T1 J1))
       (or R1 (= Q1 P1))
       (or (not R1) (= Q1 S1))
       (or Q3 (= X3 W3))
       (or Q3 (= U3 T1))
       (or (not Q3) (= U3 T3))
       (or Q3 (= P3 A3))
       (or Q3 (= X2 O3))
       (or (not Q3) (= X2 R3))
       (or (not Q3) (= O A3))
       (or (not Q3) (= Z2 Q))
       (or Q3 (= S3 Z2))
       (or (not Q3) (= W3 V3))
       (or (not C4) (= D4 Y3))
       (or (not C4) (= X3 S))
       (or C4 (= X3 N1))
       (or C4 (= Y3 Q1))
       (= I4 true)
       a!3))
      )
      (state I1
       I2
       H1
       Q2
       Q3
       Y2
       Z3
       C4
       R1
       L1
       V1
       M3
       H4
       C
       F
       I
       G1
       C1
       N
       E4
       P2
       O2
       M
       N2
       L
       F1
       M2
       E1
       L2
       D1
       K2
       X3
       N1
       S
       D4
       Y3
       Q1
       S3
       Z1
       B4
       A4
       P3
       W3
       V3
       U3
       T1
       T3
       Z2
       Q
       X2
       O3
       R3
       O
       A3
       G3
       E3
       W2
       C3
       T2
       V2
       K
       R2
       U2
       K3
       S2
       C2
       J2
       H2
       G2
       F2
       E2
       D2
       I4
       B2
       U1
       G4
       A1
       O1
       E
       X
       K1
       B
       A2
       H
       Z
       I3
       Y1
       X1
       W1
       P1
       J1
       U
       S1
       W
       M1
       B1
       Y
       V
       T
       R
       P
       J
       G
       D
       A
       F4
       B3
       D3
       F3
       H3
       J3
       L3
       N3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Int) (R Bool) (S Int) (T Bool) (U Int) (V Bool) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Bool) (C2 Bool) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Bool) (Z2 Int) (A3 Int) (B3 Bool) (C3 Int) (D3 Bool) (E3 Int) (F3 Bool) (G3 Int) (H3 Bool) (I3 Int) (J3 Bool) (K3 Int) (L3 Bool) (M3 Bool) (N3 Bool) (O3 Int) (P3 Int) (Q3 Bool) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Bool) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Bool) (L4 Int) (M4 Bool) (N4 Int) (O4 Int) (P4 Bool) (Q4 Int) (R4 Int) (S4 Bool) (T4 Int) (U4 Int) (V4 Bool) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Bool) (D5 Int) (E5 Bool) (F5 Int) (G5 Bool) (H5 Int) (I5 Bool) (J5 Int) (K5 Bool) (L5 Int) (M5 Bool) (N5 Int) (O5 Bool) (P5 Bool) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Bool) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Bool) (B6 Int) (C6 Bool) (D6 Int) (E6 Int) (F6 Bool) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Bool) (X6 Bool) (Y6 Int) (Z6 Int) (A7 Int) (B7 Bool) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Bool) (H7 Int) (I7 Int) (J7 Bool) (K7 Int) (L7 Int) (M7 Int) (N7 Bool) (O7 Int) (P7 Bool) (Q7 Bool) (R7 Int) (S7 Bool) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Bool) (Z7 Bool) (A8 Int) (B8 Int) (C8 Int) (D8 Bool) (E8 Int) (F8 Int) (G8 Bool) (H8 Int) (I8 Int) (J8 Int) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Int) (O8 Int) (P8 Int) (Q8 Bool) (R8 Bool) ) 
    (=>
      (and
        (state I1
       I2
       H1
       Q2
       Q3
       Y2
       Z3
       C4
       R1
       L1
       V1
       M3
       Q8
       C
       F
       I
       G1
       C1
       N
       E4
       P2
       O2
       M
       N2
       L
       F1
       M2
       E1
       L2
       D1
       K2
       X3
       N1
       S
       D4
       Y3
       Q1
       S3
       Z1
       B4
       A4
       P3
       W3
       V3
       U3
       T1
       T3
       Z2
       Q
       X2
       O3
       R3
       O
       A3
       G3
       E3
       W2
       C3
       T2
       V2
       K
       R2
       U2
       K3
       S2
       C2
       J2
       H2
       G2
       F2
       E2
       D2
       R8
       B2
       U1
       P8
       A1
       O1
       E
       X
       K1
       B
       A2
       H
       Z
       I3
       Y1
       X1
       W1
       P1
       J1
       U
       S1
       W
       M1
       B1
       Y
       V
       T
       R
       P
       J
       G
       D
       A
       O8
       B3
       D3
       F3
       H3
       J3
       L3
       N3)
        (let ((a!1 (= (or (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4))
                  (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       M4)
                  (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       P4
                       (not M4))
                  (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       S4
                       (not P4)
                       (not M4))
                  (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       V4
                       (not S4)
                       (not P4)
                       (not M4))
                  (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       B7
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4))
                  (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       G7
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4))
                  (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       J7
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4))
                  (and (not L8)
                       (not K8)
                       (not G8)
                       (not D8)
                       N7
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4))
                  (and (not L8)
                       (not K8)
                       (not G8)
                       D8
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4))
                  (and (not L8)
                       (not K8)
                       G8
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4))
                  (and (not L8)
                       K8
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4))
                  (and L8
                       (not K8)
                       (not G8)
                       (not D8)
                       (not N7)
                       (not J7)
                       (not G7)
                       (not B7)
                       (not V4)
                       (not S4)
                       (not P4)
                       (not M4)))
              W6))
      (a!2 (= (or (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       Q8)
                  (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       C4
                       (not Q8))
                  (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       Z3
                       (not C4)
                       (not Q8))
                  (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       Q3
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       M3
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       Y2
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       V1
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and (not C)
                       (not F)
                       (not I)
                       (not L1)
                       R1
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and (not C)
                       (not F)
                       (not I)
                       L1
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and (not C)
                       (not F)
                       I
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and (not C)
                       F
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8))
                  (and C
                       (not F)
                       (not I)
                       (not L1)
                       (not R1)
                       (not V1)
                       (not Y2)
                       (not M3)
                       (not Q3)
                       (not Z3)
                       (not C4)
                       (not Q8)))
              G1))
      (a!3 (and (not S7)
                K4
                (<= 0 F4)
                (= (+ R7
                      (* (- 1) J4)
                      (* (- 1) I4)
                      (* (- 1) H4)
                      (* (- 1) G4)
                      (* (- 1) F4))
                   0)))
      (a!4 (and (not J2)
                R8
                (<= 0 D2)
                (= (+ I2
                      (* (- 1) H2)
                      (* (- 1) G2)
                      (* (- 1) F2)
                      (* (- 1) E2)
                      (* (- 1) D2))
                   0)))
      (a!5 (and (<= 1 O2) (= K2 0) (= L2 0) (= M2 0) (= N2 0)))
      (a!6 (and (<= 1 O2) (<= 1 (+ N2 M2 L2 K2))))
      (a!7 (= K4
              (= (+ H2
                    G2
                    F2
                    E2
                    D2
                    (* (- 1) J4)
                    (* (- 1) I4)
                    (* (- 1) H4)
                    (* (- 1) G4)
                    (* (- 1) F4))
                 0)))
      (a!8 (= X6 (and Q2 W6 (not (<= V6 0)))))
      (a!9 (or (not C5) (= (+ O2 (* (- 1) B5)) 1)))
      (a!10 (or (not C5) (= (+ K2 (* (- 1) S5)) (- 1))))
      (a!11 (or (not E5) (= (+ N2 M2 (* (- 1) D6)) 0)))
      (a!12 (or (not E5) (= (+ L2 K2 (* (- 1) X5)) (- 1))))
      (a!13 (or (not E5) (= (+ O2 (* (- 1) D5)) 1)))
      (a!14 (or (not G5) (= (+ O2 (* (- 1) F5)) 1)))
      (a!15 (or (not G5) (= (+ N2 (* (- 1) M6)) (- 1))))
      (a!16 (or (not I5) (= (+ N2 M2 L2 K2 (* (- 1) Y5)) 0)))
      (a!17 (or (not I5) (= (+ O2 (* (- 1) H5)) 1)))
      (a!18 (or (not K5) (= (+ O2 (* (- 1) J5)) (- 1))))
      (a!19 (or (not K5) (= (+ N2 (* (- 1) N4)) 1)))
      (a!20 (or (not M5) (= (+ O2 (* (- 1) L5)) (- 1))))
      (a!21 (or (not M5) (= (+ L2 (* (- 1) Q4)) 1)))
      (a!22 (or (not O5) (= (+ O2 (* (- 1) N5)) (- 1))))
      (a!23 (or (not O5) (= (+ M2 (* (- 1) T4)) 1)))
      (a!24 (or (not P5) (= (+ O2 (* (- 1) W4)) (- 1))))
      (a!25 (or (not P5) (= (+ K2 (* (- 1) X4)) 1)))
      (a!26 (or (not V5) (= (+ N2 (* (- 1) I6)) (- 1))))
      (a!27 (or (not V5) (= (+ K2 (* (- 1) U5)) 1)))
      (a!28 (or (not A6) (= (+ N2 (* (- 1) L6)) (- 1))))
      (a!29 (or (not C6) (= (+ M2 L2 (* (- 1) B6)) 1)))
      (a!30 (or (not F6) (= (+ N2 (* (- 1) K6)) (- 1)))))
  (and (= (<= 1 M2) O5)
       (= (<= 1 L2) M5)
       (= (<= 1 K2) P5)
       (= (<= 1 K2) V5)
       a!1
       a!2
       (= (or (not Q7) a!3) P7)
       (= (or (not C2) a!4) B2)
       (= a!5 C5)
       (= a!5 G5)
       (= a!6 E5)
       (= a!6 I5)
       a!7
       (= A6 (and (= L2 1) (= M2 0)))
       (= C6 (<= 2 (+ M2 L2)))
       (= F6 (and (= L2 0) (= M2 1)))
       a!8
       (= Y7 S7)
       (= Y7 M8)
       (= Z7 X6)
       (= Z7 Q7)
       (= M8 (<= 2 T7))
       (= E4 (<= 2 K2))
       (= E4 P2)
       (= Q2 C2)
       (= P2 J2)
       (= H1 Q2)
       (= A5 Z4)
       (= A5 W7)
       (= R5 Q5)
       (= R5 X7)
       (= Q6 P6)
       (= S6 R6)
       (= U6 T6)
       (= R7 Y6)
       (= T7 F4)
       (= T7 Q6)
       (= U7 G4)
       (= U7 S6)
       (= V7 H4)
       (= V7 U6)
       (= W7 I4)
       (= X7 J4)
       (= N8 O6)
       (= O2 H2)
       (= O2 M)
       (= N2 G2)
       (= N2 L)
       (= M2 F2)
       (= L2 E2)
       (= K2 D2)
       (= I2 Y6)
       (= I1 I2)
       (= F1 M2)
       (= E1 L2)
       (= D1 K2)
       (= C1 N)
       (= N O6)
       (or (not Q8) (= K3 S2))
       (or Q8 (= R2 K3))
       (or (not M4) (= L4 N4))
       (or (not M4) (= J5 M7))
       (or M4 (= A8 M7))
       (or M4 (= N2 L4))
       (or (not P4) (= O4 Q4))
       (or (not P4) (= L5 A8))
       (or P4 (= B8 A8))
       (or P4 (= L2 O4))
       (or (not S4) (= R4 T4))
       (or (not S4) (= N5 B8))
       (or S4 (= B8 U4))
       (or S4 (= M2 R4))
       (or (not V4) (= U4 W4))
       (or (not V4) (= Y4 X4))
       (or V4 (= O2 U4))
       (or V4 (= K2 Y4))
       a!9
       a!10
       (or C5 (= O2 B5))
       (or C5 (= K2 S5))
       a!11
       a!12
       a!13
       (or (not E5) (= T5 0))
       (or (not E5) (= J6 0))
       (or E5 (= O2 D5))
       (or E5 (= N2 J6))
       (or E5 (= M2 D6))
       (or E5 (= L2 X5))
       (or E5 (= K2 T5))
       a!14
       a!15
       (or G5 (= O2 F5))
       (or G5 (= N2 M6))
       a!16
       a!17
       (or (not I5) (= W5 0))
       (or (not I5) (= H6 1))
       (or (not I5) (= N6 0))
       (or I5 (= O2 H5))
       (or I5 (= N2 N6))
       (or I5 (= M2 H6))
       (or I5 (= L2 Y5))
       (or I5 (= K2 W5))
       a!18
       a!19
       (or K5 (= O2 J5))
       (or K5 (= N2 N4))
       a!20
       a!21
       (or M5 (= O2 L5))
       (or M5 (= L2 Q4))
       a!22
       a!23
       (or O5 (= O2 N5))
       (or O5 (= M2 T4))
       a!24
       a!25
       (or P5 (= O2 W4))
       (or P5 (= K2 X4))
       a!26
       a!27
       (or V5 (= N2 I6))
       (or V5 (= K2 U5))
       a!28
       (or (not A6) (= Z5 0))
       (or A6 (= N2 L6))
       (or A6 (= L2 Z5))
       a!29
       (or (not C6) (= G6 1))
       (or C6 (= M2 G6))
       (or C6 (= L2 B6))
       a!30
       (or (not F6) (= E6 0))
       (or F6 (= N2 K6))
       (or F6 (= M2 E6))
       (or (not B7) (= Z6 B6))
       (or B7 (= A7 Z6))
       (or (not B7) (= C7 G6))
       (or B7 (= C7 D7))
       (or (not G7) (= F7 L6))
       (or G7 (= F7 E7))
       (or (not G7) (= H7 Z5))
       (or G7 (= H7 Z6))
       (or (not J7) (= E7 M6))
       (or J7 (= I7 E7))
       (or (not J7) (= K7 F5))
       (or J7 (= K7 L7))
       (or N7 (= L4 I7))
       (or N7 (= O4 A7))
       (or N7 (= R4 D7))
       (or (not N7) (= H5 L7))
       (or (not N7) (= A7 Y5))
       (or (not N7) (= D7 H6))
       (or (not N7) (= I7 N6))
       (or N7 (= M7 L7))
       (or N7 (= O7 Y4))
       (or (not N7) (= O7 W5))
       (or (not D8) (= B5 Q5))
       (or (not D8) (= P6 S5))
       (or D8 (= C8 Q5))
       (or D8 (= E8 P6))
       (or (not G8) (= Z4 J6))
       (or (not G8) (= R6 X5))
       (or (not G8) (= T6 D6))
       (or G8 (= H7 R6))
       (or G8 (= K7 C8))
       (or (not G8) (= C8 D5))
       (or (not G8) (= E8 T5))
       (or G8 (= F8 Z4))
       (or G8 (= H8 E8))
       (or G8 (= I8 T6))
       (or K8 (= O7 H8))
       (or (not K8) (= F8 I6))
       (or (not K8) (= H8 U5))
       (or K8 (= J8 F8))
       (or L8 (= C7 I8))
       (or (not L8) (= I8 E6))
       (or (not L8) (= J8 K6))
       (or L8 (= J8 F7))
       (or (not C4) (= D4 Y3))
       (or C4 (= Y3 Q1))
       (or C4 (= X3 N1))
       (or (not C4) (= X3 S))
       (or (not Z3) (= A4 P3))
       (or Z3 (= Y3 P3))
       (or (not Z3) (= S3 B4))
       (or Z3 (= S3 Z1))
       (or Q3 (= X3 W3))
       (or (not Q3) (= W3 V3))
       (or (not Q3) (= U3 T3))
       (or Q3 (= U3 T1))
       (or Q3 (= S3 Z2))
       (or Q3 (= P3 A3))
       (or (not Q3) (= Z2 Q))
       (or (not Q3) (= X2 R3))
       (or Q3 (= X2 O3))
       (or (not Q3) (= O A3))
       (or M3 (= K3 I3))
       (or (not M3) (= I3 Y1))
       (or (not M3) (= Z1 Z))
       (or M3 (= Z1 H))
       (or M3 (= U1 P8))
       (or (not M3) (= U1 A1))
       (or (not M3) (= O1 X))
       (or M3 (= O1 E))
       (or (not M3) (= K1 A2))
       (or M3 (= K1 B))
       (or (not Y2) (= G3 E3))
       (or Y2 (= Z2 G3))
       (or Y2 (= X2 W2))
       (or (not Y2) (= W2 C3))
       (or V1 (= O3 I3))
       (or (not V1) (= O3 X1))
       (or (not V1) (= W1 P1))
       (or V1 (= U1 P1))
       (or R1 (= T1 J1))
       (or (not R1) (= T1 U))
       (or (not R1) (= Q1 S1))
       (or R1 (= Q1 P1))
       (or L1 (= N1 O1))
       (or (not L1) (= N1 W))
       (or L1 (= K1 J1))
       (or (not L1) (= J1 M1))
       (or (not F) (= T2 V2))
       (or F (= T2 K))
       (or C (= T2 R2))
       (or (not C) (= R2 U2))
       (= (<= 1 N2) K5)))
      )
      (state Y6
       R7
       X6
       Z7
       G8
       D8
       K8
       L8
       G7
       B7
       J7
       N7
       M4
       P4
       S4
       V4
       W6
       O6
       N8
       M8
       Y7
       X7
       R5
       W7
       A5
       U6
       V7
       S6
       U7
       Q6
       T7
       I8
       C7
       E6
       K6
       J8
       F7
       H8
       O7
       U5
       I6
       F8
       T6
       D6
       R6
       H7
       X5
       E8
       T5
       C8
       K7
       D5
       J6
       Z4
       P6
       S5
       Q5
       B5
       B8
       N5
       U4
       A8
       L5
       M7
       J5
       Q7
       S7
       J4
       I4
       H4
       G4
       F4
       K4
       P7
       I7
       L4
       N6
       D7
       R4
       H6
       A7
       O4
       Y5
       Y4
       W5
       L7
       H5
       F5
       M6
       E7
       Z6
       Z5
       L6
       G6
       B6
       V6
       I5
       C6
       A6
       F6
       E5
       W4
       X4
       T4
       Q4
       N4
       C5
       V5
       G5
       K5
       M5
       O5
       P5)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Bool) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Int) (R Bool) (S Int) (T Bool) (U Int) (V Bool) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Bool) (C2 Bool) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Bool) (Z2 Int) (A3 Int) (B3 Bool) (C3 Int) (D3 Bool) (E3 Int) (F3 Bool) (G3 Int) (H3 Bool) (I3 Int) (J3 Bool) (K3 Int) (L3 Bool) (M3 Bool) (N3 Bool) (O3 Int) (P3 Int) (Q3 Bool) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Bool) (F4 Int) (G4 Int) (H4 Bool) (I4 Bool) ) 
    (=>
      (and
        (state I1
       I2
       H1
       Q2
       Q3
       Y2
       Z3
       C4
       R1
       L1
       V1
       M3
       H4
       C
       F
       I
       G1
       C1
       N
       E4
       P2
       O2
       M
       N2
       L
       F1
       M2
       E1
       L2
       D1
       K2
       X3
       N1
       S
       D4
       Y3
       Q1
       S3
       Z1
       B4
       A4
       P3
       W3
       V3
       U3
       T1
       T3
       Z2
       Q
       X2
       O3
       R3
       O
       A3
       G3
       E3
       W2
       C3
       T2
       V2
       K
       R2
       U2
       K3
       S2
       C2
       J2
       H2
       G2
       F2
       E2
       D2
       I4
       B2
       U1
       G4
       A1
       O1
       E
       X
       K1
       B
       A2
       H
       Z
       I3
       Y1
       X1
       W1
       P1
       J1
       U
       S1
       W
       M1
       B1
       Y
       V
       T
       R
       P
       J
       G
       D
       A
       F4
       B3
       D3
       F3
       H3
       J3
       L3
       N3)
        (not B2)
      )
      false
    )
  )
)

(check-sat)
(exit)
