; ./vmt/./lustre/tramway_000.smt2
(set-logic HORN)

(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Bool) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) ) 
    (=>
      (and
        (and (= (or (not P) F) Y1)
     (= (and N1 M1 K1 J1 I1 H1 G1 F1) M)
     (not (= (and V1 T1) X1))
     (= G2 Z1)
     (= D2 O1)
     (not (= F G))
     (= J U1)
     (= K S1)
     (= N M)
     (not (= P O))
     (= R Q)
     (= S Q)
     (= U (and T (not P)))
     (= U F2)
     (= V (and T P))
     (= V L1)
     (= W (and S F))
     (= W E1)
     (= X I2)
     (= Y J2)
     (= Z A)
     (= A1 B)
     (= B1 C)
     (= C1 D)
     (= D1 E)
     (= F1 (or (not E1) (not X)))
     (= G1 (or (not T) F))
     (= H1 (= Y Z))
     (= I1 G)
     (= J1 O)
     (= K1 (or (not B1) A1))
     (= M1 (or L1 (not C1)))
     (= N1 (or E1 (not D1)))
     (= O1 N)
     (= Q1 P1)
     (= T1 P1)
     (= V1 I)
     (= X1 W1)
     (= Z1 (and Y1 W1))
     (= A2 H)
     (or T R (not B2))
     (or (= E2 R) (and (not T) B2))
     (or P (= E2 H2))
     (or (not E2) (not P))
     (or S1 (= R1 L))
     (or (not S1) (not R1))
     (or A2 (= Q1 R1))
     (or (not A2) Q1)
     (not J2)
     (not I2)
     (not H2)
     (not A)
     (not B)
     (not C)
     (not D)
     (not E)
     (not H)
     (not I)
     (not J)
     (not K)
     (not L)
     (= (or (not D2) G2) C2))
      )
      (state T1
       V1
       X1
       A2
       Q1
       R1
       H
       P
       F
       Y1
       D2
       G2
       C2
       E2
       H2
       T
       B2
       R
       O1
       Z1
       W
       E1
       V
       L1
       U
       F2
       W1
       I
       J
       U1
       P1
       K
       S1
       L
       N
       M1
       N1
       K1
       J1
       I1
       H1
       G1
       F1
       M
       D1
       C1
       B1
       A1
       O
       G
       Y
       Z
       X
       E
       D
       C
       B
       A
       J2
       I2
       S
       Q)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Bool) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Bool) (T2 Bool) (U2 Bool) (V2 Bool) (W2 Bool) (X2 Bool) (Y2 Bool) (Z2 Bool) (A3 Bool) (B3 Bool) (C3 Bool) (D3 Bool) (E3 Bool) (F3 Bool) (G3 Bool) (H3 Bool) (I3 Bool) (J3 Bool) (K3 Bool) (L3 Bool) (M3 Bool) (N3 Bool) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Bool) (V3 Bool) (W3 Bool) (X3 Bool) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Bool) (C4 Bool) (D4 Bool) (E4 Bool) (F4 Bool) (G4 Bool) (H4 Bool) (I4 Bool) (J4 Bool) (K4 Bool) (L4 Bool) (M4 Bool) (N4 Bool) (O4 Bool) (P4 Bool) (Q4 Bool) (R4 Bool) (S4 Bool) (T4 Bool) ) 
    (=>
      (and
        (state T1
       V1
       X1
       A2
       Q1
       R1
       H
       P
       F
       Y1
       N4
       Q4
       M4
       O4
       R4
       T
       L4
       R
       O1
       Z1
       W
       E1
       V
       L1
       U
       P4
       W1
       I
       J
       U1
       P1
       K
       S1
       L
       N
       M1
       N1
       K1
       J1
       I1
       H1
       G1
       F1
       M
       D1
       C1
       B1
       A1
       O
       G
       Y
       Z
       X
       E
       D
       C
       B
       A
       T4
       S4
       S
       Q)
        (and (= (or L2 (not F2)) C4)
     (= (or (not G4) F4) J4)
     (= (or F (not P)) Y1)
     (= (and R3 Q3 O3 N3 M3 L3 K3 J3) N2)
     (= (and F1 G1 H1 I1 J1 K1 M1 N1) M)
     (not (= (and Z3 X3) B4))
     (not (= (and T1 V1) X1))
     (= (and (not T) L4) K2)
     (= Q4 Z1)
     (= P4 E2)
     (= N4 O1)
     (= D2 (and (not T) C2))
     (= G2 (and (not P) F2))
     (= M2 (and F (not L2)))
     (= O2 (and O1 N2))
     (= R2 (and P (not F2)))
     (= S2 (and F (not L2)))
     (= T2 (and F (not L2)))
     (= U2 (and T (not C2)))
     (= W2 V2)
     (= X2 V2)
     (= Y2 (and (not F2) C2))
     (= Z2 (and F2 C2))
     (= A3 (and X2 L2))
     (= B3 D2)
     (= C3 U2)
     (= D3 T2)
     (= E3 E2)
     (= F3 S2)
     (= G3 R2)
     (= H3 G2)
     (= I3 A3)
     (= J3 (or (not I3) (not B3)))
     (= K3 (or L2 (not C2)))
     (= L3 (= D3 C3))
     (= M3 Q2)
     (= N3 P2)
     (= O3 (or (not F3) E3))
     (= P3 Z2)
     (= Q3 (or P3 (not G3)))
     (= R3 (or I3 (not H3)))
     (= S3 O2)
     (= U3 T3)
     (= W3 I2)
     (= X3 T3)
     (= Y3 J2)
     (= Z3 M2)
     (= B4 A4)
     (= D4 (and C4 A4))
     (= E4 Y2)
     (= F4 D4)
     (= G4 S3)
     (= K4 K2)
     (= A2 H)
     (= Z1 (and W1 Y1))
     (= X1 W1)
     (= V1 I)
     (= U1 I2)
     (= T1 P1)
     (= Q1 P1)
     (= P1 H2)
     (= O1 N)
     (= N1 (or (not D1) E1))
     (= M1 (or (not C1) L1))
     (= K1 (or A1 (not B1)))
     (= J1 O)
     (= I1 G)
     (= H1 (= Y Z))
     (= G1 (or F (not T)))
     (= F1 (or (not X) (not E1)))
     (= D1 E)
     (= C1 D)
     (= B1 C)
     (= A1 B)
     (= Z A)
     (= Y T4)
     (= X S4)
     (= W (and F S))
     (= W E1)
     (= V (and P T))
     (= V L1)
     (= U (and (not P) T))
     (= U P4)
     (= S Q)
     (= R Q)
     (= Q B2)
     (= P J2)
     (= K S1)
     (= J U1)
     (or (not I4) W2 C2)
     (or R T (not L4))
     (or (= H4 W2) (and I4 (not C2)))
     (or (= O4 R) (and (not T) L4))
     (or F2 (= H4 B2))
     (or W3 (= V3 H2))
     (or (not W3) (not V3))
     (or (not H4) (not F2))
     (or K4 (= U3 V3))
     (or (not K4) U3)
     (or A2 (= Q1 R1))
     (or S1 (= R1 L))
     (or (not R1) (not S1))
     (or Q1 (not A2))
     (or P (= O4 R4))
     (or (not P) (not O4))
     (= P2 true)
     (= Q2 true)
     (= (or (not N4) Q4) M4))
      )
      (state X3
       Z3
       B4
       K4
       U3
       V3
       K2
       F2
       L2
       C4
       G4
       F4
       J4
       H4
       B2
       C2
       I4
       W2
       S3
       D4
       A3
       I3
       Z2
       P3
       Y2
       E4
       A4
       M2
       J2
       Y3
       T3
       I2
       W3
       H2
       O2
       Q3
       R3
       O3
       N3
       M3
       L3
       K3
       J3
       N2
       H3
       G3
       F3
       E3
       P2
       Q2
       C3
       D3
       B3
       G2
       R2
       S2
       E2
       T2
       U2
       D2
       X2
       V2)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Bool) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) ) 
    (=>
      (and
        (state T1
       V1
       X1
       A2
       Q1
       R1
       H
       P
       F
       Y1
       D2
       G2
       C2
       E2
       H2
       T
       B2
       R
       O1
       Z1
       W
       E1
       V
       L1
       U
       F2
       W1
       I
       J
       U1
       P1
       K
       S1
       L
       N
       M1
       N1
       K1
       J1
       I1
       H1
       G1
       F1
       M
       D1
       C1
       B1
       A1
       O
       G
       Y
       Z
       X
       E
       D
       C
       B
       A
       J2
       I2
       S
       Q)
        (not C2)
      )
      false
    )
  )
)

(check-sat)
(exit)
