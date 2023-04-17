; ./seahorn/./sv_comp_flat_small/seq-mthreaded/pals_lcr-var-start-time.5_true-unreach-call.ufo.UNBOUNDED.pals.c.flat_000.smt2
(set-logic HORN)

(declare-fun |main_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool Int Bool Bool Int Bool Bool Int Bool Bool Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) (X Bool) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Bool) (D1 Bool) (E1 Int) (F1 Bool) (G1 Bool) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (v_56 Int) ) 
    (=>
      (and
        (and true (= 0 v_56))
      )
      (main_1 v_56
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
        U1
        V1
        W1
        X1
        Y1
        Z1
        A2
        B2
        C2
        D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Bool) (L2 Bool) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Bool) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Bool) (Q3 Bool) (R3 Int) (S3 Bool) (T3 Bool) (U3 Int) (V3 Bool) (W3 Bool) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Int) (B4 Bool) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Bool) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Bool) (D5 Int) (E5 Bool) (F5 Int) (G5 Int) (H5 Int) (I5 Bool) (J5 Int) (K5 Bool) (L5 Int) (M5 Int) (N5 Int) (O5 Bool) (P5 Int) (Q5 Bool) (R5 Int) (S5 Int) (T5 Int) (U5 Bool) (V5 Int) (W5 Bool) (X5 Int) (Y5 Int) (Z5 Int) (A6 Bool) (B6 Int) (C6 Bool) (D6 Bool) (E6 Bool) (F6 Bool) (G6 Bool) (H6 Bool) (I6 Bool) (J6 Bool) (K6 Bool) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Bool) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Bool) (I7 Bool) (J7 Bool) (K7 Bool) (L7 Bool) (M7 Bool) (N7 Bool) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (v_233 Int) (v_234 Int) ) 
    (=>
      (and
        (main_1 v_233
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4
        J4
        K4
        L4
        M4
        N4
        O4
        P4
        Q4
        R4
        S4
        T4
        U4
        V4
        W4)
        (let ((a!1 (or (not N6) (not (= (= R5 X5) X))))
      (a!2 (or (not L6) (not (= (<= X5 (- 1)) A1))))
      (a!3 (or (not J6) (not (= (<= R5 (- 1)) H1))))
      (a!4 (or (not H6) (not (= (<= L5 (- 1)) O1))))
      (a!5 (or (not F6) (not (= (<= F5 (- 1)) V1))))
      (a!6 (or (not D6) (not (= (<= Z4 (- 1)) L2))))
      (a!7 (or (not D6) (not (= (<= J2 0) K2)))))
  (and (= 0 v_233)
       (= B6 (ite A6 1 0))
       (= V5 (ite U5 1 0))
       (= P5 (ite O5 1 0))
       (= J5 (ite I5 1 0))
       (= D5 (ite C5 1 0))
       (or (and N6 R6)
           (and L6 S6)
           (and J6 T6)
           (and H6 U6)
           (and F6 V6)
           (and D6 W6)
           (and X4 X6)
           (not Q6))
       (or (= D8 J5) (not N7) (not K7))
       (or (= B8 H5) (not N7) (not K7))
       (or (= A8 G5) (not N7) (not K7))
       (or (not N7) (not K7) (= Y7 (- 1)))
       (or (= X7 N5) (not N7) (not K7))
       (or (= V7 V5) (not N7) (not K7))
       (or (not N7) (not K7) (= U7 (- 1)))
       (or (= S7 S5) (not N7) (not K7))
       (or (= R7 B6) (not N7) (not K7))
       (or (= E I8) (not N7) (not K7))
       (or (= D D8) (not N7) (not K7))
       (or (= C Z7) (not N7) (not K7))
       (or (= B V7) (not N7) (not K7))
       (or (= A R7) (not N7) (not K7))
       (or (= Y8 H8) (not N7) (not K7))
       (or (= X8 G8) (not N7) (not K7))
       (or (= W8 F8) (not N7) (not K7))
       (or (= V8 E8) (not N7) (not K7))
       (or (= U8 C8) (not N7) (not K7))
       (or (= T8 B8) (not N7) (not K7))
       (or (= S8 A8) (not N7) (not K7))
       (or (= R8 Y7) (not N7) (not K7))
       (or (= Q8 X7) (not N7) (not K7))
       (or (= P8 W7) (not N7) (not K7))
       (or (= O8 U7) (not N7) (not K7))
       (or (= N8 T7) (not N7) (not K7))
       (or (= M8 S7) (not N7) (not K7))
       (or (= L8 Q7) (not N7) (not K7))
       (or (= K8 P7) (not N7) (not K7))
       (or (= J8 O7) (not N7) (not K7))
       (or (= I8 D5) (not N7) (not K7))
       (or (= H8 Y4) (not N7) (not K7))
       (or (not N7) (not K7) (= G8 (- 1)))
       (or (= F8 B5) (not N7) (not K7))
       (or (= E8 A5) (not N7) (not K7))
       (or (not N7) (not K7) (= C8 (- 1)))
       (or (= Z7 P5) (not N7) (not K7))
       (or (= W7 M5) (not N7) (not K7))
       (or (= T7 T5) (not N7) (not K7))
       (or (not N7) (not K7) (= Q7 (- 1)))
       (or (= P7 Z5) (not N7) (not K7))
       (or (= O7 Y5) (not N7) (not K7))
       (or (= Y6 P6) (not N6) (not R6))
       (or (= S2 Y6) (not N6) (not R6))
       (or (= S2 Z6) (not L6) (not S6))
       (or (not L6) (not Z6) (not S6))
       (or (= S2 A7) (not J6) (not T6))
       (or (not J6) (not A7) (not T6))
       (or (= S2 B7) (not H6) (not U6))
       (or (not H6) (not B7) (not U6))
       (or (= S2 C7) (not F6) (not V6))
       (or (not F6) (not C7) (not V6))
       (or (= S2 D7) (not W6) (not D6))
       (or (not W6) (not D6) (not D7))
       (or (not E5) (not L7) (not Q6))
       (or (= S2 E7) (not X6) (not X4))
       (or (not X6) (not X4) (not E7))
       (or (not R2) (not X6) (not X4))
       (or R2 (not E6) (not X4))
       (or (not Q2) (not W6) (not D6))
       (or Q2 (not D6) (not G6))
       (or (not A2) (not F6) (not V6))
       (or A2 (not F6) (not I6))
       (or (not T1) (not H6) (not U6))
       (or T1 (not H6) (not K6))
       (or (not M1) (not J6) (not T6))
       (or M1 (not J6) (not M6))
       (or (not F1) (not L6) (not S6))
       (or F1 (not L6) (not O6))
       (or (not M7) (and K7 N7))
       (or (not K7) (and Q6 L7))
       (or (not Q6) (not (= C6 J7)))
       (or (not Q6) (not (= W5 I7)))
       (or (not Q6) (not (= Q5 H7)))
       (or (not Q6) (not (= K5 G7)))
       (or (not Q6) (not (= E5 F7)))
       a!1
       (or (not N6) (= P6 (and X Y)))
       (or (not N6) (= W (or U V)))
       (or (not N6) (not (= W Y)))
       (or (not N6) (= V (= L5 X5)))
       (or (not N6) (= U (or S T)))
       (or (not N6) (= T (= L5 R5)))
       (or (not N6) (= S (or Q R)))
       (or (not N6) (= R (= F5 X5)))
       (or (not N6) (= Q (or O P)))
       (or (not N6) (= P (= F5 R5)))
       (or (not N6) (= O (or M N)))
       (or (not N6) (= N (= F5 L5)))
       (or (not N6) (= M (or K L)))
       (or (not N6) (= L (= Z4 X5)))
       (or (not N6) (= K (or I J)))
       (or (not N6) (= J (= Z4 R5)))
       (or (not N6) (= I (or G H)))
       (or (not N6) (= H (= Z4 L5)))
       (or (not N6) (= G (or F A6)))
       (or (not N6) (= F (= Z4 F5)))
       (or (not N6) (and L6 O6))
       a!2
       (or (not L6) (not (= U5 Z)))
       (or (not L6) (= F1 (and D1 E1)))
       (or (not L6) (= E1 (= Z5 X5)))
       (or (not L6) (= D1 (and B1 C1)))
       (or (not L6) (= C1 (= Y5 0)))
       (or (not L6) (= B1 (and Z A1)))
       (or (not L6) (and J6 M6))
       a!3
       (or (not J6) (not (= O5 G1)))
       (or (not J6) (= M1 (and K1 L1)))
       (or (not J6) (= L1 (= T5 R5)))
       (or (not J6) (= K1 (and I1 J1)))
       (or (not J6) (= J1 (= S5 0)))
       (or (not J6) (= I1 (and G1 H1)))
       (or (not J6) (and H6 K6))
       a!4
       (or (not H6) (not (= I5 N1)))
       (or (not H6) (= T1 (and R1 S1)))
       (or (not H6) (= S1 (= N5 L5)))
       (or (not H6) (= R1 (and P1 Q1)))
       (or (not H6) (= Q1 (= M5 0)))
       (or (not H6) (= P1 (and N1 O1)))
       (or (not H6) (and F6 I6))
       a!5
       (or (not F6) (not (= C5 U1)))
       (or (not F6) (= A2 (and Y1 Z1)))
       (or (not F6) (= Z1 (= H5 F5)))
       (or (not F6) (= Y1 (and W1 X1)))
       (or (not F6) (= X1 (= G5 0)))
       (or (not F6) (= W1 (and U1 V1)))
       (or (not F6) (and D6 G6))
       a!6
       a!7
       (or (not D6) (= Q2 (and O2 P2)))
       (or (not D6) (= P2 (= B5 Z4)))
       (or (not D6) (= O2 (and M2 N2)))
       (or (not D6) (= N2 (= A5 0)))
       (or (not D6) (= M2 (and K2 L2)))
       (or (not D6) (= J2 (+ H2 I2)))
       (or (not D6) (= I2 (ite C6 1 0)))
       (or (not D6) (= H2 (+ F2 G2)))
       (or (not D6) (= G2 (ite W5 1 0)))
       (or (not D6) (= F2 (+ D2 E2)))
       (or (not D6) (= E2 (ite Q5 1 0)))
       (or (not D6) (= D2 (+ C2 B2)))
       (or (not D6) (= C2 (ite K5 1 0)))
       (or (not D6) (= B2 (ite E5 1 0)))
       (or (not D6) (and X4 E6))
       (or S2 (not Q6))
       (= M7 true)
       (= R2 (= Y4 0))
       (= 1 v_234)))
      )
      (main_1 v_234
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
        X5
        J7
        C6
        R5
        I7
        W5
        L5
        H7
        Q5
        F5
        G7
        K5
        Z4
        F7
        J8
        K8
        L8
        A
        M8
        N8
        O8
        B
        P8
        Q8
        R8
        C
        S8
        T8
        U8
        D
        V8
        W8
        X8
        Y8
        E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Bool) (L2 Bool) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Bool) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Bool) (Q3 Bool) (R3 Int) (S3 Bool) (T3 Bool) (U3 Int) (V3 Bool) (W3 Bool) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Int) (B4 Bool) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Bool) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Bool) (D5 Int) (E5 Bool) (F5 Int) (G5 Int) (H5 Int) (I5 Bool) (J5 Int) (K5 Bool) (L5 Int) (M5 Int) (N5 Int) (O5 Bool) (P5 Int) (Q5 Bool) (R5 Int) (S5 Int) (T5 Int) (U5 Bool) (V5 Int) (W5 Bool) (X5 Int) (Y5 Int) (Z5 Int) (A6 Bool) (B6 Int) (C6 Bool) (D6 Bool) (E6 Bool) (F6 Bool) (G6 Bool) (H6 Bool) (I6 Bool) (J6 Bool) (K6 Bool) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Bool) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Bool) (W6 Bool) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Bool) (I7 Bool) (J7 Bool) (K7 Bool) (L7 Bool) (M7 Bool) (N7 Bool) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (v_233 Int) (v_234 Int) ) 
    (=>
      (and
        (main_1 v_233
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4
        J4
        K4
        L4
        M4
        N4
        O4
        P4
        Q4
        R4
        S4
        T4
        U4
        V4
        W4)
        (let ((a!1 (or (not N6) (not (= (= R5 X5) X))))
      (a!2 (or (not L6) (not (= (<= X5 (- 1)) A1))))
      (a!3 (or (not J6) (not (= (<= R5 (- 1)) H1))))
      (a!4 (or (not H6) (not (= (<= L5 (- 1)) O1))))
      (a!5 (or (not F6) (not (= (<= F5 (- 1)) V1))))
      (a!6 (or (not D6) (not (= (<= Z4 (- 1)) L2))))
      (a!7 (or (not D6) (not (= (<= J2 0) K2)))))
  (and (= 0 v_233)
       (= B6 (ite A6 1 0))
       (= V5 (ite U5 1 0))
       (= P5 (ite O5 1 0))
       (= J5 (ite I5 1 0))
       (= D5 (ite C5 1 0))
       (or (and N6 R6)
           (and L6 S6)
           (and J6 T6)
           (and H6 U6)
           (and F6 V6)
           (and D6 W6)
           (and X4 X6)
           (not Q6))
       (or (= D8 J5) (not N7) (not K7))
       (or (= B8 H5) (not N7) (not K7))
       (or (= A8 G5) (not N7) (not K7))
       (or (not N7) (not K7) (= Y7 (- 1)))
       (or (= X7 N5) (not N7) (not K7))
       (or (= V7 V5) (not N7) (not K7))
       (or (not N7) (not K7) (= U7 (- 1)))
       (or (= S7 S5) (not N7) (not K7))
       (or (= R7 B6) (not N7) (not K7))
       (or (= E I8) (not N7) (not K7))
       (or (= D D8) (not N7) (not K7))
       (or (= C Z7) (not N7) (not K7))
       (or (= B V7) (not N7) (not K7))
       (or (= A R7) (not N7) (not K7))
       (or (= Y8 H8) (not N7) (not K7))
       (or (= X8 G8) (not N7) (not K7))
       (or (= W8 F8) (not N7) (not K7))
       (or (= V8 E8) (not N7) (not K7))
       (or (= U8 C8) (not N7) (not K7))
       (or (= T8 B8) (not N7) (not K7))
       (or (= S8 A8) (not N7) (not K7))
       (or (= R8 Y7) (not N7) (not K7))
       (or (= Q8 X7) (not N7) (not K7))
       (or (= P8 W7) (not N7) (not K7))
       (or (= O8 U7) (not N7) (not K7))
       (or (= N8 T7) (not N7) (not K7))
       (or (= M8 S7) (not N7) (not K7))
       (or (= L8 Q7) (not N7) (not K7))
       (or (= K8 P7) (not N7) (not K7))
       (or (= J8 O7) (not N7) (not K7))
       (or (= I8 D5) (not N7) (not K7))
       (or (= H8 Y4) (not N7) (not K7))
       (or (not N7) (not K7) (= G8 (- 1)))
       (or (= F8 B5) (not N7) (not K7))
       (or (= E8 A5) (not N7) (not K7))
       (or (not N7) (not K7) (= C8 (- 1)))
       (or (= Z7 P5) (not N7) (not K7))
       (or (= W7 M5) (not N7) (not K7))
       (or (= T7 T5) (not N7) (not K7))
       (or (not N7) (not K7) (= Q7 (- 1)))
       (or (= P7 Z5) (not N7) (not K7))
       (or (= O7 Y5) (not N7) (not K7))
       (or (= Y6 P6) (not N6) (not R6))
       (or (= S2 Y6) (not N6) (not R6))
       (or (= S2 Z6) (not L6) (not S6))
       (or (not L6) (not Z6) (not S6))
       (or (= S2 A7) (not J6) (not T6))
       (or (not J6) (not A7) (not T6))
       (or (= S2 B7) (not H6) (not U6))
       (or (not H6) (not B7) (not U6))
       (or (= S2 C7) (not F6) (not V6))
       (or (not F6) (not C7) (not V6))
       (or (= S2 D7) (not W6) (not D6))
       (or (not W6) (not D6) (not D7))
       (or E5 (not L7) (not Q6))
       (or (= S2 E7) (not X6) (not X4))
       (or (not X6) (not X4) (not E7))
       (or (not R2) (not X6) (not X4))
       (or R2 (not E6) (not X4))
       (or (not Q2) (not W6) (not D6))
       (or Q2 (not D6) (not G6))
       (or (not A2) (not F6) (not V6))
       (or A2 (not F6) (not I6))
       (or (not T1) (not H6) (not U6))
       (or T1 (not H6) (not K6))
       (or (not M1) (not J6) (not T6))
       (or M1 (not J6) (not M6))
       (or (not F1) (not L6) (not S6))
       (or F1 (not L6) (not O6))
       (or (not M7) (and K7 N7))
       (or (not K7) (and Q6 L7))
       (or (not Q6) (not (= C6 J7)))
       (or (not Q6) (not (= W5 I7)))
       (or (not Q6) (not (= Q5 H7)))
       (or (not Q6) (not (= K5 G7)))
       (or (not Q6) (not (= E5 F7)))
       a!1
       (or (not N6) (= P6 (and X Y)))
       (or (not N6) (= W (or U V)))
       (or (not N6) (not (= W Y)))
       (or (not N6) (= V (= L5 X5)))
       (or (not N6) (= U (or S T)))
       (or (not N6) (= T (= L5 R5)))
       (or (not N6) (= S (or Q R)))
       (or (not N6) (= R (= F5 X5)))
       (or (not N6) (= Q (or O P)))
       (or (not N6) (= P (= F5 R5)))
       (or (not N6) (= O (or M N)))
       (or (not N6) (= N (= F5 L5)))
       (or (not N6) (= M (or K L)))
       (or (not N6) (= L (= Z4 X5)))
       (or (not N6) (= K (or I J)))
       (or (not N6) (= J (= Z4 R5)))
       (or (not N6) (= I (or G H)))
       (or (not N6) (= H (= Z4 L5)))
       (or (not N6) (= G (or F A6)))
       (or (not N6) (= F (= Z4 F5)))
       (or (not N6) (and L6 O6))
       a!2
       (or (not L6) (not (= U5 Z)))
       (or (not L6) (= F1 (and D1 E1)))
       (or (not L6) (= E1 (= Z5 X5)))
       (or (not L6) (= D1 (and B1 C1)))
       (or (not L6) (= C1 (= Y5 0)))
       (or (not L6) (= B1 (and Z A1)))
       (or (not L6) (and J6 M6))
       a!3
       (or (not J6) (not (= O5 G1)))
       (or (not J6) (= M1 (and K1 L1)))
       (or (not J6) (= L1 (= T5 R5)))
       (or (not J6) (= K1 (and I1 J1)))
       (or (not J6) (= J1 (= S5 0)))
       (or (not J6) (= I1 (and G1 H1)))
       (or (not J6) (and H6 K6))
       a!4
       (or (not H6) (not (= I5 N1)))
       (or (not H6) (= T1 (and R1 S1)))
       (or (not H6) (= S1 (= N5 L5)))
       (or (not H6) (= R1 (and P1 Q1)))
       (or (not H6) (= Q1 (= M5 0)))
       (or (not H6) (= P1 (and N1 O1)))
       (or (not H6) (and F6 I6))
       a!5
       (or (not F6) (not (= C5 U1)))
       (or (not F6) (= A2 (and Y1 Z1)))
       (or (not F6) (= Z1 (= H5 F5)))
       (or (not F6) (= Y1 (and W1 X1)))
       (or (not F6) (= X1 (= G5 0)))
       (or (not F6) (= W1 (and U1 V1)))
       (or (not F6) (and D6 G6))
       a!6
       a!7
       (or (not D6) (= Q2 (and O2 P2)))
       (or (not D6) (= P2 (= B5 Z4)))
       (or (not D6) (= O2 (and M2 N2)))
       (or (not D6) (= N2 (= A5 0)))
       (or (not D6) (= M2 (and K2 L2)))
       (or (not D6) (= J2 (+ H2 I2)))
       (or (not D6) (= I2 (ite C6 1 0)))
       (or (not D6) (= H2 (+ F2 G2)))
       (or (not D6) (= G2 (ite W5 1 0)))
       (or (not D6) (= F2 (+ D2 E2)))
       (or (not D6) (= E2 (ite Q5 1 0)))
       (or (not D6) (= D2 (+ C2 B2)))
       (or (not D6) (= C2 (ite K5 1 0)))
       (or (not D6) (= B2 (ite E5 1 0)))
       (or (not D6) (and X4 E6))
       (or S2 (not Q6))
       (= M7 true)
       (= R2 (= Y4 0))
       (= 2 v_234)))
      )
      (main_1 v_234
        J8
        K8
        L8
        A
        M8
        N8
        O8
        B
        P8
        Q8
        R8
        C
        S8
        T8
        U8
        D
        V8
        W8
        X8
        Y8
        E
        X5
        J7
        C6
        R5
        I7
        W5
        L5
        H7
        Q5
        F5
        G7
        K5
        Z4
        F7
        C4
        D4
        E4
        F4
        G4
        H4
        I4
        J4
        K4
        L4
        M4
        N4
        O4
        P4
        Q4
        R4
        S4
        T4
        U4
        V4
        W4)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Int) (T Int) (U Int) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Int) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Bool) (I3 Bool) (J3 Int) (K3 Bool) (L3 Bool) (M3 Int) (N3 Bool) (O3 Bool) (P3 Int) (Q3 Bool) (R3 Bool) (S3 Int) (T3 Bool) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Bool) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Int) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Bool) (C6 Bool) (D6 Int) (E6 Bool) (F6 Bool) (G6 Int) (H6 Bool) (I6 Bool) (J6 Bool) (K6 Bool) (L6 Int) (M6 Bool) (N6 Bool) (O6 Bool) (P6 Bool) (Q6 Bool) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Bool) (O7 Bool) (P7 Bool) (Q7 Bool) (R7 Int) (S7 Bool) (T7 Bool) (U7 Bool) (V7 Bool) (W7 Bool) (X7 Bool) (Y7 Int) (Z7 Bool) (A8 Bool) (B8 Bool) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Bool) (B9 Bool) (C9 Bool) (D9 Bool) (E9 Int) (F9 Bool) (G9 Bool) (H9 Bool) (I9 Bool) (J9 Bool) (K9 Bool) (L9 Int) (M9 Bool) (N9 Bool) (O9 Bool) (P9 Bool) (Q9 Bool) (R9 Bool) (S9 Int) (T9 Int) (U9 Int) (V9 Int) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Bool) (O10 Bool) (P10 Bool) (Q10 Bool) (R10 Int) (S10 Bool) (T10 Bool) (U10 Bool) (V10 Bool) (W10 Bool) (X10 Bool) (Y10 Int) (Z10 Bool) (A11 Bool) (B11 Bool) (C11 Bool) (D11 Bool) (E11 Bool) (F11 Int) (G11 Int) (H11 Int) (I11 Int) (J11 Int) (K11 Int) (L11 Int) (M11 Int) (N11 Int) (O11 Int) (P11 Int) (Q11 Int) (R11 Int) (S11 Int) (T11 Int) (U11 Int) (V11 Int) (W11 Int) (X11 Int) (Y11 Int) (Z11 Int) (A12 Bool) (B12 Bool) (C12 Bool) (D12 Bool) (E12 Int) (F12 Bool) (G12 Bool) (H12 Bool) (I12 Bool) (J12 Bool) (K12 Bool) (L12 Int) (M12 Bool) (N12 Bool) (O12 Bool) (P12 Bool) (Q12 Bool) (R12 Bool) (S12 Int) (T12 Int) (U12 Int) (V12 Int) (W12 Int) (X12 Int) (Y12 Int) (Z12 Int) (A13 Int) (B13 Int) (C13 Int) (D13 Int) (E13 Int) (F13 Int) (G13 Int) (H13 Int) (I13 Int) (J13 Int) (K13 Int) (L13 Int) (M13 Int) (N13 Int) (O13 Bool) (P13 Bool) (Q13 Bool) (R13 Bool) (v_356 Int) (v_357 Int) ) 
    (=>
      (and
        (main_1 v_356
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4
        J4
        K4
        L4
        M4
        N4
        O4)
        (let ((a!1 (or (not O13) (not (= (<= M7 4) A))))
      (a!2 (or (not M12) (not (= (<= 2 N13) M))))
      (a!3 (or (not H12) (not (= (<= W3 G3) O))))
      (a!4 (or (not U10) (not (= (<= A4 J3) X))))
      (a!5 (or (not H9) (not (= (<= E4 M3) G1))))
      (a!6 (or (not U7) (not (= (<= I4 P3) P1))))
      (a!7 (or (not H6) (not (= (<= M4 S3) Y1)))))
  (and (= 1 v_356)
       (or (and C9 N9) (and A9 O9) (and J9 P9) (and F9 R9) (not M9) (and Q9 H9))
       (or (and P7 A8) (and N7 B8) (and W7 C8) (and U7 D8) (and S7 E8) (not Z7))
       (or (and P10 A11)
           (and N10 B11)
           (and W10 C11)
           (not Z10)
           (and E11 S10)
           (and D11 U10))
       (or (not M6) (and B6 N6) (and J6 O6) (and H6 P6) (and E6 Q6))
       (or (= A6 J5) (not O13) (not R13))
       (or (= Z5 I5) (not O13) (not R13))
       (or (= Y5 H5) (not O13) (not R13))
       (or (= X5 G5) (not O13) (not R13))
       (or (= W5 E5) (not O13) (not R13))
       (or (= V5 D5) (not O13) (not R13))
       (or (= U5 C5) (not O13) (not R13))
       (or (= T5 A5) (not O13) (not R13))
       (or (= S5 Z4) (not O13) (not R13))
       (or (= R5 Y4) (not O13) (not R13))
       (or (= Q5 W4) (not O13) (not R13))
       (or (= P5 V4) (not O13) (not R13))
       (or (= O5 U4) (not O13) (not R13))
       (or (= N5 S4) (not O13) (not R13))
       (or (= M5 R4) (not O13) (not R13))
       (or (= L5 Q4) (not O13) (not R13))
       (or (= K5 E2) (not O13) (not R13))
       (or (= J5 M7) (not O13) (not R13))
       (or (= I5 S) (not O13) (not R13))
       (or (= H5 D2) (not O13) (not R13))
       (or (= G5 L7) (not O13) (not R13))
       (or (= F5 V1) (not O13) (not R13))
       (or (= E5 C2) (not O13) (not R13))
       (or (= D5 U1) (not O13) (not R13))
       (or (= C5 Z8) (not O13) (not R13))
       (or (= B5 M1) (not O13) (not R13))
       (or (= A5 T1) (not O13) (not R13))
       (or (= Z4 L1) (not O13) (not R13))
       (or (= Y4 M10) (not O13) (not R13))
       (or (= S4 B1) (not O13) (not R13))
       (or (= R4 T) (not O13) (not R13))
       (or (= Q4 M13) (not O13) (not R13))
       (or (= K2 K5) (not O13) (not R13))
       (or (= J2 F5) (not O13) (not R13))
       (or (= I2 B5) (not O13) (not R13))
       (or (= H2 X4) (not O13) (not R13))
       (or (= G2 T4) (not O13) (not R13))
       (or (= X4 D1) (not O13) (not R13))
       (or (= W4 K1) (not O13) (not R13))
       (or (= V4 C1) (not O13) (not R13))
       (or (= U4 Z11) (not O13) (not R13))
       (or (= T4 U) (not O13) (not R13))
       (or (= U D13) (not J12) (not P12))
       (or (= T C13) (not J12) (not P12))
       (or (= S A13) (not J12) (not P12))
       (or (= M13 B13) (not J12) (not P12))
       (or (= D13 0) (not J12) (not P12))
       (or (= C13 V3) (not J12) (not P12))
       (or (= B13 L12) (not J12) (not P12))
       (or (= A13 (- 1)) (not J12) (not P12))
       (or (= D10 0) (not J9) (not P9))
       (or (= B10 L9) (not J9) (not P9))
       (or (= M1 D10) (not J9) (not P9))
       (or (= L1 C10) (not J9) (not P9))
       (or (= K1 A10) (not J9) (not P9))
       (or (= M10 B10) (not J9) (not P9))
       (or (= C10 D4) (not J9) (not P9))
       (or (= A10 (- 1)) (not J9) (not P9))
       (or (= J10 C4) (not F9) (not R9))
       (or (= M1 L10) (not F9) (not R9))
       (or (= L1 K10) (not F9) (not R9))
       (or (= K1 I10) (not F9) (not R9))
       (or (= M10 J10) (not F9) (not R9))
       (or (= L10 0) (not F9) (not R9))
       (or (= K10 D4) (not F9) (not R9))
       (or (= I10 (- 1)) (not F9) (not R9))
       (or (= V9 1) (not C9) (not N9))
       (or (= M1 V9) (not C9) (not N9))
       (or (= L1 U9) (not C9) (not N9))
       (or (= K1 S9) (not C9) (not N9))
       (or (= M10 T9) (not C9) (not N9))
       (or (= U9 D4) (not C9) (not N9))
       (or (= T9 C4) (not C9) (not N9))
       (or (= S9 E9) (not C9) (not N9))
       (or (= X9 C4) (not A9) (not O9))
       (or (= M1 Z9) (not A9) (not O9))
       (or (= L1 Y9) (not A9) (not O9))
       (or (= K1 W9) (not A9) (not O9))
       (or (= M10 X9) (not A9) (not O9))
       (or (= Z9 1) (not A9) (not O9))
       (or (= Y9 D4) (not A9) (not O9))
       (or (= W9 D4) (not A9) (not O9))
       (or (= P8 H4) (not W7) (not C8))
       (or (= O8 Y7) (not W7) (not C8))
       (or (= V1 Q8) (not W7) (not C8))
       (or (= U1 P8) (not W7) (not C8))
       (or (= T1 N8) (not W7) (not C8))
       (or (= Z8 O8) (not W7) (not C8))
       (or (= Q8 0) (not W7) (not C8))
       (or (= N8 (- 1)) (not W7) (not C8))
       (or (= U8 0) (not U7) (not D8))
       (or (= S8 G4) (not U7) (not D8))
       (or (= R8 (- 1)) (not U7) (not D8))
       (or (= V1 U8) (not U7) (not D8))
       (or (= U1 T8) (not U7) (not D8))
       (or (= T1 R8) (not U7) (not D8))
       (or (= Z8 S8) (not U7) (not D8))
       (or (= T8 I4) (not U7) (not D8))
       (or (= V1 Y8) (not S7) (not E8))
       (or (= U1 X8) (not S7) (not E8))
       (or (= T1 V8) (not S7) (not E8))
       (or (= Z8 W8) (not S7) (not E8))
       (or (= Y8 0) (not S7) (not E8))
       (or (= X8 H4) (not S7) (not E8))
       (or (= W8 G4) (not S7) (not E8))
       (or (= V8 (- 1)) (not S7) (not E8))
       (or (= I8 1) (not P7) (not A8))
       (or (= V1 I8) (not P7) (not A8))
       (or (= U1 H8) (not P7) (not A8))
       (or (= T1 F8) (not P7) (not A8))
       (or (= Z8 G8) (not P7) (not A8))
       (or (= H8 H4) (not P7) (not A8))
       (or (= G8 G4) (not P7) (not A8))
       (or (= F8 R7) (not P7) (not A8))
       (or (= M8 1) (not N7) (not B8))
       (or (= L8 H4) (not N7) (not B8))
       (or (= J8 H4) (not N7) (not B8))
       (or (= V1 M8) (not N7) (not B8))
       (or (= U1 L8) (not N7) (not B8))
       (or (= T1 J8) (not N7) (not B8))
       (or (= Z8 K8) (not N7) (not B8))
       (or (= K8 G4) (not N7) (not B8))
       (or R3 (not N7) (not B8))
       (or (not R3) (not N7) (not Q7))
       (or O3 (not A9) (not O9))
       (or (not O3) (not A9) (not D9))
       (or R1 (not S7) (not E8))
       (or (not R1) (not S7) (not V7))
       (or Q1 (not U7) (not D8))
       (or (not Q1) (not U7) (not X7))
       (or N1 (not (= F4 1)) (not Z7))
       (or (not N1) (not (= F4 0)) (not Z7))
       (or N1 (not Z7) (not G9))
       (or (not N1) (not Z7) (not B9))
       (or I1 (not F9) (not R9))
       (or (not I1) (not F9) (not I9))
       (or (not H1) (not H9) (not K9))
       (or E1 (not (= B4 1)) (not M9))
       (or (not E1) (not (= B4 0)) (not M9))
       (or (not E1) (not M9) (not O10))
       (or M (not M12) (not P13))
       (or (not D) (not O13) (not R13))
       (or (not Q) (not F12) (not I12))
       (or (not I3) (not D12) (not A12))
       (or (not E11) (not S10) (= D1 Y11))
       (or (not E11) (not S10) (= C1 X11))
       (or (not E11) (not S10) (= B1 V11))
       (or (not E11) (not S10) (= Z11 W11))
       (or (not E11) (not S10) (= Y11 0))
       (or (not E11) (not S10) (= X11 Z3))
       (or (not E11) (not S10) (= W11 Y3))
       (or (not E11) (not S10) (= V11 (- 1)))
       (or Z (not E11) (not S10))
       (or (not D11) (not U10) (= D1 U11))
       (or (not D11) (not U10) (= C1 T11))
       (or (not D11) (not U10) (= B1 R11))
       (or (not D11) (not U10) (= Z11 S11))
       (or (not D11) (not U10) (= U11 0))
       (or (not D11) (not U10) (= T11 A4))
       (or (not D11) (not U10) (= S11 Y3))
       (or (not D11) (not U10) (= R11 (- 1)))
       (or Y (not D11) (not U10))
       (or V (not Z10) (not (= X3 1)))
       (or (not Z10) (not V) (not (= X3 0)))
       (or V (not G12) (not Z10))
       (or (not V) (not Z10) (not B12))
       (or (not Y) (not X10) (not U10))
       (or (not W10) (not C11) (= N11 (- 1)))
       (or (= D1 Q11) (not W10) (not C11))
       (or (= C1 P11) (not W10) (not C11))
       (or (= B1 N11) (not W10) (not C11))
       (or (= Z11 O11) (not W10) (not C11))
       (or (= Q11 0) (not W10) (not C11))
       (or (= P11 Z3) (not W10) (not C11))
       (or (= O11 Y10) (not W10) (not C11))
       (or (not Z) (not S10) (not V10))
       (or E1 (not M9) (not T10))
       (or (= I11 1) (not A11) (not P10))
       (or (= H11 Z3) (not A11) (not P10))
       (or (= G11 Y3) (not A11) (not P10))
       (or (= F11 R10) (not A11) (not P10))
       (or (= D1 I11) (not A11) (not P10))
       (or (= C1 H11) (not A11) (not P10))
       (or (= B1 F11) (not A11) (not P10))
       (or (= Z11 G11) (not A11) (not P10))
       (or (not L3) (not N10) (not Q10))
       (or (= M11 1) (not B11) (not N10))
       (or (= L11 Z3) (not B11) (not N10))
       (or (= K11 Y3) (not B11) (not N10))
       (or (= J11 Z3) (not B11) (not N10))
       (or (= D1 M11) (not B11) (not N10))
       (or (= C1 L11) (not B11) (not N10))
       (or (= B1 J11) (not B11) (not N10))
       (or (= Z11 K11) (not B11) (not N10))
       (or L3 (not B11) (not N10))
       (or (not Q9) (not H9) (= H10 0))
       (or (not Q9) (not H9) (= M1 H10))
       (or (not Q9) (not H9) (= L1 G10))
       (or (not Q9) (not H9) (= K1 E10))
       (or (not Q9) (not H9) (= M10 F10))
       (or (not Q9) (not H9) (= G10 E4))
       (or (not Q9) (not H9) (= F10 C4))
       (or (not Q9) (not H9) (= E10 (- 1)))
       (or H1 (not Q9) (not H9))
       (or (not M6) W1 (not (= J4 1)))
       (or (not M6) (not W1) (not (= J4 0)))
       (or (not M6) W1 (not T7))
       (or (not M6) (not W1) (not O7))
       (or (= L7 X6) (not J6) (not O6))
       (or (= E2 A7) (not J6) (not O6))
       (or (= D2 Y6) (not J6) (not O6))
       (or (= C2 W6) (not J6) (not O6))
       (or (= M7 Z6) (not J6) (not O6))
       (or (= A7 0) (not J6) (not O6))
       (or (= Z6 G6) (not J6) (not O6))
       (or (= Y6 L4) (not J6) (not O6))
       (or (= X6 L6) (not J6) (not O6))
       (or (= W6 (- 1)) (not J6) (not O6))
       (or (= L7 C7) (not H6) (not P6))
       (or (= F7 0) (not H6) (not P6))
       (or (= E7 G6) (not H6) (not P6))
       (or (= D7 M4) (not H6) (not P6))
       (or (= E2 F7) (not H6) (not P6))
       (or (= D2 D7) (not H6) (not P6))
       (or (= C2 B7) (not H6) (not P6))
       (or (= M7 E7) (not H6) (not P6))
       (or (= C7 K4) (not H6) (not P6))
       (or (= B7 (- 1)) (not H6) (not P6))
       (or Z1 (not H6) (not P6))
       (or (not Z1) (not H6) (not K6))
       (or (not F6) F2 (not P4))
       (or (= L7 H7) (not E6) (not Q6))
       (or (= K7 0) (not E6) (not Q6))
       (or (= J7 G6) (not E6) (not Q6))
       (or (= I7 L4) (not E6) (not Q6))
       (or (= H7 K4) (not E6) (not Q6))
       (or (= G7 (- 1)) (not E6) (not Q6))
       (or (= E2 K7) (not E6) (not Q6))
       (or (= D2 I7) (not E6) (not Q6))
       (or (= C2 G7) (not E6) (not Q6))
       (or (= M7 J7) (not E6) (not Q6))
       (or A2 (not E6) (not Q6))
       (or (not A2) (not E6) (not I6))
       (or (not F2) (not P4) (not C6))
       (or (= L7 S6) (not B6) (not N6))
       (or (= T6 L4) (not B6) (not N6))
       (or (= S6 K4) (not B6) (not N6))
       (or (= R6 D6) (not B6) (not N6))
       (or (= E2 V6) (not B6) (not N6))
       (or (= D2 T6) (not B6) (not N6))
       (or (= C2 R6) (not B6) (not N6))
       (or (= M7 U6) (not B6) (not N6))
       (or (= V6 1) (not B6) (not N6))
       (or (= U6 N4) (not B6) (not N6))
       (or (not R12) (not F12) (= U L13))
       (or (not R12) (not F12) (= T K13))
       (or (not R12) (not F12) (= S I13))
       (or (not R12) (not F12) (= M13 J13))
       (or (not R12) (not F12) (= L13 0))
       (or (not R12) (not F12) (= K13 V3))
       (or (not R12) (not F12) (= J13 U3))
       (or (not R12) (not F12) (= I13 (- 1)))
       (or (not R12) (not F12) Q)
       (or (not Q12) (not H12) (= U H13))
       (or (not Q12) (not H12) (= T G13))
       (or (not Q12) (not H12) (= S E13))
       (or (not Q12) (not H12) (= M13 F13))
       (or (not Q12) (not H12) (= H13 0))
       (or (not Q12) (not H12) (= G13 W3))
       (or (not Q12) (not H12) (= F13 U3))
       (or (not Q12) (not H12) (= E13 (- 1)))
       (or P (not H12) (not Q12))
       (or (not O12) (not A12) (= U Z12))
       (or (not O12) (not A12) (= T Y12))
       (or (not O12) (not A12) (= S W12))
       (or (not O12) (not A12) (= W12 V3))
       (or (not O12) (not A12) (= M13 X12))
       (or (not O12) (not A12) (= Z12 1))
       (or (not O12) (not A12) (= Y12 V3))
       (or (not O12) (not A12) (= X12 U3))
       (or (not O12) (not A12) I3)
       (or (not N12) (not C12) (= U V12))
       (or (not N12) (not C12) (= T U12))
       (or (not N12) (not C12) (= S S12))
       (or (not N12) (not C12) (= U12 V3))
       (or (not N12) (not C12) (= T12 U3))
       (or (not N12) (not C12) (= M13 T12))
       (or (not N12) (not C12) (= V12 1))
       (or (not N12) (not C12) (= S12 E12))
       (or (not P) (not H12) (not K12))
       (or (not Q13) (and O13 R13))
       a!1
       (or (not O13) (= D (and A C)))
       (or (not O13) (= B (= N13 1)))
       (or (not O13) (not (= B C)))
       (or (not O13) (and M12 P13))
       a!2
       (or (not M12) (= L M13))
       (or (not M12) (= K (+ I J)))
       (or (not M12) (= J Z11))
       (or (not M12) (= I (+ G H)))
       (or (not M12) (= H M10))
       (or (not M12) (= G (+ F E)))
       (or (not M12) (= F Z8))
       (or (not M12) (= E L7))
       (or (not M12) (= N13 (+ K L)))
       (or (not J12) (= N (= W3 G3)))
       (or (not J12) (= L12 (ite N 1 U3)))
       (or (not J12) (and K12 H12))
       a!3
       (or (not H12) (= P (or O H3)))
       (or (not H12) (and F12 I12))
       a!4
       (or (not U10) (= Y (or X K3)))
       (or (not U10) (and V10 S10))
       (or (not S10) (= Z (= A4 (- 1))))
       (or (not S10) (and T10 M9))
       (or (not J9) (= F1 (= E4 M3)))
       (or (not J9) (= L9 (ite F1 1 C4)))
       (or (not J9) (and H9 K9))
       a!5
       (or (not H9) (= H1 (or G1 N3)))
       (or (not H9) (and F9 I9))
       (or (not F9) (= I1 (= E4 (- 1))))
       (or (not F9) (and Z7 G9))
       (or (not C9) (= J1 (= D4 M3)))
       (or (not C9) (= E9 (ite J1 (- 1) D4)))
       (or (not C9) (and A9 D9))
       (or (not A9) (and Z7 B9))
       (or (not W7) (= O1 (= I4 P3)))
       (or (not W7) (= Y7 (ite O1 1 G4)))
       (or (not W7) (and U7 X7))
       a!6
       (or (not U7) (= Q1 (or P1 Q3)))
       (or (not U7) (and S7 V7))
       (or (not S7) (= R1 (= I4 (- 1))))
       (or (not S7) (and M6 T7))
       (or (not P7) (= S1 (= H4 P3)))
       (or (not P7) (= R7 (ite S1 (- 1) H4)))
       (or (not P7) (and N7 Q7))
       (or (not N7) (and M6 O7))
       (or F2 (not (= O4 1)))
       (or (not F2) (not (= O4 0)))
       (or (not F12) (= Q (= W3 (- 1))))
       (or (not F12) (and Z10 G12))
       (or (not C12) (= R (= V3 G3)))
       (or (not C12) (= E12 (ite R (- 1) V3)))
       (or (not C12) (and A12 D12))
       (or (not A12) (and Z10 B12))
       (or (not W10) (= W (= A4 J3)))
       (or (not W10) (= Y10 (ite W 1 Y3)))
       (or (not W10) (and X10 U10))
       (or (not P10) (= A1 (= Z3 J3)))
       (or (not P10) (= R10 (ite A1 (- 1) Z3)))
       (or (not P10) (and N10 Q10))
       (or (not N10) (and M9 O10))
       (or (not J6) (= X1 (= M4 S3)))
       (or (not J6) (= L6 (ite X1 1 K4)))
       (or (not J6) (and H6 K6))
       a!7
       (or (not H6) (= Z1 (or Y1 T3)))
       (or (not H6) (and E6 I6))
       (or (not E6) (= A2 (= M4 (- 1))))
       (or (not E6) (= G6 (+ 1 N4)))
       (or (not E6) (and F6 P4))
       (or (not B6) (= B2 (= L4 S3)))
       (or (not B6) (= D6 (ite B2 (- 1) L4)))
       (or (not B6) (and C6 P4))
       (= Q13 true)
       (or (and J12 P12)
           (not M12)
           (and R12 F12)
           (and Q12 H12)
           (and O12 A12)
           (and N12 C12))
       (= 1 v_357)))
      )
      (main_1 v_357
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
        L5
        M5
        N5
        G2
        O5
        P5
        Q5
        H2
        R5
        S5
        T5
        I2
        U5
        V5
        W5
        J2
        X5
        Y5
        Z5
        A6
        K2)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Int) (T Int) (U Int) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Int) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Bool) (D3 Bool) (E3 Int) (F3 Bool) (G3 Bool) (H3 Int) (I3 Bool) (J3 Bool) (K3 Int) (L3 Bool) (M3 Bool) (N3 Int) (O3 Bool) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Bool) (L4 Bool) (M4 Bool) (N4 Int) (O4 Bool) (P4 Bool) (Q4 Int) (R4 Bool) (S4 Bool) (T4 Bool) (U4 Bool) (V4 Int) (W4 Bool) (X4 Bool) (Y4 Bool) (Z4 Bool) (A5 Bool) (B5 Int) (C5 Int) (D5 Int) (E5 Int) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Bool) (Y5 Bool) (Z5 Bool) (A6 Bool) (B6 Int) (C6 Bool) (D6 Bool) (E6 Bool) (F6 Bool) (G6 Bool) (H6 Bool) (I6 Int) (J6 Bool) (K6 Bool) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Bool) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Bool) (L7 Bool) (M7 Bool) (N7 Bool) (O7 Int) (P7 Bool) (Q7 Bool) (R7 Bool) (S7 Bool) (T7 Bool) (U7 Bool) (V7 Int) (W7 Bool) (X7 Bool) (Y7 Bool) (Z7 Bool) (A8 Bool) (B8 Bool) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Bool) (Y8 Bool) (Z8 Bool) (A9 Bool) (B9 Int) (C9 Bool) (D9 Bool) (E9 Bool) (F9 Bool) (G9 Bool) (H9 Bool) (I9 Int) (J9 Bool) (K9 Bool) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Bool) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Int) (U9 Int) (V9 Int) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Bool) (L10 Bool) (M10 Bool) (N10 Bool) (O10 Int) (P10 Bool) (Q10 Bool) (R10 Bool) (S10 Bool) (T10 Bool) (U10 Bool) (V10 Int) (W10 Bool) (X10 Bool) (Y10 Bool) (Z10 Bool) (A11 Bool) (B11 Bool) (C11 Int) (D11 Int) (E11 Int) (F11 Int) (G11 Int) (H11 Int) (I11 Int) (J11 Int) (K11 Int) (L11 Int) (M11 Int) (N11 Int) (O11 Int) (P11 Int) (Q11 Int) (R11 Int) (S11 Int) (T11 Int) (U11 Int) (V11 Int) (W11 Int) (X11 Int) (Y11 Bool) (Z11 Bool) (A12 Bool) (B12 Bool) (C12 Bool) (D12 Bool) (E12 Bool) (v_317 Int) (v_318 Int) ) 
    (=>
      (and
        (main_1 v_317
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4
        J4)
        (let ((a!1 (or (not Y11) (not (= (<= W5 4) A))))
      (a!2 (or (not E9) (not (= (<= V3 E3) X))))
      (a!3 (or (not R7) (not (= (<= Z3 H3) G1))))
      (a!4 (or (not E6) (not (= (<= D4 K3) P1))))
      (a!5 (or (not W10) (not (= (<= 2 X11) M))))
      (a!6 (or (not R10) (not (= (<= R3 B3) O))))
      (a!7 (or (not R4) (not (= (<= H4 N3) Y1)))))
  (and (= 1 v_317)
       (or (and K7 Y7) (and T7 Z7) (and P7 B8) (not W7) (and A8 R7) (and X7 M7))
       (or (and X5 L6) (and G6 M6) (and C6 O6) (not J6) (and N6 E6) (and K6 Z5))
       (or (and G9 M9) (and C9 O9) (not J9) (and N9 E9) (and L9 X8) (and K9 Z8))
       (or (and O4 A5) (and L4 X4) (and T4 Y4) (and R4 Z4) (not W4))
       (or (and W10 C12) (not A12) (and B12 Y11))
       (or (= W8 H8) (not K7) (not Y7))
       (or (= I8 Y3) (not K7) (not Y7))
       (or (= M1 J8) (not K7) (not Y7))
       (or (= L1 I8) (not K7) (not Y7))
       (or (= K1 G8) (not K7) (not Y7))
       (or (= J8 1) (not K7) (not Y7))
       (or (= H8 X3) (not K7) (not Y7))
       (or (= G8 Y3) (not K7) (not Y7))
       (or J3 (not K7) (not Y7))
       (or (not Y) (not H9) (not E9))
       (or (not A8) (not R7) (= W8 P8))
       (or (not A8) (not R7) (= Q8 Z3))
       (or (not A8) (not R7) (= O8 (- 1)))
       (or (not A8) (not R7) (= M1 R8))
       (or (not A8) (not R7) (= L1 Q8))
       (or (not A8) (not R7) (= K1 O8))
       (or (not A8) (not R7) (= R8 0))
       (or (not A8) (not R7) (= P8 X3))
       (or H1 (not A8) (not R7))
       (or (not X7) (not M7) (= D8 X3))
       (or (not X7) (not M7) (= W8 D8))
       (or (not X7) (not M7) (= M1 F8))
       (or (not X7) (not M7) (= L1 E8))
       (or (not X7) (not M7) (= K1 C8))
       (or (not X7) (not M7) (= F8 1))
       (or (not X7) (not M7) (= E8 Y3))
       (or (not X7) (not M7) (= C8 O7))
       (or E1 (not W7) (not (= W3 1)))
       (or (not W7) (not E1) (not (= W3 0)))
       (or (not E1) (not W7) (not Y8))
       (or E1 (not W7) (not D9))
       (or (not H1) (not U7) (not R7))
       (or (= W8 L8) (not Z7) (not T7))
       (or (not Z7) (not T7) (= K8 (- 1)))
       (or (= M1 N8) (not Z7) (not T7))
       (or (= L1 M8) (not Z7) (not T7))
       (or (= K1 K8) (not Z7) (not T7))
       (or (= N8 0) (not Z7) (not T7))
       (or (= M8 Y3) (not Z7) (not T7))
       (or (= L8 V7) (not Z7) (not T7))
       (or (= W8 T8) (not P7) (not B8))
       (or (= U8 Y3) (not P7) (not B8))
       (or (= M1 V8) (not P7) (not B8))
       (or (= L1 U8) (not P7) (not B8))
       (or (= K1 S8) (not P7) (not B8))
       (or (= V8 0) (not P7) (not B8))
       (or (= T8 X3) (not P7) (not B8))
       (or (not P7) (not B8) (= S8 (- 1)))
       (or I1 (not P7) (not B8))
       (or (not I1) (not S7) (not P7))
       (or (not J3) (not N7) (not K7))
       (or (not N6) (not E6) (= V1 E7))
       (or (not N6) (not E6) (= U1 D7))
       (or (not N6) (not E6) (= E7 0))
       (or (not N6) (not E6) (= C7 B4))
       (or (not N6) (not E6) (= B7 (- 1)))
       (or (not N6) (not E6) (= T1 B7))
       (or (not N6) (not E6) (= J7 C7))
       (or (not N6) (not E6) (= D7 D4))
       (or Q1 (not N6) (not E6))
       (or (not K6) (not Z5) (= V1 S6))
       (or (not K6) (not Z5) (= U1 R6))
       (or (not K6) (not Z5) (= T1 P6))
       (or (not K6) (not Z5) (= J7 Q6))
       (or (not K6) (not Z5) (= S6 1))
       (or (not K6) (not Z5) (= R6 C4))
       (or (not K6) (not Z5) (= Q6 B4))
       (or (not K6) (not Z5) (= P6 B6))
       (or N1 (not J6) (not (= A4 1)))
       (or (not J6) (not N1) (not (= A4 0)))
       (or (not N1) (not J6) (not L7))
       (or N1 (not J6) (not Q7))
       (or (not Q1) (not H6) (not E6))
       (or (= V1 A7) (not M6) (not G6))
       (or (= U1 Z6) (not M6) (not G6))
       (or (= Z6 C4) (not M6) (not G6))
       (or (= Y6 I6) (not M6) (not G6))
       (or (= T1 X6) (not M6) (not G6))
       (or (= J7 Y6) (not M6) (not G6))
       (or (= A7 0) (not M6) (not G6))
       (or (not M6) (not G6) (= X6 (- 1)))
       (or (= V1 I7) (not C6) (not O6))
       (or (= U1 H7) (not C6) (not O6))
       (or (= H7 C4) (not C6) (not O6))
       (or (not C6) (not O6) (= F7 (- 1)))
       (or (= T1 F7) (not C6) (not O6))
       (or (= J7 G7) (not C6) (not O6))
       (or (= I7 0) (not C6) (not O6))
       (or (= G7 B4) (not C6) (not O6))
       (or R1 (not C6) (not O6))
       (or (not R1) (not F6) (not C6))
       (or M (not W10) (not Z11))
       (or (not M) (not W10) (not C12))
       (or D (not B12) (not Y11))
       (or (= S K11) (not T10) (not Z10))
       (or (= U N11) (not T10) (not Z10))
       (or (= T M11) (not T10) (not Z10))
       (or (= W11 L11) (not T10) (not Z10))
       (or (= N11 0) (not T10) (not Z10))
       (or (= M11 Q3) (not T10) (not Z10))
       (or (= L11 V10) (not T10) (not Z10))
       (or (not T10) (not Z10) (= K11 (- 1)))
       (or (not P) (not R10) (not U10))
       (or (not Q) (not S10) (not P10))
       (or (not D3) (not K10) (not N10))
       (or (not N9) (not E9) (= D1 E10))
       (or (not N9) (not E9) (= C1 D10))
       (or (not N9) (not E9) (= B1 B10))
       (or (not N9) (not E9) (= J10 C10))
       (or (not N9) (not E9) (= E10 0))
       (or (not N9) (not E9) (= D10 V3))
       (or (not N9) (not E9) (= C10 T3))
       (or (not N9) (not E9) (= B10 (- 1)))
       (or Y (not N9) (not E9))
       (or (not L9) (not X8) (= W9 1))
       (or (not L9) (not X8) (= V9 U3))
       (or (not L9) (not X8) (= U9 T3))
       (or (not L9) (not X8) (= T9 U3))
       (or (not L9) (not X8) (= D1 W9))
       (or (not L9) (not X8) (= C1 V9))
       (or (not L9) (not X8) (= B1 T9))
       (or (not L9) (not X8) (= J10 U9))
       (or G3 (not L9) (not X8))
       (or (not K9) (not Z8) (= R9 U3))
       (or (not K9) (not Z8) (= Q9 T3))
       (or (not K9) (not Z8) (= P9 B9))
       (or (not K9) (not Z8) (= S9 1))
       (or (not K9) (not Z8) (= D1 S9))
       (or (not K9) (not Z8) (= C1 R9))
       (or (not K9) (not Z8) (= B1 P9))
       (or (not K9) (not Z8) (= J10 Q9))
       (or V (not J9) (not (= S3 1)))
       (or (not J9) (not V) (not (= S3 0)))
       (or V (not J9) (not Q10))
       (or (not V) (not J9) (not L10))
       (or (= A10 0) (not M9) (not G9))
       (or (= Z9 U3) (not M9) (not G9))
       (or (= Y9 I9) (not M9) (not G9))
       (or (not M9) (not G9) (= X9 (- 1)))
       (or (= D1 A10) (not M9) (not G9))
       (or (= C1 Z9) (not M9) (not G9))
       (or (= B1 X9) (not M9) (not G9))
       (or (= J10 Y9) (not M9) (not G9))
       (or (not Z) (not F9) (not C9))
       (or (= D1 I10) (not O9) (not C9))
       (or (= C1 H10) (not O9) (not C9))
       (or (= B1 F10) (not O9) (not C9))
       (or (= J10 G10) (not O9) (not C9))
       (or (= I10 0) (not O9) (not C9))
       (or (= H10 U3) (not O9) (not C9))
       (or (= G10 T3) (not O9) (not C9))
       (or (not O9) (not C9) (= F10 (- 1)))
       (or Z (not O9) (not C9))
       (or (not G3) (not A9) (not X8))
       (or (not X5) (= V1 W6) (not L6))
       (or (not X5) (= U1 V6) (not L6))
       (or (not X5) (= W6 1) (not L6))
       (or (not X5) (= V6 C4) (not L6))
       (or (not X5) (= T1 T6) (not L6))
       (or (not X5) (= J7 U6) (not L6))
       (or (not X5) (= U6 B4) (not L6))
       (or (not X5) (= T6 C4) (not L6))
       (or W1 (not W4) (not (= E4 1)))
       (or (not W4) (not W1) (not (= E4 0)))
       (or W1 (not W4) (not D6))
       (or (not W1) (not W4) (not Y5))
       (or (= E2 K5) (not T4) (not Y4))
       (or (= D2 I5) (not T4) (not Y4))
       (or (= W5 J5) (not T4) (not Y4))
       (or (= V5 H5) (not T4) (not Y4))
       (or (= G5 (- 1)) (not T4) (not Y4))
       (or (= C2 G5) (not T4) (not Y4))
       (or (= K5 0) (not T4) (not Y4))
       (or (= J5 Q4) (not T4) (not Y4))
       (or (= I5 G4) (not T4) (not Y4))
       (or (= H5 V4) (not T4) (not Y4))
       (or (not Z4) (= E2 P5) (not R4))
       (or (not Z4) (= D2 N5) (not R4))
       (or (not Z4) (= W5 O5) (not R4))
       (or (not Z4) (= V5 M5) (not R4))
       (or (not Z4) (= C2 L5) (not R4))
       (or (not Z4) (= P5 0) (not R4))
       (or (not Z4) (= O5 Q4) (not R4))
       (or (not Z4) (= N5 H4) (not R4))
       (or (not Z4) (= M5 F4) (not R4))
       (or (not Z4) (not R4) (= L5 (- 1)))
       (or (not Z4) Z1 (not R4))
       (or (not Z1) (not U4) (not R4))
       (or (= E2 U5) (not O4) (not A5))
       (or (= D2 S5) (not O4) (not A5))
       (or (= W5 T5) (not O4) (not A5))
       (or (= V5 R5) (not O4) (not A5))
       (or (= U5 0) (not O4) (not A5))
       (or (= T5 Q4) (not O4) (not A5))
       (or (= S5 G4) (not O4) (not A5))
       (or (= R5 F4) (not O4) (not A5))
       (or (not O4) (not A5) (= Q5 (- 1)))
       (or (= C2 Q5) (not O4) (not A5))
       (or A2 (not O4) (not A5))
       (or (not S4) (not A2) (not O4))
       (or (not L4) (= D5 G4) (not X4))
       (or (not L4) (= C5 F4) (not X4))
       (or (not L4) (= B5 N4) (not X4))
       (or (not L4) (= E2 F5) (not X4))
       (or (not L4) (= D2 D5) (not X4))
       (or (not L4) (= W5 E5) (not X4))
       (or (not L4) (= V5 C5) (not X4))
       (or (not L4) (= F5 1) (not X4))
       (or (not L4) (= E5 I4) (not X4))
       (or (not L4) (= C2 B5) (not X4))
       (or F2 (not P4) (not K4))
       (or (not F2) (not K4) (not M4))
       (or M3 (not X5) (not L6))
       (or (not X5) (not M3) (not A6))
       (or (not B11) (not P10) (= S S11))
       (or (not B11) (not P10) (= U V11))
       (or (not B11) (not P10) (= T U11))
       (or (not B11) (not P10) (= W11 T11))
       (or (not B11) (not P10) (= V11 0))
       (or (not B11) (not P10) (= U11 Q3))
       (or (not B11) (not P10) (= T11 P3))
       (or (not B11) (not P10) (= S11 (- 1)))
       (or (not B11) (not P10) Q)
       (or (not A11) (not R10) (= S O11))
       (or (not A11) (not R10) (= U R11))
       (or (not A11) (not R10) (= T Q11))
       (or (not A11) (not R10) (= W11 P11))
       (or (not A11) (not R10) (= R11 0))
       (or (not A11) (not R10) (= Q11 R3))
       (or (not A11) (not R10) (= P11 P3))
       (or (not A11) (not R10) (= O11 (- 1)))
       (or (not A11) (not R10) P)
       (or (not Y10) (not K10) (= S G11))
       (or (not Y10) (not K10) (= U J11))
       (or (not Y10) (not K10) (= T I11))
       (or (not Y10) (not K10) (= J11 1))
       (or (not Y10) (not K10) (= H11 P3))
       (or (not Y10) (not K10) (= G11 Q3))
       (or (not Y10) (not K10) (= W11 H11))
       (or (not Y10) (not K10) (= I11 Q3))
       (or (not Y10) (not K10) D3)
       (or (not X10) (not M10) (= S C11))
       (or (not X10) (not M10) (= U F11))
       (or (not X10) (not M10) (= T E11))
       (or (not X10) (not M10) (= E11 Q3))
       (or (not X10) (not M10) (= D11 P3))
       (or (not X10) (not M10) (= W11 D11))
       (or (not X10) (not M10) (= F11 1))
       (or (not X10) (not M10) (= C11 O10))
       a!1
       (or (not Y11) (= D (and A C)))
       (or (not Y11) (= B (= X11 1)))
       (or (not Y11) (not (= B C)))
       (or (not Y11) (and W10 Z11))
       a!2
       (or (not E9) (= Y (or X F3)))
       (or (not E9) (and C9 F9))
       (or (not Z8) (= A1 (= U3 E3)))
       (or (not Z8) (= B9 (ite A1 (- 1) U3)))
       (or (not Z8) (and A9 X8))
       (or (not X8) (and W7 Y8))
       a!3
       (or (not R7) (= H1 (or G1 I3)))
       (or (not R7) (and P7 S7))
       (or (not M7) (= J1 (= Y3 H3)))
       (or (not M7) (= O7 (ite J1 (- 1) Y3)))
       (or (not M7) (and N7 K7))
       (or (not K7) (and J6 L7))
       a!4
       (or (not E6) (= Q1 (or L3 P1)))
       (or (not E6) (and C6 F6))
       (or (not Z5) (= S1 (= C4 K3)))
       (or (not Z5) (= B6 (ite S1 (- 1) C4)))
       (or (not Z5) (and X5 A6))
       (or F2 (not (= J4 1)))
       (or (not F2) (not (= J4 0)))
       (or (not D12) (and E12 A12))
       a!5
       (or (not W10) (= L W11))
       (or (not W10) (= K (+ I J)))
       (or (not W10) (= J J10))
       (or (not W10) (= F J7))
       (or (not W10) (= E V5))
       (or (not W10) (= I (+ G H)))
       (or (not W10) (= H W8))
       (or (not W10) (= G (+ F E)))
       (or (not W10) (= X11 (+ K L)))
       (or (not T7) (= F1 (= Z3 H3)))
       (or (not T7) (= V7 (ite F1 1 X3)))
       (or (not T7) (and U7 R7))
       (or (not P7) (= I1 (= Z3 (- 1))))
       (or (not P7) (and J6 Q7))
       (or (not G6) (= O1 (= D4 K3)))
       (or (not G6) (= I6 (ite O1 1 B4)))
       (or (not G6) (and H6 E6))
       (or (not C6) (= R1 (= D4 (- 1))))
       (or (not C6) (and W4 D6))
       (or (not T10) (= N (= R3 B3)))
       (or (not T10) (= V10 (ite N 1 P3)))
       (or (not T10) (and R10 U10))
       a!6
       (or (not R10) (= P (or O C3)))
       (or (not R10) (and P10 S10))
       (or (not P10) (= Q (= R3 (- 1))))
       (or (not P10) (and J9 Q10))
       (or (not M10) (= R (= Q3 B3)))
       (or (not M10) (= O10 (ite R (- 1) Q3)))
       (or (not M10) (and K10 N10))
       (or (not K10) (and J9 L10))
       (or (not G9) (= W (= V3 E3)))
       (or (not G9) (= I9 (ite W 1 T3)))
       (or (not G9) (and H9 E9))
       (or (not C9) (= Z (= V3 (- 1))))
       (or (not C9) (and W7 D9))
       (or (not X5) (and W4 Y5))
       (or (not T4) (= X1 (= H4 N3)))
       (or (not T4) (= V4 (ite X1 1 F4)))
       (or (not T4) (and R4 U4))
       a!7
       (or (not R4) (= Z1 (or O3 Y1)))
       (or (not R4) (and O4 S4))
       (or (not O4) (= A2 (= H4 (- 1))))
       (or (not O4) (= Q4 (+ 1 I4)))
       (or (not O4) (and K4 P4))
       (or (not L4) (= B2 (= G4 N3)))
       (or (not L4) (= N4 (ite B2 (- 1) G4)))
       (or (not L4) (and K4 M4))
       (= D12 true)
       (or (and T10 Z10)
           (not W10)
           (and B11 P10)
           (and A11 R10)
           (and Y10 K10)
           (and X10 M10))
       (= 3 v_318)))
      )
      (main_1 v_318
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4
        J4)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Int) (T Int) (U Int) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Int) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Bool) (H3 Bool) (I3 Int) (J3 Bool) (K3 Bool) (L3 Int) (M3 Bool) (N3 Bool) (O3 Int) (P3 Bool) (Q3 Bool) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Bool) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Int) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Bool) (B6 Bool) (C6 Int) (D6 Bool) (E6 Bool) (F6 Bool) (G6 Bool) (H6 Int) (I6 Bool) (J6 Bool) (K6 Bool) (L6 Bool) (M6 Bool) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Bool) (K7 Bool) (L7 Bool) (M7 Bool) (N7 Int) (O7 Bool) (P7 Bool) (Q7 Bool) (R7 Bool) (S7 Bool) (T7 Bool) (U7 Int) (V7 Bool) (W7 Bool) (X7 Bool) (Y7 Bool) (Z7 Bool) (A8 Bool) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Bool) (X8 Bool) (Y8 Bool) (Z8 Bool) (A9 Int) (B9 Bool) (C9 Bool) (D9 Bool) (E9 Bool) (F9 Bool) (G9 Bool) (H9 Int) (I9 Bool) (J9 Bool) (K9 Bool) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Int) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Int) (U9 Int) (V9 Int) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Bool) (K10 Bool) (L10 Bool) (M10 Bool) (N10 Int) (O10 Bool) (P10 Bool) (Q10 Bool) (R10 Bool) (S10 Bool) (T10 Bool) (U10 Int) (V10 Bool) (W10 Bool) (X10 Bool) (Y10 Bool) (Z10 Bool) (A11 Bool) (B11 Int) (C11 Int) (D11 Int) (E11 Int) (F11 Int) (G11 Int) (H11 Int) (I11 Int) (J11 Int) (K11 Int) (L11 Int) (M11 Int) (N11 Int) (O11 Int) (P11 Int) (Q11 Int) (R11 Int) (S11 Int) (T11 Int) (U11 Int) (V11 Int) (W11 Bool) (X11 Bool) (Y11 Bool) (Z11 Bool) (A12 Int) (B12 Bool) (C12 Bool) (D12 Bool) (E12 Bool) (F12 Bool) (G12 Bool) (H12 Int) (I12 Bool) (J12 Bool) (K12 Bool) (L12 Bool) (M12 Bool) (N12 Bool) (O12 Int) (P12 Int) (Q12 Int) (R12 Int) (S12 Int) (T12 Int) (U12 Int) (V12 Int) (W12 Int) (X12 Int) (Y12 Int) (Z12 Int) (A13 Int) (B13 Int) (C13 Int) (D13 Int) (E13 Int) (F13 Int) (G13 Int) (H13 Int) (I13 Int) (J13 Int) (K13 Bool) (L13 Bool) (M13 Bool) (N13 Bool) (v_352 Int) (v_353 Int) ) 
    (=>
      (and
        (main_1 v_352
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4
        J4
        K4
        L4
        M4
        N4)
        (let ((a!1 (or (not K13) (not (= (<= I7 4) A))))
      (a!2 (or (not I12) (not (= (<= 2 J13) M))))
      (a!3 (or (not D12) (not (= (<= M2 F3) O))))
      (a!4 (or (not Q10) (not (= (<= Q2 I3) X))))
      (a!5 (or (not D9) (not (= (<= U2 L3) G1))))
      (a!6 (or (not Q7) (not (= (<= Y2 O3) P1))))
      (a!7 (or (not D6) (not (= (<= C3 R3) Y1)))))
  (and (= 2 v_352)
       (or (and F9 J9) (and D9 K9) (and B9 L9) (and W8 N9) (not I9) (and M9 Y8))
       (or (and S7 W7) (and Q7 X7) (and O7 Y7) (and L7 Z7) (and J7 A8) (not V7))
       (or (and S10 W10)
           (and L10 Z10)
           (and J10 A11)
           (not V10)
           (and Y10 O10)
           (and X10 Q10))
       (or (not I6) (and F6 J6) (and D6 K6) (and A6 L6) (and M6 O4))
       (or (= Y5 H5) (not K13) (not N13))
       (or (= X5 G5) (not K13) (not N13))
       (or (= Z5 I5) (not K13) (not N13))
       (or (= W5 F5) (not K13) (not N13))
       (or (= V5 D5) (not K13) (not N13))
       (or (= U5 C5) (not K13) (not N13))
       (or (= T5 B5) (not K13) (not N13))
       (or (= S5 Z4) (not K13) (not N13))
       (or (= R5 Y4) (not K13) (not N13))
       (or (= Q5 X4) (not K13) (not N13))
       (or (= P5 V4) (not K13) (not N13))
       (or (= O5 U4) (not K13) (not N13))
       (or (= N5 T4) (not K13) (not N13))
       (or (= M5 R4) (not K13) (not N13))
       (or (= L5 Q4) (not K13) (not N13))
       (or (= K5 P4) (not K13) (not N13))
       (or (= J5 E2) (not K13) (not N13))
       (or (= I5 I7) (not K13) (not N13))
       (or (= H5 S) (not K13) (not N13))
       (or (= G5 D2) (not K13) (not N13))
       (or (= F5 H7) (not K13) (not N13))
       (or (= E5 V1) (not K13) (not N13))
       (or (= D5 C2) (not K13) (not N13))
       (or (= C5 U1) (not K13) (not N13))
       (or (= B5 V8) (not K13) (not N13))
       (or (= A5 M1) (not K13) (not N13))
       (or (= Z4 T1) (not K13) (not N13))
       (or (= Y4 L1) (not K13) (not N13))
       (or (= X4 I10) (not K13) (not N13))
       (or (= W4 D1) (not K13) (not N13))
       (or (= V4 K1) (not K13) (not N13))
       (or (= U4 C1) (not K13) (not N13))
       (or (= J2 J5) (not K13) (not N13))
       (or (= I2 E5) (not K13) (not N13))
       (or (= H2 A5) (not K13) (not N13))
       (or (= G2 W4) (not K13) (not N13))
       (or (= F2 S4) (not K13) (not N13))
       (or (= T4 V11) (not K13) (not N13))
       (or (= S4 U) (not K13) (not N13))
       (or (= R4 B1) (not K13) (not N13))
       (or (= Q4 T) (not K13) (not N13))
       (or (= P4 I13) (not K13) (not N13))
       (or (not D) (not K13) (not N13))
       (or (= M1 R9) (not F9) (not J9))
       (or (= L1 Q9) (not F9) (not J9))
       (or (= K1 O9) (not F9) (not J9))
       (or (= R9 0) (not F9) (not J9))
       (or (= I10 P9) (not F9) (not J9))
       (or (= Q9 T2) (not F9) (not J9))
       (or (= P9 H9) (not F9) (not J9))
       (or (not F9) (not J9) (= O9 (- 1)))
       (or (= M1 V9) (not D9) (not K9))
       (or (= L1 U9) (not D9) (not K9))
       (or (= K1 S9) (not D9) (not K9))
       (or (= T9 S2) (not D9) (not K9))
       (or (= I10 T9) (not D9) (not K9))
       (or (= V9 0) (not D9) (not K9))
       (or (= U9 U2) (not D9) (not K9))
       (or (not D9) (not K9) (= S9 (- 1)))
       (or H1 (not D9) (not K9))
       (or (not H1) (not D9) (not G9))
       (or (= M1 Z9) (not B9) (not L9))
       (or (= L1 Y9) (not B9) (not L9))
       (or (= K1 W9) (not B9) (not L9))
       (or (= Z9 0) (not B9) (not L9))
       (or (= X9 S2) (not B9) (not L9))
       (or (= I10 X9) (not B9) (not L9))
       (or (= Y9 T2) (not B9) (not L9))
       (or (= W9 (- 1)) (not B9) (not L9))
       (or I1 (not B9) (not L9))
       (or (not I1) (not B9) (not E9))
       (or (= M1 H10) (not W8) (not N9))
       (or (= L1 G10) (not W8) (not N9))
       (or (= K1 E10) (not W8) (not N9))
       (or (= F10 S2) (not W8) (not N9))
       (or (= I10 F10) (not W8) (not N9))
       (or (= H10 1) (not W8) (not N9))
       (or (= G10 T2) (not W8) (not N9))
       (or (= E10 T2) (not W8) (not N9))
       (or (= V1 E8) (not S7) (not W7))
       (or (= U1 D8) (not S7) (not W7))
       (or (= T1 B8) (not S7) (not W7))
       (or (= E8 0) (not S7) (not W7))
       (or (= V8 C8) (not S7) (not W7))
       (or (= D8 X2) (not S7) (not W7))
       (or (= C8 U7) (not S7) (not W7))
       (or (not S7) (not W7) (= B8 (- 1)))
       (or (= V1 I8) (not Q7) (not X7))
       (or (= U1 H8) (not Q7) (not X7))
       (or (= T1 F8) (not Q7) (not X7))
       (or (= I8 0) (not Q7) (not X7))
       (or (= H8 Y2) (not Q7) (not X7))
       (or (not Q7) (not X7) (= F8 (- 1)))
       (or (= V8 G8) (not Q7) (not X7))
       (or (= G8 W2) (not Q7) (not X7))
       (or Q1 (not Q7) (not X7))
       (or (not Q1) (not Q7) (not T7))
       (or (= V1 M8) (not O7) (not Y7))
       (or (= U1 L8) (not O7) (not Y7))
       (or (= T1 J8) (not O7) (not Y7))
       (or (= L8 X2) (not O7) (not Y7))
       (or (= K8 W2) (not O7) (not Y7))
       (or (= V8 K8) (not O7) (not Y7))
       (or (= M8 0) (not O7) (not Y7))
       (or (= J8 (- 1)) (not O7) (not Y7))
       (or R1 (not O7) (not Y7))
       (or (not R1) (not O7) (not R7))
       (or (= V1 Q8) (not L7) (not Z7))
       (or (= U1 P8) (not L7) (not Z7))
       (or (= T1 N8) (not L7) (not Z7))
       (or (= Q8 1) (not L7) (not Z7))
       (or (= O8 W2) (not L7) (not Z7))
       (or (= N8 N7) (not L7) (not Z7))
       (or (= V8 O8) (not L7) (not Z7))
       (or (= P8 X2) (not L7) (not Z7))
       (or (= V1 U8) (not J7) (not A8))
       (or (= U1 T8) (not J7) (not A8))
       (or (= T1 R8) (not J7) (not A8))
       (or (= V8 S8) (not J7) (not A8))
       (or (= U8 1) (not J7) (not A8))
       (or (= T8 X2) (not J7) (not A8))
       (or (= S8 W2) (not J7) (not A8))
       (or (= R8 X2) (not J7) (not A8))
       (or Q3 (not J7) (not A8))
       (or (not Q3) (not J7) (not M7))
       (or N3 (not W8) (not N9))
       (or (not N3) (not W8) (not Z8))
       (or N1 (not V7) (not (= V2 1)))
       (or (not N1) (not V7) (not (= V2 0)))
       (or N1 (not V7) (not C9))
       (or (not N1) (not V7) (not X8))
       (or E1 (not I9) (not (= R2 1)))
       (or (not E1) (not I9) (not (= R2 0)))
       (or (not E1) (not I9) (not K10))
       (or M (not I12) (not L13))
       (or (= U Z12) (not B12) (not L12))
       (or (= T Y12) (not B12) (not L12))
       (or (= S W12) (not B12) (not L12))
       (or (= I13 X12) (not B12) (not L12))
       (or (= Z12 0) (not B12) (not L12))
       (or (= Y12 L2) (not B12) (not L12))
       (or (= X12 K2) (not B12) (not L12))
       (or (not B12) (= W12 (- 1)) (not L12))
       (or Q (not B12) (not L12))
       (or (not Q) (not B12) (not E12))
       (or (not H3) (not Z11) (not W11))
       (or (not Y10) (not O10) (= D1 M11))
       (or (not Y10) (not O10) (= C1 L11))
       (or (not Y10) (not O10) (= B1 J11))
       (or (not Y10) (not O10) (= J11 (- 1)))
       (or (not Y10) (not O10) (= V11 K11))
       (or (not Y10) (not O10) (= M11 0))
       (or (not Y10) (not O10) (= L11 P2))
       (or (not Y10) (not O10) (= K11 O2))
       (or (not Y10) (not O10) Z)
       (or (not X10) (not Q10) (= D1 I11))
       (or (not X10) (not Q10) (= C1 H11))
       (or (not X10) (not Q10) (= B1 F11))
       (or (not X10) (not Q10) (= I11 0))
       (or (not X10) (not Q10) (= H11 Q2))
       (or (not X10) (not Q10) (= G11 O2))
       (or (not X10) (not Q10) (= F11 (- 1)))
       (or (not X10) (not Q10) (= V11 G11))
       (or (not X10) (not Q10) Y)
       (or V (not V10) (not (= N2 1)))
       (or (not V10) (not V) (not (= N2 0)))
       (or V (not C12) (not V10))
       (or (not V) (not V10) (not X11))
       (or (not T10) (not Q10) (not Y))
       (or (= D1 E11) (not S10) (not W10))
       (or (= C1 D11) (not S10) (not W10))
       (or (= B1 B11) (not S10) (not W10))
       (or (= E11 0) (not S10) (not W10))
       (or (= D11 P2) (not S10) (not W10))
       (or (= C11 U10) (not S10) (not W10))
       (or (not S10) (not W10) (= B11 (- 1)))
       (or (= V11 C11) (not S10) (not W10))
       (or (not R10) (not O10) (not Z))
       (or E1 (not I9) (not P10))
       (or (= D1 Q11) (not Z10) (not L10))
       (or (= C1 P11) (not Z10) (not L10))
       (or (= B1 N11) (not Z10) (not L10))
       (or (= V11 O11) (not Z10) (not L10))
       (or (= Q11 1) (not Z10) (not L10))
       (or (= P11 P2) (not Z10) (not L10))
       (or (= O11 O2) (not Z10) (not L10))
       (or (= N11 N10) (not Z10) (not L10))
       (or (not K3) (not J10) (not M10))
       (or (= D1 U11) (not A11) (not J10))
       (or (= C1 T11) (not A11) (not J10))
       (or (= B1 R11) (not A11) (not J10))
       (or (= V11 S11) (not A11) (not J10))
       (or (= U11 1) (not A11) (not J10))
       (or (= T11 P2) (not A11) (not J10))
       (or (= S11 O2) (not A11) (not J10))
       (or (= R11 P2) (not A11) (not J10))
       (or K3 (not A11) (not J10))
       (or (not M9) (not Y8) (= M1 D10))
       (or (not M9) (not Y8) (= L1 C10))
       (or (not M9) (not Y8) (= K1 A10))
       (or (not M9) (not Y8) (= D10 1))
       (or (not M9) (not Y8) (= I10 B10))
       (or (not M9) (not Y8) (= C10 T2))
       (or (not M9) (not Y8) (= B10 S2))
       (or (not M9) (not Y8) (= A10 A9))
       (or (not M6) (not O4) (= H7 D7))
       (or (not M6) (not O4) (= G7 1))
       (or (not M6) (not O4) (= F7 D3))
       (or (not M6) (not O4) (= E7 B3))
       (or (not M6) (not O4) (= D7 A3))
       (or (not M6) (not O4) (= C7 B3))
       (or (not M6) (not O4) (= E2 G7))
       (or (not M6) (not O4) (= D2 E7))
       (or (not M6) (not O4) (= C2 C7))
       (or (not M6) (not O4) (= I7 F7))
       (or (not B2) (not M6) (not O4))
       (or (not I6) W1 (not (= Z2 1)))
       (or (not I6) (not W1) (not (= Z2 0)))
       (or (not I6) W1 (not P7))
       (or (not I6) (not W1) (not K7))
       (or (= H7 O6) (not F6) (not J6))
       (or (= P6 B3) (not F6) (not J6))
       (or (= O6 H6) (not F6) (not J6))
       (or (not F6) (not J6) (= N6 (- 1)))
       (or (= E2 R6) (not F6) (not J6))
       (or (= D2 P6) (not F6) (not J6))
       (or (= C2 N6) (not F6) (not J6))
       (or (= I7 Q6) (not F6) (not J6))
       (or (= R6 0) (not F6) (not J6))
       (or (= Q6 C6) (not F6) (not J6))
       (or (= H7 T6) (not D6) (not K6))
       (or (= E2 W6) (not D6) (not K6))
       (or (= D2 U6) (not D6) (not K6))
       (or (= C2 S6) (not D6) (not K6))
       (or (= I7 V6) (not D6) (not K6))
       (or (= W6 0) (not D6) (not K6))
       (or (= V6 C6) (not D6) (not K6))
       (or (= U6 C3) (not D6) (not K6))
       (or (= T6 A3) (not D6) (not K6))
       (or (= S6 (- 1)) (not D6) (not K6))
       (or Z1 (not D6) (not K6))
       (or (not Z1) (not D6) (not G6))
       (or (not B6) B2 (not O4))
       (or (= H7 Y6) (not A6) (not L6))
       (or (= B7 0) (not A6) (not L6))
       (or (= A7 C6) (not A6) (not L6))
       (or (= Z6 B3) (not A6) (not L6))
       (or (= E2 B7) (not A6) (not L6))
       (or (= D2 Z6) (not A6) (not L6))
       (or (= C2 X6) (not A6) (not L6))
       (or (= I7 A7) (not A6) (not L6))
       (or (= Y6 A3) (not A6) (not L6))
       (or (= X6 (- 1)) (not A6) (not L6))
       (or A2 (not A6) (not L6))
       (or (not A2) (not A6) (not E6))
       (or (not N12) (not W11) (= U H13))
       (or (not N12) (not W11) (= T G13))
       (or (not N12) (not W11) (= S E13))
       (or (not N12) (not W11) (= I13 F13))
       (or (not N12) (not W11) (= H13 1))
       (or (not N12) (not W11) (= G13 L2))
       (or (not N12) (not W11) (= F13 K2))
       (or (not N12) (not W11) (= E13 L2))
       (or (not N12) (not W11) H3)
       (or (not M12) (not Y11) (= U D13))
       (or (not M12) (not Y11) (= T C13))
       (or (not M12) (not Y11) (= S A13))
       (or (not M12) (not Y11) (= I13 B13))
       (or (not M12) (not Y11) (= D13 1))
       (or (not M12) (not Y11) (= C13 L2))
       (or (not M12) (not Y11) (= B13 K2))
       (or (not M12) (not Y11) (= A13 A12))
       (or (not K12) (not D12) (= U V12))
       (or (not K12) (not D12) (= T U12))
       (or (not K12) (not D12) (= S S12))
       (or (not K12) (not D12) (= S12 (- 1)))
       (or (not K12) (not D12) (= I13 T12))
       (or (not K12) (not D12) (= V12 0))
       (or (not K12) (not D12) (= U12 M2))
       (or (not K12) (not D12) (= T12 K2))
       (or (not K12) (not D12) P)
       (or (not J12) (not F12) (= U R12))
       (or (not J12) (not F12) (= T Q12))
       (or (not J12) (not F12) (= S O12))
       (or (not J12) (not F12) (= Q12 L2))
       (or (not J12) (not F12) (= P12 H12))
       (or (not J12) (not F12) (= I13 P12))
       (or (not J12) (not F12) (= R12 0))
       (or (not J12) (not F12) (= O12 (- 1)))
       (or (not G12) (not D12) (not P))
       (or (not M13) (and K13 N13))
       a!1
       (or (not K13) (= D (and A C)))
       (or (not K13) (= B (= J13 1)))
       (or (not K13) (not (= B C)))
       (or (not K13) (and I12 L13))
       a!2
       (or (not I12) (= L I13))
       (or (not I12) (= K (+ I J)))
       (or (not I12) (= J V11))
       (or (not I12) (= I (+ G H)))
       (or (not I12) (= H I10))
       (or (not I12) (= G (+ F E)))
       (or (not I12) (= F V8))
       (or (not I12) (= E H7))
       (or (not I12) (= J13 (+ K L)))
       (or (not F12) (= N (= M2 F3)))
       (or (not F12) (= H12 (ite N 1 K2)))
       (or (not F12) (and G12 D12))
       a!3
       (or (not D12) (= P (or G3 O)))
       (or (not D12) (and B12 E12))
       a!4
       (or (not Q10) (= Y (or J3 X)))
       (or (not Q10) (and R10 O10))
       (or (not O10) (= Z (= Q2 (- 1))))
       (or (not O10) (and P10 I9))
       (or (not F9) (= F1 (= U2 L3)))
       (or (not F9) (= H9 (ite F1 1 S2)))
       (or (not F9) (and D9 G9))
       a!5
       (or (not D9) (= H1 (or M3 G1)))
       (or (not D9) (and B9 E9))
       (or (not B9) (= I1 (= U2 (- 1))))
       (or (not B9) (and V7 C9))
       (or (not Y8) (= J1 (= T2 L3)))
       (or (not Y8) (= A9 (ite J1 (- 1) T2)))
       (or (not Y8) (and W8 Z8))
       (or (not W8) (and V7 X8))
       (or (not S7) (= O1 (= Y2 O3)))
       (or (not S7) (= U7 (ite O1 1 W2)))
       (or (not S7) (and Q7 T7))
       a!6
       (or (not Q7) (= Q1 (or P3 P1)))
       (or (not Q7) (and O7 R7))
       (or (not O7) (= R1 (= Y2 (- 1))))
       (or (not O7) (and I6 P7))
       (or (not L7) (= S1 (= X2 O3)))
       (or (not L7) (= N7 (ite S1 (- 1) X2)))
       (or (not L7) (and J7 M7))
       (or (not J7) (and I6 K7))
       (or B2 (not (= E3 1)))
       (or (not B2) (not (= E3 0)))
       (or (not B12) (= Q (= M2 (- 1))))
       (or (not B12) (and V10 C12))
       (or (not Y11) (= R (= L2 F3)))
       (or (not Y11) (= A12 (ite R (- 1) L2)))
       (or (not Y11) (and W11 Z11))
       (or (not W11) (and V10 X11))
       (or (not S10) (= W (= Q2 I3)))
       (or (not S10) (= U10 (ite W 1 O2)))
       (or (not S10) (and T10 Q10))
       (or (not L10) (= A1 (= P2 I3)))
       (or (not L10) (= N10 (ite A1 (- 1) P2)))
       (or (not L10) (and J10 M10))
       (or (not J10) (and I9 K10))
       (or (not F6) (= X1 (= C3 R3)))
       (or (not F6) (= H6 (ite X1 1 A3)))
       (or (not F6) (and D6 G6))
       a!7
       (or (not D6) (= Z1 (or Y1 S3)))
       (or (not D6) (and A6 E6))
       (or (not A6) (= A2 (= C3 (- 1))))
       (or (not A6) (= C6 (+ 1 D3)))
       (or (not A6) (and B6 O4))
       (= M13 true)
       (or (and B12 L12)
           (not I12)
           (and N12 W11)
           (and M12 Y11)
           (and K12 D12)
           (and J12 F12))
       (= 2 v_353)))
      )
      (main_1 v_353
        K5
        L5
        M5
        F2
        N5
        O5
        P5
        G2
        Q5
        R5
        S5
        H2
        T5
        U5
        V5
        I2
        W5
        X5
        Y5
        Z5
        J2
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4
        J4
        K4
        L4
        M4
        N4)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Int) (T Int) (U Int) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Int) (C1 Int) (D1 Int) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Int) (L1 Int) (M1 Int) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Int) (U1 Int) (V1 Int) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Bool) (C3 Bool) (D3 Int) (E3 Bool) (F3 Bool) (G3 Int) (H3 Bool) (I3 Bool) (J3 Int) (K3 Bool) (L3 Bool) (M3 Int) (N3 Bool) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Bool) (K4 Bool) (L4 Bool) (M4 Bool) (N4 Int) (O4 Bool) (P4 Bool) (Q4 Bool) (R4 Bool) (S4 Int) (T4 Bool) (U4 Bool) (V4 Bool) (W4 Bool) (X4 Bool) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Int) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Bool) (V5 Bool) (W5 Bool) (X5 Bool) (Y5 Int) (Z5 Bool) (A6 Bool) (B6 Bool) (C6 Bool) (D6 Bool) (E6 Bool) (F6 Int) (G6 Bool) (H6 Bool) (I6 Bool) (J6 Bool) (K6 Bool) (L6 Bool) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Bool) (I7 Bool) (J7 Bool) (K7 Bool) (L7 Int) (M7 Bool) (N7 Bool) (O7 Bool) (P7 Bool) (Q7 Bool) (R7 Bool) (S7 Int) (T7 Bool) (U7 Bool) (V7 Bool) (W7 Bool) (X7 Bool) (Y7 Bool) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Bool) (V8 Bool) (W8 Bool) (X8 Bool) (Y8 Int) (Z8 Bool) (A9 Bool) (B9 Bool) (C9 Bool) (D9 Bool) (E9 Bool) (F9 Int) (G9 Bool) (H9 Bool) (I9 Bool) (J9 Bool) (K9 Bool) (L9 Bool) (M9 Int) (N9 Int) (O9 Int) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Int) (U9 Int) (V9 Int) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Bool) (I10 Bool) (J10 Bool) (K10 Bool) (L10 Int) (M10 Bool) (N10 Bool) (O10 Bool) (P10 Bool) (Q10 Bool) (R10 Bool) (S10 Int) (T10 Bool) (U10 Bool) (V10 Bool) (W10 Bool) (X10 Bool) (Y10 Bool) (Z10 Int) (A11 Int) (B11 Int) (C11 Int) (D11 Int) (E11 Int) (F11 Int) (G11 Int) (H11 Int) (I11 Int) (J11 Int) (K11 Int) (L11 Int) (M11 Int) (N11 Int) (O11 Int) (P11 Int) (Q11 Int) (R11 Int) (S11 Int) (T11 Int) (U11 Int) (V11 Bool) (W11 Bool) (X11 Bool) (Y11 Bool) (Z11 Bool) (A12 Bool) (v_313 Int) (v_314 Int) ) 
    (=>
      (and
        (main_1 v_313
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4)
        (let ((a!1 (or (not V11) (not (= (<= T5 4) A))))
      (a!2 (or (not B9) (not (= (<= L2 D3) X))))
      (a!3 (or (not O7) (not (= (<= P2 G3) G1))))
      (a!4 (or (not B6) (not (= (<= T2 J3) P1))))
      (a!5 (or (not O10) (not (= (<= H2 A3) O))))
      (a!6 (or (not O4) (not (= (<= X2 M3) Y1))))
      (a!7 (or (not T10) (not (= (<= 2 U11) M)))))
  (and (= 2 v_313)
       (or (and W5 K6) (and D6 H6) (and B6 I6) (and Z5 J6) (and U5 L6) (not G6))
       (or (and W8 K9) (not G9) (and L9 U8) (and J9 Z8) (and I9 B9) (and H9 D9))
       (or (and O10 V10)
           (and H10 Y10)
           (and X10 J10)
           (not T10)
           (and W10 M10)
           (and U10 Q10))
       (or (and Q4 U4) (and O4 V4) (and L4 W4) (and J4 X4) (not T4))
       (or (not Y11) (not V11) D)
       (or (and T10 Z11) (not X11) (and Y11 V11))
       (or (not F3) (not X8) (not U8))
       (or (not Y7) (not H7) (= S8 1))
       (or (not Y7) (not H7) (= Q8 N2))
       (or (not Y7) (not H7) (= M1 S8))
       (or (not Y7) (not H7) (= L1 R8))
       (or (not Y7) (not H7) (= K1 P8))
       (or (not Y7) (not H7) (= T8 Q8))
       (or (not Y7) (not H7) (= R8 O2))
       (or (not Y7) (not H7) (= P8 O2))
       (or E1 (not T7) (not (= M2 1)))
       (or (not T7) (not E1) (not (= M2 0)))
       (or E1 (not T7) (not A9))
       (or (not E1) (not T7) (not V8))
       (or (not Q7) (not U7) (= Z7 (- 1)))
       (or (= M1 C8) (not Q7) (not U7))
       (or (= L1 B8) (not Q7) (not U7))
       (or (= K1 Z7) (not Q7) (not U7))
       (or (= T8 A8) (not Q7) (not U7))
       (or (= C8 0) (not Q7) (not U7))
       (or (= B8 O2) (not Q7) (not U7))
       (or (= A8 S7) (not Q7) (not U7))
       (or (= G8 0) (not V7) (not O7))
       (or (= E8 N2) (not V7) (not O7))
       (or (= M1 G8) (not V7) (not O7))
       (or (= L1 F8) (not V7) (not O7))
       (or (= K1 D8) (not V7) (not O7))
       (or (= T8 E8) (not V7) (not O7))
       (or (= F8 P2) (not V7) (not O7))
       (or (not V7) (not O7) (= D8 (- 1)))
       (or H1 (not V7) (not O7))
       (or (not H1) (not O7) (not R7))
       (or (= K8 0) (not W7) (not M7))
       (or (= M1 K8) (not W7) (not M7))
       (or (= L1 J8) (not W7) (not M7))
       (or (= K1 H8) (not W7) (not M7))
       (or (= T8 I8) (not W7) (not M7))
       (or (= J8 O2) (not W7) (not M7))
       (or (= I8 N2) (not W7) (not M7))
       (or (not W7) (not M7) (= H8 (- 1)))
       (or I1 (not W7) (not M7))
       (or (not I1) (not P7) (not M7))
       (or (= M8 N2) (not J7) (not X7))
       (or (= M1 O8) (not J7) (not X7))
       (or (= L1 N8) (not J7) (not X7))
       (or (= K1 L8) (not J7) (not X7))
       (or (= T8 M8) (not J7) (not X7))
       (or (= O8 1) (not J7) (not X7))
       (or (= N8 O2) (not J7) (not X7))
       (or (= L8 L7) (not J7) (not X7))
       (or N1 (not G6) (not (= Q2 1)))
       (or (not G6) (not N1) (not (= Q2 0)))
       (or N1 (not G6) (not N7))
       (or (not N1) (not G6) (not I7))
       (or (= U1 O6) (not D6) (not H6))
       (or (= T1 M6) (not D6) (not H6))
       (or (= V1 P6) (not D6) (not H6))
       (or (= G7 N6) (not D6) (not H6))
       (or (= P6 0) (not D6) (not H6))
       (or (= O6 S2) (not D6) (not H6))
       (or (= N6 F6) (not D6) (not H6))
       (or (not D6) (not H6) (= M6 (- 1)))
       (or (= U1 S6) (not I6) (not B6))
       (or (= T1 Q6) (not I6) (not B6))
       (or (= S6 T2) (not I6) (not B6))
       (or (= R6 R2) (not I6) (not B6))
       (or (= V1 T6) (not I6) (not B6))
       (or (= G7 R6) (not I6) (not B6))
       (or (= T6 0) (not I6) (not B6))
       (or (not I6) (not B6) (= Q6 (- 1)))
       (or (= U1 W6) (not J6) (not Z5))
       (or (= T1 U6) (not J6) (not Z5))
       (or (= X6 0) (not J6) (not Z5))
       (or (= V6 R2) (not J6) (not Z5))
       (or (not J6) (not Z5) (= U6 (- 1)))
       (or (= V1 X6) (not J6) (not Z5))
       (or (= G7 V6) (not J6) (not Z5))
       (or (= W6 S2) (not J6) (not Z5))
       (or (= U1 A7) (not W5) (not K6))
       (or (= T1 Y6) (not W5) (not K6))
       (or (= B7 1) (not W5) (not K6))
       (or (= A7 S2) (not W5) (not K6))
       (or (= Y6 Y5) (not W5) (not K6))
       (or (= V1 B7) (not W5) (not K6))
       (or (= G7 Z6) (not W5) (not K6))
       (or (= Z6 R2) (not W5) (not K6))
       (or R1 (not J6) (not Z5))
       (or (not R1) (not C6) (not Z5))
       (or Q1 (not I6) (not B6))
       (or (not Q1) (not B6) (not E6))
       (or (= U G11) (not O10) (not V10))
       (or (= T F11) (not O10) (not V10))
       (or (= S D11) (not O10) (not V10))
       (or (= F11 H2) (not O10) (not V10))
       (or (not O10) (not V10) (= D11 (- 1)))
       (or (= T11 E11) (not O10) (not V10))
       (or (= G11 0) (not O10) (not V10))
       (or (= E11 F2) (not O10) (not V10))
       (or P (not O10) (not V10))
       (or (not P) (not O10) (not R10))
       (or (not Q) (not P10) (not M10))
       (or (= U S11) (not Y10) (not H10))
       (or (= T R11) (not Y10) (not H10))
       (or (= S P11) (not Y10) (not H10))
       (or (= T11 Q11) (not Y10) (not H10))
       (or (= S11 1) (not Y10) (not H10))
       (or (= R11 G2) (not Y10) (not H10))
       (or (= Q11 F2) (not Y10) (not H10))
       (or (= P11 G2) (not Y10) (not H10))
       (or C3 (not Y10) (not H10))
       (or (not C3) (not K10) (not H10))
       (or (not L9) (not U8) (= D1 F10))
       (or (not L9) (not U8) (= C1 E10))
       (or (not L9) (not U8) (= B1 C10))
       (or (not L9) (not U8) (= G10 D10))
       (or (not L9) (not U8) (= F10 1))
       (or (not L9) (not U8) (= E10 K2))
       (or (not L9) (not U8) (= D10 J2))
       (or (not L9) (not U8) (= C10 K2))
       (or F3 (not L9) (not U8))
       (or (not J9) (not Z8) (= W9 K2))
       (or (not J9) (not Z8) (= V9 J2))
       (or (not J9) (not Z8) (= U9 (- 1)))
       (or (not J9) (not Z8) (= D1 X9))
       (or (not J9) (not Z8) (= C1 W9))
       (or (not J9) (not Z8) (= B1 U9))
       (or (not J9) (not Z8) (= G10 V9))
       (or (not J9) (not Z8) (= X9 0))
       (or (not J9) (not Z8) Z)
       (or (not I9) (not B9) (= T9 0))
       (or (not I9) (not B9) (= S9 L2))
       (or (not I9) (not B9) (= R9 J2))
       (or (not I9) (not B9) (= Q9 (- 1)))
       (or (not I9) (not B9) (= D1 T9))
       (or (not I9) (not B9) (= C1 S9))
       (or (not I9) (not B9) (= B1 Q9))
       (or (not I9) (not B9) (= G10 R9))
       (or (not I9) (not B9) Y)
       (or (not H9) (not D9) (= N9 F9))
       (or (not H9) (not D9) (= M9 (- 1)))
       (or (not H9) (not D9) (= P9 0))
       (or (not H9) (not D9) (= O9 K2))
       (or (not H9) (not D9) (= D1 P9))
       (or (not H9) (not D9) (= C1 O9))
       (or (not H9) (not D9) (= B1 M9))
       (or (not H9) (not D9) (= G10 N9))
       (or V (not G9) (not (= I2 1)))
       (or (not G9) (not V) (not (= I2 0)))
       (or V (not G9) (not N10))
       (or (not V) (not G9) (not I10))
       (or (not E9) (not B9) (not Y))
       (or (not C9) (not Z8) (not Z))
       (or (= D1 B10) (not K9) (not W8))
       (or (= C1 A10) (not K9) (not W8))
       (or (= B1 Y9) (not K9) (not W8))
       (or (= G10 Z9) (not K9) (not W8))
       (or (= B10 1) (not K9) (not W8))
       (or (= A10 K2) (not K9) (not W8))
       (or (= Z9 J2) (not K9) (not W8))
       (or (= Y9 Y8) (not K9) (not W8))
       (or (= U1 E7) (not L6) (not U5))
       (or (= T1 C7) (not L6) (not U5))
       (or (= D7 R2) (not L6) (not U5))
       (or (= V1 F7) (not L6) (not U5))
       (or (= G7 D7) (not L6) (not U5))
       (or (= F7 1) (not L6) (not U5))
       (or (= E7 S2) (not L6) (not U5))
       (or (= C7 S2) (not L6) (not U5))
       (or W1 (not T4) (not (= U2 1)))
       (or (not T4) (not W1) (not (= U2 0)))
       (or W1 (not T4) (not A6))
       (or (not W1) (not T4) (not V5))
       (or (= Z4 S4) (not Q4) (not U4))
       (or (not Q4) (not U4) (= Y4 (- 1)))
       (or (= C2 Y4) (not Q4) (not U4))
       (or (= T5 B5) (not Q4) (not U4))
       (or (= S5 Z4) (not Q4) (not U4))
       (or (= C5 0) (not Q4) (not U4))
       (or (= B5 N4) (not Q4) (not U4))
       (or (= A5 W2) (not Q4) (not U4))
       (or (= E2 C5) (not Q4) (not U4))
       (or (= D2 A5) (not Q4) (not U4))
       (or (not O4) (not V4) (= C2 D5))
       (or (not O4) (not V4) (= T5 G5))
       (or (not O4) (not V4) (= S5 E5))
       (or (not O4) (not V4) (= E2 H5))
       (or (not O4) (not V4) (= D2 F5))
       (or (not O4) (not V4) (= H5 0))
       (or (not O4) (not V4) (= G5 N4))
       (or (not O4) (not V4) (= F5 X2))
       (or (not O4) (not V4) (= E5 V2))
       (or (not O4) (not V4) (= D5 (- 1)))
       (or (not O4) (not V4) Z1)
       (or (not O4) (not Z1) (not R4))
       (or (= C2 I5) (not W4) (not L4))
       (or (= T5 L5) (not W4) (not L4))
       (or (= S5 J5) (not W4) (not L4))
       (or (= M5 0) (not W4) (not L4))
       (or (= E2 M5) (not W4) (not L4))
       (or (= D2 K5) (not W4) (not L4))
       (or (= L5 N4) (not W4) (not L4))
       (or (= K5 W2) (not W4) (not L4))
       (or (= J5 V2) (not W4) (not L4))
       (or (not W4) (not L4) (= I5 (- 1)))
       (or A2 (not W4) (not L4))
       (or (not A2) (not L4) (not P4))
       (or (= C2 N5) (not X4) (not J4))
       (or (= T5 Q5) (not X4) (not J4))
       (or (= S5 O5) (not X4) (not J4))
       (or (= R5 1) (not X4) (not J4))
       (or (= Q5 Y2) (not X4) (not J4))
       (or (= P5 W2) (not X4) (not J4))
       (or (= O5 V2) (not X4) (not J4))
       (or (= N5 W2) (not X4) (not J4))
       (or (= E2 R5) (not X4) (not J4))
       (or (= D2 P5) (not X4) (not J4))
       (or (not B2) (not X4) (not J4))
       (or B2 (not J4) (not M4))
       (or L3 (not L6) (not U5))
       (or (not L3) (not X5) (not U5))
       (or I3 (not Y7) (not H7))
       (or (not I3) (not K7) (not H7))
       (or (not X10) (not J10) (= U O11))
       (or (not X10) (not J10) (= T N11))
       (or (not X10) (not J10) (= S L11))
       (or (not X10) (not J10) (= T11 M11))
       (or (not X10) (not J10) (= O11 1))
       (or (not X10) (not J10) (= N11 G2))
       (or (not X10) (not J10) (= M11 F2))
       (or (not X10) (not J10) (= L11 L10))
       (or (not W10) (not M10) (= U K11))
       (or (not W10) (not M10) (= T J11))
       (or (not W10) (not M10) (= S H11))
       (or (not W10) (not M10) (= T11 I11))
       (or (not W10) (not M10) (= K11 0))
       (or (not W10) (not M10) (= J11 G2))
       (or (not W10) (not M10) (= I11 F2))
       (or (not W10) (not M10) (= H11 (- 1)))
       (or (not W10) (not M10) Q)
       (or (not U10) (not Q10) (= U C11))
       (or (not U10) (not Q10) (= T B11))
       (or (not U10) (not Q10) (= S Z10))
       (or (not U10) (not Q10) (= C11 0))
       (or (not U10) (not Q10) (= A11 S10))
       (or (not U10) (not Q10) (= Z10 (- 1)))
       (or (not U10) (not Q10) (= T11 A11))
       (or (not U10) (not Q10) (= B11 G2))
       (or M (not T10) (not W11))
       (or (not M) (not Z11) (not T10))
       a!1
       (or (not V11) (= D (and A C)))
       (or (not V11) (= B (= U11 1)))
       (or (not V11) (not (= B C)))
       (or (not V11) (and T10 W11))
       (or (not U8) (and T7 V8))
       (or (not H7) (and G6 I7))
       (or B2 (not (= Z2 1)))
       (or (not B2) (not (= Z2 0)))
       (or (not Q10) (= N (= H2 A3)))
       (or (not Q10) (= S10 (ite N 1 F2)))
       (or (not Q10) (and O10 R10))
       (or (not D9) (= W (= L2 D3)))
       (or (not D9) (= F9 (ite W 1 J2)))
       (or (not D9) (and E9 B9))
       a!2
       (or (not B9) (= Y (or E3 X)))
       (or (not B9) (and C9 Z8))
       (or (not Z8) (= Z (= L2 (- 1))))
       (or (not Z8) (and T7 A9))
       (or (not Q7) (= F1 (= P2 G3)))
       (or (not Q7) (= S7 (ite F1 1 N2)))
       (or (not Q7) (and O7 R7))
       a!3
       (or (not O7) (= H1 (or H3 G1)))
       (or (not O7) (and M7 P7))
       (or (not M7) (= I1 (= P2 (- 1))))
       (or (not M7) (and G6 N7))
       (or (not J7) (= J1 (= O2 G3)))
       (or (not J7) (= L7 (ite J1 (- 1) O2)))
       (or (not J7) (and K7 H7))
       (or (not D6) (= O1 (= T2 J3)))
       (or (not D6) (= F6 (ite O1 1 R2)))
       (or (not D6) (and B6 E6))
       a!4
       (or (not B6) (= Q1 (or K3 P1)))
       (or (not B6) (and Z5 C6))
       (or (not Z5) (= R1 (= T2 (- 1))))
       (or (not Z5) (and T4 A6))
       (or (not W5) (= S1 (= S2 J3)))
       (or (not W5) (= Y5 (ite S1 (- 1) S2)))
       (or (not W5) (and U5 X5))
       a!5
       (or (not O10) (= P (or O B3)))
       (or (not O10) (and M10 P10))
       (or (not M10) (= Q (= H2 (- 1))))
       (or (not M10) (and G9 N10))
       (or (not J10) (= R (= G2 A3)))
       (or (not J10) (= L10 (ite R (- 1) G2)))
       (or (not J10) (and H10 K10))
       (or (not H10) (and G9 I10))
       (or (not W8) (= A1 (= K2 D3)))
       (or (not W8) (= Y8 (ite A1 (- 1) K2)))
       (or (not W8) (and X8 U8))
       (or (not U5) (and T4 V5))
       (or (not Q4) (= X1 (= X2 M3)))
       (or (not Q4) (= S4 (ite X1 1 V2)))
       (or (not Q4) (and O4 R4))
       a!6
       (or (not O4) (= Z1 (or N3 Y1)))
       (or (not O4) (and L4 P4))
       (or (not L4) (= A2 (= X2 (- 1))))
       (or (not L4) (= N4 (+ 1 Y2)))
       (or (not L4) (and J4 M4))
       (or (not K4) (and X11 A12))
       a!7
       (or (not T10) (= K (+ I J)))
       (or (not T10) (= J G10))
       (or (not T10) (= I (+ G H)))
       (or (not T10) (= H T8))
       (or (not T10) (= G (+ F E)))
       (or (not T10) (= F G7))
       (or (not T10) (= L T11))
       (or (not T10) (= E S5))
       (or (not T10) (= U11 (+ K L)))
       (= K4 true)
       (or (and J7 X7) (and Q7 U7) (and O7 V7) (and M7 W7) (not T7) (and Y7 H7))
       (= 3 v_314)))
      )
      (main_1 v_314
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
        V3
        W3
        X3
        Y3
        Z3
        A4
        B4
        C4
        D4
        E4
        F4
        G4
        H4
        I4)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Bool) (X Bool) (Y Int) (Z Bool) (A1 Bool) (B1 Int) (C1 Bool) (D1 Bool) (E1 Int) (F1 Bool) (G1 Bool) (H1 Int) (I1 Bool) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (v_56 Int) ) 
    (=>
      (and
        (main_1 v_56
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
        U1
        V1
        W1
        X1
        Y1
        Z1
        A2
        B2
        C2
        D2)
        (= 3 v_56)
      )
      false
    )
  )
)

(check-sat)
(exit)
