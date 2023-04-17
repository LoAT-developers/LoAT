; ./seahorn/./sv_comp_flat_small/seq-mthreaded/pals_lcr.6_false-unreach-call.1.ufo.BOUNDED-12.pals.c.flat_000.smt2
(set-logic HORN)

(declare-fun |main_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (v_32 Int) ) 
    (=>
      (and
        (and true (= 0 v_32))
      )
      (main_1 v_32
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
        F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Bool) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Bool) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) (N2 Bool) (O2 Bool) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Bool) (T2 Bool) (U2 Bool) (V2 Bool) (W2 Bool) (X2 Bool) (Y2 Bool) (Z2 Bool) (A3 Bool) (B3 Bool) (C3 Bool) (D3 Bool) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Bool) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Bool) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Bool) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Bool) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Bool) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Bool) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Bool) (P5 Int) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Bool) (V5 Bool) (W5 Bool) (X5 Bool) (Y5 Bool) (Z5 Bool) (A6 Bool) (B6 Bool) (C6 Bool) (D6 Bool) (E6 Bool) (F6 Bool) (G6 Bool) (H6 Bool) (I6 Bool) (J6 Bool) (K6 Bool) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Bool) (P6 Bool) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (v_218 Int) (v_219 Int) ) 
    (=>
      (and
        (main_1 v_218
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
        (let ((a!1 (or (not Y5) (not (= (= G5 L5) S1))))
      (a!2 (or (not Y5) (not (= (<= L5 (- 1)) H))))
      (a!3 (or (not W5) (not (= (<= G5 (- 1)) V1))))
      (a!4 (or (not U5) (not (= (<= B5 (- 1)) C2))))
      (a!5 (or (not S5) (not (= (<= W4 (- 1)) J2))))
      (a!6 (or (not Q5) (not (= (<= R4 (- 1)) Q2)))))
  (and (= 0 v_218)
       (= C3 (and A3 B3))
       (= B3 (= O4 M4))
       (= A3 (and Y2 Z2))
       (= Z2 (= N4 0))
       (= Y2 (and W2 X2))
       (= W2 (= L4 0))
       (= P5 (ite O5 1 0))
       (= K5 (ite J5 1 0))
       (= F5 (ite E5 1 0))
       (= A5 (ite Z4 1 0))
       (= V4 (ite U4 1 0))
       (= Q4 (ite P4 1 0))
       (or (and Y5 C6)
           (and W5 D6)
           (and U5 E6)
           (and S5 F6)
           (and Q5 G6)
           (and K4 H6)
           (not B6))
       (or (= D7 Y4) (not B6) (not P6))
       (or (= C7 X4) (not B6) (not P6))
       (or (= B7 F5) (not B6) (not P6))
       (or (= A7 (- 1)) (not B6) (not P6))
       (or (= Z6 D5) (not B6) (not P6))
       (or (= Y6 C5) (not B6) (not P6))
       (or (= X6 K5) (not B6) (not P6))
       (or (= W6 (- 1)) (not B6) (not P6))
       (or (= V6 I5) (not B6) (not P6))
       (or (= U6 H5) (not B6) (not P6))
       (or (= T6 P5) (not B6) (not P6))
       (or (= S6 (- 1)) (not B6) (not P6))
       (or (= R6 N5) (not B6) (not P6))
       (or (= Q6 M5) (not B6) (not P6))
       (or (= F O7) (not B6) (not P6))
       (or (= E J7) (not B6) (not P6))
       (or (= D F7) (not B6) (not P6))
       (or (= C B7) (not B6) (not P6))
       (or (= B X6) (not B6) (not P6))
       (or (= A T6) (not B6) (not P6))
       (or (= J8 P7) (not B6) (not P6))
       (or (= I8 N7) (not B6) (not P6))
       (or (= H8 M7) (not B6) (not P6))
       (or (= G8 L7) (not B6) (not P6))
       (or (= F8 K7) (not B6) (not P6))
       (or (= E8 I7) (not B6) (not P6))
       (or (= D8 H7) (not B6) (not P6))
       (or (= C8 G7) (not B6) (not P6))
       (or (= B8 E7) (not B6) (not P6))
       (or (= A8 D7) (not B6) (not P6))
       (or (= Z7 C7) (not B6) (not P6))
       (or (= Y7 A7) (not B6) (not P6))
       (or (= X7 Z6) (not B6) (not P6))
       (or (= W7 Y6) (not B6) (not P6))
       (or (= V7 W6) (not B6) (not P6))
       (or (= U7 V6) (not B6) (not P6))
       (or (= T7 U6) (not B6) (not P6))
       (or (= S7 S6) (not B6) (not P6))
       (or (= R7 R6) (not B6) (not P6))
       (or (= Q7 Q6) (not B6) (not P6))
       (or (= P7 0) (not B6) (not P6))
       (or (= O7 Q4) (not B6) (not P6))
       (or (= N7 L4) (not B6) (not P6))
       (or (= M7 (- 1)) (not B6) (not P6))
       (or (= L7 O4) (not B6) (not P6))
       (or (= K7 N4) (not B6) (not P6))
       (or (= J7 V4) (not B6) (not P6))
       (or (= I7 (- 1)) (not B6) (not P6))
       (or (= H7 T4) (not B6) (not P6))
       (or (= G7 S4) (not B6) (not P6))
       (or (= F7 A5) (not B6) (not P6))
       (or (= E7 (- 1)) (not B6) (not P6))
       (or (= I6 A6) (not Y5) (not C6))
       (or (= D3 I6) (not Y5) (not C6))
       (or (= D3 J6) (not W5) (not D6))
       (or (not J6) (not W5) (not D6))
       (or (= D3 K6) (not U5) (not E6))
       (or (not K6) (not U5) (not E6))
       (or (= D3 L6) (not S5) (not F6))
       (or (not L6) (not S5) (not F6))
       (or (= D3 M6) (not Q5) (not G6))
       (or (not M6) (not Q5) (not G6))
       (or (= D3 N6) (not K4) (not H6))
       (or (not N6) (not K4) (not H6))
       (or (not C3) (not K4) (not H6))
       (or C3 (not R5) (not K4))
       (or (not V2) (not Q5) (not G6))
       (or V2 (not T5) (not Q5))
       (or (not O2) (not S5) (not F6))
       (or O2 (not V5) (not S5))
       (or (not H2) (not U5) (not E6))
       (or H2 (not X5) (not U5))
       (or (not A2) (not W5) (not D6))
       (or A2 (not Z5) (not W5))
       (or (not O6) (and B6 P6))
       a!1
       a!2
       (or (not Y5) (= A6 (and S1 T1)))
       (or (not Y5) (not (= O5 N)))
       (or (not Y5) (not (= J5 G)))
       (or (not Y5) (= R1 (or P1 Q1)))
       (or (not Y5) (not (= R1 T1)))
       (or (not Y5) (= Q1 (= B5 L5)))
       (or (not Y5) (= P1 (or N1 O1)))
       (or (not Y5) (= O1 (= B5 G5)))
       (or (not Y5) (= N1 (or L1 M1)))
       (or (not Y5) (= M1 (= W4 L5)))
       (or (not Y5) (= L1 (or J1 K1)))
       (or (not Y5) (= K1 (= W4 G5)))
       (or (not Y5) (= J1 (or H1 I1)))
       (or (not Y5) (= I1 (= W4 B5)))
       (or (not Y5) (= H1 (or F1 G1)))
       (or (not Y5) (= G1 (= R4 L5)))
       (or (not Y5) (= F1 (or D1 E1)))
       (or (not Y5) (= E1 (= R4 G5)))
       (or (not Y5) (= D1 (or B1 C1)))
       (or (not Y5) (= C1 (= R4 B5)))
       (or (not Y5) (= B1 (or Z A1)))
       (or (not Y5) (= A1 (= R4 W4)))
       (or (not Y5) (= Z (or X Y)))
       (or (not Y5) (= Y (= M4 L5)))
       (or (not Y5) (= X (or V W)))
       (or (not Y5) (= W (= M4 G5)))
       (or (not Y5) (= V (or T U)))
       (or (not Y5) (= U (= M4 B5)))
       (or (not Y5) (= T (or R S)))
       (or (not Y5) (= S (= M4 W4)))
       (or (not Y5) (= R (or P Q)))
       (or (not Y5) (= Q (= M4 R4)))
       (or (not Y5) (= O (and M N)))
       (or (not Y5) (not (= O P)))
       (or (not Y5) (= M (and K L)))
       (or (not Y5) (= L (= N5 L5)))
       (or (not Y5) (= K (and I J)))
       (or (not Y5) (= J (= M5 0)))
       (or (not Y5) (= I (and G H)))
       (or (not Y5) (and W5 Z5))
       a!3
       (or (not W5) (not (= E5 U1)))
       (or (not W5) (= A2 (and Y1 Z1)))
       (or (not W5) (= Z1 (= I5 G5)))
       (or (not W5) (= Y1 (and W1 X1)))
       (or (not W5) (= X1 (= H5 0)))
       (or (not W5) (= W1 (and U1 V1)))
       (or (not W5) (and U5 X5))
       a!4
       (or (not U5) (not (= Z4 B2)))
       (or (not U5) (= H2 (and F2 G2)))
       (or (not U5) (= G2 (= D5 B5)))
       (or (not U5) (= F2 (and D2 E2)))
       (or (not U5) (= E2 (= C5 0)))
       (or (not U5) (= D2 (and B2 C2)))
       (or (not U5) (and S5 V5))
       a!5
       (or (not S5) (not (= U4 I2)))
       (or (not S5) (= O2 (and M2 N2)))
       (or (not S5) (= N2 (= Y4 W4)))
       (or (not S5) (= M2 (and K2 L2)))
       (or (not S5) (= L2 (= X4 0)))
       (or (not S5) (= K2 (and I2 J2)))
       (or (not S5) (and Q5 T5))
       a!6
       (or (not Q5) (not (= P4 P2)))
       (or (not Q5) (= V2 (and T2 U2)))
       (or (not Q5) (= U2 (= T4 R4)))
       (or (not Q5) (= T2 (and R2 S2)))
       (or (not Q5) (= S2 (= S4 0)))
       (or (not Q5) (= R2 (and P2 Q2)))
       (or (not Q5) (and K4 R5))
       (or D3 (not B6))
       (= O6 true)
       (not (= (<= M4 (- 1)) X2))
       (= 1 v_219)))
      )
      (main_1 v_219
        J8
        Q7
        R7
        S7
        A
        T7
        U7
        V7
        B
        W7
        X7
        Y7
        C
        Z7
        A8
        B8
        D
        C8
        D8
        E8
        E
        F8
        G8
        H8
        I8
        F
        L5
        G5
        B5
        W4
        R4
        M4)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Int) (U Int) (V Int) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Int) (B1 Int) (C1 Int) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Int) (I1 Int) (J1 Int) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Bool) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Int) (N3 Int) (O3 Int) (P3 Int) (Q3 Int) (R3 Int) (S3 Bool) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Int) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Bool) (O5 Bool) (P5 Int) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Int) (V5 Int) (W5 Bool) (X5 Bool) (Y5 Bool) (Z5 Bool) (A6 Bool) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Bool) (Y6 Bool) (Z6 Bool) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Int) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Bool) (I7 Bool) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Bool) (B8 Bool) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Bool) (G8 Int) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Bool) (E9 Bool) (F9 Bool) (G9 Bool) (H9 Bool) (I9 Bool) (J9 Int) (K9 Bool) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Bool) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Int) (U9 Int) (V9 Int) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Bool) (H10 Bool) (I10 Bool) (J10 Bool) (K10 Bool) (L10 Bool) (M10 Int) (N10 Bool) (O10 Bool) (P10 Bool) (Q10 Bool) (R10 Bool) (S10 Int) (T10 Int) (U10 Int) (V10 Int) (W10 Int) (X10 Int) (Y10 Int) (Z10 Int) (A11 Int) (B11 Int) (C11 Int) (D11 Int) (E11 Int) (F11 Int) (G11 Int) (H11 Int) (I11 Int) (J11 Bool) (K11 Bool) (L11 Bool) (M11 Bool) (N11 Bool) (O11 Bool) (P11 Int) (Q11 Bool) (R11 Bool) (S11 Bool) (T11 Bool) (U11 Bool) (V11 Int) (W11 Int) (X11 Int) (Y11 Int) (Z11 Int) (A12 Int) (B12 Int) (C12 Int) (D12 Int) (E12 Int) (F12 Int) (G12 Int) (H12 Int) (I12 Int) (J12 Int) (K12 Int) (L12 Int) (M12 Int) (N12 Int) (O12 Int) (P12 Bool) (Q12 Bool) (R12 Bool) (S12 Bool) (T12 Bool) (U12 Int) (V12 Bool) (W12 Bool) (v_335 Int) (v_336 Int) ) 
    (=>
      (and
        (main_1 v_335
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
        (let ((a!1 (or (not P12) (not (= (<= W6 5) R12))))
      (a!2 (or (not Q11) (not (= (<= 2 O12) O))))
      (a!3 (or (not L11) (not (= (<= P2 M3) Q))))
      (a!4 (or (not F9) (not (= (<= X2 O3) E1))))
      (a!5 (or (not C8) (not (= (<= B3 P3) L1))))
      (a!6 (or (not I10) (not (= (<= T2 N3) X))))
      (a!7 (or (not Z6) (not (= (<= F3 Q3) S1))))
      (a!8 (or (not Q5) (not (= (<= J3 R3) Z1)))))
  (and (= 1 v_335)
       (or (and N11 R11) (and L11 S11) (and J11 T11) (and N10 U11) (not Q11))
       (or (and H9 L9) (and D9 N9) (and H8 O9) (not K9) (and M9 F9))
       (or (and E8 I8) (and C8 J8) (and A8 K8) (and E7 L8) (not H8))
       (or (and K10 O10) (and I10 P10) (and G10 Q10) (not N10) (and R10 K9))
       (or (and B7 F7) (and Z6 G7) (and X6 H7) (and W5 I7) (not E7))
       (or (and S5 X5) (and Q5 Y5) (and N5 Z5) (not W5) (and A6 S3))
       (or (= M5 S4) (not S12) (not W12))
       (or (= L5 Q4) (not S12) (not W12))
       (or (= K5 P4) (not S12) (not W12))
       (or (= J5 O4) (not S12) (not W12))
       (or (= I5 N4) (not S12) (not W12))
       (or (= H5 L4) (not S12) (not W12))
       (or (= G5 K4) (not S12) (not W12))
       (or (= F5 J4) (not S12) (not W12))
       (or (= E5 H4) (not S12) (not W12))
       (or (= D5 G4) (not S12) (not W12))
       (or (= C5 F4) (not S12) (not W12))
       (or (= B5 D4) (not S12) (not W12))
       (or (= A5 C4) (not S12) (not W12))
       (or (= Z4 B4) (not S12) (not W12))
       (or (= Y4 Z3) (not S12) (not W12))
       (or (= X4 Y3) (not S12) (not W12))
       (or (= W4 X3) (not S12) (not W12))
       (or (= V4 V3) (not S12) (not W12))
       (or (= U4 U3) (not S12) (not W12))
       (or (= T4 T3) (not S12) (not W12))
       (or (= M4 X1) (not S12) (not W12))
       (or (= L4 D2) (not S12) (not W12))
       (or (= K4 W1) (not S12) (not W12))
       (or (= J4 Z7) (not S12) (not W12))
       (or (= I4 Q1) (not S12) (not W12))
       (or (= H4 V1) (not S12) (not W12))
       (or (= G4 P1) (not S12) (not W12))
       (or (= F4 C9) (not S12) (not W12))
       (or (= E4 J1) (not S12) (not W12))
       (or (= D4 O1) (not S12) (not W12))
       (or (= C4 I1) (not S12) (not W12))
       (or (= B4 F10) (not S12) (not W12))
       (or (= A4 C1) (not S12) (not W12))
       (or (= Z3 H1) (not S12) (not W12))
       (or (= Y3 B1) (not S12) (not W12))
       (or (= X3 I11) (not S12) (not W12))
       (or (= W3 V) (not S12) (not W12))
       (or (= V3 A1) (not S12) (not W12))
       (or (= U3 U) (not S12) (not W12))
       (or (= T3 L12) (not S12) (not W12))
       (or (= L2 R4) (not S12) (not W12))
       (or (= K2 M4) (not S12) (not W12))
       (or (= J2 I4) (not S12) (not W12))
       (or (= I2 E4) (not S12) (not W12))
       (or (= H2 A4) (not S12) (not W12))
       (or (= G2 W3) (not S12) (not W12))
       (or (= S4 U12) (not S12) (not W12))
       (or (= R4 F2) (not S12) (not W12))
       (or (= Q4 W6) (not S12) (not W12))
       (or (= P4 T) (not S12) (not W12))
       (or (= O4 E2) (not S12) (not W12))
       (or (= N4 V6) (not S12) (not W12))
       (or (= V Y11) (not N11) (not R11))
       (or (= U X11) (not N11) (not R11))
       (or (= T V11) (not N11) (not R11))
       (or (= L12 W11) (not N11) (not R11))
       (or (= Y11 0) (not N11) (not R11))
       (or (= X11 O2) (not N11) (not R11))
       (or (= W11 P11) (not N11) (not R11))
       (or (= V11 (- 1)) (not N11) (not R11))
       (or (= V C12) (not L11) (not S11))
       (or (= U B12) (not L11) (not S11))
       (or (= T Z11) (not L11) (not S11))
       (or (= L12 A12) (not L11) (not S11))
       (or (= C12 0) (not L11) (not S11))
       (or (= B12 P2) (not L11) (not S11))
       (or (= A12 N2) (not L11) (not S11))
       (or (= Z11 (- 1)) (not L11) (not S11))
       (or (= V G12) (not J11) (not T11))
       (or (= U F12) (not J11) (not T11))
       (or (= T D12) (not J11) (not T11))
       (or (= L12 E12) (not J11) (not T11))
       (or (= G12 0) (not J11) (not T11))
       (or (= F12 O2) (not J11) (not T11))
       (or (= E12 N2) (not J11) (not T11))
       (or (= D12 (- 1)) (not J11) (not T11))
       (or (= F10 Y9) (not D9) (not N9))
       (or (= J1 A10) (not D9) (not N9))
       (or (= I1 Z9) (not D9) (not N9))
       (or (= H1 X9) (not D9) (not N9))
       (or (= A10 0) (not D9) (not N9))
       (or (= Z9 W2) (not D9) (not N9))
       (or (= Y9 V2) (not D9) (not N9))
       (or (= X9 (- 1)) (not D9) (not N9))
       (or (= F10 C10) (not H8) (not O9))
       (or (= E10 1) (not H8) (not O9))
       (or (= D10 W2) (not H8) (not O9))
       (or (= B10 W2) (not H8) (not O9))
       (or (= J1 E10) (not H8) (not O9))
       (or (= I1 D10) (not H8) (not O9))
       (or (= H1 B10) (not H8) (not O9))
       (or (= C10 V2) (not H8) (not O9))
       (or (= C9 N8) (not E8) (not I8))
       (or (= Q1 P8) (not E8) (not I8))
       (or (= P1 O8) (not E8) (not I8))
       (or (= O1 M8) (not E8) (not I8))
       (or (= P8 0) (not E8) (not I8))
       (or (= O8 A3) (not E8) (not I8))
       (or (= N8 G8) (not E8) (not I8))
       (or (= M8 (- 1)) (not E8) (not I8))
       (or (= C9 R8) (not C8) (not J8))
       (or (= Q1 T8) (not C8) (not J8))
       (or (= P1 S8) (not C8) (not J8))
       (or (= O1 Q8) (not C8) (not J8))
       (or (= T8 0) (not C8) (not J8))
       (or (= S8 B3) (not C8) (not J8))
       (or (= R8 Z2) (not C8) (not J8))
       (or (= Q8 (- 1)) (not C8) (not J8))
       (or (= C9 V8) (not A8) (not K8))
       (or (= X8 0) (not A8) (not K8))
       (or (= Q1 X8) (not A8) (not K8))
       (or (= P1 W8) (not A8) (not K8))
       (or (= O1 U8) (not A8) (not K8))
       (or (= W8 A3) (not A8) (not K8))
       (or (= V8 Z2) (not A8) (not K8))
       (or (= U8 (- 1)) (not A8) (not K8))
       (or M1 (not A8) (not K8))
       (or (not M1) (not A8) (not D8))
       (or L1 (not C8) (not J8))
       (or (not L1) (not C8) (not F8))
       (or G1 (not (= Y2 1)) (not H8))
       (or (not G1) (not (= Y2 0)) (not H8))
       (or (not G1) (not H8) (not O9))
       (or G1 (not H8) (not E9))
       (or F1 (not D9) (not N9))
       (or (not F1) (not D9) (not G9))
       (or (not E1) (not F9) (not I9))
       (or Z (not (= U2 1)) (not K9))
       (or (not Z) (not (= U2 0)) (not K9))
       (or R (not J11) (not T11))
       (or (not R) (not J11) (not M11))
       (or Q (not L11) (not S11))
       (or (not Q) (not L11) (not O11))
       (or O (not Q11) (not Q12))
       (or F (not P12) (not T12))
       (or (not C) (not S12) (not W12))
       (or (not R10) (not K9) (= C1 H11))
       (or (not R10) (not K9) (= B1 G11))
       (or (not R10) (not K9) (= A1 E11))
       (or (not R10) (not K9) (= I11 F11))
       (or (not R10) (not K9) (= H11 1))
       (or (not R10) (not K9) (= G11 S2))
       (or (not R10) (not K9) (= F11 R2))
       (or (not R10) (not K9) (= E11 S2))
       (or (not Z) (not R10) (not K9))
       (or (= V K12) (not N10) (not U11))
       (or (= U J12) (not N10) (not U11))
       (or (= T H12) (not N10) (not U11))
       (or (= L12 I12) (not N10) (not U11))
       (or (= K12 1) (not N10) (not U11))
       (or (= J12 O2) (not N10) (not U11))
       (or (= I12 N2) (not N10) (not U11))
       (or (= H12 O2) (not N10) (not U11))
       (or S (not (= Q2 1)) (not N10))
       (or (not N10) (not S) (not (= Q2 0)))
       (or (not S) (not N10) (not U11))
       (or S (not N10) (not K11))
       (or (= V10 0) (not K10) (not O10))
       (or (= U10 S2) (not K10) (not O10))
       (or (= T10 M10) (not K10) (not O10))
       (or (not K10) (not O10) (= S10 (- 1)))
       (or (= C1 V10) (not K10) (not O10))
       (or (= B1 U10) (not K10) (not O10))
       (or (= A1 S10) (not K10) (not O10))
       (or (= I11 T10) (not K10) (not O10))
       (or (= Z10 0) (not I10) (not P10))
       (or (= Y10 T2) (not I10) (not P10))
       (or (= X10 R2) (not I10) (not P10))
       (or (not I10) (not P10) (= W10 (- 1)))
       (or (= C1 Z10) (not I10) (not P10))
       (or (= B1 Y10) (not I10) (not P10))
       (or (= A1 W10) (not I10) (not P10))
       (or (= I11 X10) (not I10) (not P10))
       (or X (not I10) (not P10))
       (or (not X) (not I10) (not L10))
       (or Z (not H10) (not K9))
       (or (= C11 S2) (not G10) (not Q10))
       (or (= B11 R2) (not G10) (not Q10))
       (or (not G10) (not Q10) (= A11 (- 1)))
       (or (= C1 D11) (not G10) (not Q10))
       (or (= B1 C11) (not G10) (not Q10))
       (or (= A1 A11) (not G10) (not Q10))
       (or (= I11 B11) (not G10) (not Q10))
       (or (= D11 0) (not G10) (not Q10))
       (or Y (not G10) (not Q10))
       (or (not Y) (not G10) (not J10))
       (or (not M9) (not F9) (= F10 U9))
       (or (not M9) (not F9) (= W9 0))
       (or (not M9) (not F9) (= J1 W9))
       (or (not M9) (not F9) (= I1 V9))
       (or (not M9) (not F9) (= H1 T9))
       (or (not M9) (not F9) (= V9 X2))
       (or (not M9) (not F9) (= U9 V2))
       (or (not M9) (not F9) (= T9 (- 1)))
       (or E1 (not F9) (not M9))
       (or (= F10 Q9) (not H9) (not L9))
       (or (= R9 W2) (not H9) (not L9))
       (or (= J1 S9) (not H9) (not L9))
       (or (= I1 R9) (not H9) (not L9))
       (or (= H1 P9) (not H9) (not L9))
       (or (= S9 0) (not H9) (not L9))
       (or (= Q9 J9) (not H9) (not L9))
       (or (= P9 (- 1)) (not H9) (not L9))
       (or (= C9 Z8) (not E7) (not L8))
       (or (= Q1 B9) (not E7) (not L8))
       (or (= P1 A9) (not E7) (not L8))
       (or (= O1 Y8) (not E7) (not L8))
       (or (= B9 1) (not E7) (not L8))
       (or (= A9 A3) (not E7) (not L8))
       (or (= Z8 Z2) (not E7) (not L8))
       (or (= Y8 A3) (not E7) (not L8))
       (or N1 (not (= C3 1)) (not E7))
       (or (not E7) (not N1) (not (= C3 0)))
       (or (not N1) (not E7) (not L8))
       (or N1 (not E7) (not B8))
       (or (not B7) (= M7 0) (not F7))
       (or (not B7) (= L7 E3) (not F7))
       (or (not B7) (= K7 D7) (not F7))
       (or (not B7) (= J7 (- 1)) (not F7))
       (or (not B7) (= X1 M7) (not F7))
       (or (not B7) (= W1 L7) (not F7))
       (or (not B7) (= V1 J7) (not F7))
       (or (not B7) (= Z7 K7) (not F7))
       (or (= Q7 0) (not Z6) (not G7))
       (or (= P7 F3) (not Z6) (not G7))
       (or (= O7 D3) (not Z6) (not G7))
       (or (= N7 (- 1)) (not Z6) (not G7))
       (or (= X1 Q7) (not Z6) (not G7))
       (or (= W1 P7) (not Z6) (not G7))
       (or (= V1 N7) (not Z6) (not G7))
       (or (= Z7 O7) (not Z6) (not G7))
       (or S1 (not Z6) (not G7))
       (or (not S1) (not Z6) (not C7))
       (or (= X1 U7) (not X6) (not H7))
       (or (= W1 T7) (not X6) (not H7))
       (or (= V1 R7) (not X6) (not H7))
       (or (= Z7 S7) (not X6) (not H7))
       (or (= U7 0) (not X6) (not H7))
       (or (= T7 E3) (not X6) (not H7))
       (or (= S7 D3) (not X6) (not H7))
       (or (= R7 (- 1)) (not X6) (not H7))
       (or T1 (not X6) (not H7))
       (or (not T1) (not X6) (not A7))
       (or (not A6) (not S3) (= W6 T6))
       (or (not A6) (not S3) (= V6 R6))
       (or (not A6) (not S3) (= U6 1))
       (or (not A6) (not S3) (= T6 K3))
       (or (not A6) (not S3) (= S6 I3))
       (or (not A6) (not S3) (= R6 H3))
       (or (not A6) (not S3) (= Q6 I3))
       (or (not A6) (not S3) (= F2 U6))
       (or (not A6) (not S3) (= E2 S6))
       (or (not A6) (not S3) (= D2 Q6))
       (or (not C2) (not S3) (not A6))
       (or U1 (not (= G3 1)) (not W5))
       (or (not W5) (not U1) (not (= G3 0)))
       (or (not I7) (= X1 Y7) (not W5))
       (or (not I7) (= W1 X7) (not W5))
       (or (not I7) (= V1 V7) (not W5))
       (or (not I7) (= Z7 W7) (not W5))
       (or (not I7) (= Y7 1) (not W5))
       (or (not I7) (= X7 E3) (not W5))
       (or (not I7) (= W7 D3) (not W5))
       (or (not I7) (= V7 E3) (not W5))
       (or (not I7) (not U1) (not W5))
       (or U1 (not W5) (not Y6))
       (or (= W6 E6) (not S5) (not X5))
       (or (= V6 C6) (not S5) (not X5))
       (or (= F6 0) (not S5) (not X5))
       (or (= E6 P5) (not S5) (not X5))
       (or (= D6 V5) (not S5) (not X5))
       (or (= C6 U5) (not S5) (not X5))
       (or (= B6 (- 1)) (not S5) (not X5))
       (or (= F2 F6) (not S5) (not X5))
       (or (= E2 D6) (not S5) (not X5))
       (or (= D2 B6) (not S5) (not X5))
       (or (= W6 J6) (not Q5) (not Y5))
       (or (= V6 H6) (not Q5) (not Y5))
       (or (= K6 0) (not Q5) (not Y5))
       (or (= J6 P5) (not Q5) (not Y5))
       (or (= I6 J3) (not Q5) (not Y5))
       (or (= H6 H3) (not Q5) (not Y5))
       (or (= G6 (- 1)) (not Q5) (not Y5))
       (or (= F2 K6) (not Q5) (not Y5))
       (or (= E2 I6) (not Q5) (not Y5))
       (or (= D2 G6) (not Q5) (not Y5))
       (or Z1 (not Q5) (not Y5))
       (or (not Z1) (not Q5) (not T5))
       (or C2 (not S3) (not O5))
       (or (= W6 O6) (not N5) (not Z5))
       (or (= V6 M6) (not N5) (not Z5))
       (or (= P6 0) (not N5) (not Z5))
       (or (= O6 P5) (not N5) (not Z5))
       (or (= N6 I3) (not N5) (not Z5))
       (or (= M6 H3) (not N5) (not Z5))
       (or (= L6 (- 1)) (not N5) (not Z5))
       (or (= F2 P6) (not N5) (not Z5))
       (or (= E2 N6) (not N5) (not Z5))
       (or (= D2 L6) (not N5) (not Z5))
       (or A2 (not N5) (not Z5))
       (or (not A2) (not N5) (not R5))
       (or (not V12) (and S12 W12))
       (or (not S12) (= C (and B R12)))
       (or (not S12) (= A (= O12 1)))
       (or (not S12) (not (= A B)))
       (or (not S12) (= U12 (+ 1 M2)))
       (or (not S12) (and P12 T12))
       a!1
       (or (not P12) (= F (or E R12)))
       (or (not P12) (= E (= M12 D)))
       (or (not P12) (= D (* (- 1) N12)))
       (or (not P12) (and Q11 Q12))
       a!2
       (or (not Q11) (= N I11))
       (or (not Q11) (= M (+ K L)))
       (or (not Q11) (= L F10))
       (or (not Q11) (= K (+ I J)))
       (or (not Q11) (= J C9))
       (or (not Q11) (= I (+ H G)))
       (or (not Q11) (= H Z7))
       (or (not Q11) (= G V6))
       (or (not Q11) (= O12 (+ N12 M12)))
       (or (not Q11) (= N12 L12))
       (or (not Q11) (= M12 (+ M N)))
       (or (not N11) (= P (= P2 M3)))
       (or (not N11) (= P11 (ite P 1 N2)))
       (or (not N11) (and L11 O11))
       a!3
       (or (not L11) (and J11 M11))
       (or (not J11) (= R (= P2 (- 1))))
       (or (not J11) (and N10 K11))
       a!4
       (or (not F9) (and D9 G9))
       (or (not D9) (= F1 (= X2 (- 1))))
       (or (not D9) (and H8 E9))
       (or (not E8) (= K1 (= B3 P3)))
       (or (not E8) (= G8 (ite K1 1 Z2)))
       (or (not E8) (and C8 F8))
       a!5
       (or (not C8) (and A8 D8))
       (or (not A8) (= M1 (= B3 (- 1))))
       (or (not A8) (and E7 B8))
       (or C2 (not (= L3 1)))
       (or (not C2) (not (= L3 0)))
       (or (not K10) (= W (= T2 N3)))
       (or (not K10) (= M10 (ite W 1 R2)))
       (or (not K10) (and I10 L10))
       a!6
       (or (not I10) (and G10 J10))
       (or (not G10) (= Y (= T2 (- 1))))
       (or (not G10) (and H10 K9))
       (or (not H9) (= D1 (= X2 O3)))
       (or (not H9) (= J9 (ite D1 1 V2)))
       (or (not H9) (and F9 I9))
       (or (not B7) (= R1 (= F3 Q3)))
       (or (not B7) (= D7 (ite R1 1 D3)))
       (or (not B7) (and Z6 C7))
       a!7
       (or (not Z6) (and X6 A7))
       (or (not X6) (= T1 (= F3 (- 1))))
       (or (not X6) (and W5 Y6))
       (or (not S5) (= Y1 (= J3 R3)))
       (or (not S5) (= V5 (ite Y1 I3 J3)))
       (or (not S5) (= U5 (ite Y1 1 H3)))
       (or (not S5) (and Q5 T5))
       a!8
       (or (not Q5) (and N5 R5))
       (or (not N5) (= A2 (= J3 (- 1))))
       (or (not N5) (= P5 (+ 1 K3)))
       (or (not N5) (and O5 S3))
       (= V12 true)
       (= B2 true)
       (not (= (<= 12 M2) B2))
       (= 1 v_336)))
      )
      (main_1 v_336
        M5
        T4
        U4
        V4
        G2
        W4
        X4
        Y4
        H2
        Z4
        A5
        B5
        I2
        C5
        D5
        E5
        J2
        F5
        G5
        H5
        K2
        I5
        J5
        K5
        L5
        L2
        M3
        N3
        O3
        P3
        Q3
        R3)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Int) (E Bool) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Int) (U Int) (V Int) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Int) (B1 Int) (C1 Int) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Int) (I1 Int) (J1 Int) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Int) (P1 Int) (Q1 Int) (R1 Bool) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Bool) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Int) (K3 Int) (L3 Int) (M3 Bool) (N3 Bool) (O3 Bool) (P3 Int) (Q3 Bool) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Int) (V3 Int) (W3 Bool) (X3 Bool) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Bool) (Y4 Bool) (Z4 Bool) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Int) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Bool) (B6 Bool) (C6 Bool) (D6 Bool) (E6 Bool) (F6 Bool) (G6 Int) (H6 Bool) (I6 Bool) (J6 Bool) (K6 Bool) (L6 Bool) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Bool) (H7 Bool) (I7 Bool) (J7 Int) (K7 Bool) (L7 Bool) (M7 Bool) (N7 Bool) (O7 Bool) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Bool) (H8 Bool) (I8 Bool) (J8 Bool) (K8 Bool) (L8 Bool) (M8 Int) (N8 Bool) (O8 Bool) (P8 Bool) (Q8 Bool) (R8 Bool) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Bool) (K9 Bool) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Bool) (P9 Int) (Q9 Bool) (R9 Bool) (S9 Bool) (T9 Bool) (U9 Bool) (V9 Int) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Bool) (Q10 Bool) (R10 Bool) (S10 Bool) (T10 Bool) (U10 Int) (V10 Bool) (W10 Bool) (X10 Bool) (Y10 Bool) (v_285 Int) (v_286 Int) ) 
    (=>
      (and
        (main_1 v_285
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
        L3)
        (let ((a!1 (or (not P10) (not (= (<= W4 5) R10))))
      (a!2 (or (not Q9) (not (= (<= 2 O10) O))))
      (a!3 (or (not L9) (not (= (<= J2 G3) Q))))
      (a!4 (or (not F7) (not (= (<= R2 I3) E1))))
      (a!5 (or (not C6) (not (= (<= V2 J3) L1))))
      (a!6 (or (not I8) (not (= (<= N2 H3) X))))
      (a!7 (or (not Z4) (not (= (<= Z2 K3) S1))))
      (a!8 (or (not Q3) (not (= (<= D3 L3) Z1)))))
  (and (= 1 v_285)
       (or (and N9 R9) (and L9 S9) (and N8 U9) (not Q9) (and T9 J9))
       (or (and H7 L7) (and F7 M7) (not K7) (and O7 H6) (and N7 D7))
       (or (and E6 I6) (and C6 J6) (and E5 L6) (not H6) (and K6 A6))
       (or (and K8 O8) (and I8 P8) (and G8 Q8) (not N8) (and R8 K7))
       (or (and B5 F5) (and Z4 G5) (and X4 H5) (and W3 I5) (not E5))
       (or (and S3 X3) (and Q3 Y3) (and N3 Z3) (and M3 A4) (not W3))
       (or (and S10 W10) (and Q9 Y10) (not V10) (and X10 P10))
       (or (not F) (not X10) (not P10))
       (or F (not P10) (not T10))
       (or (not T9) (not J9) (= V G10))
       (or (not T9) (not J9) (= U F10))
       (or (not T9) (not J9) (= T D10))
       (or (not T9) (not J9) (= L10 E10))
       (or (not T9) (not J9) (= G10 0))
       (or (not T9) (not J9) (= F10 I2))
       (or (not T9) (not J9) (= E10 H2))
       (or (not T9) (not J9) (= D10 (- 1)))
       (or R (not T9) (not J9))
       (or O (not Q9) (not Q10))
       (or (not O) (not Y10) (not Q9))
       (or (= V Y9) (not N9) (not R9))
       (or (= U X9) (not N9) (not R9))
       (or (= T V9) (not N9) (not R9))
       (or (= L10 W9) (not N9) (not R9))
       (or (= Y9 0) (not N9) (not R9))
       (or (= X9 I2) (not N9) (not R9))
       (or (= W9 P9) (not N9) (not R9))
       (or (not N9) (= V9 (- 1)) (not R9))
       (or (not R) (not M9) (not J9))
       (or (= V C10) (not S9) (not L9))
       (or (= U B10) (not S9) (not L9))
       (or (= T Z9) (not S9) (not L9))
       (or (= L10 A10) (not S9) (not L9))
       (or (= C10 0) (not S9) (not L9))
       (or (= B10 J2) (not S9) (not L9))
       (or (= A10 H2) (not S9) (not L9))
       (or (not S9) (not L9) (= Z9 (- 1)))
       (or Q (not S9) (not L9))
       (or (not Q) (not L9) (not O9))
       (or (not N7) (not D7) (= F8 Y7))
       (or (not N7) (not D7) (= Y7 P2))
       (or (not N7) (not D7) (= J1 A8))
       (or (not N7) (not D7) (= I1 Z7))
       (or (not N7) (not D7) (= H1 X7))
       (or (not N7) (not D7) (= A8 0))
       (or (not N7) (not D7) (= Z7 Q2))
       (or (not N7) (not D7) (= X7 (- 1)))
       (or F1 (not N7) (not D7))
       (or Z (not K7) (not (= O2 1)))
       (or (not K7) (not Z) (not (= O2 0)))
       (or (= F8 Q7) (not H7) (not L7))
       (or (= J1 S7) (not H7) (not L7))
       (or (= I1 R7) (not H7) (not L7))
       (or (= H1 P7) (not H7) (not L7))
       (or (= S7 0) (not H7) (not L7))
       (or (= R7 Q2) (not H7) (not L7))
       (or (= Q7 J7) (not H7) (not L7))
       (or (not H7) (= P7 (- 1)) (not L7))
       (or (not F1) (not G7) (not D7))
       (or (= F8 U7) (not M7) (not F7))
       (or (not M7) (not F7) (= T7 (- 1)))
       (or (= J1 W7) (not M7) (not F7))
       (or (= I1 V7) (not M7) (not F7))
       (or (= H1 T7) (not M7) (not F7))
       (or (= W7 0) (not M7) (not F7))
       (or (= V7 R2) (not M7) (not F7))
       (or (= U7 P2) (not M7) (not F7))
       (or E1 (not M7) (not F7))
       (or (not E1) (not F7) (not I7))
       (or (not K6) (not A6) (= Q1 X6))
       (or (not K6) (not A6) (= P1 W6))
       (or (not K6) (not A6) (= O1 U6))
       (or (not K6) (not A6) (= C7 V6))
       (or (not K6) (not A6) (= X6 0))
       (or (not K6) (not A6) (= W6 U2))
       (or (not K6) (not A6) (= V6 T2))
       (or (not K6) (not A6) (= U6 (- 1)))
       (or M1 (not K6) (not A6))
       (or G1 (not H6) (not (= S2 1)))
       (or (not H6) (not G1) (not (= S2 0)))
       (or (= Q1 P6) (not E6) (not I6))
       (or (= P1 O6) (not E6) (not I6))
       (or (= O1 M6) (not E6) (not I6))
       (or (= C7 N6) (not E6) (not I6))
       (or (= P6 0) (not E6) (not I6))
       (or (= O6 U2) (not E6) (not I6))
       (or (= N6 G6) (not E6) (not I6))
       (or (not E6) (= M6 (- 1)) (not I6))
       (or (not M1) (not D6) (not A6))
       (or (= Q1 T6) (not J6) (not C6))
       (or (= P1 S6) (not J6) (not C6))
       (or (= O1 Q6) (not J6) (not C6))
       (or (= C7 R6) (not J6) (not C6))
       (or (= T6 0) (not J6) (not C6))
       (or (= S6 V2) (not J6) (not C6))
       (or (= R6 T2) (not J6) (not C6))
       (or (not J6) (not C6) (= Q6 (- 1)))
       (or L1 (not J6) (not C6))
       (or (not L1) (not C6) (not F6))
       (or C (not S10) (not W10))
       (or (not R8) (not K7) (= E9 M2))
       (or (not R8) (not K7) (= C1 H9))
       (or (not R8) (not K7) (= B1 G9))
       (or (not R8) (not K7) (= A1 E9))
       (or (not R8) (not K7) (= I9 F9))
       (or (not R8) (not K7) (= H9 1))
       (or (not R8) (not K7) (= G9 M2))
       (or (not R8) (not K7) (= F9 L2))
       (or (not R8) (not K7) (not Z))
       (or S (not N8) (not (= K2 1)))
       (or (not N8) (not S) (not (= K2 0)))
       (or S (not N8) (not K9))
       (or (= V K10) (not N8) (not U9))
       (or (= U J10) (not N8) (not U9))
       (or (= T H10) (not N8) (not U9))
       (or (= L10 I10) (not N8) (not U9))
       (or (= K10 1) (not N8) (not U9))
       (or (= J10 I2) (not N8) (not U9))
       (or (= I10 H2) (not N8) (not U9))
       (or (= H10 I2) (not N8) (not U9))
       (or (not S) (not N8) (not U9))
       (or (= T8 M8) (not K8) (not O8))
       (or (not K8) (not O8) (= S8 (- 1)))
       (or (= V8 0) (not K8) (not O8))
       (or (= U8 M2) (not K8) (not O8))
       (or (= C1 V8) (not K8) (not O8))
       (or (= B1 U8) (not K8) (not O8))
       (or (= A1 S8) (not K8) (not O8))
       (or (= I9 T8) (not K8) (not O8))
       (or (= Z8 0) (not I8) (not P8))
       (or (= Y8 N2) (not I8) (not P8))
       (or (= X8 L2) (not I8) (not P8))
       (or (not I8) (not P8) (= W8 (- 1)))
       (or (= C1 Z8) (not I8) (not P8))
       (or (= B1 Y8) (not I8) (not P8))
       (or (= A1 W8) (not I8) (not P8))
       (or (= I9 X8) (not I8) (not P8))
       (or X (not I8) (not P8))
       (or (not X) (not I8) (not L8))
       (or (not H8) (not K7) Z)
       (or (= D9 0) (not G8) (not Q8))
       (or (= C9 M2) (not G8) (not Q8))
       (or (= B9 L2) (not G8) (not Q8))
       (or (not G8) (not Q8) (= A9 (- 1)))
       (or (= C1 D9) (not G8) (not Q8))
       (or (= B1 C9) (not G8) (not Q8))
       (or (= A1 A9) (not G8) (not Q8))
       (or (= I9 B9) (not G8) (not Q8))
       (or Y (not G8) (not Q8))
       (or (not Y) (not G8) (not J8))
       (or (not O7) (not H6) (= F8 C8))
       (or (not O7) (not H6) (= D8 Q2))
       (or (not O7) (not H6) (= J1 E8))
       (or (not O7) (not H6) (= I1 D8))
       (or (not O7) (not H6) (= H1 B8))
       (or (not O7) (not H6) (= E8 1))
       (or (not O7) (not H6) (= C8 P2))
       (or (not O7) (not H6) (= B8 Q2))
       (or (not O7) (not H6) (not G1))
       (or (not E7) (not H6) G1)
       (or N1 (not E5) (not (= W2 1)))
       (or (not E5) (not N1) (not (= W2 0)))
       (or N1 (not E5) (not B6))
       (or (= Z6 T2) (not L6) (not E5))
       (or (= Q1 B7) (not L6) (not E5))
       (or (= P1 A7) (not L6) (not E5))
       (or (= O1 Y6) (not L6) (not E5))
       (or (= C7 Z6) (not L6) (not E5))
       (or (= B7 1) (not L6) (not E5))
       (or (= A7 U2) (not L6) (not E5))
       (or (= Y6 U2) (not L6) (not E5))
       (or (not N1) (not L6) (not E5))
       (or (= K5 D5) (not B5) (not F5))
       (or (not B5) (= J5 (- 1)) (not F5))
       (or (= M5 0) (not B5) (not F5))
       (or (= L5 Y2) (not B5) (not F5))
       (or (= X1 M5) (not B5) (not F5))
       (or (= W1 L5) (not B5) (not F5))
       (or (= V1 J5) (not B5) (not F5))
       (or (= Z5 K5) (not B5) (not F5))
       (or (= Q5 0) (not G5) (not Z4))
       (or (= P5 Z2) (not G5) (not Z4))
       (or (= O5 X2) (not G5) (not Z4))
       (or (not G5) (not Z4) (= N5 (- 1)))
       (or (= X1 Q5) (not G5) (not Z4))
       (or (= W1 P5) (not G5) (not Z4))
       (or (= V1 N5) (not G5) (not Z4))
       (or (= Z5 O5) (not G5) (not Z4))
       (or S1 (not G5) (not Z4))
       (or (not S1) (not Z4) (not C5))
       (or (= S5 X2) (not H5) (not X4))
       (or (not H5) (= R5 (- 1)) (not X4))
       (or (= X1 U5) (not H5) (not X4))
       (or (= W1 T5) (not H5) (not X4))
       (or (= V1 R5) (not H5) (not X4))
       (or (= Z5 S5) (not H5) (not X4))
       (or (= U5 0) (not H5) (not X4))
       (or (= T5 Y2) (not H5) (not X4))
       (or T1 (not H5) (not X4))
       (or (not T1) (not A5) (not X4))
       (or U1 (not (= A3 1)) (not W3))
       (or (not W3) (not U1) (not (= A3 0)))
       (or (= X1 Y5) (not I5) (not W3))
       (or (= W1 X5) (not I5) (not W3))
       (or (= V1 V5) (not I5) (not W3))
       (or (= Z5 W5) (not I5) (not W3))
       (or (= Y5 1) (not I5) (not W3))
       (or (= X5 Y2) (not I5) (not W3))
       (or (= W5 X2) (not I5) (not W3))
       (or (= V5 Y2) (not I5) (not W3))
       (or (not U1) (not I5) (not W3))
       (or U1 (not W3) (not Y4))
       (or (= C4 U3) (not S3) (not X3))
       (or (not S3) (= B4 (- 1)) (not X3))
       (or (= W4 E4) (not S3) (not X3))
       (or (= V4 C4) (not S3) (not X3))
       (or (= F4 0) (not S3) (not X3))
       (or (= E4 P3) (not S3) (not X3))
       (or (= D4 V3) (not S3) (not X3))
       (or (= F2 F4) (not S3) (not X3))
       (or (= E2 D4) (not S3) (not X3))
       (or (= D2 B4) (not S3) (not X3))
       (or (= W4 J4) (not Y3) (not Q3))
       (or (= V4 H4) (not Y3) (not Q3))
       (or (= K4 0) (not Y3) (not Q3))
       (or (= J4 P3) (not Y3) (not Q3))
       (or (= I4 D3) (not Y3) (not Q3))
       (or (= H4 B3) (not Y3) (not Q3))
       (or (not Y3) (not Q3) (= G4 (- 1)))
       (or (= F2 K4) (not Y3) (not Q3))
       (or (= E2 I4) (not Y3) (not Q3))
       (or (= D2 G4) (not Y3) (not Q3))
       (or Z1 (not Y3) (not Q3))
       (or (not Z1) (not T3) (not Q3))
       (or (= W4 O4) (not Z3) (not N3))
       (or (= V4 M4) (not Z3) (not N3))
       (or (= P4 0) (not Z3) (not N3))
       (or (= O4 P3) (not Z3) (not N3))
       (or (= N4 C3) (not Z3) (not N3))
       (or (= M4 B3) (not Z3) (not N3))
       (or (not Z3) (= L4 (- 1)) (not N3))
       (or (= F2 P4) (not Z3) (not N3))
       (or (= E2 N4) (not Z3) (not N3))
       (or (= D2 L4) (not Z3) (not N3))
       (or A2 (not Z3) (not N3))
       (or (not A2) (not N3) (not R3))
       (or (= W4 T4) (not A4) (not M3))
       (or (= V4 R4) (not A4) (not M3))
       (or (= U4 1) (not A4) (not M3))
       (or (= T4 E3) (not A4) (not M3))
       (or (= S4 C3) (not A4) (not M3))
       (or (= R4 B3) (not A4) (not M3))
       (or (= Q4 C3) (not A4) (not M3))
       (or (= F2 U4) (not A4) (not M3))
       (or (= E2 S4) (not A4) (not M3))
       (or (= D2 Q4) (not A4) (not M3))
       (or (not C2) (not A4) (not M3))
       (or C2 (not M3) (not O3))
       a!1
       (or (not P10) (= F (or E R10)))
       (or (not P10) (= E (= M10 D)))
       (or (not P10) (= D (* (- 1) N10)))
       (or (not P10) (and Q9 Q10))
       (or (not J9) (= R (= J2 (- 1))))
       (or (not J9) (and N8 K9))
       (or (not D7) (= F1 (= R2 (- 1))))
       (or (not D7) (and E7 H6))
       (or (not A6) (= M1 (= V2 (- 1))))
       (or (not A6) (and E5 B6))
       (or C2 (not (= F3 1)))
       (or (not C2) (not (= F3 0)))
       (or (not S10) (= C (and B R10)))
       (or (not S10) (= A (= O10 1)))
       (or (not S10) (not (= A B)))
       (or (not S10) (= U10 (+ 1 G2)))
       (or (not S10) (and T10 P10))
       a!2
       (or (not Q9) (= N I9))
       (or (not Q9) (= M (+ K L)))
       (or (not Q9) (= L F8))
       (or (not Q9) (= K (+ I J)))
       (or (not Q9) (= J C7))
       (or (not Q9) (= I (+ H G)))
       (or (not Q9) (= H Z5))
       (or (not Q9) (= G V4))
       (or (not Q9) (= O10 (+ N10 M10)))
       (or (not Q9) (= N10 L10))
       (or (not Q9) (= M10 (+ M N)))
       (or (not N9) (= P (= J2 G3)))
       (or (not N9) (= P9 (ite P 1 H2)))
       (or (not N9) (and L9 O9))
       a!3
       (or (not L9) (and M9 J9))
       (or (not H7) (= D1 (= R2 I3)))
       (or (not H7) (= J7 (ite D1 1 P2)))
       (or (not H7) (and F7 I7))
       a!4
       (or (not F7) (and G7 D7))
       (or (not E6) (= K1 (= V2 J3)))
       (or (not E6) (= G6 (ite K1 1 T2)))
       (or (not E6) (and C6 F6))
       a!5
       (or (not C6) (and D6 A6))
       (or (not K8) (= W (= N2 H3)))
       (or (not K8) (= M8 (ite W 1 L2)))
       (or (not K8) (and I8 L8))
       a!6
       (or (not I8) (and G8 J8))
       (or (not G8) (= Y (= N2 (- 1))))
       (or (not G8) (and H8 K7))
       (or (not B5) (= R1 (= Z2 K3)))
       (or (not B5) (= D5 (ite R1 1 X2)))
       (or (not B5) (and Z4 C5))
       a!7
       (or (not Z4) (and X4 A5))
       (or (not X4) (= T1 (= Z2 (- 1))))
       (or (not X4) (and W3 Y4))
       (or (not S3) (= Y1 (= D3 L3)))
       (or (not S3) (= V3 (ite Y1 C3 D3)))
       (or (not S3) (= U3 (ite Y1 1 B3)))
       (or (not S3) (and Q3 T3))
       a!8
       (or (not Q3) (and N3 R3))
       (or (not N3) (= A2 (= D3 (- 1))))
       (or (not N3) (= P3 (+ 1 E3)))
       (or (not N3) (and M3 O3))
       (= B2 true)
       (= V10 true)
       (not (= (<= 12 G2) B2))
       (= 2 v_286)))
      )
      (main_1 v_286
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
        L3)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (v_32 Int) ) 
    (=>
      (and
        (main_1 v_32
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
        F1)
        (= 2 v_32)
      )
      false
    )
  )
)

(check-sat)
(exit)
