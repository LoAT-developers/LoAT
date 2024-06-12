; ./prepared/seahorn/./sv_comp_flat_small/seq-mthreaded/pals_lcr-var-start-time.4_false-unreach-call.1.ufo.UNBOUNDED.pals.c.flat_000.smt2
(set-logic HORN)


(declare-fun |main_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Bool Bool Int Bool Bool Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Bool) (T Bool) (U Int) (V Bool) (W Bool) (X Int) (Y Bool) (Z Bool) (A1 Int) (B1 Bool) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (v_45 Int) ) 
    (=>
      (and
        (and true (= 0 v_45))
      )
      (main_1 v_45
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
        S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Bool) (U2 Bool) (V2 Int) (W2 Bool) (X2 Bool) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Int) (C3 Bool) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Bool) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Bool) (C4 Int) (D4 Int) (E4 Int) (F4 Bool) (G4 Int) (H4 Bool) (I4 Int) (J4 Int) (K4 Int) (L4 Bool) (M4 Int) (N4 Bool) (O4 Int) (P4 Int) (Q4 Int) (R4 Bool) (S4 Int) (T4 Bool) (U4 Bool) (V4 Bool) (W4 Bool) (X4 Bool) (Y4 Bool) (Z4 Bool) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Bool) (V5 Bool) (W5 Bool) (X5 Bool) (Y5 Bool) (Z5 Bool) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (v_186 Int) (v_187 Int) ) 
    (=>
      (and
        (main_1 v_186
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
        (let ((a!1 (or (not C5) (not (= (= I4 O4) O))))
      (a!2 (or (not A5) (not (= (<= O4 (- 1)) R))))
      (a!3 (or (not Y4) (not (= (<= I4 (- 1)) Y))))
      (a!4 (or (not W4) (not (= (<= C4 (- 1)) F1))))
      (a!5 (or (not U4) (not (= (<= W3 (- 1)) T1))))
      (a!6 (or (not U4) (not (= (<= R1 0) S1)))))
  (and (= 0 v_186)
       (= S4 (ite R4 1 0))
       (= M4 (ite L4 1 0))
       (= G4 (ite F4 1 0))
       (= A4 (ite Z3 1 0))
       (or (and C5 G5)
           (and A5 H5)
           (and Y4 I5)
           (and W4 J5)
           (and U4 K5)
           (and U3 L5)
           (not F5))
       (or (= M6 X3) (not Z5) (not W5))
       (or (not Z5) (not W5) (= K6 (- 1)))
       (or (= J6 E4) (not Z5) (not W5))
       (or (= H6 M4) (not Z5) (not W5))
       (or (not Z5) (not W5) (= G6 (- 1)))
       (or (= E6 J4) (not Z5) (not W5))
       (or (= D6 S4) (not Z5) (not W5))
       (or (= D Q6) (not Z5) (not W5))
       (or (= C L6) (not Z5) (not W5))
       (or (= B H6) (not Z5) (not W5))
       (or (= A D6) (not Z5) (not W5))
       (or (= D7 P6) (not Z5) (not W5))
       (or (= C7 O6) (not Z5) (not W5))
       (or (= B7 N6) (not Z5) (not W5))
       (or (= A7 M6) (not Z5) (not W5))
       (or (= Z6 K6) (not Z5) (not W5))
       (or (= Y6 J6) (not Z5) (not W5))
       (or (= X6 I6) (not Z5) (not W5))
       (or (= W6 G6) (not Z5) (not W5))
       (or (= V6 F6) (not Z5) (not W5))
       (or (= U6 E6) (not Z5) (not W5))
       (or (= T6 C6) (not Z5) (not W5))
       (or (= S6 B6) (not Z5) (not W5))
       (or (= R6 A6) (not Z5) (not W5))
       (or (= Q6 A4) (not Z5) (not W5))
       (or (= P6 V3) (not Z5) (not W5))
       (or (not Z5) (not W5) (= O6 (- 1)))
       (or (= N6 Y3) (not Z5) (not W5))
       (or (= L6 G4) (not Z5) (not W5))
       (or (= I6 D4) (not Z5) (not W5))
       (or (= F6 K4) (not Z5) (not W5))
       (or (not Z5) (not W5) (= C6 (- 1)))
       (or (= B6 Q4) (not Z5) (not W5))
       (or (= A6 P4) (not Z5) (not W5))
       (or (= M5 E5) (not C5) (not G5))
       (or (= A2 M5) (not C5) (not G5))
       (or (= A2 N5) (not A5) (not H5))
       (or (not A5) (not N5) (not H5))
       (or (= A2 O5) (not Y4) (not I5))
       (or (not Y4) (not O5) (not I5))
       (or (= A2 P5) (not W4) (not J5))
       (or (not W4) (not P5) (not J5))
       (or (= A2 Q5) (not K5) (not U4))
       (or (not K5) (not U4) (not Q5))
       (or (not B4) (not X5) (not F5))
       (or (= A2 R5) (not U3) (not L5))
       (or (not U3) (not R5) (not L5))
       (or (not Z1) (not U3) (not L5))
       (or Z1 (not V4) (not U3))
       (or (not Y1) (not K5) (not U4))
       (or Y1 (not U4) (not X4))
       (or (not K1) (not W4) (not J5))
       (or K1 (not W4) (not Z4))
       (or (not D1) (not Y4) (not I5))
       (or D1 (not Y4) (not B5))
       (or (not W) (not A5) (not H5))
       (or W (not A5) (not D5))
       (or (not Y5) (and W5 Z5))
       (or (not W5) (and F5 X5))
       (or (not F5) (not (= T4 V5)))
       (or (not F5) (not (= N4 U5)))
       (or (not F5) (not (= H4 T5)))
       (or (not F5) (not (= B4 S5)))
       a!1
       (or (not C5) (= E5 (and O P)))
       (or (not C5) (= N (or L M)))
       (or (not C5) (not (= N P)))
       (or (not C5) (= M (= C4 O4)))
       (or (not C5) (= L (or J K)))
       (or (not C5) (= K (= C4 I4)))
       (or (not C5) (= J (or H I)))
       (or (not C5) (= I (= W3 O4)))
       (or (not C5) (= H (or F G)))
       (or (not C5) (= G (= W3 I4)))
       (or (not C5) (= F (or E R4)))
       (or (not C5) (= E (= W3 C4)))
       (or (not C5) (and A5 D5))
       a!2
       (or (not A5) (not (= L4 Q)))
       (or (not A5) (= W (and U V)))
       (or (not A5) (= V (= Q4 O4)))
       (or (not A5) (= U (and S T)))
       (or (not A5) (= T (= P4 0)))
       (or (not A5) (= S (and Q R)))
       (or (not A5) (and Y4 B5))
       a!3
       (or (not Y4) (not (= F4 X)))
       (or (not Y4) (= D1 (and B1 C1)))
       (or (not Y4) (= C1 (= K4 I4)))
       (or (not Y4) (= B1 (and Z A1)))
       (or (not Y4) (= A1 (= J4 0)))
       (or (not Y4) (= Z (and X Y)))
       (or (not Y4) (and W4 Z4))
       a!4
       (or (not W4) (not (= Z3 E1)))
       (or (not W4) (= K1 (and I1 J1)))
       (or (not W4) (= J1 (= E4 C4)))
       (or (not W4) (= I1 (and G1 H1)))
       (or (not W4) (= H1 (= D4 0)))
       (or (not W4) (= G1 (and E1 F1)))
       (or (not W4) (and U4 X4))
       a!5
       a!6
       (or (not U4) (= Y1 (and W1 X1)))
       (or (not U4) (= X1 (= Y3 W3)))
       (or (not U4) (= W1 (and U1 V1)))
       (or (not U4) (= V1 (= X3 0)))
       (or (not U4) (= U1 (and S1 T1)))
       (or (not U4) (= R1 (+ P1 Q1)))
       (or (not U4) (= Q1 (ite T4 1 0)))
       (or (not U4) (= P1 (+ N1 O1)))
       (or (not U4) (= O1 (ite N4 1 0)))
       (or (not U4) (= N1 (+ M1 L1)))
       (or (not U4) (= M1 (ite H4 1 0)))
       (or (not U4) (= L1 (ite B4 1 0)))
       (or (not U4) (and U3 V4))
       (or A2 (not F5))
       (= Y5 true)
       (= Z1 (= V3 0))
       (= 1 v_187)))
      )
      (main_1 v_187
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
        O4
        V5
        T4
        I4
        U5
        N4
        C4
        T5
        H4
        W3
        S5
        R6
        S6
        T6
        A
        U6
        V6
        W6
        B
        X6
        Y6
        Z6
        C
        A7
        B7
        C7
        D7
        D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Bool) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Bool) (U2 Bool) (V2 Int) (W2 Bool) (X2 Bool) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Int) (C3 Bool) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Bool) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Bool) (A4 Int) (B4 Bool) (C4 Int) (D4 Int) (E4 Int) (F4 Bool) (G4 Int) (H4 Bool) (I4 Int) (J4 Int) (K4 Int) (L4 Bool) (M4 Int) (N4 Bool) (O4 Int) (P4 Int) (Q4 Int) (R4 Bool) (S4 Int) (T4 Bool) (U4 Bool) (V4 Bool) (W4 Bool) (X4 Bool) (Y4 Bool) (Z4 Bool) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Bool) (V5 Bool) (W5 Bool) (X5 Bool) (Y5 Bool) (Z5 Bool) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (v_186 Int) (v_187 Int) ) 
    (=>
      (and
        (main_1 v_186
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
        (let ((a!1 (or (not C5) (not (= (= I4 O4) O))))
      (a!2 (or (not A5) (not (= (<= O4 (- 1)) R))))
      (a!3 (or (not Y4) (not (= (<= I4 (- 1)) Y))))
      (a!4 (or (not W4) (not (= (<= C4 (- 1)) F1))))
      (a!5 (or (not U4) (not (= (<= W3 (- 1)) T1))))
      (a!6 (or (not U4) (not (= (<= R1 0) S1)))))
  (and (= 0 v_186)
       (= S4 (ite R4 1 0))
       (= M4 (ite L4 1 0))
       (= G4 (ite F4 1 0))
       (= A4 (ite Z3 1 0))
       (or (and C5 G5)
           (and A5 H5)
           (and Y4 I5)
           (and W4 J5)
           (and U4 K5)
           (and U3 L5)
           (not F5))
       (or (= M6 X3) (not Z5) (not W5))
       (or (not Z5) (not W5) (= K6 (- 1)))
       (or (= J6 E4) (not Z5) (not W5))
       (or (= H6 M4) (not Z5) (not W5))
       (or (not Z5) (not W5) (= G6 (- 1)))
       (or (= E6 J4) (not Z5) (not W5))
       (or (= D6 S4) (not Z5) (not W5))
       (or (= D Q6) (not Z5) (not W5))
       (or (= C L6) (not Z5) (not W5))
       (or (= B H6) (not Z5) (not W5))
       (or (= A D6) (not Z5) (not W5))
       (or (= D7 P6) (not Z5) (not W5))
       (or (= C7 O6) (not Z5) (not W5))
       (or (= B7 N6) (not Z5) (not W5))
       (or (= A7 M6) (not Z5) (not W5))
       (or (= Z6 K6) (not Z5) (not W5))
       (or (= Y6 J6) (not Z5) (not W5))
       (or (= X6 I6) (not Z5) (not W5))
       (or (= W6 G6) (not Z5) (not W5))
       (or (= V6 F6) (not Z5) (not W5))
       (or (= U6 E6) (not Z5) (not W5))
       (or (= T6 C6) (not Z5) (not W5))
       (or (= S6 B6) (not Z5) (not W5))
       (or (= R6 A6) (not Z5) (not W5))
       (or (= Q6 A4) (not Z5) (not W5))
       (or (= P6 V3) (not Z5) (not W5))
       (or (not Z5) (not W5) (= O6 (- 1)))
       (or (= N6 Y3) (not Z5) (not W5))
       (or (= L6 G4) (not Z5) (not W5))
       (or (= I6 D4) (not Z5) (not W5))
       (or (= F6 K4) (not Z5) (not W5))
       (or (not Z5) (not W5) (= C6 (- 1)))
       (or (= B6 Q4) (not Z5) (not W5))
       (or (= A6 P4) (not Z5) (not W5))
       (or (= M5 E5) (not C5) (not G5))
       (or (= A2 M5) (not C5) (not G5))
       (or (= A2 N5) (not A5) (not H5))
       (or (not A5) (not N5) (not H5))
       (or (= A2 O5) (not Y4) (not I5))
       (or (not Y4) (not O5) (not I5))
       (or (= A2 P5) (not W4) (not J5))
       (or (not W4) (not P5) (not J5))
       (or (= A2 Q5) (not K5) (not U4))
       (or (not K5) (not U4) (not Q5))
       (or B4 (not X5) (not F5))
       (or (= A2 R5) (not U3) (not L5))
       (or (not U3) (not R5) (not L5))
       (or (not Z1) (not U3) (not L5))
       (or Z1 (not V4) (not U3))
       (or (not Y1) (not K5) (not U4))
       (or Y1 (not U4) (not X4))
       (or (not K1) (not W4) (not J5))
       (or K1 (not W4) (not Z4))
       (or (not D1) (not Y4) (not I5))
       (or D1 (not Y4) (not B5))
       (or (not W) (not A5) (not H5))
       (or W (not A5) (not D5))
       (or (not Y5) (and W5 Z5))
       (or (not W5) (and F5 X5))
       (or (not F5) (not (= T4 V5)))
       (or (not F5) (not (= N4 U5)))
       (or (not F5) (not (= H4 T5)))
       (or (not F5) (not (= B4 S5)))
       a!1
       (or (not C5) (= E5 (and O P)))
       (or (not C5) (= N (or L M)))
       (or (not C5) (not (= N P)))
       (or (not C5) (= M (= C4 O4)))
       (or (not C5) (= L (or J K)))
       (or (not C5) (= K (= C4 I4)))
       (or (not C5) (= J (or H I)))
       (or (not C5) (= I (= W3 O4)))
       (or (not C5) (= H (or F G)))
       (or (not C5) (= G (= W3 I4)))
       (or (not C5) (= F (or E R4)))
       (or (not C5) (= E (= W3 C4)))
       (or (not C5) (and A5 D5))
       a!2
       (or (not A5) (not (= L4 Q)))
       (or (not A5) (= W (and U V)))
       (or (not A5) (= V (= Q4 O4)))
       (or (not A5) (= U (and S T)))
       (or (not A5) (= T (= P4 0)))
       (or (not A5) (= S (and Q R)))
       (or (not A5) (and Y4 B5))
       a!3
       (or (not Y4) (not (= F4 X)))
       (or (not Y4) (= D1 (and B1 C1)))
       (or (not Y4) (= C1 (= K4 I4)))
       (or (not Y4) (= B1 (and Z A1)))
       (or (not Y4) (= A1 (= J4 0)))
       (or (not Y4) (= Z (and X Y)))
       (or (not Y4) (and W4 Z4))
       a!4
       (or (not W4) (not (= Z3 E1)))
       (or (not W4) (= K1 (and I1 J1)))
       (or (not W4) (= J1 (= E4 C4)))
       (or (not W4) (= I1 (and G1 H1)))
       (or (not W4) (= H1 (= D4 0)))
       (or (not W4) (= G1 (and E1 F1)))
       (or (not W4) (and U4 X4))
       a!5
       a!6
       (or (not U4) (= Y1 (and W1 X1)))
       (or (not U4) (= X1 (= Y3 W3)))
       (or (not U4) (= W1 (and U1 V1)))
       (or (not U4) (= V1 (= X3 0)))
       (or (not U4) (= U1 (and S1 T1)))
       (or (not U4) (= R1 (+ P1 Q1)))
       (or (not U4) (= Q1 (ite T4 1 0)))
       (or (not U4) (= P1 (+ N1 O1)))
       (or (not U4) (= O1 (ite N4 1 0)))
       (or (not U4) (= N1 (+ M1 L1)))
       (or (not U4) (= M1 (ite H4 1 0)))
       (or (not U4) (= L1 (ite B4 1 0)))
       (or (not U4) (and U3 V4))
       (or A2 (not F5))
       (= Y5 true)
       (= Z1 (= V3 0))
       (= 2 v_187)))
      )
      (main_1 v_187
        R6
        S6
        T6
        A
        U6
        V6
        W6
        B
        X6
        Y6
        Z6
        C
        A7
        B7
        C7
        D7
        D
        O4
        V5
        T4
        I4
        U5
        N4
        C4
        T5
        H4
        W3
        S5
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
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Bool) (S2 Bool) (T2 Int) (U2 Bool) (V2 Bool) (W2 Int) (X2 Bool) (Y2 Bool) (Z2 Int) (A3 Bool) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Bool) (Y4 Bool) (Z4 Int) (A5 Bool) (B5 Bool) (C5 Int) (D5 Bool) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Int) (I5 Int) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Bool) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Int) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Int) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Bool) (Y7 Bool) (Z7 Bool) (A8 Bool) (B8 Int) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Int) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Bool) (O8 Bool) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Bool) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Int) (P9 Bool) (Q9 Bool) (R9 Bool) (S9 Bool) (T9 Bool) (U9 Bool) (V9 Int) (W9 Bool) (X9 Bool) (Y9 Bool) (Z9 Bool) (A10 Bool) (B10 Bool) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Int) (Q10 Int) (R10 Int) (S10 Int) (T10 Int) (U10 Int) (V10 Int) (W10 Int) (X10 Int) (Y10 Bool) (Z10 Bool) (A11 Bool) (B11 Bool) (v_288 Int) (v_289 Int) ) 
    (=>
      (and
        (main_1 v_288
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
        R3)
        (let ((a!1 (or (not Y10) (not (= (<= J6 3) A))))
      (a!2 (or (not E8) (not (= (<= H3 T2) V))))
      (a!3 (or (not W9) (not (= (<= 2 X10) K))))
      (a!4 (or (not R9) (not (= (<= D3 Q2) M))))
      (a!5 (or (not R6) (not (= (<= L3 W2) E1))))
      (a!6 (or (not D5) (not (= (<= P3 Z2) N1)))))
  (and (= 1 v_288)
       (or (and M9 X9)
           (and K9 Y9)
           (and T9 Z9)
           (and R9 A10)
           (not W9)
           (and B10 P9))
       (or (and Z7 K8) (and X7 L8) (and G8 M8) (and E8 N8) (and C8 O8) (not J8))
       (or (and X4 K5) (and F5 L5) (and D5 M5) (and A5 N5) (not J5))
       (or (= W4 I4) (not Y10) (not B11))
       (or (= V4 H4) (not Y10) (not B11))
       (or (= U4 G4) (not Y10) (not B11))
       (or (= T4 F4) (not Y10) (not B11))
       (or (= S4 D4) (not Y10) (not B11))
       (or (= R4 C4) (not Y10) (not B11))
       (or (= Q4 B4) (not Y10) (not B11))
       (or (= P4 Z3) (not Y10) (not B11))
       (or (= O4 Y3) (not Y10) (not B11))
       (or (= N4 X3) (not Y10) (not B11))
       (or (= M4 V3) (not Y10) (not B11))
       (or (= L4 U3) (not Y10) (not B11))
       (or (= K4 T3) (not Y10) (not B11))
       (or (= J4 T1) (not Y10) (not B11))
       (or (= I4 J6) (not Y10) (not B11))
       (or (= H4 Q) (not Y10) (not B11))
       (or (= G4 S1) (not Y10) (not B11))
       (or (= F4 I6) (not Y10) (not B11))
       (or (= E4 K1) (not Y10) (not B11))
       (or (= D4 R1) (not Y10) (not B11))
       (or (= C4 J1) (not Y10) (not B11))
       (or (= X3 J9) (not Y10) (not B11))
       (or (= W3 S) (not Y10) (not B11))
       (or (= V3 Z) (not Y10) (not B11))
       (or (= U3 R) (not Y10) (not B11))
       (or (= T3 W10) (not Y10) (not B11))
       (or (= Y1 J4) (not Y10) (not B11))
       (or (= X1 E4) (not Y10) (not B11))
       (or (= W1 A4) (not Y10) (not B11))
       (or (= V1 W3) (not Y10) (not B11))
       (or (= B4 W7) (not Y10) (not B11))
       (or (= A4 B1) (not Y10) (not B11))
       (or (= Z3 I1) (not Y10) (not B11))
       (or (= Y3 A1) (not Y10) (not B11))
       (or (= A9 0) (not G8) (not M8))
       (or (= Z8 G3) (not G8) (not M8))
       (or (= Y8 I8) (not G8) (not M8))
       (or (= X8 (- 1)) (not G8) (not M8))
       (or (= B1 A9) (not G8) (not M8))
       (or (= A1 Z8) (not G8) (not M8))
       (or (= Z X8) (not G8) (not M8))
       (or (= J9 Y8) (not G8) (not M8))
       (or (= E9 0) (not E8) (not N8))
       (or (= D9 H3) (not E8) (not N8))
       (or (= C9 F3) (not E8) (not N8))
       (or (= B9 (- 1)) (not E8) (not N8))
       (or (= B1 E9) (not E8) (not N8))
       (or (= A1 D9) (not E8) (not N8))
       (or (= Z B9) (not E8) (not N8))
       (or (= J9 C9) (not E8) (not N8))
       (or (= I9 0) (not C8) (not O8))
       (or (= H9 G3) (not C8) (not O8))
       (or (= G9 F3) (not C8) (not O8))
       (or (= F9 (- 1)) (not C8) (not O8))
       (or (= B1 I9) (not C8) (not O8))
       (or (= A1 H9) (not C8) (not O8))
       (or (= Z F9) (not C8) (not O8))
       (or (= J9 G9) (not C8) (not O8))
       (or (= K1 N7) (not T6) (not Z6))
       (or (= J1 M7) (not T6) (not Z6))
       (or (= I1 K7) (not T6) (not Z6))
       (or (= W7 L7) (not T6) (not Z6))
       (or (= N7 0) (not T6) (not Z6))
       (or (= M7 K3) (not T6) (not Z6))
       (or (= L7 V6) (not T6) (not Z6))
       (or (= K7 (- 1)) (not T6) (not Z6))
       (or (= S7 (- 1)) (not P6) (not B7))
       (or (= K1 V7) (not P6) (not B7))
       (or (= J1 U7) (not P6) (not B7))
       (or (= I1 S7) (not P6) (not B7))
       (or (= W7 T7) (not P6) (not B7))
       (or (= V7 0) (not P6) (not B7))
       (or (= U7 K3) (not P6) (not B7))
       (or (= T7 J3) (not P6) (not B7))
       (or (not Y2) (not K6) (not N6))
       (or L1 (not (= M3 1)) (not J5))
       (or (not L1) (not (= M3 0)) (not J5))
       (or L1 (not J5) (not Q6))
       (or (not L1) (not J5) (not L6))
       (or G1 (not P6) (not B7))
       (or C1 (not (= I3 1)) (not W6))
       (or (not C1) (not (= I3 0)) (not W6))
       (or (not C1) (not W6) (not Y7))
       (or X (not C8) (not O8))
       (or W (not E8) (not N8))
       (or (not W) (not E8) (not H8))
       (or (not D) (not Y10) (not B11))
       (or K (not W9) (not Z10))
       (or (= S N10) (not T9) (not Z9))
       (or (= R M10) (not T9) (not Z9))
       (or (= Q K10) (not T9) (not Z9))
       (or (= K10 (- 1)) (not T9) (not Z9))
       (or (= W10 L10) (not T9) (not Z9))
       (or (= N10 0) (not T9) (not Z9))
       (or (= M10 C3) (not T9) (not Z9))
       (or (= L10 V9) (not T9) (not Z9))
       (or (= S R10) (not R9) (not A10))
       (or (= R Q10) (not R9) (not A10))
       (or (= Q O10) (not R9) (not A10))
       (or (= W10 P10) (not R9) (not A10))
       (or (= R10 0) (not R9) (not A10))
       (or (= Q10 D3) (not R9) (not A10))
       (or (= P10 B3) (not R9) (not A10))
       (or (= O10 (- 1)) (not R9) (not A10))
       (or N (not R9) (not A10))
       (or (not N) (not U9) (not R9))
       (or (not O) (not P9) (not S9))
       (or (= S F10) (not X9) (not M9))
       (or (= R E10) (not X9) (not M9))
       (or (= Q C10) (not X9) (not M9))
       (or (= F10 1) (not X9) (not M9))
       (or (= E10 C3) (not X9) (not M9))
       (or (= C10 O9) (not X9) (not M9))
       (or (= W10 D10) (not X9) (not M9))
       (or (= D10 B3) (not X9) (not M9))
       (or (= S J10) (not K9) (not Y9))
       (or (= R I10) (not K9) (not Y9))
       (or (= Q G10) (not K9) (not Y9))
       (or (= I10 C3) (not K9) (not Y9))
       (or (= H10 B3) (not K9) (not Y9))
       (or (= W10 H10) (not K9) (not Y9))
       (or (= J10 1) (not K9) (not Y9))
       (or (= G10 C3) (not K9) (not Y9))
       (or S2 (not K9) (not Y9))
       (or (not S2) (not N9) (not K9))
       (or T (not (= E3 1)) (not J8))
       (or (not J8) (not T) (not (= E3 0)))
       (or T (not J8) (not Q9))
       (or (not T) (not L9) (not J8))
       (or (not X) (not C8) (not F8))
       (or C1 (not W6) (not D8))
       (or (not Z7) (= S8 1) (not K8))
       (or (not Z7) (= R8 G3) (not K8))
       (or (not Z7) (= P8 B8) (not K8))
       (or (not Z7) (= B1 S8) (not K8))
       (or (not Z7) (= A1 R8) (not K8))
       (or (not Z7) (= Z P8) (not K8))
       (or (not Z7) (= Q8 F3) (not K8))
       (or (not Z7) (= J9 Q8) (not K8))
       (or (not V2) (not X7) (not A8))
       (or (= W8 1) (not X7) (not L8))
       (or (= V8 G3) (not X7) (not L8))
       (or (= U8 F3) (not X7) (not L8))
       (or (= T8 G3) (not X7) (not L8))
       (or (= B1 W8) (not X7) (not L8))
       (or (= A1 V8) (not X7) (not L8))
       (or (= Z T8) (not X7) (not L8))
       (or (= J9 U8) (not X7) (not L8))
       (or V2 (not X7) (not L8))
       (or (not Y6) (not K6) (= K1 J7))
       (or (not Y6) (not K6) (= J1 I7))
       (or (not Y6) (not K6) (= I1 G7))
       (or (not Y6) (not K6) (= W7 H7))
       (or (not Y6) (not K6) (= J7 1))
       (or (not Y6) (not K6) (= I7 K3))
       (or (not Y6) (not K6) (= H7 J3))
       (or (not Y6) (not K6) (= G7 K3))
       (or Y2 (not K6) (not Y6))
       (or (not X6) (not M6) (= K1 F7))
       (or (not X6) (not M6) (= J1 E7))
       (or (not X6) (not M6) (= I1 C7))
       (or (not X6) (not M6) (= W7 D7))
       (or (not X6) (not M6) (= F7 1))
       (or (not X6) (not M6) (= E7 K3))
       (or (not X6) (not M6) (= D7 J3))
       (or (not X6) (not M6) (= C7 O6))
       (or (not G1) (not P6) (not S6))
       (or (= K1 R7) (not R6) (not A7))
       (or (= J1 Q7) (not R6) (not A7))
       (or (= I1 O7) (not R6) (not A7))
       (or (= W7 P7) (not R6) (not A7))
       (or (= R7 0) (not R6) (not A7))
       (or (= Q7 L3) (not R6) (not A7))
       (or (= P7 J3) (not R6) (not A7))
       (or (= O7 (- 1)) (not R6) (not A7))
       (or F1 (not R6) (not A7))
       (or (not F1) (not R6) (not U6))
       (or (= X5 0) (not F5) (not L5))
       (or (= W5 C5) (not F5) (not L5))
       (or (= V5 I5) (not F5) (not L5))
       (or (= U5 H5) (not F5) (not L5))
       (or (= T5 (- 1)) (not F5) (not L5))
       (or (= T1 X5) (not F5) (not L5))
       (or (= S1 V5) (not F5) (not L5))
       (or (= R1 T5) (not F5) (not L5))
       (or (= J6 W5) (not F5) (not L5))
       (or (= I6 U5) (not F5) (not L5))
       (or (= Y5 (- 1)) (not D5) (not M5))
       (or (= T1 C6) (not D5) (not M5))
       (or (= S1 A6) (not D5) (not M5))
       (or (= R1 Y5) (not D5) (not M5))
       (or (= J6 B6) (not D5) (not M5))
       (or (= I6 Z5) (not D5) (not M5))
       (or (= C6 0) (not D5) (not M5))
       (or (= B6 C5) (not D5) (not M5))
       (or (= A6 P3) (not D5) (not M5))
       (or (= Z5 N3) (not D5) (not M5))
       (or O1 (not D5) (not M5))
       (or (not O1) (not D5) (not G5))
       (or (not B5) U1 (not S3))
       (or (= T1 H6) (not A5) (not N5))
       (or (= S1 F6) (not A5) (not N5))
       (or (= R1 D6) (not A5) (not N5))
       (or (= J6 G6) (not A5) (not N5))
       (or (= I6 E6) (not A5) (not N5))
       (or (= H6 0) (not A5) (not N5))
       (or (= G6 C5) (not A5) (not N5))
       (or (= F6 O3) (not A5) (not N5))
       (or (= E6 N3) (not A5) (not N5))
       (or (= D6 (- 1)) (not A5) (not N5))
       (or P1 (not A5) (not N5))
       (or (not P1) (not A5) (not E5))
       (or (not U1) (not S3) (not Y4))
       (or (= S5 1) (not X4) (not K5))
       (or (= R5 Q3) (not X4) (not K5))
       (or (= Q5 O3) (not X4) (not K5))
       (or (= T1 S5) (not X4) (not K5))
       (or (= S1 Q5) (not X4) (not K5))
       (or (= R1 O5) (not X4) (not K5))
       (or (= J6 R5) (not X4) (not K5))
       (or (= I6 P5) (not X4) (not K5))
       (or (= P5 N3) (not X4) (not K5))
       (or (= O5 Z4) (not X4) (not K5))
       (or (not B10) (not P9) (= S V10))
       (or (not B10) (not P9) (= R U10))
       (or (not B10) (not P9) (= Q S10))
       (or (not B10) (not P9) (= W10 T10))
       (or (not B10) (not P9) (= V10 0))
       (or (not B10) (not P9) (= U10 C3))
       (or (not B10) (not P9) (= T10 B3))
       (or (not B10) (not P9) (= S10 (- 1)))
       (or (not B10) (not P9) O)
       (or (not A11) (and Y10 B11))
       a!1
       (or (not Y10) (= D (and A C)))
       (or (not Y10) (= B (= X10 1)))
       (or (not Y10) (not (= B C)))
       (or (not Y10) (and W9 Z10))
       (or (not G8) (= U (= H3 T2)))
       (or (not G8) (= I8 (ite U 1 F3)))
       (or (not G8) (and E8 H8))
       a!2
       (or (not E8) (= W (or V U2)))
       (or (not E8) (and F8 C8))
       (or (not C8) (= X (= H3 (- 1))))
       (or (not C8) (and D8 W6))
       (or (not T6) (= D1 (= L3 W2)))
       (or (not T6) (= V6 (ite D1 1 J3)))
       (or (not T6) (and R6 U6))
       (or (not P6) (= G1 (= L3 (- 1))))
       (or (not P6) (and J5 Q6))
       (or (not M6) (= H1 (= K3 W2)))
       (or (not M6) (= O6 (ite H1 (- 1) K3)))
       (or (not M6) (and K6 N6))
       (or (not K6) (and J5 L6))
       (or U1 (not (= R3 1)))
       (or (not U1) (not (= R3 0)))
       a!3
       (or (not W9) (= J W10))
       (or (not W9) (= I (+ G H)))
       (or (not W9) (= H J9))
       (or (not W9) (= G (+ F E)))
       (or (not W9) (= F W7))
       (or (not W9) (= E I6))
       (or (not W9) (= X10 (+ I J)))
       (or (not T9) (= L (= D3 Q2)))
       (or (not T9) (= V9 (ite L 1 B3)))
       (or (not T9) (and R9 U9))
       a!4
       (or (not R9) (= N (or M R2)))
       (or (not R9) (and P9 S9))
       (or (not P9) (= O (= D3 (- 1))))
       (or (not P9) (and J8 Q9))
       (or (not M9) (= P (= C3 Q2)))
       (or (not M9) (= O9 (ite P (- 1) C3)))
       (or (not M9) (and K9 N9))
       (or (not K9) (and J8 L9))
       (or (not Z7) (= Y (= G3 T2)))
       (or (not Z7) (= B8 (ite Y (- 1) G3)))
       (or (not Z7) (and X7 A8))
       (or (not X7) (and W6 Y7))
       a!5
       (or (not R6) (= F1 (or E1 X2)))
       (or (not R6) (and S6 P6))
       (or (not F5) (= M1 (= P3 Z2)))
       (or (not F5) (= I5 (ite M1 O3 P3)))
       (or (not F5) (= H5 (ite M1 1 N3)))
       (or (not F5) (and D5 G5))
       a!6
       (or (not D5) (= O1 (or N1 A3)))
       (or (not D5) (and A5 E5))
       (or (not A5) (= P1 (= P3 (- 1))))
       (or (not A5) (= C5 (+ 1 Q3)))
       (or (not A5) (and B5 S3))
       (or (not X4) (= Q1 (= O3 Z2)))
       (or (not X4) (= Z4 (ite Q1 (- 1) O3)))
       (or (not X4) (and Y4 S3))
       (= A11 true)
       (or (and T6 Z6) (and R6 A7) (and P6 B7) (not W6) (and Y6 K6) (and X6 M6))
       (= 1 v_289)))
      )
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
        K4
        L4
        M4
        V1
        N4
        O4
        P4
        W1
        Q4
        R4
        S4
        X1
        T4
        U4
        V4
        W4
        Y1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Bool) (O2 Bool) (P2 Int) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Bool) (U2 Bool) (V2 Int) (W2 Bool) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Int) (S3 Bool) (T3 Bool) (U3 Int) (V3 Bool) (W3 Bool) (X3 Bool) (Y3 Bool) (Z3 Int) (A4 Int) (B4 Bool) (C4 Bool) (D4 Bool) (E4 Bool) (F4 Bool) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Bool) (G5 Int) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Int) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Bool) (T6 Int) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Int) (B7 Bool) (C7 Bool) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Bool) (G8 Int) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Bool) (N8 Int) (O8 Bool) (P8 Bool) (Q8 Bool) (R8 Bool) (S8 Bool) (T8 Bool) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Int) (Q9 Bool) (R9 Bool) (S9 Bool) (T9 Bool) (U9 Bool) (V9 Bool) (W9 Bool) (v_257 Int) (v_258 Int) ) 
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
        N3)
        (let ((a!1 (or (not Q9) (not (= (<= B5 3) A))))
      (a!2 (or (not W6) (not (= (<= D3 P2) V))))
      (a!3 (or (not J5) (not (= (<= H3 S2) E1))))
      (a!4 (or (not O8) (not (= (<= 2 P9) K))))
      (a!5 (or (not J8) (not (= (<= Z2 M2) M))))
      (a!6 (or (not V3) (not (= (<= L3 V2) N1)))))
  (and (= 1 v_257)
       (or (and L5 R5) (not O5) (and T5 H5) (and S5 J5) (and Q5 C5) (and P5 E5))
       (or (and E8 P8) (and C8 Q8) (and L8 R8) (and J8 S8) (and H8 T8) (not O8))
       (or (and S3 F4) (and P3 C4) (and X3 D4) (and V3 E4) (not B4))
       (or (and O8 U9) (not S9) (and T9 Q9))
       (or (= B8 M7) (not P6) (not D7))
       (or (= O7 1) (not P6) (not D7))
       (or (= N7 C3) (not P6) (not D7))
       (or (= M7 B3) (not P6) (not D7))
       (or (= B1 O7) (not P6) (not D7))
       (or (= A1 N7) (not P6) (not D7))
       (or (= Z L7) (not P6) (not D7))
       (or (= L7 C3) (not P6) (not D7))
       (or R2 (not P6) (not D7))
       (or D (not T9) (not Q9))
       (or (not F7) (not W6) (= B8 U7))
       (or (not F7) (not W6) (= W7 0))
       (or (not F7) (not W6) (= V7 D3))
       (or (not F7) (not W6) (= U7 B3))
       (or (not F7) (not W6) (= T7 (- 1)))
       (or (not F7) (not W6) (= B1 W7))
       (or (not F7) (not W6) (= A1 V7))
       (or (not F7) (not W6) (= Z T7))
       (or W (not F7) (not W6))
       (or (not C7) (not R6) (= B8 I7))
       (or (not C7) (not R6) (= K7 1))
       (or (not C7) (not R6) (= B1 K7))
       (or (not C7) (not R6) (= A1 J7))
       (or (not C7) (not R6) (= Z H7))
       (or (not C7) (not R6) (= J7 C3))
       (or (not C7) (not R6) (= I7 B3))
       (or (not C7) (not R6) (= H7 T6))
       (or T (not B7) (not (= A3 1)))
       (or (not B7) (not T) (not (= A3 0)))
       (or (not W) (not Z6) (not W6))
       (or C1 (not O5) (not (= E3 1)))
       (or (not O5) (not C1) (not (= E3 0)))
       (or (not C1) (not O5) (not Q6))
       (or C1 (not O5) (not V6))
       (or (= K1 F6) (not R5) (not L5))
       (or (= J1 E6) (not R5) (not L5))
       (or (= I1 C6) (not R5) (not L5))
       (or (= O6 D6) (not R5) (not L5))
       (or (= F6 0) (not R5) (not L5))
       (or (= E6 G3) (not R5) (not L5))
       (or (= D6 N5) (not R5) (not L5))
       (or (not R5) (not L5) (= C6 (- 1)))
       (or (not G1) (not K5) (not H5))
       (or (not U2) (not F5) (not C5))
       (or K (not O8) (not R9))
       (or (not K) (not O8) (not U9))
       (or (= S F9) (not R8) (not L8))
       (or (= R E9) (not R8) (not L8))
       (or (= Q C9) (not R8) (not L8))
       (or (= F9 0) (not R8) (not L8))
       (or (= D9 N8) (not R8) (not L8))
       (or (not R8) (not L8) (= C9 (- 1)))
       (or (= O9 D9) (not R8) (not L8))
       (or (= E9 Y2) (not R8) (not L8))
       (or (= S J9) (not S8) (not J8))
       (or (= R I9) (not S8) (not J8))
       (or (= Q G9) (not S8) (not J8))
       (or (= O9 H9) (not S8) (not J8))
       (or (= J9 0) (not S8) (not J8))
       (or (= I9 Z2) (not S8) (not J8))
       (or (= H9 X2) (not S8) (not J8))
       (or (not S8) (not J8) (= G9 (- 1)))
       (or N (not S8) (not J8))
       (or (not N) (not J8) (not M8))
       (or (not I8) (not B7) T)
       (or (= S N9) (not H8) (not T8))
       (or (= R M9) (not H8) (not T8))
       (or (= Q K9) (not H8) (not T8))
       (or (= O9 L9) (not H8) (not T8))
       (or (= N9 0) (not H8) (not T8))
       (or (= M9 Y2) (not H8) (not T8))
       (or (= L9 X2) (not H8) (not T8))
       (or (not H8) (not T8) (= K9 (- 1)))
       (or O (not H8) (not T8))
       (or (not O) (not H8) (not K8))
       (or (= S X8) (not P8) (not E8))
       (or (= R W8) (not P8) (not E8))
       (or (= Q U8) (not P8) (not E8))
       (or (= X8 1) (not P8) (not E8))
       (or (= W8 Y2) (not P8) (not E8))
       (or (= O9 V8) (not P8) (not E8))
       (or (= V8 X2) (not P8) (not E8))
       (or (= U8 G8) (not P8) (not E8))
       (or (not D8) (not B7) (not T))
       (or (= S B9) (not Q8) (not C8))
       (or (= R A9) (not Q8) (not C8))
       (or (= Q Y8) (not Q8) (not C8))
       (or (= A9 Y2) (not Q8) (not C8))
       (or (= Z8 X2) (not Q8) (not C8))
       (or (= O9 Z8) (not Q8) (not C8))
       (or (= B9 1) (not Q8) (not C8))
       (or (= Y8 Y2) (not Q8) (not C8))
       (or O2 (not Q8) (not C8))
       (or (not O2) (not C8) (not F8))
       (or (= B8 Q7) (not E7) (not Y6))
       (or (= S7 0) (not E7) (not Y6))
       (or (= R7 C3) (not E7) (not Y6))
       (or (= Q7 A7) (not E7) (not Y6))
       (or (not E7) (not Y6) (= P7 (- 1)))
       (or (= B1 S7) (not E7) (not Y6))
       (or (= A1 R7) (not E7) (not Y6))
       (or (= Z P7) (not E7) (not Y6))
       (or (not U6) (not X) (not X6))
       (or (not U6) (= B8 Y7) (not G7))
       (or (not U6) (= A8 0) (not G7))
       (or (not U6) (= Z7 C3) (not G7))
       (or (not U6) (= Y7 B3) (not G7))
       (or (not U6) (not G7) (= X7 (- 1)))
       (or (not U6) (= B1 A8) (not G7))
       (or (not U6) (= A1 Z7) (not G7))
       (or (not U6) (= Z X7) (not G7))
       (or (not U6) X (not G7))
       (or (not R2) (not S6) (not P6))
       (or (not T5) (not H5) (= N6 0))
       (or (not T5) (not H5) (= K1 N6))
       (or (not T5) (not H5) (= J1 M6))
       (or (not T5) (not H5) (= I1 K6))
       (or (not T5) (not H5) (= O6 L6))
       (or (not T5) (not H5) (= M6 G3))
       (or (not T5) (not H5) (= L6 F3))
       (or (not T5) (not H5) (= K6 (- 1)))
       (or (not T5) (not H5) G1)
       (or (not S5) (not J5) (= K1 J6))
       (or (not S5) (not J5) (= J1 I6))
       (or (not S5) (not J5) (= I1 G6))
       (or (not S5) (not J5) (= O6 H6))
       (or (not S5) (not J5) (= J6 0))
       (or (not S5) (not J5) (= I6 H3))
       (or (not S5) (not J5) (= H6 F3))
       (or (not S5) (not J5) (= G6 (- 1)))
       (or F1 (not S5) (not J5))
       (or (not Q5) (not C5) (= K1 B6))
       (or (not Q5) (not C5) (= J1 A6))
       (or (not Q5) (not C5) (= I1 Y5))
       (or (not Q5) (not C5) (= O6 Z5))
       (or (not Q5) (not C5) (= B6 1))
       (or (not Q5) (not C5) (= A6 G3))
       (or (not Q5) (not C5) (= Z5 F3))
       (or (not Q5) (not C5) (= Y5 G3))
       (or U2 (not C5) (not Q5))
       (or (not P5) (not E5) (= V5 F3))
       (or (not P5) (not E5) (= K1 X5))
       (or (not P5) (not E5) (= J1 W5))
       (or (not P5) (not E5) (= I1 U5))
       (or (not P5) (not E5) (= O6 V5))
       (or (not P5) (not E5) (= X5 1))
       (or (not P5) (not E5) (= W5 G3))
       (or (not P5) (not E5) (= U5 G5))
       (or (not F1) (not M5) (not J5))
       (or L1 (not B4) (not (= I3 1)))
       (or (not B4) (not L1) (not (= I3 0)))
       (or (not L1) (not B4) (not D5))
       (or L1 (not I5) (not B4))
       (or (not D4) (= T1 P4) (not X3))
       (or (not D4) (= S1 N4) (not X3))
       (or (not D4) (= P4 0) (not X3))
       (or (not D4) (= O4 U3) (not X3))
       (or (not D4) (= N4 A4) (not X3))
       (or (not D4) (= M4 Z3) (not X3))
       (or (not D4) (= L4 (- 1)) (not X3))
       (or (not D4) (= R1 L4) (not X3))
       (or (not D4) (= B5 O4) (not X3))
       (or (not D4) (= A5 M4) (not X3))
       (or (= T1 U4) (not E4) (not V3))
       (or (= S1 S4) (not E4) (not V3))
       (or (= T4 U3) (not E4) (not V3))
       (or (= S4 L3) (not E4) (not V3))
       (or (= R4 J3) (not E4) (not V3))
       (or (not E4) (not V3) (= Q4 (- 1)))
       (or (= R1 Q4) (not E4) (not V3))
       (or (= B5 T4) (not E4) (not V3))
       (or (= A5 R4) (not E4) (not V3))
       (or (= U4 0) (not E4) (not V3))
       (or O1 (not E4) (not V3))
       (or (not O1) (not Y3) (not V3))
       (or (= T1 Z4) (not S3) (not F4))
       (or (= S1 X4) (not S3) (not F4))
       (or (= R1 V4) (not S3) (not F4))
       (or (= B5 Y4) (not S3) (not F4))
       (or (= A5 W4) (not S3) (not F4))
       (or (= Z4 0) (not S3) (not F4))
       (or (= Y4 U3) (not S3) (not F4))
       (or (= X4 K3) (not S3) (not F4))
       (or (= W4 J3) (not S3) (not F4))
       (or (not S3) (not F4) (= V4 (- 1)))
       (or P1 (not S3) (not F4))
       (or (not W3) (not P1) (not S3))
       (or (not P3) (= T1 K4) (not C4))
       (or (not P3) (= S1 I4) (not C4))
       (or (not P3) (= R1 G4) (not C4))
       (or (not P3) (= B5 J4) (not C4))
       (or (not P3) (= A5 H4) (not C4))
       (or (not P3) (= K4 1) (not C4))
       (or (not P3) (= J4 M3) (not C4))
       (or (not P3) (= I4 K3) (not C4))
       (or (not P3) (= H4 J3) (not C4))
       (or (not P3) (= G4 R3) (not C4))
       (or U1 (not T3) (not O3))
       (or (not U1) (not O3) (not Q3))
       a!1
       (or (not Q9) (= D (and A C)))
       (or (not Q9) (= B (= P9 1)))
       (or (not Q9) (not (= B C)))
       (or (not Q9) (and O8 R9))
       a!2
       (or (not W6) (= W (or V Q2)))
       (or (not W6) (and U6 X6))
       (or (not R6) (= Y (= C3 P2)))
       (or (not R6) (= T6 (ite Y (- 1) C3)))
       (or (not R6) (and S6 P6))
       (or (not P6) (and O5 Q6))
       a!3
       (or (not J5) (= F1 (or E1 T2)))
       (or (not J5) (and H5 K5))
       (or (not E5) (= H1 (= G3 S2)))
       (or (not E5) (= G5 (ite H1 (- 1) G3)))
       (or (not E5) (and F5 C5))
       (or (not C5) (and B4 D5))
       (or U1 (not (= N3 1)))
       (or (not U1) (not (= N3 0)))
       (or (not V9) (and W9 S9))
       (or (not L5) (= D1 (= H3 S2)))
       (or (not L5) (= N5 (ite D1 1 F3)))
       (or (not L5) (and M5 J5))
       (or (not H5) (= G1 (= H3 (- 1))))
       (or (not H5) (and B4 I5))
       a!4
       (or (not O8) (= J O9))
       (or (not O8) (= I (+ G H)))
       (or (not O8) (= H B8))
       (or (not O8) (= G (+ F E)))
       (or (not O8) (= F O6))
       (or (not O8) (= E A5))
       (or (not O8) (= P9 (+ I J)))
       (or (not L8) (= L (= Z2 M2)))
       (or (not L8) (= N8 (ite L 1 X2)))
       (or (not L8) (and J8 M8))
       a!5
       (or (not J8) (= N (or N2 M)))
       (or (not J8) (and H8 K8))
       (or (not H8) (= O (= Z2 (- 1))))
       (or (not H8) (and I8 B7))
       (or (not E8) (= P (= Y2 M2)))
       (or (not E8) (= G8 (ite P (- 1) Y2)))
       (or (not E8) (and C8 F8))
       (or (not C8) (and D8 B7))
       (or (not Y6) (= U (= D3 P2)))
       (or (not Y6) (= A7 (ite U 1 B3)))
       (or (not Y6) (and Z6 W6))
       (or (not U6) (= X (= D3 (- 1))))
       (or (not U6) (and O5 V6))
       (or (not X3) (= M1 (= L3 V2)))
       (or (not X3) (= A4 (ite M1 K3 L3)))
       (or (not X3) (= Z3 (ite M1 1 J3)))
       (or (not X3) (and V3 Y3))
       a!6
       (or (not V3) (= O1 (or N1 W2)))
       (or (not V3) (and S3 W3))
       (or (not S3) (= P1 (= L3 (- 1))))
       (or (not S3) (= U3 (+ 1 M3)))
       (or (not S3) (and O3 T3))
       (or (not P3) (= Q1 (= K3 V2)))
       (or (not P3) (= R3 (ite Q1 (- 1) K3)))
       (or (not P3) (and O3 Q3))
       (= V9 true)
       (or (and P6 D7) (and Y6 E7) (and U6 G7) (not B7) (and F7 W6) (and C7 R6))
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
        N3)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Bool) (U2 Bool) (V2 Int) (W2 Bool) (X2 Bool) (Y2 Int) (Z2 Bool) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Bool) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Bool) (X4 Bool) (Y4 Int) (Z4 Bool) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Int) (E5 Int) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Bool) (H6 Bool) (I6 Bool) (J6 Bool) (K6 Int) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Bool) (P6 Bool) (Q6 Bool) (R6 Int) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Bool) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Bool) (U7 Bool) (V7 Bool) (W7 Bool) (X7 Int) (Y7 Bool) (Z7 Bool) (A8 Bool) (B8 Bool) (C8 Bool) (D8 Bool) (E8 Int) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Bool) (H9 Bool) (I9 Bool) (J9 Bool) (K9 Int) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Bool) (P9 Bool) (Q9 Bool) (R9 Int) (S9 Bool) (T9 Bool) (U9 Bool) (V9 Bool) (W9 Bool) (X9 Bool) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Int) (Q10 Int) (R10 Int) (S10 Int) (T10 Int) (U10 Bool) (V10 Bool) (W10 Bool) (X10 Bool) (v_284 Int) (v_285 Int) ) 
    (=>
      (and
        (main_1 v_284
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
        (let ((a!1 (or (not U10) (not (= (<= F6 3) A))))
      (a!2 (or (not A8) (not (= (<= E2 S2) V))))
      (a!3 (or (not S9) (not (= (<= 2 T10) K))))
      (a!4 (or (not N9) (not (= (<= A2 P2) M))))
      (a!5 (or (not N6) (not (= (<= I2 V2) E1))))
      (a!6 (or (not Z4) (not (= (<= M2 Y2) N1)))))
  (and (= 2 v_284)
       (or (and P9 T9) (and N9 U9) (and L9 V9) (and I9 W9) (not S9) (and X9 G9))
       (or (and C8 G8) (and Y7 I8) (and V7 J8) (and T7 K8) (not F8) (and H8 A8))
       (or (and B5 G5) (and Z4 H5) (and W4 I5) (not F5) (and J5 R3))
       (or (= U4 G4) (not U10) (not X10))
       (or (= T4 F4) (not U10) (not X10))
       (or (= V4 H4) (not U10) (not X10))
       (or (= S4 E4) (not U10) (not X10))
       (or (= R4 C4) (not U10) (not X10))
       (or (= Q4 B4) (not U10) (not X10))
       (or (= P4 A4) (not U10) (not X10))
       (or (= O4 Y3) (not U10) (not X10))
       (or (= N4 X3) (not U10) (not X10))
       (or (= M4 W3) (not U10) (not X10))
       (or (= L4 U3) (not U10) (not X10))
       (or (= K4 T3) (not U10) (not X10))
       (or (= J4 S3) (not U10) (not X10))
       (or (= I4 T1) (not U10) (not X10))
       (or (= H4 F6) (not U10) (not X10))
       (or (= G4 Q) (not U10) (not X10))
       (or (= F4 S1) (not U10) (not X10))
       (or (= E4 E6) (not U10) (not X10))
       (or (= D4 K1) (not U10) (not X10))
       (or (= C4 R1) (not U10) (not X10))
       (or (= B4 J1) (not U10) (not X10))
       (or (= A4 S7) (not U10) (not X10))
       (or (= Z3 B1) (not U10) (not X10))
       (or (= Y3 I1) (not U10) (not X10))
       (or (= T3 R) (not U10) (not X10))
       (or (= S3 S10) (not U10) (not X10))
       (or (= X1 I4) (not U10) (not X10))
       (or (= W1 D4) (not U10) (not X10))
       (or (= V1 Z3) (not U10) (not X10))
       (or (= U1 V3) (not U10) (not X10))
       (or (= X3 A1) (not U10) (not X10))
       (or (= W3 F9) (not U10) (not X10))
       (or (= V3 S) (not U10) (not X10))
       (or (= U3 Z) (not U10) (not X10))
       (or (not D) (not U10) (not X10))
       (or (= B1 O8) (not C8) (not G8))
       (or (= A1 N8) (not C8) (not G8))
       (or (= Z L8) (not C8) (not G8))
       (or (= O8 0) (not C8) (not G8))
       (or (= N8 D2) (not C8) (not G8))
       (or (not C8) (not G8) (= L8 (- 1)))
       (or (= M8 E8) (not C8) (not G8))
       (or (= F9 M8) (not C8) (not G8))
       (or (not W) (not A8) (not D8))
       (or (= B1 W8) (not Y7) (not I8))
       (or (= A1 V8) (not Y7) (not I8))
       (or (= Z T8) (not Y7) (not I8))
       (or (= W8 0) (not Y7) (not I8))
       (or (= V8 D2) (not Y7) (not I8))
       (or (= U8 C2) (not Y7) (not I8))
       (or (= T8 (- 1)) (not Y7) (not I8))
       (or (= F9 U8) (not Y7) (not I8))
       (or X (not Y7) (not I8))
       (or (= K1 J7) (not L6) (not V6))
       (or (= J1 I7) (not L6) (not V6))
       (or (= I1 G7) (not L6) (not V6))
       (or (= S7 H7) (not L6) (not V6))
       (or (= J7 0) (not L6) (not V6))
       (or (= I7 H2) (not L6) (not V6))
       (or (= H7 G2) (not L6) (not V6))
       (or (= G7 (- 1)) (not L6) (not V6))
       (or G1 (not L6) (not V6))
       (or (= K1 R7) (not G6) (not X6))
       (or (= J1 Q7) (not G6) (not X6))
       (or (= I1 O7) (not G6) (not X6))
       (or (= O7 H2) (not G6) (not X6))
       (or (= S7 P7) (not G6) (not X6))
       (or (= R7 1) (not G6) (not X6))
       (or (= Q7 H2) (not G6) (not X6))
       (or (= P7 G2) (not G6) (not X6))
       (or X2 (not G6) (not X6))
       (or (not X2) (not G6) (not J6))
       (or (not J5) (not R3) (= T1 D6))
       (or (not J5) (not R3) (= S1 B6))
       (or (not J5) (not R3) (= R1 Z5))
       (or (not J5) (not R3) (= F6 C6))
       (or (not J5) (not R3) (= E6 A6))
       (or (not J5) (not R3) (= D6 1))
       (or (not J5) (not R3) (= C6 N2))
       (or (not J5) (not R3) (= B6 L2))
       (or (not J5) (not R3) (= A6 K2))
       (or (not J5) (not R3) (= Z5 L2))
       (or (not Q1) (not J5) (not R3))
       (or L1 (not F5) (not (= J2 1)))
       (or (not L1) (not F5) (not (= J2 0)))
       (or L1 (not F5) (not M6))
       (or (not L1) (not F5) (not H6))
       (or C1 (not S6) (not (= F2 1)))
       (or (not C1) (not S6) (not (= F2 0)))
       (or (not C1) (not S6) (not U7))
       (or K (not S9) (not V10))
       (or (= S B10) (not T9) (not P9))
       (or (= R A10) (not T9) (not P9))
       (or (= Q Y9) (not T9) (not P9))
       (or (= B10 0) (not T9) (not P9))
       (or (= A10 Z1) (not T9) (not P9))
       (or (not T9) (not P9) (= Y9 (- 1)))
       (or (= S10 Z9) (not T9) (not P9))
       (or (= Z9 R9) (not T9) (not P9))
       (or (= S F10) (not N9) (not U9))
       (or (= R E10) (not N9) (not U9))
       (or (= Q C10) (not N9) (not U9))
       (or (= E10 A2) (not N9) (not U9))
       (or (= D10 Y1) (not N9) (not U9))
       (or (= S10 D10) (not N9) (not U9))
       (or (= F10 0) (not N9) (not U9))
       (or (not N9) (not U9) (= C10 (- 1)))
       (or N (not N9) (not U9))
       (or (not N) (not Q9) (not N9))
       (or (= S J10) (not L9) (not V9))
       (or (= R I10) (not L9) (not V9))
       (or (= Q G10) (not L9) (not V9))
       (or (not L9) (= G10 (- 1)) (not V9))
       (or (= S10 H10) (not L9) (not V9))
       (or (= J10 0) (not L9) (not V9))
       (or (= I10 Z1) (not L9) (not V9))
       (or (= H10 Y1) (not L9) (not V9))
       (or O (not L9) (not V9))
       (or (not O) (not L9) (not O9))
       (or (= S N10) (not I9) (not W9))
       (or (= R M10) (not I9) (not W9))
       (or (= Q K10) (not I9) (not W9))
       (or (= S10 L10) (not I9) (not W9))
       (or (= N10 1) (not I9) (not W9))
       (or (= M10 Z1) (not I9) (not W9))
       (or (= L10 Y1) (not I9) (not W9))
       (or (= K10 K9) (not I9) (not W9))
       (or (not R2) (not J9) (not G9))
       (or (not H8) (not A8) (= B1 S8))
       (or (not H8) (not A8) (= A1 R8))
       (or (not H8) (not A8) (= Z P8))
       (or (not H8) (not A8) (= S8 0))
       (or (not H8) (not A8) (= R8 E2))
       (or (not H8) (not A8) (= Q8 C2))
       (or (not H8) (not A8) (= P8 (- 1)))
       (or (not H8) (not A8) (= F9 Q8))
       (or (not H8) (not A8) W)
       (or T (not F8) (not (= B2 1)))
       (or (not F8) (not T) (not (= B2 0)))
       (or T (not F8) (not M9))
       (or (not T) (not H9) (not F8))
       (or (not B8) (not Y7) (not X))
       (or C1 (not S6) (not Z7))
       (or (not V7) (= B1 A9) (not J8))
       (or (not V7) (= A1 Z8) (not J8))
       (or (not V7) (= Z X8) (not J8))
       (or (not V7) (= A9 1) (not J8))
       (or (not V7) (= Z8 D2) (not J8))
       (or (not V7) (= Y8 C2) (not J8))
       (or (not V7) (= X8 X7) (not J8))
       (or (not V7) (= F9 Y8) (not J8))
       (or (= B1 E9) (not T7) (not K8))
       (or (= A1 D9) (not T7) (not K8))
       (or (= Z B9) (not T7) (not K8))
       (or (= E9 1) (not T7) (not K8))
       (or (= D9 D2) (not T7) (not K8))
       (or (= C9 C2) (not T7) (not K8))
       (or (= B9 D2) (not T7) (not K8))
       (or (= F9 C9) (not T7) (not K8))
       (or U2 (not T7) (not K8))
       (or (not U2) (not T7) (not W7))
       (or (not W6) (not I6) (= K1 N7))
       (or (not W6) (not I6) (= J1 M7))
       (or (not W6) (not I6) (= I1 K7))
       (or (not W6) (not I6) (= S7 L7))
       (or (not W6) (not I6) (= N7 1))
       (or (not W6) (not I6) (= M7 H2))
       (or (not W6) (not I6) (= L7 G2))
       (or (not W6) (not I6) (= K7 K6))
       (or (not T6) (not P6) (= K1 B7))
       (or (not T6) (not P6) (= J1 A7))
       (or (not T6) (not P6) (= I1 Y6))
       (or (not T6) (not P6) (= S7 Z6))
       (or (not T6) (not P6) (= B7 0))
       (or (not T6) (not P6) (= A7 H2))
       (or (not T6) (not P6) (= Z6 R6))
       (or (not T6) (not P6) (= Y6 (- 1)))
       (or (not O6) (not L6) (not G1))
       (or (= K1 F7) (not N6) (not U6))
       (or (= J1 E7) (not N6) (not U6))
       (or (= I1 C7) (not N6) (not U6))
       (or (= S7 D7) (not N6) (not U6))
       (or (= F7 0) (not N6) (not U6))
       (or (= E7 I2) (not N6) (not U6))
       (or (= D7 G2) (not N6) (not U6))
       (or (not N6) (not U6) (= C7 (- 1)))
       (or F1 (not N6) (not U6))
       (or (not F1) (not N6) (not Q6))
       (or (= O5 0) (not B5) (not G5))
       (or (= N5 Y4) (not B5) (not G5))
       (or (= M5 E5) (not B5) (not G5))
       (or (= T1 O5) (not B5) (not G5))
       (or (= S1 M5) (not B5) (not G5))
       (or (= R1 K5) (not B5) (not G5))
       (or (= F6 N5) (not B5) (not G5))
       (or (= E6 L5) (not B5) (not G5))
       (or (= L5 D5) (not B5) (not G5))
       (or (not B5) (not G5) (= K5 (- 1)))
       (or (= T5 0) (not Z4) (not H5))
       (or (= S5 Y4) (not Z4) (not H5))
       (or (= R5 M2) (not Z4) (not H5))
       (or (= Q5 K2) (not Z4) (not H5))
       (or (= P5 (- 1)) (not Z4) (not H5))
       (or (= T1 T5) (not Z4) (not H5))
       (or (= S1 R5) (not Z4) (not H5))
       (or (= R1 P5) (not Z4) (not H5))
       (or (= F6 S5) (not Z4) (not H5))
       (or (= E6 Q5) (not Z4) (not H5))
       (or O1 (not Z4) (not H5))
       (or (not O1) (not Z4) (not C5))
       (or (not X4) Q1 (not R3))
       (or (= U5 (- 1)) (not W4) (not I5))
       (or (= T1 Y5) (not W4) (not I5))
       (or (= S1 W5) (not W4) (not I5))
       (or (= R1 U5) (not W4) (not I5))
       (or (= F6 X5) (not W4) (not I5))
       (or (= E6 V5) (not W4) (not I5))
       (or (= Y5 0) (not W4) (not I5))
       (or (= X5 Y4) (not W4) (not I5))
       (or (= W5 L2) (not W4) (not I5))
       (or (= V5 K2) (not W4) (not I5))
       (or P1 (not W4) (not I5))
       (or (not P1) (not W4) (not A5))
       (or (not X9) (not G9) (= S R10))
       (or (not X9) (not G9) (= R Q10))
       (or (not X9) (not G9) (= Q O10))
       (or (not X9) (not G9) (= S10 P10))
       (or (not X9) (not G9) (= R10 1))
       (or (not X9) (not G9) (= Q10 Z1))
       (or (not X9) (not G9) (= P10 Y1))
       (or (not X9) (not G9) (= O10 Z1))
       (or (not X9) (not G9) R2)
       (or (not W10) (and U10 X10))
       a!1
       (or (not U10) (= D (and A C)))
       (or (not U10) (= B (= T10 1)))
       (or (not U10) (not (= B C)))
       (or (not U10) (and S9 V10))
       (or (not C8) (= U (= E2 S2)))
       (or (not C8) (= E8 (ite U 1 C2)))
       (or (not C8) (and A8 D8))
       a!2
       (or (not A8) (= W (or T2 V)))
       (or (not A8) (and B8 Y7))
       (or (not Y7) (= X (= E2 (- 1))))
       (or (not Y7) (and Z7 S6))
       (or (not P6) (= D1 (= I2 V2)))
       (or (not P6) (= R6 (ite D1 1 G2)))
       (or (not P6) (and N6 Q6))
       (or (not L6) (= G1 (= I2 (- 1))))
       (or (not L6) (and F5 M6))
       (or (not I6) (= H1 (= H2 V2)))
       (or (not I6) (= K6 (ite H1 (- 1) H2)))
       (or (not I6) (and G6 J6))
       (or (not G6) (and F5 H6))
       (or Q1 (not (= O2 1)))
       (or (not Q1) (not (= O2 0)))
       a!3
       (or (not S9) (= J S10))
       (or (not S9) (= I (+ G H)))
       (or (not S9) (= H F9))
       (or (not S9) (= G (+ F E)))
       (or (not S9) (= F S7))
       (or (not S9) (= E E6))
       (or (not S9) (= T10 (+ I J)))
       (or (not P9) (= L (= A2 P2)))
       (or (not P9) (= R9 (ite L 1 Y1)))
       (or (not P9) (and N9 Q9))
       a!4
       (or (not N9) (= N (or Q2 M)))
       (or (not N9) (and L9 O9))
       (or (not L9) (= O (= A2 (- 1))))
       (or (not L9) (and F8 M9))
       (or (not I9) (= P (= Z1 P2)))
       (or (not I9) (= K9 (ite P (- 1) Z1)))
       (or (not I9) (and G9 J9))
       (or (not G9) (and F8 H9))
       (or (not V7) (= Y (= D2 S2)))
       (or (not V7) (= X7 (ite Y (- 1) D2)))
       (or (not V7) (and T7 W7))
       (or (not T7) (and S6 U7))
       a!5
       (or (not N6) (= F1 (or W2 E1)))
       (or (not N6) (and O6 L6))
       (or (not B5) (= M1 (= M2 Y2)))
       (or (not B5) (= E5 (ite M1 L2 M2)))
       (or (not B5) (= D5 (ite M1 1 K2)))
       (or (not B5) (and Z4 C5))
       a!6
       (or (not Z4) (= O1 (or N1 Z2)))
       (or (not Z4) (and W4 A5))
       (or (not W4) (= P1 (= M2 (- 1))))
       (or (not W4) (= Y4 (+ 1 N2)))
       (or (not W4) (and X4 R3))
       (= W10 true)
       (or (and N6 U6) (and L6 V6) (and G6 X6) (not S6) (and W6 I6) (and T6 P6))
       (= 2 v_285)))
      )
      (main_1 v_285
        J4
        K4
        L4
        U1
        M4
        N4
        O4
        V1
        P4
        Q4
        R4
        W1
        S4
        T4
        U4
        V4
        X1
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
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Int) (R Int) (S Int) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Bool) (N2 Bool) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Int) (S2 Bool) (T2 Bool) (U2 Int) (V2 Bool) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Bool) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Int) (S3 Bool) (T3 Bool) (U3 Bool) (V3 Bool) (W3 Int) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Bool) (C4 Bool) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Bool) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Int) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Int) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Bool) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Bool) (N6 Bool) (O6 Bool) (P6 Bool) (Q6 Int) (R6 Bool) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Int) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Bool) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Bool) (A8 Bool) (B8 Bool) (C8 Bool) (D8 Int) (E8 Bool) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Int) (L8 Bool) (M8 Bool) (N8 Bool) (O8 Bool) (P8 Bool) (Q8 Bool) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Bool) (O9 Bool) (P9 Bool) (Q9 Bool) (R9 Bool) (S9 Bool) (v_253 Int) (v_254 Int) ) 
    (=>
      (and
        (main_1 v_253
        U1
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
        M3)
        (let ((a!1 (or (not N9) (not (= (<= Y4 3) A))))
      (a!2 (or (not T6) (not (= (<= A2 O2) V))))
      (a!3 (or (not G5) (not (= (<= E2 R2) E1))))
      (a!4 (or (not L8) (not (= (<= 2 M9) K))))
      (a!5 (or (not G8) (not (= (<= W1 L2) M))))
      (a!6 (or (not S3) (not (= (<= I2 U2) N1)))))
  (and (= 2 v_253)
       (or (and B8 P8) (and I8 M8) (and G8 N8) (and E8 O8) (and Z7 Q8) (not L8))
       (or (and I5 M5) (and G5 N5) (and P5 B5) (not L5) (and Q5 Z4) (and O5 E5))
       (or (and U3 Z3) (and S3 A4) (and P3 B4) (and N3 C4) (not Y3))
       (or (and L8 R9) (not P9) (and Q9 N9))
       (or (not D7) (not M6) (= Y7 V7))
       (or (not D7) (not M6) (= X7 1))
       (or (not D7) (not M6) (= W7 Z1))
       (or (not D7) (not M6) (= V7 Y1))
       (or (not D7) (not M6) (= U7 Z1))
       (or (not D7) (not M6) (= B1 X7))
       (or (not D7) (not M6) (= A1 W7))
       (or (not D7) (not M6) (= Z U7))
       (or Q2 (not D7) (not M6))
       (or T (not Y6) (not (= X1 1)))
       (or (not Y6) (not T) (not (= X1 0)))
       (or (= Y7 F7) (not V6) (not Z6))
       (or (= G7 Z1) (not V6) (not Z6))
       (or (= B1 H7) (not V6) (not Z6))
       (or (= A1 G7) (not V6) (not Z6))
       (or (= Z E7) (not V6) (not Z6))
       (or (= H7 0) (not V6) (not Z6))
       (or (= F7 X6) (not V6) (not Z6))
       (or (not V6) (not Z6) (= E7 (- 1)))
       (or (= Y7 N7) (not B7) (not R6))
       (or (= P7 0) (not B7) (not R6))
       (or (= O7 Z1) (not B7) (not R6))
       (or (= N7 Y1) (not B7) (not R6))
       (or (not B7) (not R6) (= M7 (- 1)))
       (or (= B1 P7) (not B7) (not R6))
       (or (= A1 O7) (not B7) (not R6))
       (or (= Z M7) (not B7) (not R6))
       (or X (not B7) (not R6))
       (or (not Q2) (not P6) (not M6))
       (or (not Q5) (not Z4) (= J1 J6))
       (or (not Q5) (not Z4) (= I1 H6))
       (or (not Q5) (not Z4) (= J6 D2))
       (or (not Q5) (not Z4) (= K1 K6))
       (or (not Q5) (not Z4) (= L6 I6))
       (or (not Q5) (not Z4) (= K6 1))
       (or (not Q5) (not Z4) (= I6 C2))
       (or (not Q5) (not Z4) (= H6 D2))
       (or (= J1 X5) (not N5) (not G5))
       (or (= I1 V5) (not N5) (not G5))
       (or (= K1 Y5) (not N5) (not G5))
       (or (= L6 W5) (not N5) (not G5))
       (or (= Y5 0) (not N5) (not G5))
       (or (= X5 E2) (not N5) (not G5))
       (or (= W5 C2) (not N5) (not G5))
       (or (not N5) (not G5) (= V5 (- 1)))
       (or F1 (not N5) (not G5))
       (or (not G1) (not H5) (not E5))
       (or D (not Q9) (not N9))
       (or K (not L8) (not O9))
       (or (not K) (not L8) (not R9))
       (or (= S U8) (not M8) (not I8))
       (or (= R T8) (not M8) (not I8))
       (or (= Q R8) (not M8) (not I8))
       (or (= T8 V1) (not M8) (not I8))
       (or (= S8 K8) (not M8) (not I8))
       (or (= L9 S8) (not M8) (not I8))
       (or (= U8 0) (not M8) (not I8))
       (or (not M8) (= R8 (- 1)) (not I8))
       (or (= S Y8) (not G8) (not N8))
       (or (= R X8) (not G8) (not N8))
       (or (= Q V8) (not G8) (not N8))
       (or (= Y8 0) (not G8) (not N8))
       (or (= W8 U1) (not G8) (not N8))
       (or (not G8) (not N8) (= V8 (- 1)))
       (or (= L9 W8) (not G8) (not N8))
       (or (= X8 W1) (not G8) (not N8))
       (or N (not G8) (not N8))
       (or (not N) (not G8) (not J8))
       (or (not F8) (not Y6) T)
       (or (= S C9) (not O8) (not E8))
       (or (= R B9) (not O8) (not E8))
       (or (= Q Z8) (not O8) (not E8))
       (or (= B9 V1) (not O8) (not E8))
       (or (not O8) (not E8) (= Z8 (- 1)))
       (or (= L9 A9) (not O8) (not E8))
       (or (= C9 0) (not O8) (not E8))
       (or (= A9 U1) (not O8) (not E8))
       (or O (not O8) (not E8))
       (or (not O) (not E8) (not H8))
       (or (= S G9) (not B8) (not P8))
       (or (= R F9) (not B8) (not P8))
       (or (= Q D9) (not B8) (not P8))
       (or (= L9 E9) (not B8) (not P8))
       (or (= G9 1) (not B8) (not P8))
       (or (= F9 V1) (not B8) (not P8))
       (or (= E9 U1) (not B8) (not P8))
       (or (= D9 D8) (not B8) (not P8))
       (or (not A8) (not Y6) (not T))
       (or (= S K9) (not Z7) (not Q8))
       (or (= R J9) (not Z7) (not Q8))
       (or (= Q H9) (not Z7) (not Q8))
       (or (= L9 I9) (not Z7) (not Q8))
       (or (= K9 1) (not Z7) (not Q8))
       (or (= J9 V1) (not Z7) (not Q8))
       (or (= I9 U1) (not Z7) (not Q8))
       (or (= H9 V1) (not Z7) (not Q8))
       (or N2 (not Z7) (not Q8))
       (or (not N2) (not Z7) (not C8))
       (or (not A7) (not T6) (= Y7 J7))
       (or (not A7) (not T6) (= L7 0))
       (or (not A7) (not T6) (= K7 A2))
       (or (not A7) (not T6) (= J7 Y1))
       (or (not A7) (not T6) (= I7 (- 1)))
       (or (not A7) (not T6) (= B1 L7))
       (or (not A7) (not T6) (= A1 K7))
       (or (not A7) (not T6) (= Z I7))
       (or (not A7) (not T6) W)
       (or (not W6) (not T6) (not W))
       (or (not U6) (not R6) (not X))
       (or (= Y7 R7) (not O6) (not C7))
       (or (= T7 1) (not O6) (not C7))
       (or (= S7 Z1) (not O6) (not C7))
       (or (= R7 Y1) (not O6) (not C7))
       (or (= Q7 Q6) (not O6) (not C7))
       (or (= B1 T7) (not O6) (not C7))
       (or (= A1 S7) (not O6) (not C7))
       (or (= Z Q7) (not O6) (not C7))
       (or (not P5) (not B5) (= J1 F6))
       (or (not P5) (not B5) (= I1 D6))
       (or (not P5) (not B5) (= K1 G6))
       (or (not P5) (not B5) (= L6 E6))
       (or (not P5) (not B5) (= G6 1))
       (or (not P5) (not B5) (= F6 D2))
       (or (not P5) (not B5) (= E6 C2))
       (or (not P5) (not B5) (= D6 D5))
       (or (not O5) (not E5) (= J1 B6))
       (or (not O5) (not E5) (= I1 Z5))
       (or (not O5) (not E5) (= K1 C6))
       (or (not O5) (not E5) (= L6 A6))
       (or (not O5) (not E5) (= C6 0))
       (or (not O5) (not E5) (= B6 D2))
       (or (not O5) (not E5) (= A6 C2))
       (or (not O5) (not E5) (= Z5 (- 1)))
       (or (not O5) (not E5) G1)
       (or C1 (not L5) (not (= B2 1)))
       (or (not L5) (not C1) (not (= B2 0)))
       (or C1 (not L5) (not S6))
       (or (not C1) (not L5) (not N6))
       (or (not J5) (not G5) (not F1))
       (or (= J1 T5) (not I5) (not M5))
       (or (= I1 R5) (not I5) (not M5))
       (or (not I5) (not M5) (= R5 (- 1)))
       (or (= K1 U5) (not I5) (not M5))
       (or (= L6 S5) (not I5) (not M5))
       (or (= U5 0) (not I5) (not M5))
       (or (= T5 D2) (not I5) (not M5))
       (or (= S5 K5) (not I5) (not M5))
       (or L1 (not Y3) (not (= F2 1)))
       (or (not Y3) (not L1) (not (= F2 0)))
       (or L1 (not F5) (not Y3))
       (or (not L1) (not A5) (not Y3))
       (or (not Z3) (= R1 D4) (not U3))
       (or (not Z3) (= H4 0) (not U3))
       (or (not Z3) (= T1 H4) (not U3))
       (or (not Z3) (= S1 F4) (not U3))
       (or (not Z3) (= Y4 G4) (not U3))
       (or (not Z3) (= X4 E4) (not U3))
       (or (not Z3) (= G4 R3) (not U3))
       (or (not Z3) (= F4 X3) (not U3))
       (or (not Z3) (= E4 W3) (not U3))
       (or (not Z3) (not U3) (= D4 (- 1)))
       (or (not S3) (= R1 I4) (not A4))
       (or (not S3) (= M4 0) (not A4))
       (or (not S3) (= L4 R3) (not A4))
       (or (not S3) (= K4 I2) (not A4))
       (or (not S3) (= J4 G2) (not A4))
       (or (not S3) (not A4) (= I4 (- 1)))
       (or (not S3) (= T1 M4) (not A4))
       (or (not S3) (= S1 K4) (not A4))
       (or (not S3) (= Y4 L4) (not A4))
       (or (not S3) (= X4 J4) (not A4))
       (or (not S3) O1 (not A4))
       (or (not S3) (not O1) (not V3))
       (or (= R1 N4) (not B4) (not P3))
       (or (= P4 H2) (not B4) (not P3))
       (or (= O4 G2) (not B4) (not P3))
       (or (not B4) (not P3) (= N4 (- 1)))
       (or (= T1 R4) (not B4) (not P3))
       (or (= S1 P4) (not B4) (not P3))
       (or (= Y4 Q4) (not B4) (not P3))
       (or (= X4 O4) (not B4) (not P3))
       (or (= R4 0) (not B4) (not P3))
       (or (= Q4 R3) (not B4) (not P3))
       (or P1 (not B4) (not P3))
       (or (not P1) (not P3) (not T3))
       (or (= R1 S4) (not C4) (not N3))
       (or (= T1 W4) (not C4) (not N3))
       (or (= S1 U4) (not C4) (not N3))
       (or (= Y4 V4) (not C4) (not N3))
       (or (= X4 T4) (not C4) (not N3))
       (or (= W4 1) (not C4) (not N3))
       (or (= V4 J2) (not C4) (not N3))
       (or (= U4 H2) (not C4) (not N3))
       (or (= T4 G2) (not C4) (not N3))
       (or (= S4 H2) (not C4) (not N3))
       (or (not Q1) (not C4) (not N3))
       (or Q1 (not N3) (not Q3))
       (or T2 (not Q5) (not Z4))
       (or (not T2) (not C5) (not Z4))
       a!1
       (or (not N9) (= B (= M9 1)))
       (or (not N9) (not (= B C)))
       (or (not N9) (= D (and C A)))
       (or (not N9) (and L8 O9))
       (or (not M6) (and L5 N6))
       (or (not Z4) (and Y3 A5))
       (or Q1 (not (= K2 1)))
       (or (not Q1) (not (= K2 0)))
       (or (not V6) (= U (= A2 O2)))
       (or (not V6) (= X6 (ite U 1 Y1)))
       (or (not V6) (and W6 T6))
       a!2
       (or (not T6) (= W (or P2 V)))
       (or (not T6) (and U6 R6))
       (or (not R6) (= X (= A2 (- 1))))
       (or (not R6) (and L5 S6))
       a!3
       (or (not G5) (= F1 (or S2 E1)))
       (or (not G5) (and E5 H5))
       (or (not E5) (= G1 (= E2 (- 1))))
       (or (not E5) (and Y3 F5))
       (or (not B5) (= H1 (= D2 R2)))
       (or (not B5) (= D5 (ite H1 (- 1) D2)))
       (or (not B5) (and C5 Z4))
       a!4
       (or (not L8) (= H Y7))
       (or (not L8) (= G (+ F E)))
       (or (not L8) (= F L6))
       (or (not L8) (= E X4))
       (or (not L8) (= J L9))
       (or (not L8) (= I (+ G H)))
       (or (not L8) (= M9 (+ I J)))
       (or (not I8) (= L (= W1 L2)))
       (or (not I8) (= K8 (ite L 1 U1)))
       (or (not I8) (and G8 J8))
       a!5
       (or (not G8) (= N (or M2 M)))
       (or (not G8) (and E8 H8))
       (or (not E8) (= O (= W1 (- 1))))
       (or (not E8) (and F8 Y6))
       (or (not B8) (= P (= V1 L2)))
       (or (not B8) (= D8 (ite P (- 1) V1)))
       (or (not B8) (and Z7 C8))
       (or (not Z7) (and A8 Y6))
       (or (not O6) (= Y (= Z1 O2)))
       (or (not O6) (= Q6 (ite Y (- 1) Z1)))
       (or (not O6) (and P6 M6))
       (or (not I5) (= D1 (= E2 R2)))
       (or (not I5) (= K5 (ite D1 1 C2)))
       (or (not I5) (and J5 G5))
       (or (not U3) (= M1 (= I2 U2)))
       (or (not U3) (= X3 (ite M1 H2 I2)))
       (or (not U3) (= W3 (ite M1 1 G2)))
       (or (not U3) (and S3 V3))
       a!6
       (or (not S3) (= O1 (or V2 N1)))
       (or (not S3) (and P3 T3))
       (or (not P3) (= P1 (= I2 (- 1))))
       (or (not P3) (= R3 (+ 1 J2)))
       (or (not P3) (and N3 Q3))
       (or (not O3) (and P9 S9))
       (= O3 true)
       (or (and O6 C7) (and V6 Z6) (and R6 B7) (not Y6) (and D7 M6) (and A7 T6))
       (= 3 v_254)))
      )
      (main_1 v_254
        U1
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
        M3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Bool) (T Bool) (U Int) (V Bool) (W Bool) (X Int) (Y Bool) (Z Bool) (A1 Int) (B1 Bool) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (v_45 Int) ) 
    (=>
      (and
        (main_1 v_45
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
        S1)
        (= 3 v_45)
      )
      false
    )
  )
)

(check-sat)
(exit)
