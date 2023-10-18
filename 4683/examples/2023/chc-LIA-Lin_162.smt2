; ./prepared/vmt/./lustre/MOESI_2_e3_929_e3_2294_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Bool Bool Int Int Int Int Int Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Bool Bool Int Bool ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Bool) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (let ((a!1 (not (= (or (and B2 W)
                       (and B2 C1)
                       (and J2 W)
                       (and J2 C1)
                       (and W C1)
                       (and B2 J2))
                   T1))))
  (and (= (or (not K1) D) J1)
       (= T T1)
       (= T A2)
       (= N Z1)
       (= Z1 Y1)
       (= A2 K1)
       (= O 0)
       (= O M1)
       (= P 0)
       (= P O1)
       (= Q 0)
       (= Q Q1)
       (= S R)
       (= S V1)
       (= M1 L1)
       (= O1 N1)
       (= Q1 P1)
       (= U1 0)
       (= U1 X1)
       (= V1 R1)
       (= X1 W1)
       (or (= G1 F1) C1)
       (or (= F2 I1) C1)
       (or (= E2 D2) C1)
       (or (not C1) (= D2 G2))
       (or (not C1) (= B1 G))
       (or (= B1 U) C1)
       (or (not C1) (= D1 E))
       (or (= D1 Z) C1)
       (or (not C1) (= F1 E1))
       (or (not C1) (= I1 H1))
       (or (= V U) W)
       (or (not W) (= U X))
       (or (not W) (= Z Y))
       (or (= A1 Z) W)
       (or (not M) (= M2 0))
       (or (not M) (= K2 0))
       (or (not M) (= H2 1))
       (or (not M) (= B 0))
       (or (not I) (= K 0))
       (or (not I) (= J 0))
       (or (not I) (= H 1))
       (or (not I) (= L 0))
       (or (not J2) (= N2 M2))
       (or (not J2) (= L2 K2))
       (or (not J2) (= I2 H2))
       (or (not J2) (= A O2))
       (or (not J2) (= C B))
       (or (not B2) (= G1 K))
       (or B2 (= G1 N2))
       (or (not B2) (= V J))
       (or B2 (= V L2))
       (or (not B2) (= F2 C2))
       (or B2 (= F2 A))
       (or B2 (= E2 C))
       (or (not B2) (= E2 L))
       (or (not B2) (= A1 H))
       (or B2 (= A1 I2))
       (or (not F) (= E 0))
       (or (not F) (= G 0))
       (not N)
       (= D true)
       a!1))
      )
      (state T
       A2
       J2
       B2
       W
       C1
       T1
       N
       Z1
       U1
       X1
       S
       V1
       Q
       Q1
       P
       O1
       O
       M1
       K1
       Y1
       W1
       R1
       P1
       N1
       L1
       D
       J1
       E2
       C
       L
       F2
       A
       C2
       G1
       N2
       K
       A1
       I2
       H
       V
       J
       L2
       D2
       G2
       I1
       H1
       F1
       E1
       D1
       Z
       E
       B1
       G
       U
       Y
       X
       R
       B
       M
       M2
       K2
       H2
       I
       F
       O2
       S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Bool) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Bool) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Bool) (V2 Int) (W2 Bool) (X2 Int) (Y2 Bool) (Z2 Bool) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Bool) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Bool) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) (F4 Int) (G4 Bool) (H4 Bool) (I4 Bool) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Bool) (O4 Bool) (P4 Bool) (Q4 Bool) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Bool) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) ) 
    (=>
      (and
        (state T
       B2
       Y4
       Q4
       W
       C1
       T1
       N
       A2
       U1
       Y1
       S
       W1
       Q
       Q1
       P
       O1
       O
       M1
       K1
       Z1
       X1
       R1
       P1
       N1
       L1
       D
       J1
       T4
       C
       L
       U4
       A
       R4
       G1
       C5
       K
       A1
       X4
       H
       V
       J
       A5
       S4
       V4
       I1
       H1
       F1
       E1
       D1
       Z
       E
       B1
       G
       U
       Y
       X
       R
       B
       M
       B5
       Z4
       W4
       I
       F
       D5
       S1)
        (let ((a!1 (= (<= (+ Y1 (* (- 1) Q1)) (- 1)) Y2))
      (a!2 (not (= (or (and G4 C4)
                       (and G4 Z3)
                       (and G4 J2)
                       (and C4 Z3)
                       (and C4 J2)
                       (and Z3 J2))
                   V3)))
      (a!3 (not (= (or (and W C1)
                       (and C1 Q4)
                       (and W Q4)
                       (and C1 Y4)
                       (and W Y4)
                       (and Q4 Y4))
                   T1)))
      (a!4 (= H2
              (= (+ X1
                    R1
                    P1
                    N1
                    L1
                    (* (- 1) G2)
                    (* (- 1) F2)
                    (* (- 1) E2)
                    (* (- 1) D2)
                    (* (- 1) C2))
                 0)))
      (a!5 (or (not U2) (= (+ O1 (* (- 1) C3)) 1)))
      (a!6 (or (not U2) (= (+ M1 (* (- 1) T2)) (- 1))))
      (a!7 (or (not W2) (= (+ Y1 M1 (* (- 1) B3)) 0)))
      (a!8 (or (not W2) (= (+ Q1 (* (- 1) O1) (* (- 1) F3)) (- 1))))
      (a!9 (or (not W2) (= (+ W1 (* (- 1) H3)) 1)))
      (a!10 (or (not Y2) (= (+ Y1 W1 Q1 O1 M1 (* (- 1) A3)) 1)))
      (a!11 (or (not Z2) (= (+ Y1 W1 Q1 O1 M1 (* (- 1) P2)) 1))))
  (and (= (<= 1 W1) Z2)
       (= (<= 1 O1) U2)
       a!1
       a!2
       a!3
       (= (or (not I4) H2) H4)
       (= (or D (not K1)) J1)
       a!4
       (= K3 (<= 2 J3))
       (= W3 (and B2 V3))
       (= O4 K3)
       (= O4 N4)
       (= B2 K1)
       (= A2 Z1)
       (= P4 W3)
       (= P4 I4)
       (= T B2)
       (= N A2)
       (= J3 D2)
       (= J3 O3)
       (= M3 L3)
       (= O3 N3)
       (= Q3 P3)
       (= S3 R3)
       (= U3 T3)
       (= J4 C2)
       (= J4 M3)
       (= K4 E2)
       (= K4 Q3)
       (= L4 F2)
       (= L4 S3)
       (= M4 G2)
       (= M4 U3)
       (= Y1 X1)
       (= W1 R1)
       (= U1 Y1)
       (= Q1 P1)
       (= O1 N1)
       (= M1 L1)
       (= S W1)
       (= Q Q1)
       (= P O1)
       (= O M1)
       (or (not Q4) (= U4 R4))
       (or Q4 (= U4 A))
       (or (not Q4) (= T4 L))
       (or Q4 (= T4 C))
       (or Q4 (= G1 C5))
       (or (not Q4) (= G1 K))
       (or Q4 (= A1 X4))
       (or (not Q4) (= A1 H))
       (or Q4 (= V A5))
       (or (not Q4) (= V J))
       (or (not J2) (= I2 K2))
       (or (not J2) (= M2 L2))
       (or (not J2) (= O2 N2))
       (or (not J2) (= Q2 P2))
       (or (not J2) (= S2 R2))
       (or J2 (= Y1 S2))
       (or J2 (= W1 Q2))
       (or J2 (= Q1 O2))
       (or J2 (= O1 M2))
       (or J2 (= M1 I2))
       a!5
       a!6
       (or U2 (= O1 C3))
       (or U2 (= M1 T2))
       a!7
       a!8
       a!9
       (or (not W2) (= V2 0))
       (or (not W2) (= D3 0))
       (or W2 (= Y1 B3))
       (or W2 (= W1 H3))
       (or W2 (= Q1 F3))
       (or W2 (= O1 D3))
       (or W2 (= M1 V2))
       a!10
       (or (not Y2) (= X2 0))
       (or (not Y2) (= E3 1))
       (or (not Y2) (= G3 0))
       (or (not Y2) (= I3 0))
       (or Y2 (= Y1 I3))
       (or Y2 (= W1 A3))
       (or Y2 (= Q1 G3))
       (or Y2 (= O1 E3))
       (or Y2 (= M1 X2))
       a!11
       (or (not Z2) (= K2 0))
       (or (not Z2) (= L2 1))
       (or (not Z2) (= N2 0))
       (or (not Z2) (= R2 0))
       (or Z2 (= Y1 R2))
       (or Z2 (= W1 P2))
       (or Z2 (= Q1 N2))
       (or Z2 (= O1 L2))
       (or Z2 (= M1 K2))
       (or (not Z3) (= X3 T2))
       (or Z3 (= Y3 X3))
       (or (not Z3) (= A4 C3))
       (or Z3 (= B4 A4))
       (or (not C4) (= V2 L3))
       (or C4 (= L3 X3))
       (or (not C4) (= N3 D3))
       (or (not C4) (= P3 F3))
       (or (not C4) (= R3 H3))
       (or (not C4) (= T3 B3))
       (or C4 (= A4 N3))
       (or C4 (= D4 P3))
       (or C4 (= E4 R3))
       (or C4 (= F4 T3))
       (or G4 (= M2 B4))
       (or G4 (= O2 D4))
       (or G4 (= Q2 E4))
       (or G4 (= S2 F4))
       (or (not G4) (= X2 Y3))
       (or G4 (= Y3 I2))
       (or (not G4) (= B4 E3))
       (or (not G4) (= D4 G3))
       (or (not G4) (= E4 A3))
       (or (not G4) (= F4 I3))
       (or C1 (= U4 I1))
       (or C1 (= T4 S4))
       (or (not C1) (= S4 V4))
       (or (not C1) (= I1 H1))
       (or C1 (= G1 F1))
       (or (not C1) (= F1 E1))
       (or C1 (= D1 Z))
       (or (not C1) (= D1 E))
       (or C1 (= B1 U))
       (or (not C1) (= B1 G))
       (or W (= A1 Z))
       (or (not W) (= Z Y))
       (or W (= V U))
       (or (not W) (= U X))
       (= (<= 1 W1) W2)))
      )
      (state W3
       P4
       J2
       G4
       Z3
       C4
       V3
       K3
       O4
       U3
       M4
       S3
       L4
       Q3
       K4
       O3
       J3
       M3
       J4
       I4
       N4
       G2
       F2
       E2
       D2
       C2
       H2
       H4
       F4
       S2
       I3
       E4
       Q2
       A3
       D4
       O2
       G3
       B4
       M2
       E3
       Y3
       X2
       I2
       T3
       B3
       R3
       H3
       P3
       F3
       N3
       A4
       D3
       L3
       V2
       X3
       C3
       T2
       V1
       R2
       Z2
       N2
       K2
       L2
       Y2
       W2
       P2
       U2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Bool) (E Int) (F Bool) (G Int) (H Int) (I Bool) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Int) (V Int) (W Bool) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Bool) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (state T
       A2
       J2
       B2
       W
       C1
       T1
       N
       Z1
       U1
       X1
       S
       V1
       Q
       Q1
       P
       O1
       O
       M1
       K1
       Y1
       W1
       R1
       P1
       N1
       L1
       D
       J1
       E2
       C
       L
       F2
       A
       C2
       G1
       N2
       K
       A1
       I2
       H
       V
       J
       L2
       D2
       G2
       I1
       H1
       F1
       E1
       D1
       Z
       E
       B1
       G
       U
       Y
       X
       R
       B
       M
       M2
       K2
       H2
       I
       F
       O2
       S1)
        (not J1)
      )
      false
    )
  )
)

(check-sat)
(exit)
