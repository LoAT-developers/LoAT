; ./prepared/tricera/sv-comp-2020/./mixed/s3_srvr_2.cil-2.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main255| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main336| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main107| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main118| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main446| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main199| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main272| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main495| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main269| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main330| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main300| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main478| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        true
      )
      (inv_main4 B A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main199 B
             A1
             I
             J1
             I1
             M1
             D1
             C
             Z1
             F2
             S1
             R1
             V
             Z
             S
             P1
             B2
             A2
             H
             Q1
             A
             B1
             G2
             E1
             R
             Y
             C2
             H1
             K
             N
             L
             U1
             W
             D
             O1
             G
             Y1
             N1
             T1
             F
             X1
             C1
             K1
             F1
             H2
             O
             Q
             P
             G1
             V1
             K2
             D2
             W1
             J2
             X
             E2
             U
             T
             E
             M
             L1
             I2)
        (and (= J 0)
     (<= 0 I2)
     (<= 0 Y1)
     (<= 0 O1)
     (<= 0 U)
     (<= 0 T)
     (<= 0 M)
     (<= 0 G)
     (<= 0 E)
     (not (= C2 0)))
      )
      (inv_main118 B
             A1
             I
             J1
             I1
             M1
             D1
             C
             Z1
             F2
             S1
             R1
             V
             Z
             S
             P1
             B2
             A2
             H
             Q1
             A
             B1
             G2
             E1
             R
             Y
             C2
             H1
             K
             N
             L
             U1
             W
             D
             O1
             G
             Y1
             N1
             T1
             F
             X1
             C1
             J
             F1
             H2
             O
             Q
             P
             G1
             V1
             K2
             D2
             W1
             J2
             X
             E2
             U
             T
             E
             M
             L1
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main199 H
             Z1
             A
             F
             M
             I
             L1
             N
             K1
             D
             B2
             U
             R
             Q
             N1
             Y
             J1
             G
             C2
             A2
             G1
             Y1
             W
             W1
             K2
             G2
             P
             F1
             I1
             T
             E2
             B1
             H2
             P1
             D1
             R1
             V1
             J2
             J
             T1
             I2
             D2
             H1
             O
             Q1
             O1
             A1
             K
             E1
             M1
             L
             V
             C
             X
             B
             U1
             S1
             F2
             C1
             E
             Z
             S)
        (and (not (= H1 0))
     (= P 0)
     (<= 0 F2)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 S)
     (<= 0 E)
     (= X1 0))
      )
      (inv_main118 H
             Z1
             A
             F
             M
             I
             L1
             N
             K1
             D
             B2
             U
             R
             Q
             N1
             Y
             J1
             G
             C2
             A2
             G1
             Y1
             W
             W1
             K2
             G2
             P
             F1
             I1
             T
             E2
             B1
             H2
             P1
             D1
             R1
             V1
             J2
             J
             T1
             I2
             D2
             X1
             O
             Q1
             O1
             A1
             K
             E1
             M1
             L
             V
             C
             X
             B
             U1
             S1
             F2
             C1
             E
             Z
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main478 Q
             P1
             M1
             Q1
             O1
             D1
             F
             Z
             X1
             B1
             B2
             L1
             I1
             L
             J1
             J2
             E1
             E2
             A1
             H1
             A2
             D
             H
             T
             T1
             X
             C2
             N
             Y
             E
             P
             K
             I2
             W
             G1
             V1
             K1
             C1
             W1
             C
             S
             O
             D2
             B
             K2
             R1
             F2
             Z1
             R
             F1
             Y1
             U1
             V
             M
             J
             H2
             I
             G2
             U
             S1
             G
             A)
        (and (= C1 0)
     (<= 0 G2)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 K1)
     (<= 0 G1)
     (<= 0 U)
     (<= 0 I)
     (<= 0 A)
     (= N1 0))
      )
      (inv_main118 Q
             P1
             M1
             Q1
             O1
             D1
             F
             Z
             X1
             B1
             B2
             L1
             I1
             L
             J1
             J2
             E1
             E2
             A1
             H1
             A2
             D
             H
             T
             T1
             X
             C2
             N
             Y
             E
             P
             K
             I2
             W
             G1
             V1
             K1
             C1
             W1
             C
             S
             O
             N1
             B
             K2
             R1
             F2
             Z1
             R
             F1
             Y1
             U1
             V
             M
             J
             H2
             I
             G2
             U
             S1
             G
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main478 C1
             F2
             B
             Y1
             K
             Z
             T1
             N
             P1
             U
             H2
             C2
             O
             S1
             J
             O1
             G2
             D
             E1
             F
             M
             G
             E2
             I
             C
             R1
             B2
             M1
             J1
             W1
             V
             Y
             Q
             V1
             P
             N1
             A
             E
             R
             H
             U1
             X
             T
             D2
             B1
             W
             K2
             I2
             G1
             S
             I1
             Q1
             F1
             L
             L1
             A2
             J2
             D1
             X1
             A1
             K1
             H1)
        (and (= Z X)
     (not (= E 0))
     (<= 0 X1)
     (<= 0 N1)
     (<= 0 H1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 P)
     (<= 0 A)
     (<= 0 J2)
     (= Z1 0))
      )
      (inv_main118 C1
             F2
             B
             Y1
             K
             Z
             T1
             N
             P1
             U
             H2
             C2
             O
             S1
             J
             O1
             G2
             D
             E1
             F
             M
             G
             E2
             I
             C
             R1
             B2
             M1
             J1
             W1
             V
             Y
             Q
             V1
             P
             N1
             A
             E
             R
             H
             U1
             X
             Z1
             D2
             B1
             W
             K2
             I2
             G1
             S
             I1
             Q1
             F1
             L
             L1
             A2
             J2
             D1
             X1
             A1
             K1
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main478 P1
             J2
             C
             C1
             F
             E
             Z
             G2
             W1
             S
             X
             D1
             B2
             P
             F1
             B
             O
             U1
             L
             Y
             A1
             W
             G1
             I1
             I2
             B1
             D2
             H
             O1
             I
             K
             T1
             F2
             K1
             Q1
             C2
             S1
             H2
             J1
             Y1
             M
             N
             E1
             G
             Z1
             H1
             M1
             J
             T
             R
             E2
             X1
             A2
             N1
             V
             K2
             U
             V1
             Q
             A
             R1
             D)
        (and (= L1 0)
     (not (= E N))
     (<= 0 C2)
     (<= 0 V1)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 U)
     (<= 0 Q)
     (<= 0 D)
     (<= 0 A)
     (not (= H2 0))
     (= v_63 E))
      )
      (inv_main118 P1
             J2
             C
             C1
             F
             E
             Z
             G2
             W1
             S
             X
             D1
             B2
             P
             F1
             B
             O
             U1
             L
             Y
             A1
             W
             G1
             I1
             I2
             B1
             D2
             H
             O1
             I
             K
             T1
             F2
             K1
             Q1
             C2
             S1
             H2
             J1
             Y1
             v_63
             N
             L1
             G
             Z1
             H1
             M1
             J
             T
             R
             E2
             X1
             A2
             N1
             V
             K2
             U
             V1
             Q
             A
             R1
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main107 L
             H2
             V1
             M
             I
             C1
             Q1
             K
             V
             H
             O1
             E1
             Y1
             D
             K2
             Q
             W1
             G
             J1
             P
             H1
             F
             D1
             M1
             B2
             N1
             S
             U
             S1
             T
             I2
             Y
             K1
             O
             W
             P1
             U1
             D2
             R
             J2
             X1
             G2
             A
             R1
             C
             J
             A2
             Z
             F1
             L1
             G1
             B
             E2
             E
             Z1
             I1
             B1
             X
             C2
             F2
             A1
             N)
        (and (= T1 (+ 1 I))
     (= C (- 12288))
     (<= 0 F2)
     (<= 0 C2)
     (<= 0 U1)
     (<= 0 P1)
     (<= 0 B1)
     (<= 0 X)
     (<= 0 W)
     (<= 0 N)
     (not (= W1 0)))
      )
      (inv_main118 L
             H2
             V1
             M
             T1
             C1
             Q1
             K
             V
             H
             O1
             E1
             Y1
             D
             K2
             Q
             W1
             G
             J1
             P
             H1
             F
             D1
             M1
             B2
             N1
             S
             U
             S1
             T
             I2
             Y
             K1
             O
             W
             P1
             U1
             D2
             R
             J2
             X1
             G2
             A
             R1
             C
             J
             A2
             Z
             F1
             L1
             G1
             B
             E2
             E
             Z1
             I1
             B1
             X
             C2
             F2
             A1
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main107 L
             D
             P
             K2
             C2
             A
             H
             J2
             H1
             K1
             M
             J
             E2
             D1
             E1
             A1
             V1
             X1
             F
             J1
             R1
             N
             U1
             A2
             W1
             N1
             G2
             Y
             T
             I1
             U
             X
             K
             H2
             B
             C1
             D2
             E
             R
             Z1
             Z
             Y1
             O
             W
             I2
             Q1
             L1
             I
             V
             G
             P1
             M1
             F1
             B1
             C
             O1
             Q
             T1
             S1
             F2
             B2
             G1)
        (and (not (= V1 0))
     (not (= Q1 (- 16384)))
     (= S (+ 1 C2))
     (<= 0 F2)
     (<= 0 D2)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 G1)
     (<= 0 C1)
     (<= 0 Q)
     (<= 0 B)
     (not (= I2 (- 12288))))
      )
      (inv_main118 L
             D
             P
             K2
             S
             A
             H
             J2
             H1
             K1
             M
             J
             E2
             D1
             E1
             A1
             V1
             X1
             F
             J1
             R1
             N
             U1
             A2
             W1
             N1
             G2
             Y
             T
             I1
             U
             X
             K
             H2
             B
             C1
             D2
             E
             R
             Z1
             Z
             Y1
             O
             W
             I2
             Q1
             L1
             I
             V
             G
             P1
             M1
             F1
             B1
             C
             O1
             Q
             T1
             S1
             F2
             B2
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main107 J
             C2
             N
             F2
             C1
             L
             I1
             K
             Y1
             D
             J1
             Z1
             V
             Z
             M1
             Q1
             J2
             P
             Y
             D1
             D2
             R1
             U1
             L1
             T1
             I
             T
             V1
             O1
             P1
             B
             W1
             H1
             B2
             S1
             G
             S
             F1
             G1
             E2
             K1
             E
             F
             A1
             N1
             H2
             R
             A
             Q
             O
             G2
             H
             X
             M
             I2
             K2
             W
             E1
             C
             B1
             X1
             U)
        (and (= A2 (+ 1 C1))
     (not (= N1 (- 12288)))
     (not (= J2 0))
     (<= 0 S1)
     (<= 0 E1)
     (<= 0 B1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 S)
     (<= 0 G)
     (<= 0 C)
     (= H2 (- 16384)))
      )
      (inv_main118 J
             C2
             N
             F2
             A2
             L
             I1
             K
             Y1
             D
             J1
             Z1
             V
             Z
             M1
             Q1
             J2
             P
             Y
             D1
             D2
             R1
             U1
             L1
             T1
             I
             T
             V1
             O1
             P1
             B
             W1
             H1
             B2
             S1
             G
             S
             F1
             G1
             E2
             K1
             E
             F
             A1
             N1
             H2
             R
             A
             Q
             O
             G2
             H
             X
             M
             I2
             K2
             W
             E1
             C
             B1
             X1
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 E2 K2)
        (and (= K1 (- 1))
     (= G1 0)
     (not (= D1 0))
     (= A1 0)
     (= P 0)
     (= F 8464)
     (= D 8464)
     (= B 1)
     (<= 0 Y1)
     (<= 0 J1)
     (<= 0 X)
     (<= 0 V)
     (<= 0 U)
     (<= 0 M)
     (<= 0 E)
     (<= 0 C)
     (= I2 8464)
     (= v_63 A)
     (= v_64 D1))
      )
      (inv_main107 I2
             K2
             D
             D1
             G
             F
             Q1
             T
             O1
             B1
             P1
             H2
             C1
             B
             H1
             X1
             H
             T1
             M1
             N
             L1
             I1
             Z1
             S
             F1
             N1
             G2
             K
             S1
             E1
             F2
             J2
             C2
             J
             C
             A
             v_63
             v_64
             L
             K1
             Q
             U1
             G1
             A1
             B2
             W1
             Y
             Z
             V1
             D2
             R1
             O
             I
             A2
             P
             R
             V
             E
             J1
             X
             W
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 H1 U1)
        (and (= Z1 0)
     (= O1 (- 1))
     (= L1 1)
     (= F1 0)
     (not (= E1 0))
     (= Z 8464)
     (= Q 0)
     (= P 8464)
     (= M 0)
     (<= 0 C2)
     (<= 0 V1)
     (<= 0 P1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 N)
     (<= 0 D)
     (<= 0 B)
     (= I2 8464)
     (= v_63 I1)
     (= v_64 E1))
      )
      (inv_main107 P
             U1
             Z
             Q
             C
             I2
             S1
             G
             R1
             D1
             E
             T1
             A1
             L1
             I
             Q1
             F
             W
             R
             A2
             F2
             E1
             X1
             N1
             A
             M1
             S
             W1
             V
             J
             H2
             K
             D2
             J2
             C2
             I1
             v_63
             v_64
             Y1
             O1
             H
             O
             Z1
             M
             G2
             E2
             U
             L
             B2
             X
             Y
             K1
             C1
             K2
             F1
             J1
             T
             D
             P1
             N
             G1
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 V1 Z1)
        (and (= D2 0)
     (= T1 8464)
     (= H1 8464)
     (= G1 0)
     (= Y 0)
     (= X 8464)
     (= U 0)
     (= R 1)
     (= M (- 1))
     (= F 0)
     (<= 0 U1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 S)
     (<= 0 P)
     (<= 0 J)
     (<= 0 I)
     (<= 0 D)
     (= E2 0)
     (= v_64 Q1))
      )
      (inv_main107 T1
             Z1
             X
             E2
             J1
             H1
             G2
             B1
             W
             L1
             C2
             K1
             L
             R
             R1
             B2
             Z
             S1
             X1
             C1
             O
             F
             G
             K
             L2
             I1
             A
             K2
             Q
             B
             E1
             A1
             V
             Y1
             J
             Q1
             v_64
             U
             O1
             M
             C
             A2
             Y
             G1
             N
             W1
             N1
             T
             H2
             E
             J2
             I2
             F2
             M1
             D2
             H
             D
             F1
             U1
             S
             P1
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 Z
             V1
             A2
             X1
             X
             U
             C1
             K
             V
             D2
             C2
             O
             M1
             G
             F
             E
             N
             S
             Y1
             D
             L
             S1
             G1
             Q1
             J1
             O1
             W1
             B
             H2
             P
             W
             J
             C
             Z1
             H1
             I1
             H
             A1
             N1
             B1
             U1
             F1
             R1
             E1
             T
             T1
             A
             L1
             I
             E2
             B2
             G2
             K1
             R
             Q
             M
             F2
             I2
             Y
             P1
             J2
             D1)
        (and (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (not (= U 8465))
     (not (= U 8466))
     (= U 8496)
     (not (= U 8464))
     (not (= U 16384))
     (<= 0 F2)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 H)
     (<= 0 I2)
     (not (= U 12292))
     (= v_62 U))
      )
      (inv_main269 Z
             V1
             A2
             X1
             X
             U
             C1
             K
             V
             D2
             C2
             O
             M1
             G
             F
             E
             N
             S
             Y1
             D
             L
             S1
             G1
             Q1
             J1
             O1
             W1
             B
             H2
             P
             W
             J
             C
             Z1
             H1
             I1
             H
             A1
             N1
             B1
             U1
             v_62
             R1
             E1
             T
             T1
             A
             L1
             I
             E2
             B2
             G2
             K1
             R
             Q
             M
             F2
             I2
             Y
             P1
             J2
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 S
             T1
             Q
             P1
             K1
             G1
             E1
             S1
             D
             C2
             R
             J1
             D2
             F2
             Z1
             V1
             E2
             D1
             H
             I1
             N1
             X
             Z
             B1
             G2
             L
             H1
             X1
             B
             T
             A
             J2
             U
             F
             C
             H2
             K
             N
             Y1
             J
             E
             U1
             Q1
             W
             C1
             P
             O1
             M1
             R1
             F1
             M
             G
             O
             V
             I2
             W1
             A1
             A2
             L1
             I
             B2
             Y)
        (and (not (= G1 12292))
     (not (= G1 8192))
     (not (= G1 24576))
     (not (= G1 8195))
     (not (= G1 8480))
     (not (= G1 8481))
     (not (= G1 8482))
     (not (= G1 8465))
     (not (= G1 8466))
     (not (= G1 8496))
     (not (= G1 8464))
     (not (= G1 16384))
     (<= 0 H2)
     (<= 0 A2)
     (<= 0 L1)
     (<= 0 A1)
     (<= 0 Y)
     (<= 0 K)
     (<= 0 I)
     (<= 0 C)
     (= G1 8497)
     (= v_62 G1))
      )
      (inv_main269 S
             T1
             Q
             P1
             K1
             G1
             E1
             S1
             D
             C2
             R
             J1
             D2
             F2
             Z1
             V1
             E2
             D1
             H
             I1
             N1
             X
             Z
             B1
             G2
             L
             H1
             X1
             B
             T
             A
             J2
             U
             F
             C
             H2
             K
             N
             Y1
             J
             E
             v_62
             Q1
             W
             C1
             P
             O1
             M1
             R1
             F1
             M
             G
             O
             V
             I2
             W1
             A1
             A2
             L1
             I
             B2
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main330 Y1
             U1
             H1
             T1
             G2
             R
             G
             J2
             I1
             W
             U
             V
             X1
             L
             L1
             H2
             E
             M1
             J1
             C1
             X
             D
             R1
             N1
             W1
             N
             S
             M
             S1
             F
             G1
             B2
             O1
             H
             Z1
             A
             T
             C
             D1
             I
             E1
             K1
             V1
             P
             C2
             Y
             F2
             Z
             A2
             E2
             A1
             B
             Q
             J
             D2
             Q1
             O
             I2
             P1
             K
             F1
             B1)
        (and (= C1 0)
     (<= 0 Z1)
     (<= 0 P1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 O)
     (<= 0 K)
     (<= 0 A)
     (<= 0 I2)
     (not (= J1 (- 1))))
      )
      (inv_main336 Y1
             U1
             H1
             T1
             G2
             R
             G
             J2
             I1
             W
             U
             V
             X1
             L
             L1
             H2
             E
             M1
             J1
             C1
             X
             D
             R1
             N1
             W1
             N
             S
             M
             S1
             F
             G1
             B2
             O1
             H
             Z1
             A
             T
             C
             D1
             I
             E1
             K1
             V1
             P
             C2
             Y
             F2
             Z
             A2
             E2
             A1
             B
             Q
             J
             D2
             Q1
             O
             I2
             P1
             K
             F1
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main330 C
             S1
             E2
             S
             Z1
             G
             O1
             E1
             Q1
             Z
             V1
             I2
             F
             A2
             N
             I
             R1
             G1
             H2
             P
             U
             U1
             T
             W1
             L
             J2
             C2
             D1
             V
             Y1
             P1
             R
             A
             X1
             B
             D
             Y
             M
             B2
             K1
             X
             G2
             E
             J
             F1
             L1
             F2
             N1
             M1
             C1
             J1
             W
             K
             B1
             H
             Q
             D2
             T1
             A1
             H1
             I1
             O)
        (and (not (= H2 (- 1)))
     (not (= P 0))
     (<= 0 D2)
     (<= 0 T1)
     (<= 0 H1)
     (<= 0 A1)
     (<= 0 Y)
     (<= 0 O)
     (<= 0 D)
     (<= 0 B)
     (= H2 (- 4)))
      )
      (inv_main336 C
             S1
             E2
             S
             Z1
             G
             O1
             E1
             Q1
             Z
             V1
             I2
             F
             A2
             N
             I
             R1
             G1
             H2
             P
             U
             U1
             T
             W1
             L
             J2
             C2
             D1
             V
             Y1
             P1
             R
             A
             X1
             B
             D
             Y
             M
             B2
             K1
             X
             G2
             E
             J
             F1
             L1
             F2
             N1
             M1
             C1
             J1
             W
             K
             B1
             H
             Q
             D2
             T1
             A1
             H1
             I1
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main446 D2
             K2
             G2
             Z1
             G1
             X1
             O
             V
             G
             C2
             C
             L
             K
             R
             Q
             J2
             I1
             N
             S1
             B1
             F2
             H1
             M
             A2
             R1
             E
             W
             E2
             X
             Z
             L1
             A1
             T
             A
             N1
             F1
             J1
             V1
             S
             D
             B
             B2
             I2
             K1
             O1
             H2
             W1
             I
             J
             Y1
             F
             P1
             Q1
             Y
             H
             P
             C1
             T1
             D1
             U
             E1
             U1)
        (and (<= 0 U1)
     (<= 0 T1)
     (<= 0 N1)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 U)
     (= H 3))
      )
      (inv_main495 D2
             K2
             G2
             Z1
             G1
             X1
             O
             V
             G
             C2
             C
             L
             K
             R
             Q
             J2
             I1
             N
             S1
             B1
             F2
             H1
             M
             A2
             R1
             E
             W
             E2
             X
             Z
             L1
             A1
             T
             A
             N1
             F1
             J1
             V1
             S
             M1
             B
             B2
             I2
             K1
             O1
             H2
             W1
             I
             J
             Y1
             F
             P1
             Q1
             Y
             H
             P
             C1
             T1
             D1
             U
             E1
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main269 M1
             H2
             X
             U
             G
             Z1
             I
             F2
             B
             C2
             R
             V
             B1
             L1
             S1
             Z
             A1
             O
             H1
             D2
             E1
             U1
             E2
             K1
             Y1
             J
             I1
             F
             M
             I2
             X1
             F1
             B2
             E
             L
             O1
             A
             L2
             T1
             K2
             W1
             A2
             Y
             R1
             K
             G1
             G2
             H
             Q1
             W
             N1
             S
             D
             T
             D1
             C
             J2
             V1
             J1
             N
             P1
             C1)
        (and (= Q 2)
     (<= 0 A)
     (<= 0 J2)
     (<= 0 V1)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 C1)
     (<= 0 N)
     (<= 0 L)
     (= D1 1))
      )
      (inv_main272 M1
             H2
             X
             U
             G
             Z1
             I
             F2
             B
             C2
             R
             V
             B1
             L1
             S1
             Z
             A1
             O
             H1
             D2
             E1
             U1
             E2
             K1
             Y1
             J
             I1
             F
             M
             I2
             X1
             F1
             B2
             E
             L
             O1
             A
             L2
             T1
             P
             W1
             A2
             Y
             R1
             K
             G1
             G2
             H
             Q1
             W
             N1
             S
             D
             T
             Q
             C
             J2
             V1
             J1
             N
             P1
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main269 G2
             D2
             D
             S1
             D1
             E2
             U1
             R1
             Y
             C
             M1
             I2
             K
             J1
             K2
             U
             T
             B1
             N1
             L2
             X
             N
             J
             X1
             G1
             F2
             E
             L1
             E1
             H2
             Z
             P
             A1
             P1
             V1
             Y1
             I1
             C2
             H
             Q1
             F1
             B2
             G
             W
             J2
             T1
             F
             V
             C1
             B
             Z1
             S
             A
             O
             Q
             M
             I
             O1
             L
             H1
             R
             K1)
        (and (= Q 3)
     (not (= Q 1))
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 L)
     (<= 0 I)
     (= A2 4))
      )
      (inv_main272 G2
             D2
             D
             S1
             D1
             E2
             U1
             R1
             Y
             C
             M1
             I2
             K
             J1
             K2
             U
             T
             B1
             N1
             L2
             X
             N
             J
             X1
             G1
             F2
             E
             L1
             E1
             H2
             Z
             P
             A1
             P1
             V1
             Y1
             I1
             C2
             H
             W1
             F1
             B2
             G
             W
             J2
             T1
             F
             V
             C1
             B
             Z1
             S
             A
             O
             A2
             M
             I
             O1
             L
             H1
             R
             K1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main269 M
             Z
             O
             G2
             P
             D2
             H2
             L
             T1
             X1
             Q1
             K1
             O1
             T
             B
             Y1
             A
             S
             Y
             Q
             I2
             J2
             R1
             J
             I
             W
             U1
             W1
             D
             H1
             J1
             C2
             E1
             A2
             F1
             E
             F
             K
             H
             V
             V1
             L1
             I1
             R
             X
             C
             G1
             P1
             N1
             F2
             G
             B2
             S1
             M1
             K2
             Z1
             A1
             B1
             C1
             N
             E2
             D1)
        (and (not (= K2 1))
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 A1)
     (<= 0 N)
     (<= 0 F)
     (<= 0 E)
     (not (= K2 3)))
      )
      (inv_main272 M
             Z
             O
             G2
             P
             D2
             H2
             L
             T1
             X1
             Q1
             K1
             O1
             T
             B
             Y1
             A
             S
             Y
             Q
             I2
             J2
             R1
             J
             I
             W
             U1
             W1
             D
             H1
             J1
             C2
             E1
             A2
             F1
             E
             F
             K
             H
             U
             V1
             L1
             I1
             R
             X
             C
             G1
             P1
             N1
             F2
             G
             B2
             S1
             M1
             K2
             Z1
             A1
             B1
             C1
             N
             E2
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 S
             K1
             J
             A1
             J2
             Y
             I
             N1
             L1
             Y1
             M
             Z1
             L
             R
             D1
             F2
             E1
             V
             G2
             B1
             F
             M1
             B
             V1
             G
             Q
             I2
             J1
             W
             E
             E2
             Z
             H
             D2
             K
             O
             H2
             O1
             U
             T
             N
             T1
             P
             H1
             A
             W1
             U1
             G1
             X
             R1
             C1
             C
             P1
             S1
             C2
             I1
             X1
             B2
             Q1
             A2
             D
             F1)
        (and (not (= Y 8513))
     (not (= Y 8528))
     (not (= Y 8529))
     (not (= Y 8544))
     (not (= Y 8545))
     (not (= Y 8560))
     (not (= Y 8561))
     (not (= Y 8448))
     (not (= Y 8576))
     (not (= Y 8577))
     (not (= Y 8592))
     (not (= Y 8593))
     (not (= Y 8608))
     (not (= Y 8609))
     (not (= Y 8640))
     (not (= Y 8641))
     (not (= Y 8656))
     (not (= Y 8657))
     (= Y 8672)
     (not (= Y 8497))
     (not (= Y 12292))
     (not (= Y 8192))
     (not (= Y 24576))
     (not (= Y 8195))
     (not (= Y 8480))
     (not (= Y 8481))
     (not (= Y 8482))
     (not (= Y 8465))
     (not (= Y 8466))
     (not (= Y 8496))
     (not (= Y 8464))
     (not (= Y 16384))
     (<= 0 H2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 X1)
     (<= 0 Q1)
     (<= 0 F1)
     (<= 0 O)
     (<= 0 K)
     (not (= Y 8512))
     (= v_62 Y))
      )
      (inv_main446 S
             K1
             J
             A1
             J2
             Y
             I
             N1
             L1
             Y1
             M
             Z1
             L
             R
             D1
             F2
             E1
             V
             G2
             B1
             F
             M1
             B
             V1
             G
             Q
             I2
             J1
             W
             E
             E2
             Z
             H
             D2
             K
             O
             H2
             O1
             U
             T
             N
             v_62
             P
             H1
             A
             W1
             U1
             G1
             X
             R1
             C1
             C
             P1
             S1
             C2
             I1
             X1
             B2
             Q1
             A2
             D
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 I2
             C
             Q1
             C1
             B2
             T1
             K1
             E1
             P
             Z
             W1
             H2
             F2
             Y
             U
             E
             M
             Q
             U1
             V1
             K
             B
             A2
             R1
             H
             J1
             W
             J
             I1
             I
             O
             H1
             V
             M1
             T
             N
             B1
             S
             L
             L1
             R
             D
             Z1
             N1
             O1
             C2
             D2
             G1
             X
             A1
             Y1
             F
             G
             G2
             F1
             E2
             S1
             X1
             A
             P1
             D1
             J2)
        (and (not (= T1 8512))
     (not (= T1 8513))
     (not (= T1 8528))
     (not (= T1 8529))
     (not (= T1 8544))
     (not (= T1 8545))
     (not (= T1 8560))
     (not (= T1 8561))
     (not (= T1 8448))
     (not (= T1 8576))
     (not (= T1 8577))
     (not (= T1 8592))
     (not (= T1 8593))
     (not (= T1 8608))
     (not (= T1 8609))
     (not (= T1 8640))
     (not (= T1 8641))
     (not (= T1 8656))
     (not (= T1 8657))
     (not (= T1 8672))
     (not (= T1 8497))
     (not (= T1 12292))
     (not (= T1 8192))
     (not (= T1 24576))
     (not (= T1 8195))
     (not (= T1 8480))
     (not (= T1 8481))
     (not (= T1 8482))
     (not (= T1 8465))
     (not (= T1 8466))
     (not (= T1 8496))
     (not (= T1 8464))
     (not (= T1 16384))
     (<= 0 X1)
     (<= 0 S1)
     (<= 0 P1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 N)
     (<= 0 A)
     (<= 0 J2)
     (= T1 8673)
     (= v_62 T1))
      )
      (inv_main446 I2
             C
             Q1
             C1
             B2
             T1
             K1
             E1
             P
             Z
             W1
             H2
             F2
             Y
             U
             E
             M
             Q
             U1
             V1
             K
             B
             A2
             R1
             H
             J1
             W
             J
             I1
             I
             O
             H1
             V
             M1
             T
             N
             B1
             S
             L
             L1
             R
             v_62
             Z1
             N1
             O1
             C2
             D2
             G1
             X
             A1
             Y1
             F
             G
             G2
             F1
             E2
             S1
             X1
             A
             P1
             D1
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main199 Y
             H2
             M1
             L
             I1
             W1
             Z
             G1
             O
             O1
             P1
             M
             E2
             U
             N1
             X
             H
             B
             V
             A
             R
             D1
             H1
             J
             J1
             Y1
             G
             L1
             D
             C
             K1
             R1
             K
             B1
             W
             E
             C2
             Q
             C1
             T1
             X1
             Z1
             F
             D2
             B2
             T
             G2
             J2
             F2
             F1
             S1
             A2
             V1
             A1
             I2
             E1
             N
             S
             P
             I
             U1
             Q1)
        (and (= G 0)
     (= F 0)
     (<= 0 C2)
     (<= 0 Q1)
     (<= 0 W)
     (<= 0 S)
     (<= 0 P)
     (<= 0 N)
     (<= 0 I)
     (<= 0 E)
     (= N1 0))
      )
      (inv_main478 Y
             H2
             M1
             L
             I1
             W1
             Z
             G1
             O
             O1
             P1
             M
             E2
             U
             N1
             X
             H
             B
             V
             A
             R
             D1
             H1
             J
             J1
             Y1
             G
             L1
             D
             C
             K1
             R1
             K
             B1
             W
             E
             C2
             Q
             C1
             T1
             X1
             Z1
             F
             D2
             B2
             T
             G2
             J2
             F2
             F1
             S1
             A2
             V1
             A1
             I2
             E1
             N
             S
             P
             I
             U1
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main199 N1
             Z1
             R1
             J2
             E
             Y
             M
             I1
             V1
             E1
             C
             W1
             P1
             K2
             C1
             E2
             K
             H1
             X
             D2
             I
             I2
             H2
             B2
             L1
             Y1
             B1
             N
             M1
             G2
             W
             D
             A
             J
             B
             O1
             D1
             A1
             Z
             Q1
             V
             J1
             H
             R
             G
             G1
             L
             U1
             F2
             U
             A2
             X1
             C2
             S1
             K1
             F
             Q
             P
             F1
             T
             S
             T1)
        (and (= B1 0)
     (= H 0)
     (<= 0 T1)
     (<= 0 O1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 B)
     (not (<= O 0))
     (not (= C1 0)))
      )
      (inv_main478 N1
             Z1
             R1
             J2
             E
             Y
             M
             I1
             V1
             E1
             C
             W1
             P1
             K2
             C1
             E2
             K
             H1
             X
             D2
             I
             I2
             H2
             B2
             L1
             Y1
             B1
             N
             M1
             G2
             W
             D
             A
             J
             B
             O1
             D1
             A1
             Z
             O
             V
             J1
             H
             R
             G
             G1
             L
             U1
             F2
             U
             A2
             X1
             C2
             S1
             K1
             F
             Q
             P
             F1
             T
             S
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 J1
             H1
             Q
             B
             M
             F
             I2
             D1
             H
             I1
             H2
             V1
             A1
             E1
             X
             P
             D2
             F2
             B1
             I
             Y
             W
             M1
             B2
             D
             Z
             U1
             L
             O1
             U
             G2
             E2
             R1
             L1
             N1
             K
             C1
             S1
             W1
             C
             T1
             X1
             R
             F1
             Q1
             V
             J2
             A2
             N
             K1
             T
             E
             G1
             P1
             S
             O
             Y1
             C2
             G
             J
             A
             Z1)
        (and (not (= F 8513))
     (not (= F 8528))
     (not (= F 8529))
     (= F 8544)
     (not (= F 8497))
     (not (= F 12292))
     (not (= F 8192))
     (not (= F 24576))
     (not (= F 8195))
     (not (= F 8480))
     (not (= F 8481))
     (not (= F 8482))
     (not (= F 8465))
     (not (= F 8466))
     (not (= F 8496))
     (not (= F 8464))
     (not (= F 16384))
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 Y1)
     (<= 0 N1)
     (<= 0 C1)
     (<= 0 K)
     (<= 0 J)
     (<= 0 G)
     (not (= F 8512))
     (= v_62 F))
      )
      (inv_main330 J1
             H1
             Q
             B
             M
             F
             I2
             D1
             H
             I1
             H2
             V1
             A1
             E1
             X
             P
             D2
             F2
             B1
             I
             Y
             W
             M1
             B2
             D
             Z
             U1
             L
             O1
             U
             G2
             E2
             R1
             L1
             N1
             K
             C1
             S1
             W1
             C
             T1
             v_62
             R
             F1
             Q1
             V
             J2
             A2
             N
             K1
             T
             E
             G1
             P1
             S
             O
             Y1
             C2
             G
             J
             A
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 T
             H2
             N1
             M1
             V1
             E
             N
             F2
             J2
             S1
             T1
             Z
             W
             Y
             F
             R1
             W1
             X
             P1
             J1
             R
             D1
             G2
             P
             V
             H
             M
             Z1
             J
             E2
             I1
             A1
             O1
             D
             B2
             K
             Q
             I2
             A
             X1
             Y1
             D2
             B
             S
             U
             H1
             G
             F1
             O
             B1
             U1
             C1
             G1
             E1
             C2
             C
             K1
             Q1
             I
             L1
             L
             A2)
        (and (not (= E 8513))
     (not (= E 8528))
     (not (= E 8529))
     (not (= E 8544))
     (= E 8545)
     (not (= E 8497))
     (not (= E 12292))
     (not (= E 8192))
     (not (= E 24576))
     (not (= E 8195))
     (not (= E 8480))
     (not (= E 8481))
     (not (= E 8482))
     (not (= E 8465))
     (not (= E 8466))
     (not (= E 8496))
     (not (= E 8464))
     (not (= E 16384))
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 K1)
     (<= 0 Q)
     (<= 0 K)
     (<= 0 I)
     (not (= E 8512))
     (= v_62 E))
      )
      (inv_main330 T
             H2
             N1
             M1
             V1
             E
             N
             F2
             J2
             S1
             T1
             Z
             W
             Y
             F
             R1
             W1
             X
             P1
             J1
             R
             D1
             G2
             P
             V
             H
             M
             Z1
             J
             E2
             I1
             A1
             O1
             D
             B2
             K
             Q
             I2
             A
             X1
             Y1
             v_62
             B
             S
             U
             H1
             G
             F1
             O
             B1
             U1
             C1
             G1
             E1
             C2
             C
             K1
             Q1
             I
             L1
             L
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main118 H2
             M1
             Z1
             J1
             D2
             I2
             Z
             W
             B2
             D1
             F1
             L1
             D
             T
             A
             K
             N
             C1
             C2
             G
             E
             E2
             I
             I1
             B
             G2
             R
             Q
             Q1
             S
             W1
             F
             U
             Y
             R1
             K2
             A1
             V1
             M
             O
             P1
             X1
             O1
             F2
             V
             L
             S1
             U1
             H1
             P
             N1
             C
             J
             X
             H
             T1
             B1
             J2
             K1
             A2
             Y1
             E1)
        (and (not (= I2 8192))
     (not (= I2 24576))
     (not (= I2 8195))
     (not (= I2 8480))
     (not (= I2 8481))
     (= I2 8482)
     (not (= I2 16384))
     (= G1 3)
     (<= 0 A2)
     (<= 0 R1)
     (<= 0 K1)
     (<= 0 E1)
     (<= 0 B1)
     (<= 0 A1)
     (<= 0 K2)
     (<= 0 J2)
     (not (= I2 12292)))
      )
      (inv_main199 H2
             M1
             Z1
             J1
             D2
             G1
             Z
             W
             B2
             D1
             F1
             L1
             D
             T
             A
             K
             N
             C1
             C2
             G
             E
             E2
             I
             I1
             B
             G2
             R
             Q
             Q1
             S
             W1
             F
             U
             Y
             R1
             K2
             A1
             V1
             M
             O
             P1
             I2
             O1
             F2
             V
             L
             S1
             U1
             H1
             P
             N1
             C
             J
             X
             H
             T1
             B1
             J2
             K1
             A2
             Y1
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main118 J2
             I2
             T
             I
             U
             E
             C2
             E1
             Y1
             X
             R1
             V1
             N1
             J1
             B1
             Q
             P
             D1
             M
             D
             U1
             Q1
             F2
             H1
             K1
             O1
             H
             R
             P1
             I1
             H2
             A2
             N
             O2
             O
             N2
             B2
             Z1
             K2
             X1
             M2
             W
             T1
             A
             G
             Y
             M1
             L2
             C
             W1
             L1
             G1
             E2
             Z
             J
             L
             F
             B
             C1
             S
             K
             A1)
        (and (= D2 8448)
     (= S1 8482)
     (= V 0)
     (not (= E 12292))
     (not (= E 8192))
     (not (= E 24576))
     (not (= E 8195))
     (= E 8480)
     (not (= E 16384))
     (<= 0 B)
     (<= 0 B2)
     (<= 0 C1)
     (<= 0 A1)
     (<= 0 S)
     (<= 0 O)
     (<= 0 F)
     (<= 0 N2)
     (not (<= F1 0))
     (= G2 0))
      )
      (inv_main199 J2
             I2
             T
             I
             U
             D2
             C2
             E1
             Y1
             X
             V
             V1
             N1
             J1
             B1
             G2
             P
             D1
             M
             D
             U1
             Q1
             F2
             H1
             K1
             O1
             H
             R
             P1
             I1
             S1
             A2
             N
             O2
             O
             N2
             B2
             Z1
             K2
             F1
             M2
             E
             T1
             A
             G
             Y
             M1
             L2
             C
             W1
             L1
             G1
             E2
             Z
             J
             L
             F
             B
             C1
             S
             K
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main118 P
             D2
             M
             M2
             N2
             S1
             W1
             J2
             V
             C2
             S
             K
             E
             F
             L2
             L1
             C
             F2
             H
             G
             W
             R
             H2
             F1
             C1
             Q
             T1
             O
             I2
             Y
             O1
             G2
             J
             X
             T
             B1
             I1
             B
             N
             X1
             O2
             D
             P1
             N1
             K1
             A1
             Z
             R1
             M1
             H1
             B2
             D1
             E2
             Y1
             L
             I
             A2
             U1
             U
             A
             J1
             Z1)
        (and (not (= S1 12292))
     (not (= S1 8192))
     (not (= S1 24576))
     (not (= S1 8195))
     (not (= S1 8480))
     (= S1 8481)
     (not (= S1 16384))
     (= Q1 8482)
     (= G1 0)
     (= E1 8448)
     (<= 0 A)
     (<= 0 A2)
     (<= 0 Z1)
     (<= 0 U1)
     (<= 0 I1)
     (<= 0 B1)
     (<= 0 U)
     (<= 0 T)
     (not (<= K2 0))
     (= V1 0))
      )
      (inv_main199 P
             D2
             M
             M2
             N2
             E1
             W1
             J2
             V
             C2
             V1
             K
             E
             F
             L2
             G1
             C
             F2
             H
             G
             W
             R
             H2
             F1
             C1
             Q
             T1
             O
             I2
             Y
             Q1
             G2
             J
             X
             T
             B1
             I1
             B
             N
             K2
             O2
             S1
             P1
             N1
             K1
             A1
             Z
             R1
             M1
             H1
             B2
             D1
             E2
             Y1
             L
             I
             A2
             U1
             U
             A
             J1
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main118 E
             V
             K1
             J
             A1
             U
             T1
             H2
             Z1
             W
             U1
             D1
             N2
             O
             I
             Z
             D2
             H
             G
             M2
             J1
             I2
             R1
             Q1
             S1
             W1
             C1
             E2
             M1
             F2
             V1
             L2
             B2
             H1
             J2
             Y1
             L
             A
             D
             X
             C2
             R
             I1
             M
             F
             K2
             B
             C
             E1
             Q
             G2
             G1
             S
             O1
             L1
             N1
             Y
             X1
             A2
             B1
             K
             P1)
        (and (not (= U 8512))
     (not (= U 8513))
     (not (= U 8528))
     (not (= U 8529))
     (not (= U 8544))
     (not (= U 8545))
     (= U 8560)
     (not (= U 8497))
     (not (= U 12292))
     (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (not (= U 8465))
     (not (= U 8466))
     (not (= U 8496))
     (not (= U 8464))
     (not (= U 16384))
     (= P 8576)
     (= N 8448)
     (<= 0 J2)
     (<= 0 A2)
     (<= 0 Y1)
     (<= 0 X1)
     (<= 0 P1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 L)
     (not (<= T 0))
     (= F1 0))
      )
      (inv_main199 E
             V
             K1
             J
             A1
             N
             T1
             H2
             Z1
             W
             F1
             D1
             N2
             O
             I
             Z
             D2
             H
             G
             M2
             J1
             I2
             R1
             Q1
             S1
             W1
             C1
             E2
             M1
             F2
             P
             L2
             B2
             H1
             J2
             Y1
             L
             A
             D
             T
             C2
             U
             I1
             M
             F
             K2
             B
             C
             E1
             Q
             G2
             G1
             S
             O1
             L1
             N1
             Y
             X1
             A2
             B1
             K
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main118 E2
             J1
             I
             P
             A
             X
             Z
             T
             U1
             M2
             T1
             P1
             H
             X1
             N
             S1
             N2
             D1
             F1
             V1
             I1
             A1
             M
             B
             H2
             J2
             W
             O
             S
             J
             G
             C2
             K1
             K2
             L1
             G2
             L
             O1
             E1
             K
             U
             H1
             B1
             Y1
             D2
             M1
             F2
             Y
             C1
             F
             W1
             R1
             E
             C
             B2
             I2
             L2
             A2
             G1
             D
             R
             Q1)
        (and (= N1 0)
     (not (= X 8512))
     (not (= X 8513))
     (not (= X 8528))
     (not (= X 8529))
     (not (= X 8544))
     (not (= X 8545))
     (not (= X 8560))
     (= X 8561)
     (not (= X 8497))
     (not (= X 12292))
     (not (= X 8192))
     (not (= X 24576))
     (not (= X 8195))
     (not (= X 8480))
     (not (= X 8481))
     (not (= X 8482))
     (not (= X 8465))
     (not (= X 8466))
     (not (= X 8496))
     (not (= X 8464))
     (not (= X 16384))
     (= V 8576)
     (<= 0 L2)
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 G1)
     (<= 0 L)
     (<= 0 D)
     (not (<= Q 0))
     (= Z1 8448))
      )
      (inv_main199 E2
             J1
             I
             P
             A
             Z1
             Z
             T
             U1
             M2
             N1
             P1
             H
             X1
             N
             S1
             N2
             D1
             F1
             V1
             I1
             A1
             M
             B
             H2
             J2
             W
             O
             S
             J
             V
             C2
             K1
             K2
             L1
             G2
             L
             O1
             E1
             Q
             U
             X
             B1
             Y1
             D2
             M1
             F2
             Y
             C1
             F
             W1
             R1
             E
             C
             B2
             I2
             L2
             A2
             G1
             D
             R
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main118 A1
             H2
             I
             Y
             F1
             C
             P1
             W1
             H
             A
             B1
             T1
             M1
             V
             F
             J1
             F2
             N
             U1
             K1
             L1
             K2
             Q
             Z1
             S
             Y1
             Z
             P
             O
             C1
             E2
             G1
             X1
             N1
             I2
             U
             D2
             T
             E1
             B
             L
             W
             E
             R1
             M
             C2
             S1
             M2
             Q1
             K
             L2
             A2
             R
             D
             B2
             V1
             D1
             I1
             J2
             J
             G
             O1)
        (and (= H1 8608)
     (not (= C 8512))
     (not (= C 8513))
     (not (= C 8528))
     (not (= C 8529))
     (not (= C 8544))
     (not (= C 8545))
     (not (= C 8560))
     (not (= C 8561))
     (not (= C 8448))
     (not (= C 8576))
     (not (= C 8577))
     (= C 8592)
     (not (= C 8497))
     (not (= C 12292))
     (not (= C 8192))
     (not (= C 24576))
     (not (= C 8195))
     (not (= C 8480))
     (not (= C 8481))
     (not (= C 8482))
     (not (= C 8465))
     (not (= C 8466))
     (not (= C 8496))
     (not (= C 8464))
     (not (= C 16384))
     (<= 0 J2)
     (<= 0 I2)
     (<= 0 D2)
     (<= 0 O1)
     (<= 0 I1)
     (<= 0 D1)
     (<= 0 U)
     (<= 0 J)
     (not (<= X 0))
     (= G2 0))
      )
      (inv_main199 A1
             H2
             I
             Y
             F1
             H1
             P1
             W1
             H
             A
             G2
             T1
             M1
             V
             F
             J1
             F2
             N
             U1
             K1
             L1
             K2
             Q
             Z1
             S
             Y1
             Z
             P
             O
             C1
             E2
             G1
             X1
             N1
             I2
             U
             D2
             T
             E1
             X
             L
             C
             E
             R1
             M
             C2
             S1
             M2
             Q1
             K
             L2
             A2
             R
             D
             B2
             V1
             D1
             I1
             J2
             J
             G
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main118 L2
             I2
             Q1
             H
             V
             A1
             H1
             Z1
             R1
             P
             C
             R
             U
             N1
             U1
             O1
             K
             B2
             Y1
             M
             S
             E2
             S1
             D2
             Q
             F1
             A2
             K2
             X
             G1
             H2
             J
             E1
             J2
             T
             G
             L1
             M1
             V1
             G2
             D
             C1
             X1
             E
             P1
             D1
             K1
             C2
             T1
             W1
             B
             J1
             Z
             L
             I1
             N
             M2
             I
             W
             F2
             B1
             Y)
        (and (not (= A1 8512))
     (not (= A1 8513))
     (not (= A1 8528))
     (not (= A1 8529))
     (not (= A1 8544))
     (not (= A1 8545))
     (not (= A1 8560))
     (not (= A1 8561))
     (not (= A1 8448))
     (not (= A1 8576))
     (not (= A1 8577))
     (not (= A1 8592))
     (= A1 8593)
     (not (= A1 8497))
     (not (= A1 12292))
     (not (= A1 8192))
     (not (= A1 24576))
     (not (= A1 8195))
     (not (= A1 8480))
     (not (= A1 8481))
     (not (= A1 8482))
     (not (= A1 8465))
     (not (= A1 8466))
     (not (= A1 8496))
     (not (= A1 8464))
     (not (= A1 16384))
     (= F 0)
     (<= 0 F2)
     (<= 0 L1)
     (<= 0 Y)
     (<= 0 W)
     (<= 0 T)
     (<= 0 I)
     (<= 0 G)
     (<= 0 M2)
     (not (<= O 0))
     (= A 8608))
      )
      (inv_main199 L2
             I2
             Q1
             H
             V
             A
             H1
             Z1
             R1
             P
             F
             R
             U
             N1
             U1
             O1
             K
             B2
             Y1
             M
             S
             E2
             S1
             D2
             Q
             F1
             A2
             K2
             X
             G1
             H2
             J
             E1
             J2
             T
             G
             L1
             M1
             V1
             O
             D
             A1
             X1
             E
             P1
             D1
             K1
             C2
             T1
             W1
             B
             J1
             Z
             L
             I1
             N
             M2
             I
             W
             F2
             B1
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main118 J1
             Y1
             U
             F1
             B1
             E2
             G2
             L2
             A2
             F
             C
             A
             D2
             Z
             K
             I
             B
             T
             D
             P1
             Z1
             I2
             M1
             W
             S1
             X
             O1
             Q
             L
             N
             C2
             I1
             X1
             G1
             J
             H1
             Y
             H
             F2
             W1
             G
             L1
             B2
             V
             K1
             A1
             H2
             R1
             M2
             V1
             D1
             N1
             P
             J2
             T1
             U1
             R
             Q1
             O
             K2
             E1
             E)
        (and (not (= E2 8513))
     (not (= E2 8528))
     (not (= E2 8529))
     (not (= E2 8544))
     (not (= E2 8545))
     (not (= E2 8560))
     (not (= E2 8561))
     (not (= E2 8448))
     (not (= E2 8576))
     (not (= E2 8577))
     (not (= E2 8592))
     (not (= E2 8593))
     (= E2 8608)
     (not (= E2 8497))
     (not (= E2 12292))
     (not (= E2 8192))
     (not (= E2 24576))
     (not (= E2 8195))
     (not (= E2 8480))
     (not (= E2 8481))
     (not (= E2 8482))
     (not (= E2 8465))
     (not (= E2 8466))
     (not (= E2 8496))
     (not (= E2 8464))
     (not (= E2 16384))
     (= C1 8640)
     (= M 0)
     (<= 0 K2)
     (<= 0 Q1)
     (<= 0 H1)
     (<= 0 Y)
     (<= 0 R)
     (<= 0 O)
     (<= 0 J)
     (<= 0 E)
     (not (<= S 0))
     (not (= E2 8512)))
      )
      (inv_main199 J1
             Y1
             U
             F1
             B1
             C1
             G2
             L2
             A2
             F
             M
             A
             D2
             Z
             K
             I
             B
             T
             D
             P1
             Z1
             I2
             M1
             W
             S1
             X
             O1
             Q
             L
             N
             C2
             I1
             X1
             G1
             J
             H1
             Y
             H
             F2
             S
             G
             E2
             B2
             V
             K1
             A1
             H2
             R1
             M2
             V1
             D1
             N1
             P
             J2
             T1
             U1
             R
             Q1
             O
             K2
             E1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main118 Z
             F
             P1
             J
             U1
             B2
             Q
             S1
             L1
             L2
             D2
             I1
             H2
             N1
             F1
             M1
             O1
             G1
             K2
             C
             L
             W
             A2
             P
             G
             B
             G2
             M2
             Q1
             R
             V1
             O
             E
             K1
             V
             B1
             X
             M
             H1
             D1
             E1
             T
             T1
             J2
             H
             S
             A
             C1
             W1
             I2
             K
             U
             N
             R1
             J1
             F2
             C2
             D
             Y
             Y1
             A1
             I)
        (and (not (= B2 8512))
     (not (= B2 8513))
     (not (= B2 8528))
     (not (= B2 8529))
     (not (= B2 8544))
     (not (= B2 8545))
     (not (= B2 8560))
     (not (= B2 8561))
     (not (= B2 8448))
     (not (= B2 8576))
     (not (= B2 8577))
     (not (= B2 8592))
     (not (= B2 8593))
     (not (= B2 8608))
     (= B2 8609)
     (not (= B2 8497))
     (not (= B2 12292))
     (not (= B2 8192))
     (not (= B2 24576))
     (not (= B2 8195))
     (not (= B2 8480))
     (not (= B2 8481))
     (not (= B2 8482))
     (not (= B2 8465))
     (not (= B2 8466))
     (not (= B2 8496))
     (not (= B2 8464))
     (not (= B2 16384))
     (= Z1 0)
     (<= 0 C2)
     (<= 0 Y1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 V)
     (<= 0 I)
     (<= 0 D)
     (not (<= X1 0))
     (= E2 8640))
      )
      (inv_main199 Z
             F
             P1
             J
             U1
             E2
             Q
             S1
             L1
             L2
             Z1
             I1
             H2
             N1
             F1
             M1
             O1
             G1
             K2
             C
             L
             W
             A2
             P
             G
             B
             G2
             M2
             Q1
             R
             V1
             O
             E
             K1
             V
             B1
             X
             M
             H1
             X1
             E1
             B2
             T1
             J2
             H
             S
             A
             C1
             W1
             I2
             K
             U
             N
             R1
             J1
             F2
             C2
             D
             Y
             Y1
             A1
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main255 L
             Q
             H1
             G2
             C2
             T1
             D2
             X
             P2
             E2
             I2
             D
             A
             B1
             K
             I
             H2
             G
             N1
             Z
             B
             D1
             I1
             L2
             J1
             A2
             C
             S
             O2
             V
             P
             M2
             U
             A1
             W1
             K1
             Y
             R1
             V1
             C1
             Q1
             Y1
             L1
             F
             W
             O1
             B2
             F2
             X1
             G1
             P1
             N
             Z1
             O
             F1
             T
             N2
             J2
             S1
             E
             M1
             M)
        (and (= U1 8496)
     (= F1 0)
     (= R 1)
     (= J 0)
     (= H 1)
     (<= 0 E)
     (<= 0 N2)
     (<= 0 J2)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 K1)
     (<= 0 Y)
     (<= 0 M)
     (not (<= E1 0))
     (= K2 0))
      )
      (inv_main199 L
             Q
             H1
             G2
             C2
             U1
             D2
             X
             P2
             E2
             J
             D
             A
             B1
             K
             K2
             H2
             G
             N1
             Z
             B
             D1
             I1
             L2
             J1
             A2
             C
             S
             O2
             V
             P
             M2
             U
             A1
             W1
             K1
             Y
             R1
             V1
             E1
             Q1
             Y1
             L1
             H
             W
             O1
             B2
             F2
             X1
             G1
             P1
             N
             Z1
             O
             R
             T
             N2
             J2
             S1
             E
             M1
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main255 P1
             P
             A1
             K1
             O
             D
             A2
             E
             B2
             H
             I1
             D2
             R1
             K
             L1
             G1
             T1
             Q
             M
             M2
             I
             O1
             H2
             G2
             E1
             C
             N1
             N
             Z1
             U
             G
             L
             S
             L2
             O2
             B1
             X1
             M1
             Y
             K2
             I2
             S1
             F1
             D1
             C1
             T
             F
             Q1
             B
             J
             U1
             J2
             W
             F2
             V
             J1
             X
             N2
             W1
             V1
             E2
             H1)
        (and (= Y1 1)
     (= Z 0)
     (not (= V 0))
     (= R 8496)
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 V1)
     (<= 0 H1)
     (<= 0 B1)
     (<= 0 X)
     (<= 0 O2)
     (<= 0 N2)
     (not (<= A 0))
     (= C2 0))
      )
      (inv_main199 P1
             P
             A1
             K1
             O
             R
             A2
             E
             B2
             H
             C2
             D2
             R1
             K
             L1
             Z
             T1
             Q
             M
             M2
             I
             O1
             H2
             G2
             E1
             C
             N1
             N
             Z1
             U
             G
             L
             S
             L2
             O2
             B1
             X1
             M1
             Y
             A
             I2
             S1
             F1
             Y1
             C1
             T
             F
             Q1
             B
             J
             U1
             J2
             W
             F2
             V
             J1
             X
             N2
             W1
             V1
             E2
             H1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main272 H
             J1
             J
             T1
             K
             D1
             V1
             W
             P
             A1
             G2
             C
             I
             H1
             G
             L1
             N1
             A
             R1
             B2
             K2
             B
             A2
             T
             L2
             B1
             C1
             C2
             S
             I1
             O
             I2
             J2
             E1
             X1
             F2
             M1
             S1
             F1
             H2
             K1
             V
             R
             E2
             X
             Y
             F
             U1
             W1
             Z1
             E
             Q1
             G1
             D
             D2
             Z
             Y1
             Q
             O1
             U
             P1
             L)
        (and (= M 0)
     (not (= C 0))
     (<= 0 F2)
     (<= 0 Y1)
     (<= 0 X1)
     (<= 0 O1)
     (<= 0 M1)
     (<= 0 U)
     (<= 0 Q)
     (<= 0 L)
     (not (<= H2 0))
     (= N 8656))
      )
      (inv_main199 H
             J1
             J
             T1
             K
             N
             V1
             W
             P
             A1
             M
             C
             I
             H1
             G
             L1
             N1
             A
             R1
             B2
             K2
             B
             A2
             T
             L2
             B1
             C1
             C2
             S
             I1
             O
             I2
             J2
             E1
             X1
             F2
             M1
             S1
             F1
             H2
             K1
             V
             R
             E2
             X
             Y
             F
             U1
             W1
             Z1
             E
             Q1
             G1
             D
             D2
             Z
             Y1
             Q
             O1
             U
             P1
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main272 D2
             A
             O1
             S1
             B
             Q1
             R1
             A1
             O
             K1
             N1
             M1
             M
             S
             H
             F
             C
             A2
             Q
             D1
             J2
             X
             G
             K
             I
             K2
             B2
             V
             L
             R
             P
             C2
             Y1
             I1
             T1
             H1
             B1
             I2
             G1
             X1
             F2
             F1
             G2
             D
             E2
             E1
             U
             C1
             J1
             Z
             L1
             W
             Z1
             W1
             H2
             U1
             J
             Y
             V1
             L2
             E
             P1)
        (and (= T 8512)
     (= N 0)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 P1)
     (<= 0 H1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 J)
     (<= 0 L2)
     (not (<= X1 0))
     (= M1 0))
      )
      (inv_main199 D2
             A
             O1
             S1
             B
             T
             R1
             A1
             O
             K1
             N
             M1
             M
             S
             H
             F
             C
             A2
             Q
             D1
             J2
             X
             G
             K
             I
             K2
             B2
             V
             L
             R
             P
             C2
             Y1
             I1
             T1
             H1
             B1
             I2
             G1
             X1
             F2
             F1
             G2
             D
             E2
             E1
             U
             C1
             J1
             Z
             L1
             W
             Z1
             W1
             H2
             U1
             J
             Y
             V1
             L2
             E
             P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 Y
             K1
             X
             M1
             Q1
             E
             C
             G2
             P1
             B
             O1
             J
             A2
             B1
             B2
             N1
             F2
             M
             L1
             Z1
             H1
             D1
             N
             I2
             C2
             K
             L
             S
             S1
             G1
             C1
             F1
             Y1
             E2
             R
             U
             V1
             X1
             W
             G
             I
             A
             H2
             H
             D2
             V
             I1
             R1
             T1
             J2
             E1
             D
             Q
             F
             P
             J1
             U1
             A1
             O
             Z
             W1
             T)
        (and (not (= E 8513))
     (not (= E 8528))
     (not (= E 8529))
     (not (= E 8544))
     (not (= E 8545))
     (not (= E 8560))
     (not (= E 8561))
     (= E 8448)
     (not (= E 8497))
     (not (= E 12292))
     (not (= E 8192))
     (not (= E 24576))
     (not (= E 8195))
     (not (= E 8480))
     (not (= E 8481))
     (not (= E 8482))
     (not (= E 8465))
     (not (= E 8466))
     (not (= E 8496))
     (not (= E 8464))
     (not (= E 16384))
     (not (<= 1 W))
     (<= 0 V1)
     (<= 0 U1)
     (<= 0 A1)
     (<= 0 Z)
     (<= 0 U)
     (<= 0 T)
     (<= 0 R)
     (<= 0 O)
     (not (= E 8512))
     (= v_62 C1))
      )
      (inv_main199 Y
             K1
             X
             M1
             Q1
             C1
             C
             G2
             P1
             B
             O1
             J
             A2
             B1
             B2
             N1
             F2
             M
             L1
             Z1
             H1
             D1
             N
             I2
             C2
             K
             L
             S
             S1
             G1
             v_62
             F1
             Y1
             E2
             R
             U
             V1
             X1
             W
             G
             I
             E
             H2
             H
             D2
             V
             I1
             R1
             T1
             J2
             E1
             D
             Q
             F
             P
             J1
             U1
             A1
             O
             Z
             W1
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main118 M1
             B2
             B1
             U1
             V1
             W1
             T
             U
             P
             Q
             C
             C2
             O
             E
             V
             A1
             G2
             L1
             T1
             N
             X
             R
             P1
             K2
             G
             F2
             E1
             B
             K1
             H2
             H1
             E2
             Q1
             I2
             R1
             D1
             D2
             K
             C1
             J2
             M
             F
             Z
             J
             W
             J1
             A2
             O1
             I1
             A
             N1
             L
             D
             Y1
             G1
             F1
             Y
             H
             S1
             I
             S
             Z1)
        (and (not (= W1 8512))
     (not (= W1 8513))
     (not (= W1 8528))
     (not (= W1 8529))
     (not (= W1 8544))
     (not (= W1 8545))
     (not (= W1 8560))
     (not (= W1 8561))
     (= W1 8448)
     (not (= W1 8497))
     (not (= W1 12292))
     (not (= W1 8192))
     (not (= W1 24576))
     (not (= W1 8195))
     (not (= W1 8480))
     (not (= W1 8481))
     (not (= W1 8482))
     (not (= W1 8465))
     (not (= W1 8466))
     (not (= W1 8496))
     (not (= W1 8464))
     (not (= W1 16384))
     (<= 1 C1)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 I)
     (<= 0 H)
     (not (<= L 0))
     (= X1 1)
     (= v_63 H1)
     (= v_64 L))
      )
      (inv_main199 M1
             B2
             B1
             U1
             V1
             H1
             T
             U
             P
             Q
             C
             C2
             X1
             E
             V
             A1
             G2
             L1
             T1
             N
             X
             R
             P1
             K2
             G
             F2
             E1
             B
             K1
             H2
             v_63
             E2
             Q1
             I2
             R1
             D1
             D2
             K
             L
             J2
             M
             W1
             Z
             J
             W
             J1
             A2
             O1
             I1
             A
             N1
             v_64
             D
             Y1
             G1
             F1
             Y
             H
             S1
             I
             S
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main446 B
             S1
             Y
             U
             H1
             P1
             Y1
             R
             Z1
             F2
             M2
             X
             J2
             N2
             L1
             W1
             I
             E
             H2
             E2
             C
             O1
             G2
             J
             K2
             L2
             B2
             R1
             M
             I1
             C1
             U1
             L
             D2
             D1
             F
             P
             T
             Q
             K1
             H
             Q1
             N1
             X1
             W
             A2
             K
             G1
             B1
             T1
             D
             I2
             V1
             N
             O
             M1
             F1
             G
             S
             A
             E1
             C2)
        (and (= Z 8640)
     (not (= X 0))
     (= V 8448)
     (not (= O 3))
     (<= 0 A)
     (<= 0 C2)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 S)
     (<= 0 P)
     (<= 0 G)
     (<= 0 F)
     (not (<= A1 0))
     (= J1 0))
      )
      (inv_main199 B
             S1
             Y
             U
             H1
             V
             Y1
             R
             Z1
             F2
             J1
             X
             J2
             N2
             L1
             W1
             I
             E
             H2
             E2
             C
             O1
             G2
             J
             K2
             L2
             B2
             R1
             M
             I1
             Z
             U1
             L
             D2
             D1
             F
             P
             T
             Q
             A1
             H
             Q1
             N1
             X1
             W
             A2
             K
             G1
             B1
             T1
             D
             I2
             V1
             N
             O
             M1
             F1
             G
             S
             A
             E1
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main446 Y1
             U
             A2
             V1
             H1
             N
             I
             T1
             G2
             J
             K2
             O1
             B1
             K
             I2
             N1
             E2
             W
             T
             K1
             P1
             J1
             F2
             M2
             M1
             H
             S1
             U1
             A
             E1
             V
             F
             G1
             C
             D
             S
             Z1
             Q1
             I1
             F1
             Z
             B
             Y
             L
             X1
             D1
             W1
             D2
             L1
             M
             R1
             R
             C2
             A1
             C1
             E
             G
             Q
             X
             P
             B2
             L2)
        (and (= O1 0)
     (not (= C1 3))
     (= O 3)
     (= N2 8448)
     (<= 0 L2)
     (<= 0 Z1)
     (<= 0 X)
     (<= 0 S)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 G)
     (<= 0 D)
     (not (<= H2 0))
     (= J2 0))
      )
      (inv_main199 Y1
             U
             A2
             V1
             H1
             N2
             I
             T1
             G2
             J
             J2
             O1
             B1
             K
             I2
             N1
             E2
             W
             T
             K1
             P1
             J1
             F2
             M2
             M1
             H
             S1
             U1
             A
             E1
             O
             F
             G1
             C
             D
             S
             Z1
             Q1
             I1
             H2
             Z
             B
             Y
             L
             X1
             D1
             W1
             D2
             L1
             M
             R1
             R
             C2
             A1
             C1
             E
             G
             Q
             X
             P
             B2
             L2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main300 C2
             E1
             N
             J
             Y
             M
             W1
             P1
             W
             F2
             C
             Y1
             T
             G2
             E2
             O
             J1
             B2
             H1
             H2
             K2
             D
             I1
             L1
             X1
             L
             S1
             B
             B1
             G1
             E
             H
             L2
             U
             V1
             A1
             S
             K
             U1
             G
             X
             Q1
             P
             D1
             K1
             R1
             O1
             M2
             C1
             R
             T1
             Q
             I2
             A
             N1
             F1
             F
             Z1
             Z
             D2
             V
             M1)
        (and (= J2 8544)
     (= A2 0)
     (= V1 (- 30))
     (= V1 (- 1))
     (= I 1)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 M1)
     (<= 0 A1)
     (<= 0 Z)
     (<= 0 S)
     (<= 0 F)
     (= B 0))
      )
      (inv_main199 C2
             E1
             N
             J
             Y
             J2
             W1
             P1
             W
             F2
             A2
             Y1
             T
             G2
             E2
             O
             J1
             B2
             H1
             H2
             K2
             D
             I1
             L1
             X1
             L
             S1
             B
             B1
             G1
             E
             H
             L2
             U
             V1
             A1
             S
             K
             U1
             G
             X
             Q1
             I
             D1
             K1
             R1
             O1
             M2
             C1
             R
             T1
             Q
             I2
             A
             N1
             F1
             F
             Z1
             Z
             D2
             V
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main300 M2
             E1
             S
             O1
             J1
             B1
             T
             E
             P1
             U
             Y
             C
             A1
             K2
             R
             F2
             X
             C2
             I1
             X1
             L
             D
             B
             F
             U1
             B2
             H
             R1
             A2
             N
             J2
             G1
             H1
             O
             D2
             F1
             I
             G2
             T1
             Q1
             C1
             M1
             H2
             K
             W
             L2
             N1
             V
             Z
             V1
             I2
             Y1
             A
             W1
             Q
             G
             E2
             J
             D1
             P
             K1
             L1)
        (and (not (= D2 (- 1)))
     (= Z1 0)
     (= S1 8544)
     (= R1 0)
     (= G1 (- 2))
     (= M 1)
     (not (= L 0))
     (<= 0 E2)
     (<= 0 D2)
     (<= 0 L1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 P)
     (<= 0 J)
     (<= 0 I)
     (= D2 (- 30))
     (= v_65 G1))
      )
      (inv_main199 M2
             E1
             S
             O1
             J1
             S1
             T
             E
             P1
             U
             Z1
             C
             A1
             K2
             R
             F2
             X
             C2
             I1
             X1
             L
             D
             B
             F
             U1
             B2
             H
             R1
             A2
             N
             J2
             G1
             H1
             O
             D2
             F1
             I
             G2
             T1
             Q1
             C1
             M1
             M
             K
             W
             L2
             N1
             V
             Z
             V1
             I2
             Y1
             A
             W1
             Q
             G
             E2
             J
             v_65
             P
             K1
             L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main300 J2
             Z1
             G
             R1
             M
             S
             Y1
             W
             O2
             F
             H
             P1
             N2
             E2
             L1
             Q1
             J
             M2
             Q
             E
             U1
             P
             G2
             C2
             O
             K1
             B
             O1
             D
             A1
             V1
             L2
             Y
             F1
             L
             J1
             C1
             K
             K2
             M1
             S1
             H1
             C
             V
             Z
             N1
             W1
             A
             G1
             E1
             B2
             T1
             D1
             A2
             N
             F2
             I2
             D2
             X1
             B1
             H2
             U)
        (and (not (= L2 (- 2)))
     (not (= L2 (- 4)))
     (not (= U1 0))
     (= O1 0)
     (= I1 1)
     (= X 0)
     (= T 8544)
     (= R 512)
     (= L (- 30))
     (not (= L (- 1)))
     (not (>= E1 65))
     (<= 0 I2)
     (<= 0 D2)
     (<= 0 X1)
     (<= 0 J1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 U)
     (<= 0 L)
     (= (+ I (* (- 8) E1)) 0)
     (= v_67 L2)
     (= v_68 L2))
      )
      (inv_main199 J2
             Z1
             G
             R1
             M
             T
             Y1
             W
             O2
             F
             X
             P1
             N2
             E2
             L1
             Q1
             J
             M2
             Q
             E
             U1
             P
             G2
             C2
             O
             K1
             B
             O1
             D
             A1
             V1
             L2
             Y
             F1
             L
             J1
             C1
             K
             K2
             M1
             S1
             H1
             I1
             V
             Z
             N1
             W1
             A
             G1
             E1
             R
             T1
             D1
             A2
             N
             F2
             I2
             D2
             v_67
             v_68
             I
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main300 C2
             J2
             X
             V
             R1
             P1
             G
             U
             K1
             C
             Y
             L2
             Z1
             G2
             E
             Y1
             J1
             U1
             X1
             I
             Q
             M
             B2
             B
             Q1
             T1
             N2
             O2
             M1
             A2
             Z
             D1
             E1
             T
             E2
             N1
             A
             F2
             I2
             I1
             K
             L1
             V1
             C1
             O
             H2
             H1
             W1
             N
             P
             H
             A1
             O1
             F1
             D2
             J
             S
             F
             D
             S1
             B1
             R)
        (and (= M2 8544)
     (= K2 1024)
     (= E2 (- 30))
     (not (= E2 (- 1)))
     (= G1 0)
     (not (= D1 (- 2)))
     (= D1 (- 4))
     (not (= Q 0))
     (= L 1)
     (= O2 0)
     (not (>= P 129))
     (<= 0 A)
     (<= 0 D)
     (<= 0 E2)
     (<= 0 S1)
     (<= 0 N1)
     (<= 0 S)
     (<= 0 R)
     (<= 0 F)
     (= (+ W (* (- 8) P)) 0)
     (= v_67 D1)
     (= v_68 D1))
      )
      (inv_main199 C2
             J2
             X
             V
             R1
             M2
             G
             U
             K1
             C
             G1
             L2
             Z1
             G2
             E
             Y1
             J1
             U1
             X1
             I
             Q
             M
             B2
             B
             Q1
             T1
             N2
             O2
             M1
             A2
             Z
             D1
             E1
             T
             E2
             N1
             A
             F2
             I2
             I1
             K
             L1
             L
             C1
             O
             H2
             H1
             W1
             N
             P
             K2
             A1
             O1
             F1
             D2
             J
             S
             F
             v_67
             v_68
             W
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main330 M2
             U1
             B1
             Y
             I2
             L2
             Y1
             W
             A1
             V1
             K2
             H2
             G2
             H1
             J1
             M1
             K1
             F1
             H
             A
             Z1
             E
             K
             R1
             X1
             T1
             D2
             G1
             C1
             G
             C2
             L
             E1
             P
             B2
             V
             Z
             D1
             F2
             Q
             J
             S1
             W1
             N
             S
             J2
             O
             M
             X
             O1
             P1
             N1
             R
             Q1
             D
             T
             F
             U
             E2
             A2
             I1
             I)
        (and (= B 0)
     (= L1 8560)
     (not (= H (- 4)))
     (not (= H (- 1)))
     (= C 1)
     (<= 0 E2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 Z)
     (<= 0 V)
     (<= 0 U)
     (<= 0 I)
     (<= 0 F)
     (not (= A 0)))
      )
      (inv_main199 M2
             U1
             B1
             Y
             I2
             L1
             Y1
             W
             A1
             V1
             K2
             H2
             G2
             H1
             J1
             M1
             K1
             F1
             H
             A
             Z1
             E
             K
             R1
             X1
             B
             D2
             G1
             C1
             G
             C2
             L
             E1
             P
             B2
             V
             Z
             D1
             F2
             Q
             J
             S1
             C
             N
             S
             J2
             O
             M
             X
             O1
             P1
             N1
             R
             Q1
             D
             T
             F
             U
             E2
             A2
             I1
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main336 N
             A
             V1
             H1
             Q1
             I1
             K2
             B2
             T
             A1
             U
             F1
             G1
             Y
             M2
             A2
             H
             W
             X1
             J1
             C2
             I2
             Y1
             M1
             E
             X
             V
             N1
             U1
             E1
             E2
             S
             T1
             F2
             B
             D1
             G
             F
             C1
             J
             Z
             B1
             H2
             D2
             K
             P1
             L2
             G2
             L
             I
             R
             K1
             P
             C
             S1
             J2
             M
             L1
             O1
             Q
             W1
             Z1)
        (and (= R1 1)
     (not (= E1 (- 256)))
     (= O 8560)
     (= D 0)
     (<= 0 B)
     (<= 0 Z1)
     (<= 0 O1)
     (<= 0 L1)
     (<= 0 D1)
     (<= 0 Q)
     (<= 0 M)
     (<= 0 G)
     (= X1 (- 2))
     (= v_65 E1))
      )
      (inv_main199 N
             A
             V1
             H1
             Q1
             O
             K2
             B2
             T
             A1
             U
             F1
             G1
             Y
             M2
             A2
             H
             W
             X1
             J1
             C2
             I2
             Y1
             M1
             E
             D
             V
             N1
             U1
             E1
             E2
             S
             T1
             F2
             B
             D1
             G
             F
             C1
             J
             Z
             B1
             R1
             D2
             K
             P1
             L2
             G2
             L
             I
             R
             K1
             P
             C
             S1
             J2
             M
             L1
             O1
             Q
             W1
             v_65)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main330 G1
             P
             H1
             Y
             L2
             E2
             A1
             K1
             T
             K2
             Z
             Q1
             N1
             J
             O
             D1
             D2
             U1
             C1
             C
             N
             R1
             B
             I2
             S
             L1
             F2
             C2
             T1
             R
             J1
             H2
             X1
             B2
             L
             E1
             F1
             D
             B1
             Y1
             K
             Q
             M1
             Z1
             V1
             W1
             O1
             S1
             M2
             I
             V
             F
             M
             X
             H
             P1
             U
             G
             A2
             E
             A
             J2)
        (and (= I1 1)
     (= C1 (- 1))
     (= W 8560)
     (<= 0 J2)
     (<= 0 A2)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 U)
     (<= 0 L)
     (<= 0 G)
     (<= 0 E)
     (= G2 0))
      )
      (inv_main199 G1
             P
             H1
             Y
             L2
             W
             A1
             K1
             T
             K2
             Z
             Q1
             N1
             J
             O
             D1
             D2
             U1
             C1
             C
             N
             R1
             B
             I2
             S
             G2
             F2
             C2
             T1
             R
             J1
             H2
             X1
             B2
             L
             E1
             F1
             D
             B1
             Y1
             K
             Q
             I1
             Z1
             V1
             W1
             O1
             S1
             M2
             I
             V
             F
             M
             X
             H
             P1
             U
             G
             A2
             E
             A
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main336 X
             K1
             S1
             O2
             I1
             W
             U
             L
             I2
             Y
             M
             D
             T
             Z1
             F2
             N
             Z
             B
             R1
             R
             B1
             J1
             F
             V1
             E2
             X1
             J2
             H
             K
             P1
             C
             Q
             N2
             U1
             B2
             S
             M2
             O
             L1
             J
             C1
             D1
             H2
             A1
             P
             F1
             M1
             E
             T1
             I
             G1
             Q1
             D2
             G
             C2
             W1
             Y1
             V
             A2
             A
             L2
             O1)
        (and (= G2 0)
     (= P1 (- 256))
     (= N1 8448)
     (= H1 1)
     (<= 0 A)
     (<= 0 M2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 Y1)
     (<= 0 O1)
     (<= 0 V)
     (<= 0 S)
     (not (<= E1 0))
     (= K2 8576)
     (= v_67 P1))
      )
      (inv_main199 X
             K1
             S1
             O2
             I1
             N1
             U
             L
             I2
             Y
             G2
             D
             T
             Z1
             F2
             N
             Z
             B
             R1
             R
             B1
             J1
             F
             V1
             E2
             H1
             J2
             H
             K
             P1
             K2
             Q
             N2
             U1
             B2
             S
             M2
             O
             L1
             E1
             C1
             D1
             H2
             A1
             P
             F1
             M1
             E
             T1
             I
             G1
             Q1
             D2
             G
             C2
             W1
             Y1
             V
             A2
             A
             L2
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main336 L2
             B2
             J1
             O
             V1
             F1
             L1
             U
             D2
             C2
             Y
             E2
             H2
             E
             A2
             X1
             O2
             O1
             H1
             N2
             G1
             K2
             B
             L
             U1
             X
             J
             I1
             J2
             T
             Z1
             B1
             A1
             F
             M2
             Q1
             M
             D1
             S
             Q
             H
             T1
             K1
             D
             W1
             S1
             V
             N
             G2
             P
             N1
             W
             G
             R1
             I
             Y1
             C
             R
             F2
             M1
             I2
             P1)
        (and (= E1 8576)
     (= C1 0)
     (= Z 8448)
     (not (= T (- 256)))
     (= K 1)
     (<= 0 C)
     (<= 0 M2)
     (<= 0 F2)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 M1)
     (<= 0 R)
     (<= 0 M)
     (not (<= A 0))
     (not (= H1 (- 2)))
     (= v_67 T))
      )
      (inv_main199 L2
             B2
             J1
             O
             V1
             Z
             L1
             U
             D2
             C2
             C1
             E2
             H2
             E
             A2
             X1
             O2
             O1
             H1
             N2
             G1
             K2
             B
             L
             U1
             K
             J
             I1
             J2
             T
             E1
             B1
             A1
             F
             M2
             Q1
             M
             D1
             S
             A
             H
             T1
             K1
             D
             W1
             S1
             V
             N
             G2
             P
             N1
             W
             G
             R1
             I
             Y1
             C
             R
             F2
             M1
             I2
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 G1
             X1
             B1
             O
             N1
             K1
             H2
             J
             M2
             E
             I
             T
             K2
             R
             J2
             S
             F2
             W1
             V
             A2
             Q1
             A
             Z
             P
             I1
             S1
             M
             L
             H1
             J1
             C
             B2
             U
             H
             Z1
             D
             E1
             C2
             F
             D1
             F1
             L2
             Y
             E2
             P1
             O1
             G2
             L1
             R1
             W
             B
             V1
             I2
             X
             A1
             K
             Y1
             C1
             N
             U1
             M1
             D2)
        (and (= K1 8512)
     (not (= K1 8497))
     (not (= K1 12292))
     (not (= K1 8192))
     (not (= K1 24576))
     (not (= K1 8195))
     (not (= K1 8480))
     (not (= K1 8481))
     (not (= K1 8482))
     (not (= K1 8465))
     (not (= K1 8466))
     (not (= K1 8496))
     (not (= K1 8464))
     (not (= K1 16384))
     (not (= J1 (- 256)))
     (= Q 0)
     (= G 1)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 Y1)
     (<= 0 U1)
     (<= 0 E1)
     (<= 0 C1)
     (<= 0 N)
     (<= 0 D)
     (= T1 8528)
     (= v_65 J1))
      )
      (inv_main199 G1
             X1
             B1
             O
             N1
             T1
             H2
             J
             M2
             E
             Q
             T
             K2
             R
             J2
             S
             F2
             W1
             V
             A2
             Q1
             A
             Z
             P
             I1
             S1
             M
             L
             H1
             J1
             C
             B2
             U
             H
             Z1
             D
             E1
             C2
             F
             D1
             F1
             K1
             G
             E2
             P1
             O1
             G2
             L1
             R1
             W
             B
             V1
             I2
             X
             A1
             K
             v_65
             C1
             N
             U1
             M1
             D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 N1
             H1
             Z1
             N
             B1
             O1
             C2
             J2
             A1
             R
             V1
             W1
             Y1
             P1
             Q
             I1
             M2
             G
             V
             G1
             F
             A
             T
             W
             D1
             M
             I2
             B
             C
             L2
             S1
             L1
             T1
             M1
             R1
             K2
             J1
             F1
             G2
             H
             A2
             Y
             X1
             K1
             I
             D
             O
             Q1
             D2
             S
             K
             Z
             U1
             X
             E
             E1
             E2
             L
             U
             H2
             B2
             C1)
        (and (not (= O1 8497))
     (not (= O1 12292))
     (not (= O1 8192))
     (not (= O1 24576))
     (not (= O1 8195))
     (not (= O1 8480))
     (not (= O1 8481))
     (not (= O1 8482))
     (not (= O1 8465))
     (not (= O1 8466))
     (not (= O1 8496))
     (not (= O1 8464))
     (not (= O1 16384))
     (= P 0)
     (= J 8528)
     (= L2 (- 256))
     (<= 0 K2)
     (<= 0 H2)
     (<= 0 E2)
     (<= 0 R1)
     (<= 0 J1)
     (<= 0 C1)
     (<= 0 U)
     (<= 0 L)
     (not (<= F2 0))
     (= O1 8512)
     (= v_65 L2))
      )
      (inv_main199 N1
             H1
             Z1
             N
             B1
             J
             C2
             J2
             A1
             R
             P
             W1
             Y1
             P1
             Q
             I1
             M2
             G
             V
             G1
             F
             A
             T
             W
             D1
             M
             I2
             B
             C
             L2
             S1
             L1
             T1
             M1
             R1
             K2
             J1
             F1
             G2
             F2
             A2
             O1
             X1
             K1
             I
             D
             O
             Q1
             D2
             S
             K
             Z
             U1
             X
             E
             E1
             v_65
             L
             U
             H2
             B2
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 I1
             E1
             A
             M
             P
             Q
             I2
             F2
             H2
             D2
             F
             B1
             M1
             J
             Z1
             X
             A2
             A1
             C2
             D
             P1
             J2
             N1
             Y
             X1
             M2
             S
             S1
             Q1
             Z
             B
             C1
             G1
             L1
             Y1
             K1
             R1
             N
             U
             G
             T
             H1
             K2
             O1
             T1
             W
             E2
             L2
             O
             R
             H
             J1
             V
             E
             C
             W1
             L
             U1
             F1
             I
             G2
             V1)
        (and (= D1 0)
     (not (= Z (- 256)))
     (not (= Q 8512))
     (= Q 8513)
     (not (= Q 8497))
     (not (= Q 12292))
     (not (= Q 8192))
     (not (= Q 24576))
     (not (= Q 8195))
     (not (= Q 8480))
     (not (= Q 8481))
     (not (= Q 8482))
     (not (= Q 8465))
     (not (= Q 8466))
     (not (= Q 8496))
     (not (= Q 8464))
     (not (= Q 16384))
     (= K 1)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 U1)
     (<= 0 R1)
     (<= 0 K1)
     (<= 0 F1)
     (<= 0 L)
     (<= 0 I)
     (= B2 8528)
     (= v_65 Z))
      )
      (inv_main199 I1
             E1
             A
             M
             P
             B2
             I2
             F2
             H2
             D2
             D1
             B1
             M1
             J
             Z1
             X
             A2
             A1
             C2
             D
             P1
             J2
             N1
             Y
             X1
             M2
             S
             S1
             Q1
             Z
             B
             C1
             G1
             L1
             Y1
             K1
             R1
             N
             U
             G
             T
             Q
             K
             O1
             T1
             W
             E2
             L2
             O
             R
             H
             J1
             V
             E
             C
             W1
             v_65
             U1
             F1
             I
             G2
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 F1
             H1
             X
             G2
             U1
             M1
             B2
             D
             C
             W1
             L1
             R1
             E1
             Y1
             P
             Q
             C2
             A2
             L2
             H
             I
             M2
             Z
             F
             V
             S1
             B1
             Y
             N
             Z1
             F2
             C1
             O1
             B
             E2
             D1
             O
             I2
             T1
             K1
             J1
             U
             K2
             I1
             X1
             N1
             M
             J
             G
             W
             E
             V1
             L
             H2
             Q1
             T
             P1
             S
             D2
             R
             J2
             A)
        (and (not (= M1 8512))
     (= M1 8513)
     (not (= M1 8497))
     (not (= M1 12292))
     (not (= M1 8192))
     (not (= M1 24576))
     (not (= M1 8195))
     (not (= M1 8480))
     (not (= M1 8481))
     (not (= M1 8482))
     (not (= M1 8465))
     (not (= M1 8466))
     (not (= M1 8496))
     (not (= M1 8464))
     (not (= M1 16384))
     (= G1 0)
     (= K 8528)
     (<= 0 A)
     (<= 0 E2)
     (<= 0 D2)
     (<= 0 P1)
     (<= 0 D1)
     (<= 0 S)
     (<= 0 R)
     (<= 0 O)
     (not (<= A1 0))
     (= Z1 (- 256))
     (= v_65 Z1))
      )
      (inv_main199 F1
             H1
             X
             G2
             U1
             K
             B2
             D
             C
             W1
             G1
             R1
             E1
             Y1
             P
             Q
             C2
             A2
             L2
             H
             I
             M2
             Z
             F
             V
             S1
             B1
             Y
             N
             Z1
             F2
             C1
             O1
             B
             E2
             D1
             O
             I2
             T1
             A1
             J1
             M1
             K2
             I1
             X1
             N1
             M
             J
             G
             W
             E
             V1
             L
             H2
             Q1
             T
             v_65
             S
             D2
             R
             J2
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main118 F1
             D2
             M
             V
             T1
             D1
             K1
             Z1
             J1
             R
             E2
             W1
             P
             G
             H2
             I2
             F
             U
             L2
             A
             B
             P1
             C2
             N1
             Q
             T
             I
             E1
             K2
             Y
             G1
             C
             B2
             C1
             M1
             L
             H1
             E
             N
             V1
             O1
             X1
             J2
             X
             K
             A1
             Z
             W
             L1
             J
             Q1
             U1
             B1
             D
             F2
             Y1
             S1
             R1
             I1
             G2
             A2
             S)
        (and (not (= D1 8513))
     (not (= D1 8528))
     (not (= D1 8529))
     (not (= D1 8544))
     (not (= D1 8545))
     (not (= D1 8560))
     (not (= D1 8561))
     (not (= D1 8448))
     (= D1 8576)
     (not (= D1 8497))
     (not (= D1 12292))
     (not (= D1 8192))
     (not (= D1 24576))
     (not (= D1 8195))
     (not (= D1 8480))
     (not (= D1 8481))
     (not (= D1 8482))
     (not (= D1 8465))
     (not (= D1 8466))
     (not (= D1 8496))
     (not (= D1 8464))
     (not (= D1 16384))
     (= O 8466)
     (= H 2)
     (<= 0 G2)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 S)
     (<= 0 L)
     (not (<= H 0))
     (not (= D1 8512)))
      )
      (inv_main199 F1
             D2
             M
             V
             T1
             O
             K1
             Z1
             J1
             R
             E2
             W1
             P
             G
             H2
             I2
             F
             U
             L2
             A
             B
             P1
             C2
             N1
             Q
             T
             I
             E1
             K2
             Y
             G1
             C
             B2
             C1
             M1
             L
             H1
             E
             N
             H
             O1
             D1
             J2
             X
             K
             A1
             Z
             W
             L1
             J
             Q1
             U1
             B1
             D
             F2
             Y1
             S1
             R1
             I1
             G2
             A2
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main118 K1
             W1
             D2
             K
             D1
             U
             E1
             V
             H2
             N1
             S
             E2
             B
             E
             R1
             A2
             G
             P1
             O1
             M
             T1
             Y
             M1
             F1
             A1
             B1
             U1
             H1
             K2
             P
             C1
             I2
             X
             D
             L2
             F2
             S1
             I1
             J
             O
             J2
             H
             X1
             C2
             N2
             L
             T
             J1
             L1
             W
             Z1
             R
             V1
             G2
             Y1
             I
             G1
             A
             B2
             Q1
             F
             Z)
        (and (not (= U 8512))
     (not (= U 8513))
     (not (= U 8528))
     (not (= U 8529))
     (not (= U 8544))
     (not (= U 8545))
     (not (= U 8560))
     (not (= U 8561))
     (not (= U 8448))
     (= U 8576)
     (not (= U 8497))
     (not (= U 12292))
     (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (not (= U 8465))
     (not (= U 8466))
     (not (= U 8496))
     (not (= U 8464))
     (not (= U 16384))
     (= Q 8592)
     (not (= N 2))
     (<= 0 A)
     (<= 0 L2)
     (<= 0 F2)
     (<= 0 B2)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 G1)
     (<= 0 Z)
     (not (<= N 0))
     (not (<= M2 0))
     (= C 0))
      )
      (inv_main199 K1
             W1
             D2
             K
             D1
             Q
             E1
             V
             H2
             N1
             C
             E2
             B
             E
             R1
             A2
             G
             P1
             O1
             M
             T1
             Y
             M1
             F1
             A1
             B1
             U1
             H1
             K2
             P
             C1
             I2
             X
             D
             L2
             F2
             S1
             I1
             J
             M2
             J2
             U
             X1
             C2
             N2
             L
             T
             J1
             L1
             W
             Z1
             R
             V1
             G2
             Y1
             I
             G1
             A
             B2
             Q1
             F
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main118 H1
             Z1
             J
             L2
             X
             U
             Y1
             D2
             J2
             A1
             I
             W1
             C
             O1
             T
             B1
             M
             E
             T1
             N
             G1
             C2
             S1
             U1
             R1
             B2
             F2
             J1
             I2
             V1
             F
             A
             C1
             N1
             W
             A2
             Z
             E2
             V
             P
             R
             Q
             H2
             L
             Y
             K1
             K
             F1
             X1
             L1
             B
             D
             Q1
             O
             G2
             H
             K2
             G
             E1
             P1
             M1
             D1)
        (and (not (= U 8512))
     (not (= U 8513))
     (not (= U 8528))
     (not (= U 8529))
     (not (= U 8544))
     (not (= U 8545))
     (not (= U 8560))
     (not (= U 8561))
     (not (= U 8448))
     (not (= U 8576))
     (= U 8577)
     (not (= U 8497))
     (not (= U 12292))
     (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (not (= U 8465))
     (not (= U 8466))
     (not (= U 8496))
     (not (= U 8464))
     (not (= U 16384))
     (= S 8466)
     (<= 0 A2)
     (<= 0 P1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 Z)
     (<= 0 W)
     (<= 0 G)
     (<= 0 K2)
     (not (<= I1 0))
     (= I1 2))
      )
      (inv_main199 H1
             Z1
             J
             L2
             X
             S
             Y1
             D2
             J2
             A1
             I
             W1
             C
             O1
             T
             B1
             M
             E
             T1
             N
             G1
             C2
             S1
             U1
             R1
             B2
             F2
             J1
             I2
             V1
             F
             A
             C1
             N1
             W
             A2
             Z
             E2
             V
             I1
             R
             U
             H2
             L
             Y
             K1
             K
             F1
             X1
             L1
             B
             D
             Q1
             O
             G2
             H
             K2
             G
             E1
             P1
             M1
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main118 B
             K1
             V
             Q
             I2
             R
             X
             A2
             S1
             H1
             E2
             O
             W1
             A1
             N2
             N1
             O1
             C
             V1
             Z
             T
             T1
             M
             E1
             E
             P
             H2
             J1
             N
             A
             C1
             I1
             I
             M1
             F2
             Z1
             D2
             L1
             F
             U
             C2
             Y
             X1
             U1
             L
             G
             H
             G2
             M2
             Q1
             S
             P1
             B2
             K
             J2
             L2
             J
             B1
             G1
             K2
             R1
             W)
        (and (= F1 8592)
     (= D1 0)
     (not (= R 8512))
     (not (= R 8513))
     (not (= R 8528))
     (not (= R 8529))
     (not (= R 8544))
     (not (= R 8545))
     (not (= R 8560))
     (not (= R 8561))
     (not (= R 8448))
     (not (= R 8576))
     (= R 8577)
     (not (= R 8497))
     (not (= R 12292))
     (not (= R 8192))
     (not (= R 24576))
     (not (= R 8195))
     (not (= R 8480))
     (not (= R 8481))
     (not (= R 8482))
     (not (= R 8465))
     (not (= R 8466))
     (not (= R 8496))
     (not (= R 8464))
     (not (= R 16384))
     (<= 0 K2)
     (<= 0 F2)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 G1)
     (<= 0 B1)
     (<= 0 W)
     (<= 0 J)
     (not (<= Y1 0))
     (not (<= D 0))
     (not (= Y1 2)))
      )
      (inv_main199 B
             K1
             V
             Q
             I2
             F1
             X
             A2
             S1
             H1
             D1
             O
             W1
             A1
             N2
             N1
             O1
             C
             V1
             Z
             T
             T1
             M
             E1
             E
             P
             H2
             J1
             N
             A
             C1
             I1
             I
             M1
             F2
             Z1
             D2
             L1
             F
             D
             C2
             R
             X1
             U1
             L
             G
             H
             G2
             M2
             Q1
             S
             P1
             B2
             K
             J2
             L2
             J
             B1
             G1
             K2
             R1
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main118 Z
             O1
             K1
             C1
             I
             T1
             L
             D
             Z1
             C2
             D2
             L1
             Q
             P
             K2
             N1
             B1
             X
             I1
             A1
             J
             X1
             V
             O
             R
             V1
             U1
             J1
             E
             H
             A
             F2
             S1
             D1
             F
             E1
             Q1
             G
             Y
             U
             F1
             A2
             N
             H1
             G2
             C
             H2
             B2
             B
             Y1
             E2
             W1
             P1
             S
             I2
             L2
             R1
             K
             T
             M2
             J2
             G1)
        (and (not (= T1 8513))
     (not (= T1 8528))
     (not (= T1 8529))
     (not (= T1 8544))
     (not (= T1 8545))
     (not (= T1 8560))
     (not (= T1 8561))
     (not (= T1 8448))
     (not (= T1 8576))
     (not (= T1 8577))
     (not (= T1 8592))
     (not (= T1 8593))
     (not (= T1 8608))
     (not (= T1 8609))
     (= T1 8640)
     (not (= T1 8497))
     (not (= T1 12292))
     (not (= T1 8192))
     (not (= T1 24576))
     (not (= T1 8195))
     (not (= T1 8480))
     (not (= T1 8481))
     (not (= T1 8482))
     (not (= T1 8465))
     (not (= T1 8466))
     (not (= T1 8496))
     (not (= T1 8464))
     (not (= T1 16384))
     (= M1 3)
     (not (= L1 0))
     (= W 0)
     (<= 0 R1)
     (<= 0 Q1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 T)
     (<= 0 K)
     (<= 0 F)
     (<= 0 M2)
     (not (<= M 0))
     (not (= T1 8512)))
      )
      (inv_main199 Z
             O1
             K1
             C1
             I
             M1
             L
             D
             Z1
             C2
             W
             L1
             Q
             P
             K2
             N1
             B1
             X
             I1
             A1
             J
             X1
             V
             O
             R
             V1
             U1
             J1
             E
             H
             A
             F2
             S1
             D1
             F
             E1
             Q1
             G
             Y
             M
             F1
             T1
             N
             H1
             G2
             C
             H2
             B2
             B
             Y1
             E2
             W1
             P1
             S
             I2
             L2
             R1
             K
             T
             M2
             J2
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main118 L1
             I
             I2
             M2
             A2
             C1
             E2
             Y1
             S1
             P
             E
             L
             X1
             M
             W1
             I1
             B
             G2
             O
             M1
             J
             Q1
             Z
             A1
             D2
             J2
             O1
             D
             E1
             L2
             B1
             R1
             V1
             U1
             Z1
             D1
             Q
             H1
             F
             F2
             N1
             T1
             H
             Y
             F1
             K
             K1
             G1
             X
             S
             J1
             G
             H2
             N
             U
             B2
             C
             W
             T
             C2
             V
             A)
        (and (= P1 8656)
     (not (= C1 8512))
     (not (= C1 8513))
     (not (= C1 8528))
     (not (= C1 8529))
     (not (= C1 8544))
     (not (= C1 8545))
     (not (= C1 8560))
     (not (= C1 8561))
     (not (= C1 8448))
     (not (= C1 8576))
     (not (= C1 8577))
     (not (= C1 8592))
     (not (= C1 8593))
     (not (= C1 8608))
     (not (= C1 8609))
     (= C1 8640)
     (not (= C1 8497))
     (not (= C1 12292))
     (not (= C1 8192))
     (not (= C1 24576))
     (not (= C1 8195))
     (not (= C1 8480))
     (not (= C1 8481))
     (not (= C1 8482))
     (not (= C1 8465))
     (not (= C1 8466))
     (not (= C1 8496))
     (not (= C1 8464))
     (not (= C1 16384))
     (= L 0)
     (<= 0 A)
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 D1)
     (<= 0 W)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 C)
     (not (<= R 0))
     (= K2 0))
      )
      (inv_main199 L1
             I
             I2
             M2
             A2
             P1
             E2
             Y1
             S1
             P
             K2
             L
             X1
             M
             W1
             I1
             B
             G2
             O
             M1
             J
             Q1
             Z
             A1
             D2
             J2
             O1
             D
             E1
             L2
             B1
             R1
             V1
             U1
             Z1
             D1
             Q
             H1
             F
             R
             N1
             C1
             H
             Y
             F1
             K
             K1
             G1
             X
             S
             J1
             G
             H2
             N
             U
             B2
             C
             W
             T
             C2
             V
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main118 Y1
             A1
             M2
             A2
             M1
             I2
             P
             L1
             V
             C2
             K2
             U
             X
             U1
             K1
             T
             C
             G1
             E2
             J
             L2
             N1
             A
             D2
             L
             I
             E
             M
             T1
             H2
             G
             J2
             F1
             S1
             O
             Z1
             Y
             W1
             R1
             N
             K
             O1
             Z
             G2
             B
             J1
             H1
             C1
             B1
             H
             S
             R
             F2
             W
             X1
             D
             Q
             I1
             E1
             D1
             B2
             V1)
        (and (not (= I2 8513))
     (not (= I2 8528))
     (not (= I2 8529))
     (not (= I2 8544))
     (not (= I2 8545))
     (not (= I2 8560))
     (not (= I2 8561))
     (not (= I2 8448))
     (not (= I2 8576))
     (not (= I2 8577))
     (not (= I2 8592))
     (not (= I2 8593))
     (not (= I2 8608))
     (not (= I2 8609))
     (not (= I2 8640))
     (= I2 8641)
     (not (= I2 8497))
     (not (= I2 12292))
     (not (= I2 8192))
     (not (= I2 24576))
     (not (= I2 8195))
     (not (= I2 8480))
     (not (= I2 8481))
     (not (= I2 8482))
     (not (= I2 8465))
     (not (= I2 8466))
     (not (= I2 8496))
     (not (= I2 8464))
     (not (= I2 16384))
     (= Q1 0)
     (not (= U 0))
     (= F 3)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 Q)
     (<= 0 O)
     (not (<= P1 0))
     (not (= I2 8512)))
      )
      (inv_main199 Y1
             A1
             M2
             A2
             M1
             F
             P
             L1
             V
             C2
             Q1
             U
             X
             U1
             K1
             T
             C
             G1
             E2
             J
             L2
             N1
             A
             D2
             L
             I
             E
             M
             T1
             H2
             G
             J2
             F1
             S1
             O
             Z1
             Y
             W1
             R1
             P1
             K
             I2
             Z
             G2
             B
             J1
             H1
             C1
             B1
             H
             S
             R
             F2
             W
             X1
             D
             Q
             I1
             E1
             D1
             B2
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main118 M
             K
             W
             A
             S
             E2
             D2
             V1
             J1
             E1
             U
             H
             O
             I2
             B2
             N1
             I
             T
             Z
             C
             S1
             B
             N
             J2
             G2
             A2
             R1
             O1
             Z1
             D1
             P1
             B1
             T1
             A1
             F2
             Q
             C1
             R
             Y
             U1
             X1
             V
             Y1
             F
             K2
             L
             I1
             M2
             Q1
             E
             X
             W1
             G
             H1
             C2
             K1
             L1
             M1
             L2
             J
             G1
             H2)
        (and (not (= E2 8513))
     (not (= E2 8528))
     (not (= E2 8529))
     (not (= E2 8544))
     (not (= E2 8545))
     (not (= E2 8560))
     (not (= E2 8561))
     (not (= E2 8448))
     (not (= E2 8576))
     (not (= E2 8577))
     (not (= E2 8592))
     (not (= E2 8593))
     (not (= E2 8608))
     (not (= E2 8609))
     (not (= E2 8640))
     (= E2 8641)
     (not (= E2 8497))
     (not (= E2 12292))
     (not (= E2 8192))
     (not (= E2 24576))
     (not (= E2 8195))
     (not (= E2 8480))
     (not (= E2 8481))
     (not (= E2 8482))
     (not (= E2 8465))
     (not (= E2 8466))
     (not (= E2 8496))
     (not (= E2 8464))
     (not (= E2 16384))
     (= F1 0)
     (= H 0)
     (= D 8656)
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 M1)
     (<= 0 L1)
     (<= 0 C1)
     (<= 0 Q)
     (<= 0 J)
     (<= 0 L2)
     (not (<= P 0))
     (not (= E2 8512)))
      )
      (inv_main199 M
             K
             W
             A
             S
             D
             D2
             V1
             J1
             E1
             F1
             H
             O
             I2
             B2
             N1
             I
             T
             Z
             C
             S1
             B
             N
             J2
             G2
             A2
             R1
             O1
             Z1
             D1
             P1
             B1
             T1
             A1
             F2
             Q
             C1
             R
             Y
             P
             X1
             E2
             Y1
             F
             K2
             L
             I1
             M2
             Q1
             E
             X
             W1
             G
             H1
             C2
             K1
             L1
             M1
             L2
             J
             G1
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main118 M
             D2
             A
             B1
             X
             R1
             Q1
             L2
             I1
             T1
             J
             U1
             D1
             K1
             D
             N1
             K
             J1
             V1
             B2
             Z1
             H
             H2
             K2
             S1
             Q
             E
             U
             W
             W1
             C
             P
             F1
             M1
             R
             G1
             O
             C1
             B
             Z
             O1
             X1
             I
             N
             T
             S
             E1
             G
             C2
             A2
             F2
             J2
             F
             H1
             L1
             I2
             Y1
             A1
             G2
             N2
             M2
             L)
        (and (not (= R1 8512))
     (not (= R1 8513))
     (not (= R1 8528))
     (not (= R1 8529))
     (not (= R1 8544))
     (not (= R1 8545))
     (not (= R1 8560))
     (not (= R1 8561))
     (not (= R1 8448))
     (not (= R1 8576))
     (not (= R1 8577))
     (not (= R1 8592))
     (not (= R1 8593))
     (not (= R1 8608))
     (not (= R1 8609))
     (not (= R1 8640))
     (not (= R1 8641))
     (= R1 8656)
     (not (= R1 8497))
     (not (= R1 12292))
     (not (= R1 8192))
     (not (= R1 24576))
     (not (= R1 8195))
     (not (= R1 8480))
     (not (= R1 8481))
     (not (= R1 8482))
     (not (= R1 8465))
     (not (= R1 8466))
     (not (= R1 8496))
     (not (= R1 8464))
     (not (= R1 16384))
     (= P1 8672)
     (= L1 2)
     (not (= H1 0))
     (= Y 0)
     (not (= F 0))
     (<= 0 G2)
     (<= 0 Y1)
     (<= 0 G1)
     (<= 0 A1)
     (<= 0 R)
     (<= 0 O)
     (<= 0 L)
     (<= 0 N2)
     (not (<= V 0))
     (= E2 3)
     (= v_66 W))
      )
      (inv_main199 M
             D2
             A
             B1
             X
             P1
             Q1
             L2
             I1
             T1
             Y
             U1
             D1
             K1
             D
             N1
             K
             J1
             V1
             B2
             Z1
             H
             H2
             K2
             S1
             Q
             E
             U
             W
             W1
             C
             P
             v_66
             M1
             R
             G1
             O
             C1
             B
             V
             O1
             R1
             I
             N
             T
             S
             E1
             G
             C2
             A2
             F2
             J2
             F
             H1
             E2
             I2
             Y1
             A1
             G2
             N2
             M2
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 L1
             J1
             B1
             C2
             S1
             S
             K
             N
             M2
             I
             H1
             D2
             I1
             Q1
             B2
             L
             H
             O
             U
             F1
             O1
             G
             H2
             C
             X
             M
             D1
             D
             X1
             Z
             K2
             Y
             G2
             J
             L2
             P
             A2
             J2
             R1
             Q
             V
             T1
             Z1
             R
             N1
             E1
             V1
             A1
             I2
             W
             E
             C1
             M1
             T
             A
             Y1
             K1
             G1
             F2
             W1
             F
             E2)
        (and (= B 0)
     (= U1 8672)
     (not (= M1 0))
     (not (= T 0))
     (not (= S 8512))
     (not (= S 8513))
     (not (= S 8528))
     (not (= S 8529))
     (not (= S 8544))
     (not (= S 8545))
     (not (= S 8560))
     (not (= S 8561))
     (not (= S 8448))
     (not (= S 8576))
     (not (= S 8577))
     (not (= S 8592))
     (not (= S 8593))
     (not (= S 8608))
     (not (= S 8609))
     (not (= S 8640))
     (not (= S 8641))
     (= S 8656)
     (not (= S 8497))
     (not (= S 12292))
     (not (= S 8192))
     (not (= S 24576))
     (not (= S 8195))
     (not (= S 8480))
     (not (= S 8481))
     (not (= S 8482))
     (not (= S 8465))
     (not (= S 8466))
     (not (= S 8496))
     (not (= S 8464))
     (not (= S 16384))
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 A2)
     (<= 0 W1)
     (<= 0 K1)
     (<= 0 G1)
     (<= 0 P)
     (<= 0 L2)
     (not (<= P1 0))
     (not (= A 2))
     (= v_65 X1))
      )
      (inv_main199 L1
             J1
             B1
             C2
             S1
             U1
             K
             N
             M2
             I
             B
             D2
             I1
             Q1
             B2
             L
             H
             O
             U
             F1
             O1
             G
             H2
             C
             X
             M
             D1
             D
             X1
             Z
             K2
             Y
             v_65
             J
             L2
             P
             A2
             J2
             R1
             P1
             V
             S
             Z1
             R
             N1
             E1
             V1
             A1
             I2
             W
             E
             C1
             M1
             T
             A
             Y1
             K1
             G1
             F2
             W1
             F
             E2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main118 I1
             E
             M1
             J1
             L1
             C2
             P1
             G2
             V1
             N
             D
             U1
             G1
             A
             X
             B2
             H1
             K
             T1
             K1
             L
             W1
             A1
             C
             J
             N1
             K2
             F2
             B1
             E2
             R1
             X1
             M
             N2
             D1
             H
             C1
             I
             U
             A2
             G
             O1
             R
             H2
             Y
             V
             T
             Q
             D2
             S1
             M2
             Z1
             Z
             I2
             Q1
             P
             F1
             Y1
             J2
             E1
             B
             F)
        (and (not (= C2 8512))
     (not (= C2 8513))
     (not (= C2 8528))
     (not (= C2 8529))
     (not (= C2 8544))
     (not (= C2 8545))
     (not (= C2 8560))
     (not (= C2 8561))
     (not (= C2 8448))
     (not (= C2 8576))
     (not (= C2 8577))
     (not (= C2 8592))
     (not (= C2 8593))
     (not (= C2 8608))
     (not (= C2 8609))
     (not (= C2 8640))
     (not (= C2 8641))
     (not (= C2 8656))
     (= C2 8657)
     (not (= C2 8497))
     (not (= C2 12292))
     (not (= C2 8192))
     (not (= C2 24576))
     (not (= C2 8195))
     (not (= C2 8480))
     (not (= C2 8481))
     (not (= C2 8482))
     (not (= C2 8465))
     (not (= C2 8466))
     (not (= C2 8496))
     (not (= C2 8464))
     (not (= C2 16384))
     (= Q1 2)
     (not (= Z 0))
     (= W 8672)
     (= S 3)
     (= O 0)
     (<= 0 J2)
     (<= 0 Y1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 H)
     (<= 0 F)
     (not (<= L2 0))
     (not (= I2 0))
     (= v_66 B1))
      )
      (inv_main199 I1
             E
             M1
             J1
             L1
             W
             P1
             G2
             V1
             N
             O
             U1
             G1
             A
             X
             B2
             H1
             K
             T1
             K1
             L
             W1
             A1
             C
             J
             N1
             K2
             F2
             B1
             E2
             R1
             X1
             v_66
             N2
             D1
             H
             C1
             I
             U
             L2
             G
             C2
             R
             H2
             Y
             V
             T
             Q
             D2
             S1
             M2
             Z1
             Z
             I2
             S
             P
             F1
             Y1
             J2
             E1
             B
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 G
             I
             U1
             I2
             V1
             E2
             L2
             Y
             R
             C2
             J2
             D1
             C1
             S1
             O1
             K
             Z1
             N1
             K1
             W
             H2
             V
             E1
             T1
             F2
             A2
             F1
             O
             G1
             M1
             U
             X
             D2
             F
             P
             B2
             B
             A
             N
             P1
             X1
             I1
             B1
             K2
             G2
             Q1
             Q
             A1
             H1
             T
             J
             J1
             C
             D
             L
             S
             E
             M
             R1
             L1
             W1
             H)
        (and (not (= E2 8513))
     (not (= E2 8528))
     (not (= E2 8529))
     (not (= E2 8544))
     (not (= E2 8545))
     (not (= E2 8560))
     (not (= E2 8561))
     (not (= E2 8448))
     (not (= E2 8576))
     (not (= E2 8577))
     (not (= E2 8592))
     (not (= E2 8593))
     (not (= E2 8608))
     (not (= E2 8609))
     (not (= E2 8640))
     (not (= E2 8641))
     (not (= E2 8656))
     (= E2 8657)
     (not (= E2 8497))
     (not (= E2 12292))
     (not (= E2 8192))
     (not (= E2 24576))
     (not (= E2 8195))
     (not (= E2 8480))
     (not (= E2 8481))
     (not (= E2 8482))
     (not (= E2 8465))
     (not (= E2 8466))
     (not (= E2 8496))
     (not (= E2 8464))
     (not (= E2 16384))
     (= Z 8672)
     (not (= L 2))
     (not (= D 0))
     (not (= C 0))
     (= M2 0)
     (<= 0 B)
     (<= 0 B2)
     (<= 0 R1)
     (<= 0 L1)
     (<= 0 P)
     (<= 0 M)
     (<= 0 H)
     (<= 0 E)
     (not (<= Y1 0))
     (not (= E2 8512))
     (= v_65 G1))
      )
      (inv_main199 G
             I
             U1
             I2
             V1
             Z
             L2
             Y
             R
             C2
             M2
             D1
             C1
             S1
             O1
             K
             Z1
             N1
             K1
             W
             H2
             V
             E1
             T1
             F2
             A2
             F1
             O
             G1
             M1
             U
             X
             v_65
             F
             P
             B2
             B
             A
             N
             Y1
             X1
             E2
             B1
             K2
             G2
             Q1
             Q
             A1
             H1
             T
             J
             J1
             C
             D
             L
             S
             E
             M
             R1
             L1
             W1
             H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main300 X1
             E
             M2
             I1
             J1
             A
             G1
             L2
             N1
             W
             M1
             L
             S1
             R1
             T
             B2
             T1
             X
             Z
             F1
             F2
             O
             Q
             D
             J2
             H2
             E2
             B1
             J
             C2
             V
             G
             Y
             K2
             C
             W1
             D2
             K1
             Q1
             H1
             Z1
             U
             D1
             O1
             G2
             R
             C1
             Y1
             A2
             E1
             K
             I2
             L1
             B
             S
             H
             I
             F
             P1
             P
             A1
             N)
        (and (= U1 0)
     (not (= B1 0))
     (<= 0 D2)
     (<= 0 W1)
     (<= 0 P1)
     (<= 0 P)
     (<= 0 N)
     (<= 0 I)
     (<= 0 F)
     (<= 0 C)
     (not (<= M 0))
     (= V1 8544))
      )
      (inv_main199 X1
             E
             M2
             I1
             J1
             V1
             G1
             L2
             N1
             W
             U1
             L
             S1
             R1
             T
             B2
             T1
             X
             Z
             F1
             F2
             O
             Q
             D
             J2
             H2
             E2
             B1
             J
             C2
             V
             G
             Y
             K2
             C
             W1
             D2
             K1
             Q1
             M
             Z1
             U
             D1
             O1
             G2
             R
             C1
             Y1
             A2
             E1
             K
             I2
             L1
             B
             S
             H
             I
             F
             P1
             P
             A1
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main300 S
             T1
             P
             B
             K1
             X1
             C
             E2
             E
             Z
             H1
             B1
             F2
             Y1
             Q1
             J1
             R1
             F1
             A1
             L
             I
             D
             I1
             A2
             S1
             D1
             M2
             X
             Q
             Z1
             K
             N
             U
             C2
             J
             L1
             H
             D2
             K2
             Y
             T
             B2
             A
             W
             W1
             F
             G1
             M1
             J2
             O1
             E1
             V1
             O
             U1
             V
             C1
             G2
             L2
             P1
             N1
             G
             I2)
        (and (= R 0)
     (= M 8544)
     (not (= J (- 30)))
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 P1)
     (<= 0 N1)
     (<= 0 L1)
     (<= 0 J)
     (<= 0 H)
     (<= 0 L2)
     (not (<= H2 0))
     (= X 0))
      )
      (inv_main199 S
             T1
             P
             B
             K1
             M
             C
             E2
             E
             Z
             R
             B1
             F2
             Y1
             Q1
             J1
             R1
             F1
             A1
             L
             I
             D
             I1
             A2
             S1
             D1
             M2
             X
             Q
             Z1
             K
             N
             U
             C2
             J
             L1
             H
             D2
             K2
             H2
             T
             B2
             A
             W
             W1
             F
             G1
             M1
             J2
             O1
             E1
             V1
             O
             U1
             V
             C1
             G2
             L2
             P1
             N1
             G
             I2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main300 R1
             X
             J
             L
             W
             V
             G1
             Q1
             H2
             E1
             Z
             P1
             D1
             G2
             M
             A2
             L1
             J2
             D2
             F2
             M2
             G
             P
             W1
             Z1
             F1
             Y
             A1
             I1
             O
             S1
             L2
             K2
             C
             M1
             D
             E
             X1
             E2
             A
             T
             F
             N
             S
             H1
             U
             T1
             B2
             J1
             Y1
             I2
             I
             H
             C1
             U1
             R
             O1
             N1
             K
             K1
             Q
             C2)
        (and (= M1 (- 30))
     (not (= M1 (- 1)))
     (= B1 0)
     (= A1 0)
     (= M2 0)
     (<= 0 C2)
     (<= 0 O1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 K)
     (<= 0 E)
     (<= 0 D)
     (not (<= B 0))
     (= V1 8544))
      )
      (inv_main199 R1
             X
             J
             L
             W
             V1
             G1
             Q1
             H2
             E1
             B1
             P1
             D1
             G2
             M
             A2
             L1
             J2
             D2
             F2
             M2
             G
             P
             W1
             Z1
             F1
             Y
             A1
             I1
             O
             S1
             L2
             K2
             C
             M1
             D
             E
             X1
             E2
             B
             T
             F
             N
             S
             H1
             U
             T1
             B2
             J1
             Y1
             I2
             I
             H
             C1
             U1
             R
             O1
             N1
             K
             K1
             Q
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main300 P1
             X
             A2
             P
             M1
             Q1
             O1
             W
             U1
             F
             Y
             Y1
             X1
             K1
             I2
             K
             D2
             V1
             V
             H1
             Z
             F2
             Q
             Z1
             U
             L1
             E2
             N
             G
             I
             O2
             T
             A1
             H
             O
             M
             C
             G2
             S1
             B2
             A
             M2
             J2
             B1
             N1
             C2
             L2
             B
             J
             N2
             S
             R1
             R
             J1
             L
             E
             G1
             W1
             D1
             C1
             I1
             K2)
        (and (= T1 0)
     (= F1 8544)
     (= E1 512)
     (not (= Z 0))
     (not (= T (- 2)))
     (not (= T (- 4)))
     (= O (- 30))
     (not (= O (- 1)))
     (= N 0)
     (>= N2 65)
     (<= 0 C)
     (<= 0 K2)
     (<= 0 W1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 O)
     (<= 0 M)
     (not (<= D 0))
     (= (+ H2 (* (- 8) N2)) 0)
     (= v_67 T)
     (= v_68 T))
      )
      (inv_main199 P1
             X
             A2
             P
             M1
             F1
             O1
             W
             U1
             F
             T1
             Y1
             X1
             K1
             I2
             K
             D2
             V1
             V
             H1
             Z
             F2
             Q
             Z1
             U
             L1
             E2
             N
             G
             I
             O2
             T
             A1
             H
             O
             M
             C
             G2
             S1
             D
             A
             M2
             J2
             B1
             N1
             C2
             L2
             B
             J
             N2
             E1
             R1
             R
             J1
             L
             E
             G1
             W1
             v_67
             v_68
             H2
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main300 C2
             A1
             U1
             K1
             A
             G2
             B2
             F1
             N1
             J1
             A2
             Z
             O
             L2
             R
             E2
             D
             X1
             D1
             K2
             B
             M2
             Z1
             M
             T1
             L1
             U
             S1
             S
             E
             I2
             N2
             I1
             X
             H
             F
             H1
             I
             Y1
             D2
             V
             Y
             T
             F2
             R1
             C1
             B1
             O2
             J
             Q
             W1
             C
             W
             M1
             N
             P
             L
             G
             H2
             J2
             G1
             V1)
        (and (not (= B 0))
     (= S1 0)
     (= Q1 0)
     (= E1 8544)
     (= K 1024)
     (= H (- 30))
     (not (= H (- 1)))
     (not (= N2 (- 2)))
     (= N2 (- 4))
     (>= Q 129)
     (<= 0 J2)
     (<= 0 H2)
     (<= 0 V1)
     (<= 0 H1)
     (<= 0 L)
     (<= 0 H)
     (<= 0 G)
     (<= 0 F)
     (not (<= O1 0))
     (= (+ P1 (* (- 8) Q)) 0)
     (= v_67 N2)
     (= v_68 N2))
      )
      (inv_main199 C2
             A1
             U1
             K1
             A
             E1
             B2
             F1
             N1
             J1
             Q1
             Z
             O
             L2
             R
             E2
             D
             X1
             D1
             K2
             B
             M2
             Z1
             M
             T1
             L1
             U
             S1
             S
             E
             I2
             N2
             I1
             X
             H
             F
             H1
             I
             Y1
             O1
             V
             Y
             T
             F2
             R1
             C1
             B1
             O2
             J
             Q
             K
             C
             W
             M1
             N
             P
             L
             G
             v_67
             v_68
             P1
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 C
             Y1
             O
             L
             I2
             H2
             S
             A
             X1
             H1
             O1
             U
             U1
             Q
             C1
             E2
             K
             I
             L1
             E
             D
             W
             K1
             R
             X
             M
             Y
             V
             N1
             Q1
             T
             B1
             N
             J
             C2
             Z1
             T1
             M1
             H
             I1
             D2
             Z
             D1
             F1
             P
             J2
             P1
             E1
             B
             W1
             G1
             F
             B2
             A1
             A2
             R1
             G
             V1
             S1
             K2
             G2
             F2)
        (and (not (= H2 8513))
     (= H2 8528)
     (not (= H2 8497))
     (not (= H2 12292))
     (not (= H2 8192))
     (not (= H2 24576))
     (not (= H2 8195))
     (not (= H2 8480))
     (not (= H2 8481))
     (not (= H2 8482))
     (not (= H2 8465))
     (not (= H2 8466))
     (not (= H2 8496))
     (not (= H2 8464))
     (not (= H2 16384))
     (= J1 1)
     (not (= I (- 2097152)))
     (<= 0 F2)
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 S1)
     (<= 0 G)
     (<= 0 K2)
     (not (= H2 8512))
     (= v_63 Q1)
     (= v_64 H2)
     (= v_65 I))
      )
      (inv_main300 C
             Y1
             O
             L
             I2
             H2
             S
             A
             X1
             H1
             O1
             U
             U1
             Q
             C1
             E2
             K
             I
             L1
             E
             D
             W
             K1
             R
             X
             M
             Y
             J1
             N1
             Q1
             T
             B1
             N
             J
             v_63
             Z1
             T1
             M1
             H
             I1
             D2
             v_64
             D1
             F1
             P
             J2
             P1
             E1
             B
             W1
             G1
             F
             B2
             A1
             A2
             R1
             G
             v_65
             S1
             K2
             G2
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 S
             N
             J
             C1
             V
             K
             Q
             C2
             F1
             L1
             E2
             P
             G1
             J2
             H1
             W1
             M
             V1
             E1
             W
             G2
             D
             H
             L
             K1
             R
             I2
             X
             U1
             M1
             T
             C
             O
             P1
             F2
             A2
             Z
             T1
             B1
             K2
             B
             D1
             A1
             I
             H2
             X1
             N1
             A
             D2
             Y
             R1
             Z1
             E
             G
             F
             S1
             U
             B2
             J1
             O1
             I1
             Q1)
        (and (= V1 (- 2097152))
     (not (= K 8512))
     (not (= K 8513))
     (= K 8528)
     (not (= K 8497))
     (not (= K 12292))
     (not (= K 8192))
     (not (= K 24576))
     (not (= K 8195))
     (not (= K 8480))
     (not (= K 8481))
     (not (= K 8482))
     (not (= K 8465))
     (not (= K 8466))
     (not (= K 8496))
     (not (= K 8464))
     (not (= K 16384))
     (<= 0 F2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 Q1)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 Z)
     (<= 0 U)
     (= Y1 0)
     (= v_63 M1)
     (= v_64 K)
     (= v_65 V1))
      )
      (inv_main300 S
             N
             J
             C1
             V
             K
             Q
             C2
             F1
             L1
             E2
             P
             G1
             J2
             H1
             W1
             M
             V1
             E1
             W
             G2
             D
             H
             L
             K1
             R
             I2
             Y1
             U1
             M1
             T
             C
             O
             P1
             v_63
             A2
             Z
             T1
             B1
             K2
             B
             v_64
             A1
             I
             H2
             X1
             N1
             A
             D2
             Y
             R1
             Z1
             E
             G
             F
             S1
             U
             v_65
             J1
             O1
             I1
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 F
             F1
             T
             J1
             A2
             E1
             U
             R
             N
             V
             X1
             C2
             M1
             E
             W
             S1
             V1
             G2
             K2
             L
             G1
             F2
             Q
             E2
             O1
             I1
             N1
             Y
             P
             Z
             U1
             H
             J2
             I
             B2
             O
             J
             Z1
             Y1
             D
             I2
             A1
             A
             X
             B
             G
             D1
             H1
             P1
             L1
             C1
             Q1
             R1
             M
             K1
             K
             D2
             H2
             C
             T1
             B1
             W1)
        (and (not (= E1 8512))
     (not (= E1 8513))
     (not (= E1 8528))
     (= E1 8529)
     (not (= E1 8497))
     (not (= E1 12292))
     (not (= E1 8192))
     (not (= E1 24576))
     (not (= E1 8195))
     (not (= E1 8480))
     (not (= E1 8481))
     (not (= E1 8482))
     (not (= E1 8465))
     (not (= E1 8466))
     (not (= E1 8496))
     (not (= E1 8464))
     (not (= E1 16384))
     (= S 1)
     (<= 0 H2)
     (<= 0 D2)
     (<= 0 B2)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 O)
     (<= 0 J)
     (<= 0 C)
     (not (= G2 (- 2097152)))
     (= v_63 Z)
     (= v_64 E1)
     (= v_65 G2))
      )
      (inv_main300 F
             F1
             T
             J1
             A2
             E1
             U
             R
             N
             V
             X1
             C2
             M1
             E
             W
             S1
             V1
             G2
             K2
             L
             G1
             F2
             Q
             E2
             O1
             I1
             N1
             S
             P
             Z
             U1
             H
             J2
             I
             v_63
             O
             J
             Z1
             Y1
             D
             I2
             v_64
             A
             X
             B
             G
             D1
             H1
             P1
             L1
             C1
             Q1
             R1
             M
             K1
             K
             D2
             v_65
             C
             T1
             B1
             W1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main118 A
             G
             W1
             O1
             H
             I2
             C2
             N1
             Q
             R
             J2
             M
             O
             V
             V1
             Y1
             X1
             S1
             M1
             J
             D1
             T1
             F
             P
             I
             U1
             R1
             S
             K
             K2
             A1
             B
             A2
             Z1
             F1
             E1
             F2
             G1
             Y
             K1
             I1
             Z
             P1
             C1
             C
             B1
             U
             N
             L
             L1
             H2
             G2
             B2
             X
             D2
             J1
             E2
             E
             H1
             T
             W
             D)
        (and (not (= I2 8513))
     (not (= I2 8528))
     (= I2 8529)
     (not (= I2 8497))
     (not (= I2 12292))
     (not (= I2 8192))
     (not (= I2 24576))
     (not (= I2 8195))
     (not (= I2 8480))
     (not (= I2 8481))
     (not (= I2 8482))
     (not (= I2 8465))
     (not (= I2 8466))
     (not (= I2 8496))
     (not (= I2 8464))
     (not (= I2 16384))
     (= S1 (- 2097152))
     (= Q1 0)
     (<= 0 F2)
     (<= 0 E2)
     (<= 0 H1)
     (<= 0 F1)
     (<= 0 E1)
     (<= 0 T)
     (<= 0 E)
     (<= 0 D)
     (not (= I2 8512))
     (= v_63 K2)
     (= v_64 I2)
     (= v_65 S1))
      )
      (inv_main300 A
             G
             W1
             O1
             H
             I2
             C2
             N1
             Q
             R
             J2
             M
             O
             V
             V1
             Y1
             X1
             S1
             M1
             J
             D1
             T1
             F
             P
             I
             U1
             R1
             Q1
             K
             K2
             A1
             B
             A2
             Z1
             v_63
             E1
             F2
             G1
             Y
             K1
             I1
             v_64
             P1
             C1
             C
             B1
             U
             N
             L
             L1
             H2
             G2
             B2
             X
             D2
             J1
             E2
             v_65
             H1
             T
             W
             D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 C2
             Z1
             M
             U
             S
             A2
             Q1
             F2
             J2
             X1
             R
             C
             Y1
             B2
             F1
             K1
             N
             H
             V1
             L
             R1
             Z
             F
             E
             P1
             B1
             M1
             G
             G2
             I2
             S1
             T
             G1
             H1
             U1
             D
             A
             C1
             D1
             X
             O
             D2
             W
             Y
             E1
             L1
             K
             P
             A1
             Q
             N1
             B
             E2
             W1
             I1
             V
             J1
             T1
             O1
             I
             H2
             J)
        (and (not (= A2 8192))
     (not (= A2 24576))
     (not (= A2 8195))
     (not (= A2 8480))
     (not (= A2 8481))
     (not (= A2 8482))
     (not (= A2 8465))
     (= A2 8466)
     (not (= A2 8464))
     (not (= A2 16384))
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 O1)
     (<= 0 J1)
     (<= 0 J)
     (<= 0 I)
     (<= 0 D)
     (<= 0 A)
     (not (= A2 12292))
     (= v_62 A2))
      )
      (inv_main255 C2
             Z1
             M
             U
             S
             A2
             Q1
             F2
             J2
             X1
             R
             C
             Y1
             B2
             F1
             K1
             N
             H
             V1
             L
             R1
             Z
             F
             E
             P1
             B1
             M1
             G
             G2
             I2
             S1
             T
             G1
             H1
             U1
             D
             A
             C1
             D1
             X
             O
             v_62
             W
             Y
             E1
             L1
             K
             P
             A1
             Q
             N1
             B
             E2
             W1
             I1
             V
             J1
             T1
             O1
             I
             H2
             J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 G2
             U
             I
             B2
             F1
             F2
             A1
             S
             M1
             L1
             J2
             H2
             T1
             V
             D2
             X1
             Y
             O1
             P
             E2
             W
             N1
             R1
             W1
             E
             J1
             E1
             J
             M
             Z1
             I2
             A
             H1
             K1
             L
             D1
             A2
             C
             X
             B
             V1
             B1
             P1
             G1
             D
             H
             G
             S1
             K
             U1
             T
             I1
             C1
             Y1
             O
             Q
             F
             N
             R
             C2
             Z
             Q1)
        (and (not (= F2 8192))
     (not (= F2 24576))
     (not (= F2 8195))
     (not (= F2 8480))
     (not (= F2 8481))
     (not (= F2 8482))
     (= F2 8464)
     (not (= F2 16384))
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 Q1)
     (<= 0 D1)
     (<= 0 R)
     (<= 0 N)
     (<= 0 L)
     (<= 0 F)
     (not (= F2 12292))
     (= v_62 F2))
      )
      (inv_main255 G2
             U
             I
             B2
             F1
             F2
             A1
             S
             M1
             L1
             J2
             H2
             T1
             V
             D2
             X1
             Y
             O1
             P
             E2
             W
             N1
             R1
             W1
             E
             J1
             E1
             J
             M
             Z1
             I2
             A
             H1
             K1
             L
             D1
             A2
             C
             X
             B
             V1
             v_62
             P1
             G1
             D
             H
             G
             S1
             K
             U1
             T
             I1
             C1
             Y1
             O
             Q
             F
             N
             R
             C2
             Z
             Q1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main118 N
             U1
             H1
             X1
             K1
             U
             L
             O
             B2
             D
             N1
             E1
             M
             Z
             Y
             T
             F2
             J
             I2
             Z1
             D1
             P1
             X
             Q1
             C
             G2
             J2
             O1
             D2
             L1
             W1
             A2
             S1
             I1
             F
             G1
             Y1
             S
             R1
             F1
             W
             T1
             E2
             K
             M1
             J1
             H2
             I
             Q
             C2
             B1
             C1
             R
             H
             G
             P
             A1
             B
             V1
             E
             A
             V)
        (and (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (= U 8465)
     (not (= U 8464))
     (not (= U 16384))
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 G1)
     (<= 0 A1)
     (<= 0 V)
     (<= 0 F)
     (<= 0 E)
     (<= 0 B)
     (not (= U 12292))
     (= v_62 U))
      )
      (inv_main255 N
             U1
             H1
             X1
             K1
             U
             L
             O
             B2
             D
             N1
             E1
             M
             Z
             Y
             T
             F2
             J
             I2
             Z1
             D1
             P1
             X
             Q1
             C
             G2
             J2
             O1
             D2
             L1
             W1
             A2
             S1
             I1
             F
             G1
             Y1
             S
             R1
             F1
             W
             v_62
             E2
             K
             M1
             J1
             H2
             I
             Q
             C2
             B1
             C1
             R
             H
             G
             P
             A1
             B
             V1
             E
             A
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main495 B
             S
             Z
             H
             F2
             X
             M1
             S1
             W
             J2
             U
             U1
             H2
             G
             M
             C2
             G2
             E1
             I2
             P
             C
             R1
             T1
             H1
             D1
             K
             Y1
             L
             F
             Z1
             B2
             X1
             J1
             D
             F1
             O1
             T
             R
             I
             D2
             J
             G1
             W1
             O
             A1
             Q
             Q1
             N1
             V
             C1
             A
             E2
             P1
             L1
             E
             B1
             Y
             A2
             K1
             V1
             I1
             N)
        (and (<= 0 V1)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 F1)
     (<= 0 Y)
     (<= 0 T)
     (<= 0 N)
     (<= 0 A2))
      )
      false
    )
  )
)

(check-sat)
(exit)
