; ./prepared/vmt/./lustre/ILLINOIS_2_e1_834_e1_1895_000.smt2
(set-logic HORN)


(declare-fun |state| ( Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Int Int Int Int Bool Bool Bool Bool Int Int Int Int Bool Bool Bool Bool Bool Bool Bool ) Bool)

(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Int) (C2 Bool) (D2 Bool) (E2 Int) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Bool) (K2 Int) (L2 Bool) (M2 Int) (N2 Bool) (O2 Int) (P2 Bool) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Bool) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Int) (C3 Int) (D3 Bool) (E3 Int) (F3 Int) ) 
    (=>
      (and
        (let ((a!1 (= (or (and (not R1)
                       (not D)
                       (not Z2)
                       (not D3)
                       (not C1)
                       (not I1)
                       (not Y1)
                       (not C2)
                       (not G2))
                  (and (not R1)
                       (not D)
                       (not Z2)
                       (not D3)
                       (not C1)
                       (not I1)
                       (not Y1)
                       (not C2)
                       G2)
                  (and (not R1)
                       (not D)
                       (not Z2)
                       (not D3)
                       (not C1)
                       (not I1)
                       (not Y1)
                       C2
                       (not G2))
                  (and (not R1)
                       (not D)
                       (not Z2)
                       (not D3)
                       (not C1)
                       (not I1)
                       Y1
                       (not C2)
                       (not G2))
                  (and (not R1)
                       (not D)
                       (not Z2)
                       (not D3)
                       (not C1)
                       I1
                       (not Y1)
                       (not C2)
                       (not G2))
                  (and (not R1)
                       (not D)
                       (not Z2)
                       (not D3)
                       C1
                       (not I1)
                       (not Y1)
                       (not C2)
                       (not G2))
                  (and (not R1)
                       (not D)
                       (not Z2)
                       D3
                       (not C1)
                       (not I1)
                       (not Y1)
                       (not C2)
                       (not G2))
                  (and (not R1)
                       (not D)
                       Z2
                       (not D3)
                       (not C1)
                       (not I1)
                       (not Y1)
                       (not C2)
                       (not G2))
                  (and (not R1)
                       D
                       (not Z2)
                       (not D3)
                       (not C1)
                       (not I1)
                       (not Y1)
                       (not C2)
                       (not G2))
                  (and R1
                       (not D)
                       (not Z2)
                       (not D3)
                       (not C1)
                       (not I1)
                       (not Y1)
                       (not C2)
                       (not G2)))
              M)))
  (and (= (or A (not P)) O)
       (= Y P)
       (= N Y)
       (= N M)
       (= T S)
       (= K 0)
       (= K V)
       (= I H)
       (= I R)
       (= J 0)
       (= J T)
       (= L 0)
       (= L X)
       (= R Q)
       (= V U)
       (= X W)
       (or (not (<= Z 0)) (= (+ H Z) 1))
       (or (<= Z 0) (= H Z))
       (or (= M2 X1) G2)
       (or (= E2 Q1) G2)
       (or (not G2) (= X1 K2))
       (or (not G2) (= Q1 I2))
       (or (not G2) (= W1 X2))
       (or (= O2 W1) G2)
       (or (not C2) (= M2 W2))
       (or (= M2 C) C2)
       (or (not C2) (= E2 R2))
       (or (= B2 E2) C2)
       (or (= A2 C3) C2)
       (or (not C2) (= A2 Y2))
       (or (not C2) (= O2 G))
       (or (= O2 F) C2)
       (or (= X1 M1) Y1)
       (or (not Y1) (= M1 Z1))
       (or (not Y1) (= U1 Q2))
       (or Y1 (= A2 U1))
       (or (= P1 O1) I1)
       (or (not I1) (= B1 J1))
       (or (= H1 B1) I1)
       (or (not I1) (= L1 K1))
       (or (= M1 L1) I1)
       (or (not I1) (= O1 N1))
       (or (not C1) (= A1 D1))
       (or (= B1 A1) C1)
       (or (not C1) (= F1 E1))
       (or (= G1 F1) C1)
       (or (not D3) (= F3 E3))
       (or (not D3) (= C3 B3))
       (or (not A3) (= X2 0))
       (or (not Z2) (= F E))
       (or Z2 (= S2 F3))
       (or (not Z2) (= S2 U2))
       (or (not V2) (= G 0))
       (or (not V2) (= Y2 0))
       (or (not V2) (= W2 1))
       (or (not D) (= B2 T2))
       (or (not D) (= C B))
       (or D (= S2 B2))
       (or R1 (= Q1 H1))
       (or (not R1) (= P1 V1))
       (or (not R1) (= G1 T1))
       (or (not R1) (= H1 S1))
       (or R1 (= U1 G1))
       (or R1 (= W1 P1))
       (= A true)
       a!1))
      )
      (state N
       Y
       I1
       C1
       R1
       Y1
       G2
       C2
       D
       Z2
       D3
       M
       L
       X
       K
       V
       J
       T
       I
       R
       S2
       U2
       F3
       B2
       T2
       O2
       F
       G
       A2
       C3
       Y2
       M2
       C
       W2
       E2
       R2
       W1
       X2
       X1
       K2
       Q1
       I2
       U1
       Q2
       M1
       Z1
       P1
       V1
       G1
       T1
       H1
       S1
       O1
       N1
       L1
       K1
       B1
       J1
       F1
       E1
       A1
       D1
       H
       Z
       P
       W
       U
       S
       Q
       A
       O
       V2
       A3
       E
       B
       E3
       B3
       D2
       F2
       H2
       J2
       L2
       N2
       P2)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Int) (C2 Bool) (D2 Bool) (E2 Int) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Bool) (K2 Int) (L2 Bool) (M2 Int) (N2 Bool) (O2 Int) (P2 Bool) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Bool) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Bool) (H3 Int) (I3 Int) (J3 Bool) (K3 Int) (L3 Int) (M3 Bool) (N3 Int) (O3 Bool) (P3 Int) (Q3 Bool) (R3 Int) (S3 Bool) (T3 Int) (U3 Bool) (V3 Int) (W3 Bool) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Int) (B4 Int) (C4 Bool) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Bool) (W4 Bool) (X4 Bool) (Y4 Bool) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Bool) (E5 Int) (F5 Int) (G5 Int) (H5 Bool) (I5 Int) (J5 Int) (K5 Bool) (L5 Int) (M5 Int) (N5 Int) (O5 Bool) (P5 Int) (Q5 Int) (R5 Int) (S5 Bool) (T5 Int) (U5 Int) (V5 Bool) (W5 Int) (X5 Int) (Y5 Int) (Z5 Bool) (A6 Int) (B6 Bool) (C6 Int) (D6 Int) (E6 Int) (F6 Bool) (G6 Bool) (H6 Int) (I6 Int) (J6 Bool) (K6 Int) (L6 Int) ) 
    (=>
      (and
        (state N
       Y
       I1
       C1
       R1
       Y1
       G2
       C2
       D
       F6
       J6
       M
       L
       X
       K
       V
       J
       T
       I
       R
       S2
       U2
       L6
       B2
       T2
       O2
       F
       G
       A2
       I6
       E6
       M2
       C
       C6
       E2
       R2
       W1
       D6
       X1
       K2
       Q1
       I2
       U1
       Q2
       M1
       Z1
       P1
       V1
       G1
       T1
       H1
       S1
       O1
       N1
       L1
       K1
       B1
       J1
       F1
       E1
       A1
       D1
       H
       Z
       P
       W
       U
       S
       Q
       A
       O
       B6
       G6
       E
       B
       K6
       H6
       D2
       F2
       H2
       J2
       L2
       N2
       P2)
        (let ((a!1 (= (or (and (not Z5)
                       (not V5)
                       (not S5)
                       (not O5)
                       (not K5)
                       (not H5)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not Z5)
                       (not V5)
                       (not S5)
                       (not O5)
                       (not K5)
                       (not H5)
                       (not J3)
                       (not G3)
                       B3)
                  (and (not Z5)
                       (not V5)
                       (not S5)
                       (not O5)
                       (not K5)
                       (not H5)
                       (not J3)
                       G3
                       (not B3))
                  (and (not Z5)
                       (not V5)
                       (not S5)
                       (not O5)
                       (not K5)
                       (not H5)
                       J3
                       (not G3)
                       (not B3))
                  (and (not Z5)
                       (not V5)
                       (not S5)
                       (not O5)
                       (not K5)
                       H5
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not Z5)
                       (not V5)
                       (not S5)
                       (not O5)
                       K5
                       (not H5)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not Z5)
                       (not V5)
                       (not S5)
                       O5
                       (not K5)
                       (not H5)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not Z5)
                       (not V5)
                       S5
                       (not O5)
                       (not K5)
                       (not H5)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and (not Z5)
                       V5
                       (not S5)
                       (not O5)
                       (not K5)
                       (not H5)
                       (not J3)
                       (not G3)
                       (not B3))
                  (and Z5
                       (not V5)
                       (not S5)
                       (not O5)
                       (not K5)
                       (not H5)
                       (not J3)
                       (not G3)
                       (not B3)))
              V4))
      (a!2 (= (or (and (not D)
                       (not C1)
                       (not I1)
                       (not R1)
                       (not Y1)
                       (not C2)
                       (not G2)
                       (not F6)
                       (not J6))
                  (and (not D)
                       (not C1)
                       (not I1)
                       (not R1)
                       (not Y1)
                       (not C2)
                       (not G2)
                       (not F6)
                       J6)
                  (and (not D)
                       (not C1)
                       (not I1)
                       (not R1)
                       (not Y1)
                       (not C2)
                       (not G2)
                       F6
                       (not J6))
                  (and (not D)
                       (not C1)
                       (not I1)
                       (not R1)
                       (not Y1)
                       (not C2)
                       G2
                       (not F6)
                       (not J6))
                  (and (not D)
                       (not C1)
                       (not I1)
                       (not R1)
                       (not Y1)
                       C2
                       (not G2)
                       (not F6)
                       (not J6))
                  (and (not D)
                       (not C1)
                       (not I1)
                       (not R1)
                       Y1
                       (not C2)
                       (not G2)
                       (not F6)
                       (not J6))
                  (and (not D)
                       (not C1)
                       (not I1)
                       R1
                       (not Y1)
                       (not C2)
                       (not G2)
                       (not F6)
                       (not J6))
                  (and (not D)
                       (not C1)
                       I1
                       (not R1)
                       (not Y1)
                       (not C2)
                       (not G2)
                       (not F6)
                       (not J6))
                  (and (not D)
                       C1
                       (not I1)
                       (not R1)
                       (not Y1)
                       (not C2)
                       (not G2)
                       (not F6)
                       (not J6))
                  (and D
                       (not C1)
                       (not I1)
                       (not R1)
                       (not Y1)
                       (not C2)
                       (not G2)
                       (not F6)
                       (not J6)))
              M))
      (a!3 (= Z2
              (= (+ W U S Q (* (- 1) Y2) (* (- 1) X2) (* (- 1) W2) (* (- 1) V2))
                 2)))
      (a!4 (= Q3 (and (<= 1 R) (<= 1 (+ X V)))))
      (a!5 (or (not M3) (= (+ V (* (- 1) F4)) (- 1))))
      (a!6 (or (not M3) (= (+ R (* (- 1) L3)) 1)))
      (a!7 (or (not O3) (= (+ X (* (- 1) K4)) (- 2))))
      (a!8 (or (not O3) (= (+ T (* (- 1) A4)) 1)))
      (a!9 (or (not O3) (= (+ R (* (- 1) N3)) 1)))
      (a!10 (or (not Q3) (= (+ X V (* (- 1) J4)) (- 1))))
      (a!11 (or (not Q3) (= (+ R (* (- 1) P3)) 1)))
      (a!12 (or (not S3) (= (+ X R (* (- 1) R3)) 1)))
      (a!13 (or (not S3) (= (+ T (* (- 1) D4)) (- 1))))
      (a!14 (or (not U3) (= (+ X V T R (* (- 1) T3)) 1)))
      (a!15 (or (not W3) (= (+ T (* (- 1) H3)) 1)))
      (a!16 (or (not W3) (= (+ R (* (- 1) V3)) (- 1))))
      (a!17 (or (not Y3) (= (+ X (* (- 1) K3)) 1)))
      (a!18 (or (not Y3) (= (+ R (* (- 1) X3)) (- 1))))
      (a!19 (or (not Z3) (= (+ V (* (- 1) D3)) 1)))
      (a!20 (or (not Z3) (= (+ R (* (- 1) C3)) (- 1))))
      (a!21 (or (not C4) (= (+ V (* (- 1) H4)) 1)))
      (a!22 (or (not C4) (= (+ T (* (- 1) B4)) (- 1)))))
  (and (= (<= 1 X) Y3)
       (= (<= 1 V) Z3)
       (= (<= 1 V) C4)
       (= (<= 1 T) W3)
       (= (<= 1 R) U3)
       a!1
       a!2
       (= (or (not Y4) Z2) X4)
       (= (or A (not P)) O)
       (= (and (<= 1 R) (= T 0) (= V 0) (= X 0)) M3)
       (= (and (<= 1 R) (<= 1 T)) O3)
       a!3
       a!4
       (= W4 (and Y V4))
       (= D5 W4)
       (= D5 Y4)
       (= Y P)
       (= N Y)
       (= O4 N4)
       (= Q4 P4)
       (= S4 R4)
       (= U4 T4)
       (= Z4 V2)
       (= Z4 O4)
       (= A5 W2)
       (= A5 Q4)
       (= B5 X2)
       (= B5 S4)
       (= C5 Y2)
       (= C5 U4)
       (= X W)
       (= V U)
       (= T S)
       (= R Q)
       (= L X)
       (= K V)
       (= J T)
       (= I R)
       (or (not (<= E5 0)) (= (+ E5 F5) 1))
       (or (<= E5 0) (= E5 F5))
       (or (not (<= Z 0)) (= (+ H Z) 1))
       (or (<= Z 0) (= H Z))
       (or F6 (= S2 L6))
       (or (not F6) (= S2 U2))
       (or (not B3) (= A3 C3))
       (or (not B3) (= E3 D3))
       (or B3 (= V E3))
       (or B3 (= R A3))
       (or (not G3) (= F3 H3))
       (or (not G3) (= V3 Y5))
       (or G3 (= A6 Y5))
       (or G3 (= T F3))
       (or (not J3) (= I3 K3))
       (or (not J3) (= X3 A6))
       (or J3 (= A6 A3))
       (or J3 (= X I3))
       a!5
       a!6
       (or M3 (= V F4))
       (or M3 (= R L3))
       a!7
       a!8
       a!9
       (or O3 (= X K4))
       (or O3 (= T A4))
       (or O3 (= R N3))
       a!10
       a!11
       (or (not Q3) (= G4 0))
       (or Q3 (= X J4))
       (or Q3 (= V G4))
       (or Q3 (= R P3))
       a!12
       a!13
       (or (not S3) (= L4 0))
       (or S3 (= X L4))
       (or S3 (= T D4))
       (or S3 (= R R3))
       a!14
       (or (not U3) (= E4 1))
       (or (not U3) (= I4 0))
       (or (not U3) (= M4 0))
       (or U3 (= X M4))
       (or U3 (= V I4))
       (or U3 (= T E4))
       (or U3 (= R T3))
       a!15
       a!16
       (or W3 (= T H3))
       (or W3 (= R V3))
       a!17
       a!18
       (or Y3 (= X K3))
       (or Y3 (= R X3))
       a!19
       a!20
       (or Z3 (= V D3))
       (or Z3 (= R C3))
       a!21
       a!22
       (or C4 (= V H4))
       (or C4 (= T B4))
       (or (not H5) (= L3 N4))
       (or (not H5) (= R4 F4))
       (or H5 (= G5 N4))
       (or H5 (= I5 R4))
       (or (not K5) (= N3 G5))
       (or (not K5) (= P4 A4))
       (or (not K5) (= T4 K4))
       (or K5 (= J5 G5))
       (or K5 (= L5 P4))
       (or K5 (= M5 T4))
       (or (not O5) (= P3 J5))
       (or (not O5) (= I5 G4))
       (or (not O5) (= M5 J4))
       (or O5 (= N5 J5))
       (or O5 (= P5 I5))
       (or O5 (= Q5 M5))
       (or (not S5) (= B4 L5))
       (or (not S5) (= P5 H4))
       (or S5 (= R5 L5))
       (or S5 (= T5 P5))
       (or (not V5) (= R3 N5))
       (or (not V5) (= Q5 L4))
       (or (not V5) (= R5 D4))
       (or V5 (= U5 N5))
       (or V5 (= W5 R5))
       (or V5 (= X5 Q5))
       (or Z5 (= E3 T5))
       (or Z5 (= F3 W5))
       (or Z5 (= I3 X5))
       (or (not Z5) (= T3 U5))
       (or (not Z5) (= T5 I4))
       (or (not Z5) (= W5 E4))
       (or (not Z5) (= X5 M4))
       (or Z5 (= Y5 U5))
       (or G2 (= O2 W1))
       (or G2 (= M2 X1))
       (or G2 (= E2 Q1))
       (or (not G2) (= X1 K2))
       (or (not G2) (= W1 D6))
       (or (not G2) (= Q1 I2))
       (or (not C2) (= O2 G))
       (or C2 (= O2 F))
       (or (not C2) (= M2 C6))
       (or C2 (= M2 C))
       (or (not C2) (= E2 R2))
       (or C2 (= B2 E2))
       (or C2 (= A2 I6))
       (or (not C2) (= A2 E6))
       (or Y1 (= A2 U1))
       (or Y1 (= X1 M1))
       (or (not Y1) (= U1 Q2))
       (or (not Y1) (= M1 Z1))
       (or R1 (= W1 P1))
       (or R1 (= U1 G1))
       (or R1 (= Q1 H1))
       (or (not R1) (= P1 V1))
       (or (not R1) (= H1 S1))
       (or (not R1) (= G1 T1))
       (or I1 (= P1 O1))
       (or (not I1) (= O1 N1))
       (or I1 (= M1 L1))
       (or (not I1) (= L1 K1))
       (or I1 (= H1 B1))
       (or (not I1) (= B1 J1))
       (or C1 (= G1 F1))
       (or (not C1) (= F1 E1))
       (or C1 (= B1 A1))
       (or (not C1) (= A1 D1))
       (or D (= S2 B2))
       (or (not D) (= B2 T2))
       (= (<= 1 X) S3)))
      )
      (state W4
       D5
       K5
       H5
       O5
       S5
       V5
       Z5
       G3
       J3
       B3
       V4
       U4
       C5
       S4
       B5
       Q4
       A5
       O4
       Z4
       A6
       X3
       A3
       Y5
       V3
       X5
       I3
       M4
       T5
       E3
       I4
       W5
       F3
       E4
       U5
       T3
       Q5
       L4
       R5
       D4
       N5
       R3
       P5
       H4
       L5
       B4
       M5
       J4
       I5
       G4
       J5
       P3
       T4
       K4
       P4
       A4
       G5
       N3
       R4
       F4
       N4
       L3
       F5
       E5
       Y4
       Y2
       X2
       W2
       V2
       Z2
       X4
       U3
       S3
       K3
       H3
       C3
       D3
       M3
       O3
       Q3
       C4
       W3
       Y3
       Z3)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Int) (C2 Bool) (D2 Bool) (E2 Int) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Bool) (K2 Int) (L2 Bool) (M2 Int) (N2 Bool) (O2 Int) (P2 Bool) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Bool) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Int) (C3 Int) (D3 Bool) (E3 Int) (F3 Int) ) 
    (=>
      (and
        (state N
       Y
       I1
       C1
       R1
       Y1
       G2
       C2
       D
       Z2
       D3
       M
       L
       X
       K
       V
       J
       T
       I
       R
       S2
       U2
       F3
       B2
       T2
       O2
       F
       G
       A2
       C3
       Y2
       M2
       C
       W2
       E2
       R2
       W1
       X2
       X1
       K2
       Q1
       I2
       U1
       Q2
       M1
       Z1
       P1
       V1
       G1
       T1
       H1
       S1
       O1
       N1
       L1
       K1
       B1
       J1
       F1
       E1
       A1
       D1
       H
       Z
       P
       W
       U
       S
       Q
       A
       O
       V2
       A3
       E
       B
       E3
       B3
       D2
       F2
       H2
       J2
       L2
       N2
       P2)
        (not O)
      )
      false
    )
  )
)

(check-sat)
(exit)
