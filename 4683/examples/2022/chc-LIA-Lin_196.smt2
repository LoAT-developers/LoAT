; ./vmt/./lustre/MOESI_1_e2_982_e7_492_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Bool Bool Int Bool ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Bool) (I Int) (J Int) (K Int) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Int) (V Bool) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Bool) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Bool) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Bool) (C2 Bool) (D2 Int) (E2 Bool) (F2 Int) (G2 Int) (H2 Bool) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (let ((a!1 (= U1 (and T (not (<= Q 0)))))
      (a!2 (not (= (or (and H2 V)
                       (and M1 V)
                       (and M1 B1)
                       (and B1 V)
                       (and B1 H2)
                       (and M1 H2))
                   T))))
  (and (= (or (not B2) (not C2)) E2)
       a!1
       (= U1 B2)
       (= M Y1)
       (= Y1 C2)
       (= O1 N1)
       (= O 0)
       (= O O1)
       (= A2 Z1)
       (= N 0)
       (= N A2)
       (= P 0)
       (= P Q1)
       (= R Q)
       (= R V1)
       (= S 0)
       (= S X1)
       (= Q1 P1)
       (= V1 R1)
       (= X1 W1)
       (or (= U T1) V)
       (or (not V) (= Y X))
       (or (= Z Y) V)
       (or (not V) (= T1 W))
       (or (not L) (= K2 0))
       (or (not L) (= I2 0))
       (or (not L) (= F2 1))
       (or (not L) (= B 0))
       (or (not H) (= G 1))
       (or (not H) (= I 0))
       (or (not H) (= J 0))
       (or (not H) (= K 0))
       (or (not E) (= D 0))
       (or (not E) (= F 0))
       (or (not H2) (= L2 K2))
       (or (not H2) (= J2 I2))
       (or (not H2) (= G2 F2))
       (or (not H2) (= A M2))
       (or (not H2) (= C B))
       (or B1 (= L1 K1))
       (or (not B1) (= H1 G1))
       (or (not B1) (= E1 D1))
       (or (not B1) (= A1 F))
       (or B1 (= A1 T1))
       (or (not B1) (= C1 D))
       (or B1 (= C1 Y))
       (or B1 (= F1 E1))
       (or B1 (= I1 H1))
       (or (not B1) (= K1 J1))
       (or M1 (= L1 C))
       (or (not M1) (= L1 K))
       (or M1 (= U J2))
       (or (not M1) (= U I))
       (or M1 (= Z G2))
       (or (not M1) (= Z G))
       (or M1 (= F1 L2))
       (or (not M1) (= F1 J))
       (or (not M1) (= I1 D2))
       (or M1 (= I1 A))
       (not M)
       a!2))
      )
      (state U1
       B2
       H2
       M1
       V
       B1
       T
       M
       Y1
       S
       X1
       R
       V1
       P
       Q1
       O
       O1
       N
       A2
       C2
       W1
       R1
       P1
       N1
       Z1
       E2
       L1
       C
       K
       I1
       A
       D2
       F1
       L2
       J
       Z
       G2
       G
       U
       I
       J2
       K1
       J1
       H1
       G1
       E1
       D1
       C1
       Y
       D
       A1
       F
       T1
       X
       W
       Q
       B
       L
       K2
       I2
       F2
       H
       E
       M2
       S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Bool) (I Int) (J Int) (K Int) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Int) (V Bool) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Bool) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Bool) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Bool) (B2 Int) (C2 Bool) (D2 Int) (E2 Bool) (F2 Int) (G2 Bool) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Bool) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Bool) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Bool) (O3 Bool) (P3 Int) (Q3 Int) (R3 Bool) (S3 Int) (T3 Int) (U3 Bool) (V3 Int) (W3 Int) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Bool) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Bool) (M4 Int) (N4 Int) (O4 Bool) (P4 Bool) (Q4 Int) (R4 Bool) (S4 Int) (T4 Int) (U4 Bool) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) ) 
    (=>
      (and
        (state U1
       O4
       U4
       M1
       V
       B1
       T
       M
       Y1
       S
       X1
       R
       V1
       P
       Q1
       O
       O1
       N
       N4
       P4
       W1
       R1
       P1
       N1
       M4
       R4
       L1
       C
       K
       I1
       A
       Q4
       F1
       Y4
       J
       Z
       T4
       G
       U
       I
       W4
       K1
       J1
       H1
       G1
       E1
       D1
       C1
       Y
       D
       A1
       F
       T1
       X
       W
       Q
       B
       L
       X4
       V4
       S4
       H
       E
       Z4
       S1)
        (let ((a!1 (not (= (or (and Y3 U3)
                       (and Y3 R3)
                       (and Y3 L2)
                       (and U3 R3)
                       (and U3 L2)
                       (and R3 L2))
                   N3)))
      (a!2 (not (= (or (and V B1)
                       (and M1 U4)
                       (and V U4)
                       (and V M1)
                       (and B1 U4)
                       (and B1 M1))
                   T)))
      (a!3 (or O4 (and N3 (not (<= M3 0)))))
      (a!4 (or (not A2) (= (+ N4 (* (- 1) Z1)) (- 1))))
      (a!5 (or (not A2) (= (+ O1 (* (- 1) T2)) 1)))
      (a!6 (or (not C2) (= (+ X1 N4 (* (- 1) J2)) 0)))
      (a!7 (or (not C2) (= (+ Q1 O1 (* (- 1) W2)) (- 1))))
      (a!8 (or (not C2) (= (+ V1 (* (- 1) Y2)) 1)))
      (a!9 (or (not E2) (= (+ X1 V1 Q1 O1 N4 (* (- 1) H2)) 1)))
      (a!10 (or (not G2) (= (+ X1 V1 Q1 O1 N4 (* (- 1) I2)) 1))))
  (and (= (<= 1 V1) C2)
       (= (<= 1 V1) G2)
       (= (<= 1 O1) A2)
       a!1
       a!2
       (= (or (not O4) (not P4)) R4)
       (= (or (not B4) (not A4)) Z3)
       (= B3 (<= 2 A3))
       (= O3 a!3)
       (= A4 O3)
       (= L4 B3)
       (= L4 B4)
       (= Y1 P4)
       (= U1 O4)
       (= M Y1)
       (= N4 M4)
       (= A3 F3)
       (= A3 E4)
       (= D3 C3)
       (= F3 E3)
       (= H3 G3)
       (= J3 I3)
       (= L3 K3)
       (= D4 D3)
       (= D4 C4)
       (= G4 H3)
       (= G4 F4)
       (= I4 J3)
       (= I4 H4)
       (= K4 L3)
       (= K4 J4)
       (= X1 W1)
       (= V1 R1)
       (= Q1 P1)
       (= O1 N1)
       (= S X1)
       (= R V1)
       (= P Q1)
       (= O O1)
       (= N N4)
       a!4
       a!5
       (or A2 (= N4 Z1))
       (or A2 (= O1 T2))
       a!6
       a!7
       a!8
       (or C2 (= N4 B2))
       (or (not C2) (= B2 0))
       (or (not C2) (= U2 0))
       (or C2 (= X1 J2))
       (or C2 (= V1 Y2))
       (or C2 (= Q1 W2))
       (or C2 (= O1 U2))
       a!9
       (or E2 (= N4 D2))
       (or (not E2) (= D2 0))
       (or (not E2) (= V2 1))
       (or (not E2) (= X2 0))
       (or (not E2) (= Z2 0))
       (or E2 (= X1 Z2))
       (or E2 (= V1 H2))
       (or E2 (= Q1 X2))
       (or E2 (= O1 V2))
       a!10
       (or G2 (= N4 F2))
       (or (not G2) (= F2 0))
       (or (not G2) (= M2 1))
       (or (not G2) (= O2 0))
       (or (not G2) (= R2 0))
       (or G2 (= X1 R2))
       (or G2 (= V1 I2))
       (or G2 (= Q1 O2))
       (or G2 (= O1 M2))
       (or L2 (= N4 K2))
       (or (not L2) (= K2 F2))
       (or (not L2) (= N2 M2))
       (or (not L2) (= P2 O2))
       (or (not L2) (= Q2 I2))
       (or (not L2) (= S2 R2))
       (or L2 (= X1 S2))
       (or L2 (= V1 Q2))
       (or L2 (= Q1 P2))
       (or L2 (= O1 N2))
       (or (not R3) (= P3 Z1))
       (or R3 (= Q3 P3))
       (or (not R3) (= S3 T2))
       (or R3 (= T3 S3))
       (or (not U3) (= B2 C3))
       (or U3 (= C3 P3))
       (or (not U3) (= E3 U2))
       (or (not U3) (= G3 W2))
       (or (not U3) (= I3 Y2))
       (or (not U3) (= K3 J2))
       (or U3 (= S3 E3))
       (or U3 (= V3 G3))
       (or U3 (= W3 I3))
       (or U3 (= X3 K3))
       (or (not Y3) (= D2 Q3))
       (or Y3 (= N2 T3))
       (or Y3 (= P2 V3))
       (or Y3 (= Q2 W3))
       (or Y3 (= S2 X3))
       (or Y3 (= Q3 K2))
       (or (not Y3) (= T3 V2))
       (or (not Y3) (= V3 X2))
       (or (not Y3) (= W3 H2))
       (or (not Y3) (= X3 Z2))
       (or (not M1) (= L1 K))
       (or M1 (= L1 C))
       (or (not M1) (= I1 Q4))
       (or M1 (= I1 A))
       (or M1 (= F1 Y4))
       (or (not M1) (= F1 J))
       (or M1 (= Z T4))
       (or (not M1) (= Z G))
       (or M1 (= U W4))
       (or (not M1) (= U I))
       (or B1 (= L1 K1))
       (or (not B1) (= K1 J1))
       (or B1 (= I1 H1))
       (or (not B1) (= H1 G1))
       (or B1 (= F1 E1))
       (or (not B1) (= E1 D1))
       (or B1 (= C1 Y))
       (or (not B1) (= C1 D))
       (or B1 (= A1 T1))
       (or (not B1) (= A1 F))
       (or (not V) (= T1 W))
       (or V (= Z Y))
       (or (not V) (= Y X))
       (or V (= U T1))
       (= (<= 2 (+ X1 Q1)) E2)))
      )
      (state O3
       A4
       L2
       Y3
       R3
       U3
       N3
       B3
       L4
       L3
       K4
       J3
       I4
       H3
       G4
       F3
       A3
       D3
       D4
       B4
       J4
       H4
       F4
       E4
       C4
       Z3
       X3
       S2
       Z2
       W3
       Q2
       H2
       V3
       P2
       X2
       T3
       N2
       V2
       Q3
       D2
       K2
       K3
       J2
       I3
       Y2
       G3
       W2
       E3
       S3
       U2
       C3
       B2
       P3
       T2
       Z1
       M3
       R2
       G2
       O2
       F2
       M2
       E2
       C2
       I2
       A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Int) (G Int) (H Bool) (I Int) (J Int) (K Int) (L Bool) (M Bool) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Int) (V Bool) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Bool) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Bool) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Bool) (C2 Bool) (D2 Int) (E2 Bool) (F2 Int) (G2 Int) (H2 Bool) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (state U1
       B2
       H2
       M1
       V
       B1
       T
       M
       Y1
       S
       X1
       R
       V1
       P
       Q1
       O
       O1
       N
       A2
       C2
       W1
       R1
       P1
       N1
       Z1
       E2
       L1
       C
       K
       I1
       A
       D2
       F1
       L2
       J
       Z
       G2
       G
       U
       I
       J2
       K1
       J1
       H1
       G1
       E1
       D1
       C1
       Y
       D
       A1
       F
       T1
       X
       W
       Q
       B
       L
       K2
       I2
       F2
       H
       E
       M2
       S1)
        (not E2)
      )
      false
    )
  )
)

(check-sat)
(exit)
