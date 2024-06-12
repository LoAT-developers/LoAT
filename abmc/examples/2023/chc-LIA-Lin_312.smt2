; ./prepared/seahorn/./sv_comp_flat_small/seq-mthreaded/pals_lcr-var-start-time.4_false-unreach-call.1.ufo.BOUNDED-8.pals.c.flat_000.smt2
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
       (or (not D4) (not Z5) (not H5))
       (or (= A2 T5) (not W3) (not N5))
       (or (not W3) (not T5) (not N5))
       (or (not Z1) (not W3) (not N5))
       (or Z1 (not W3) (not X4))
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
       (or D4 (not Z5) (not H5))
       (or (= A2 T5) (not W3) (not N5))
       (or (not W3) (not T5) (not N5))
       (or (not Z1) (not W3) (not N5))
       (or Z1 (not W3) (not X4))
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
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Bool) (U2 Bool) (V2 Int) (W2 Bool) (X2 Bool) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Int) (C3 Bool) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Bool) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Bool) (D5 Bool) (E5 Int) (F5 Bool) (G5 Bool) (H5 Int) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Int) (N5 Int) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Bool) (T6 Int) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Int) (B7 Bool) (C7 Bool) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Bool) (G8 Int) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Int) (O8 Bool) (P8 Bool) (Q8 Bool) (R8 Bool) (S8 Bool) (T8 Bool) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Bool) (Q9 Bool) (R9 Bool) (S9 Bool) (T9 Int) (U9 Bool) (V9 Bool) (W9 Bool) (X9 Bool) (Y9 Bool) (Z9 Bool) (A10 Int) (B10 Bool) (C10 Bool) (D10 Bool) (E10 Bool) (F10 Bool) (G10 Bool) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Int) (Q10 Int) (R10 Int) (S10 Int) (T10 Int) (U10 Int) (V10 Int) (W10 Int) (X10 Int) (Y10 Int) (Z10 Int) (A11 Int) (B11 Int) (C11 Int) (D11 Bool) (E11 Bool) (F11 Int) (G11 Bool) (H11 Bool) (v_294 Int) (v_295 Int) ) 
    (=>
      (and
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
        (let ((a!1 (or (not D11) (not (= (<= O6 3) A))))
      (a!2 (or (not W6) (not (= (<= O3 Y2) E1))))
      (a!3 (or (not B10) (not (= (<= 2 C11) K))))
      (a!4 (or (not W9) (not (= (<= G3 S2) M))))
      (a!5 (or (not J8) (not (= (<= K3 V2) V))))
      (a!6 (or (not I5) (not (= (<= S3 B3) N1)))))
  (and (= 1 v_294)
       (or (and C8 Q8) (and L8 R8) (and J8 S8) (and H8 T8) (not O8) (and P8 E8))
       (or (and R9 C10)
           (and P9 D10)
           (and Y9 E10)
           (and W9 F10)
           (not B10)
           (and G10 U9))
       (or (and R6 C7) (and Y6 E7) (and W6 F7) (and U6 G7) (not B7) (and D7 P6))
       (or (and C5 P5) (and K5 Q5) (and I5 R5) (and F5 S5) (not O5))
       (or (= B5 N4) (not D11) (not H11))
       (or (= A5 L4) (not D11) (not H11))
       (or (= Z4 K4) (not D11) (not H11))
       (or (= Y4 J4) (not D11) (not H11))
       (or (= X4 I4) (not D11) (not H11))
       (or (= W4 G4) (not D11) (not H11))
       (or (= V4 F4) (not D11) (not H11))
       (or (= U4 E4) (not D11) (not H11))
       (or (= T4 C4) (not D11) (not H11))
       (or (= S4 B4) (not D11) (not H11))
       (or (= R4 A4) (not D11) (not H11))
       (or (= Q4 Y3) (not D11) (not H11))
       (or (= P4 X3) (not D11) (not H11))
       (or (= O4 W3) (not D11) (not H11))
       (or (= N4 F11) (not D11) (not H11))
       (or (= M4 T1) (not D11) (not H11))
       (or (= L4 O6) (not D11) (not H11))
       (or (= K4 Q) (not D11) (not H11))
       (or (= J4 S1) (not D11) (not H11))
       (or (= I4 N6) (not D11) (not H11))
       (or (= H4 K1) (not D11) (not H11))
       (or (= G4 R1) (not D11) (not H11))
       (or (= F4 J1) (not D11) (not H11))
       (or (= E4 B8) (not D11) (not H11))
       (or (= Z3 S) (not D11) (not H11))
       (or (= Y3 Z) (not D11) (not H11))
       (or (= X3 R) (not D11) (not H11))
       (or (= W3 B11) (not D11) (not H11))
       (or (= Z1 M4) (not D11) (not H11))
       (or (= Y1 H4) (not D11) (not H11))
       (or (= X1 D4) (not D11) (not H11))
       (or (= W1 Z3) (not D11) (not H11))
       (or (= D4 B1) (not D11) (not H11))
       (or (= C4 I1) (not D11) (not H11))
       (or (= B4 A1) (not D11) (not H11))
       (or (= A4 O9) (not D11) (not H11))
       (or (= F9 0) (not L8) (not R8))
       (or (= E9 J3) (not L8) (not R8))
       (or (= D9 N8) (not L8) (not R8))
       (or (= C9 (- 1)) (not L8) (not R8))
       (or (= B1 F9) (not L8) (not R8))
       (or (= A1 E9) (not L8) (not R8))
       (or (= Z C9) (not L8) (not R8))
       (or (= O9 D9) (not L8) (not R8))
       (or (= B9 1) (not C8) (not Q8))
       (or (= A9 J3) (not C8) (not Q8))
       (or (= Z8 I3) (not C8) (not Q8))
       (or (= Y8 J3) (not C8) (not Q8))
       (or (= B1 B9) (not C8) (not Q8))
       (or (= A1 A9) (not C8) (not Q8))
       (or (= Z Y8) (not C8) (not Q8))
       (or (= O9 Z8) (not C8) (not Q8))
       (or (= B8 U7) (not W6) (not F7))
       (or (= W7 0) (not W6) (not F7))
       (or (= K1 W7) (not W6) (not F7))
       (or (= J1 V7) (not W6) (not F7))
       (or (= I1 T7) (not W6) (not F7))
       (or (= V7 O3) (not W6) (not F7))
       (or (= U7 M3) (not W6) (not F7))
       (or (= T7 (- 1)) (not W6) (not F7))
       (or (= B8 I7) (not R6) (not C7))
       (or (= K1 K7) (not R6) (not C7))
       (or (= J1 J7) (not R6) (not C7))
       (or (= I1 H7) (not R6) (not C7))
       (or (= K7 1) (not R6) (not C7))
       (or (= J7 N3) (not R6) (not C7))
       (or (= I7 M3) (not R6) (not C7))
       (or (= H7 T6) (not R6) (not C7))
       (or (not A3) (not P6) (not S6))
       (or X2 (not C8) (not Q8))
       (or (not X2) (not C8) (not F8))
       (or L1 (not (= P3 1)) (not O5))
       (or (not L1) (not (= P3 0)) (not O5))
       (or (not L1) (not O5) (not Q6))
       (or F1 (not W6) (not F7))
       (or (not F1) (not W6) (not Z6))
       (or T (not (= H3 1)) (not O8))
       (or (not T) (not (= H3 0)) (not O8))
       (or (not D) (not D11) (not H11))
       (or K (not B10) (not E11))
       (or (= S S10) (not Y9) (not E10))
       (or (= R R10) (not Y9) (not E10))
       (or (= Q P10) (not Y9) (not E10))
       (or (not Y9) (= P10 (- 1)) (not E10))
       (or (= B11 Q10) (not Y9) (not E10))
       (or (= S10 0) (not Y9) (not E10))
       (or (= R10 F3) (not Y9) (not E10))
       (or (= Q10 A10) (not Y9) (not E10))
       (or (= S W10) (not W9) (not F10))
       (or (= R V10) (not W9) (not F10))
       (or (= Q T10) (not W9) (not F10))
       (or (= B11 U10) (not W9) (not F10))
       (or (= W10 0) (not W9) (not F10))
       (or (= V10 G3) (not W9) (not F10))
       (or (= U10 E3) (not W9) (not F10))
       (or (= T10 (- 1)) (not W9) (not F10))
       (or N (not W9) (not F10))
       (or (not N) (not Z9) (not W9))
       (or T (not O8) (not V9))
       (or (not O) (not U9) (not X9))
       (or (= S K10) (not R9) (not C10))
       (or (= R J10) (not R9) (not C10))
       (or (= Q H10) (not R9) (not C10))
       (or (= K10 1) (not R9) (not C10))
       (or (= J10 F3) (not R9) (not C10))
       (or (= H10 T9) (not R9) (not C10))
       (or (= B11 I10) (not R9) (not C10))
       (or (= I10 E3) (not R9) (not C10))
       (or (not T) (not Q9) (not O8))
       (or (= S O10) (not P9) (not D10))
       (or (= R N10) (not P9) (not D10))
       (or (= Q L10) (not P9) (not D10))
       (or (= N10 F3) (not P9) (not D10))
       (or (= M10 E3) (not P9) (not D10))
       (or (= B11 M10) (not P9) (not D10))
       (or (= O10 1) (not P9) (not D10))
       (or (= L10 F3) (not P9) (not D10))
       (or U2 (not P9) (not D10))
       (or (not U2) (not P9) (not S9))
       (or (not P8) (not E8) (= X8 1))
       (or (not P8) (not E8) (= W8 J3))
       (or (not P8) (not E8) (= V8 I3))
       (or (not P8) (not E8) (= B1 X8))
       (or (not P8) (not E8) (= A1 W8))
       (or (not P8) (not E8) (= Z U8))
       (or (not P8) (not E8) (= U8 G8))
       (or (not P8) (not E8) (= O9 V8))
       (or (= J9 0) (not J8) (not S8))
       (or (= I9 K3) (not J8) (not S8))
       (or (= H9 I3) (not J8) (not S8))
       (or (= G9 (- 1)) (not J8) (not S8))
       (or (= B1 J9) (not J8) (not S8))
       (or (= A1 I9) (not J8) (not S8))
       (or (= Z G9) (not J8) (not S8))
       (or (= O9 H9) (not J8) (not S8))
       (or W (not J8) (not S8))
       (or (not W) (not J8) (not M8))
       (or (not X) (not H8) (not K8))
       (or (= M9 J3) (not H8) (not T8))
       (or (= L9 I3) (not H8) (not T8))
       (or (= K9 (- 1)) (not H8) (not T8))
       (or (= B1 N9) (not H8) (not T8))
       (or (= A1 M9) (not H8) (not T8))
       (or (= Z K9) (not H8) (not T8))
       (or (= O9 L9) (not H8) (not T8))
       (or (= N9 0) (not H8) (not T8))
       (or X (not H8) (not T8))
       (or (not D7) (not P6) (= B8 M7))
       (or (not D7) (not P6) (= K1 O7))
       (or (not D7) (not P6) (= J1 N7))
       (or (not D7) (not P6) (= I1 L7))
       (or (not D7) (not P6) (= O7 1))
       (or (not D7) (not P6) (= N7 N3))
       (or (not D7) (not P6) (= M7 M3))
       (or (not D7) (not P6) (= L7 N3))
       (or A3 (not P6) (not D7))
       (or C1 (not (= L3 1)) (not B7))
       (or (not B7) (not C1) (not (= L3 0)))
       (or C1 (not B7) (not I8))
       (or (not D8) (not C1) (not B7))
       (or (= B8 Q7) (not Y6) (not E7))
       (or (= K1 S7) (not Y6) (not E7))
       (or (= J1 R7) (not Y6) (not E7))
       (or (= I1 P7) (not Y6) (not E7))
       (or (= S7 0) (not Y6) (not E7))
       (or (= R7 N3) (not Y6) (not E7))
       (or (= Q7 A7) (not Y6) (not E7))
       (or (= P7 (- 1)) (not Y6) (not E7))
       (or L1 (not O5) (not V6))
       (or (= B8 Y7) (not U6) (not G7))
       (or (= K1 A8) (not U6) (not G7))
       (or (= J1 Z7) (not U6) (not G7))
       (or (= I1 X7) (not U6) (not G7))
       (or (= A8 0) (not U6) (not G7))
       (or (= Z7 N3) (not U6) (not G7))
       (or (= Y7 M3) (not U6) (not G7))
       (or (= X7 (- 1)) (not U6) (not G7))
       (or G1 (not U6) (not G7))
       (or (not G1) (not U6) (not X6))
       (or (not K5) (= A6 N5) (not Q5))
       (or (not K5) (= Z5 M5) (not Q5))
       (or (not K5) (= Y5 (- 1)) (not Q5))
       (or (not K5) (= T1 C6) (not Q5))
       (or (not K5) (= S1 A6) (not Q5))
       (or (not K5) (= R1 Y5) (not Q5))
       (or (not K5) (= O6 B6) (not Q5))
       (or (not K5) (= N6 Z5) (not Q5))
       (or (not K5) (= C6 0) (not Q5))
       (or (not K5) (= B6 H5) (not Q5))
       (or (= T1 H6) (not I5) (not R5))
       (or (= S1 F6) (not I5) (not R5))
       (or (= R1 D6) (not I5) (not R5))
       (or (= O6 G6) (not I5) (not R5))
       (or (= N6 E6) (not I5) (not R5))
       (or (= H6 0) (not I5) (not R5))
       (or (= G6 H5) (not I5) (not R5))
       (or (= F6 S3) (not I5) (not R5))
       (or (= E6 Q3) (not I5) (not R5))
       (or (= D6 (- 1)) (not I5) (not R5))
       (or O1 (not I5) (not R5))
       (or (not O1) (not I5) (not L5))
       (or V1 (not G5) (not V3))
       (or (= T1 M6) (not F5) (not S5))
       (or (= S1 K6) (not F5) (not S5))
       (or (= R1 I6) (not F5) (not S5))
       (or (= O6 L6) (not F5) (not S5))
       (or (= N6 J6) (not F5) (not S5))
       (or (= M6 0) (not F5) (not S5))
       (or (= L6 H5) (not F5) (not S5))
       (or (= K6 R3) (not F5) (not S5))
       (or (= J6 Q3) (not F5) (not S5))
       (or (= I6 (- 1)) (not F5) (not S5))
       (or P1 (not F5) (not S5))
       (or (not P1) (not F5) (not J5))
       (or (not D5) (not V1) (not V3))
       (or (= X5 1) (not C5) (not P5))
       (or (= W5 T3) (not C5) (not P5))
       (or (= V5 R3) (not C5) (not P5))
       (or (= U5 Q3) (not C5) (not P5))
       (or (= T5 E5) (not C5) (not P5))
       (or (= T1 X5) (not C5) (not P5))
       (or (= S1 V5) (not C5) (not P5))
       (or (= R1 T5) (not C5) (not P5))
       (or (= O6 W5) (not C5) (not P5))
       (or (= N6 U5) (not C5) (not P5))
       (or (not G10) (not U9) (= S A11))
       (or (not G10) (not U9) (= R Z10))
       (or (not G10) (not U9) (= Q X10))
       (or (not G10) (not U9) (= B11 Y10))
       (or (not G10) (not U9) (= A11 0))
       (or (not G10) (not U9) (= Z10 F3))
       (or (not G10) (not U9) (= Y10 E3))
       (or (not G10) (not U9) (= X10 (- 1)))
       (or (not G10) (not U9) O)
       (or (not G11) (and D11 H11))
       a!1
       (or (not D11) (= D (and A C)))
       (or (not D11) (= B (= C11 1)))
       (or (not D11) (not (= B C)))
       (or (not D11) (= F11 (+ 1 D3)))
       (or (not D11) (and B10 E11))
       (or (not L8) (= U (= K3 V2)))
       (or (not L8) (= N8 (ite U 1 I3)))
       (or (not L8) (and J8 M8))
       (or (not E8) (= Y (= J3 V2)))
       (or (not E8) (= G8 (ite Y (- 1) J3)))
       (or (not E8) (and C8 F8))
       (or (not C8) (and B7 D8))
       a!2
       (or (not W6) (= F1 (or E1 Z2)))
       (or (not W6) (and U6 X6))
       (or (not R6) (= H1 (= N3 Y2)))
       (or (not R6) (= T6 (ite H1 (- 1) N3)))
       (or (not R6) (and P6 S6))
       (or (not P6) (and O5 Q6))
       (or V1 (not (= U3 1)))
       (or (not V1) (not (= U3 0)))
       a!3
       (or (not B10) (= J B11))
       (or (not B10) (= I (+ G H)))
       (or (not B10) (= H O9))
       (or (not B10) (= G (+ F E)))
       (or (not B10) (= F B8))
       (or (not B10) (= E N6))
       (or (not B10) (= C11 (+ I J)))
       (or (not Y9) (= L (= G3 S2)))
       (or (not Y9) (= A10 (ite L 1 E3)))
       (or (not Y9) (and W9 Z9))
       a!4
       (or (not W9) (= N (or M T2)))
       (or (not W9) (and U9 X9))
       (or (not U9) (= O (= G3 (- 1))))
       (or (not U9) (and V9 O8))
       (or (not R9) (= P (= F3 S2)))
       (or (not R9) (= T9 (ite P (- 1) F3)))
       (or (not R9) (and P9 S9))
       (or (not P9) (and Q9 O8))
       a!5
       (or (not J8) (= W (or V W2)))
       (or (not J8) (and H8 K8))
       (or (not H8) (= X (= K3 (- 1))))
       (or (not H8) (and B7 I8))
       (or (not Y6) (= D1 (= O3 Y2)))
       (or (not Y6) (= A7 (ite D1 1 M3)))
       (or (not Y6) (and W6 Z6))
       (or (not U6) (= G1 (= O3 (- 1))))
       (or (not U6) (and V6 O5))
       (or (not K5) (= M1 (= S3 B3)))
       (or (not K5) (= N5 (ite M1 R3 S3)))
       (or (not K5) (= M5 (ite M1 1 Q3)))
       (or (not K5) (and I5 L5))
       a!6
       (or (not I5) (= O1 (or N1 C3)))
       (or (not I5) (and F5 J5))
       (or (not F5) (= P1 (= S3 (- 1))))
       (or (not F5) (= H5 (+ 1 T3)))
       (or (not F5) (and G5 V3))
       (or (not C5) (= Q1 (= R3 B3)))
       (or (not C5) (= E5 (ite Q1 (- 1) R3)))
       (or (not C5) (and D5 V3))
       (= G11 true)
       (= U1 true)
       (not (= (<= 8 D3) U1))
       (= 1 v_295)))
      )
      (main_1 v_295
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
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Int) (S2 Bool) (T2 Bool) (U2 Int) (V2 Bool) (W2 Bool) (X2 Int) (Y2 Bool) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Int) (V3 Bool) (W3 Bool) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Bool) (C4 Int) (D4 Int) (E4 Bool) (F4 Bool) (G4 Bool) (H4 Bool) (I4 Bool) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Int) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Int) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Int) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Bool) (V5 Bool) (W5 Bool) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Bool) (W6 Int) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Int) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Bool) (I7 Bool) (J7 Bool) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Bool) (J8 Int) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Bool) (O8 Bool) (P8 Bool) (Q8 Int) (R8 Bool) (S8 Bool) (T8 Bool) (U8 Bool) (V8 Bool) (W8 Bool) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Bool) (U9 Bool) (V9 Int) (W9 Bool) (X9 Bool) (Y9 Bool) (Z9 Bool) (A10 Bool) (v_261 Int) (v_262 Int) ) 
    (=>
      (and
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
        (let ((a!1 (or (not T9) (not (= (<= E5 3) A))))
      (a!2 (or (not Z6) (not (= (<= G3 R2) V))))
      (a!3 (or (not M5) (not (= (<= K3 U2) E1))))
      (a!4 (or (not R8) (not (= (<= 2 S9) K))))
      (a!5 (or (not M8) (not (= (<= C3 O2) M))))
      (a!6 (or (not Y3) (not (= (<= O3 X2) N1)))))
  (and (= 1 v_261)
       (or (and U6 F7) (and B7 H7) (and X6 J7) (not E7) (and I7 Z6) (and G7 S6))
       (or (and H8 S8) (and F8 T8) (and O8 U8) (and M8 V8) (and K8 W8) (not R8))
       (or (and O5 U5) (not R5) (and W5 K5) (and V5 M5) (and T5 F5) (and S5 H5))
       (or (and V3 I4) (and S3 F4) (and A4 G4) (and Y3 H4) (not E4))
       (or D (not X9) (not T9))
       (or (and R8 Y9) (not W9) (and X9 T9))
       (or T (not E7) (not (= D3 1)))
       (or (not E7) (not T) (not (= D3 0)))
       (or (= E8 T7) (not H7) (not B7))
       (or (= V7 0) (not H7) (not B7))
       (or (= U7 F3) (not H7) (not B7))
       (or (= T7 D7) (not H7) (not B7))
       (or (not H7) (not B7) (= S7 (- 1)))
       (or (= B1 V7) (not H7) (not B7))
       (or (= A1 U7) (not H7) (not B7))
       (or (= Z S7) (not H7) (not B7))
       (or (= E8 B8) (not X6) (not J7))
       (or (= D8 0) (not X6) (not J7))
       (or (= C8 F3) (not X6) (not J7))
       (or (= B8 E3) (not X6) (not J7))
       (or (not X6) (not J7) (= A8 (- 1)))
       (or (= B1 D8) (not X6) (not J7))
       (or (= A1 C8) (not X6) (not J7))
       (or (= Z A8) (not X6) (not J7))
       (or X (not X6) (not J7))
       (or (not T2) (not V6) (not S6))
       (or (not V5) (not M5) (= K1 M6))
       (or (not V5) (not M5) (= J1 L6))
       (or (not V5) (not M5) (= I1 J6))
       (or (not V5) (not M5) (= R6 K6))
       (or (not V5) (not M5) (= M6 0))
       (or (not V5) (not M5) (= L6 K3))
       (or (not V5) (not M5) (= K6 I3))
       (or (not V5) (not M5) (= J6 (- 1)))
       (or F1 (not V5) (not M5))
       (or (not S5) (not H5) (= K1 A6))
       (or (not S5) (not H5) (= J1 Z5))
       (or (not S5) (not H5) (= I1 X5))
       (or (not S5) (not H5) (= R6 Y5))
       (or (not S5) (not H5) (= A6 1))
       (or (not S5) (not H5) (= Z5 J3))
       (or (not S5) (not H5) (= Y5 I3))
       (or (not S5) (not H5) (= X5 J5))
       (or (not F1) (not P5) (not M5))
       (or (not W2) (not I5) (not F5))
       (or L1 (not E4) (not (= L3 1)))
       (or (not E4) (not L1) (not (= L3 0)))
       (or (not L1) (not E4) (not G5))
       (or L1 (not L5) (not E4))
       (or (not K) (not R8) (not Y9))
       (or K (not R8) (not U9))
       (or (= S I9) (not U8) (not O8))
       (or (= R H9) (not U8) (not O8))
       (or (= Q F9) (not U8) (not O8))
       (or (= I9 0) (not U8) (not O8))
       (or (= G9 Q8) (not U8) (not O8))
       (or (not U8) (= F9 (- 1)) (not O8))
       (or (= R9 G9) (not U8) (not O8))
       (or (= H9 B3) (not U8) (not O8))
       (or (= S M9) (not M8) (not V8))
       (or (= R L9) (not M8) (not V8))
       (or (= Q J9) (not M8) (not V8))
       (or (= R9 K9) (not M8) (not V8))
       (or (= M9 0) (not M8) (not V8))
       (or (= L9 C3) (not M8) (not V8))
       (or (= K9 A3) (not M8) (not V8))
       (or (not M8) (= J9 (- 1)) (not V8))
       (or N (not M8) (not V8))
       (or (not N) (not M8) (not P8))
       (or (not L8) (not E7) T)
       (or (= S Q9) (not K8) (not W8))
       (or (= R P9) (not K8) (not W8))
       (or (= Q N9) (not K8) (not W8))
       (or (= R9 O9) (not K8) (not W8))
       (or (= Q9 0) (not K8) (not W8))
       (or (= P9 B3) (not K8) (not W8))
       (or (= O9 A3) (not K8) (not W8))
       (or (not K8) (not W8) (= N9 (- 1)))
       (or O (not K8) (not W8))
       (or (not O) (not K8) (not N8))
       (or (= S A9) (not S8) (not H8))
       (or (= R Z8) (not S8) (not H8))
       (or (= Q X8) (not S8) (not H8))
       (or (= A9 1) (not S8) (not H8))
       (or (= Z8 B3) (not S8) (not H8))
       (or (= R9 Y8) (not S8) (not H8))
       (or (= Y8 A3) (not S8) (not H8))
       (or (= X8 J8) (not S8) (not H8))
       (or (not G8) (not E7) (not T))
       (or (= S E9) (not T8) (not F8))
       (or (= R D9) (not T8) (not F8))
       (or (= Q B9) (not T8) (not F8))
       (or (= D9 B3) (not T8) (not F8))
       (or (= C9 A3) (not T8) (not F8))
       (or (= R9 C9) (not T8) (not F8))
       (or (= E9 1) (not T8) (not F8))
       (or (= B9 B3) (not T8) (not F8))
       (or Q2 (not T8) (not F8))
       (or (not Q2) (not I8) (not F8))
       (or (not I7) (not Z6) (= E8 X7))
       (or (not I7) (not Z6) (= Z7 0))
       (or (not I7) (not Z6) (= Y7 G3))
       (or (not I7) (not Z6) (= X7 E3))
       (or (not I7) (not Z6) (= W7 (- 1)))
       (or (not I7) (not Z6) (= B1 Z7))
       (or (not I7) (not Z6) (= A1 Y7))
       (or (not I7) (not Z6) (= Z W7))
       (or W (not I7) (not Z6))
       (or (not G7) (not S6) (= E8 P7))
       (or (not G7) (not S6) (= R7 1))
       (or (not G7) (not S6) (= Q7 F3))
       (or (not G7) (not S6) (= P7 E3))
       (or (not G7) (not S6) (= O7 F3))
       (or (not G7) (not S6) (= B1 R7))
       (or (not G7) (not S6) (= A1 Q7))
       (or (not G7) (not S6) (= Z O7))
       (or T2 (not S6) (not G7))
       (or (not W) (not C7) (not Z6))
       (or (not A7) (not X6) (not X))
       (or (= M7 F3) (not F7) (not U6))
       (or (= E8 L7) (not F7) (not U6))
       (or (= B1 N7) (not F7) (not U6))
       (or (= A1 M7) (not F7) (not U6))
       (or (= Z K7) (not F7) (not U6))
       (or (= N7 1) (not F7) (not U6))
       (or (= L7 E3) (not F7) (not U6))
       (or (= K7 W6) (not F7) (not U6))
       (or (not W5) (not K5) (= P6 J3))
       (or (not W5) (not K5) (= K1 Q6))
       (or (not W5) (not K5) (= J1 P6))
       (or (not W5) (not K5) (= I1 N6))
       (or (not W5) (not K5) (= R6 O6))
       (or (not W5) (not K5) (= Q6 0))
       (or (not W5) (not K5) (= O6 I3))
       (or (not W5) (not K5) (= N6 (- 1)))
       (or (not W5) (not K5) G1)
       (or (not T5) (not F5) (= K1 E6))
       (or (not T5) (not F5) (= J1 D6))
       (or (not T5) (not F5) (= I1 B6))
       (or (not T5) (not F5) (= R6 C6))
       (or (not T5) (not F5) (= E6 1))
       (or (not T5) (not F5) (= D6 J3))
       (or (not T5) (not F5) (= C6 I3))
       (or (not T5) (not F5) (= B6 J3))
       (or W2 (not F5) (not T5))
       (or C1 (not R5) (not (= H3 1)))
       (or (not R5) (not C1) (not (= H3 0)))
       (or (not C1) (not R5) (not T6))
       (or C1 (not R5) (not Y6))
       (or (= K1 I6) (not U5) (not O5))
       (or (= J1 H6) (not U5) (not O5))
       (or (= I1 F6) (not U5) (not O5))
       (or (= R6 G6) (not U5) (not O5))
       (or (= I6 0) (not U5) (not O5))
       (or (= H6 J3) (not U5) (not O5))
       (or (= G6 Q5) (not U5) (not O5))
       (or (not U5) (not O5) (= F6 (- 1)))
       (or (not N5) (not K5) (not G1))
       (or (= T1 S4) (not A4) (not G4))
       (or (= S1 Q4) (not A4) (not G4))
       (or (= S4 0) (not A4) (not G4))
       (or (= R4 X3) (not A4) (not G4))
       (or (= Q4 D4) (not A4) (not G4))
       (or (= P4 C4) (not A4) (not G4))
       (or (= O4 (- 1)) (not A4) (not G4))
       (or (= R1 O4) (not A4) (not G4))
       (or (= E5 R4) (not A4) (not G4))
       (or (= D5 P4) (not A4) (not G4))
       (or (= T1 X4) (not H4) (not Y3))
       (or (= S1 V4) (not H4) (not Y3))
       (or (not H4) (not Y3) (= T4 (- 1)))
       (or (= R1 T4) (not H4) (not Y3))
       (or (= E5 W4) (not H4) (not Y3))
       (or (= D5 U4) (not H4) (not Y3))
       (or (= X4 0) (not H4) (not Y3))
       (or (= W4 X3) (not H4) (not Y3))
       (or (= V4 O3) (not H4) (not Y3))
       (or (= U4 M3) (not H4) (not Y3))
       (or O1 (not H4) (not Y3))
       (or (not O1) (not B4) (not Y3))
       (or (= T1 C5) (not V3) (not I4))
       (or (= S1 A5) (not V3) (not I4))
       (or (= R1 Y4) (not V3) (not I4))
       (or (= E5 B5) (not V3) (not I4))
       (or (= D5 Z4) (not V3) (not I4))
       (or (= C5 0) (not V3) (not I4))
       (or (= B5 X3) (not V3) (not I4))
       (or (= A5 N3) (not V3) (not I4))
       (or (= Z4 M3) (not V3) (not I4))
       (or (not V3) (not I4) (= Y4 (- 1)))
       (or P1 (not V3) (not I4))
       (or (not P1) (not V3) (not Z3))
       (or (= L4 N3) (not S3) (not F4))
       (or (= T1 N4) (not S3) (not F4))
       (or (= S1 L4) (not S3) (not F4))
       (or (= N4 1) (not S3) (not F4))
       (or (= M4 P3) (not S3) (not F4))
       (or (= R1 J4) (not S3) (not F4))
       (or (= E5 M4) (not S3) (not F4))
       (or (= D5 K4) (not S3) (not F4))
       (or (= K4 M3) (not S3) (not F4))
       (or (= J4 U3) (not S3) (not F4))
       (or (not W3) V1 (not R3))
       (or (not V1) (not R3) (not T3))
       a!1
       (or (not T9) (= D (and A C)))
       (or (not T9) (= B (= S9 1)))
       (or (not T9) (not (= B C)))
       (or (not T9) (= V9 (+ 1 Z2)))
       (or (not T9) (and R8 U9))
       a!2
       (or (not Z6) (= W (or V S2)))
       (or (not Z6) (and A7 X6))
       (or (not S6) (and R5 T6))
       a!3
       (or (not M5) (= F1 (or E1 V2)))
       (or (not M5) (and N5 K5))
       (or (not H5) (= H1 (= J3 U2)))
       (or (not H5) (= J5 (ite H1 (- 1) J3)))
       (or (not H5) (and I5 F5))
       (or (not F5) (and E4 G5))
       (or (not Z9) (and W9 A10))
       (or (not B7) (= U (= G3 R2)))
       (or (not B7) (= D7 (ite U 1 E3)))
       (or (not B7) (and C7 Z6))
       (or (not X6) (= X (= G3 (- 1))))
       (or (not X6) (and R5 Y6))
       (or (not K5) (= G1 (= K3 (- 1))))
       (or (not K5) (and E4 L5))
       (or V1 (not (= Q3 1)))
       (or (not V1) (not (= Q3 0)))
       a!4
       (or (not R8) (= J R9))
       (or (not R8) (= I (+ G H)))
       (or (not R8) (= H E8))
       (or (not R8) (= G (+ F E)))
       (or (not R8) (= F R6))
       (or (not R8) (= E D5))
       (or (not R8) (= S9 (+ I J)))
       (or (not O8) (= L (= C3 O2)))
       (or (not O8) (= Q8 (ite L 1 A3)))
       (or (not O8) (and M8 P8))
       a!5
       (or (not M8) (= N (or M P2)))
       (or (not M8) (and K8 N8))
       (or (not K8) (= O (= C3 (- 1))))
       (or (not K8) (and L8 E7))
       (or (not H8) (= P (= B3 O2)))
       (or (not H8) (= J8 (ite P (- 1) B3)))
       (or (not H8) (and F8 I8))
       (or (not F8) (and G8 E7))
       (or (not U6) (= Y (= F3 R2)))
       (or (not U6) (= W6 (ite Y (- 1) F3)))
       (or (not U6) (and V6 S6))
       (or (not O5) (= D1 (= K3 U2)))
       (or (not O5) (= Q5 (ite D1 1 I3)))
       (or (not O5) (and P5 M5))
       (or (not A4) (= M1 (= O3 X2)))
       (or (not A4) (= D4 (ite M1 N3 O3)))
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
       (= Z9 true)
       (not (= (<= 8 Z2) U1))
       (= 3 v_262)))
      )
      (main_1 v_262
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
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Bool) (T2 Bool) (U2 Int) (V2 Bool) (W2 Bool) (X2 Int) (Y2 Bool) (Z2 Bool) (A3 Int) (B3 Bool) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Bool) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Bool) (C5 Bool) (D5 Int) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Int) (J5 Int) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Bool) (P6 Int) (Q6 Bool) (R6 Bool) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Bool) (W6 Int) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Bool) (Z7 Bool) (A8 Bool) (B8 Bool) (C8 Int) (D8 Bool) (E8 Bool) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Bool) (J8 Int) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Bool) (O8 Bool) (P8 Bool) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Bool) (P9 Int) (Q9 Bool) (R9 Bool) (S9 Bool) (T9 Bool) (U9 Bool) (V9 Bool) (W9 Int) (X9 Bool) (Y9 Bool) (Z9 Bool) (A10 Bool) (B10 Bool) (C10 Bool) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Int) (Q10 Int) (R10 Int) (S10 Int) (T10 Int) (U10 Int) (V10 Int) (W10 Int) (X10 Int) (Y10 Int) (Z10 Bool) (A11 Bool) (B11 Int) (C11 Bool) (D11 Bool) (v_290 Int) (v_291 Int) ) 
    (=>
      (and
        (main_1 v_290
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
        (let ((a!1 (or (not Z10) (not (= (<= K6 3) A))))
      (a!2 (or (not S6) (not (= (<= K2 X2) E1))))
      (a!3 (or (not X9) (not (= (<= 2 Y10) K))))
      (a!4 (or (not S9) (not (= (<= C2 R2) M))))
      (a!5 (or (not F8) (not (= (<= G2 U2) V))))
      (a!6 (or (not E5) (not (= (<= O2 A3) N1)))))
  (and (= 2 v_290)
       (or (and F8 M8) (and D8 N8) (and A8 O8) (not K8) (and P8 Y7) (and L8 H8))
       (or (and U9 Y9)
           (and S9 Z9)
           (and Q9 A10)
           (and N9 B10)
           (not X9)
           (and C10 L9))
       (or (and U6 Y6) (and Q6 A7) (and N6 B7) (and L6 C7) (not X6) (and Z6 S6))
       (or (and G5 L5) (and E5 M5) (and B5 N5) (not K5) (and O5 U3))
       (or (= Z4 K4) (not Z10) (not D11))
       (or (= Y4 J4) (not Z10) (not D11))
       (or (= A5 M4) (not Z10) (not D11))
       (or (= X4 I4) (not Z10) (not D11))
       (or (= W4 H4) (not Z10) (not D11))
       (or (= V4 F4) (not Z10) (not D11))
       (or (= U4 E4) (not Z10) (not D11))
       (or (= T4 D4) (not Z10) (not D11))
       (or (= S4 B4) (not Z10) (not D11))
       (or (= R4 A4) (not Z10) (not D11))
       (or (= Q4 Z3) (not Z10) (not D11))
       (or (= P4 X3) (not Z10) (not D11))
       (or (= O4 W3) (not Z10) (not D11))
       (or (= N4 V3) (not Z10) (not D11))
       (or (= M4 B11) (not Z10) (not D11))
       (or (= L4 U1) (not Z10) (not D11))
       (or (= K4 K6) (not Z10) (not D11))
       (or (= J4 Q) (not Z10) (not D11))
       (or (= I4 T1) (not Z10) (not D11))
       (or (= H4 J6) (not Z10) (not D11))
       (or (= G4 K1) (not Z10) (not D11))
       (or (= F4 S1) (not Z10) (not D11))
       (or (= E4 J1) (not Z10) (not D11))
       (or (= D4 X7) (not Z10) (not D11))
       (or (= C4 B1) (not Z10) (not D11))
       (or (= B4 I1) (not Z10) (not D11))
       (or (= A4 A1) (not Z10) (not D11))
       (or (= V3 X10) (not Z10) (not D11))
       (or (= Y1 L4) (not Z10) (not D11))
       (or (= X1 G4) (not Z10) (not D11))
       (or (= W1 C4) (not Z10) (not D11))
       (or (= V1 Y3) (not Z10) (not D11))
       (or (= Z3 K9) (not Z10) (not D11))
       (or (= Y3 S) (not Z10) (not D11))
       (or (= X3 Z) (not Z10) (not D11))
       (or (= W3 R) (not Z10) (not D11))
       (or (not D) (not Z10) (not D11))
       (or (= B1 F9) (not A8) (not O8))
       (or (= A1 E9) (not A8) (not O8))
       (or (= Z C9) (not A8) (not O8))
       (or (= F9 1) (not A8) (not O8))
       (or (= E9 F2) (not A8) (not O8))
       (or (= D9 E2) (not A8) (not O8))
       (or (= C9 C8) (not A8) (not O8))
       (or (= K9 D9) (not A8) (not O8))
       (or (not F1) (not S6) (not V6))
       (or (= K1 S7) (not N6) (not B7))
       (or (= J1 R7) (not N6) (not B7))
       (or (= I1 P7) (not N6) (not B7))
       (or (= X7 Q7) (not N6) (not B7))
       (or (= S7 1) (not N6) (not B7))
       (or (= R7 J2) (not N6) (not B7))
       (or (= Q7 I2) (not N6) (not B7))
       (or (= P7 P6) (not N6) (not B7))
       (or (= K1 W7) (not L6) (not C7))
       (or (= J1 V7) (not L6) (not C7))
       (or (= I1 T7) (not L6) (not C7))
       (or (= X7 U7) (not L6) (not C7))
       (or (= W7 1) (not L6) (not C7))
       (or (= V7 J2) (not L6) (not C7))
       (or (= U7 I2) (not L6) (not C7))
       (or (= T7 J2) (not L6) (not C7))
       (or Z2 (not L6) (not C7))
       (or (not Z2) (not L6) (not O6))
       (or (not W2) (not Y7) (not B8))
       (or L1 (not K5) (not (= L2 1)))
       (or (not L1) (not K5) (not (= L2 0)))
       (or (not L1) (not K5) (not M6))
       (or T (not K8) (not (= D2 1)))
       (or (not T) (not K8) (not (= D2 0)))
       (or K (not X9) (not A11))
       (or (= S G10) (not U9) (not Y9))
       (or (= R F10) (not U9) (not Y9))
       (or (= Q D10) (not U9) (not Y9))
       (or (= G10 0) (not U9) (not Y9))
       (or (= F10 B2) (not U9) (not Y9))
       (or (not U9) (not Y9) (= D10 (- 1)))
       (or (= X10 E10) (not U9) (not Y9))
       (or (= E10 W9) (not U9) (not Y9))
       (or (= S K10) (not S9) (not Z9))
       (or (= R J10) (not S9) (not Z9))
       (or (= Q H10) (not S9) (not Z9))
       (or (= J10 C2) (not S9) (not Z9))
       (or (= I10 A2) (not S9) (not Z9))
       (or (= X10 I10) (not S9) (not Z9))
       (or (= K10 0) (not S9) (not Z9))
       (or (not S9) (not Z9) (= H10 (- 1)))
       (or N (not S9) (not Z9))
       (or (not N) (not V9) (not S9))
       (or T (not K8) (not R9))
       (or (= S O10) (not Q9) (not A10))
       (or (= R N10) (not Q9) (not A10))
       (or (= Q L10) (not Q9) (not A10))
       (or (= L10 (- 1)) (not Q9) (not A10))
       (or (= X10 M10) (not Q9) (not A10))
       (or (= O10 0) (not Q9) (not A10))
       (or (= N10 B2) (not Q9) (not A10))
       (or (= M10 A2) (not Q9) (not A10))
       (or O (not Q9) (not A10))
       (or (not O) (not Q9) (not T9))
       (or (= S S10) (not N9) (not B10))
       (or (= R R10) (not N9) (not B10))
       (or (= Q P10) (not N9) (not B10))
       (or (= X10 Q10) (not N9) (not B10))
       (or (= S10 1) (not N9) (not B10))
       (or (= R10 B2) (not N9) (not B10))
       (or (= Q10 A2) (not N9) (not B10))
       (or (= P10 P9) (not N9) (not B10))
       (or (not T) (not M9) (not K8))
       (or (not T2) (not L9) (not O9))
       (or (not P8) (not Y7) (= B1 J9))
       (or (not P8) (not Y7) (= A1 I9))
       (or (not P8) (not Y7) (= Z G9))
       (or (not P8) (not Y7) (= I9 F2))
       (or (not P8) (not Y7) (= H9 E2))
       (or (not P8) (not Y7) (= G9 F2))
       (or (not P8) (not Y7) (= K9 H9))
       (or (not P8) (not Y7) (= J9 1))
       (or W2 (not Y7) (not P8))
       (or (not L8) (not H8) (= B1 T8))
       (or (not L8) (not H8) (= A1 S8))
       (or (not L8) (not H8) (= Z Q8))
       (or (not L8) (not H8) (= T8 0))
       (or (not L8) (not H8) (= S8 F2))
       (or (not L8) (not H8) (= R8 J8))
       (or (not L8) (not H8) (= Q8 (- 1)))
       (or (not L8) (not H8) (= K9 R8))
       (or (= B1 X8) (not F8) (not M8))
       (or (= A1 W8) (not F8) (not M8))
       (or (= Z U8) (not F8) (not M8))
       (or (= X8 0) (not F8) (not M8))
       (or (= W8 G2) (not F8) (not M8))
       (or (= V8 E2) (not F8) (not M8))
       (or (not F8) (not M8) (= U8 (- 1)))
       (or (= K9 V8) (not F8) (not M8))
       (or W (not F8) (not M8))
       (or (not W) (not F8) (not I8))
       (or (= B1 B9) (not D8) (not N8))
       (or (= A1 A9) (not D8) (not N8))
       (or (= Z Y8) (not D8) (not N8))
       (or (= B9 0) (not D8) (not N8))
       (or (= A9 F2) (not D8) (not N8))
       (or (= Z8 E2) (not D8) (not N8))
       (or (= Y8 (- 1)) (not D8) (not N8))
       (or (= K9 Z8) (not D8) (not N8))
       (or X (not D8) (not N8))
       (or (not X) (not D8) (not G8))
       (or (not Z6) (not S6) (= K1 K7))
       (or (not Z6) (not S6) (= J1 J7))
       (or (not Z6) (not S6) (= I1 H7))
       (or (not Z6) (not S6) (= X7 I7))
       (or (not Z6) (not S6) (= K7 0))
       (or (not Z6) (not S6) (= J7 K2))
       (or (not Z6) (not S6) (= I7 I2))
       (or (not Z6) (not S6) (= H7 (- 1)))
       (or (not Z6) (not S6) F1)
       (or C1 (not X6) (not (= H2 1)))
       (or (not X6) (not C1) (not (= H2 0)))
       (or C1 (not X6) (not E8))
       (or (not Z7) (not C1) (not X6))
       (or (= K1 G7) (not U6) (not Y6))
       (or (= J1 F7) (not U6) (not Y6))
       (or (= I1 D7) (not U6) (not Y6))
       (or (= X7 E7) (not U6) (not Y6))
       (or (= G7 0) (not U6) (not Y6))
       (or (= F7 J2) (not U6) (not Y6))
       (or (= E7 W6) (not U6) (not Y6))
       (or (not U6) (not Y6) (= D7 (- 1)))
       (or L1 (not K5) (not R6))
       (or (= K1 O7) (not Q6) (not A7))
       (or (= J1 N7) (not Q6) (not A7))
       (or (= I1 L7) (not Q6) (not A7))
       (or (= X7 M7) (not Q6) (not A7))
       (or (= O7 0) (not Q6) (not A7))
       (or (= N7 J2) (not Q6) (not A7))
       (or (= M7 I2) (not Q6) (not A7))
       (or (= L7 (- 1)) (not Q6) (not A7))
       (or G1 (not Q6) (not A7))
       (or (not G1) (not Q6) (not T6))
       (or (not O5) (not U3) (= U1 I6))
       (or (not O5) (not U3) (= T1 G6))
       (or (not O5) (not U3) (= S1 E6))
       (or (not O5) (not U3) (= K6 H6))
       (or (not O5) (not U3) (= J6 F6))
       (or (not O5) (not U3) (= I6 1))
       (or (not O5) (not U3) (= H6 P2))
       (or (not O5) (not U3) (= G6 N2))
       (or (not O5) (not U3) (= F6 M2))
       (or (not O5) (not U3) (= E6 N2))
       (or (not R1) (not O5) (not U3))
       (or (not G5) (= T5 0) (not L5))
       (or (not G5) (= S5 D5) (not L5))
       (or (not G5) (= R5 J5) (not L5))
       (or (not G5) (= Q5 I5) (not L5))
       (or (not G5) (not L5) (= P5 (- 1)))
       (or (not G5) (= U1 T5) (not L5))
       (or (not G5) (= T1 R5) (not L5))
       (or (not G5) (= S1 P5) (not L5))
       (or (not G5) (= K6 S5) (not L5))
       (or (not G5) (= J6 Q5) (not L5))
       (or (= W5 O2) (not E5) (not M5))
       (or (= V5 M2) (not E5) (not M5))
       (or (= U5 (- 1)) (not E5) (not M5))
       (or (= U1 Y5) (not E5) (not M5))
       (or (= T1 W5) (not E5) (not M5))
       (or (= S1 U5) (not E5) (not M5))
       (or (= K6 X5) (not E5) (not M5))
       (or (= J6 V5) (not E5) (not M5))
       (or (= Y5 0) (not E5) (not M5))
       (or (= X5 D5) (not E5) (not M5))
       (or O1 (not E5) (not M5))
       (or (not O1) (not E5) (not H5))
       (or R1 (not C5) (not U3))
       (or (= U1 D6) (not B5) (not N5))
       (or (= T1 B6) (not B5) (not N5))
       (or (= S1 Z5) (not B5) (not N5))
       (or (= K6 C6) (not B5) (not N5))
       (or (= J6 A6) (not B5) (not N5))
       (or (= D6 0) (not B5) (not N5))
       (or (= C6 D5) (not B5) (not N5))
       (or (= B6 N2) (not B5) (not N5))
       (or (= A6 M2) (not B5) (not N5))
       (or (= Z5 (- 1)) (not B5) (not N5))
       (or P1 (not B5) (not N5))
       (or (not P1) (not B5) (not F5))
       (or (not C10) (not L9) (= S W10))
       (or (not C10) (not L9) (= R V10))
       (or (not C10) (not L9) (= Q T10))
       (or (not C10) (not L9) (= X10 U10))
       (or (not C10) (not L9) (= W10 1))
       (or (not C10) (not L9) (= V10 B2))
       (or (not C10) (not L9) (= U10 A2))
       (or (not C10) (not L9) (= T10 B2))
       (or (not C10) (not L9) T2)
       (or (not C11) (and Z10 D11))
       a!1
       (or (not Z10) (= D (and A C)))
       (or (not Z10) (= B (= Y10 1)))
       (or (not Z10) (not (= B C)))
       (or (not Z10) (= B11 (+ 1 Z1)))
       (or (not Z10) (and X9 A11))
       (or (not H8) (= U (= G2 U2)))
       (or (not H8) (= J8 (ite U 1 E2)))
       (or (not H8) (and F8 I8))
       (or (not A8) (= Y (= F2 U2)))
       (or (not A8) (= C8 (ite Y (- 1) F2)))
       (or (not A8) (and Y7 B8))
       (or (not Y7) (and X6 Z7))
       a!2
       (or (not S6) (= F1 (or Y2 E1)))
       (or (not S6) (and Q6 T6))
       (or (not N6) (= H1 (= J2 X2)))
       (or (not N6) (= P6 (ite H1 (- 1) J2)))
       (or (not N6) (and L6 O6))
       (or (not L6) (and K5 M6))
       (or R1 (not (= Q2 1)))
       (or (not R1) (not (= Q2 0)))
       a!3
       (or (not X9) (= J X10))
       (or (not X9) (= I (+ G H)))
       (or (not X9) (= H K9))
       (or (not X9) (= G (+ F E)))
       (or (not X9) (= F X7))
       (or (not X9) (= E J6))
       (or (not X9) (= Y10 (+ I J)))
       (or (not U9) (= L (= C2 R2)))
       (or (not U9) (= W9 (ite L 1 A2)))
       (or (not U9) (and S9 V9))
       a!4
       (or (not S9) (= N (or S2 M)))
       (or (not S9) (and Q9 T9))
       (or (not Q9) (= O (= C2 (- 1))))
       (or (not Q9) (and R9 K8))
       (or (not N9) (= P (= B2 R2)))
       (or (not N9) (= P9 (ite P (- 1) B2)))
       (or (not N9) (and L9 O9))
       (or (not L9) (and M9 K8))
       a!5
       (or (not F8) (= W (or V2 V)))
       (or (not F8) (and D8 G8))
       (or (not D8) (= X (= G2 (- 1))))
       (or (not D8) (and X6 E8))
       (or (not U6) (= D1 (= K2 X2)))
       (or (not U6) (= W6 (ite D1 1 I2)))
       (or (not U6) (and S6 V6))
       (or (not Q6) (= G1 (= K2 (- 1))))
       (or (not Q6) (and R6 K5))
       (or (not G5) (= M1 (= O2 A3)))
       (or (not G5) (= J5 (ite M1 N2 O2)))
       (or (not G5) (= I5 (ite M1 1 M2)))
       (or (not G5) (and E5 H5))
       a!6
       (or (not E5) (= O1 (or N1 B3)))
       (or (not E5) (and B5 F5))
       (or (not B5) (= P1 (= O2 (- 1))))
       (or (not B5) (= D5 (+ 1 P2)))
       (or (not B5) (and C5 U3))
       (= C11 true)
       (= Q1 true)
       (not (= (<= 8 Z1) Q1))
       (= 2 v_291)))
      )
      (main_1 v_291
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
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Bool) (P2 Bool) (Q2 Int) (R2 Bool) (S2 Bool) (T2 Int) (U2 Bool) (V2 Bool) (W2 Int) (X2 Bool) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Bool) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Int) (V3 Bool) (W3 Bool) (X3 Bool) (Y3 Bool) (Z3 Int) (A4 Int) (B4 Bool) (C4 Bool) (D4 Bool) (E4 Bool) (F4 Bool) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Bool) (G5 Int) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Int) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Bool) (T6 Int) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Int) (B7 Bool) (C7 Bool) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Bool) (G8 Int) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Int) (O8 Bool) (P8 Bool) (Q8 Bool) (R8 Bool) (S8 Bool) (T8 Bool) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Int) (Q9 Bool) (R9 Bool) (S9 Int) (T9 Bool) (U9 Bool) (V9 Bool) (W9 Bool) (v_257 Int) (v_258 Int) ) 
    (=>
      (and
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
        (let ((a!1 (or (not Q9) (not (= (<= B5 3) A))))
      (a!2 (or (not O8) (not (= (<= 2 P9) K))))
      (a!3 (or (not J8) (not (= (<= Y1 N2) M))))
      (a!4 (or (not W6) (not (= (<= C2 Q2) V))))
      (a!5 (or (not J5) (not (= (<= G2 T2) E1))))
      (a!6 (or (not V3) (not (= (<= K2 W2) N1)))))
  (and (= 2 v_257)
       (or (and R6 F7) (and Y6 C7) (and W6 D7) (not B7) (and G7 P6) (and E7 U6))
       (or (and J5 Q5) (and H5 R5) (and S5 E5) (not O5) (and T5 C5) (and P5 L5))
       (or (and E8 S8) (and L8 P8) (and J8 Q8) (and H8 R8) (and C8 T8) (not O8))
       (or (and X3 C4) (and V3 D4) (and S3 E4) (and Q3 F4) (not B4))
       (or (and Q9 U9) (and O8 V9) (not T9))
       (or (not G7) (not P6) (= B8 Y7))
       (or (not G7) (not P6) (= A8 1))
       (or (not G7) (not P6) (= Z7 B2))
       (or (not G7) (not P6) (= Y7 A2))
       (or (not G7) (not P6) (= X7 B2))
       (or (not G7) (not P6) (= B1 A8))
       (or (not G7) (not P6) (= A1 Z7))
       (or (not G7) (not P6) (= Z X7))
       (or S2 (not G7) (not P6))
       (or T (not B7) (not (= Z1 1)))
       (or (not B7) (not T) (not (= Z1 0)))
       (or (not X) (not X6) (not U6))
       (or (= B8 U7) (not R6) (not F7))
       (or (= W7 1) (not R6) (not F7))
       (or (= V7 B2) (not R6) (not F7))
       (or (= U7 A2) (not R6) (not F7))
       (or (= T7 T6) (not R6) (not F7))
       (or (= B1 W7) (not R6) (not F7))
       (or (= A1 V7) (not R6) (not F7))
       (or (= Z T7) (not R6) (not F7))
       (or (not T5) (not C5) (= J1 M6))
       (or (not T5) (not C5) (= I1 K6))
       (or (not T5) (not C5) (= L6 E2))
       (or (not T5) (not C5) (= K1 N6))
       (or (not T5) (not C5) (= O6 L6))
       (or (not T5) (not C5) (= N6 1))
       (or (not T5) (not C5) (= M6 F2))
       (or (not T5) (not C5) (= K6 F2))
       (or C1 (not O5) (not (= D2 1)))
       (or (not O5) (not C1) (not (= D2 0)))
       (or C1 (not O5) (not V6))
       (or (= J1 E6) (not R5) (not H5))
       (or (= I1 C6) (not R5) (not H5))
       (or (= K1 F6) (not R5) (not H5))
       (or (= O6 D6) (not R5) (not H5))
       (or (= F6 0) (not R5) (not H5))
       (or (= E6 F2) (not R5) (not H5))
       (or (= D6 E2) (not R5) (not H5))
       (or (not R5) (not H5) (= C6 (- 1)))
       (or G1 (not R5) (not H5))
       (or L1 (not B4) (not (= H2 1)))
       (or (not L1) (not B4) (not (= H2 0)))
       (or L1 (not I5) (not B4))
       (or (not L1) (not D5) (not B4))
       (or D (not U9) (not Q9))
       (or K (not O8) (not R9))
       (or (not K) (not O8) (not V9))
       (or (= S X8) (not P8) (not L8))
       (or (= R W8) (not P8) (not L8))
       (or (= Q U8) (not P8) (not L8))
       (or (= W8 X1) (not P8) (not L8))
       (or (= V8 N8) (not P8) (not L8))
       (or (= O9 V8) (not P8) (not L8))
       (or (= X8 0) (not P8) (not L8))
       (or (not P8) (not L8) (= U8 (- 1)))
       (or (= S B9) (not Q8) (not J8))
       (or (= R A9) (not Q8) (not J8))
       (or (= Q Y8) (not Q8) (not J8))
       (or (= B9 0) (not Q8) (not J8))
       (or (= Z8 W1) (not Q8) (not J8))
       (or (not Q8) (not J8) (= Y8 (- 1)))
       (or (= O9 Z8) (not Q8) (not J8))
       (or (= A9 Y1) (not Q8) (not J8))
       (or N (not Q8) (not J8))
       (or (not N) (not J8) (not M8))
       (or (not I8) (not B7) T)
       (or (= S F9) (not H8) (not R8))
       (or (= R E9) (not H8) (not R8))
       (or (= Q C9) (not H8) (not R8))
       (or (= E9 X1) (not H8) (not R8))
       (or (not H8) (not R8) (= C9 (- 1)))
       (or (= O9 D9) (not H8) (not R8))
       (or (= F9 0) (not H8) (not R8))
       (or (= D9 W1) (not H8) (not R8))
       (or O (not H8) (not R8))
       (or (not O) (not H8) (not K8))
       (or (= S J9) (not E8) (not S8))
       (or (= R I9) (not E8) (not S8))
       (or (= Q G9) (not E8) (not S8))
       (or (= O9 H9) (not E8) (not S8))
       (or (= J9 1) (not E8) (not S8))
       (or (= I9 X1) (not E8) (not S8))
       (or (= H9 W1) (not E8) (not S8))
       (or (= G9 G8) (not E8) (not S8))
       (or (not D8) (not B7) (not T))
       (or (= S N9) (not C8) (not T8))
       (or (= R M9) (not C8) (not T8))
       (or (= Q K9) (not C8) (not T8))
       (or (= O9 L9) (not C8) (not T8))
       (or (= N9 1) (not C8) (not T8))
       (or (= M9 X1) (not C8) (not T8))
       (or (= L9 W1) (not C8) (not T8))
       (or (= K9 X1) (not C8) (not T8))
       (or P2 (not C8) (not T8))
       (or (not P2) (not F8) (not C8))
       (or (not E7) (not U6) (= B8 Q7))
       (or (not E7) (not U6) (= S7 0))
       (or (not E7) (not U6) (= R7 B2))
       (or (not E7) (not U6) (= Q7 A2))
       (or (not E7) (not U6) (= P7 (- 1)))
       (or (not E7) (not U6) (= B1 S7))
       (or (not E7) (not U6) (= A1 R7))
       (or (not E7) (not U6) (= Z P7))
       (or (not E7) (not U6) X)
       (or (= I7 A7) (not Y6) (not C7))
       (or (= B8 I7) (not Y6) (not C7))
       (or (= K7 0) (not Y6) (not C7))
       (or (= B1 K7) (not Y6) (not C7))
       (or (= A1 J7) (not Y6) (not C7))
       (or (= Z H7) (not Y6) (not C7))
       (or (= J7 B2) (not Y6) (not C7))
       (or (not Y6) (not C7) (= H7 (- 1)))
       (or (= B8 M7) (not D7) (not W6))
       (or (= O7 0) (not D7) (not W6))
       (or (= N7 C2) (not D7) (not W6))
       (or (= M7 A2) (not D7) (not W6))
       (or (not D7) (not W6) (= L7 (- 1)))
       (or (= B1 O7) (not D7) (not W6))
       (or (= A1 N7) (not D7) (not W6))
       (or (= Z L7) (not D7) (not W6))
       (or W (not D7) (not W6))
       (or (not W) (not W6) (not Z6))
       (or (not S6) (not S2) (not P6))
       (or (not Q6) (not O5) (not C1))
       (or (not S5) (not E5) (= J1 I6))
       (or (not S5) (not E5) (= I1 G6))
       (or (not S5) (not E5) (= K1 J6))
       (or (not S5) (not E5) (= O6 H6))
       (or (not S5) (not E5) (= J6 1))
       (or (not S5) (not E5) (= I6 F2))
       (or (not S5) (not E5) (= H6 E2))
       (or (not S5) (not E5) (= G6 G5))
       (or (not P5) (not L5) (= J1 W5))
       (or (not P5) (not L5) (= I1 U5))
       (or (not P5) (not L5) (= K1 X5))
       (or (not P5) (not L5) (= O6 V5))
       (or (not P5) (not L5) (= X5 0))
       (or (not P5) (not L5) (= W5 F2))
       (or (not P5) (not L5) (= V5 N5))
       (or (not P5) (not L5) (= U5 (- 1)))
       (or (not K5) (not H5) (not G1))
       (or (= J1 A6) (not Q5) (not J5))
       (or (= I1 Y5) (not Q5) (not J5))
       (or (= K1 B6) (not Q5) (not J5))
       (or (= O6 Z5) (not Q5) (not J5))
       (or (= B6 0) (not Q5) (not J5))
       (or (= A6 G2) (not Q5) (not J5))
       (or (= Z5 E2) (not Q5) (not J5))
       (or (not Q5) (not J5) (= Y5 (- 1)))
       (or F1 (not Q5) (not J5))
       (or (not F1) (not J5) (not M5))
       (or (= H4 Z3) (not X3) (not C4))
       (or (= K4 0) (not X3) (not C4))
       (or (= J4 U3) (not X3) (not C4))
       (or (= I4 A4) (not X3) (not C4))
       (or (= U1 K4) (not X3) (not C4))
       (or (= T1 I4) (not X3) (not C4))
       (or (= S1 G4) (not X3) (not C4))
       (or (= B5 J4) (not X3) (not C4))
       (or (= A5 H4) (not X3) (not C4))
       (or (not X3) (not C4) (= G4 (- 1)))
       (or (= P4 0) (not D4) (not V3))
       (or (= O4 U3) (not D4) (not V3))
       (or (= N4 K2) (not D4) (not V3))
       (or (= M4 I2) (not D4) (not V3))
       (or (not D4) (not V3) (= L4 (- 1)))
       (or (= U1 P4) (not D4) (not V3))
       (or (= T1 N4) (not D4) (not V3))
       (or (= S1 L4) (not D4) (not V3))
       (or (= B5 O4) (not D4) (not V3))
       (or (= A5 M4) (not D4) (not V3))
       (or O1 (not D4) (not V3))
       (or (not O1) (not Y3) (not V3))
       (or (not S3) (= U1 U4) (not E4))
       (or (not S3) (= T1 S4) (not E4))
       (or (not S3) (= S1 Q4) (not E4))
       (or (not S3) (= B5 T4) (not E4))
       (or (not S3) (= A5 R4) (not E4))
       (or (not S3) (= U4 0) (not E4))
       (or (not S3) (= T4 U3) (not E4))
       (or (not S3) (= S4 J2) (not E4))
       (or (not S3) (= R4 I2) (not E4))
       (or (not S3) (not E4) (= Q4 (- 1)))
       (or (not S3) P1 (not E4))
       (or (not S3) (not P1) (not W3))
       (or (= U1 Z4) (not F4) (not Q3))
       (or (= T1 X4) (not F4) (not Q3))
       (or (= S1 V4) (not F4) (not Q3))
       (or (= B5 Y4) (not F4) (not Q3))
       (or (= A5 W4) (not F4) (not Q3))
       (or (= Z4 1) (not F4) (not Q3))
       (or (= Y4 L2) (not F4) (not Q3))
       (or (= X4 J2) (not F4) (not Q3))
       (or (= W4 I2) (not F4) (not Q3))
       (or (= V4 J2) (not F4) (not Q3))
       (or (not R1) (not F4) (not Q3))
       (or R1 (not Q3) (not T3))
       (or V2 (not T5) (not C5))
       (or (not V2) (not F5) (not C5))
       a!1
       (or (not Q9) (= D (and A C)))
       (or (not Q9) (= B (= P9 1)))
       (or (not Q9) (not (= B C)))
       (or (not Q9) (= S9 (+ 1 V1)))
       (or (not Q9) (and O8 R9))
       (or (not P6) (and Q6 O5))
       (or (not C5) (and B4 D5))
       (or (not U6) (= X (= C2 (- 1))))
       (or (not U6) (and O5 V6))
       (or (not R6) (= Y (= B2 Q2)))
       (or (not R6) (= T6 (ite Y (- 1) B2)))
       (or (not R6) (and S6 P6))
       (or (not L5) (= D1 (= G2 T2)))
       (or (not L5) (= N5 (ite D1 1 E2)))
       (or (not L5) (and J5 M5))
       (or (not H5) (= G1 (= G2 (- 1))))
       (or (not H5) (and B4 I5))
       (or (not E5) (= H1 (= F2 T2)))
       (or (not E5) (= G5 (ite H1 (- 1) F2)))
       (or (not E5) (and F5 C5))
       (or R1 (not (= M2 1)))
       (or (not R1) (not (= M2 0)))
       a!2
       (or (not O8) (= J O9))
       (or (not O8) (= F O6))
       (or (not O8) (= E A5))
       (or (not O8) (= I (+ G H)))
       (or (not O8) (= H B8))
       (or (not O8) (= G (+ F E)))
       (or (not O8) (= P9 (+ I J)))
       (or (not L8) (= L (= Y1 N2)))
       (or (not L8) (= N8 (ite L 1 W1)))
       (or (not L8) (and J8 M8))
       a!3
       (or (not J8) (= N (or O2 M)))
       (or (not J8) (and H8 K8))
       (or (not H8) (= O (= Y1 (- 1))))
       (or (not H8) (and I8 B7))
       (or (not E8) (= P (= X1 N2)))
       (or (not E8) (= G8 (ite P (- 1) X1)))
       (or (not E8) (and C8 F8))
       (or (not C8) (and D8 B7))
       (or (not Y6) (= U (= C2 Q2)))
       (or (not Y6) (= A7 (ite U 1 A2)))
       (or (not Y6) (and W6 Z6))
       a!4
       (or (not W6) (= W (or R2 V)))
       (or (not W6) (and U6 X6))
       a!5
       (or (not J5) (= F1 (or U2 E1)))
       (or (not J5) (and K5 H5))
       (or (not X3) (= M1 (= K2 W2)))
       (or (not X3) (= Z3 (ite M1 1 I2)))
       (or (not X3) (= A4 (ite M1 J2 K2)))
       (or (not X3) (and V3 Y3))
       a!6
       (or (not V3) (= O1 (or X2 N1)))
       (or (not V3) (and S3 W3))
       (or (not S3) (= P1 (= K2 (- 1))))
       (or (not S3) (= U3 (+ 1 L2)))
       (or (not S3) (and Q3 T3))
       (or (not R3) (and T9 W9))
       (= Q1 true)
       (= R3 true)
       (not (= (<= 8 V1) Q1))
       (= 3 v_258)))
      )
      (main_1 v_258
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
