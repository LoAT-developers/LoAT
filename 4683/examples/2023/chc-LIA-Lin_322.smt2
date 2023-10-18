; ./prepared/seahorn/./sv_comp_flat_small/systemc/token_ring.03_false-unreach-call_false-termination.cil.c.flat_000.smt2
(set-logic HORN)


(declare-fun |main_1| ( Int Int Int Int Int Int Int Bool Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Bool Bool ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Bool) (C1 Bool) (v_29 Int) ) 
    (=>
      (and
        (and true (= 0 v_29))
      )
      (main_1 v_29 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z A1 B1 C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Bool) (v_52 Int) (v_53 Int) ) 
    (=>
      (and
        (main_1 v_52
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
        L1)
        (and (= 0 v_52)
     (or (= Y1 0) (not O1) (not M1))
     (or (= I Y1) (not O1) (not M1))
     (or (= H X1) (not O1) (not M1))
     (or (= G W1) (not O1) (not M1))
     (or (= F U1) (not O1) (not M1))
     (or (= E T1) (not O1) (not M1))
     (or (= D S1) (not O1) (not M1))
     (or (= C R1) (not O1) (not M1))
     (or (= B Q1) (not O1) (not M1))
     (or (= A P1) (not O1) (not M1))
     (or (= X1 0) (not O1) (not M1))
     (or (= W1 0) (not O1) (not M1))
     (or (= U1 0) (not O1) (not M1))
     (or (= T1 0) (not O1) (not M1))
     (or (= S1 0) (not O1) (not M1))
     (or (= R1 0) (not O1) (not M1))
     (or (= Q1 0) (not O1) (not M1))
     (or (= P1 0) (not O1) (not M1))
     (or (not O1) (not M1) (not V1))
     (or (not N1) (and M1 O1))
     (= N1 true)
     (or (= Z1 V1) (not O1) (not M1))
     (= 1 v_53))
      )
      (main_1 v_53
        A
        B
        C
        D
        E
        F
        Z1
        G
        H
        I
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
        L1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Bool) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (v_51 Int) (v_52 Int) ) 
    (=>
      (and
        (main_1 v_51
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
        L1)
        (and (= 1 v_51)
     (or (= Y1 P1) (not M1) (not O1))
     (or (= X1 S) (not M1) (not O1))
     (or (= I X1) (not M1) (not O1))
     (or (= H W1) (not M1) (not O1))
     (or (= G V1) (not M1) (not O1))
     (or (= F U1) (not M1) (not O1))
     (or (= E T1) (not M1) (not O1))
     (or (= D S1) (not M1) (not O1))
     (or (= C R1) (not M1) (not O1))
     (or (= B Q1) (not M1) (not O1))
     (or (= W1 R) (not M1) (not O1))
     (or (= V1 Q) (not M1) (not O1))
     (or (= U1 O) (not M1) (not O1))
     (or (= T1 N) (not M1) (not O1))
     (or (= S1 M) (not M1) (not O1))
     (or (= R1 L) (not M1) (not O1))
     (or (= Q1 K) (not M1) (not O1))
     (or (= P1 J) (not M1) (not O1))
     (or (not N1) (and M1 O1))
     (= N1 true)
     (not (= P A))
     (= 2 v_52))
      )
      (main_1 v_52
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
        Y1
        B
        C
        D
        E
        F
        G
        H
        I
        C1
        D1
        E1
        F1
        G1
        H1
        I1
        J1
        A
        L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (v_48 Int) (v_49 Int) ) 
    (=>
      (and
        (main_1 v_48 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z A1 B1 C1)
        (and (= 2 v_48)
     (or (= U1 M1) (not D1) (not F1))
     (or (= T1 L1) (not D1) (not F1))
     (or (= S1 K1) (not D1) (not F1))
     (or (= R1 J1) (not D1) (not F1))
     (or (= Q1 I1) (not D1) (not F1))
     (or (= P1 H1) (not D1) (not F1))
     (or (= O1 G1) (not D1) (not F1))
     (or (= N1 S) (not D1) (not F1))
     (or (= M1 R) (not D1) (not F1))
     (or (= L1 Q) (not D1) (not F1))
     (or (= K1 P) (not D1) (not F1))
     (or (= J1 O) (not D1) (not F1))
     (or (= I1 N) (not D1) (not F1))
     (or (= H1 M) (not D1) (not F1))
     (or (= G1 L) (not D1) (not F1))
     (or (not E1) (and D1 F1))
     (= E1 true)
     (or (= V1 N1) (not D1) (not F1))
     (= 3 v_49))
      )
      (main_1 v_49
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
        O1
        P1
        Q1
        R1
        S1
        T1
        U1
        V1
        B1
        C1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) (M Bool) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Int) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Int) (E1 Bool) (F1 Bool) (G1 Int) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Bool) (B3 Bool) (C3 Bool) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Int) (J3 Bool) (K3 Int) (L3 Int) (M3 Int) (N3 Bool) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Bool) (V3 Int) (W3 Int) (X3 Int) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Bool) (C4 Bool) (D4 Bool) (E4 Bool) (F4 Int) (G4 Bool) (H4 Bool) (I4 Bool) (J4 Bool) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Int) (E5 Int) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Bool) (Q5 Bool) (R5 Bool) (S5 Bool) (T5 Int) (U5 Bool) (V5 Bool) (W5 Bool) (X5 Bool) (Y5 Bool) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Bool) (E7 Bool) (F7 Bool) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Bool) (Z7 Bool) (A8 Bool) (B8 Bool) (C8 Int) (D8 Bool) (E8 Bool) (F8 Bool) (G8 Bool) (H8 Bool) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Int) (U9 Int) (V9 Int) (W9 Bool) (X9 Bool) (Y9 Bool) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Int) (Q10 Int) (R10 Int) (S10 Int) (T10 Int) (U10 Int) (V10 Int) (W10 Int) (X10 Bool) (Y10 Bool) (Z10 Int) (A11 Int) (B11 Int) (C11 Int) (D11 Int) (E11 Int) (F11 Int) (G11 Int) (H11 Int) (I11 Int) (J11 Int) (K11 Bool) (L11 Bool) (M11 Int) (N11 Int) (O11 Bool) (P11 Bool) (Q11 Bool) (R11 Int) (S11 Int) (T11 Int) (U11 Int) (V11 Bool) (v_308 Int) (v_309 Int) ) 
    (=>
      (and
        (main_1 v_308
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
        B3)
        (let ((a!1 (or (not A4) (not (= (<= 6 X3) Y))))
      (a!2 (or (not A4) (not (= (<= W3 4) Z)))))
  (and (= 3 v_308)
       (not (= O1 P1))
       (= N1 (= J2 0))
       (= M1 (or K1 L1))
       (= L1 (= S2 0))
       (= K1 (or I1 J1))
       (= J1 (= T2 0))
       (= I1 (= U2 0))
       (or (and A8 E8) (and Y7 F8) (and D7 G8) (and U5 H8) (not D8))
       (or (and R5 V5) (and P5 W5) (and A5 X5) (and G4 Y5) (not U5))
       (or (and C4 H4) (and R3 I4) (and P3 J4) (not G4))
       (or (not O11) (and K11 P11) (and X10 Q11))
       (or (= D U11) (not X10) (not Q11))
       (or (= C T11) (not X10) (not Q11))
       (or (= U11 H11) (not X10) (not Q11))
       (or (= T11 J11) (not X10) (not Q11))
       (or (not W9) (and X9 D8) (and A8 Y9))
       (or (= K G11) (not W9) (not Y10))
       (or (= J F11) (not W9) (not Y10))
       (or (= I D11) (not W9) (not Y10))
       (or (= H B11) (not W9) (not Y10))
       (or (= G Z10) (not W9) (not Y10))
       (or (= Z10 W10) (not W9) (not Y10))
       (or (= J11 E11) (not W9) (not Y10))
       (or (= I11 C11) (not W9) (not Y10))
       (or (= H11 A11) (not W9) (not Y10))
       (or (= G11 P10) (not W9) (not Y10))
       (or (= F11 Q10) (not W9) (not Y10))
       (or (= E11 R10) (not W9) (not Y10))
       (or (= D11 S10) (not W9) (not Y10))
       (or (= C11 T10) (not W9) (not Y10))
       (or (= B11 U10) (not W9) (not Y10))
       (or (= A11 V10) (not W9) (not Y10))
       (or (= L10 X7) (not Y9) (not A8))
       (or (= S10 K10) (not Y9) (not A8))
       (or (= R10 J10) (not Y9) (not A8))
       (or (= Q10 I10) (not Y9) (not A8))
       (or (= P10 H10) (not Y9) (not A8))
       (or (= O10 2) (not Y9) (not A8))
       (or (= N10 C8) (not Y9) (not A8))
       (or (= M10 1) (not Y9) (not A8))
       (or (= K10 W7) (not Y9) (not A8))
       (or (= J10 V7) (not Y9) (not A8))
       (or (= I10 U7) (not Y9) (not A8))
       (or (= H10 S7) (not Y9) (not A8))
       (or (= W10 O10) (not Y9) (not A8))
       (or (= V10 N10) (not Y9) (not A8))
       (or (= U10 M10) (not Y9) (not A8))
       (or (= T10 L10) (not Y9) (not A8))
       (or (= V9 P8) (not A8) (not E8))
       (or (= U9 O8) (not A8) (not E8))
       (or (= T9 N8) (not A8) (not E8))
       (or (= S9 M8) (not A8) (not E8))
       (or (= R9 L8) (not A8) (not E8))
       (or (= Q9 K8) (not A8) (not E8))
       (or (= P9 J8) (not A8) (not E8))
       (or (= O9 I8) (not A8) (not E8))
       (or (= P8 1) (not A8) (not E8))
       (or (= O8 C8) (not A8) (not E8))
       (or (= N8 2) (not A8) (not E8))
       (or (= M8 X7) (not A8) (not E8))
       (or (= L8 W7) (not A8) (not E8))
       (or (= K8 V7) (not A8) (not E8))
       (or (= J8 U7) (not A8) (not E8))
       (or (= I8 S7) (not A8) (not E8))
       (or (= V9 X8) (not Y7) (not F8))
       (or (= U9 W8) (not Y7) (not F8))
       (or (= T9 V8) (not Y7) (not F8))
       (or (= S9 U8) (not Y7) (not F8))
       (or (= R9 T8) (not Y7) (not F8))
       (or (= Q9 S8) (not Y7) (not F8))
       (or (= P9 R8) (not Y7) (not F8))
       (or (= O9 Q8) (not Y7) (not F8))
       (or (= X8 1) (not Y7) (not F8))
       (or (= W8 T7) (not Y7) (not F8))
       (or (= V8 2) (not Y7) (not F8))
       (or (= U8 X7) (not Y7) (not F8))
       (or (= T8 W7) (not Y7) (not F8))
       (or (= S8 V7) (not Y7) (not F8))
       (or (= R8 U7) (not Y7) (not F8))
       (or (= Q8 S7) (not Y7) (not F8))
       (or (and U5 E7) (and R5 F7) (not D7))
       (or (= V9 F9) (not D7) (not G8))
       (or (= U9 E9) (not D7) (not G8))
       (or (= T9 D9) (not D7) (not G8))
       (or (= S9 C9) (not D7) (not G8))
       (or (= R9 B9) (not D7) (not G8))
       (or (= Q9 A9) (not D7) (not G8))
       (or (= P9 Z8) (not D7) (not G8))
       (or (= O9 Y8) (not D7) (not G8))
       (or (= F9 X2) (not D7) (not G8))
       (or (= E9 T7) (not D7) (not G8))
       (or (= D9 0) (not D7) (not G8))
       (or (= C9 X7) (not D7) (not G8))
       (or (= B9 W7) (not D7) (not G8))
       (or (= A9 V7) (not D7) (not G8))
       (or (= Z8 U7) (not D7) (not G8))
       (or (= Y8 S7) (not D7) (not G8))
       (or (= V9 N9) (not U5) (not H8))
       (or (= U9 M9) (not U5) (not H8))
       (or (= T9 L9) (not U5) (not H8))
       (or (= S9 K9) (not U5) (not H8))
       (or (= R9 J9) (not U5) (not H8))
       (or (= Q9 I9) (not U5) (not H8))
       (or (= P9 H9) (not U5) (not H8))
       (or (= O9 G9) (not U5) (not H8))
       (or (= N9 X2) (not U5) (not H8))
       (or (= M9 B7) (not U5) (not H8))
       (or (= L9 S2) (not U5) (not H8))
       (or (= K9 X6) (not U5) (not H8))
       (or (= J9 Y6) (not U5) (not H8))
       (or (= I9 Z6) (not U5) (not H8))
       (or (= H9 A7) (not U5) (not H8))
       (or (= G9 C7) (not U5) (not H8))
       (or (= X7 L7) (not U5) (not E7))
       (or (= W7 K7) (not U5) (not E7))
       (or (= V7 J7) (not U5) (not E7))
       (or (= U7 I7) (not U5) (not E7))
       (or (= T7 H7) (not U5) (not E7))
       (or (= S7 G7) (not U5) (not E7))
       (or (= L7 X6) (not U5) (not E7))
       (or (= K7 Y6) (not U5) (not E7))
       (or (= J7 Z6) (not U5) (not E7))
       (or (= I7 A7) (not U5) (not E7))
       (or (= H7 B7) (not U5) (not E7))
       (or (= G7 C7) (not U5) (not E7))
       (or (= X7 R7) (not R5) (not F7))
       (or (= W7 Q7) (not R5) (not F7))
       (or (= V7 P7) (not R5) (not F7))
       (or (= U7 O7) (not R5) (not F7))
       (or (= T7 N7) (not R5) (not F7))
       (or (= S7 M7) (not R5) (not F7))
       (or (= R7 L5) (not R5) (not F7))
       (or (= Q7 N5) (not R5) (not F7))
       (or (= P7 O5) (not R5) (not F7))
       (or (= O7 2) (not R5) (not F7))
       (or (= N7 T5) (not R5) (not F7))
       (or (= M7 1) (not R5) (not F7))
       (or (= C7 E6) (not R5) (not V5))
       (or (= B7 D6) (not R5) (not V5))
       (or (= A7 C6) (not R5) (not V5))
       (or (= Z6 B6) (not R5) (not V5))
       (or (= Y6 A6) (not R5) (not V5))
       (or (= X6 Z5) (not R5) (not V5))
       (or (= E6 1) (not R5) (not V5))
       (or (= D6 T5) (not R5) (not V5))
       (or (= C6 2) (not R5) (not V5))
       (or (= B6 O5) (not R5) (not V5))
       (or (= A6 N5) (not R5) (not V5))
       (or (= Z5 L5) (not R5) (not V5))
       (or (= C7 K6) (not P5) (not W5))
       (or (= B7 J6) (not P5) (not W5))
       (or (= A7 I6) (not P5) (not W5))
       (or (= Z6 H6) (not P5) (not W5))
       (or (= Y6 G6) (not P5) (not W5))
       (or (= X6 F6) (not P5) (not W5))
       (or (= K6 1) (not P5) (not W5))
       (or (= J6 M5) (not P5) (not W5))
       (or (= I6 2) (not P5) (not W5))
       (or (= H6 O5) (not P5) (not W5))
       (or (= G6 N5) (not P5) (not W5))
       (or (= F6 L5) (not P5) (not W5))
       (or (and G4 B5) (and C4 C5) (not A5))
       (or (= C7 Q6) (not A5) (not X5))
       (or (= B7 P6) (not A5) (not X5))
       (or (= A7 O6) (not A5) (not X5))
       (or (= Z6 N6) (not A5) (not X5))
       (or (= Y6 M6) (not A5) (not X5))
       (or (= X6 L6) (not A5) (not X5))
       (or (= Q6 Y2) (not A5) (not X5))
       (or (= P6 M5) (not A5) (not X5))
       (or (= O6 0) (not A5) (not X5))
       (or (= N6 O5) (not A5) (not X5))
       (or (= M6 N5) (not A5) (not X5))
       (or (= L6 L5) (not A5) (not X5))
       (or (= C7 W6) (not G4) (not Y5))
       (or (= B7 V6) (not G4) (not Y5))
       (or (= A7 U6) (not G4) (not Y5))
       (or (= Z6 T6) (not G4) (not Y5))
       (or (= Y6 S6) (not G4) (not Y5))
       (or (= X6 R6) (not G4) (not Y5))
       (or (= W6 Y2) (not G4) (not Y5))
       (or (= V6 Y4) (not G4) (not Y5))
       (or (= U6 T2) (not G4) (not Y5))
       (or (= T6 W4) (not G4) (not Y5))
       (or (= S6 X4) (not G4) (not Y5))
       (or (= R6 Z4) (not G4) (not Y5))
       (or (= O5 G5) (not G4) (not B5))
       (or (= N5 F5) (not G4) (not B5))
       (or (= M5 E5) (not G4) (not B5))
       (or (= L5 D5) (not G4) (not B5))
       (or (= G5 W4) (not G4) (not B5))
       (or (= F5 X4) (not G4) (not B5))
       (or (= E5 Y4) (not G4) (not B5))
       (or (= D5 Z4) (not G4) (not B5))
       (or (and A4 D4) (and T3 E4) (not C4))
       (or (= O5 K5) (not C4) (not C5))
       (or (= N5 J5) (not C4) (not C5))
       (or (= M5 I5) (not C4) (not C5))
       (or (= L5 H5) (not C4) (not C5))
       (or (= K5 2) (not C4) (not C5))
       (or (= J5 F4) (not C4) (not C5))
       (or (= I5 F4) (not C4) (not C5))
       (or (= H5 1) (not C4) (not C5))
       (or (= Z4 N4) (not C4) (not H4))
       (or (= Y4 M4) (not C4) (not H4))
       (or (= X4 L4) (not C4) (not H4))
       (or (= W4 K4) (not C4) (not H4))
       (or (= N4 1) (not C4) (not H4))
       (or (= M4 F4) (not C4) (not H4))
       (or (= L4 F4) (not C4) (not H4))
       (or (= K4 2) (not C4) (not H4))
       (or (= Z4 R4) (not R3) (not I4))
       (or (= Y4 Q4) (not R3) (not I4))
       (or (= X4 P4) (not R3) (not I4))
       (or (= W4 O4) (not R3) (not I4))
       (or (= R4 Z2) (not R3) (not I4))
       (or (= Q4 W2) (not R3) (not I4))
       (or (= P4 V2) (not R3) (not I4))
       (or (= O4 0) (not R3) (not I4))
       (or (= Z4 V4) (not P3) (not J4))
       (or (= Y4 U4) (not P3) (not J4))
       (or (= X4 T4) (not P3) (not J4))
       (or (= W4 S4) (not P3) (not J4))
       (or (= V4 Z2) (not P3) (not J4))
       (or (= U4 W2) (not P3) (not J4))
       (or (= T4 V2) (not P3) (not J4))
       (or (= S4 U2) (not P3) (not J4))
       (or (not A3) (not Y9) (not A8))
       (or A3 (not A8) (not E8))
       (or (not F2) (not X10) (not Q11))
       (or (not P1) (not O3) (not Q3))
       (or (not I1) (not P3) (not J4))
       (or I1 (not S3) (not P3))
       (or H1 (not R3) (not I4))
       (or (not H1) (not R3) (not U3))
       (or (not F1) (not T3) (not E4))
       (or F1 (not Z3) (not T3))
       (or E1 (not Y3) (not B4))
       (or (not C1) (not A4) (not D4))
       (or (not X) (not C4) (not C5))
       (or X (not C4) (not H4))
       (or (not V) (not G4) (not Y5))
       (or V (not G4) (not B5))
       (or U (not A5) (not X5))
       (or (not U) (not A5) (not Q5))
       (or (not S) (not P5) (not W5))
       (or S (not P5) (not S5))
       (or (not R) (not R5) (not F7))
       (or R (not R5) (not V5))
       (or (not P) (not U5) (not H8))
       (or P (not U5) (not E7))
       (or O (not D7) (not G8))
       (or (not O) (not D7) (not Z7))
       (or (not M) (not Y7) (not F8))
       (or M (not Y7) (not B8))
       (or (not F) (not W9) (not Y10))
       (or F2 (not L11) (not X10))
       (or (not X9) (not D8) (= S10 C10))
       (or (not X9) (not D8) (= R10 B10))
       (or (not X9) (not D8) (= Q10 A10))
       (or (not X9) (not D8) (= P10 Z9))
       (or (not X9) (not D8) (= G10 T9))
       (or (not X9) (not D8) (= F10 U9))
       (or (not X9) (not D8) (= E10 V9))
       (or (not X9) (not D8) (= D10 S9))
       (or (not X9) (not D8) (= C10 R9))
       (or (not X9) (not D8) (= B10 Q9))
       (or (not X9) (not D8) (= A10 P9))
       (or (not X9) (not D8) (= Z9 O9))
       (or (not X9) (not D8) (= W10 G10))
       (or (not X9) (not D8) (= V10 F10))
       (or (not X9) (not D8) (= U10 E10))
       (or (not X9) (not D8) (= T10 D10))
       (or L (not D8) (not X9))
       (or (= D S11) (not K11) (not P11))
       (or (= C R11) (not K11) (not P11))
       (or (= S11 M11) (not K11) (not P11))
       (or (= R11 N11) (not K11) (not P11))
       (or (not V11) (not O11) (= N3 J3))
       (or (not V11) (not O11) (= M3 I11))
       (or (not V11) (not O11) (= L3 K))
       (or (not V11) (not O11) (= K3 H))
       (or (not V11) (not O11) (= I3 D))
       (or (not V11) (not O11) (= H3 I))
       (or (not V11) (not O11) (= G3 C))
       (or (not V11) (not O11) (= F3 J))
       (or (not V11) (not O11) (= E3 G))
       (or (not V11) (not O11) (= D3 2))
       (or (not V11) (not O11) (= Y1 M3))
       (or (not V11) (not O11) (= X1 L3))
       (or (not V11) (not O11) (= W1 K3))
       (or (not V11) (not O11) (= V1 I3))
       (or (not V11) (not O11) (= U1 H3))
       (or (not V11) (not O11) (= T1 G3))
       (or (not V11) (not O11) (= S1 F3))
       (or (not V11) (not O11) (= R1 E3))
       (or (not V11) (not O11) (= Q1 D3))
       (or J3 (not O11) (not V11))
       (or (not X10) (and W9 Y10))
       (or (not W9) (= F (= E 0)))
       (or (not D8) (= L (= J2 0)))
       (or (not A8) (= C8 (+ 1 T7)))
       (or (not A8) (and Y7 B8))
       (or (not Y7) (= M (= X2 1)))
       (or (not Y7) (and D7 Z7))
       (or (not D7) (= O (= N 0)))
       (or (not U5) (= P (= S2 0)))
       (or (not R5) (= Q (= X2 1)))
       (or (not R5) (not (= Q R)))
       (or (not R5) (= T5 (+ 1 M5)))
       (or (not R5) (and P5 S5))
       (or (not P5) (= S (= Y2 1)))
       (or (not P5) (and A5 Q5))
       (or (not A5) (= U (= T 0)))
       (or (not G4) (= V (= T2 0)))
       (or (not C4) (= W (= Y2 1)))
       (or (not C4) (not (= W X)))
       a!1
       a!2
       (or (not A4) (= C1 (and A1 B1)))
       (or (not A4) (= B1 (= V3 5)))
       (or (not A4) (= A1 (and Y Z)))
       (or (not A4) (and Y3 B4))
       (or (not Y3) (= E1 (= W2 D1)))
       (or (not Y3) (= D1 (+ 3 V2)))
       (or (not Y3) (and T3 Z3))
       (or (not T3) (= F1 (= Z2 1)))
       (or (not T3) (and R3 U3))
       (or (not R3) (= H1 (= G1 0)))
       (or (not R3) (and P3 S3))
       (or (not P3) (and O3 Q3))
       (or (not C3) (and V11 O11))
       (or (not K11) (= A (= I11 1)))
       (or (not K11) (not (= A B)))
       (or (not K11) (= N11 (ite B J11 0)))
       (or (not K11) (= M11 (+ 1 H11)))
       (or (not K11) (and L11 X10))
       (= C3 true)
       (= O1 (or M1 N1))
       (= 1 v_309)))
      )
      (main_1 v_309
        Q1
        R1
        S1
        T1
        U1
        V1
        N3
        W1
        X1
        Y1
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
        I1)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Int) (V Bool) (W Bool) (X Int) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Bool) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Bool) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Bool) (R2 Bool) (S2 Bool) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Int) (D3 Bool) (E3 Bool) (F3 Bool) (G3 Bool) (H3 Bool) (I3 Bool) (J3 Bool) (K3 Int) (L3 Int) (M3 Int) (N3 Bool) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Int) (V3 Bool) (W3 Bool) (X3 Bool) (Y3 Bool) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Bool) (Q4 Bool) (R4 Bool) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Int) (J5 Bool) (K5 Bool) (L5 Bool) (M5 Bool) (N5 Bool) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Bool) (T6 Bool) (U6 Bool) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Bool) (O7 Bool) (P7 Bool) (Q7 Bool) (R7 Int) (S7 Bool) (T7 Bool) (U7 Bool) (V7 Bool) (W7 Bool) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Bool) (M9 Bool) (N9 Bool) (O9 Int) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Int) (U9 Int) (V9 Int) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Bool) (v_273 Int) (v_274 Int) ) 
    (=>
      (and
        (main_1 v_273
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
        R2)
        (let ((a!1 (or (not P3) (not (= (<= 6 M3) P))))
      (a!2 (or (not P3) (not (= (<= L3 4) Q)))))
  (and (= 3 v_273)
       (not (= F1 G1))
       (= E1 (= Z1 0))
       (= D1 (or B1 C1))
       (= C1 (= I2 0))
       (= B1 (or Z A1))
       (= A1 (= J2 0))
       (= Z (= K2 0))
       (or (and P7 T7) (and N7 U7) (and S6 V7) (and J5 W7) (not S7))
       (or (and G5 K5) (and E5 L5) (and P4 M5) (and V3 N5) (not J5))
       (or (and R3 W3) (and G3 X3) (and E3 Y3) (not V3))
       (or (and S7 M9) (and P7 N9) (not L9))
       (or (= L10 V9) (not S7) (not M9))
       (or (= Q9 F9) (not S7) (not M9))
       (or (= K10 U9) (not S7) (not M9))
       (or (= J10 T9) (not S7) (not M9))
       (or (= I10 S9) (not S7) (not M9))
       (or (= H10 R9) (not S7) (not M9))
       (or (= G10 Q9) (not S7) (not M9))
       (or (= F10 P9) (not S7) (not M9))
       (or (= E10 O9) (not S7) (not M9))
       (or (= V9 I9) (not S7) (not M9))
       (or (= U9 J9) (not S7) (not M9))
       (or (= T9 K9) (not S7) (not M9))
       (or (= S9 H9) (not S7) (not M9))
       (or (= R9 G9) (not S7) (not M9))
       (or (= P9 E9) (not S7) (not M9))
       (or (= O9 D9) (not S7) (not M9))
       (or (= L10 D10) (not P7) (not N9))
       (or (= K10 C10) (not P7) (not N9))
       (or (= J10 B10) (not P7) (not N9))
       (or (= I10 A10) (not P7) (not N9))
       (or (= H10 Z9) (not P7) (not N9))
       (or (= G10 Y9) (not P7) (not N9))
       (or (= F10 X9) (not P7) (not N9))
       (or (= E10 W9) (not P7) (not N9))
       (or (= D10 2) (not P7) (not N9))
       (or (= C10 R7) (not P7) (not N9))
       (or (= B10 1) (not P7) (not N9))
       (or (= A10 M7) (not P7) (not N9))
       (or (= Z9 L7) (not P7) (not N9))
       (or (= Y9 K7) (not P7) (not N9))
       (or (= X9 J7) (not P7) (not N9))
       (or (= W9 H7) (not P7) (not N9))
       (or (= E8 1) (not P7) (not T7))
       (or (= D8 R7) (not P7) (not T7))
       (or (= C8 2) (not P7) (not T7))
       (or (= B8 M7) (not P7) (not T7))
       (or (= A8 L7) (not P7) (not T7))
       (or (= Z7 K7) (not P7) (not T7))
       (or (= Y7 J7) (not P7) (not T7))
       (or (= X7 H7) (not P7) (not T7))
       (or (= J9 D8) (not P7) (not T7))
       (or (= I9 C8) (not P7) (not T7))
       (or (= H9 B8) (not P7) (not T7))
       (or (= G9 A8) (not P7) (not T7))
       (or (= F9 Z7) (not P7) (not T7))
       (or (= E9 Y7) (not P7) (not T7))
       (or (= D9 X7) (not P7) (not T7))
       (or (= K9 E8) (not P7) (not T7))
       (or (= M8 1) (not N7) (not U7))
       (or (= L8 I7) (not N7) (not U7))
       (or (= K8 2) (not N7) (not U7))
       (or (= J8 M7) (not N7) (not U7))
       (or (= I8 L7) (not N7) (not U7))
       (or (= H8 K7) (not N7) (not U7))
       (or (= G8 J7) (not N7) (not U7))
       (or (= F8 H7) (not N7) (not U7))
       (or (= J9 L8) (not N7) (not U7))
       (or (= I9 K8) (not N7) (not U7))
       (or (= H9 J8) (not N7) (not U7))
       (or (= G9 I8) (not N7) (not U7))
       (or (= F9 H8) (not N7) (not U7))
       (or (= E9 G8) (not N7) (not U7))
       (or (= D9 F8) (not N7) (not U7))
       (or (= K9 M8) (not N7) (not U7))
       (or (= C9 N2) (not J5) (not W7))
       (or (= J9 B9) (not J5) (not W7))
       (or (= I9 A9) (not J5) (not W7))
       (or (= H9 Z8) (not J5) (not W7))
       (or (= G9 Y8) (not J5) (not W7))
       (or (= F9 X8) (not J5) (not W7))
       (or (= E9 W8) (not J5) (not W7))
       (or (= D9 V8) (not J5) (not W7))
       (or (= B9 Q6) (not J5) (not W7))
       (or (= A9 I2) (not J5) (not W7))
       (or (= Z8 M6) (not J5) (not W7))
       (or (= Y8 N6) (not J5) (not W7))
       (or (= X8 O6) (not J5) (not W7))
       (or (= W8 P6) (not J5) (not W7))
       (or (= V8 R6) (not J5) (not W7))
       (or (= K9 C9) (not J5) (not W7))
       (or (= Y6 O6) (not J5) (not T6))
       (or (= X6 P6) (not J5) (not T6))
       (or (= W6 Q6) (not J5) (not T6))
       (or (= V6 R6) (not J5) (not T6))
       (or (= M7 A7) (not J5) (not T6))
       (or (= L7 Z6) (not J5) (not T6))
       (or (= K7 Y6) (not J5) (not T6))
       (or (= J7 X6) (not J5) (not T6))
       (or (= I7 W6) (not J5) (not T6))
       (or (= H7 V6) (not J5) (not T6))
       (or (= A7 M6) (not J5) (not T6))
       (or (= Z6 N6) (not J5) (not T6))
       (or (= R6 T5) (not G5) (not K5))
       (or (= Q6 S5) (not G5) (not K5))
       (or (= P6 R5) (not G5) (not K5))
       (or (= O6 Q5) (not G5) (not K5))
       (or (= N6 P5) (not G5) (not K5))
       (or (= M6 O5) (not G5) (not K5))
       (or (= T5 1) (not G5) (not K5))
       (or (= S5 I5) (not G5) (not K5))
       (or (= R5 2) (not G5) (not K5))
       (or (= Q5 D5) (not G5) (not K5))
       (or (= P5 C5) (not G5) (not K5))
       (or (= O5 A5) (not G5) (not K5))
       (or (= R6 Z5) (not E5) (not L5))
       (or (= Q6 Y5) (not E5) (not L5))
       (or (= P6 X5) (not E5) (not L5))
       (or (= W5 D5) (not E5) (not L5))
       (or (= V5 C5) (not E5) (not L5))
       (or (= U5 A5) (not E5) (not L5))
       (or (= O6 W5) (not E5) (not L5))
       (or (= N6 V5) (not E5) (not L5))
       (or (= M6 U5) (not E5) (not L5))
       (or (= Z5 1) (not E5) (not L5))
       (or (= Y5 B5) (not E5) (not L5))
       (or (= X5 2) (not E5) (not L5))
       (or (= R6 L6) (not V3) (not N5))
       (or (= Q6 K6) (not V3) (not N5))
       (or (= P6 J6) (not V3) (not N5))
       (or (= O6 I6) (not V3) (not N5))
       (or (= N6 H6) (not V3) (not N5))
       (or (= M6 G6) (not V3) (not N5))
       (or (= L6 O2) (not V3) (not N5))
       (or (= K6 N4) (not V3) (not N5))
       (or (= J6 J2) (not V3) (not N5))
       (or (= I6 L4) (not V3) (not N5))
       (or (= H6 M4) (not V3) (not N5))
       (or (= G6 O4) (not V3) (not N5))
       (or (= D5 V4) (not V3) (not Q4))
       (or (= C5 U4) (not V3) (not Q4))
       (or (= B5 T4) (not V3) (not Q4))
       (or (= A5 S4) (not V3) (not Q4))
       (or (= V4 L4) (not V3) (not Q4))
       (or (= U4 M4) (not V3) (not Q4))
       (or (= T4 N4) (not V3) (not Q4))
       (or (= S4 O4) (not V3) (not Q4))
       (or (= O4 G4) (not G3) (not X3))
       (or (= N4 F4) (not G3) (not X3))
       (or (= M4 E4) (not G3) (not X3))
       (or (= L4 D4) (not G3) (not X3))
       (or (= G4 P2) (not G3) (not X3))
       (or (= F4 M2) (not G3) (not X3))
       (or (= E4 L2) (not G3) (not X3))
       (or (= D4 0) (not G3) (not X3))
       (or (= O4 K4) (not E3) (not Y3))
       (or (= N4 J4) (not E3) (not Y3))
       (or (= M4 I4) (not E3) (not Y3))
       (or (= L4 H4) (not E3) (not Y3))
       (or (= J4 M2) (not E3) (not Y3))
       (or (= I4 L2) (not E3) (not Y3))
       (or (= H4 K2) (not E3) (not Y3))
       (or (= K4 P2) (not E3) (not Y3))
       (or (not G1) (not D3) (not F3))
       (or (not Z) (not E3) (not Y3))
       (or Z (not E3) (not H3))
       (or Y (not G3) (not X3))
       (or (not Y) (not G3) (not J3))
       (or V (not N3) (not Q3))
       (or (not M) (not V3) (not N5))
       (or M (not V3) (not Q4))
       (or (not J) (not E5) (not L5))
       (or J (not E5) (not H5))
       (or I (not G5) (not K5))
       (or (not U6) (not G5) (= M7 G7))
       (or (not U6) (not G5) (= L7 F7))
       (or (not U6) (not G5) (= K7 E7))
       (or (not U6) (not G5) (= J7 D7))
       (or (not U6) (not G5) (= I7 C7))
       (or (not U6) (not G5) (= H7 B7))
       (or (not U6) (not G5) (= G7 A5))
       (or (not U6) (not G5) (= F7 C5))
       (or (not U6) (not G5) (= E7 D5))
       (or (not U6) (not G5) (= D7 2))
       (or (not U6) (not G5) (= C7 I5))
       (or (not U6) (not G5) (= B7 1))
       (or (not I) (not U6) (not G5))
       (or (not S6) (and U6 G5) (and J5 T6))
       (or (= J9 T8) (not S6) (not V7))
       (or (= I9 S8) (not S6) (not V7))
       (or (= H9 R8) (not S6) (not V7))
       (or (= G9 Q8) (not S6) (not V7))
       (or (= F9 P8) (not S6) (not V7))
       (or (= E9 O8) (not S6) (not V7))
       (or (= D9 N8) (not S6) (not V7))
       (or (= U8 N2) (not S6) (not V7))
       (or (= T8 I7) (not S6) (not V7))
       (or (= S8 0) (not S6) (not V7))
       (or (= R8 M7) (not S6) (not V7))
       (or (= Q8 L7) (not S6) (not V7))
       (or (= P8 K7) (not S6) (not V7))
       (or (= O8 J7) (not S6) (not V7))
       (or (= N8 H7) (not S6) (not V7))
       (or (= K9 U8) (not S6) (not V7))
       (or (and V3 Q4) (and R3 R4) (not P4))
       (or (= R6 F6) (not P4) (not M5))
       (or (= Q6 E6) (not P4) (not M5))
       (or (= P6 D6) (not P4) (not M5))
       (or (= O6 C6) (not P4) (not M5))
       (or (= N6 B6) (not P4) (not M5))
       (or (= M6 A6) (not P4) (not M5))
       (or (= F6 O2) (not P4) (not M5))
       (or (= E6 B5) (not P4) (not M5))
       (or (= D6 0) (not P4) (not M5))
       (or (= C6 D5) (not P4) (not M5))
       (or (= B6 C5) (not P4) (not M5))
       (or (= A6 A5) (not P4) (not M5))
       (or L (not P4) (not M5))
       (or (not L) (not P4) (not F5))
       (or (not T) (not S3) (not P3))
       (or (not R3) (and T3 I3) (and S3 P3))
       (or (= D5 Z4) (not R3) (not R4))
       (or (= C5 Y4) (not R3) (not R4))
       (or (= B5 X4) (not R3) (not R4))
       (or (= A5 W4) (not R3) (not R4))
       (or (= Z4 2) (not R3) (not R4))
       (or (= Y4 U3) (not R3) (not R4))
       (or (= X4 U3) (not R3) (not R4))
       (or (= W4 1) (not R3) (not R4))
       (or (= O4 C4) (not R3) (not W3))
       (or (= N4 B4) (not R3) (not W3))
       (or (= M4 A4) (not R3) (not W3))
       (or (= L4 Z3) (not R3) (not W3))
       (or (= C4 1) (not R3) (not W3))
       (or (= B4 U3) (not R3) (not W3))
       (or (= A4 U3) (not R3) (not W3))
       (or (= Z3 2) (not R3) (not W3))
       (or (not O) (not R3) (not R4))
       (or O (not R3) (not W3))
       (or (not Q2) (not P7) (not N9))
       (or Q2 (not P7) (not T7))
       (or W (not I3) (not O3))
       (or (not W) (not T3) (not I3))
       (or (not G) (not J5) (not W7))
       (or G (not J5) (not T6))
       (or F (not S6) (not V7))
       (or (not F) (not S6) (not O7))
       (or (not D) (not N7) (not U7))
       (or D (not N7) (not Q7))
       (or C (not S7) (not M9))
       (or (not M10) (not L9) (= A3 E10))
       (or (not M10) (not L9) (= Z2 J10))
       (or (not M10) (not L9) (= Y2 K10))
       (or (not M10) (not L9) (= X2 H10))
       (or (not M10) (not L9) (= V2 F10))
       (or (not M10) (not L9) (= U2 L10))
       (or (not M10) (not L9) (= T2 0))
       (or (not M10) (not L9) (= C3 T2))
       (or (not M10) (not L9) (= B3 I10))
       (or (not M10) (not L9) (= W2 G10))
       (or (not M10) (not L9) (= O1 B3))
       (or (not M10) (not L9) (= N1 A3))
       (or (not M10) (not L9) (= M1 Z2))
       (or (not M10) (not L9) (= L1 Y2))
       (or (not M10) (not L9) (= K1 X2))
       (or (not M10) (not L9) (= J1 W2))
       (or (not M10) (not L9) (= I1 V2))
       (or (not M10) (not L9) (= H1 U2))
       (or B (not M10) (not L9))
       (or (not L9) (= B (= A 0)))
       (or (not S7) (= C (= Z1 0)))
       (or (not P7) (= R7 (+ 1 I7)))
       (or (not P7) (and N7 Q7))
       (or (not N7) (= D (= N2 1)))
       (or (not N7) (and S6 O7))
       (or (not J5) (= G (= I2 0)))
       (or (not G5) (= H (= N2 1)))
       (or (not G5) (not (= H I)))
       (or (not G5) (= I5 (+ 1 B5)))
       (or (not G5) (and E5 H5))
       (or (not E5) (= J (= O2 1)))
       (or (not E5) (and P4 F5))
       (or (not V3) (= M (= J2 0)))
       a!1
       a!2
       (or (not P3) (= T (and R S)))
       (or (not P3) (= S (= K3 5)))
       (or (not P3) (= R (and P Q)))
       (or (not P3) (and N3 Q3))
       (or (not N3) (= V (= M2 U)))
       (or (not N3) (= U (+ 3 L2)))
       (or (not N3) (and I3 O3))
       (or (not I3) (= W (= P2 1)))
       (or (not I3) (and G3 J3))
       (or (not G3) (= Y (= X 0)))
       (or (not G3) (and E3 H3))
       (or (not E3) (and D3 F3))
       (or (not S6) (= F (= E 0)))
       (or (not P4) (= L (= K 0)))
       (or (not R3) (= N (= O2 1)))
       (or (not R3) (not (= N O)))
       (or (not S2) (and M10 L9))
       (= S2 true)
       (= F1 (or D1 E1))
       (= 2 v_274)))
      )
      (main_1 v_274
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
        C3
        H1
        I1
        J1
        K1
        L1
        M1
        N1
        O1
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2
        Z)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Int) (T Bool) (U Bool) (V Int) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Bool) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Bool) (C3 Bool) (D3 Bool) (E3 Bool) (F3 Int) (G3 Int) (H3 Int) (I3 Bool) (J3 Bool) (K3 Bool) (L3 Bool) (M3 Bool) (N3 Bool) (O3 Bool) (P3 Int) (Q3 Bool) (R3 Bool) (S3 Bool) (T3 Bool) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Bool) (L4 Bool) (M4 Bool) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Bool) (A5 Bool) (B5 Bool) (C5 Bool) (D5 Int) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Bool) (O6 Bool) (P6 Bool) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Bool) (J7 Bool) (K7 Bool) (L7 Bool) (M7 Int) (N7 Bool) (O7 Bool) (P7 Bool) (Q7 Bool) (R7 Bool) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Bool) (H9 Bool) (v_242 Int) (v_243 Int) ) 
    (=>
      (and
        (main_1 v_242
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
        D2
        E2
        F2
        G2
        H2)
        (let ((a!1 (or (not K3) (not (= (<= 6 H3) N))))
      (a!2 (or (not K3) (not (= (<= G3 4) O)))))
  (and (= 3 v_242)
       (= X (= A2 0))
       (= D1 (or B1 C1))
       (not (= D1 E1))
       (= C1 (= P1 0))
       (= B1 (or Z A1))
       (= A1 (= Y1 0))
       (= Z (or X Y))
       (or (and K7 O7) (and I7 P7) (and N6 Q7) (and E5 R7) (not N7))
       (or (and B5 F5) (and Z4 G5) (and K4 H5) (and Q3 I5) (not E5))
       (or (and M3 R3) (and B3 S3) (and Z2 T3) (not Q3))
       (or (= F9 X8) (not E5) (not R7))
       (or (= E9 W8) (not E5) (not R7))
       (or (= D9 V8) (not E5) (not R7))
       (or (= C9 U8) (not E5) (not R7))
       (or (= B9 T8) (not E5) (not R7))
       (or (= A9 S8) (not E5) (not R7))
       (or (= Z8 R8) (not E5) (not R7))
       (or (= Y8 Q8) (not E5) (not R7))
       (or (= X8 D2) (not E5) (not R7))
       (or (= W8 L6) (not E5) (not R7))
       (or (= V8 Y1) (not E5) (not R7))
       (or (= U8 H6) (not E5) (not R7))
       (or (= T8 I6) (not E5) (not R7))
       (or (= S8 J6) (not E5) (not R7))
       (or (= R8 K6) (not E5) (not R7))
       (or (= Q8 M6) (not E5) (not R7))
       (or (= N5 D5) (not B5) (not F5))
       (or (= M5 2) (not B5) (not F5))
       (or (= L5 Y4) (not B5) (not F5))
       (or (= K5 X4) (not B5) (not F5))
       (or (= M6 O5) (not B5) (not F5))
       (or (= L6 N5) (not B5) (not F5))
       (or (= K6 M5) (not B5) (not F5))
       (or (= J6 L5) (not B5) (not F5))
       (or (= I6 K5) (not B5) (not F5))
       (or (= H6 J5) (not B5) (not F5))
       (or (= O5 1) (not B5) (not F5))
       (or (= J5 V4) (not B5) (not F5))
       (or (= P5 V4) (not Z4) (not G5))
       (or (= T5 W4) (not Z4) (not G5))
       (or (= S5 2) (not Z4) (not G5))
       (or (= R5 Y4) (not Z4) (not G5))
       (or (= Q5 X4) (not Z4) (not G5))
       (or (= M6 U5) (not Z4) (not G5))
       (or (= L6 T5) (not Z4) (not G5))
       (or (= K6 S5) (not Z4) (not G5))
       (or (= J6 R5) (not Z4) (not G5))
       (or (= I6 Q5) (not Z4) (not G5))
       (or (= H6 P5) (not Z4) (not G5))
       (or (= U5 1) (not Z4) (not G5))
       (or (and Q3 L4) (and M3 M4) (not K4))
       (or (= M6 A6) (not K4) (not H5))
       (or (= L6 Z5) (not K4) (not H5))
       (or (= K6 Y5) (not K4) (not H5))
       (or (= J6 X5) (not K4) (not H5))
       (or (= I6 W5) (not K4) (not H5))
       (or (= H6 V5) (not K4) (not H5))
       (or (= A6 E2) (not K4) (not H5))
       (or (= Z5 W4) (not K4) (not H5))
       (or (= Y5 0) (not K4) (not H5))
       (or (= X5 Y4) (not K4) (not H5))
       (or (= W5 X4) (not K4) (not H5))
       (or (= V5 V4) (not K4) (not H5))
       (or (= M6 G6) (not Q3) (not I5))
       (or (= L6 F6) (not Q3) (not I5))
       (or (= K6 E6) (not Q3) (not I5))
       (or (= J6 D6) (not Q3) (not I5))
       (or (= I6 C6) (not Q3) (not I5))
       (or (= H6 B6) (not Q3) (not I5))
       (or (= G6 E2) (not Q3) (not I5))
       (or (= F6 I4) (not Q3) (not I5))
       (or (= E6 Z1) (not Q3) (not I5))
       (or (= D6 G4) (not Q3) (not I5))
       (or (= C6 H4) (not Q3) (not I5))
       (or (= B6 J4) (not Q3) (not I5))
       (or (= Q4 G4) (not Q3) (not L4))
       (or (= P4 H4) (not Q3) (not L4))
       (or (= Y4 Q4) (not Q3) (not L4))
       (or (= X4 P4) (not Q3) (not L4))
       (or (= W4 O4) (not Q3) (not L4))
       (or (= V4 N4) (not Q3) (not L4))
       (or (= O4 I4) (not Q3) (not L4))
       (or (= N4 J4) (not Q3) (not L4))
       (or (= J4 F4) (not Z2) (not T3))
       (or (= I4 E4) (not Z2) (not T3))
       (or (= H4 D4) (not Z2) (not T3))
       (or (= G4 C4) (not Z2) (not T3))
       (or (= F4 F2) (not Z2) (not T3))
       (or (= E4 C2) (not Z2) (not T3))
       (or (= D4 B2) (not Z2) (not T3))
       (or (= C4 A2) (not Z2) (not T3))
       (or (not X) (not Z2) (not T3))
       (or (not K) (not Q3) (not I5))
       (or K (not Q3) (not L4))
       (or J (not K4) (not H5))
       (or (not J) (not K4) (not A5))
       (or (not H) (not Z4) (not G5))
       (or H (not Z4) (not C5))
       (or G (not B5) (not F5))
       (or (not E) (not E5) (not R7))
       (or (not P6) (not B5) (= H7 B7))
       (or (not P6) (not B5) (= G7 A7))
       (or (not P6) (not B5) (= F7 Z6))
       (or (not P6) (not B5) (= E7 Y6))
       (or (not P6) (not B5) (= D7 X6))
       (or (not P6) (not B5) (= C7 W6))
       (or (not P6) (not B5) (= B7 V4))
       (or (not P6) (not B5) (= A7 X4))
       (or (not P6) (not B5) (= Z6 Y4))
       (or (not P6) (not B5) (= Y6 2))
       (or (not P6) (not B5) (= X6 D5))
       (or (not P6) (not B5) (= W6 1))
       (or (not G) (not P6) (not B5))
       (or (not O6) (not E5) (= H7 V6))
       (or (not O6) (not E5) (= G7 U6))
       (or (not O6) (not E5) (= F7 T6))
       (or (not O6) (not E5) (= E7 S6))
       (or (not O6) (not E5) (= D7 R6))
       (or (not O6) (not E5) (= C7 Q6))
       (or (not O6) (not E5) (= V6 H6))
       (or (not O6) (not E5) (= U6 I6))
       (or (not O6) (not E5) (= T6 J6))
       (or (not O6) (not E5) (= S6 K6))
       (or (not O6) (not E5) (= R6 L6))
       (or (not O6) (not E5) (= Q6 M6))
       (or E (not O6) (not E5))
       (or (not N6) (and P6 B5) (and O6 E5))
       (or (= L8 G7) (not N6) (not Q7))
       (or (= F9 P8) (not N6) (not Q7))
       (or (= E9 O8) (not N6) (not Q7))
       (or (= D9 N8) (not N6) (not Q7))
       (or (= C9 M8) (not N6) (not Q7))
       (or (= B9 L8) (not N6) (not Q7))
       (or (= A9 K8) (not N6) (not Q7))
       (or (= Z8 J8) (not N6) (not Q7))
       (or (= Y8 I8) (not N6) (not Q7))
       (or (= P8 D2) (not N6) (not Q7))
       (or (= O8 D7) (not N6) (not Q7))
       (or (= N8 0) (not N6) (not Q7))
       (or (= M8 H7) (not N6) (not Q7))
       (or (= K8 F7) (not N6) (not Q7))
       (or (= J8 E7) (not N6) (not Q7))
       (or (= I8 C7) (not N6) (not Q7))
       (or D (not N6) (not Q7))
       (or (and K3 N3) (and D3 O3) (not M3))
       (or (= R4 1) (not M3) (not M4))
       (or (= Y4 U4) (not M3) (not M4))
       (or (= X4 T4) (not M3) (not M4))
       (or (= W4 S4) (not M3) (not M4))
       (or (= V4 R4) (not M3) (not M4))
       (or (= U4 2) (not M3) (not M4))
       (or (= T4 P3) (not M3) (not M4))
       (or (= S4 P3) (not M3) (not M4))
       (or (= J4 X3) (not M3) (not R3))
       (or (= I4 W3) (not M3) (not R3))
       (or (= H4 V3) (not M3) (not R3))
       (or (= G4 U3) (not M3) (not R3))
       (or (= X3 1) (not M3) (not R3))
       (or (= W3 P3) (not M3) (not R3))
       (or (= V3 P3) (not M3) (not R3))
       (or (= U3 2) (not M3) (not R3))
       (or (= X7 2) (not K7) (not O7))
       (or (= Z7 1) (not K7) (not O7))
       (or (= Y7 M7) (not K7) (not O7))
       (or (= W7 H7) (not K7) (not O7))
       (or (= V7 G7) (not K7) (not O7))
       (or (= U7 F7) (not K7) (not O7))
       (or (= T7 E7) (not K7) (not O7))
       (or (= S7 C7) (not K7) (not O7))
       (or (= F9 Z7) (not K7) (not O7))
       (or (= E9 Y7) (not K7) (not O7))
       (or (= D9 X7) (not K7) (not O7))
       (or (= C9 W7) (not K7) (not O7))
       (or (= B9 V7) (not K7) (not O7))
       (or (= A9 U7) (not K7) (not O7))
       (or (= Z8 T7) (not K7) (not O7))
       (or (= Y8 S7) (not K7) (not O7))
       (or G2 (not K7) (not O7))
       (or (= E8 H7) (not I7) (not P7))
       (or (= D8 G7) (not I7) (not P7))
       (or (= C8 F7) (not I7) (not P7))
       (or (= B8 E7) (not I7) (not P7))
       (or (= A8 C7) (not I7) (not P7))
       (or (= F9 H8) (not I7) (not P7))
       (or (= E9 G8) (not I7) (not P7))
       (or (= D9 F8) (not I7) (not P7))
       (or (= C9 E8) (not I7) (not P7))
       (or (= B9 D8) (not I7) (not P7))
       (or (= A9 C8) (not I7) (not P7))
       (or (= Z8 B8) (not I7) (not P7))
       (or (= Y8 A8) (not I7) (not P7))
       (or (= H8 1) (not I7) (not P7))
       (or (= G8 D7) (not I7) (not P7))
       (or (= F8 2) (not I7) (not P7))
       (or (not B) (not I7) (not P7))
       (or B (not I7) (not L7))
       (or (not R) (not K3) (not N3))
       (or T (not I3) (not L3))
       (or (not U) (not D3) (not O3))
       (or U (not D3) (not J3))
       (or X (not C3) (not Z2))
       (or (= J4 B4) (not B3) (not S3))
       (or (= I4 A4) (not B3) (not S3))
       (or (= H4 Z3) (not B3) (not S3))
       (or (= G4 Y3) (not B3) (not S3))
       (or (= B4 F2) (not B3) (not S3))
       (or (= A4 C2) (not B3) (not S3))
       (or (= Z3 B2) (not B3) (not S3))
       (or (= Y3 0) (not B3) (not S3))
       (or W (not B3) (not S3))
       (or (not W) (not B3) (not E3))
       (or (not E1) (not I2) (not A3))
       (or (not M) (not M3) (not M4))
       (or M (not M3) (not R3))
       (or (not J7) (not N6) (not D))
       (or (not H9) (not N7) (= O2 F9))
       (or (not H9) (not N7) (= N2 E9))
       (or (not H9) (not N7) (= M2 B9))
       (or (not H9) (not N7) (= Y2 Q2))
       (or (not H9) (not N7) (= X2 P2))
       (or (not H9) (not N7) (= W2 O2))
       (or (not H9) (not N7) (= V2 N2))
       (or (not H9) (not N7) (= U2 M2))
       (or (not H9) (not N7) (= T2 L2))
       (or (not H9) (not N7) (= S2 K2))
       (or (not H9) (not N7) (= R2 J2))
       (or (not H9) (not N7) (= Q2 C9))
       (or (not H9) (not N7) (= P2 Y8))
       (or (not H9) (not N7) (= L2 A9))
       (or (not H9) (not N7) (= K2 Z8))
       (or (not H9) (not N7) (= J2 D9))
       (or (not A) (not N7) (not H9))
       (or (not N7) (= A (= P1 0)))
       (or (not E5) (= E (= Y1 0)))
       (or (not B5) (= F (= D2 1)))
       (or (not B5) (not (= F G)))
       (or (not B5) (= D5 (+ 1 W4)))
       (or (not B5) (and Z4 C5))
       (or (not Z4) (= H (= E2 1)))
       (or (not Z4) (and K4 A5))
       (or (not K4) (= J (= I 0)))
       (or (not Q3) (= K (= Z1 0)))
       (or (not Z2) (and I2 A3))
       (or (not N6) (= D (= C 0)))
       (or (not M3) (= L (= E2 1)))
       (or (not M3) (not (= L M)))
       (or (not K7) (= M7 (+ 1 D7)))
       (or (not K7) (and I7 L7))
       (or (not I7) (= B (= D2 1)))
       (or (not I7) (and J7 N6))
       a!1
       a!2
       (or (not K3) (= R (and Q P)))
       (or (not K3) (= P (and N O)))
       (or (not K3) (= Q (= F3 5)))
       (or (not K3) (and I3 L3))
       (or (not I3) (= T (= C2 S)))
       (or (not I3) (= S (+ 3 B2)))
       (or (not I3) (and D3 J3))
       (or (not D3) (= U (= F2 1)))
       (or (not D3) (and B3 E3))
       (or (not B3) (= W (= V 0)))
       (or (not B3) (and C3 Z2))
       (or (not G9) (and H9 N7))
       (= G9 true)
       (= Y (= Z1 0))
       (= 3 v_243)))
      )
      (main_1 v_243
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
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        Y2
        G2
        X)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Bool) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Bool) (v_42 Int) (v_43 Int) ) 
    (=>
      (and
        (main_1 v_42
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
        K1)
        (and (= 3 v_42)
     (= D (= B1 0))
     (= C (or A B))
     (= B (= C1 0))
     (= A (= D1 0))
     (= G (or F E))
     (not (= G H))
     (= F (= S 0))
     (or H (not L1) (not N1))
     (or (not M1) (and L1 N1))
     (or (not O1) (and P1 M1))
     (= O1 true)
     (= E (or C D))
     (= 4 v_43))
      )
      (main_1 v_43
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
        A)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Bool) (H Bool) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Bool) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Bool) (A2 Bool) (B2 Bool) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (main_1 v_64
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
        (let ((a!1 (or (not H2) (not (= (<= 6 E2) A))))
      (a!2 (or (not H2) (not (= (<= D2 4) B)))))
  (and (= 3 v_64)
       (not (= Q R))
       (= L (= M1 0))
       (= K (= N1 0))
       (= P (= C1 0))
       (= O (or N M))
       (= M (or K L))
       (= N (= L1 0))
       (or (not J2) (and K2 H2) (and L2 F2))
       (or G (not F2) (not I2))
       (or H (not A2) (not G2))
       (or (not J) (not Y1) (not B2))
       (or (not X1) (not V1) (not R))
       (or K (not Z1) (not W1))
       (or (not L2) (not F2) (not G))
       (or (not K2) (not H2) E)
       (or (not F2) (= G (= P1 F)))
       (or (not F2) (= F (+ 3 O1)))
       (or (not F2) (and A2 G2))
       a!1
       a!2
       (or (not H2) (= E (and C D)))
       (or (not H2) (= D (= C2 5)))
       (or (not H2) (= C (and A B)))
       (or (not H2) (and F2 I2))
       (or (not A2) (= H (= S1 1)))
       (or (not A2) (and Y1 B2))
       (or (not Y1) (= J (= I 0)))
       (or (not Y1) (and W1 Z1))
       (or (not W1) (and X1 V1))
       (= J2 true)
       (= Q (or O P))
       (= 5 v_65)))
      )
      (main_1 v_65
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
        K)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Int) (E Int) (F Bool) (G Int) (H Int) (I Int) (J Int) (K Int) (L Bool) (M Bool) (N Int) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Int) (U Bool) (V Bool) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Int) (E1 Bool) (F1 Bool) (G1 Int) (H1 Bool) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (N1 Bool) (O1 Bool) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Bool) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Bool) (A3 Bool) (B3 Bool) (C3 Int) (D3 Int) (E3 Int) (F3 Int) (G3 Int) (H3 Int) (I3 Bool) (J3 Int) (K3 Int) (L3 Int) (M3 Bool) (N3 Bool) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Bool) (S3 Int) (T3 Int) (U3 Int) (V3 Bool) (W3 Bool) (X3 Bool) (Y3 Bool) (Z3 Bool) (A4 Bool) (B4 Bool) (C4 Int) (D4 Bool) (E4 Bool) (F4 Bool) (G4 Bool) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Bool) (Y4 Bool) (Z4 Bool) (A5 Int) (B5 Int) (C5 Int) (D5 Int) (E5 Int) (F5 Int) (G5 Int) (H5 Int) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Bool) (N5 Bool) (O5 Bool) (P5 Bool) (Q5 Int) (R5 Bool) (S5 Bool) (T5 Bool) (U5 Bool) (V5 Bool) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Bool) (B7 Bool) (C7 Bool) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Int) (L7 Int) (M7 Int) (N7 Int) (O7 Int) (P7 Int) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Bool) (W7 Bool) (X7 Bool) (Y7 Bool) (Z7 Int) (A8 Bool) (B8 Bool) (C8 Bool) (D8 Bool) (E8 Bool) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Int) (J9 Int) (K9 Int) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Bool) (U9 Bool) (V9 Bool) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Int) (K10 Int) (L10 Int) (M10 Int) (N10 Int) (O10 Int) (P10 Int) (Q10 Int) (R10 Int) (S10 Int) (T10 Int) (U10 Bool) (V10 Bool) (W10 Int) (X10 Int) (Y10 Int) (Z10 Int) (A11 Int) (B11 Int) (C11 Int) (D11 Int) (E11 Int) (F11 Int) (G11 Int) (H11 Bool) (I11 Bool) (J11 Int) (K11 Int) (L11 Bool) (M11 Bool) (N11 Bool) (O11 Int) (P11 Int) (Q11 Int) (R11 Int) (S11 Bool) (T11 Bool) (U11 Bool) (V11 Bool) (W11 Bool) (v_309 Int) (v_310 Int) ) 
    (=>
      (and
        (main_1 v_309
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
        A3)
        (let ((a!1 (or (not X3) (not (= (<= 6 U3) Y))))
      (a!2 (or (not X3) (not (= (<= T3 4) Z)))))
  (and (= 4 v_309)
       (= M1 (or K1 L1))
       (not (= M1 N1))
       (= L1 (= I2 0))
       (= K1 (or I1 J1))
       (= J1 (= R2 0))
       (= I1 (= S2 0))
       (or (and R5 E8) (not A8) (and D8 A7) (and C8 V7) (and B8 X7))
       (or (and X4 U5) (and D4 V5) (not R5) (and T5 M5) (and S5 O5))
       (or (and Z3 E4) (and O3 F4) (and N3 G4) (not D4))
       (or (= C Q11) (not U10) (not N11))
       (or (= D R11) (not U10) (not N11))
       (or (= R11 E11) (not U10) (not N11))
       (or (= Q11 G11) (not U10) (not N11))
       (or (not T9) (and A8 U9) (and X7 V9))
       (or (not E2) (not U10) (not N11))
       (or (= M10 E10) (not X7) (not V9))
       (or (= T10 L10) (not X7) (not V9))
       (or (= S10 K10) (not X7) (not V9))
       (or (= R10 J10) (not X7) (not V9))
       (or (= Q10 I10) (not X7) (not V9))
       (or (= P10 H10) (not X7) (not V9))
       (or (= O10 G10) (not X7) (not V9))
       (or (= N10 F10) (not X7) (not V9))
       (or (= L10 2) (not X7) (not V9))
       (or (= K10 Z7) (not X7) (not V9))
       (or (= J10 1) (not X7) (not V9))
       (or (= I10 U7) (not X7) (not V9))
       (or (= H10 T7) (not X7) (not V9))
       (or (= G10 S7) (not X7) (not V9))
       (or (= F10 R7) (not X7) (not V9))
       (or (= E10 P7) (not X7) (not V9))
       (or (not A7) (and R5 B7) (and O5 C7))
       (or (not O) (not W7) (not A7))
       (or (= U7 O7) (not O5) (not C7))
       (or (= T7 N7) (not O5) (not C7))
       (or (= S7 M7) (not O5) (not C7))
       (or (= R7 L7) (not O5) (not C7))
       (or (= Q7 K7) (not O5) (not C7))
       (or (= P7 J7) (not O5) (not C7))
       (or (= O7 I5) (not O5) (not C7))
       (or (= N7 K5) (not O5) (not C7))
       (or (= M7 L5) (not O5) (not C7))
       (or (= L7 2) (not O5) (not C7))
       (or (= K7 Q5) (not O5) (not C7))
       (or (= J7 1) (not O5) (not C7))
       (or (= W4 S4) (not N3) (not G4))
       (or (= V4 R4) (not N3) (not G4))
       (or (= U4 Q4) (not N3) (not G4))
       (or (= T4 P4) (not N3) (not G4))
       (or (= S4 Y2) (not N3) (not G4))
       (or (= R4 V2) (not N3) (not G4))
       (or (= Q4 U2) (not N3) (not G4))
       (or (= P4 T2) (not N3) (not G4))
       (or (not A3) (not N3) (not G4))
       (or (not Z2) (not X7) (not V9))
       (or (not V10) (not T9) (= G W10))
       (or (not V10) (not T9) (= K D11))
       (or (not V10) (not T9) (= J C11))
       (or (not V10) (not T9) (= I A11))
       (or (not V10) (not T9) (= H Y10))
       (or (not V10) (not T9) (= A11 P10))
       (or (not V10) (not T9) (= G11 B11))
       (or (not V10) (not T9) (= F11 Z10))
       (or (not V10) (not T9) (= E11 X10))
       (or (not V10) (not T9) (= D11 M10))
       (or (not V10) (not T9) (= C11 N10))
       (or (not V10) (not T9) (= B11 O10))
       (or (not V10) (not T9) (= Z10 Q10))
       (or (not V10) (not T9) (= Y10 R10))
       (or (not V10) (not T9) (= X10 S10))
       (or (not V10) (not T9) (= W10 T10))
       (or (not F) (not T9) (not V10))
       (or (not D8) (not A7) (= S9 C9))
       (or (not D8) (not A7) (= R9 B9))
       (or (not D8) (not A7) (= Q9 A9))
       (or (not D8) (not A7) (= P9 Z8))
       (or (not D8) (not A7) (= O9 Y8))
       (or (not D8) (not A7) (= N9 X8))
       (or (not D8) (not A7) (= M9 W8))
       (or (not D8) (not A7) (= L9 V8))
       (or (not D8) (not A7) (= C9 W2))
       (or (not D8) (not A7) (= B9 Q7))
       (or (not D8) (not A7) (= A9 0))
       (or (not D8) (not A7) (= Z8 U7))
       (or (not D8) (not A7) (= Y8 T7))
       (or (not D8) (not A7) (= X8 S7))
       (or (not D8) (not A7) (= W8 R7))
       (or (not D8) (not A7) (= V8 P7))
       (or (not D8) (not A7) O)
       (or (and D4 Y4) (and Z3 Z4) (not X4))
       (or (= Z6 N6) (not X4) (not U5))
       (or (= Y6 M6) (not X4) (not U5))
       (or (= X6 L6) (not X4) (not U5))
       (or (= W6 K6) (not X4) (not U5))
       (or (= V6 J6) (not X4) (not U5))
       (or (= U6 I6) (not X4) (not U5))
       (or (= N6 X2) (not X4) (not U5))
       (or (= M6 J5) (not X4) (not U5))
       (or (= L6 0) (not X4) (not U5))
       (or (= K6 L5) (not X4) (not U5))
       (or (= J6 K5) (not X4) (not U5))
       (or (= I6 I5) (not X4) (not U5))
       (or U (not X4) (not U5))
       (or (not U) (not X4) (not N5))
       (or (not C8) (not V7) (= S9 U8))
       (or (not C8) (not V7) (= R9 T8))
       (or (not C8) (not V7) (= Q9 S8))
       (or (not C8) (not V7) (= P9 R8))
       (or (not C8) (not V7) (= O9 Q8))
       (or (not C8) (not V7) (= N9 P8))
       (or (not C8) (not V7) (= M9 O8))
       (or (not C8) (not V7) (= L9 N8))
       (or (not C8) (not V7) (= U8 1))
       (or (not C8) (not V7) (= T8 Q7))
       (or (not C8) (not V7) (= S8 2))
       (or (not C8) (not V7) (= R8 U7))
       (or (not C8) (not V7) (= Q8 T7))
       (or (not C8) (not V7) (= P8 S7))
       (or (not C8) (not V7) (= O8 R7))
       (or (not C8) (not V7) (= N8 P7))
       (or (not B8) (not X7) (= I8 T7))
       (or (not B8) (not X7) (= H8 S7))
       (or (not B8) (not X7) (= G8 R7))
       (or (not B8) (not X7) (= F8 P7))
       (or (not B8) (not X7) (= S9 M8))
       (or (not B8) (not X7) (= R9 L8))
       (or (not B8) (not X7) (= Q9 K8))
       (or (not B8) (not X7) (= P9 J8))
       (or (not B8) (not X7) (= O9 I8))
       (or (not B8) (not X7) (= N9 H8))
       (or (not B8) (not X7) (= M9 G8))
       (or (not B8) (not X7) (= L9 F8))
       (or (not B8) (not X7) (= M8 1))
       (or (not B8) (not X7) (= L8 Z7))
       (or (not B8) (not X7) (= K8 2))
       (or (not B8) (not X7) (= J8 U7))
       (or Z2 (not B8) (not X7))
       (or (not U9) (= W9 L9) (not A8))
       (or (not U9) (= M10 W9) (not A8))
       (or (= T10 D10) (not U9) (not A8))
       (or (= S10 C10) (not U9) (not A8))
       (or (= R10 B10) (not U9) (not A8))
       (or (= Q10 A10) (not U9) (not A8))
       (or (= P10 Z9) (not U9) (not A8))
       (or (= O10 Y9) (not U9) (not A8))
       (or (= N10 X9) (not U9) (not A8))
       (or (not U9) (= D10 Q9) (not A8))
       (or (= C10 R9) (not U9) (not A8))
       (or (not U9) (= B10 S9) (not A8))
       (or (= A10 P9) (not U9) (not A8))
       (or (not U9) (= Z9 O9) (not A8))
       (or (not U9) (= Y9 N9) (not A8))
       (or (not U9) (= X9 M9) (not A8))
       (or (not U9) L (not A8))
       (or (not T5) (not M5) (= Z6 H6))
       (or (not T5) (not M5) (= Y6 G6))
       (or (not T5) (not M5) (= X6 F6))
       (or (not T5) (not M5) (= W6 E6))
       (or (not T5) (not M5) (= V6 D6))
       (or (not T5) (not M5) (= U6 C6))
       (or (not T5) (not M5) (= H6 1))
       (or (not T5) (not M5) (= G6 J5))
       (or (not T5) (not M5) (= F6 2))
       (or (not T5) (not M5) (= E6 L5))
       (or (not T5) (not M5) (= D6 K5))
       (or (not T5) (not M5) (= C6 I5))
       (or (not S5) (not O5) (= Z5 2))
       (or (not S5) (not O5) (= Y5 L5))
       (or (not S5) (not O5) (= X5 K5))
       (or (not S5) (not O5) (= W5 I5))
       (or (not S5) (not O5) (= Z6 B6))
       (or (not S5) (not O5) (= Y6 A6))
       (or (not S5) (not O5) (= X6 Z5))
       (or (not S5) (not O5) (= W6 Y5))
       (or (not S5) (not O5) (= V6 X5))
       (or (not S5) (not O5) (= U6 W5))
       (or (not S5) (not O5) (= B6 1))
       (or (not S5) (not O5) (= A6 Q5))
       (or (= G7 W6) (not R5) (not B7))
       (or (= F7 X6) (not R5) (not B7))
       (or (= E7 Y6) (not R5) (not B7))
       (or (= U7 I7) (not R5) (not B7))
       (or (= T7 H7) (not R5) (not B7))
       (or (= S7 G7) (not R5) (not B7))
       (or (= R7 F7) (not R5) (not B7))
       (or (= Q7 E7) (not R5) (not B7))
       (or (= P7 D7) (not R5) (not B7))
       (or (= I7 U6) (not R5) (not B7))
       (or (= H7 V6) (not R5) (not B7))
       (or (= D7 Z6) (not R5) (not B7))
       (or (= S9 K9) (not E8) (not R5))
       (or (= R9 J9) (not E8) (not R5))
       (or (= Q9 I9) (not E8) (not R5))
       (or (= P9 H9) (not E8) (not R5))
       (or (= O9 G9) (not E8) (not R5))
       (or (= N9 F9) (not E8) (not R5))
       (or (= M9 E9) (not E8) (not R5))
       (or (= L9 D9) (not E8) (not R5))
       (or (= K9 W2) (not E8) (not R5))
       (or (= J9 Y6) (not E8) (not R5))
       (or (= I9 R2) (not E8) (not R5))
       (or (= H9 U6) (not E8) (not R5))
       (or (= G9 V6) (not E8) (not R5))
       (or (= F9 W6) (not E8) (not R5))
       (or (= E9 X6) (not E8) (not R5))
       (or (= D9 Z6) (not E8) (not R5))
       (or (= D5 T4) (not D4) (not Y4))
       (or (= C5 U4) (not D4) (not Y4))
       (or (= B5 V4) (not D4) (not Y4))
       (or (= L5 D5) (not D4) (not Y4))
       (or (= K5 C5) (not D4) (not Y4))
       (or (= J5 B5) (not D4) (not Y4))
       (or (= I5 A5) (not D4) (not Y4))
       (or (= A5 W4) (not D4) (not Y4))
       (or (= Z6 T6) (not V5) (not D4))
       (or (= Y6 S6) (not V5) (not D4))
       (or (= X6 R6) (not V5) (not D4))
       (or (= W6 Q6) (not V5) (not D4))
       (or (= V6 P6) (not V5) (not D4))
       (or (= U6 O6) (not V5) (not D4))
       (or (= T6 X2) (not V5) (not D4))
       (or (= S6 V4) (not V5) (not D4))
       (or (= R6 S2) (not V5) (not D4))
       (or (= Q6 T4) (not V5) (not D4))
       (or (= P6 U4) (not V5) (not D4))
       (or (= O6 W4) (not V5) (not D4))
       (or (and Q3 B4) (not Z3) (and A4 X3))
       (or (= L5 H5) (not Z3) (not Z4))
       (or (= K5 G5) (not Z3) (not Z4))
       (or (= J5 F5) (not Z3) (not Z4))
       (or (= I5 E5) (not Z3) (not Z4))
       (or (= H5 2) (not Z3) (not Z4))
       (or (= G5 C4) (not Z3) (not Z4))
       (or (= F5 C4) (not Z3) (not Z4))
       (or (= E5 1) (not Z3) (not Z4))
       (or (= K4 1) (not Z3) (not E4))
       (or (= J4 C4) (not Z3) (not E4))
       (or (= I4 C4) (not Z3) (not E4))
       (or (= H4 2) (not Z3) (not E4))
       (or (= W4 K4) (not Z3) (not E4))
       (or (= V4 J4) (not Z3) (not E4))
       (or (= U4 I4) (not Z3) (not E4))
       (or (= T4 H4) (not Z3) (not E4))
       (or E1 (not Y3) (not V3))
       (or A3 (not P3) (not N3))
       (or (= W4 O4) (not F4) (not O3))
       (or (= V4 N4) (not F4) (not O3))
       (or (= U4 M4) (not F4) (not O3))
       (or (= T4 L4) (not F4) (not O3))
       (or (= O4 Y2) (not F4) (not O3))
       (or (= N4 V2) (not F4) (not O3))
       (or (= M4 U2) (not F4) (not O3))
       (or (= L4 0) (not F4) (not O3))
       (or H1 (not F4) (not O3))
       (or (not H1) (not R3) (not O3))
       (or F1 (not Q3) (not W3))
       (or (not F1) (not Q3) (not B4))
       (or (not A4) (not C1) (not X3))
       (or (not X) (not Z3) (not Z4))
       (or X (not Z3) (not E4))
       (or V (not D4) (not Y4))
       (or (not V) (not V5) (not D4))
       (or S (not P5) (not M5))
       (or (not S) (not T5) (not M5))
       (or (not R) (not O5) (not C7))
       (or R (not S5) (not O5))
       (or P (not R5) (not B7))
       (or (not P) (not E8) (not R5))
       (or M (not V7) (not Y7))
       (or (not M) (not C8) (not V7))
       (or (not L11) (and H11 M11) (and U10 N11))
       (or (= M3 I3) (not L11) (not S11))
       (or (= Q1 D3) (not L11) (not S11))
       (or (= P1 C3) (not L11) (not S11))
       (or (= K3 K) (not L11) (not S11))
       (or (= D3 G) (not L11) (not S11))
       (or (= C3 2) (not L11) (not S11))
       (or (= L3 F11) (not L11) (not S11))
       (or (= J3 H) (not L11) (not S11))
       (or (= H3 D) (not L11) (not S11))
       (or (= G3 I) (not L11) (not S11))
       (or (= F3 C) (not L11) (not S11))
       (or (= E3 J) (not L11) (not S11))
       (or (= X1 L3) (not L11) (not S11))
       (or (= W1 K3) (not L11) (not S11))
       (or (= V1 J3) (not L11) (not S11))
       (or (= U1 H3) (not L11) (not S11))
       (or (= T1 G3) (not L11) (not S11))
       (or (= S1 F3) (not L11) (not S11))
       (or (= R1 E3) (not L11) (not S11))
       (or I3 (not L11) (not S11))
       (or E2 (not I11) (not U10))
       (or (= C O11) (not M11) (not H11))
       (or (= D P11) (not M11) (not H11))
       (or (= P11 J11) (not M11) (not H11))
       (or (= O11 K11) (not M11) (not H11))
       (or (not N1) (not V11) (not T11))
       (or (not U10) (and V10 T9))
       (or (not T9) (= F (= E 0)))
       (or (not M5) (= S (= X2 1)))
       (or (not M5) (and X4 N5))
       a!1
       a!2
       (or (not X3) (= C1 (and A1 B1)))
       (or (not X3) (= B1 (= S3 5)))
       (or (not X3) (= A1 (and Y Z)))
       (or (not X3) (and V3 Y3))
       (or (not U11) (and V11 T11))
       (or (not X7) (= Z7 (+ 1 Q7)))
       (or (not X7) (and V7 Y7))
       (or (not V7) (= M (= W2 1)))
       (or (not V7) (and A7 W7))
       (or (not A7) (= O (= N 0)))
       (or (not O5) (= Q (= W2 1)))
       (or (not O5) (not (= Q R)))
       (or (not O5) (= Q5 (+ 1 J5)))
       (or (not O5) (and P5 M5))
       (or (not N3) (and W11 U11))
       (or (not X4) (= U (= T 0)))
       (or (not A8) (= L (= I2 0)))
       (or (not R5) (= P (= R2 0)))
       (or (not D4) (= V (= S2 0)))
       (or (not Z3) (= W (= X2 1)))
       (or (not Z3) (not (= W X)))
       (or (not V3) (= E1 (= V2 D1)))
       (or (not V3) (= D1 (+ 3 U2)))
       (or (not V3) (and Q3 W3))
       (or (not Q3) (= F1 (= Y2 1)))
       (or (not Q3) (and O3 R3))
       (or (not O3) (= H1 (= G1 0)))
       (or (not O3) (and P3 N3))
       (or (not B3) (and L11 S11))
       (or (not H11) (= A (= F11 1)))
       (or (not H11) (not (= A B)))
       (or (not H11) (= K11 (ite B G11 0)))
       (or (not H11) (= J11 (+ 1 E11)))
       (or (not H11) (and I11 U10))
       (= B3 true)
       (= O1 true)
       (not (= N1 O1))
       (= 1 v_310)))
      )
      (main_1 v_310
        P1
        Q1
        R1
        S1
        T1
        U1
        M3
        V1
        W1
        X1
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
        A3)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Int) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (T Bool) (U Int) (V Bool) (W Bool) (X Int) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Bool) (F1 Bool) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Bool) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Bool) (Q2 Bool) (R2 Bool) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Int) (Z2 Int) (A3 Int) (B3 Int) (C3 Bool) (D3 Bool) (E3 Bool) (F3 Bool) (G3 Bool) (H3 Int) (I3 Int) (J3 Int) (K3 Bool) (L3 Bool) (M3 Bool) (N3 Bool) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Int) (S3 Bool) (T3 Bool) (U3 Bool) (V3 Bool) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Int) (J4 Int) (K4 Int) (L4 Int) (M4 Bool) (N4 Bool) (O4 Bool) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Int) (Y4 Int) (Z4 Int) (A5 Int) (B5 Bool) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Int) (G5 Bool) (H5 Bool) (I5 Bool) (J5 Bool) (K5 Bool) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Int) (M6 Int) (N6 Int) (O6 Int) (P6 Bool) (Q6 Bool) (R6 Bool) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Int) (H7 Int) (I7 Int) (J7 Int) (K7 Bool) (L7 Bool) (M7 Bool) (N7 Bool) (O7 Int) (P7 Bool) (Q7 Bool) (R7 Bool) (S7 Bool) (T7 Bool) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Int) (F9 Int) (G9 Int) (H9 Int) (I9 Bool) (J9 Bool) (K9 Bool) (L9 Int) (M9 Int) (N9 Int) (O9 Int) (P9 Int) (Q9 Int) (R9 Int) (S9 Int) (T9 Int) (U9 Int) (V9 Int) (W9 Int) (X9 Int) (Y9 Int) (Z9 Int) (A10 Int) (B10 Int) (C10 Int) (D10 Int) (E10 Int) (F10 Int) (G10 Int) (H10 Int) (I10 Int) (J10 Bool) (K10 Bool) (L10 Bool) (M10 Bool) (N10 Bool) (v_274 Int) (v_275 Int) ) 
    (=>
      (and
        (main_1 v_274
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
        Q2)
        (let ((a!1 (or (not M3) (not (= (<= 6 J3) P))))
      (a!2 (or (not M3) (not (= (<= I3 4) Q)))))
  (and (= 4 v_274)
       (= D1 (or B1 C1))
       (not (= D1 E1))
       (= C1 (= Y1 0))
       (= B1 (or Z A1))
       (= A1 (= H2 0))
       (= Z (= I2 0))
       (or (and P6 S7) (and G5 T7) (not P7) (and R7 K7) (and Q7 M7))
       (or (and M4 J5) (and S3 K5) (not G5) (and I5 B5) (and H5 D5))
       (or (and C3 V3) (not S3) (and U3 D3) (and T3 O3))
       (or (not I9) (and P7 J9) (and M7 K9))
       (or (= I10 A10) (not M7) (not K9))
       (or (= H10 Z9) (not M7) (not K9))
       (or (= G10 Y9) (not M7) (not K9))
       (or (= F10 X9) (not M7) (not K9))
       (or (= E10 W9) (not M7) (not K9))
       (or (= D10 V9) (not M7) (not K9))
       (or (= C10 U9) (not M7) (not K9))
       (or (= B10 T9) (not M7) (not K9))
       (or (= A10 2) (not M7) (not K9))
       (or (= Z9 O7) (not M7) (not K9))
       (or (= Y9 1) (not M7) (not K9))
       (or (= X9 J7) (not M7) (not K9))
       (or (= W9 I7) (not M7) (not K9))
       (or (= V9 H7) (not M7) (not K9))
       (or (= U9 G7) (not M7) (not K9))
       (or (= T9 E7) (not M7) (not K9))
       (or (= K4 G4) (not C3) (not V3))
       (or (= J4 F4) (not C3) (not V3))
       (or (= I4 E4) (not C3) (not V3))
       (or (= H4 O2) (not C3) (not V3))
       (or (= L4 H4) (not C3) (not V3))
       (or (= G4 L2) (not C3) (not V3))
       (or (= F4 K2) (not C3) (not V3))
       (or (= E4 J2) (not C3) (not V3))
       (or (not P6) (and R6 D5) (and Q6 G5))
       (or (= N8 I7) (not P6) (not S7))
       (or (= M8 H7) (not P6) (not S7))
       (or (= L8 G7) (not P6) (not S7))
       (or (= K8 E7) (not P6) (not S7))
       (or (= D9 N8) (not P6) (not S7))
       (or (= H9 R8) (not P6) (not S7))
       (or (= G9 Q8) (not P6) (not S7))
       (or (= F9 P8) (not P6) (not S7))
       (or (= E9 O8) (not P6) (not S7))
       (or (= C9 M8) (not P6) (not S7))
       (or (= B9 L8) (not P6) (not S7))
       (or (= A9 K8) (not P6) (not S7))
       (or (= R8 M2) (not P6) (not S7))
       (or (= Q8 F7) (not P6) (not S7))
       (or (= P8 0) (not P6) (not S7))
       (or (= O8 J7) (not P6) (not S7))
       (or (not P2) (not M7) (not K9))
       (or (not R7) (not K7) (= J8 1))
       (or (not R7) (not K7) (= I8 F7))
       (or (not R7) (not K7) (= H8 2))
       (or (not R7) (not K7) (= G8 J7))
       (or (not R7) (not K7) (= F8 I7))
       (or (not R7) (not K7) (= E8 H7))
       (or (not R7) (not K7) (= D8 G7))
       (or (not R7) (not K7) (= C8 E7))
       (or (not R7) (not K7) (= D9 F8))
       (or (not R7) (not K7) (= H9 J8))
       (or (not R7) (not K7) (= G9 I8))
       (or (not R7) (not K7) (= F9 H8))
       (or (not R7) (not K7) (= E9 G8))
       (or (not R7) (not K7) (= C9 E8))
       (or (not R7) (not K7) (= B9 D8))
       (or (not R7) (not K7) (= A9 C8))
       (or (not Q7) (not M7) (= B8 1))
       (or (not Q7) (not M7) (= A8 O7))
       (or (not Q7) (not M7) (= Z7 2))
       (or (not Q7) (not M7) (= Y7 J7))
       (or (not Q7) (not M7) (= X7 I7))
       (or (not Q7) (not M7) (= W7 H7))
       (or (not Q7) (not M7) (= V7 G7))
       (or (not Q7) (not M7) (= U7 E7))
       (or (not Q7) (not M7) (= D9 X7))
       (or (not Q7) (not M7) (= H9 B8))
       (or (not Q7) (not M7) (= G9 A8))
       (or (not Q7) (not M7) (= F9 Z7))
       (or (not Q7) (not M7) (= E9 Y7))
       (or (not Q7) (not M7) (= C9 W7))
       (or (not Q7) (not M7) (= B9 V7))
       (or (not Q7) (not M7) (= A9 U7))
       (or P2 (not Q7) (not M7))
       (or (= R9 G9) (not P7) (not J9))
       (or (= I10 S9) (not P7) (not J9))
       (or (= H10 R9) (not P7) (not J9))
       (or (= G10 Q9) (not P7) (not J9))
       (or (= F10 P9) (not P7) (not J9))
       (or (= E10 O9) (not P7) (not J9))
       (or (= D10 N9) (not P7) (not J9))
       (or (= C10 M9) (not P7) (not J9))
       (or (= B10 L9) (not P7) (not J9))
       (or (= S9 F9) (not P7) (not J9))
       (or (= Q9 H9) (not P7) (not J9))
       (or (= P9 E9) (not P7) (not J9))
       (or (= O9 D9) (not P7) (not J9))
       (or (= N9 C9) (not P7) (not J9))
       (or (= M9 B9) (not P7) (not J9))
       (or (= L9 A9) (not P7) (not J9))
       (or (not I5) (not B5) (= W5 1))
       (or (not I5) (not B5) (= V5 Y4))
       (or (not I5) (not B5) (= O6 W5))
       (or (not I5) (not B5) (= N6 V5))
       (or (not I5) (not B5) (= M6 U5))
       (or (not I5) (not B5) (= L6 T5))
       (or (not I5) (not B5) (= K6 S5))
       (or (not I5) (not B5) (= J6 R5))
       (or (not I5) (not B5) (= U5 2))
       (or (not I5) (not B5) (= T5 A5))
       (or (not I5) (not B5) (= S5 Z4))
       (or (not I5) (not B5) (= R5 X4))
       (or (not H5) (not D5) (= O6 Q5))
       (or (not H5) (not D5) (= N6 P5))
       (or (not H5) (not D5) (= M6 O5))
       (or (not H5) (not D5) (= L6 N5))
       (or (not H5) (not D5) (= K6 M5))
       (or (not H5) (not D5) (= J6 L5))
       (or (not H5) (not D5) (= Q5 1))
       (or (not H5) (not D5) (= P5 F5))
       (or (not H5) (not D5) (= O5 2))
       (or (not H5) (not D5) (= N5 A5))
       (or (not H5) (not D5) (= M5 Z4))
       (or (not H5) (not D5) (= L5 X4))
       (or (= D9 V8) (not T7) (not G5))
       (or (= H9 Z8) (not T7) (not G5))
       (or (= G9 Y8) (not T7) (not G5))
       (or (= F9 X8) (not T7) (not G5))
       (or (= E9 W8) (not T7) (not G5))
       (or (= C9 U8) (not T7) (not G5))
       (or (= B9 T8) (not T7) (not G5))
       (or (= A9 S8) (not T7) (not G5))
       (or (= Z8 M2) (not T7) (not G5))
       (or (= Y8 N6) (not T7) (not G5))
       (or (= X8 H2) (not T7) (not G5))
       (or (= W8 J6) (not T7) (not G5))
       (or (= V8 K6) (not T7) (not G5))
       (or (= U8 L6) (not T7) (not G5))
       (or (= T8 M6) (not T7) (not G5))
       (or (= S8 O6) (not T7) (not G5))
       (or (and F3 Q3) (not O3) (and P3 M3))
       (or V (not K3) (not N3))
       (or (not Y) (not G3) (not D3))
       (or W (not L3) (not F3))
       (or (not W) (not Q3) (not F3))
       (or (not T) (not P3) (not M3))
       (or J (not B5) (not E5))
       (or (not J) (not I5) (not B5))
       (or I (not H5) (not D5))
       (or (not R6) (not D5) (= Z6 F5))
       (or (not R6) (not D5) (= Y6 1))
       (or (not R6) (not D5) (= J7 D7))
       (or (not R6) (not D5) (= I7 C7))
       (or (not R6) (not D5) (= H7 B7))
       (or (not R6) (not D5) (= G7 A7))
       (or (not R6) (not D5) (= F7 Z6))
       (or (not R6) (not D5) (= E7 Y6))
       (or (not R6) (not D5) (= D7 X4))
       (or (not R6) (not D5) (= C7 Z4))
       (or (not R6) (not D5) (= B7 A5))
       (or (not R6) (not D5) (= A7 2))
       (or (not I) (not R6) (not D5))
       (or (not Q6) (not G5) (= V6 L6))
       (or (not Q6) (not G5) (= T6 N6))
       (or (not Q6) (not G5) (= X6 J6))
       (or (not Q6) (not G5) (= W6 K6))
       (or (not Q6) (not G5) (= S6 O6))
       (or (not Q6) (not G5) (= J7 X6))
       (or (not Q6) (not G5) (= I7 W6))
       (or (not Q6) (not G5) (= H7 V6))
       (or (not Q6) (not G5) (= G7 U6))
       (or (not Q6) (not G5) (= F7 T6))
       (or (not Q6) (not G5) (= E7 S6))
       (or (not Q6) (not G5) (= U6 M6))
       (or (not O4) (not O3) (= A5 W4))
       (or (not O4) (not O3) (= Z4 V4))
       (or (not O4) (not O3) (= Y4 U4))
       (or (not O4) (not O3) (= X4 T4))
       (or (not O4) (not O3) (= W4 2))
       (or (not O4) (not O3) (= V4 R3))
       (or (not O4) (not O3) (= U4 R3))
       (or (not O4) (not O3) (= T4 1))
       (or (not O) (not O4) (not O3))
       (or (and S3 N4) (not M4) (and O4 O3))
       (or (= X5 X4) (not M4) (not J5))
       (or (= O6 C6) (not M4) (not J5))
       (or (= N6 B6) (not M4) (not J5))
       (or (= M6 A6) (not M4) (not J5))
       (or (= L6 Z5) (not M4) (not J5))
       (or (= K6 Y5) (not M4) (not J5))
       (or (= J6 X5) (not M4) (not J5))
       (or (= C6 N2) (not M4) (not J5))
       (or (= B6 Y4) (not M4) (not J5))
       (or (= A6 0) (not M4) (not J5))
       (or (= Z5 A5) (not M4) (not J5))
       (or (= Y5 Z4) (not M4) (not J5))
       (or L (not M4) (not J5))
       (or (not L) (not M4) (not C5))
       (or (not U3) (not D3) (= K4 C4))
       (or (not U3) (not D3) (= J4 B4))
       (or (not U3) (not D3) (= I4 A4))
       (or (not U3) (not D3) (= L4 D4))
       (or (not U3) (not D3) (= D4 O2))
       (or (not U3) (not D3) (= C4 L2))
       (or (not U3) (not D3) (= B4 K2))
       (or (not U3) (not D3) (= A4 0))
       (or Y (not U3) (not D3))
       (or (not T3) (not O3) (= K4 Y3))
       (or (not T3) (not O3) (= J4 X3))
       (or (not T3) (not O3) (= I4 W3))
       (or (not T3) (not O3) (= L4 Z3))
       (or (not T3) (not O3) (= Z3 1))
       (or (not T3) (not O3) (= Y3 R3))
       (or (not T3) (not O3) (= X3 R3))
       (or (not T3) (not O3) (= W3 2))
       (or O (not T3) (not O3))
       (or (= O6 I6) (not S3) (not K5))
       (or (= N6 H6) (not S3) (not K5))
       (or (= M6 G6) (not S3) (not K5))
       (or (= L6 F6) (not S3) (not K5))
       (or (= K6 E6) (not S3) (not K5))
       (or (= J6 D6) (not S3) (not K5))
       (or (= I6 N2) (not S3) (not K5))
       (or (= H6 K4) (not S3) (not K5))
       (or (= G6 I2) (not S3) (not K5))
       (or (= F6 I4) (not S3) (not K5))
       (or (= E6 J4) (not S3) (not K5))
       (or (= D6 L4) (not S3) (not K5))
       (or (not M) (not S3) (not K5))
       (or (= Q4 K4) (not S3) (not N4))
       (or (= P4 L4) (not S3) (not N4))
       (or (= A5 S4) (not S3) (not N4))
       (or (= Z4 R4) (not S3) (not N4))
       (or (= Y4 Q4) (not S3) (not N4))
       (or (= X4 P4) (not S3) (not N4))
       (or (= S4 I4) (not S3) (not N4))
       (or (= R4 J4) (not S3) (not N4))
       (or M (not S3) (not N4))
       (or (not Q2) (not C3) (not V3))
       (or Q2 (not E3) (not C3))
       (or (not G) (not T7) (not G5))
       (or G (not Q6) (not G5))
       (or F (not P6) (not S7))
       (or (not F) (not P6) (not L7))
       (or D (not K7) (not N7))
       (or (not D) (not R7) (not K7))
       (or C (not P7) (not J9))
       (or (not J10) (not I9) (= T2 I10))
       (or (not J10) (not I9) (= S2 0))
       (or (not J10) (not I9) (= B3 S2))
       (or (not J10) (not I9) (= A3 F10))
       (or (not J10) (not I9) (= Z2 B10))
       (or (not J10) (not I9) (= Y2 G10))
       (or (not J10) (not I9) (= W2 E10))
       (or (not J10) (not I9) (= V2 D10))
       (or (not J10) (not I9) (= U2 C10))
       (or (not J10) (not I9) (= X2 H10))
       (or (not J10) (not I9) (= N1 A3))
       (or (not J10) (not I9) (= M1 Z2))
       (or (not J10) (not I9) (= L1 Y2))
       (or (not J10) (not I9) (= K1 X2))
       (or (not J10) (not I9) (= J1 W2))
       (or (not J10) (not I9) (= I1 V2))
       (or (not J10) (not I9) (= H1 U2))
       (or (not J10) (not I9) (= G1 T2))
       (or B (not J10) (not I9))
       (or (not E1) (not M10) (not K10))
       (or (not I9) (= B (= A 0)))
       (or (not M7) (= O7 (+ 1 F7)))
       (or (not M7) (and K7 N7))
       (or (not K7) (= D (= M2 1)))
       (or (not K7) (and P6 L7))
       (or (not D5) (= H (= M2 1)))
       (or (not D5) (not (= H I)))
       (or (not D5) (= F5 (+ 1 Y4)))
       (or (not D5) (and B5 E5))
       (or (not B5) (= J (= N2 1)))
       (or (not B5) (and M4 C5))
       (or (not D3) (= Y (= X 0)))
       (or (not D3) (and E3 C3))
       (or (not C3) (and N10 L10))
       (or (not P6) (= F (= E 0)))
       (or (not L10) (and M10 K10))
       a!1
       a!2
       (or (not M3) (= T (and R S)))
       (or (not M3) (= S (= H3 5)))
       (or (not M3) (= R (and P Q)))
       (or (not M3) (and K3 N3))
       (or (not P7) (= C (= Y1 0)))
       (or (not G5) (= G (= H2 0)))
       (or (not O3) (= N (= N2 1)))
       (or (not O3) (not (= N O)))
       (or (not K3) (= V (= L2 U)))
       (or (not K3) (= U (+ 3 K2)))
       (or (not K3) (and F3 L3))
       (or (not F3) (= W (= O2 1)))
       (or (not F3) (and G3 D3))
       (or (not M4) (= L (= K 0)))
       (or (not S3) (= M (= I2 0)))
       (or (not R2) (and J10 I9))
       (= F1 true)
       (= R2 true)
       (not (= E1 F1))
       (= 2 v_275)))
      )
      (main_1 v_275
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
        B3
        G1
        H1
        I1
        J1
        K1
        L1
        M1
        N1
        H2
        I2
        J2
        K2
        L2
        M2
        N2
        O2
        P2
        Q2)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Int) (D Bool) (E Bool) (F Bool) (G Bool) (H Bool) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Int) (T Bool) (U Bool) (V Int) (W Bool) (X Bool) (Y Bool) (Z Bool) (A1 Bool) (B1 Bool) (C1 Bool) (D1 Bool) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Bool) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (Q2 Int) (R2 Int) (S2 Int) (T2 Int) (U2 Int) (V2 Int) (W2 Int) (X2 Int) (Y2 Bool) (Z2 Bool) (A3 Bool) (B3 Bool) (C3 Bool) (D3 Int) (E3 Int) (F3 Int) (G3 Bool) (H3 Bool) (I3 Bool) (J3 Bool) (K3 Bool) (L3 Bool) (M3 Bool) (N3 Int) (O3 Bool) (P3 Bool) (Q3 Bool) (R3 Bool) (S3 Int) (T3 Int) (U3 Int) (V3 Int) (W3 Int) (X3 Int) (Y3 Int) (Z3 Int) (A4 Int) (B4 Int) (C4 Int) (D4 Int) (E4 Int) (F4 Int) (G4 Int) (H4 Int) (I4 Bool) (J4 Bool) (K4 Bool) (L4 Int) (M4 Int) (N4 Int) (O4 Int) (P4 Int) (Q4 Int) (R4 Int) (S4 Int) (T4 Int) (U4 Int) (V4 Int) (W4 Int) (X4 Bool) (Y4 Bool) (Z4 Bool) (A5 Bool) (B5 Int) (C5 Bool) (D5 Bool) (E5 Bool) (F5 Bool) (G5 Bool) (H5 Int) (I5 Int) (J5 Int) (K5 Int) (L5 Int) (M5 Int) (N5 Int) (O5 Int) (P5 Int) (Q5 Int) (R5 Int) (S5 Int) (T5 Int) (U5 Int) (V5 Int) (W5 Int) (X5 Int) (Y5 Int) (Z5 Int) (A6 Int) (B6 Int) (C6 Int) (D6 Int) (E6 Int) (F6 Int) (G6 Int) (H6 Int) (I6 Int) (J6 Int) (K6 Int) (L6 Bool) (M6 Bool) (N6 Bool) (O6 Int) (P6 Int) (Q6 Int) (R6 Int) (S6 Int) (T6 Int) (U6 Int) (V6 Int) (W6 Int) (X6 Int) (Y6 Int) (Z6 Int) (A7 Int) (B7 Int) (C7 Int) (D7 Int) (E7 Int) (F7 Int) (G7 Bool) (H7 Bool) (I7 Bool) (J7 Bool) (K7 Int) (L7 Bool) (M7 Bool) (N7 Bool) (O7 Bool) (P7 Bool) (Q7 Int) (R7 Int) (S7 Int) (T7 Int) (U7 Int) (V7 Int) (W7 Int) (X7 Int) (Y7 Int) (Z7 Int) (A8 Int) (B8 Int) (C8 Int) (D8 Int) (E8 Int) (F8 Int) (G8 Int) (H8 Int) (I8 Int) (J8 Int) (K8 Int) (L8 Int) (M8 Int) (N8 Int) (O8 Int) (P8 Int) (Q8 Int) (R8 Int) (S8 Int) (T8 Int) (U8 Int) (V8 Int) (W8 Int) (X8 Int) (Y8 Int) (Z8 Int) (A9 Int) (B9 Int) (C9 Int) (D9 Int) (E9 Bool) (F9 Bool) (G9 Bool) (H9 Bool) (I9 Bool) (v_243 Int) (v_244 Int) ) 
    (=>
      (and
        (main_1 v_243
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
        D2
        E2
        F2
        G2)
        (let ((a!1 (or (not I3) (not (= (<= 6 F3) N))))
      (a!2 (or (not I3) (not (= (<= E3 4) O)))))
  (and (= 4 v_243)
       (= Y (= X1 0))
       (= X (= Y1 0))
       (not (= C1 D1))
       (= B1 (or A1 Z))
       (not (= B1 C1))
       (= A1 (= O1 0))
       (or (and X4 E5) (and I4 F5) (and O3 G5) (not C5) (and D5 Z4))
       (or (and G7 N7) (and L6 O7) (and C5 P7) (not L7) (and M7 I7))
       (or (and K3 P3) (and Z2 Q3) (not O3) (and R3 Y2))
       (or (= Q5 2) (not X4) (not E5))
       (or (= O5 V4) (not X4) (not E5))
       (or (= S5 1) (not X4) (not E5))
       (or (= R5 U4) (not X4) (not E5))
       (or (= N5 T4) (not X4) (not E5))
       (or (= K6 S5) (not X4) (not E5))
       (or (= J6 R5) (not X4) (not E5))
       (or (= I6 Q5) (not X4) (not E5))
       (or (= H6 P5) (not X4) (not E5))
       (or (= G6 O5) (not X4) (not E5))
       (or (= F6 N5) (not X4) (not E5))
       (or (= P5 W4) (not X4) (not E5))
       (or (not N6) (not Z4) (= F7 Z6))
       (or (not N6) (not Z4) (= E7 Y6))
       (or (not N6) (not Z4) (= D7 X6))
       (or (not N6) (not Z4) (= C7 W6))
       (or (not N6) (not Z4) (= B7 V6))
       (or (not N6) (not Z4) (= A7 U6))
       (or (not N6) (not Z4) (= Z6 T4))
       (or (not N6) (not Z4) (= Y6 V4))
       (or (not N6) (not Z4) (= X6 W4))
       (or (not N6) (not Z4) (= W6 2))
       (or (not N6) (not Z4) (= V6 B5))
       (or (not N6) (not Z4) (= U6 1))
       (or (= H4 Z3) (not Z2) (not Q3))
       (or (= G4 Y3) (not Z2) (not Q3))
       (or (= F4 X3) (not Z2) (not Q3))
       (or (= E4 W3) (not Z2) (not Q3))
       (or (= Z3 E2) (not Z2) (not Q3))
       (or (= Y3 B2) (not Z2) (not Q3))
       (or (= X3 A2) (not Z2) (not Q3))
       (or (= W3 0) (not Z2) (not Q3))
       (or (not G7) (= Y7 A7) (not N7))
       (or (not G7) (= F8 1) (not N7))
       (or (not G7) (= E8 B7) (not N7))
       (or (not G7) (= D8 2) (not N7))
       (or (= C8 F7) (not G7) (not N7))
       (or (not G7) (= B8 E7) (not N7))
       (or (not G7) (= A8 D7) (not N7))
       (or (not G7) (= Z7 C7) (not N7))
       (or (= D9 F8) (not G7) (not N7))
       (or (= C9 E8) (not G7) (not N7))
       (or (= B9 D8) (not G7) (not N7))
       (or (= A9 C8) (not G7) (not N7))
       (or (= Z8 B8) (not G7) (not N7))
       (or (not G7) (= Y8 A8) (not N7))
       (or (not G7) (= X8 Z7) (not N7))
       (or (not G7) (= W8 Y7) (not N7))
       (or (not M7) (not I7) (= X7 1))
       (or (not M7) (not I7) (= W7 K7))
       (or (not M7) (not I7) (= V7 2))
       (or (not M7) (not I7) (= U7 F7))
       (or (not M7) (not I7) (= T7 E7))
       (or (not M7) (not I7) (= S7 D7))
       (or (not M7) (not I7) (= R7 C7))
       (or (not M7) (not I7) (= Q7 A7))
       (or (not M7) (not I7) (= D9 X7))
       (or (not M7) (not I7) (= C9 W7))
       (or (not M7) (not I7) (= B9 V7))
       (or (not M7) (not I7) (= A9 U7))
       (or (not M7) (not I7) (= Z8 T7))
       (or (not M7) (not I7) (= Y8 S7))
       (or (not M7) (not I7) (= X8 R7))
       (or (not M7) (not I7) (= W8 Q7))
       (or (not D5) (not Z4) (= M5 1))
       (or (not D5) (not Z4) (= L5 B5))
       (or (not D5) (not Z4) (= K6 M5))
       (or (not D5) (not Z4) (= J6 L5))
       (or (not D5) (not Z4) (= I6 K5))
       (or (not D5) (not Z4) (= H6 J5))
       (or (not D5) (not Z4) (= G6 I5))
       (or (not D5) (not Z4) (= F6 H5))
       (or (not D5) (not Z4) (= K5 2))
       (or (not D5) (not Z4) (= J5 W4))
       (or (not D5) (not Z4) (= I5 V4))
       (or (not D5) (not Z4) (= H5 T4))
       (or (= D9 V8) (not C5) (not P7))
       (or (= C9 U8) (not C5) (not P7))
       (or (= B9 T8) (not C5) (not P7))
       (or (= A9 S8) (not C5) (not P7))
       (or (= Z8 R8) (not C5) (not P7))
       (or (= Y8 Q8) (not C5) (not P7))
       (or (= X8 P8) (not C5) (not P7))
       (or (= W8 O8) (not C5) (not P7))
       (or (= V8 C2) (not C5) (not P7))
       (or (= U8 J6) (not C5) (not P7))
       (or (= T8 X1) (not C5) (not P7))
       (or (= S8 F6) (not C5) (not P7))
       (or (= R8 G6) (not C5) (not P7))
       (or (= Q8 H6) (not C5) (not P7))
       (or (= P8 I6) (not C5) (not P7))
       (or (= O8 K6) (not C5) (not P7))
       (or (not R3) (not Y2) (= H4 D4))
       (or (not R3) (not Y2) (= G4 C4))
       (or (not R3) (not Y2) (= F4 B4))
       (or (not R3) (not Y2) (= E4 A4))
       (or (not R3) (not Y2) (= D4 E2))
       (or (not R3) (not Y2) (= C4 B2))
       (or (not R3) (not Y2) (= B4 A2))
       (or (not R3) (not Y2) (= A4 Z1))
       (or (not R3) (not Y2) (not G2))
       (or (= K6 E6) (not G5) (not O3))
       (or (= J6 D6) (not G5) (not O3))
       (or (= I6 C6) (not G5) (not O3))
       (or (= H6 B6) (not G5) (not O3))
       (or (= G6 A6) (not G5) (not O3))
       (or (= F6 Z5) (not G5) (not O3))
       (or (= E6 D2) (not G5) (not O3))
       (or (= D6 G4) (not G5) (not O3))
       (or (= C6 Y1) (not G5) (not O3))
       (or (= B6 E4) (not G5) (not O3))
       (or (= A6 F4) (not G5) (not O3))
       (or (= Z5 H4) (not G5) (not O3))
       (or (not A3) (not Y2) G2)
       (or (not K) (not G5) (not O3))
       (or (not H) (not X4) (not E5))
       (or H (not A5) (not X4))
       (or (not G) (not N6) (not Z4))
       (or G (not D5) (not Z4))
       (or (not E) (not C5) (not P7))
       (or (not M6) (not C5) (= F7 T6))
       (or (not M6) (not C5) (= E7 S6))
       (or (not M6) (not C5) (= D7 R6))
       (or (not M6) (not C5) (= C7 Q6))
       (or (not M6) (not C5) (= B7 P6))
       (or (not M6) (not C5) (= A7 O6))
       (or (not M6) (not C5) (= T6 F6))
       (or (not M6) (not C5) (= S6 G6))
       (or (not M6) (not C5) (= R6 H6))
       (or (not M6) (not C5) (= Q6 I6))
       (or (not M6) (not C5) (= P6 J6))
       (or (not M6) (not C5) (= O6 K6))
       (or E (not M6) (not C5))
       (or (not L6) (and N6 Z4) (and M6 C5))
       (or (not D) (not L6) (not H7))
       (or (not O7) (= M8 B7) (not L6))
       (or (= D9 N8) (not O7) (not L6))
       (or (= C9 M8) (not O7) (not L6))
       (or (= B9 L8) (not O7) (not L6))
       (or (= A9 K8) (not O7) (not L6))
       (or (= Z8 J8) (not O7) (not L6))
       (or (not O7) (= Y8 I8) (not L6))
       (or (not O7) (= X8 H8) (not L6))
       (or (not O7) (= W8 G8) (not L6))
       (or (not O7) (= N8 C2) (not L6))
       (or (= L8 0) (not O7) (not L6))
       (or (= K8 F7) (not O7) (not L6))
       (or (not O7) (= J8 E7) (not L6))
       (or (not O7) (= I8 D7) (not L6))
       (or (not O7) (= H8 C7) (not L6))
       (or (= G8 A7) (not O7) (not L6))
       (or (not O7) D (not L6))
       (or (not J4) (not O3) (= W4 O4))
       (or (not J4) (not O3) (= V4 N4))
       (or (not J4) (not O3) (= U4 M4))
       (or (not J4) (not O3) (= T4 L4))
       (or (not J4) (not O3) (= O4 E4))
       (or (not J4) (not O3) (= N4 F4))
       (or (not J4) (not O3) (= M4 G4))
       (or (not J4) (not O3) (= L4 H4))
       (or K (not J4) (not O3))
       (or (and K3 K4) (not I4) (and J4 O3))
       (or (not J) (not I4) (not Y4))
       (or (= U5 V4) (not I4) (not F5))
       (or (= T5 T4) (not I4) (not F5))
       (or (= K6 Y5) (not I4) (not F5))
       (or (= J6 X5) (not I4) (not F5))
       (or (= I6 W5) (not I4) (not F5))
       (or (= H6 V5) (not I4) (not F5))
       (or (= G6 U5) (not I4) (not F5))
       (or (= F6 T5) (not I4) (not F5))
       (or (= Y5 D2) (not I4) (not F5))
       (or (= X5 U4) (not I4) (not F5))
       (or (= W5 0) (not I4) (not F5))
       (or (= V5 W4) (not I4) (not F5))
       (or J (not I4) (not F5))
       (or (not U) (not M3) (not B3))
       (or F2 (not M7) (not I7))
       (or (not B) (not G7) (not N7))
       (or B (not G7) (not J7))
       (or (and I3 L3) (not K3) (and M3 B3))
       (or (= S4 2) (not K3) (not K4))
       (or (= R4 N3) (not K3) (not K4))
       (or (= Q4 N3) (not K3) (not K4))
       (or (= W4 S4) (not K3) (not K4))
       (or (= V4 R4) (not K3) (not K4))
       (or (= U4 Q4) (not K3) (not K4))
       (or (= T4 P4) (not K3) (not K4))
       (or (= P4 1) (not K3) (not K4))
       (or (= H4 V3) (not K3) (not P3))
       (or (= G4 U3) (not K3) (not P3))
       (or (= F4 T3) (not K3) (not P3))
       (or (= E4 S3) (not K3) (not P3))
       (or (= V3 1) (not K3) (not P3))
       (or (= U3 N3) (not K3) (not P3))
       (or (= T3 N3) (not K3) (not P3))
       (or (= S3 2) (not K3) (not P3))
       (or (not M) (not K3) (not K4))
       (or M (not K3) (not P3))
       (or (not J3) (not G3) T)
       (or (not R) (not L3) (not I3))
       (or U (not H3) (not B3))
       (or W (not Z2) (not Q3))
       (or (not W) (not C3) (not Z2))
       (or (not C1) (not E9) (not G9))
       (or (not I9) (not L7) (= P2 A9))
       (or (not I9) (not L7) (= O2 W8))
       (or (not I9) (not L7) (= N2 D9))
       (or (not I9) (not L7) (= X2 P2))
       (or (not I9) (not L7) (= W2 O2))
       (or (not I9) (not L7) (= V2 N2))
       (or (not I9) (not L7) (= U2 M2))
       (or (not I9) (not L7) (= T2 L2))
       (or (not I9) (not L7) (= S2 K2))
       (or (not I9) (not L7) (= R2 J2))
       (or (not I9) (not L7) (= Q2 I2))
       (or (not I9) (not L7) (= M2 C9))
       (or (not I9) (not L7) (= L2 Z8))
       (or (not I9) (not L7) (= K2 Y8))
       (or (not I9) (not L7) (= J2 X8))
       (or (not I9) (not L7) (= I2 B9))
       (or (not I9) (not L7) (not A))
       (or (not Z4) (= F (= C2 1)))
       (or (not Z4) (not (= F G)))
       (or (not Z4) (= B5 (+ 1 U4)))
       (or (not Z4) (and A5 X4))
       (or (not X4) (= H (= D2 1)))
       (or (not X4) (and I4 Y4))
       (or (not G3) (= T (= B2 S)))
       (or (not G3) (= S (+ 3 A2)))
       (or (not G3) (and H3 B3))
       (or (not Z2) (= W (= V 0)))
       (or (not Z2) (and A3 Y2))
       (or (not Y2) (and H9 F9))
       (or (not I7) (= K7 (+ 1 B7)))
       (or (not I7) (and J7 G7))
       (or (not G7) (= B (= C2 1)))
       (or (not G7) (and L6 H7))
       (or (not F9) (and E9 G9))
       (or (not C5) (= E (= X1 0)))
       (or (not O3) (= K (= Y1 0)))
       (or (not B3) (= U (= E2 1)))
       (or (not B3) (and C3 Z2))
       (or (not H2) (and I9 L7))
       (or (not L6) (= D (= C 0)))
       (or (not I4) (= J (= I 0)))
       (or (not L7) (= A (= O1 0)))
       (or (not K3) (= L (= D2 1)))
       (or (not K3) (not (= L M)))
       a!1
       a!2
       (or (not I3) (= Q (= D3 5)))
       (or (not I3) (= R (and P Q)))
       (or (not I3) (= P (and N O)))
       (or (not I3) (and J3 G3))
       (= H2 true)
       (= D1 true)
       (= Z (or X Y))
       (= 3 v_244)))
      )
      (main_1 v_244
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
        Q2
        R2
        S2
        T2
        U2
        V2
        W2
        X2
        F2
        G2)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Bool) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Bool) (J1 Bool) (K1 Bool) (L1 Bool) (M1 Bool) (v_39 Int) (v_40 Int) ) 
    (=>
      (and
        (main_1 v_39
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
        J1)
        (and (= 4 v_39)
     (= E (or C D))
     (not (= E F))
     (= B (= A1 0))
     (= A (= B1 0))
     (= D (= R 0))
     (= C (or A B))
     (or (not M1) (not K1) F)
     (or (not L1) (and M1 K1))
     (= G true)
     (= L1 true)
     (not (= F G))
     (= 4 v_40))
      )
      (main_1 v_40
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
        J1)
    )
  )
)
(assert
  (forall ( (A Bool) (B Bool) (C Bool) (D Bool) (E Bool) (F Int) (G Bool) (H Bool) (I Int) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Bool) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Bool) (T1 Bool) (U1 Bool) (V1 Bool) (W1 Bool) (X1 Bool) (Y1 Bool) (Z1 Int) (A2 Int) (B2 Int) (C2 Bool) (D2 Bool) (E2 Bool) (F2 Bool) (G2 Bool) (H2 Bool) (I2 Bool) (J2 Bool) (K2 Bool) (L2 Bool) (M2 Bool) (v_65 Int) (v_66 Int) ) 
    (=>
      (and
        (main_1 v_65
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
        T1)
        (let ((a!1 (or (not E2) (not (= (<= 6 B2) A))))
      (a!2 (or (not E2) (not (= (<= A2 4) B)))))
  (and (= 4 v_65)
       (= L (= K1 0))
       (= K (= L1 0))
       (not (= P Q))
       (= N (= B1 0))
       (= O (or N M))
       (not (= O P))
       (or (not H2) (and I2 E2) (and C2 J2))
       (or T1 (not U1) (not W1))
       (or (not G) (not C2) (not J2))
       (or G (not C2) (not F2))
       (or E (not I2) (not E2))
       (or (not Y1) (not V1) (not J))
       (or H (not X1) (not D2))
       (or (not P) (not G2) (not L2))
       a!1
       a!2
       (or (not E2) (= E (and C D)))
       (or (not E2) (= D (= Z1 5)))
       (or (not E2) (= C (and B A)))
       (or (not E2) (and C2 F2))
       (or (not K2) (and L2 G2))
       (or (not V1) (= J (= I 0)))
       (or (not V1) (and U1 W1))
       (or (not U1) (and M2 K2))
       (or (not C2) (= G (= O1 F)))
       (or (not C2) (= F (+ 3 N1)))
       (or (not C2) (and X1 D2))
       (or (not X1) (= H (= R1 1)))
       (or (not X1) (and Y1 V1))
       (= Q true)
       (= H2 true)
       (= M (or K L))
       (= 5 v_66)))
      )
      (main_1 v_66
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
        T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Bool) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Bool) (C1 Bool) (v_29 Int) ) 
    (=>
      (and
        (main_1 v_29 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z A1 B1 C1)
        (= 5 v_29)
      )
      false
    )
  )
)

(check-sat)
(exit)
