; ./seahorn/./sv_comp_flat_small/seq-mthreaded/pals_lcr-var-start-time.4_true-unreach-call.ufo.BOUNDED-8.pals.c.flat_000.smt2
(set-logic HORN)

(declare-fun |main_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Bool Bool Int Bool Bool Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Int) (W Bool) (X Bool) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (v_47 Int) ) 
    (=>
      (and
        (and true (= 0 v_47))
      )
      (main_1 v_47
        A
        B
        C
        D
        E
        F
        G
        H
        I
        J
        K
        L
        M
        N
        O
        P
        Q
        R
        S
        T
        U
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
        G1
        H1
        I1
        J1
        K1
        L1
        M1
        N1
        O1
        P1
        Q1
        R1
        S1
        T1
        U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Bool) (V2 Bool) (W2 Int) (X2 Bool) (Y2 Bool) (Z2 Int) (A3 Bool) (B3 Bool) (C3 Int) (D3 Bool) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Bool) (C4 Int) (D4 Bool) (E4 Int) (F4 Int) (G4 Int) (H4 Bool) (I4 Int) (J4 Bool) (K4 Int) (L4 Int) (M4 Int) (N4 Bool) (O4 Int) (P4 Bool) (Q4 Int) (R4 Int) (S4 Int) (T4 Bool) (U4 Int) (V4 Bool) (W4 Bool) (X4 Bool) (Y4 Bool) (Z4 Bool) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Bool) (V5 Bool) (W5 Bool) (X5 Bool) (Y5 Bool) (Z5 Bool) (A6 Bool) (B6 Bool) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (v_190 Int) (v_191 Int) ) 
    (=>
      (and
        (main_1 v_190
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3
        Q3
        R3
        S3
        T3
        U3
        V3)
        (let ((a!1 (or (not E5) (not (= (= K4 Q4) O))))
      (a!2 (or (not C5) (not (= (<= Q4 (- 1)) R))))
      (a!3 (or (not A5) (not (= (<= K4 (- 1)) Y))))
      (a!4 (or (not Y4) (not (= (<= E4 (- 1)) F1))))
      (a!5 (or (not W4) (not (= (<= Y3 (- 1)) T1))))
      (a!6 (or (not W4) (not (= (<= R1 0) S1)))))
  (and (= 0 v_190)
       (= U4 (ite T4 1 0))
       (= O4 (ite N4 1 0))
       (= I4 (ite H4 1 0))
       (= C4 (ite B4 1 0))
       (or (and E5 I5)
           (and C5 J5)
           (and A5 K5)
           (and Y4 L5)
           (and W4 M5)
           (and W3 N5)
           (not H5))
       (or (= P6 A4) (not B6) (not Y5))
       (or (= N6 I4) (not B6) (not Y5))
       (or (not B6) (not Y5) (= M6 (- 1)))
       (or (= K6 F4) (not B6) (not Y5))
       (or (= J6 O4) (not B6) (not Y5))
       (or (= H6 M4) (not B6) (not Y5))
       (or (= G6 L4) (not B6) (not Y5))
       (or (= D S6) (not B6) (not Y5))
       (or (= C N6) (not B6) (not Y5))
       (or (= B J6) (not B6) (not Y5))
       (or (= A F6) (not B6) (not Y5))
       (or (= H7 T6) (not B6) (not Y5))
       (or (= G7 R6) (not B6) (not Y5))
       (or (= F7 Q6) (not B6) (not Y5))
       (or (= E7 P6) (not B6) (not Y5))
       (or (= D7 O6) (not B6) (not Y5))
       (or (= C7 M6) (not B6) (not Y5))
       (or (= B7 L6) (not B6) (not Y5))
       (or (= A7 K6) (not B6) (not Y5))
       (or (= Z6 I6) (not B6) (not Y5))
       (or (= Y6 H6) (not B6) (not Y5))
       (or (= X6 G6) (not B6) (not Y5))
       (or (= W6 E6) (not B6) (not Y5))
       (or (= V6 D6) (not B6) (not Y5))
       (or (= U6 C6) (not B6) (not Y5))
       (or (= T6 0) (not B6) (not Y5))
       (or (= S6 C4) (not B6) (not Y5))
       (or (= R6 X3) (not B6) (not Y5))
       (or (not B6) (not Y5) (= Q6 (- 1)))
       (or (= O6 Z3) (not B6) (not Y5))
       (or (= L6 G4) (not B6) (not Y5))
       (or (not B6) (not Y5) (= I6 (- 1)))
       (or (= F6 U4) (not B6) (not Y5))
       (or (not B6) (not Y5) (= E6 (- 1)))
       (or (= D6 S4) (not B6) (not Y5))
       (or (= C6 R4) (not B6) (not Y5))
       (or (= O5 G5) (not E5) (not I5))
       (or (= A2 O5) (not E5) (not I5))
       (or (= A2 P5) (not C5) (not J5))
       (or (not C5) (not P5) (not J5))
       (or (= A2 Q5) (not A5) (not K5))
       (or (not A5) (not Q5) (not K5))
       (or (= A2 R5) (not Y4) (not L5))
       (or (not Y4) (not R5) (not L5))
       (or (= A2 S5) (not W4) (not M5))
       (or (not W4) (not S5) (not M5))
       (or (not D4) (not H5) (not Z5))
       (or (= A2 T5) (not W3) (not N5))
       (or (not T5) (not W3) (not N5))
       (or (not Z1) (not W3) (not N5))
       (or Z1 (not X4) (not W3))
       (or (not Y1) (not W4) (not M5))
       (or Y1 (not W4) (not Z4))
       (or (not K1) (not Y4) (not L5))
       (or K1 (not Y4) (not B5))
       (or (not D1) (not A5) (not K5))
       (or D1 (not A5) (not D5))
       (or (not W) (not C5) (not J5))
       (or W (not C5) (not F5))
       (or (not A6) (and Y5 B6))
       (or (not Y5) (and H5 Z5))
       (or (not H5) (not (= V4 X5)))
       (or (not H5) (not (= P4 W5)))
       (or (not H5) (not (= J4 V5)))
       (or (not H5) (not (= D4 U5)))
       a!1
       (or (not E5) (= G5 (and O P)))
       (or (not E5) (= N (or L M)))
       (or (not E5) (not (= N P)))
       (or (not E5) (= M (= E4 Q4)))
       (or (not E5) (= L (or J K)))
       (or (not E5) (= K (= E4 K4)))
       (or (not E5) (= J (or H I)))
       (or (not E5) (= I (= Y3 Q4)))
       (or (not E5) (= H (or F G)))
       (or (not E5) (= G (= Y3 K4)))
       (or (not E5) (= F (or E T4)))
       (or (not E5) (= E (= Y3 E4)))
       (or (not E5) (and C5 F5))
       a!2
       (or (not C5) (not (= N4 Q)))
       (or (not C5) (= W (and U V)))
       (or (not C5) (= V (= S4 Q4)))
       (or (not C5) (= U (and S T)))
       (or (not C5) (= T (= R4 0)))
       (or (not C5) (= S (and Q R)))
       (or (not C5) (and A5 D5))
       a!3
       (or (not A5) (not (= H4 X)))
       (or (not A5) (= D1 (and B1 C1)))
       (or (not A5) (= C1 (= M4 K4)))
       (or (not A5) (= B1 (and Z A1)))
       (or (not A5) (= A1 (= L4 0)))
       (or (not A5) (= Z (and X Y)))
       (or (not A5) (and Y4 B5))
       a!4
       (or (not Y4) (not (= B4 E1)))
       (or (not Y4) (= K1 (and I1 J1)))
       (or (not Y4) (= J1 (= G4 E4)))
       (or (not Y4) (= I1 (and G1 H1)))
       (or (not Y4) (= H1 (= F4 0)))
       (or (not Y4) (= G1 (and E1 F1)))
       (or (not Y4) (and W4 Z4))
       a!5
       a!6
       (or (not W4) (= Y1 (and W1 X1)))
       (or (not W4) (= X1 (= A4 Y3)))
       (or (not W4) (= W1 (and U1 V1)))
       (or (not W4) (= V1 (= Z3 0)))
       (or (not W4) (= U1 (and S1 T1)))
       (or (not W4) (= R1 (+ P1 Q1)))
       (or (not W4) (= Q1 (ite V4 1 0)))
       (or (not W4) (= P1 (+ N1 O1)))
       (or (not W4) (= O1 (ite P4 1 0)))
       (or (not W4) (= N1 (+ M1 L1)))
       (or (not W4) (= M1 (ite J4 1 0)))
       (or (not W4) (= L1 (ite D4 1 0)))
       (or (not W4) (and W3 X4))
       (or A2 (not H5))
       (= A6 true)
       (= Z1 (= X3 0))
       (= 1 v_191)))
      )
      (main_1 v_191
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        Q4
        X5
        V4
        K4
        W5
        P4
        E4
        V5
        J4
        Y3
        U5
        H7
        U6
        V6
        W6
        A
        X6
        Y6
        Z6
        B
        A7
        B7
        C7
        C
        D7
        E7
        F7
        G7
        D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Bool) (V2 Bool) (W2 Int) (X2 Bool) (Y2 Bool) (Z2 Int) (A3 Bool) (B3 Bool) (C3 Int) (D3 Bool) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Bool) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Bool) (C4 Int) (D4 Bool) (E4 Int) (F4 Int) (G4 Int) (H4 Bool) (I4 Int) (J4 Bool) (K4 Int) (L4 Int) (M4 Int) (N4 Bool) (O4 Int) (P4 Bool) (Q4 Int) (R4 Int) (S4 Int) (T4 Bool) (U4 Int) (V4 Bool) (W4 Bool) (X4 Bool) (Y4 Bool) (Z4 Bool) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Bool) (V5 Bool) (W5 Bool) (X5 Bool) (Y5 Bool) (Z5 Bool) (A6 Bool) (B6 Bool) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (v_190 Int) (v_191 Int) ) 
    (=>
      (and
        (main_1 v_190
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3
        Q3
        R3
        S3
        T3
        U3
        V3)
        (let ((a!1 (or (not E5) (not (= (= K4 Q4) O))))
      (a!2 (or (not C5) (not (= (<= Q4 (- 1)) R))))
      (a!3 (or (not A5) (not (= (<= K4 (- 1)) Y))))
      (a!4 (or (not Y4) (not (= (<= E4 (- 1)) F1))))
      (a!5 (or (not W4) (not (= (<= Y3 (- 1)) T1))))
      (a!6 (or (not W4) (not (= (<= R1 0) S1)))))
  (and (= 0 v_190)
       (= U4 (ite T4 1 0))
       (= O4 (ite N4 1 0))
       (= I4 (ite H4 1 0))
       (= C4 (ite B4 1 0))
       (or (and E5 I5)
           (and C5 J5)
           (and A5 K5)
           (and Y4 L5)
           (and W4 M5)
           (and W3 N5)
           (not H5))
       (or (= P6 A4) (not B6) (not Y5))
       (or (= N6 I4) (not B6) (not Y5))
       (or (not B6) (not Y5) (= M6 (- 1)))
       (or (= K6 F4) (not B6) (not Y5))
       (or (= J6 O4) (not B6) (not Y5))
       (or (= H6 M4) (not B6) (not Y5))
       (or (= G6 L4) (not B6) (not Y5))
       (or (= D S6) (not B6) (not Y5))
       (or (= C N6) (not B6) (not Y5))
       (or (= B J6) (not B6) (not Y5))
       (or (= A F6) (not B6) (not Y5))
       (or (= H7 T6) (not B6) (not Y5))
       (or (= G7 R6) (not B6) (not Y5))
       (or (= F7 Q6) (not B6) (not Y5))
       (or (= E7 P6) (not B6) (not Y5))
       (or (= D7 O6) (not B6) (not Y5))
       (or (= C7 M6) (not B6) (not Y5))
       (or (= B7 L6) (not B6) (not Y5))
       (or (= A7 K6) (not B6) (not Y5))
       (or (= Z6 I6) (not B6) (not Y5))
       (or (= Y6 H6) (not B6) (not Y5))
       (or (= X6 G6) (not B6) (not Y5))
       (or (= W6 E6) (not B6) (not Y5))
       (or (= V6 D6) (not B6) (not Y5))
       (or (= U6 C6) (not B6) (not Y5))
       (or (= T6 0) (not B6) (not Y5))
       (or (= S6 C4) (not B6) (not Y5))
       (or (= R6 X3) (not B6) (not Y5))
       (or (not B6) (not Y5) (= Q6 (- 1)))
       (or (= O6 Z3) (not B6) (not Y5))
       (or (= L6 G4) (not B6) (not Y5))
       (or (not B6) (not Y5) (= I6 (- 1)))
       (or (= F6 U4) (not B6) (not Y5))
       (or (not B6) (not Y5) (= E6 (- 1)))
       (or (= D6 S4) (not B6) (not Y5))
       (or (= C6 R4) (not B6) (not Y5))
       (or (= O5 G5) (not E5) (not I5))
       (or (= A2 O5) (not E5) (not I5))
       (or (= A2 P5) (not C5) (not J5))
       (or (not C5) (not P5) (not J5))
       (or (= A2 Q5) (not A5) (not K5))
       (or (not A5) (not Q5) (not K5))
       (or (= A2 R5) (not Y4) (not L5))
       (or (not Y4) (not R5) (not L5))
       (or (= A2 S5) (not W4) (not M5))
       (or (not W4) (not S5) (not M5))
       (or D4 (not H5) (not Z5))
       (or (= A2 T5) (not W3) (not N5))
       (or (not T5) (not W3) (not N5))
       (or (not Z1) (not W3) (not N5))
       (or Z1 (not X4) (not W3))
       (or (not Y1) (not W4) (not M5))
       (or Y1 (not W4) (not Z4))
       (or (not K1) (not Y4) (not L5))
       (or K1 (not Y4) (not B5))
       (or (not D1) (not A5) (not K5))
       (or D1 (not A5) (not D5))
       (or (not W) (not C5) (not J5))
       (or W (not C5) (not F5))
       (or (not A6) (and Y5 B6))
       (or (not Y5) (and H5 Z5))
       (or (not H5) (not (= V4 X5)))
       (or (not H5) (not (= P4 W5)))
       (or (not H5) (not (= J4 V5)))
       (or (not H5) (not (= D4 U5)))
       a!1
       (or (not E5) (= G5 (and O P)))
       (or (not E5) (= N (or L M)))
       (or (not E5) (not (= N P)))
       (or (not E5) (= M (= E4 Q4)))
       (or (not E5) (= L (or J K)))
       (or (not E5) (= K (= E4 K4)))
       (or (not E5) (= J (or H I)))
       (or (not E5) (= I (= Y3 Q4)))
       (or (not E5) (= H (or F G)))
       (or (not E5) (= G (= Y3 K4)))
       (or (not E5) (= F (or E T4)))
       (or (not E5) (= E (= Y3 E4)))
       (or (not E5) (and C5 F5))
       a!2
       (or (not C5) (not (= N4 Q)))
       (or (not C5) (= W (and U V)))
       (or (not C5) (= V (= S4 Q4)))
       (or (not C5) (= U (and S T)))
       (or (not C5) (= T (= R4 0)))
       (or (not C5) (= S (and Q R)))
       (or (not C5) (and A5 D5))
       a!3
       (or (not A5) (not (= H4 X)))
       (or (not A5) (= D1 (and B1 C1)))
       (or (not A5) (= C1 (= M4 K4)))
       (or (not A5) (= B1 (and Z A1)))
       (or (not A5) (= A1 (= L4 0)))
       (or (not A5) (= Z (and X Y)))
       (or (not A5) (and Y4 B5))
       a!4
       (or (not Y4) (not (= B4 E1)))
       (or (not Y4) (= K1 (and I1 J1)))
       (or (not Y4) (= J1 (= G4 E4)))
       (or (not Y4) (= I1 (and G1 H1)))
       (or (not Y4) (= H1 (= F4 0)))
       (or (not Y4) (= G1 (and E1 F1)))
       (or (not Y4) (and W4 Z4))
       a!5
       a!6
       (or (not W4) (= Y1 (and W1 X1)))
       (or (not W4) (= X1 (= A4 Y3)))
       (or (not W4) (= W1 (and U1 V1)))
       (or (not W4) (= V1 (= Z3 0)))
       (or (not W4) (= U1 (and S1 T1)))
       (or (not W4) (= R1 (+ P1 Q1)))
       (or (not W4) (= Q1 (ite V4 1 0)))
       (or (not W4) (= P1 (+ N1 O1)))
       (or (not W4) (= O1 (ite P4 1 0)))
       (or (not W4) (= N1 (+ M1 L1)))
       (or (not W4) (= M1 (ite J4 1 0)))
       (or (not W4) (= L1 (ite D4 1 0)))
       (or (not W4) (and W3 X4))
       (or A2 (not H5))
       (= A6 true)
       (= Z1 (= X3 0))
       (= 2 v_191)))
      )
      (main_1 v_191
        H7
        U6
        V6
        W6
        A
        X6
        Y6
        Z6
        B
        A7
        B7
        C7
        C
        D7
        E7
        F7
        G7
        D
        Q4
        X5
        V4
        K4
        W5
        P4
        E4
        V5
        J4
        Y3
        U5
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3
        Q3
        R3
        S3
        T3
        U3
        V3)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Bool) (U2 Bool) (V2 Int) (W2 Bool) (X2 Bool) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Int) (C3 Bool) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Bool) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Bool) (D5 Bool) (E5 Int) (F5 Bool) (G5 Bool) (H5 Int) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Int) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Bool) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Int) (T6 Bool) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Int) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Bool) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Int) (G8 Bool) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Int) (N8 Bool) (O8 Bool) (P8 Bool) (Q8 Bool) (R8 Bool) (S8 Bool) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Bool) (P9 Bool) (Q9 Bool) (R9 Bool) (S9 Int) (T9 Bool) (U9 Bool) (V9 Bool) (W9 Bool) (X9 Bool) (Y9 Bool) (Z9 Int) (A10 Bool) (B10 Bool) (C10 Bool) (D10 Bool) (E10 Bool) (F10 Bool) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Int) (Q10 Int) (R10 Int) (S10 Int) (T10 Int) (U10 Int) (V10 Int) (W10 Int) (X10 Int) (Y10 Int) (Z10 Int) (A11 Int) (B11 Int) (C11 Bool) (D11 Bool) (E11 Int) (F11 Bool) (G11 Bool) (v_293 Int) (v_294 Int) ) 
    (=>
      (and
        (main_1 v_293
        A2
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3
        Q3
        R3
        S3
        T3
        U3)
        (let ((a!1 (or (not C11) (not (= (<= N6 3) A))))
      (a!2 (or (not V6) (not (= (<= O3 Y2) E1))))
      (a!3 (or (not A10) (not (= (<= 2 B11) K))))
      (a!4 (or (not V9) (not (= (<= G3 S2) M))))
      (a!5 (or (not I8) (not (= (<= K3 V2) V))))
      (a!6 (or (not I5) (not (= (<= S3 B3) N1)))))
  (and (= 1 v_293)
       (or (and B8 P8) (and K8 Q8) (and I8 R8) (and G8 S8) (not N8) (and O8 D8))
       (or (and Q9 B10)
           (and O9 C10)
           (and X9 D10)
           (and V9 E10)
           (not A10)
           (and F10 T9))
       (or (and Q6 B7) (and X6 D7) (and V6 E7) (and T6 F7) (not A7) (and C7 O6))
       (or (and C5 O5) (and K5 P5) (and I5 Q5) (and F5 R5) (not N5))
       (or (= B5 N4) (not C11) (not G11))
       (or (= A5 L4) (not C11) (not G11))
       (or (= Z4 K4) (not C11) (not G11))
       (or (= Y4 J4) (not C11) (not G11))
       (or (= X4 I4) (not C11) (not G11))
       (or (= W4 G4) (not C11) (not G11))
       (or (= V4 F4) (not C11) (not G11))
       (or (= U4 E4) (not C11) (not G11))
       (or (= T4 C4) (not C11) (not G11))
       (or (= S4 B4) (not C11) (not G11))
       (or (= R4 A4) (not C11) (not G11))
       (or (= Q4 Y3) (not C11) (not G11))
       (or (= P4 X3) (not C11) (not G11))
       (or (= O4 W3) (not C11) (not G11))
       (or (= N4 E11) (not C11) (not G11))
       (or (= M4 T1) (not C11) (not G11))
       (or (= L4 N6) (not C11) (not G11))
       (or (= K4 Q) (not C11) (not G11))
       (or (= J4 S1) (not C11) (not G11))
       (or (= I4 M6) (not C11) (not G11))
       (or (= H4 K1) (not C11) (not G11))
       (or (= G4 R1) (not C11) (not G11))
       (or (= F4 J1) (not C11) (not G11))
       (or (= E4 A8) (not C11) (not G11))
       (or (= D4 B1) (not C11) (not G11))
       (or (= Y3 Z) (not C11) (not G11))
       (or (= X3 R) (not C11) (not G11))
       (or (= W3 A11) (not C11) (not G11))
       (or (= Z1 M4) (not C11) (not G11))
       (or (= Y1 H4) (not C11) (not G11))
       (or (= X1 D4) (not C11) (not G11))
       (or (= W1 Z3) (not C11) (not G11))
       (or (= C4 I1) (not C11) (not G11))
       (or (= B4 A1) (not C11) (not G11))
       (or (= A4 N9) (not C11) (not G11))
       (or (= Z3 S) (not C11) (not G11))
       (or (= E9 0) (not K8) (not Q8))
       (or (= D9 J3) (not K8) (not Q8))
       (or (= C9 M8) (not K8) (not Q8))
       (or (= B9 (- 1)) (not K8) (not Q8))
       (or (= B1 E9) (not K8) (not Q8))
       (or (= A1 D9) (not K8) (not Q8))
       (or (= Z B9) (not K8) (not Q8))
       (or (= N9 C9) (not K8) (not Q8))
       (or (= A9 1) (not B8) (not P8))
       (or (= Z8 J3) (not B8) (not P8))
       (or (= Y8 I3) (not B8) (not P8))
       (or (= X8 J3) (not B8) (not P8))
       (or (= B1 A9) (not B8) (not P8))
       (or (= A1 Z8) (not B8) (not P8))
       (or (= Z X8) (not B8) (not P8))
       (or (= N9 Y8) (not B8) (not P8))
       (or (= A8 T7) (not V6) (not E7))
       (or (= V7 0) (not V6) (not E7))
       (or (= K1 V7) (not V6) (not E7))
       (or (= J1 U7) (not V6) (not E7))
       (or (= I1 S7) (not V6) (not E7))
       (or (= U7 O3) (not V6) (not E7))
       (or (= T7 M3) (not V6) (not E7))
       (or (= S7 (- 1)) (not V6) (not E7))
       (or (= A8 H7) (not Q6) (not B7))
       (or (= K1 J7) (not Q6) (not B7))
       (or (= J1 I7) (not Q6) (not B7))
       (or (= I1 G7) (not Q6) (not B7))
       (or (= J7 1) (not Q6) (not B7))
       (or (= I7 N3) (not Q6) (not B7))
       (or (= H7 M3) (not Q6) (not B7))
       (or (= G7 S6) (not Q6) (not B7))
       (or (= Z5 R3) (not K5) (not P5))
       (or (= Y5 M5) (not K5) (not P5))
       (or (= X5 (- 1)) (not K5) (not P5))
       (or (= T1 B6) (not K5) (not P5))
       (or (= S1 Z5) (not K5) (not P5))
       (or (= R1 X5) (not K5) (not P5))
       (or (= N6 A6) (not K5) (not P5))
       (or (= M6 Y5) (not K5) (not P5))
       (or (= B6 0) (not K5) (not P5))
       (or (= A6 H5) (not K5) (not P5))
       (or (not A3) (not O6) (not R6))
       (or X2 (not B8) (not P8))
       (or (not X2) (not B8) (not E8))
       (or L1 (not (= P3 1)) (not N5))
       (or (not L1) (not (= P3 0)) (not N5))
       (or (not L1) (not N5) (not P6))
       (or F1 (not V6) (not E7))
       (or (not F1) (not V6) (not Y6))
       (or T (not (= H3 1)) (not N8))
       (or (not T) (not (= H3 0)) (not N8))
       (or (not D) (not C11) (not G11))
       (or K (not A10) (not D11))
       (or (= S R10) (not X9) (not D10))
       (or (= R Q10) (not X9) (not D10))
       (or (= Q O10) (not X9) (not D10))
       (or (not X9) (= O10 (- 1)) (not D10))
       (or (= A11 P10) (not X9) (not D10))
       (or (= R10 0) (not X9) (not D10))
       (or (= Q10 F3) (not X9) (not D10))
       (or (= P10 Z9) (not X9) (not D10))
       (or (= S V10) (not V9) (not E10))
       (or (= R U10) (not V9) (not E10))
       (or (= Q S10) (not V9) (not E10))
       (or (= A11 T10) (not V9) (not E10))
       (or (= V10 0) (not V9) (not E10))
       (or (= U10 G3) (not V9) (not E10))
       (or (= T10 E3) (not V9) (not E10))
       (or (= S10 (- 1)) (not V9) (not E10))
       (or N (not V9) (not E10))
       (or (not N) (not Y9) (not V9))
       (or T (not N8) (not U9))
       (or (not O) (not T9) (not W9))
       (or (= S J10) (not Q9) (not B10))
       (or (= R I10) (not Q9) (not B10))
       (or (= Q G10) (not Q9) (not B10))
       (or (= J10 1) (not Q9) (not B10))
       (or (= I10 F3) (not Q9) (not B10))
       (or (= G10 S9) (not Q9) (not B10))
       (or (= A11 H10) (not Q9) (not B10))
       (or (= H10 E3) (not Q9) (not B10))
       (or (not T) (not P9) (not N8))
       (or (= S N10) (not O9) (not C10))
       (or (= R M10) (not O9) (not C10))
       (or (= Q K10) (not O9) (not C10))
       (or (= M10 F3) (not O9) (not C10))
       (or (= L10 E3) (not O9) (not C10))
       (or (= A11 L10) (not O9) (not C10))
       (or (= N10 1) (not O9) (not C10))
       (or (= K10 F3) (not O9) (not C10))
       (or U2 (not O9) (not C10))
       (or (not U2) (not O9) (not R9))
       (or (not O8) (not D8) (= W8 1))
       (or (not O8) (not D8) (= V8 J3))
       (or (not O8) (not D8) (= U8 I3))
       (or (not O8) (not D8) (= B1 W8))
       (or (not O8) (not D8) (= A1 V8))
       (or (not O8) (not D8) (= Z T8))
       (or (not O8) (not D8) (= T8 F8))
       (or (not O8) (not D8) (= N9 U8))
       (or (= I9 0) (not I8) (not R8))
       (or (= H9 K3) (not I8) (not R8))
       (or (= G9 I3) (not I8) (not R8))
       (or (= F9 (- 1)) (not I8) (not R8))
       (or (= B1 I9) (not I8) (not R8))
       (or (= A1 H9) (not I8) (not R8))
       (or (= Z F9) (not I8) (not R8))
       (or (= N9 G9) (not I8) (not R8))
       (or W (not I8) (not R8))
       (or (not W) (not I8) (not L8))
       (or (not X) (not G8) (not J8))
       (or (= L9 J3) (not G8) (not S8))
       (or (= K9 I3) (not G8) (not S8))
       (or (= J9 (- 1)) (not G8) (not S8))
       (or (= B1 M9) (not G8) (not S8))
       (or (= A1 L9) (not G8) (not S8))
       (or (= Z J9) (not G8) (not S8))
       (or (= N9 K9) (not G8) (not S8))
       (or (= M9 0) (not G8) (not S8))
       (or X (not G8) (not S8))
       (or (not C7) (not O6) (= A8 L7))
       (or (not C7) (not O6) (= K1 N7))
       (or (not C7) (not O6) (= J1 M7))
       (or (not C7) (not O6) (= I1 K7))
       (or (not C7) (not O6) (= N7 1))
       (or (not C7) (not O6) (= M7 N3))
       (or (not C7) (not O6) (= L7 M3))
       (or (not C7) (not O6) (= K7 N3))
       (or A3 (not O6) (not C7))
       (or C1 (not (= L3 1)) (not A7))
       (or (not A7) (not C1) (not (= L3 0)))
       (or C1 (not A7) (not H8))
       (or (not C8) (not C1) (not A7))
       (or (= A8 P7) (not X6) (not D7))
       (or (= K1 R7) (not X6) (not D7))
       (or (= J1 Q7) (not X6) (not D7))
       (or (= I1 O7) (not X6) (not D7))
       (or (= R7 0) (not X6) (not D7))
       (or (= Q7 N3) (not X6) (not D7))
       (or (= P7 Z6) (not X6) (not D7))
       (or (= O7 (- 1)) (not X6) (not D7))
       (or L1 (not N5) (not U6))
       (or (= A8 X7) (not T6) (not F7))
       (or (= K1 Z7) (not T6) (not F7))
       (or (= J1 Y7) (not T6) (not F7))
       (or (= I1 W7) (not T6) (not F7))
       (or (= Z7 0) (not T6) (not F7))
       (or (= Y7 N3) (not T6) (not F7))
       (or (= X7 M3) (not T6) (not F7))
       (or (= W7 (- 1)) (not T6) (not F7))
       (or G1 (not T6) (not F7))
       (or (not G1) (not T6) (not W6))
       (or (= T1 G6) (not I5) (not Q5))
       (or (= S1 E6) (not I5) (not Q5))
       (or (= R1 C6) (not I5) (not Q5))
       (or (= N6 F6) (not I5) (not Q5))
       (or (= M6 D6) (not I5) (not Q5))
       (or (= G6 0) (not I5) (not Q5))
       (or (= F6 H5) (not I5) (not Q5))
       (or (= E6 S3) (not I5) (not Q5))
       (or (= D6 Q3) (not I5) (not Q5))
       (or (= C6 (- 1)) (not I5) (not Q5))
       (or O1 (not I5) (not Q5))
       (or (not O1) (not I5) (not L5))
       (or V1 (not G5) (not V3))
       (or (= T1 L6) (not F5) (not R5))
       (or (= S1 J6) (not F5) (not R5))
       (or (= R1 H6) (not F5) (not R5))
       (or (= N6 K6) (not F5) (not R5))
       (or (= M6 I6) (not F5) (not R5))
       (or (= L6 0) (not F5) (not R5))
       (or (= K6 H5) (not F5) (not R5))
       (or (= J6 R3) (not F5) (not R5))
       (or (= I6 Q3) (not F5) (not R5))
       (or (= H6 (- 1)) (not F5) (not R5))
       (or P1 (not F5) (not R5))
       (or (not J5) (not P1) (not F5))
       (or (not V1) (not V3) (not D5))
       (or (not C5) (= W5 1) (not O5))
       (or (not C5) (= V5 T3) (not O5))
       (or (not C5) (= U5 R3) (not O5))
       (or (not C5) (= T5 Q3) (not O5))
       (or (not C5) (= S5 E5) (not O5))
       (or (not C5) (= T1 W5) (not O5))
       (or (not C5) (= S1 U5) (not O5))
       (or (not C5) (= R1 S5) (not O5))
       (or (not C5) (= N6 V5) (not O5))
       (or (not C5) (= M6 T5) (not O5))
       (or (not F10) (not T9) (= S Z10))
       (or (not F10) (not T9) (= R Y10))
       (or (not F10) (not T9) (= Q W10))
       (or (not F10) (not T9) (= A11 X10))
       (or (not F10) (not T9) (= Z10 0))
       (or (not F10) (not T9) (= Y10 F3))
       (or (not F10) (not T9) (= X10 E3))
       (or (not F10) (not T9) (= W10 (- 1)))
       (or (not F10) (not T9) O)
       (or (not F11) (and C11 G11))
       a!1
       (or (not C11) (= D (and A C)))
       (or (not C11) (= B (= B11 1)))
       (or (not C11) (not (= B C)))
       (or (not C11) (= E11 (+ 1 D3)))
       (or (not C11) (and A10 D11))
       (or (not K8) (= U (= K3 V2)))
       (or (not K8) (= M8 (ite U 1 I3)))
       (or (not K8) (and I8 L8))
       (or (not D8) (= Y (= J3 V2)))
       (or (not D8) (= F8 (ite Y (- 1) J3)))
       (or (not D8) (and B8 E8))
       (or (not B8) (and A7 C8))
       a!2
       (or (not V6) (= F1 (or E1 Z2)))
       (or (not V6) (and T6 W6))
       (or (not Q6) (= H1 (= N3 Y2)))
       (or (not Q6) (= S6 (ite H1 (- 1) N3)))
       (or (not Q6) (and O6 R6))
       (or (not O6) (and N5 P6))
       (or (not K5) (= M1 (= S3 B3)))
       (or (not K5) (= M5 (ite M1 1 Q3)))
       (or (not K5) (and I5 L5))
       (or V1 (not (= U3 1)))
       (or (not V1) (not (= U3 0)))
       a!3
       (or (not A10) (= J A11))
       (or (not A10) (= I (+ G H)))
       (or (not A10) (= H N9))
       (or (not A10) (= G (+ F E)))
       (or (not A10) (= F A8))
       (or (not A10) (= E M6))
       (or (not A10) (= B11 (+ I J)))
       (or (not X9) (= L (= G3 S2)))
       (or (not X9) (= Z9 (ite L 1 E3)))
       (or (not X9) (and V9 Y9))
       a!4
       (or (not V9) (= N (or M T2)))
       (or (not V9) (and T9 W9))
       (or (not T9) (= O (= G3 (- 1))))
       (or (not T9) (and U9 N8))
       (or (not Q9) (= P (= F3 S2)))
       (or (not Q9) (= S9 (ite P (- 1) F3)))
       (or (not Q9) (and O9 R9))
       (or (not O9) (and P9 N8))
       a!5
       (or (not I8) (= W (or V W2)))
       (or (not I8) (and G8 J8))
       (or (not G8) (= X (= K3 (- 1))))
       (or (not G8) (and A7 H8))
       (or (not X6) (= D1 (= O3 Y2)))
       (or (not X6) (= Z6 (ite D1 1 M3)))
       (or (not X6) (and V6 Y6))
       (or (not T6) (= G1 (= O3 (- 1))))
       (or (not T6) (and U6 N5))
       a!6
       (or (not I5) (= O1 (or N1 C3)))
       (or (not I5) (and F5 J5))
       (or (not F5) (= P1 (= S3 (- 1))))
       (or (not F5) (= H5 (+ 1 T3)))
       (or (not F5) (and G5 V3))
       (or (not C5) (= Q1 (= R3 B3)))
       (or (not C5) (= E5 (ite Q1 (- 1) R3)))
       (or (not C5) (and D5 V3))
       (= F11 true)
       (= U1 true)
       (not (= (<= 8 D3) U1))
       (= 1 v_294)))
      )
      (main_1 v_294
        A2
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        B5
        O4
        P4
        Q4
        W1
        R4
        S4
        T4
        X1
        U4
        V4
        W4
        Y1
        X4
        Y4
        Z4
        A5
        Z1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Int) (S2 Bool) (T2 Bool) (U2 Int) (V2 Bool) (W2 Bool) (X2 Int) (Y2 Bool) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Int) (V3 Bool) (W3 Bool) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Bool) (C4 Int) (D4 Bool) (E4 Bool) (F4 Bool) (G4 Bool) (H4 Bool) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Int) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Int) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Bool) (V5 Bool) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Bool) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Int) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Int) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Bool) (I7 Bool) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Bool) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Int) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Bool) (O8 Bool) (P8 Int) (Q8 Bool) (R8 Bool) (S8 Bool) (T8 Bool) (U8 Bool) (V8 Bool) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Int) (Q9 Int) (R9 Int) (S9 Bool) (T9 Bool) (U9 Int) (V9 Bool) (W9 Bool) (X9 Bool) (Y9 Bool) (Z9 Bool) (v_260 Int) (v_261 Int) ) 
    (=>
      (and
        (main_1 v_260
        W1
        X1
        Y1
        Z1
        A2
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3
        Q3)
        (let ((a!1 (or (not S9) (not (= (<= D5 3) A))))
      (a!2 (or (not Y6) (not (= (<= G3 R2) V))))
      (a!3 (or (not L5) (not (= (<= K3 U2) E1))))
      (a!4 (or (not Q8) (not (= (<= 2 R9) K))))
      (a!5 (or (not L8) (not (= (<= C3 O2) M))))
      (a!6 (or (not Y3) (not (= (<= O3 X2) N1)))))
  (and (= 1 v_260)
       (or (and T6 E7) (and A7 G7) (and W6 I7) (not D7) (and H7 Y6) (and F7 R6))
       (or (and G8 R8) (and E8 S8) (and N8 T8) (and L8 U8) (and J8 V8) (not Q8))
       (or (and N5 T5) (not Q5) (and V5 J5) (and U5 L5) (and S5 E5) (and R5 G5))
       (or (and V3 H4) (and S3 E4) (and A4 F4) (and Y3 G4) (not D4))
       (or D (not W9) (not S9))
       (or (and Q8 X9) (not V9) (and W9 S9))
       (or T (not D7) (not (= D3 1)))
       (or (not D7) (not T) (not (= D3 0)))
       (or (= D8 S7) (not G7) (not A7))
       (or (= U7 0) (not G7) (not A7))
       (or (= T7 F3) (not G7) (not A7))
       (or (= S7 C7) (not G7) (not A7))
       (or (not G7) (not A7) (= R7 (- 1)))
       (or (= B1 U7) (not G7) (not A7))
       (or (= A1 T7) (not G7) (not A7))
       (or (= Z R7) (not G7) (not A7))
       (or (= D8 A8) (not W6) (not I7))
       (or (= C8 0) (not W6) (not I7))
       (or (= B8 F3) (not W6) (not I7))
       (or (= A8 E3) (not W6) (not I7))
       (or (not W6) (not I7) (= Z7 (- 1)))
       (or (= B1 C8) (not W6) (not I7))
       (or (= A1 B8) (not W6) (not I7))
       (or (= Z Z7) (not W6) (not I7))
       (or X (not W6) (not I7))
       (or (not T2) (not U6) (not R6))
       (or (not U5) (not L5) (= K1 L6))
       (or (not U5) (not L5) (= J1 K6))
       (or (not U5) (not L5) (= I1 I6))
       (or (not U5) (not L5) (= Q6 J6))
       (or (not U5) (not L5) (= L6 0))
       (or (not U5) (not L5) (= K6 K3))
       (or (not U5) (not L5) (= J6 I3))
       (or (not U5) (not L5) (= I6 (- 1)))
       (or F1 (not U5) (not L5))
       (or (not R5) (not G5) (= K1 Z5))
       (or (not R5) (not G5) (= J1 Y5))
       (or (not R5) (not G5) (= I1 W5))
       (or (not R5) (not G5) (= Q6 X5))
       (or (not R5) (not G5) (= Z5 1))
       (or (not R5) (not G5) (= Y5 J3))
       (or (not R5) (not G5) (= X5 I3))
       (or (not R5) (not G5) (= W5 I5))
       (or (not F1) (not O5) (not L5))
       (or L1 (not D4) (not (= L3 1)))
       (or (not D4) (not L1) (not (= L3 0)))
       (or (not L1) (not D4) (not F5))
       (or L1 (not D4) (not K5))
       (or (not K) (not Q8) (not X9))
       (or K (not Q8) (not T9))
       (or (= S H9) (not T8) (not N8))
       (or (= R G9) (not T8) (not N8))
       (or (= Q E9) (not T8) (not N8))
       (or (= H9 0) (not T8) (not N8))
       (or (= F9 P8) (not T8) (not N8))
       (or (not T8) (= E9 (- 1)) (not N8))
       (or (= Q9 F9) (not T8) (not N8))
       (or (= G9 B3) (not T8) (not N8))
       (or (= S L9) (not L8) (not U8))
       (or (= R K9) (not L8) (not U8))
       (or (= Q I9) (not L8) (not U8))
       (or (= Q9 J9) (not L8) (not U8))
       (or (= L9 0) (not L8) (not U8))
       (or (= K9 C3) (not L8) (not U8))
       (or (= J9 A3) (not L8) (not U8))
       (or (not L8) (= I9 (- 1)) (not U8))
       (or N (not L8) (not U8))
       (or (not N) (not L8) (not O8))
       (or (not K8) (not D7) T)
       (or (= S P9) (not J8) (not V8))
       (or (= R O9) (not J8) (not V8))
       (or (= Q M9) (not J8) (not V8))
       (or (= Q9 N9) (not J8) (not V8))
       (or (= P9 0) (not J8) (not V8))
       (or (= O9 B3) (not J8) (not V8))
       (or (= N9 A3) (not J8) (not V8))
       (or (not J8) (not V8) (= M9 (- 1)))
       (or O (not J8) (not V8))
       (or (not O) (not J8) (not M8))
       (or (= S Z8) (not R8) (not G8))
       (or (= R Y8) (not R8) (not G8))
       (or (= Q W8) (not R8) (not G8))
       (or (= Z8 1) (not R8) (not G8))
       (or (= Y8 B3) (not R8) (not G8))
       (or (= Q9 X8) (not R8) (not G8))
       (or (= X8 A3) (not R8) (not G8))
       (or (= W8 I8) (not R8) (not G8))
       (or (not F8) (not D7) (not T))
       (or (= S D9) (not S8) (not E8))
       (or (= R C9) (not S8) (not E8))
       (or (= Q A9) (not S8) (not E8))
       (or (= C9 B3) (not S8) (not E8))
       (or (= B9 A3) (not S8) (not E8))
       (or (= Q9 B9) (not S8) (not E8))
       (or (= D9 1) (not S8) (not E8))
       (or (= A9 B3) (not S8) (not E8))
       (or Q2 (not S8) (not E8))
       (or (not Q2) (not H8) (not E8))
       (or (not H7) (not Y6) (= D8 W7))
       (or (not H7) (not Y6) (= Y7 0))
       (or (not H7) (not Y6) (= X7 G3))
       (or (not H7) (not Y6) (= W7 E3))
       (or (not H7) (not Y6) (= V7 (- 1)))
       (or (not H7) (not Y6) (= B1 Y7))
       (or (not H7) (not Y6) (= A1 X7))
       (or (not H7) (not Y6) (= Z V7))
       (or W (not H7) (not Y6))
       (or (not F7) (not R6) (= D8 O7))
       (or (not F7) (not R6) (= Q7 1))
       (or (not F7) (not R6) (= P7 F3))
       (or (not F7) (not R6) (= O7 E3))
       (or (not F7) (not R6) (= N7 F3))
       (or (not F7) (not R6) (= B1 Q7))
       (or (not F7) (not R6) (= A1 P7))
       (or (not F7) (not R6) (= Z N7))
       (or T2 (not R6) (not F7))
       (or (not W) (not B7) (not Y6))
       (or (not Z6) (not W6) (not X))
       (or (= L7 F3) (not E7) (not T6))
       (or (= D8 K7) (not E7) (not T6))
       (or (= B1 M7) (not E7) (not T6))
       (or (= A1 L7) (not E7) (not T6))
       (or (= Z J7) (not E7) (not T6))
       (or (= M7 1) (not E7) (not T6))
       (or (= K7 E3) (not E7) (not T6))
       (or (= J7 V6) (not E7) (not T6))
       (or (not V5) (not J5) (= O6 J3))
       (or (not V5) (not J5) (= K1 P6))
       (or (not V5) (not J5) (= J1 O6))
       (or (not V5) (not J5) (= I1 M6))
       (or (not V5) (not J5) (= Q6 N6))
       (or (not V5) (not J5) (= P6 0))
       (or (not V5) (not J5) (= N6 I3))
       (or (not V5) (not J5) (= M6 (- 1)))
       (or (not V5) (not J5) G1)
       (or (not S5) (not E5) (= K1 D6))
       (or (not S5) (not E5) (= J1 C6))
       (or (not S5) (not E5) (= I1 A6))
       (or (not S5) (not E5) (= Q6 B6))
       (or (not S5) (not E5) (= D6 1))
       (or (not S5) (not E5) (= C6 J3))
       (or (not S5) (not E5) (= B6 I3))
       (or (not S5) (not E5) (= A6 J3))
       (or C1 (not Q5) (not (= H3 1)))
       (or (not Q5) (not C1) (not (= H3 0)))
       (or (not C1) (not Q5) (not S6))
       (or C1 (not Q5) (not X6))
       (or (= K1 H6) (not T5) (not N5))
       (or (= J1 G6) (not T5) (not N5))
       (or (= I1 E6) (not T5) (not N5))
       (or (= Q6 F6) (not T5) (not N5))
       (or (= H6 0) (not T5) (not N5))
       (or (= G6 J3) (not T5) (not N5))
       (or (= F6 P5) (not T5) (not N5))
       (or (not T5) (not N5) (= E6 (- 1)))
       (or (not M5) (not J5) (not G1))
       (or (= T1 R4) (not A4) (not F4))
       (or (= S1 P4) (not A4) (not F4))
       (or (= R4 0) (not A4) (not F4))
       (or (= Q4 X3) (not A4) (not F4))
       (or (= P4 N3) (not A4) (not F4))
       (or (= O4 C4) (not A4) (not F4))
       (or (= N4 (- 1)) (not A4) (not F4))
       (or (= R1 N4) (not A4) (not F4))
       (or (= D5 Q4) (not A4) (not F4))
       (or (= C5 O4) (not A4) (not F4))
       (or (= T1 W4) (not G4) (not Y3))
       (or (= S1 U4) (not G4) (not Y3))
       (or (not G4) (not Y3) (= S4 (- 1)))
       (or (= R1 S4) (not G4) (not Y3))
       (or (= D5 V4) (not G4) (not Y3))
       (or (= C5 T4) (not G4) (not Y3))
       (or (= W4 0) (not G4) (not Y3))
       (or (= V4 X3) (not G4) (not Y3))
       (or (= U4 O3) (not G4) (not Y3))
       (or (= T4 M3) (not G4) (not Y3))
       (or O1 (not G4) (not Y3))
       (or (not O1) (not B4) (not Y3))
       (or (not V3) (= T1 B5) (not H4))
       (or (not V3) (= S1 Z4) (not H4))
       (or (not V3) (= R1 X4) (not H4))
       (or (not V3) (= D5 A5) (not H4))
       (or (not V3) (= C5 Y4) (not H4))
       (or (not V3) (= B5 0) (not H4))
       (or (not V3) (= A5 X3) (not H4))
       (or (not V3) (= Z4 N3) (not H4))
       (or (not V3) (= Y4 M3) (not H4))
       (or (not V3) (not H4) (= X4 (- 1)))
       (or (not V3) P1 (not H4))
       (or (not V3) (not P1) (not Z3))
       (or (= K4 N3) (not E4) (not S3))
       (or (= T1 M4) (not E4) (not S3))
       (or (= S1 K4) (not E4) (not S3))
       (or (= M4 1) (not E4) (not S3))
       (or (= L4 P3) (not E4) (not S3))
       (or (= R1 I4) (not E4) (not S3))
       (or (= D5 L4) (not E4) (not S3))
       (or (= C5 J4) (not E4) (not S3))
       (or (= J4 M3) (not E4) (not S3))
       (or (= I4 U3) (not E4) (not S3))
       (or V1 (not W3) (not R3))
       (or (not V1) (not R3) (not T3))
       (or (not W2) (not H5) (not E5))
       (or W2 (not E5) (not S5))
       a!1
       (or (not S9) (= D (and A C)))
       (or (not S9) (= B (= R9 1)))
       (or (not S9) (not (= B C)))
       (or (not S9) (= U9 (+ 1 Z2)))
       (or (not S9) (and Q8 T9))
       a!2
       (or (not Y6) (= W (or V S2)))
       (or (not Y6) (and Z6 W6))
       (or (not R6) (and Q5 S6))
       a!3
       (or (not L5) (= F1 (or E1 V2)))
       (or (not L5) (and M5 J5))
       (or (not G5) (= H1 (= J3 U2)))
       (or (not G5) (= I5 (ite H1 (- 1) J3)))
       (or (not G5) (and H5 E5))
       (or (not E5) (and D4 F5))
       (or (not Y9) (and V9 Z9))
       (or (not A7) (= U (= G3 R2)))
       (or (not A7) (= C7 (ite U 1 E3)))
       (or (not A7) (and B7 Y6))
       (or (not W6) (= X (= G3 (- 1))))
       (or (not W6) (and Q5 X6))
       (or (not J5) (= G1 (= K3 (- 1))))
       (or (not J5) (and D4 K5))
       (or V1 (not (= Q3 1)))
       (or (not V1) (not (= Q3 0)))
       a!4
       (or (not Q8) (= J Q9))
       (or (not Q8) (= I (+ G H)))
       (or (not Q8) (= H D8))
       (or (not Q8) (= G (+ F E)))
       (or (not Q8) (= F Q6))
       (or (not Q8) (= E C5))
       (or (not Q8) (= R9 (+ I J)))
       (or (not N8) (= L (= C3 O2)))
       (or (not N8) (= P8 (ite L 1 A3)))
       (or (not N8) (and L8 O8))
       a!5
       (or (not L8) (= N (or M P2)))
       (or (not L8) (and J8 M8))
       (or (not J8) (= O (= C3 (- 1))))
       (or (not J8) (and K8 D7))
       (or (not G8) (= P (= B3 O2)))
       (or (not G8) (= I8 (ite P (- 1) B3)))
       (or (not G8) (and E8 H8))
       (or (not E8) (and F8 D7))
       (or (not T6) (= Y (= F3 R2)))
       (or (not T6) (= V6 (ite Y (- 1) F3)))
       (or (not T6) (and U6 R6))
       (or (not N5) (= D1 (= K3 U2)))
       (or (not N5) (= P5 (ite D1 1 I3)))
       (or (not N5) (and O5 L5))
       (or (not A4) (= M1 (= O3 X2)))
       (or (not A4) (= C4 (ite M1 1 M3)))
       (or (not A4) (and Y3 B4))
       a!6
       (or (not Y3) (= O1 (or Y2 N1)))
       (or (not Y3) (and V3 Z3))
       (or (not V3) (= P1 (= O3 (- 1))))
       (or (not V3) (= X3 (+ 1 P3)))
       (or (not V3) (and R3 W3))
       (or (not S3) (= Q1 (= N3 X2)))
       (or (not S3) (= U3 (ite Q1 (- 1) N3)))
       (or (not S3) (and R3 T3))
       (= U1 true)
       (= Y9 true)
       (not (= (<= 8 Z2) U1))
       (= 3 v_261)))
      )
      (main_1 v_261
        W1
        X1
        Y1
        Z1
        A2
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3
        Q3)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Bool) (T2 Bool) (U2 Int) (V2 Bool) (W2 Bool) (X2 Int) (Y2 Bool) (Z2 Bool) (A3 Int) (B3 Bool) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Bool) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Bool) (C5 Bool) (D5 Int) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Int) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Bool) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Int) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Int) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Bool) (Y7 Bool) (Z7 Bool) (A8 Bool) (B8 Int) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Int) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Bool) (O8 Bool) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Bool) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Int) (P9 Bool) (Q9 Bool) (R9 Bool) (S9 Bool) (T9 Bool) (U9 Bool) (V9 Int) (W9 Bool) (X9 Bool) (Y9 Bool) (Z9 Bool) (A10 Bool) (B10 Bool) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Int) (Q10 Int) (R10 Int) (S10 Int) (T10 Int) (U10 Int) (V10 Int) (W10 Int) (X10 Int) (Y10 Bool) (Z10 Bool) (A11 Int) (B11 Bool) (C11 Bool) (v_289 Int) (v_290 Int) ) 
    (=>
      (and
        (main_1 v_289
        Z1
        A2
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3
        Q3
        R3
        S3
        T3)
        (let ((a!1 (or (not Y10) (not (= (<= J6 3) A))))
      (a!2 (or (not R6) (not (= (<= K2 X2) E1))))
      (a!3 (or (not W9) (not (= (<= 2 X10) K))))
      (a!4 (or (not R9) (not (= (<= C2 R2) M))))
      (a!5 (or (not E8) (not (= (<= G2 U2) V))))
      (a!6 (or (not E5) (not (= (<= O2 A3) N1)))))
  (and (= 2 v_289)
       (or (and E8 L8) (and C8 M8) (and Z7 N8) (not J8) (and O8 X7) (and K8 G8))
       (or (and T9 X9)
           (and R9 Y9)
           (and P9 Z9)
           (and M9 A10)
           (not W9)
           (and B10 K9))
       (or (and T6 X6) (and P6 Z6) (and M6 A7) (and K6 B7) (not W6) (and Y6 R6))
       (or (and G5 K5) (and E5 L5) (and B5 M5) (not J5) (and N5 U3))
       (or (= Z4 K4) (not Y10) (not C11))
       (or (= Y4 J4) (not Y10) (not C11))
       (or (= A5 M4) (not Y10) (not C11))
       (or (= X4 I4) (not Y10) (not C11))
       (or (= W4 H4) (not Y10) (not C11))
       (or (= V4 F4) (not Y10) (not C11))
       (or (= U4 E4) (not Y10) (not C11))
       (or (= T4 D4) (not Y10) (not C11))
       (or (= S4 B4) (not Y10) (not C11))
       (or (= R4 A4) (not Y10) (not C11))
       (or (= Q4 Z3) (not Y10) (not C11))
       (or (= P4 X3) (not Y10) (not C11))
       (or (= O4 W3) (not Y10) (not C11))
       (or (= N4 V3) (not Y10) (not C11))
       (or (= M4 A11) (not Y10) (not C11))
       (or (= L4 U1) (not Y10) (not C11))
       (or (= K4 J6) (not Y10) (not C11))
       (or (= J4 Q) (not Y10) (not C11))
       (or (= I4 T1) (not Y10) (not C11))
       (or (= H4 I6) (not Y10) (not C11))
       (or (= G4 K1) (not Y10) (not C11))
       (or (= F4 S1) (not Y10) (not C11))
       (or (= E4 J1) (not Y10) (not C11))
       (or (= D4 W7) (not Y10) (not C11))
       (or (= C4 B1) (not Y10) (not C11))
       (or (= B4 I1) (not Y10) (not C11))
       (or (= A4 A1) (not Y10) (not C11))
       (or (= Z3 J9) (not Y10) (not C11))
       (or (= Y1 L4) (not Y10) (not C11))
       (or (= X1 G4) (not Y10) (not C11))
       (or (= W1 C4) (not Y10) (not C11))
       (or (= V1 Y3) (not Y10) (not C11))
       (or (= Y3 S) (not Y10) (not C11))
       (or (= X3 Z) (not Y10) (not C11))
       (or (= W3 R) (not Y10) (not C11))
       (or (= V3 W10) (not Y10) (not C11))
       (or (not D) (not Y10) (not C11))
       (or (= B1 E9) (not Z7) (not N8))
       (or (= A1 D9) (not Z7) (not N8))
       (or (= Z B9) (not Z7) (not N8))
       (or (= E9 1) (not Z7) (not N8))
       (or (= D9 F2) (not Z7) (not N8))
       (or (= C9 E2) (not Z7) (not N8))
       (or (= B9 B8) (not Z7) (not N8))
       (or (= J9 C9) (not Z7) (not N8))
       (or (not F1) (not R6) (not U6))
       (or (= K1 R7) (not M6) (not A7))
       (or (= J1 Q7) (not M6) (not A7))
       (or (= I1 O7) (not M6) (not A7))
       (or (= W7 P7) (not M6) (not A7))
       (or (= R7 1) (not M6) (not A7))
       (or (= Q7 J2) (not M6) (not A7))
       (or (= P7 I2) (not M6) (not A7))
       (or (= O7 O6) (not M6) (not A7))
       (or (= K1 V7) (not K6) (not B7))
       (or (= J1 U7) (not K6) (not B7))
       (or (= I1 S7) (not K6) (not B7))
       (or (= W7 T7) (not K6) (not B7))
       (or (= V7 1) (not K6) (not B7))
       (or (= U7 J2) (not K6) (not B7))
       (or (= T7 I2) (not K6) (not B7))
       (or (= S7 J2) (not K6) (not B7))
       (or Z2 (not K6) (not B7))
       (or (not Z2) (not K6) (not N6))
       (or (= S5 0) (not G5) (not K5))
       (or (= R5 D5) (not G5) (not K5))
       (or (= Q5 N2) (not G5) (not K5))
       (or (= P5 I5) (not G5) (not K5))
       (or (not G5) (not K5) (= O5 (- 1)))
       (or (= U1 S5) (not G5) (not K5))
       (or (= T1 Q5) (not G5) (not K5))
       (or (= S1 O5) (not G5) (not K5))
       (or (= J6 R5) (not G5) (not K5))
       (or (= I6 P5) (not G5) (not K5))
       (or (not W2) (not X7) (not A8))
       (or L1 (not J5) (not (= L2 1)))
       (or (not L1) (not J5) (not (= L2 0)))
       (or (not L1) (not J5) (not L6))
       (or T (not J8) (not (= D2 1)))
       (or (not T) (not J8) (not (= D2 0)))
       (or K (not W9) (not Z10))
       (or (= S F10) (not T9) (not X9))
       (or (= R E10) (not T9) (not X9))
       (or (= Q C10) (not T9) (not X9))
       (or (= F10 0) (not T9) (not X9))
       (or (= E10 B2) (not T9) (not X9))
       (or (not T9) (not X9) (= C10 (- 1)))
       (or (= W10 D10) (not T9) (not X9))
       (or (= D10 V9) (not T9) (not X9))
       (or (= S J10) (not R9) (not Y9))
       (or (= R I10) (not R9) (not Y9))
       (or (= Q G10) (not R9) (not Y9))
       (or (= I10 C2) (not R9) (not Y9))
       (or (= H10 A2) (not R9) (not Y9))
       (or (= W10 H10) (not R9) (not Y9))
       (or (= J10 0) (not R9) (not Y9))
       (or (not R9) (not Y9) (= G10 (- 1)))
       (or N (not R9) (not Y9))
       (or (not N) (not U9) (not R9))
       (or T (not J8) (not Q9))
       (or (= S N10) (not P9) (not Z9))
       (or (= R M10) (not P9) (not Z9))
       (or (= Q K10) (not P9) (not Z9))
       (or (= K10 (- 1)) (not P9) (not Z9))
       (or (= W10 L10) (not P9) (not Z9))
       (or (= N10 0) (not P9) (not Z9))
       (or (= M10 B2) (not P9) (not Z9))
       (or (= L10 A2) (not P9) (not Z9))
       (or O (not P9) (not Z9))
       (or (not O) (not P9) (not S9))
       (or (= S R10) (not M9) (not A10))
       (or (= R Q10) (not M9) (not A10))
       (or (= Q O10) (not M9) (not A10))
       (or (= W10 P10) (not M9) (not A10))
       (or (= R10 1) (not M9) (not A10))
       (or (= Q10 B2) (not M9) (not A10))
       (or (= P10 A2) (not M9) (not A10))
       (or (= O10 O9) (not M9) (not A10))
       (or (not T) (not L9) (not J8))
       (or (not T2) (not K9) (not N9))
       (or (not O8) (not X7) (= B1 I9))
       (or (not O8) (not X7) (= A1 H9))
       (or (not O8) (not X7) (= Z F9))
       (or (not O8) (not X7) (= H9 F2))
       (or (not O8) (not X7) (= G9 E2))
       (or (not O8) (not X7) (= F9 F2))
       (or (not O8) (not X7) (= J9 G9))
       (or (not O8) (not X7) (= I9 1))
       (or W2 (not X7) (not O8))
       (or (not K8) (not G8) (= B1 S8))
       (or (not K8) (not G8) (= A1 R8))
       (or (not K8) (not G8) (= Z P8))
       (or (not K8) (not G8) (= S8 0))
       (or (not K8) (not G8) (= R8 F2))
       (or (not K8) (not G8) (= Q8 I8))
       (or (not K8) (not G8) (= P8 (- 1)))
       (or (not K8) (not G8) (= J9 Q8))
       (or (= B1 W8) (not E8) (not L8))
       (or (= A1 V8) (not E8) (not L8))
       (or (= Z T8) (not E8) (not L8))
       (or (= W8 0) (not E8) (not L8))
       (or (= V8 G2) (not E8) (not L8))
       (or (= U8 E2) (not E8) (not L8))
       (or (not E8) (not L8) (= T8 (- 1)))
       (or (= J9 U8) (not E8) (not L8))
       (or W (not E8) (not L8))
       (or (not W) (not E8) (not H8))
       (or (= B1 A9) (not C8) (not M8))
       (or (= A1 Z8) (not C8) (not M8))
       (or (= Z X8) (not C8) (not M8))
       (or (= A9 0) (not C8) (not M8))
       (or (= Z8 F2) (not C8) (not M8))
       (or (= Y8 E2) (not C8) (not M8))
       (or (= X8 (- 1)) (not C8) (not M8))
       (or (= J9 Y8) (not C8) (not M8))
       (or X (not C8) (not M8))
       (or (not X) (not C8) (not F8))
       (or (not Y6) (not R6) (= K1 J7))
       (or (not Y6) (not R6) (= J1 I7))
       (or (not Y6) (not R6) (= I1 G7))
       (or (not Y6) (not R6) (= W7 H7))
       (or (not Y6) (not R6) (= J7 0))
       (or (not Y6) (not R6) (= I7 K2))
       (or (not Y6) (not R6) (= H7 I2))
       (or (not Y6) (not R6) (= G7 (- 1)))
       (or (not Y6) (not R6) F1)
       (or C1 (not W6) (not (= H2 1)))
       (or (not W6) (not C1) (not (= H2 0)))
       (or C1 (not W6) (not D8))
       (or (not Y7) (not C1) (not W6))
       (or (= K1 F7) (not T6) (not X6))
       (or (= J1 E7) (not T6) (not X6))
       (or (= I1 C7) (not T6) (not X6))
       (or (= W7 D7) (not T6) (not X6))
       (or (= F7 0) (not T6) (not X6))
       (or (= E7 J2) (not T6) (not X6))
       (or (= D7 V6) (not T6) (not X6))
       (or (not T6) (not X6) (= C7 (- 1)))
       (or L1 (not J5) (not Q6))
       (or (= K1 N7) (not P6) (not Z6))
       (or (= J1 M7) (not P6) (not Z6))
       (or (= I1 K7) (not P6) (not Z6))
       (or (= W7 L7) (not P6) (not Z6))
       (or (= N7 0) (not P6) (not Z6))
       (or (= M7 J2) (not P6) (not Z6))
       (or (= L7 I2) (not P6) (not Z6))
       (or (= K7 (- 1)) (not P6) (not Z6))
       (or G1 (not P6) (not Z6))
       (or (not G1) (not P6) (not S6))
       (or (not N5) (not U3) (= U1 H6))
       (or (not N5) (not U3) (= T1 F6))
       (or (not N5) (not U3) (= S1 D6))
       (or (not N5) (not U3) (= J6 G6))
       (or (not N5) (not U3) (= I6 E6))
       (or (not N5) (not U3) (= H6 1))
       (or (not N5) (not U3) (= G6 P2))
       (or (not N5) (not U3) (= F6 N2))
       (or (not N5) (not U3) (= E6 M2))
       (or (not N5) (not U3) (= D6 N2))
       (or (not R1) (not N5) (not U3))
       (or (= V5 O2) (not E5) (not L5))
       (or (= U5 M2) (not E5) (not L5))
       (or (= T5 (- 1)) (not E5) (not L5))
       (or (= U1 X5) (not E5) (not L5))
       (or (= T1 V5) (not E5) (not L5))
       (or (= S1 T5) (not E5) (not L5))
       (or (= J6 W5) (not E5) (not L5))
       (or (= I6 U5) (not E5) (not L5))
       (or (= X5 0) (not E5) (not L5))
       (or (= W5 D5) (not E5) (not L5))
       (or O1 (not E5) (not L5))
       (or (not O1) (not E5) (not H5))
       (or R1 (not C5) (not U3))
       (or (= U1 C6) (not B5) (not M5))
       (or (= T1 A6) (not B5) (not M5))
       (or (= S1 Y5) (not B5) (not M5))
       (or (= J6 B6) (not B5) (not M5))
       (or (= I6 Z5) (not B5) (not M5))
       (or (= C6 0) (not B5) (not M5))
       (or (= B6 D5) (not B5) (not M5))
       (or (= A6 N2) (not B5) (not M5))
       (or (= Z5 M2) (not B5) (not M5))
       (or (= Y5 (- 1)) (not B5) (not M5))
       (or P1 (not B5) (not M5))
       (or (not F5) (not P1) (not B5))
       (or (not B10) (not K9) (= S V10))
       (or (not B10) (not K9) (= R U10))
       (or (not B10) (not K9) (= Q S10))
       (or (not B10) (not K9) (= W10 T10))
       (or (not B10) (not K9) (= V10 1))
       (or (not B10) (not K9) (= U10 B2))
       (or (not B10) (not K9) (= T10 A2))
       (or (not B10) (not K9) (= S10 B2))
       (or (not B10) (not K9) T2)
       (or (not B11) (and Y10 C11))
       a!1
       (or (not Y10) (= D (and A C)))
       (or (not Y10) (= B (= X10 1)))
       (or (not Y10) (not (= B C)))
       (or (not Y10) (= A11 (+ 1 Z1)))
       (or (not Y10) (and W9 Z10))
       (or (not G8) (= U (= G2 U2)))
       (or (not G8) (= I8 (ite U 1 E2)))
       (or (not G8) (and E8 H8))
       (or (not Z7) (= Y (= F2 U2)))
       (or (not Z7) (= B8 (ite Y (- 1) F2)))
       (or (not Z7) (and X7 A8))
       (or (not X7) (and W6 Y7))
       a!2
       (or (not R6) (= F1 (or Y2 E1)))
       (or (not R6) (and P6 S6))
       (or (not M6) (= H1 (= J2 X2)))
       (or (not M6) (= O6 (ite H1 (- 1) J2)))
       (or (not M6) (and K6 N6))
       (or (not K6) (and J5 L6))
       (or (not G5) (= M1 (= O2 A3)))
       (or (not G5) (= I5 (ite M1 1 M2)))
       (or (not G5) (and E5 H5))
       (or R1 (not (= Q2 1)))
       (or (not R1) (not (= Q2 0)))
       a!3
       (or (not W9) (= J W10))
       (or (not W9) (= I (+ G H)))
       (or (not W9) (= H J9))
       (or (not W9) (= G (+ F E)))
       (or (not W9) (= F W7))
       (or (not W9) (= E I6))
       (or (not W9) (= X10 (+ I J)))
       (or (not T9) (= L (= C2 R2)))
       (or (not T9) (= V9 (ite L 1 A2)))
       (or (not T9) (and R9 U9))
       a!4
       (or (not R9) (= N (or S2 M)))
       (or (not R9) (and P9 S9))
       (or (not P9) (= O (= C2 (- 1))))
       (or (not P9) (and Q9 J8))
       (or (not M9) (= P (= B2 R2)))
       (or (not M9) (= O9 (ite P (- 1) B2)))
       (or (not M9) (and K9 N9))
       (or (not K9) (and L9 J8))
       a!5
       (or (not E8) (= W (or V2 V)))
       (or (not E8) (and C8 F8))
       (or (not C8) (= X (= G2 (- 1))))
       (or (not C8) (and W6 D8))
       (or (not T6) (= D1 (= K2 X2)))
       (or (not T6) (= V6 (ite D1 1 I2)))
       (or (not T6) (and R6 U6))
       (or (not P6) (= G1 (= K2 (- 1))))
       (or (not P6) (and Q6 J5))
       a!6
       (or (not E5) (= O1 (or N1 B3)))
       (or (not E5) (and B5 F5))
       (or (not B5) (= P1 (= O2 (- 1))))
       (or (not B5) (= D5 (+ 1 P2)))
       (or (not B5) (and C5 U3))
       (= B11 true)
       (= Q1 true)
       (not (= (<= 8 Z1) Q1))
       (= 2 v_290)))
      )
      (main_1 v_290
        A5
        N4
        O4
        P4
        V1
        Q4
        R4
        S4
        W1
        T4
        U4
        V4
        X1
        W4
        X4
        Y4
        Z4
        Y1
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3
        Q3
        R3
        S3
        T3)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Bool) (P2 Bool) (Q2 Int) (R2 Bool) (S2 Bool) (T2 Int) (U2 Bool) (V2 Bool) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Bool) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Int) (V3 Bool) (W3 Bool) (X3 Bool) (Y3 Bool) (Z3 Int) (A4 Bool) (B4 Bool) (C4 Bool) (D4 Bool) (E4 Bool) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Bool) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Int) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Int) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Bool) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Int) (T6 Bool) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Int) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Bool) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Int) (G8 Bool) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Int) (N8 Bool) (O8 Bool) (P8 Bool) (Q8 Bool) (R8 Bool) (S8 Bool) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Bool) (Q9 Bool) (R9 Int) (S9 Bool) (T9 Bool) (U9 Bool) (V9 Bool) (v_256 Int) (v_257 Int) ) 
    (=>
      (and
        (main_1 v_256
        V1
        W1
        X1
        Y1
        Z1
        A2
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3)
        (let ((a!1 (or (not P9) (not (= (<= A5 3) A))))
      (a!2 (or (not N8) (not (= (<= 2 O9) K))))
      (a!3 (or (not I8) (not (= (<= Y1 N2) M))))
      (a!4 (or (not V6) (not (= (<= C2 Q2) V))))
      (a!5 (or (not I5) (not (= (<= G2 T2) E1))))
      (a!6 (or (not V3) (not (= (<= K2 W2) N1)))))
  (and (= 2 v_256)
       (or (and Q6 E7) (and X6 B7) (and V6 C7) (not A7) (and F7 O6) (and D7 T6))
       (or (and I5 P5) (and G5 Q5) (and R5 D5) (not N5) (and S5 B5) (and O5 K5))
       (or (and D8 R8) (and K8 O8) (and I8 P8) (and G8 Q8) (and B8 S8) (not N8))
       (or (and X3 B4) (and V3 C4) (and S3 D4) (and Q3 E4) (not A4))
       (or (and P9 T9) (and N8 U9) (not S9))
       (or (not F7) (not O6) (= A8 X7))
       (or (not F7) (not O6) (= Z7 1))
       (or (not F7) (not O6) (= Y7 B2))
       (or (not F7) (not O6) (= X7 A2))
       (or (not F7) (not O6) (= W7 B2))
       (or (not F7) (not O6) (= B1 Z7))
       (or (not F7) (not O6) (= A1 Y7))
       (or (not F7) (not O6) (= Z W7))
       (or T (not A7) (not (= Z1 1)))
       (or (not A7) (not T) (not (= Z1 0)))
       (or (not X) (not W6) (not T6))
       (or (= A8 T7) (not Q6) (not E7))
       (or (= V7 1) (not Q6) (not E7))
       (or (= U7 B2) (not Q6) (not E7))
       (or (= T7 A2) (not Q6) (not E7))
       (or (= S7 S6) (not Q6) (not E7))
       (or (= B1 V7) (not Q6) (not E7))
       (or (= A1 U7) (not Q6) (not E7))
       (or (= Z S7) (not Q6) (not E7))
       (or (not S5) (not B5) (= J1 L6))
       (or (not S5) (not B5) (= I1 J6))
       (or (not S5) (not B5) (= K6 E2))
       (or (not S5) (not B5) (= K1 M6))
       (or (not S5) (not B5) (= N6 K6))
       (or (not S5) (not B5) (= M6 1))
       (or (not S5) (not B5) (= L6 F2))
       (or (not S5) (not B5) (= J6 F2))
       (or C1 (not N5) (not (= D2 1)))
       (or (not N5) (not C1) (not (= D2 0)))
       (or C1 (not N5) (not U6))
       (or (= J1 D6) (not Q5) (not G5))
       (or (= I1 B6) (not Q5) (not G5))
       (or (= K1 E6) (not Q5) (not G5))
       (or (= N6 C6) (not Q5) (not G5))
       (or (= E6 0) (not Q5) (not G5))
       (or (= D6 F2) (not Q5) (not G5))
       (or (= C6 E2) (not Q5) (not G5))
       (or (not Q5) (not G5) (= B6 (- 1)))
       (or G1 (not Q5) (not G5))
       (or L1 (not A4) (not (= H2 1)))
       (or (not L1) (not A4) (not (= H2 0)))
       (or L1 (not A4) (not H5))
       (or (not L1) (not A4) (not C5))
       (or D (not T9) (not P9))
       (or K (not N8) (not Q9))
       (or (not K) (not N8) (not U9))
       (or (= S W8) (not O8) (not K8))
       (or (= R V8) (not O8) (not K8))
       (or (= Q T8) (not O8) (not K8))
       (or (= V8 X1) (not O8) (not K8))
       (or (= U8 M8) (not O8) (not K8))
       (or (= N9 U8) (not O8) (not K8))
       (or (= W8 0) (not O8) (not K8))
       (or (not O8) (not K8) (= T8 (- 1)))
       (or (= S A9) (not P8) (not I8))
       (or (= R Z8) (not P8) (not I8))
       (or (= Q X8) (not P8) (not I8))
       (or (= A9 0) (not P8) (not I8))
       (or (= Y8 W1) (not P8) (not I8))
       (or (not P8) (not I8) (= X8 (- 1)))
       (or (= N9 Y8) (not P8) (not I8))
       (or (= Z8 Y1) (not P8) (not I8))
       (or N (not P8) (not I8))
       (or (not N) (not I8) (not L8))
       (or (not H8) (not A7) T)
       (or (= S E9) (not G8) (not Q8))
       (or (= R D9) (not G8) (not Q8))
       (or (= Q B9) (not G8) (not Q8))
       (or (= D9 X1) (not G8) (not Q8))
       (or (not G8) (not Q8) (= B9 (- 1)))
       (or (= N9 C9) (not G8) (not Q8))
       (or (= E9 0) (not G8) (not Q8))
       (or (= C9 W1) (not G8) (not Q8))
       (or O (not G8) (not Q8))
       (or (not O) (not G8) (not J8))
       (or (= S I9) (not D8) (not R8))
       (or (= R H9) (not D8) (not R8))
       (or (= Q F9) (not D8) (not R8))
       (or (= N9 G9) (not D8) (not R8))
       (or (= I9 1) (not D8) (not R8))
       (or (= H9 X1) (not D8) (not R8))
       (or (= G9 W1) (not D8) (not R8))
       (or (= F9 F8) (not D8) (not R8))
       (or (not C8) (not A7) (not T))
       (or (= S M9) (not B8) (not S8))
       (or (= R L9) (not B8) (not S8))
       (or (= Q J9) (not B8) (not S8))
       (or (= N9 K9) (not B8) (not S8))
       (or (= M9 1) (not B8) (not S8))
       (or (= L9 X1) (not B8) (not S8))
       (or (= K9 W1) (not B8) (not S8))
       (or (= J9 X1) (not B8) (not S8))
       (or P2 (not B8) (not S8))
       (or (not P2) (not E8) (not B8))
       (or (not D7) (not T6) (= A8 P7))
       (or (not D7) (not T6) (= R7 0))
       (or (not D7) (not T6) (= Q7 B2))
       (or (not D7) (not T6) (= P7 A2))
       (or (not D7) (not T6) (= O7 (- 1)))
       (or (not D7) (not T6) (= B1 R7))
       (or (not D7) (not T6) (= A1 Q7))
       (or (not D7) (not T6) (= Z O7))
       (or (not D7) (not T6) X)
       (or (= H7 Z6) (not X6) (not B7))
       (or (= A8 H7) (not X6) (not B7))
       (or (= J7 0) (not X6) (not B7))
       (or (= B1 J7) (not X6) (not B7))
       (or (= A1 I7) (not X6) (not B7))
       (or (= Z G7) (not X6) (not B7))
       (or (= I7 B2) (not X6) (not B7))
       (or (not X6) (not B7) (= G7 (- 1)))
       (or (= A8 L7) (not C7) (not V6))
       (or (= N7 0) (not C7) (not V6))
       (or (= M7 C2) (not C7) (not V6))
       (or (= L7 A2) (not C7) (not V6))
       (or (not C7) (not V6) (= K7 (- 1)))
       (or (= B1 N7) (not C7) (not V6))
       (or (= A1 M7) (not C7) (not V6))
       (or (= Z K7) (not C7) (not V6))
       (or W (not C7) (not V6))
       (or (not W) (not V6) (not Y6))
       (or (not P6) (not N5) (not C1))
       (or (not R5) (not D5) (= J1 H6))
       (or (not R5) (not D5) (= I1 F6))
       (or (not R5) (not D5) (= K1 I6))
       (or (not R5) (not D5) (= N6 G6))
       (or (not R5) (not D5) (= I6 1))
       (or (not R5) (not D5) (= H6 F2))
       (or (not R5) (not D5) (= G6 E2))
       (or (not R5) (not D5) (= F6 F5))
       (or (not O5) (not K5) (= J1 V5))
       (or (not O5) (not K5) (= I1 T5))
       (or (not O5) (not K5) (= K1 W5))
       (or (not O5) (not K5) (= N6 U5))
       (or (not O5) (not K5) (= W5 0))
       (or (not O5) (not K5) (= V5 F2))
       (or (not O5) (not K5) (= U5 M5))
       (or (not O5) (not K5) (= T5 (- 1)))
       (or (not J5) (not G5) (not G1))
       (or (= J1 Z5) (not P5) (not I5))
       (or (= I1 X5) (not P5) (not I5))
       (or (= K1 A6) (not P5) (not I5))
       (or (= N6 Y5) (not P5) (not I5))
       (or (= A6 0) (not P5) (not I5))
       (or (= Z5 G2) (not P5) (not I5))
       (or (= Y5 E2) (not P5) (not I5))
       (or (not P5) (not I5) (= X5 (- 1)))
       (or F1 (not P5) (not I5))
       (or (not F1) (not I5) (not L5))
       (or (= G4 Z3) (not X3) (not B4))
       (or (= J4 0) (not X3) (not B4))
       (or (= I4 U3) (not X3) (not B4))
       (or (= H4 J2) (not X3) (not B4))
       (or (= U1 J4) (not X3) (not B4))
       (or (= T1 H4) (not X3) (not B4))
       (or (= S1 F4) (not X3) (not B4))
       (or (= A5 I4) (not X3) (not B4))
       (or (= Z4 G4) (not X3) (not B4))
       (or (not X3) (not B4) (= F4 (- 1)))
       (or (= O4 0) (not C4) (not V3))
       (or (= N4 U3) (not C4) (not V3))
       (or (= M4 K2) (not C4) (not V3))
       (or (= L4 I2) (not C4) (not V3))
       (or (not C4) (not V3) (= K4 (- 1)))
       (or (= U1 O4) (not C4) (not V3))
       (or (= T1 M4) (not C4) (not V3))
       (or (= S1 K4) (not C4) (not V3))
       (or (= A5 N4) (not C4) (not V3))
       (or (= Z4 L4) (not C4) (not V3))
       (or O1 (not C4) (not V3))
       (or (not Y3) (not O1) (not V3))
       (or (= U1 T4) (not D4) (not S3))
       (or (= T1 R4) (not D4) (not S3))
       (or (= S1 P4) (not D4) (not S3))
       (or (= A5 S4) (not D4) (not S3))
       (or (= Z4 Q4) (not D4) (not S3))
       (or (= T4 0) (not D4) (not S3))
       (or (= S4 U3) (not D4) (not S3))
       (or (= R4 J2) (not D4) (not S3))
       (or (= Q4 I2) (not D4) (not S3))
       (or (not D4) (not S3) (= P4 (- 1)))
       (or P1 (not D4) (not S3))
       (or (not P1) (not S3) (not W3))
       (or (= U1 Y4) (not E4) (not Q3))
       (or (= T1 W4) (not E4) (not Q3))
       (or (= S1 U4) (not E4) (not Q3))
       (or (= A5 X4) (not E4) (not Q3))
       (or (= Z4 V4) (not E4) (not Q3))
       (or (= Y4 1) (not E4) (not Q3))
       (or (= X4 L2) (not E4) (not Q3))
       (or (= W4 J2) (not E4) (not Q3))
       (or (= V4 I2) (not E4) (not Q3))
       (or (= U4 J2) (not E4) (not Q3))
       (or (not R1) (not E4) (not Q3))
       (or R1 (not Q3) (not T3))
       (or V2 (not S5) (not B5))
       (or (not V2) (not E5) (not B5))
       (or S2 (not F7) (not O6))
       (or (not R6) (not S2) (not O6))
       a!1
       (or (not P9) (= D (and A C)))
       (or (not P9) (= B (= O9 1)))
       (or (not P9) (not (= B C)))
       (or (not P9) (= R9 (+ 1 V1)))
       (or (not P9) (and N8 Q9))
       (or (not O6) (and P6 N5))
       (or (not B5) (and A4 C5))
       (or (not T6) (= X (= C2 (- 1))))
       (or (not T6) (and N5 U6))
       (or (not Q6) (= Y (= B2 Q2)))
       (or (not Q6) (= S6 (ite Y (- 1) B2)))
       (or (not Q6) (and R6 O6))
       (or (not K5) (= D1 (= G2 T2)))
       (or (not K5) (= M5 (ite D1 1 E2)))
       (or (not K5) (and I5 L5))
       (or (not G5) (= G1 (= G2 (- 1))))
       (or (not G5) (and A4 H5))
       (or (not D5) (= H1 (= F2 T2)))
       (or (not D5) (= F5 (ite H1 (- 1) F2)))
       (or (not D5) (and E5 B5))
       (or R1 (not (= M2 1)))
       (or (not R1) (not (= M2 0)))
       a!2
       (or (not N8) (= J N9))
       (or (not N8) (= F N6))
       (or (not N8) (= E Z4))
       (or (not N8) (= I (+ G H)))
       (or (not N8) (= H A8))
       (or (not N8) (= G (+ F E)))
       (or (not N8) (= O9 (+ I J)))
       (or (not K8) (= L (= Y1 N2)))
       (or (not K8) (= M8 (ite L 1 W1)))
       (or (not K8) (and I8 L8))
       a!3
       (or (not I8) (= N (or O2 M)))
       (or (not I8) (and G8 J8))
       (or (not G8) (= O (= Y1 (- 1))))
       (or (not G8) (and H8 A7))
       (or (not D8) (= P (= X1 N2)))
       (or (not D8) (= F8 (ite P (- 1) X1)))
       (or (not D8) (and B8 E8))
       (or (not B8) (and C8 A7))
       (or (not X6) (= U (= C2 Q2)))
       (or (not X6) (= Z6 (ite U 1 A2)))
       (or (not X6) (and V6 Y6))
       a!4
       (or (not V6) (= W (or R2 V)))
       (or (not V6) (and T6 W6))
       a!5
       (or (not I5) (= F1 (or U2 E1)))
       (or (not I5) (and J5 G5))
       (or (not X3) (= M1 (= K2 W2)))
       (or (not X3) (= Z3 (ite M1 1 I2)))
       (or (not X3) (and V3 Y3))
       a!6
       (or (not V3) (= O1 (or X2 N1)))
       (or (not V3) (and S3 W3))
       (or (not S3) (= P1 (= K2 (- 1))))
       (or (not S3) (= U3 (+ 1 L2)))
       (or (not S3) (and Q3 T3))
       (or (not R3) (and S9 V9))
       (= Q1 true)
       (= R3 true)
       (not (= (<= 8 V1) Q1))
       (= 3 v_257)))
      )
      (main_1 v_257
        V1
        W1
        X1
        Y1
        Z1
        A2
        B2
        C2
        D2
        E2
        F2
        G2
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        Z2
        A3
        B3
        C3
        D3
        E3
        F3
        G3
        H3
        I3
        J3
        K3
        L3
        M3
        N3
        O3
        P3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Int) (W Bool) (X Bool) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Bool) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (v_47 Int) ) 
    (=>
      (and
        (main_1 v_47
        A
        B
        C
        D
        E
        F
        G
        H
        I
        J
        K
        L
        M
        N
        O
        P
        Q
        R
        S
        T
        U
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
        G1
        H1
        I1
        J1
        K1
        L1
        M1
        N1
        O1
        P1
        Q1
        R1
        S1
        T1
        U1)
        (= 3 v_47)
      )
      false
    )
  )
)

(check-sat)
(exit)
