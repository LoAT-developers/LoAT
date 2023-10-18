; ./prepared/vmt/./lustre/metros_3_000.smt2
(set-logic HORN)


(declare-fun |state| ( Int Int Bool Bool Int Int Int Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Int Int Bool Int Int Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Bool Bool Int Int Bool Bool Int Int Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Int) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Bool) (W Bool) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Bool) (N1 Int) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Int) (W1 Int) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Bool) (H2 Int) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) ) 
    (=>
      (and
        (and (= (+ L (* (- 1) K) (* (- 1) Q)) 0)
     (= V1 C2)
     (= V1 Q)
     (= K1 H2)
     (= K1 D)
     (= U 0)
     (= U L1)
     (= B 0)
     (= A 0)
     (= A N1)
     (= C 0)
     (= D 0)
     (= K E2)
     (= K B)
     (= L F2)
     (= L C)
     (= W1 D2)
     (= W1 J1)
     (= X1 (and P1 Q1))
     (= X1 J2)
     (= Q1 O1)
     (= P1 M1)
     (= H1 M2)
     (= J L2)
     (= I K2)
     (= J2 I2)
     (= I2 H)
     (= E G2)
     (= I1 S)
     (= M1 G)
     (= O1 F)
     (= R1 Y1)
     (= R1 I)
     (= S1 Z1)
     (= S1 H1)
     (= T1 J)
     (= T1 A2)
     (= U1 B2)
     (= U1 I1)
     (not M2)
     (not L2)
     (not K2)
     (= E true)
     (= F true)
     (= G true)
     (not S)
     (= (+ K1 (* (- 1) K) (* (- 1) J1)) 0))
      )
      (state K1
       H2
       E
       G2
       L
       F2
       K
       E2
       W1
       D2
       V1
       C2
       U1
       B2
       T1
       A2
       S1
       Z1
       R1
       Y1
       X1
       J2
       P1
       Q1
       D
       C
       B
       J1
       Q
       I1
       J
       H1
       I
       O1
       M1
       F
       A
       N1
       G
       U
       L1
       S
       M2
       L2
       K2
       I2
       H
       M
       N
       O
       P
       R
       T
       V
       W
       X
       Y
       Z
       A1
       B1
       C1
       D1
       E1
       F1
       G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Int) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Bool) (W Bool) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Bool) (N1 Int) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Int) (W1 Int) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Bool) (H2 Int) (I2 Bool) (J2 Bool) (K2 Int) (L2 Int) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Int) (Q2 Int) (R2 Bool) (S2 Bool) (T2 Bool) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Bool) (B3 Int) (C3 Bool) (D3 Int) (E3 Bool) (F3 Bool) (G3 Bool) (H3 Bool) (I3 Int) (J3 Int) (K3 Bool) (L3 Bool) (M3 Bool) (N3 Bool) (O3 Bool) (P3 Int) (Q3 Int) (R3 Bool) (S3 Bool) (T3 Int) (U3 Int) (V3 Bool) (W3 Int) (X3 Bool) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Bool) (C4 Int) (D4 Int) (E4 Bool) (F4 Bool) (G4 Bool) (H4 Bool) (I4 Bool) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Bool) (O4 Int) (P4 Bool) (Q4 Bool) (R4 Bool) (S4 Bool) (T4 Bool) (U4 Bool) (V4 Bool) (W4 Bool) (X4 Bool) (Y4 Bool) (Z4 Bool) ) 
    (=>
      (and
        (state K1
       H2
       E
       G2
       L
       F2
       K
       E2
       W1
       D2
       V1
       C2
       U1
       B2
       T1
       A2
       S1
       Z1
       R1
       Y1
       X1
       W4
       P1
       Q1
       D
       C
       B
       J1
       Q
       I1
       J
       H1
       I
       O1
       M1
       F
       A
       N1
       G
       U
       L1
       S
       Z4
       Y4
       X4
       V4
       H
       M
       N
       O
       P
       R
       T
       V
       W
       X
       Y
       Z
       A1
       B1
       C1
       D1
       E1
       F1
       G1)
        (let ((a!1 (= A3 (<= (+ H2 (* (- 1) F2)) 40)))
      (a!2 (or (not C3) (= (+ L1 (* (- 1) B3)) (- 1))))
      (a!3 (or (not C3) (= (+ L (* (- 1) W2)) (- 1))))
      (a!4 (or (not E3) (= (+ N1 (* (- 1) D3)) (- 1))))
      (a!5 (or (not E3) (= (+ K1 (* (- 1) Y2)) (- 1))))
      (a!6 (or (not F3) (= (+ K (* (- 1) U2)) (- 1))))
      (a!7 (or (not I1) (not (= (<= I3 0) P4))))
      (a!8 (or (not H1) (not (= (<= 0 I3) R4))))
      (a!9 (or (not J) (not (= (<= J3 0) T4))))
      (a!10 (or (not I) (not (= (<= 0 J3) I2)))))
  (and (= (+ T3 (* (- 1) P3) (* (- 1) I3)) 0)
       (= (+ K1 (* (- 1) K) (* (- 1) J1)) 0)
       (= (+ L (* (- 1) K) (* (- 1) Q)) 0)
       (= L2 K2)
       (= Q2 P2)
       (= V2 U2)
       (= X2 W2)
       (= Z2 Y2)
       (= P3 V2)
       (= Q3 X2)
       (= T3 Z2)
       (= U3 L2)
       (= W3 Q2)
       (= C4 J3)
       (= D4 I3)
       (= J4 C4)
       (= K4 D4)
       (= L4 P3)
       (= M4 Q3)
       (= O4 T3)
       (= W1 D2)
       (= W1 J1)
       (= V1 C2)
       (= V1 Q)
       (= K1 H2)
       (= K1 D)
       (= U L1)
       (= L F2)
       (= L C)
       (= K E2)
       (= K B)
       (= A N1)
       (= V4 H)
       (= J2 I2)
       (= O2 (and N2 M2))
       (= T2 (and S2 R2))
       a!1
       (= G3 S3)
       (= H3 O3)
       (= K3 E4)
       (= L3 (and H K3))
       (= M3 L3)
       (= N3 J2)
       (= O3 U4)
       (= R3 S4)
       (= S3 Q4)
       (= V3 O2)
       (= X3 T2)
       (= Y3 V3)
       (= Z3 X3)
       (= A4 N3)
       (= B4 R3)
       (= E4 (and Z3 Y3))
       (= F4 A4)
       (= G4 B4)
       (= H4 H3)
       (= I4 G3)
       (= N4 A3)
       (= Q4 P4)
       (= S4 R4)
       (= U4 T4)
       (= X1 (and P1 Q1))
       (= X1 W4)
       (= U1 B2)
       (= U1 I1)
       (= T1 A2)
       (= T1 J)
       (= S1 Z1)
       (= S1 H1)
       (= R1 Y1)
       (= R1 I)
       (= Q1 O1)
       (= P1 M1)
       (= O1 F)
       (= M1 G)
       (= I1 S)
       (= H1 Z4)
       (= J Y4)
       (= I X4)
       (= E G2)
       (or (= D3 P2) (not U1) (not G3))
       (or (= B3 K2) (not T1) (not H3))
       (or (not (<= 9 N1)) (not (= E3 S2)))
       (or (not (<= 9 L1)) (not (= C3 N2)))
       (or (= P2 0) (and U1 G3))
       (or (= K2 0) (and T1 H3))
       (or N2 (<= 9 L1))
       (or S2 (<= 9 N1))
       a!2
       a!3
       (or C3 (= L1 B3))
       (or C3 (= L W2))
       a!4
       a!5
       (or E3 (= N1 D3))
       (or E3 (= K1 Y2))
       a!6
       (or F3 (= K U2))
       (or (not S1) (not (= F3 R2)))
       (or S1 R2)
       (or (not R1) (not (= F3 M2)))
       (or R1 M2)
       (or I1 (= (<= 10 I3) P4))
       a!7
       a!8
       (or H1 (= R4 (<= I3 (- 10))))
       (or J (= (<= 10 J3) T4))
       a!9
       a!10
       (or I (= I2 (<= J3 (- 10))))
       (= (+ Q3 (* (- 1) P3) (* (- 1) J3)) 0)))
      )
      (state T3
       O4
       A3
       N4
       Q3
       M4
       P3
       L4
       D4
       K4
       C4
       J4
       G3
       I4
       H3
       H4
       B4
       G4
       A4
       F4
       E4
       K3
       Y3
       Z3
       Z2
       X2
       V2
       I3
       J3
       S3
       O3
       R3
       N3
       X3
       V3
       T2
       Q2
       W3
       O2
       L2
       U3
       Q4
       S4
       U4
       J2
       L3
       M3
       E3
       C3
       F3
       Y2
       W2
       U2
       R2
       S2
       D3
       P2
       M2
       N2
       B3
       K2
       P4
       R4
       T4
       I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Int) (Q Int) (R Int) (S Bool) (T Int) (U Int) (V Bool) (W Bool) (X Int) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Bool) (N1 Int) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Int) (W1 Int) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Bool) (H2 Int) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) ) 
    (=>
      (and
        (state K1
       H2
       E
       G2
       L
       F2
       K
       E2
       W1
       D2
       V1
       C2
       U1
       B2
       T1
       A2
       S1
       Z1
       R1
       Y1
       X1
       J2
       P1
       Q1
       D
       C
       B
       J1
       Q
       I1
       J
       H1
       I
       O1
       M1
       F
       A
       N1
       G
       U
       L1
       S
       M2
       L2
       K2
       I2
       H
       M
       N
       O
       P
       R
       T
       V
       W
       X
       Y
       Z
       A1
       B1
       C1
       D1
       E1
       F1
       G1)
        (not G2)
      )
      false
    )
  )
)

(check-sat)
(exit)
