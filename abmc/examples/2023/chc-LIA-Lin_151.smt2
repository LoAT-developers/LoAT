; ./prepared/vmt/./lustre/metros_1_e2_1102_e7_1163_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Int Int Int Bool Bool Bool Bool Int Int Int Int Bool Bool Int Int Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Bool Bool Bool Bool Bool Int Int Int Bool Bool Int Int Bool Bool Int Int Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Bool) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Int) (K2 Bool) (L2 Bool) (M2 Int) (N2 Bool) (O2 Int) ) 
    (=>
      (and
        (let ((a!1 (= W
              (and N2
                   (not (<= 1 S))
                   (not (<= 1 M2))
                   (not (<= 1 O2))
                   (not (<= 32767 U))))))
  (and (= (+ M1 C2 (* (- 1) K1)) 0)
       (= D2 P1)
       (= C2 N1)
       (= I 0)
       (= I J2)
       (= G 0)
       (= G I2)
       (= E 0)
       (= D 0)
       (= C 0)
       (= K1 M2)
       (= K1 C)
       (= L1 D)
       (= L1 O2)
       (= M1 E)
       (= M1 S)
       (= N1 U)
       (= P1 O1)
       (= (or (not J1) A) N)
       (= (and B2 A2) Z1)
       (= G2 V1)
       (= F2 T1)
       (= E2 R1)
       (= M H2)
       (= L F2)
       (= J E2)
       (= H L2)
       (= L2 B2)
       (= K2 A2)
       (= B Y1)
       (= F K2)
       (= K G2)
       a!1
       (= W J1)
       (= R1 Q1)
       (= T1 S1)
       (= V1 U1)
       (= X1 W1)
       (= Z1 N2)
       (= H2 X1)
       (not M)
       (not L)
       (not J)
       (= H true)
       (= A true)
       (= B true)
       (= F true)
       (not K)
       (= (+ D2 M1 (* (- 1) L1)) 0)))
      )
      (state W
       J1
       M
       H2
       L
       F2
       D2
       M1
       L1
       K
       G2
       J
       E2
       C2
       K1
       I
       J2
       H
       L2
       G
       I2
       F
       K2
       B2
       A2
       X1
       V1
       T1
       R1
       P1
       N1
       E
       D
       C
       Z1
       N2
       B
       Y1
       W1
       U1
       S1
       Q1
       O1
       U
       S
       O2
       M2
       A
       N
       O
       P
       Q
       R
       T
       V
       X
       Y
       Z
       A1
       B1
       C1
       D1
       E1
       F1
       G1
       H1
       I1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Bool) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Int) (K2 Int) (L2 Bool) (M2 Bool) (N2 Int) (O2 Bool) (P2 Bool) (Q2 Bool) (R2 Int) (S2 Bool) (T2 Bool) (U2 Bool) (V2 Bool) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Int) (C3 Int) (D3 Bool) (E3 Int) (F3 Bool) (G3 Int) (H3 Int) (I3 Bool) (J3 Bool) (K3 Bool) (L3 Bool) (M3 Int) (N3 Bool) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Bool) (Y3 Bool) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Bool) (G4 Bool) (H4 Bool) (I4 Bool) (J4 Bool) (K4 Bool) (L4 Bool) (M4 Bool) (N4 Bool) (O4 Bool) (P4 Bool) (Q4 Bool) (R4 Bool) (S4 Bool) (T4 Int) (U4 Int) (V4 Int) (W4 Bool) (X4 Int) (Y4 Int) (Z4 Bool) (A5 Bool) (B5 Int) (C5 Bool) (D5 Int) ) 
    (=>
      (and
        (state W
       J1
       M
       H2
       L
       F2
       D2
       M1
       L1
       K
       G2
       J
       E2
       C2
       K1
       I
       Y4
       H
       A5
       G
       X4
       F
       Z4
       B2
       A2
       X1
       V1
       T1
       R1
       P1
       N1
       E
       D
       C
       Z1
       C5
       B
       Y1
       W1
       U1
       S1
       Q1
       O1
       U
       S
       D5
       B5
       A
       N
       O
       P
       Q
       R
       T
       V
       X
       Y
       Z
       A1
       B1
       C1
       D1
       E1
       F1
       G1
       H1
       I1)
        (let ((a!1 (not (= (or (and Q1 S2) (and U1 T2)) U2)))
      (a!2 (or J1
               (and S3
                    (not (<= 1 U3))
                    (not (<= 1 T3))
                    (not (<= 1 R3))
                    (not (<= 32767 V3)))))
      (a!3 (or (not L2) (= (+ K1 (* (- 1) N2)) (- 1))))
      (a!4 (or (not O2) (= (+ M1 (* (- 1) R2)) (- 1))))
      (a!5 (or (not W4) (= (+ L1 (* (- 1) J2)) (- 1))))
      (a!6 (or (not H2) (not (= (<= 0 M3) O3))))
      (a!7 (or (not G2) (not (= (<= 0 H3) J3))))
      (a!8 (or (not F2) (not (= (<= M3 0) N3))))
      (a!9 (or (not E2) (not (= (<= H3 0) I3)))))
  (and (= (+ B4 H3 (* (- 1) Z3)) 0)
       (= (+ D2 M1 (* (- 1) L1)) 0)
       (= (+ M1 C2 (* (- 1) K1)) 0)
       (= A3 N2)
       (= B3 J2)
       (= C3 R2)
       (= E3 W2)
       (= G3 Y2)
       (= H3 C4)
       (= M3 E4)
       (= Z3 A3)
       (= Z3 R3)
       (= A4 B3)
       (= A4 T3)
       (= B4 C3)
       (= B4 U3)
       (= C4 V3)
       (= E4 D4)
       (= T4 E3)
       (= U4 G3)
       (= D2 P1)
       (= C2 N1)
       (= P1 O1)
       (= N1 U)
       (= M1 S)
       (= M1 E)
       (= L1 D5)
       (= L1 D)
       (= K1 B5)
       (= K1 C)
       (= I Y4)
       (= G X4)
       a!1
       (= (or (not Y3) V2) X3)
       (= (or A (not J1)) N)
       (= (and M4 L4) K4)
       (= (and A2 B2) Z1)
       (= A5 B2)
       (= Z4 A2)
       (= X2 T2)
       (= Z2 F4)
       (= D3 (and Q2 M2))
       (= F3 (and P2 I2))
       (= K3 I3)
       (= L3 J3)
       (= P3 N3)
       (= Q3 O3)
       (= W3 a!2)
       (= Y3 W3)
       (= G4 S2)
       (= I4 H4)
       (= J4 U2)
       (= K4 S3)
       (= N4 X2)
       (= N4 K3)
       (= O4 Z2)
       (= O4 P3)
       (= P4 L3)
       (= P4 G4)
       (= Q4 Q3)
       (= Q4 I4)
       (= R4 D3)
       (= R4 L4)
       (= S4 F3)
       (= S4 M4)
       (= H2 X1)
       (= G2 V1)
       (= F2 T1)
       (= E2 R1)
       (= Z1 C5)
       (= Y1 V2)
       (= X1 W1)
       (= V1 U1)
       (= T1 S1)
       (= R1 Q1)
       (= W J1)
       (= M H2)
       (= L F2)
       (= K G2)
       (= J E2)
       (= H A5)
       (= F Z4)
       (= B Y1)
       (or (= Y2 V4) (not T1) (not Z2))
       (or (= W2 K2) (not X2) (not R1))
       (or (not (<= 9 Y4)) (not (= W4 I2)))
       (or (not (<= 9 X4)) (not (= L2 M2)))
       (or (= Y2 0) (and T1 Z2))
       (or (= W2 0) (and R1 X2))
       (or I2 (<= 9 Y4))
       a!3
       (or L2 (= X4 K2))
       (or (not L2) (= X4 K2))
       (or L2 (= K1 N2))
       (or M2 (<= 9 X4))
       a!4
       (or O2 (= M1 R2))
       a!5
       (or W4 (= Y4 V4))
       (or (not W4) (= Y4 V4))
       (or W4 (= L1 J2))
       a!6
       (or H2 (= O3 (<= M3 (- 10))))
       a!7
       (or G2 (= J3 (<= H3 (- 10))))
       a!8
       (or F2 (= N3 (<= 10 M3)))
       a!9
       (or E2 (= I3 (<= 10 H3)))
       (or (not X1) (not (= O2 P2)))
       (or X1 P2)
       (or (not V1) (not (= O2 Q2)))
       (or V1 Q2)
       (= (+ M3 B4 (* (- 1) A4)) 0)))
      )
      (state W3
       Y3
       Q3
       Q4
       P3
       O4
       M3
       B4
       A4
       L3
       P4
       K3
       N4
       H3
       Z3
       G3
       U4
       F3
       S4
       E3
       T4
       D3
       R4
       M4
       L4
       I4
       G4
       Z2
       X2
       E4
       C4
       C3
       B3
       A3
       K4
       S3
       U2
       J4
       H4
       S2
       F4
       T2
       D4
       V3
       U3
       T3
       R3
       V2
       X3
       L2
       W4
       O2
       N2
       J2
       R2
       Q2
       M2
       K2
       W2
       P2
       I2
       V4
       Y2
       I3
       J3
       N3
       O3)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Bool) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Bool) (C1 Bool) (D1 Int) (E1 Int) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Int) (K2 Bool) (L2 Bool) (M2 Int) (N2 Bool) (O2 Int) ) 
    (=>
      (and
        (state W
       J1
       M
       H2
       L
       F2
       D2
       M1
       L1
       K
       G2
       J
       E2
       C2
       K1
       I
       J2
       H
       L2
       G
       I2
       F
       K2
       B2
       A2
       X1
       V1
       T1
       R1
       P1
       N1
       E
       D
       C
       Z1
       N2
       B
       Y1
       W1
       U1
       S1
       Q1
       O1
       U
       S
       O2
       M2
       A
       N
       O
       P
       Q
       R
       T
       V
       X
       Y
       Z
       A1
       B1
       C1
       D1
       E1
       F1
       G1
       H1
       I1)
        (not N)
      )
      false
    )
  )
)

(check-sat)
(exit)
