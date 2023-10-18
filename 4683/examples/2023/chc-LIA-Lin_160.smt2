; ./prepared/vmt/./lustre/MESI_3_e2_819_e8_1896_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Int Int Int Int Int Bool Int Int Int Bool Int Int Int Bool Int Int Int Bool Int Int Int Int Int Int Int Int Int Int Int Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Bool Int Int Int Int Int Int Int Int Int Bool ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Bool) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Bool) (P1 Bool) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (let ((a!1 (= (or (not N) (<= (+ K1 Q P O) 3)) M))
      (a!2 (not (= (or (and Y1 F2)
                       (and Y1 E)
                       (and F2 E)
                       (and E1 F2 E)
                       (and E1 Y1))
                   O1))))
  (and a!1
       (= P1 O1)
       (= P1 C1)
       (= C1 N)
       (= U P)
       (= S J1)
       (= R O)
       (= C2 0)
       (= C2 S)
       (= A2 0)
       (= A2 Y)
       (= Z1 0)
       (= Z1 V)
       (= X1 3)
       (= X1 B1)
       (= V T)
       (= X Q)
       (= Y W)
       (= A1 K1)
       (= B1 Z)
       (or (<= 0 Z) (= (+ A1 Z) 0))
       (or (not (<= 0 Z)) (= A1 Z))
       (or (<= 0 T) (= (+ U T) 0))
       (or (not (<= 0 T)) (= U T))
       (or (<= 0 W) (= (+ X W) 0))
       (or (not (<= 0 W)) (= X W))
       (or (<= 0 J1) (= (+ R J1) 0))
       (or (not (<= 0 J1)) (= R J1))
       (or (not U1) (= F1 0))
       (or (not U1) (= H1 0))
       (or (= D D2) E)
       (or (not E) (= D F))
       (or (= H H2) E)
       (or (not E) (= H G))
       (or (= J K2) E)
       (or (not E) (= J I))
       (or (= L B) E)
       (or (not E) (= L K))
       (or F2 (= M2 K2))
       (or (not F2) (= L2 K2))
       (or F2 (= J2 H2))
       (or (not F2) (= I2 H2))
       (or (not F2) (= G2 D2))
       (or F2 (= E2 D2))
       (or (not F2) (= B A))
       (or F2 (= C B))
       (or (not Y1) (= C T1))
       (or (not Y1) (= Q1 J2))
       (or (not Y1) (= R1 E2))
       (or (not Y1) (= S1 M2))
       (or E1 (= D1 D))
       (or E1 (= B2 L))
       (or (not E1) (= B2 N1))
       (or (not E1) (= F1 D1))
       (or E1 (= G1 H))
       (or (not E1) (= H1 G1))
       (or E1 (= M1 J))
       (or (not E1) (= M1 L1))
       (or (not V1) (= L2 0))
       (or (not V1) (= I2 1))
       (or (not V1) (= G2 0))
       (or (not W1) (= Q1 1))
       (or (not W1) (= R1 0))
       (or (not W1) (= S1 0))
       a!2))
      )
      (state P1
       O1
       X1
       A2
       Z1
       C2
       S1
       W1
       R1
       Q1
       L2
       V1
       G2
       I2
       F1
       U1
       H1
       C
       T1
       Y1
       M2
       E2
       J2
       A1
       K1
       X
       Q
       U
       P
       R
       O
       C1
       F2
       E
       E1
       B1
       Y
       V
       S
       B2
       L
       N1
       M1
       J
       L1
       G1
       H
       D1
       D
       N
       Z
       W
       T
       J1
       M
       B
       K
       K2
       I
       H2
       G
       F
       D2
       A
       I1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Bool) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Bool) (P1 Bool) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Bool) (B2 Int) (C2 Bool) (D2 Int) (E2 Bool) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Bool) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Bool) (F3 Bool) (G3 Int) (H3 Bool) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Bool) (N3 Int) (O3 Int) (P3 Int) (Q3 Bool) (R3 Bool) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Bool) (J4 Bool) (K4 Int) (L4 Bool) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Bool) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) ) 
    (=>
      (and
        (state P1
       O1
       K4
       N4
       M4
       P4
       S1
       W1
       R1
       Q1
       Y4
       V1
       T4
       V4
       F1
       U1
       H1
       C
       T1
       L4
       Z4
       R4
       W4
       A1
       K1
       X
       Q
       U
       P
       R
       O
       C1
       S4
       E
       E1
       B1
       Y
       V
       S
       O4
       L
       N1
       M1
       J
       L1
       G1
       H
       D1
       D
       N
       Z
       W
       T
       J1
       M
       B
       K
       X4
       I
       U4
       G
       F
       Q4
       A
       I1)
        (let ((a!1 (not (= (or (and J4 J2)
                       (and M3 H3)
                       (and M3 J2)
                       (and H3 J2)
                       (and J4 M3 H3))
                   E3)))
      (a!2 (not (= (or (and L4 S4)
                       (and E S4)
                       (and E L4)
                       (and E1 L4)
                       (and E E1 S4))
                   O1)))
      (a!3 (= (or (not R3) (<= (+ V3 U3 T3 S3) 3)) Q3))
      (a!4 (= (or (not N) (<= (+ K1 Q P O) 3)) M))
      (a!5 (or (not Y1) (= (+ V (* (- 1) P2)) 1)))
      (a!6 (or (not Y1) (= (+ S (* (- 1) X1)) 1)))
      (a!7 (or (not A2) (= (+ Y V S (* (- 1) F2)) 2)))
      (a!8 (or (not A2) (= (+ B1 (* (- 1) U2)) 1)))
      (a!9 (or (not C2) (= (+ B1 Y V S (* (- 1) G2)) 1)))
      (a!10 (or (not E2) (= (+ B1 Y V S (* (- 1) H2)) 1))))
  (and (= (<= 1 B1) E2)
       (= (<= 1 Y) C2)
       (= (<= 1 V) Y1)
       a!1
       a!2
       a!3
       a!4
       (= F3 (and C1 E3))
       (= I4 F3)
       (= I4 R3)
       (= P1 C1)
       (= C1 N)
       (= P4 S)
       (= N4 Y)
       (= M4 V)
       (= K4 B1)
       (= X2 W2)
       (= Z2 Y2)
       (= B3 A3)
       (= D3 C3)
       (= S3 X3)
       (= T3 A4)
       (= U3 D4)
       (= V3 G4)
       (= Y3 X2)
       (= Y3 W3)
       (= B4 Z2)
       (= B4 Z3)
       (= E4 B3)
       (= E4 C4)
       (= H4 D3)
       (= H4 F4)
       (= B1 Z)
       (= A1 K1)
       (= Y W)
       (= X Q)
       (= V T)
       (= U P)
       (= S J1)
       (= R O)
       (or (<= 0 W3) (= (+ X3 W3) 0))
       (or (not (<= 0 W3)) (= X3 W3))
       (or (<= 0 Z3) (= (+ A4 Z3) 0))
       (or (not (<= 0 Z3)) (= A4 Z3))
       (or (<= 0 C4) (= (+ D4 C4) 0))
       (or (not (<= 0 C4)) (= D4 C4))
       (or (<= 0 F4) (= (+ G4 F4) 0))
       (or (not (<= 0 F4)) (= G4 F4))
       (or (<= 0 J1) (= (+ R J1) 0))
       (or (not (<= 0 J1)) (= R J1))
       (or (<= 0 Z) (= (+ A1 Z) 0))
       (or (not (<= 0 Z)) (= A1 Z))
       (or (<= 0 W) (= (+ X W) 0))
       (or (not (<= 0 W)) (= X W))
       (or (<= 0 T) (= (+ U T) 0))
       (or (not (<= 0 T)) (= U T))
       (or S4 (= Z4 X4))
       (or (not S4) (= Y4 X4))
       (or S4 (= W4 U4))
       (or (not S4) (= V4 U4))
       (or (not S4) (= T4 Q4))
       (or S4 (= R4 Q4))
       (or S4 (= C B))
       (or (not S4) (= B A))
       a!5
       a!6
       (or Y1 (= B1 V2))
       (or (not Y1) (= B1 V2))
       (or Y1 (= Y S2))
       (or (not Y1) (= Y S2))
       (or Y1 (= V P2))
       (or Y1 (= S X1))
       a!7
       a!8
       (or (not A2) (= Z1 0))
       (or (not A2) (= Q2 0))
       (or A2 (= B1 U2))
       (or A2 (= Y F2))
       (or A2 (= V Q2))
       (or A2 (= S Z1))
       a!9
       (or (not C2) (= B2 0))
       (or (not C2) (= R2 1))
       (or (not C2) (= T2 0))
       (or C2 (= B1 G2))
       (or C2 (= Y T2))
       (or C2 (= V R2))
       (or C2 (= S B2))
       a!10
       (or (not E2) (= D2 0))
       (or (not E2) (= K2 1))
       (or (not E2) (= M2 0))
       (or E2 (= B1 H2))
       (or E2 (= Y M2))
       (or E2 (= V K2))
       (or E2 (= S D2))
       (or (not J2) (= I2 D2))
       (or (not J2) (= L2 K2))
       (or (not J2) (= N2 M2))
       (or (not J2) (= O2 H2))
       (or J2 (= B1 O2))
       (or J2 (= Y N2))
       (or J2 (= V L2))
       (or J2 (= S I2))
       (or (not H3) (= G3 B2))
       (or H3 (= G3 I2))
       (or H3 (= I3 L2))
       (or (not H3) (= I3 R2))
       (or H3 (= J3 N2))
       (or (not H3) (= J3 T2))
       (or (not H3) (= K3 G2))
       (or H3 (= K3 O2))
       (or (not M3) (= L3 X1))
       (or M3 (= L3 G3))
       (or (not M3) (= N3 P2))
       (or M3 (= N3 I3))
       (or (not M3) (= O3 S2))
       (or M3 (= O3 J3))
       (or (not M3) (= P3 V2))
       (or M3 (= P3 K3))
       (or (not J4) (= Z1 W2))
       (or J4 (= W2 L3))
       (or (not J4) (= Y2 Q2))
       (or (not J4) (= A3 F2))
       (or (not J4) (= C3 U2))
       (or J4 (= N3 Y2))
       (or J4 (= O3 A3))
       (or J4 (= P3 C3))
       (or (not E1) (= O4 N1))
       (or E1 (= O4 L))
       (or (not E1) (= M1 L1))
       (or E1 (= M1 J))
       (or (not E1) (= H1 G1))
       (or E1 (= G1 H))
       (or (not E1) (= F1 D1))
       (or E1 (= D1 D))
       (or (not E) (= L K))
       (or E (= L B))
       (or E (= J X4))
       (or (not E) (= J I))
       (or E (= H U4))
       (or (not E) (= H G))
       (or E (= D Q4))
       (or (not E) (= D F))
       (= (<= 1 B1) A2)))
      )
      (state F3
       E3
       D3
       B3
       Z2
       X2
       M2
       E2
       D2
       K2
       T2
       C2
       B2
       R2
       Z1
       A2
       Q2
       O2
       H2
       J2
       N2
       I2
       L2
       G4
       V3
       D4
       U3
       A4
       T3
       X3
       S3
       I4
       H3
       M3
       J4
       H4
       E4
       B4
       Y3
       C3
       P3
       U2
       A3
       O3
       F2
       Y2
       N3
       W2
       L3
       R3
       F4
       C4
       Z3
       W3
       Q3
       K3
       V2
       J3
       S2
       I3
       P2
       X1
       G3
       G2
       Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Bool) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Bool) (P1 Bool) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (state P1
       O1
       X1
       A2
       Z1
       C2
       S1
       W1
       R1
       Q1
       L2
       V1
       G2
       I2
       F1
       U1
       H1
       C
       T1
       Y1
       M2
       E2
       J2
       A1
       K1
       X
       Q
       U
       P
       R
       O
       C1
       F2
       E
       E1
       B1
       Y
       V
       S
       B2
       L
       N1
       M1
       J
       L1
       G1
       H
       D1
       D
       N
       Z
       W
       T
       J1
       M
       B
       K
       K2
       I
       H2
       G
       F
       D2
       A
       I1)
        (not M)
      )
      false
    )
  )
)

(check-sat)
(exit)
