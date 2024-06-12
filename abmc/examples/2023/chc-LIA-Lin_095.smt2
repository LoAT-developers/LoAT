; ./prepared/tricera/sv-comp-2020/./mixed/s3_srvr_6.cil-1.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main393| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main439| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main258| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main523| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main325| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main275| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main4| ( Int Int ) Bool)
(declare-fun |inv_main485| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main107| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main343| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main458| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main540| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main202| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main121| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main337| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main488| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main436| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main286| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main304| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) ) 
    (=>
      (and
        true
      )
      (inv_main4 A B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 U
             W1
             F1
             K
             I2
             T1
             B
             D
             G1
             V1
             R1
             H2
             Q
             J
             A
             L1
             P
             M1
             M
             J1
             H1
             U1
             N
             I
             X
             F2
             P1
             W
             T
             G2
             S
             Q1
             D2
             E1
             V
             H
             C2
             O
             A2
             L
             J2
             X1
             R
             E2
             B1
             K1
             N1
             G
             A1
             Z
             O1
             C
             I1
             S1
             D1
             Z1
             Y
             E
             B2
             F
             Y1
             C1)
        (and (not (= T1 16384))
     (not (= T1 8192))
     (not (= T1 24576))
     (not (= T1 8195))
     (not (= T1 8480))
     (not (= T1 8481))
     (not (= T1 8482))
     (not (= T1 8464))
     (not (= T1 8465))
     (not (= T1 8466))
     (not (= T1 8496))
     (not (= T1 8497))
     (= T1 8512)
     (<= 0 C2)
     (<= 0 B2)
     (<= 0 C1)
     (<= 0 Y)
     (<= 0 V)
     (<= 0 H)
     (<= 0 F)
     (<= 0 E)
     (not (= T1 12292))
     (= v_62 T1))
      )
      (inv_main286 U
             W1
             F1
             K
             I2
             T1
             B
             D
             G1
             V1
             R1
             H2
             Q
             J
             A
             L1
             P
             M1
             M
             J1
             H1
             U1
             N
             I
             X
             F2
             P1
             W
             T
             G2
             S
             Q1
             D2
             E1
             V
             H
             C2
             O
             A2
             L
             J2
             v_62
             R
             E2
             B1
             K1
             N1
             G
             A1
             Z
             O1
             C
             I1
             S1
             D1
             Z1
             Y
             E
             B2
             F
             Y1
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 E1
             U1
             C
             Q1
             J1
             A
             B1
             W
             H
             G1
             B
             E
             J2
             F
             C1
             C2
             J
             W1
             K1
             D
             K
             N
             S
             U
             T
             Z
             L
             Q
             R
             I
             V
             M
             Y
             Y1
             D1
             V1
             X
             M1
             B2
             L1
             A2
             E2
             A1
             X1
             G2
             P
             O1
             H2
             H1
             I2
             N1
             S1
             P1
             I1
             T1
             R1
             F2
             G
             D2
             Z1
             O
             F1)
        (and (not (= A 12292))
     (not (= A 16384))
     (not (= A 8192))
     (not (= A 24576))
     (not (= A 8195))
     (not (= A 8480))
     (not (= A 8481))
     (not (= A 8482))
     (not (= A 8464))
     (not (= A 8465))
     (not (= A 8466))
     (not (= A 8496))
     (not (= A 8497))
     (not (= A 8512))
     (<= 0 F2)
     (<= 0 D2)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 F1)
     (<= 0 D1)
     (<= 0 X)
     (<= 0 G)
     (= A 8513)
     (= v_62 A))
      )
      (inv_main286 E1
             U1
             C
             Q1
             J1
             A
             B1
             W
             H
             G1
             B
             E
             J2
             F
             C1
             C2
             J
             W1
             K1
             D
             K
             N
             S
             U
             T
             Z
             L
             Q
             R
             I
             V
             M
             Y
             Y1
             D1
             V1
             X
             M1
             B2
             L1
             A2
             v_62
             A1
             X1
             G2
             P
             O1
             H2
             H1
             I2
             N1
             S1
             P1
             I1
             T1
             R1
             F2
             G
             D2
             Z1
             O
             F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 J1 O)
        (and (= E2 0)
     (= D2 0)
     (= P1 1)
     (= I1 0)
     (= A1 8464)
     (not (= G 0))
     (= E 8464)
     (= D 8464)
     (<= 0 G2)
     (<= 0 F2)
     (<= 0 W1)
     (<= 0 Q1)
     (<= 0 L1)
     (<= 0 B1)
     (<= 0 Z)
     (<= 0 B)
     (= H2 (- 1))
     (= v_63 I2)
     (= v_64 G))
      )
      (inv_main107 E
             O
             A1
             G
             C2
             D
             H
             U
             C1
             V1
             H1
             X
             N
             P1
             Y1
             F
             K1
             U1
             Z1
             A
             R1
             F1
             K2
             G1
             N1
             V
             R
             E1
             O1
             S1
             I
             T
             X1
             P
             G2
             I2
             v_63
             v_64
             S
             H2
             D1
             Y
             D2
             E2
             K
             M1
             J2
             L
             J
             C
             B2
             T1
             A2
             Q
             I1
             W
             Q1
             Z
             B
             L1
             M
             F2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 E Y1)
        (and (= G2 0)
     (= B2 8464)
     (= W1 0)
     (= T1 1)
     (= G1 0)
     (= D1 8464)
     (= U 0)
     (= P 0)
     (= L (- 1))
     (= H 8464)
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 X1)
     (<= 0 P1)
     (<= 0 H1)
     (<= 0 O)
     (<= 0 I)
     (<= 0 F)
     (= J2 0)
     (= v_64 D))
      )
      (inv_main107 D1
             Y1
             B2
             J2
             K2
             H
             W
             F2
             L2
             E1
             H2
             C
             C1
             T1
             M
             Y
             J1
             F1
             T
             S
             V1
             P
             L1
             K
             A1
             N
             R
             A
             S1
             B
             I1
             V
             E2
             Q1
             A2
             D
             v_64
             G1
             Z
             L
             N1
             X
             W1
             G2
             R1
             O1
             J
             G
             I2
             D2
             K1
             M1
             B1
             Z1
             U
             U1
             C2
             X1
             P1
             F
             Q
             O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 V1
             O1
             N1
             G2
             C1
             L1
             N
             S
             P1
             G
             B
             I
             Y1
             X1
             A
             M1
             V
             C
             J2
             J
             H
             G1
             A1
             K
             D1
             B1
             F
             Y
             F2
             K1
             J1
             H1
             E
             U
             R1
             A2
             B2
             U1
             P
             Q1
             F1
             H2
             E1
             X
             W
             E2
             W1
             I2
             O
             L
             M
             D
             S1
             Z1
             D2
             R
             Q
             T1
             I1
             Z
             C2
             T)
        (and (not (= L1 16384))
     (not (= L1 8192))
     (not (= L1 24576))
     (not (= L1 8195))
     (not (= L1 8480))
     (not (= L1 8481))
     (not (= L1 8482))
     (not (= L1 8464))
     (not (= L1 8465))
     (= L1 8466)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 I1)
     (<= 0 Z)
     (<= 0 T)
     (<= 0 Q)
     (not (= L1 12292))
     (= v_62 L1))
      )
      (inv_main258 V1
             O1
             N1
             G2
             C1
             L1
             N
             S
             P1
             G
             B
             I
             Y1
             X1
             A
             M1
             V
             C
             J2
             J
             H
             G1
             A1
             K
             D1
             B1
             F
             Y
             F2
             K1
             J1
             H1
             E
             U
             R1
             A2
             B2
             U1
             P
             Q1
             F1
             v_62
             E1
             X
             W
             E2
             W1
             I2
             O
             L
             M
             D
             S1
             Z1
             D2
             R
             Q
             T1
             I1
             Z
             C2
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 B2
             F2
             J1
             G2
             Y1
             A
             I
             D2
             T1
             T
             W1
             U
             A1
             P1
             R1
             Q1
             E2
             N1
             V1
             O
             H2
             X1
             Y
             G1
             F
             F1
             D1
             D
             L
             J2
             L1
             A2
             N
             H1
             V
             K1
             H
             Q
             I1
             P
             M
             E1
             C1
             C2
             X
             K
             G
             B1
             R
             W
             M1
             U1
             S1
             Z1
             C
             S
             J
             Z
             E
             O1
             I2
             B)
        (and (not (= A 16384))
     (not (= A 8192))
     (not (= A 24576))
     (not (= A 8195))
     (not (= A 8480))
     (not (= A 8481))
     (not (= A 8482))
     (= A 8464)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 Z)
     (<= 0 V)
     (<= 0 J)
     (<= 0 H)
     (<= 0 E)
     (<= 0 B)
     (not (= A 12292))
     (= v_62 A))
      )
      (inv_main258 B2
             F2
             J1
             G2
             Y1
             A
             I
             D2
             T1
             T
             W1
             U
             A1
             P1
             R1
             Q1
             E2
             N1
             V1
             O
             H2
             X1
             Y
             G1
             F
             F1
             D1
             D
             L
             J2
             L1
             A2
             N
             H1
             V
             K1
             H
             Q
             I1
             P
             M
             v_62
             C1
             C2
             X
             K
             G
             B1
             R
             W
             M1
             U1
             S1
             Z1
             C
             S
             J
             Z
             E
             O1
             I2
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 E
             C1
             U
             F
             I
             O
             B2
             F2
             V1
             N
             V
             H2
             Q
             R1
             K1
             A2
             Y1
             P1
             C
             J2
             M1
             P
             E1
             S
             X1
             T1
             A
             A1
             G
             J
             F1
             G2
             N1
             B
             Y
             R
             T
             L1
             W1
             Q1
             D
             W
             G1
             D2
             S1
             O1
             Z1
             L
             H1
             D1
             E2
             Z
             M
             K
             C2
             I2
             B1
             U1
             X
             I1
             H
             J1)
        (and (not (= O 16384))
     (not (= O 8192))
     (not (= O 24576))
     (not (= O 8195))
     (not (= O 8480))
     (not (= O 8481))
     (not (= O 8482))
     (not (= O 8464))
     (= O 8465)
     (<= 0 U1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 X)
     (<= 0 T)
     (<= 0 R)
     (not (= O 12292))
     (= v_62 O))
      )
      (inv_main258 E
             C1
             U
             F
             I
             O
             B2
             F2
             V1
             N
             V
             H2
             Q
             R1
             K1
             A2
             Y1
             P1
             C
             J2
             M1
             P
             E1
             S
             X1
             T1
             A
             A1
             G
             J
             F1
             G2
             N1
             B
             Y
             R
             T
             L1
             W1
             Q1
             D
             v_62
             G1
             D2
             S1
             O1
             Z1
             L
             H1
             D1
             E2
             Z
             M
             K
             C2
             I2
             B1
             U1
             X
             I1
             H
             J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 M1
             X
             O
             K
             J2
             T
             C1
             U1
             R
             Y1
             B2
             P
             Q
             Z
             I
             M
             N
             B1
             X1
             G2
             H2
             V1
             E2
             U
             F1
             I1
             V
             F
             D2
             H
             P1
             K1
             A2
             Y
             D
             Q1
             S
             C2
             N1
             I2
             Z1
             T1
             S1
             F2
             J
             E
             G1
             W1
             W
             D1
             A1
             L
             E1
             L1
             C
             R1
             J1
             H1
             B
             A
             O1
             G)
        (and (not (= T 8529))
     (not (= T 8544))
     (not (= T 8545))
     (not (= T 8560))
     (not (= T 8561))
     (not (= T 8448))
     (not (= T 8576))
     (not (= T 8577))
     (not (= T 8592))
     (not (= T 8593))
     (not (= T 8608))
     (not (= T 8609))
     (not (= T 8640))
     (not (= T 8641))
     (not (= T 8656))
     (not (= T 8657))
     (= T 8672)
     (not (= T 8513))
     (not (= T 12292))
     (not (= T 16384))
     (not (= T 8192))
     (not (= T 24576))
     (not (= T 8195))
     (not (= T 8480))
     (not (= T 8481))
     (not (= T 8482))
     (not (= T 8464))
     (not (= T 8465))
     (not (= T 8466))
     (not (= T 8496))
     (not (= T 8497))
     (not (= T 8512))
     (<= 0 Q1)
     (<= 0 J1)
     (<= 0 H1)
     (<= 0 S)
     (<= 0 G)
     (<= 0 D)
     (<= 0 B)
     (<= 0 A)
     (not (= T 8528))
     (= v_62 T))
      )
      (inv_main485 M1
             X
             O
             K
             J2
             T
             C1
             U1
             R
             Y1
             B2
             P
             Q
             Z
             I
             M
             N
             B1
             X1
             G2
             H2
             V1
             E2
             U
             F1
             I1
             V
             F
             D2
             H
             P1
             K1
             A2
             Y
             D
             Q1
             S
             C2
             N1
             I2
             Z1
             v_62
             S1
             F2
             J
             E
             G1
             W1
             W
             D1
             A1
             L
             E1
             L1
             C
             R1
             J1
             H1
             B
             A
             O1
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 F1
             I1
             E1
             C1
             G
             R1
             L1
             S
             S1
             H1
             P
             D
             J2
             P1
             A1
             X1
             K1
             M
             B
             H
             D2
             W1
             J1
             Z1
             E
             Y
             J
             V
             F
             O1
             B1
             T
             I
             A2
             M1
             E2
             N1
             V1
             T1
             L
             F2
             U
             H2
             Y1
             K
             X
             Z
             W
             C
             G2
             R
             U1
             Q
             A
             O
             C2
             I2
             B2
             G1
             N
             Q1
             D1)
        (and (not (= R1 8528))
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
     (not (= R1 8656))
     (not (= R1 8657))
     (not (= R1 8672))
     (not (= R1 8513))
     (not (= R1 12292))
     (not (= R1 16384))
     (not (= R1 8192))
     (not (= R1 24576))
     (not (= R1 8195))
     (not (= R1 8480))
     (not (= R1 8481))
     (not (= R1 8482))
     (not (= R1 8464))
     (not (= R1 8465))
     (not (= R1 8466))
     (not (= R1 8496))
     (not (= R1 8497))
     (not (= R1 8512))
     (<= 0 E2)
     (<= 0 B2)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 N)
     (<= 0 I2)
     (= R1 8673)
     (= v_62 R1))
      )
      (inv_main485 F1
             I1
             E1
             C1
             G
             R1
             L1
             S
             S1
             H1
             P
             D
             J2
             P1
             A1
             X1
             K1
             M
             B
             H
             D2
             W1
             J1
             Z1
             E
             Y
             J
             V
             F
             O1
             B1
             T
             I
             A2
             M1
             E2
             N1
             V1
             T1
             L
             F2
             v_62
             H2
             Y1
             K
             X
             Z
             W
             C
             G2
             R
             U1
             Q
             A
             O
             C2
             I2
             B2
             G1
             N
             Q1
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main337 P1
             V
             A
             K
             D1
             T
             C1
             Q1
             G1
             H1
             G
             U
             C2
             S
             M1
             V1
             X
             F2
             K1
             I2
             G2
             R
             J2
             E2
             J1
             C
             Z1
             N1
             Y
             B1
             H
             A2
             M
             D
             S1
             E
             L
             Y1
             Z
             O
             U1
             T1
             A1
             B
             P
             B2
             I1
             L1
             X1
             I
             R1
             D2
             Q
             F
             F1
             W
             J
             W1
             E1
             N
             H2
             O1)
        (and (= I2 0)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 E1)
     (<= 0 N)
     (<= 0 L)
     (<= 0 J)
     (<= 0 E)
     (not (= K1 (- 1))))
      )
      (inv_main343 P1
             V
             A
             K
             D1
             T
             C1
             Q1
             G1
             H1
             G
             U
             C2
             S
             M1
             V1
             X
             F2
             K1
             I2
             G2
             R
             J2
             E2
             J1
             C
             Z1
             N1
             Y
             B1
             H
             A2
             M
             D
             S1
             E
             L
             Y1
             Z
             O
             U1
             T1
             A1
             B
             P
             B2
             I1
             L1
             X1
             I
             R1
             D2
             Q
             F
             F1
             W
             J
             W1
             E1
             N
             H2
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main337 S1
             D
             N1
             E2
             U1
             G1
             Q
             J1
             T
             A1
             Y
             H1
             V1
             O
             C
             N
             X
             Z1
             Z
             Y1
             C1
             I
             V
             L
             Q1
             P
             G2
             K
             A2
             F2
             A
             F1
             B1
             R1
             X1
             I1
             E
             G
             H2
             M1
             I2
             E1
             M
             F
             K1
             W
             D2
             J
             W1
             S
             L1
             D1
             H
             O1
             J2
             C2
             B
             P1
             R
             U
             T1
             B2)
        (and (= Z (- 4))
     (not (= Z (- 1)))
     (<= 0 B2)
     (<= 0 X1)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 U)
     (<= 0 R)
     (<= 0 E)
     (<= 0 B)
     (not (= Y1 0)))
      )
      (inv_main343 S1
             D
             N1
             E2
             U1
             G1
             Q
             J1
             T
             A1
             Y
             H1
             V1
             O
             C
             N
             X
             Z1
             Z
             Y1
             C1
             I
             V
             L
             Q1
             P
             G2
             K
             A2
             F2
             A
             F1
             B1
             R1
             X1
             I1
             E
             G
             H2
             M1
             I2
             E1
             M
             F
             K1
             W
             D2
             J
             W1
             S
             L1
             D1
             H
             O1
             J2
             C2
             B
             P1
             R
             U
             T1
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main121 L
             C1
             R1
             G2
             J1
             T1
             W
             A
             A2
             V1
             I2
             B2
             F1
             J
             P
             C2
             H
             X
             I
             K
             R
             B
             Y1
             K2
             Q1
             B1
             D
             M1
             D2
             D1
             H1
             P1
             E
             G
             T
             M
             U1
             G1
             Z
             O
             X1
             H2
             S1
             U
             F
             W1
             V
             C
             Q
             J2
             Y
             O1
             Z1
             L1
             F2
             N1
             K1
             I1
             A1
             E1
             S
             N)
        (and (= T1 8528)
     (not (= T1 8513))
     (not (= T1 12292))
     (not (= T1 16384))
     (not (= T1 8192))
     (not (= T1 24576))
     (not (= T1 8195))
     (not (= T1 8480))
     (not (= T1 8481))
     (not (= T1 8482))
     (not (= T1 8464))
     (not (= T1 8465))
     (not (= T1 8466))
     (not (= T1 8496))
     (not (= T1 8497))
     (not (= T1 8512))
     (not (= X (- 2097152)))
     (<= 0 U1)
     (<= 0 K1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 A1)
     (<= 0 T)
     (<= 0 N)
     (<= 0 M)
     (= E2 1)
     (= v_63 D1)
     (= v_64 T1)
     (= v_65 X))
      )
      (inv_main304 L
             C1
             R1
             G2
             J1
             T1
             W
             A
             A2
             V1
             I2
             B2
             F1
             J
             P
             C2
             H
             X
             I
             K
             R
             B
             Y1
             K2
             Q1
             B1
             D
             E2
             D2
             D1
             H1
             P1
             E
             G
             v_63
             M
             U1
             G1
             Z
             O
             X1
             v_64
             S1
             U
             F
             W1
             V
             C
             Q
             J2
             Y
             O1
             Z1
             L1
             F2
             N1
             K1
             v_65
             A1
             E1
             S
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main121 V
             I1
             U
             K
             F1
             N1
             Z1
             K2
             H1
             I
             R
             M1
             G
             A2
             C1
             F
             X1
             C
             G1
             S1
             A
             Q
             Y
             S
             G2
             O1
             L1
             P
             O
             D2
             M
             C2
             E2
             P1
             B
             V1
             E
             Y1
             W1
             I2
             Z
             R1
             X
             L
             U1
             T1
             D1
             H
             B2
             D
             E1
             F2
             K1
             Q1
             B1
             N
             J
             H2
             W
             A1
             T
             J2)
        (and (not (= N1 8513))
     (not (= N1 12292))
     (not (= N1 16384))
     (not (= N1 8192))
     (not (= N1 24576))
     (not (= N1 8195))
     (not (= N1 8480))
     (not (= N1 8481))
     (not (= N1 8482))
     (not (= N1 8464))
     (not (= N1 8465))
     (not (= N1 8466))
     (not (= N1 8496))
     (not (= N1 8497))
     (not (= N1 8512))
     (= J1 0)
     (= C (- 2097152))
     (<= 0 H2)
     (<= 0 V1)
     (<= 0 A1)
     (<= 0 W)
     (<= 0 J)
     (<= 0 E)
     (<= 0 B)
     (<= 0 J2)
     (= N1 8528)
     (= v_63 D2)
     (= v_64 N1)
     (= v_65 C))
      )
      (inv_main304 V
             I1
             U
             K
             F1
             N1
             Z1
             K2
             H1
             I
             R
             M1
             G
             A2
             C1
             F
             X1
             C
             G1
             S1
             A
             Q
             Y
             S
             G2
             O1
             L1
             J1
             O
             D2
             M
             C2
             E2
             P1
             v_63
             V1
             E
             Y1
             W1
             I2
             Z
             v_64
             X
             L
             U1
             T1
             D1
             H
             B2
             D
             E1
             F2
             K1
             Q1
             B1
             N
             J
             v_65
             W
             A1
             T
             J2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main121 Q
             A
             R
             M
             W
             D1
             M1
             E2
             J1
             U
             K
             R1
             A2
             T
             K1
             Z
             Y
             V1
             G2
             N
             G
             O1
             K2
             Z1
             L1
             Q1
             P1
             H
             G1
             J
             T1
             N1
             F
             S1
             L
             I
             C1
             J2
             P
             S
             C
             U1
             I1
             I2
             O
             E1
             A1
             X
             H2
             Y1
             V
             D2
             F1
             F2
             B
             D
             X1
             B2
             B1
             C2
             W1
             E)
        (and (= H1 1)
     (not (= D1 8528))
     (= D1 8529)
     (not (= D1 8513))
     (not (= D1 12292))
     (not (= D1 16384))
     (not (= D1 8192))
     (not (= D1 24576))
     (not (= D1 8195))
     (not (= D1 8480))
     (not (= D1 8481))
     (not (= D1 8482))
     (not (= D1 8464))
     (not (= D1 8465))
     (not (= D1 8466))
     (not (= D1 8496))
     (not (= D1 8497))
     (not (= D1 8512))
     (<= 0 C2)
     (<= 0 B2)
     (<= 0 X1)
     (<= 0 C1)
     (<= 0 B1)
     (<= 0 L)
     (<= 0 I)
     (<= 0 E)
     (not (= V1 (- 2097152)))
     (= v_63 J)
     (= v_64 D1)
     (= v_65 V1))
      )
      (inv_main304 Q
             A
             R
             M
             W
             D1
             M1
             E2
             J1
             U
             K
             R1
             A2
             T
             K1
             Z
             Y
             V1
             G2
             N
             G
             O1
             K2
             Z1
             L1
             Q1
             P1
             H1
             G1
             J
             T1
             N1
             F
             S1
             v_63
             I
             C1
             J2
             P
             S
             C
             v_64
             I1
             I2
             O
             E1
             A1
             X
             H2
             Y1
             V
             D2
             F1
             F2
             B
             D
             X1
             v_65
             B1
             C2
             W1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main121 V
             W1
             P
             L
             G
             X1
             N1
             O1
             J2
             Y
             D1
             C
             O
             V1
             C1
             Q
             H
             Q1
             T1
             X
             I1
             M
             K2
             D
             T
             A1
             A
             K
             B2
             F
             K1
             U
             G2
             J
             L1
             E
             W
             E1
             S1
             I
             B
             F2
             H1
             U1
             Z
             S
             I2
             M1
             Z1
             H2
             R
             E2
             R1
             Y1
             F1
             J1
             C2
             B1
             D2
             G1
             A2
             N)
        (and (= X1 8529)
     (not (= X1 8513))
     (not (= X1 12292))
     (not (= X1 16384))
     (not (= X1 8192))
     (not (= X1 24576))
     (not (= X1 8195))
     (not (= X1 8480))
     (not (= X1 8481))
     (not (= X1 8482))
     (not (= X1 8464))
     (not (= X1 8465))
     (not (= X1 8466))
     (not (= X1 8496))
     (not (= X1 8497))
     (not (= X1 8512))
     (= Q1 (- 2097152))
     (= P1 0)
     (<= 0 D2)
     (<= 0 C2)
     (<= 0 L1)
     (<= 0 G1)
     (<= 0 B1)
     (<= 0 W)
     (<= 0 N)
     (<= 0 E)
     (not (= X1 8528))
     (= v_63 F)
     (= v_64 X1)
     (= v_65 Q1))
      )
      (inv_main304 V
             W1
             P
             L
             G
             X1
             N1
             O1
             J2
             Y
             D1
             C
             O
             V1
             C1
             Q
             H
             Q1
             T1
             X
             I1
             M
             K2
             D
             T
             A1
             A
             P1
             B2
             F
             K1
             U
             G2
             J
             v_63
             E
             W
             E1
             S1
             I
             B
             v_64
             H1
             U1
             Z
             S
             I2
             M1
             Z1
             H2
             R
             E2
             R1
             Y1
             F1
             J1
             C2
             v_65
             D2
             G1
             A2
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main121 S
             U1
             E2
             E1
             K1
             G1
             Q
             X1
             A1
             O
             Q1
             A2
             U
             B1
             J2
             P1
             H2
             R
             N
             G
             I1
             P
             V
             D1
             B2
             L1
             H
             W1
             J1
             F
             Y
             W
             Y1
             M
             V1
             G2
             X
             T1
             K
             C1
             A
             L
             S1
             H1
             L2
             O1
             D2
             F1
             F2
             D
             M1
             R1
             C2
             E
             C
             J
             N1
             I2
             B
             T
             K2
             Z1)
        (and (not (= G1 16384))
     (not (= G1 8192))
     (not (= G1 24576))
     (not (= G1 8195))
     (not (= G1 8480))
     (not (= G1 8481))
     (not (= G1 8482))
     (not (= G1 8464))
     (not (= G1 8465))
     (not (= G1 8466))
     (= G1 8496)
     (= Z 2)
     (= C 1)
     (<= 0 B)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 Z1)
     (<= 0 V1)
     (<= 0 N1)
     (<= 0 X)
     (<= 0 T)
     (not (= G1 12292))
     (= v_64 G1))
      )
      (inv_main275 S
             U1
             E2
             E1
             K1
             G1
             Q
             X1
             A1
             O
             Q1
             A2
             U
             B1
             J2
             P1
             H2
             R
             N
             G
             I1
             P
             V
             D1
             B2
             L1
             H
             W1
             J1
             F
             Y
             W
             Y1
             M
             V1
             G2
             X
             T1
             K
             I
             A
             v_64
             S1
             H1
             L2
             O1
             D2
             F1
             F2
             D
             M1
             R1
             C2
             E
             Z
             J
             N1
             I2
             B
             T
             K2
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main121 K
             N
             R1
             S1
             D
             D2
             P
             N1
             W
             Y
             S
             J1
             L1
             O1
             A2
             C1
             G2
             I2
             M
             P1
             T
             R
             F1
             E2
             A1
             G1
             X
             H1
             A
             Y1
             K1
             H2
             E1
             B
             T1
             Z1
             I1
             V1
             L
             K2
             C2
             U1
             M1
             U
             D1
             V
             O
             B2
             X1
             I
             Z
             Q
             J
             W1
             Q1
             F2
             C
             J2
             B1
             H
             G
             E)
        (and (not (= D2 16384))
     (not (= D2 8192))
     (not (= D2 24576))
     (not (= D2 8195))
     (not (= D2 8480))
     (not (= D2 8481))
     (not (= D2 8482))
     (not (= D2 8464))
     (not (= D2 8465))
     (not (= D2 8466))
     (= D2 8496)
     (not (= Q1 1))
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 I1)
     (<= 0 B1)
     (<= 0 H)
     (<= 0 E)
     (<= 0 C)
     (<= 0 J2)
     (not (= D2 12292))
     (= v_63 D2))
      )
      (inv_main275 K
             N
             R1
             S1
             D
             D2
             P
             N1
             W
             Y
             S
             J1
             L1
             O1
             A2
             C1
             G2
             I2
             M
             P1
             T
             R
             F1
             E2
             A1
             G1
             X
             H1
             A
             Y1
             K1
             H2
             E1
             B
             T1
             Z1
             I1
             V1
             L
             F
             C2
             v_63
             M1
             U
             D1
             V
             O
             B2
             X1
             I
             Z
             Q
             J
             W1
             Q1
             F2
             C
             J2
             B1
             H
             G
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main121 N
             H
             D1
             O1
             B2
             D
             M1
             S1
             C1
             S
             B
             A2
             H2
             E
             G2
             J1
             T1
             Q1
             A1
             L2
             I1
             H1
             T
             F1
             P
             A
             V
             K1
             W1
             D2
             G
             L1
             V1
             M
             P1
             U
             X1
             R1
             O
             Z1
             C
             F
             W
             N1
             R
             B1
             J2
             K
             J
             Y
             U1
             L
             Z
             E2
             Y1
             I
             X
             F2
             G1
             E1
             I2
             C2)
        (and (not (= D 12292))
     (not (= D 16384))
     (not (= D 8192))
     (not (= D 24576))
     (not (= D 8195))
     (not (= D 8480))
     (not (= D 8481))
     (not (= D 8482))
     (not (= D 8464))
     (not (= D 8465))
     (not (= D 8466))
     (not (= D 8496))
     (= D 8497)
     (= K2 2)
     (<= 0 F2)
     (<= 0 C2)
     (<= 0 X1)
     (<= 0 P1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 X)
     (<= 0 U)
     (= Y1 1)
     (= v_64 D))
      )
      (inv_main275 N
             H
             D1
             O1
             B2
             D
             M1
             S1
             C1
             S
             B
             A2
             H2
             E
             G2
             J1
             T1
             Q1
             A1
             L2
             I1
             H1
             T
             F1
             P
             A
             V
             K1
             W1
             D2
             G
             L1
             V1
             M
             P1
             U
             X1
             R1
             O
             Q
             C
             v_64
             W
             N1
             R
             B1
             J2
             K
             J
             Y
             U1
             L
             Z
             E2
             K2
             I
             X
             F2
             G1
             E1
             I2
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main121 G2
             G1
             V
             R
             X1
             Y1
             C1
             B
             F1
             D
             P
             D1
             F2
             T1
             N
             F
             J2
             J
             Q1
             M
             I1
             H1
             S1
             C
             W
             B2
             P1
             K1
             Y
             J1
             A2
             Z1
             O1
             U1
             M1
             N1
             A
             G
             H2
             L1
             L
             T
             H
             E
             E2
             O
             D2
             U
             W1
             Z
             E1
             K
             Q
             B1
             V1
             I2
             A1
             S
             K2
             I
             R1
             X)
        (and (not (= Y1 16384))
     (not (= Y1 8192))
     (not (= Y1 24576))
     (not (= Y1 8195))
     (not (= Y1 8480))
     (not (= Y1 8481))
     (not (= Y1 8482))
     (not (= Y1 8464))
     (not (= Y1 8465))
     (not (= Y1 8466))
     (not (= Y1 8496))
     (= Y1 8497)
     (not (= V1 1))
     (<= 0 A)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 A1)
     (<= 0 X)
     (<= 0 S)
     (<= 0 I)
     (<= 0 K2)
     (not (= Y1 12292))
     (= v_63 Y1))
      )
      (inv_main275 G2
             G1
             V
             R
             X1
             Y1
             C1
             B
             F1
             D
             P
             D1
             F2
             T1
             N
             F
             J2
             J
             Q1
             M
             I1
             H1
             S1
             C
             W
             B2
             P1
             K1
             Y
             J1
             A2
             Z1
             O1
             U1
             M1
             N1
             A
             G
             H2
             C2
             L
             v_63
             H
             E
             E2
             O
             D2
             U
             W1
             Z
             E1
             K
             Q
             B1
             V1
             I2
             A1
             S
             K2
             I
             R1
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 H2
             J
             J2
             S1
             A2
             D2
             C2
             C1
             F1
             R1
             Z1
             K
             J1
             K1
             P
             C
             L
             V1
             U
             P1
             Q1
             E1
             O1
             Z
             X1
             N1
             W1
             I
             N
             W
             M
             M1
             Y
             V
             I2
             G1
             F
             D1
             D
             E2
             T1
             S
             X
             T
             Q
             R
             U1
             F2
             Y1
             B1
             E
             L1
             O
             A1
             H1
             A
             G
             B
             I1
             H
             G2
             B2)
        (and (not (= D2 8529))
     (not (= D2 8544))
     (not (= D2 8545))
     (not (= D2 8560))
     (not (= D2 8561))
     (not (= D2 8448))
     (not (= D2 8576))
     (not (= D2 8577))
     (not (= D2 8592))
     (not (= D2 8593))
     (not (= D2 8608))
     (not (= D2 8609))
     (= D2 8640)
     (not (= D2 8513))
     (not (= D2 12292))
     (not (= D2 16384))
     (not (= D2 8192))
     (not (= D2 24576))
     (not (= D2 8195))
     (not (= D2 8480))
     (not (= D2 8481))
     (not (= D2 8482))
     (not (= D2 8464))
     (not (= D2 8465))
     (not (= D2 8466))
     (not (= D2 8496))
     (not (= D2 8497))
     (not (= D2 8512))
     (<= 0 B2)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 H)
     (<= 0 G)
     (<= 0 F)
     (<= 0 B)
     (<= 0 I2)
     (not (= D2 8528))
     (= v_62 D2))
      )
      (inv_main436 H2
             J
             J2
             S1
             A2
             D2
             C2
             C1
             F1
             R1
             Z1
             K
             J1
             K1
             P
             C
             L
             V1
             U
             P1
             Q1
             E1
             O1
             Z
             X1
             N1
             W1
             I
             N
             W
             M
             M1
             Y
             V
             I2
             G1
             F
             D1
             D
             E2
             T1
             v_62
             X
             T
             Q
             R
             U1
             F2
             Y1
             B1
             E
             L1
             O
             A1
             H1
             A
             G
             B
             I1
             H
             G2
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 H2
             G2
             F2
             R1
             P1
             C2
             G1
             U1
             O1
             I1
             C1
             S
             K
             Q1
             A1
             T1
             G
             K1
             J
             Y
             T
             X
             E
             F
             A
             H
             W1
             P
             O
             U
             B
             E2
             W
             I2
             L1
             X1
             J2
             J1
             S1
             I
             D1
             Z1
             M
             D2
             L
             Z
             D
             Y1
             Q
             A2
             N
             H1
             M1
             R
             F1
             C
             V
             E1
             B1
             V1
             B2
             N1)
        (and (not (= C2 8529))
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
     (= C2 8641)
     (not (= C2 8513))
     (not (= C2 12292))
     (not (= C2 16384))
     (not (= C2 8192))
     (not (= C2 24576))
     (not (= C2 8195))
     (not (= C2 8480))
     (not (= C2 8481))
     (not (= C2 8482))
     (not (= C2 8464))
     (not (= C2 8465))
     (not (= C2 8466))
     (not (= C2 8496))
     (not (= C2 8497))
     (not (= C2 8512))
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 N1)
     (<= 0 L1)
     (<= 0 E1)
     (<= 0 B1)
     (<= 0 V)
     (<= 0 J2)
     (not (= C2 8528))
     (= v_62 C2))
      )
      (inv_main436 H2
             G2
             F2
             R1
             P1
             C2
             G1
             U1
             O1
             I1
             C1
             S
             K
             Q1
             A1
             T1
             G
             K1
             J
             Y
             T
             X
             E
             F
             A
             H
             W1
             P
             O
             U
             B
             E2
             W
             I2
             L1
             X1
             J2
             J1
             S1
             I
             D1
             v_62
             M
             D2
             L
             Z
             D
             Y1
             Q
             A2
             N
             H1
             M1
             R
             F1
             C
             V
             E1
             B1
             V1
             B2
             N1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main202 Z
             S
             M1
             F1
             I
             A
             B
             P1
             K2
             Q1
             R1
             A1
             J2
             E
             N
             L1
             K
             O1
             N1
             E1
             E2
             C
             V
             V1
             A2
             F2
             X
             Q
             P
             C2
             H1
             M
             U
             K1
             W1
             W
             S1
             I2
             B2
             X1
             I1
             R
             B1
             D
             G2
             Z1
             J
             G1
             F
             D2
             H
             C1
             T
             H2
             Y1
             L
             D1
             O
             U1
             Y
             T1
             G)
        (and (not (= X 0))
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 S1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 W)
     (<= 0 O)
     (<= 0 G)
     (= J1 0))
      )
      (inv_main121 Z
             S
             M1
             F1
             I
             A
             B
             P1
             K2
             Q1
             R1
             A1
             J2
             E
             N
             L1
             K
             O1
             N1
             E1
             E2
             C
             V
             V1
             A2
             F2
             X
             Q
             P
             C2
             H1
             M
             U
             K1
             W1
             W
             S1
             I2
             B2
             X1
             I1
             R
             J1
             D
             G2
             Z1
             J
             G1
             F
             D2
             H
             C1
             T
             H2
             Y1
             L
             D1
             O
             U1
             Y
             T1
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main202 O
             R1
             J
             Z1
             Y1
             B1
             H2
             L1
             J2
             T
             L
             Y
             N1
             C1
             X1
             H
             C
             G
             S1
             H1
             E1
             K1
             Q
             I2
             V
             E
             R
             F1
             D1
             C2
             Z
             T1
             E2
             M1
             D
             G1
             W
             K2
             Q1
             B
             F
             S
             I1
             U
             F2
             A
             O1
             V1
             K
             X
             B2
             G2
             W1
             U1
             P1
             N
             M
             D2
             I
             P
             A2
             A1)
        (and (not (= I1 0))
     (= R 0)
     (<= 0 D2)
     (<= 0 G1)
     (<= 0 A1)
     (<= 0 W)
     (<= 0 P)
     (<= 0 M)
     (<= 0 I)
     (<= 0 D)
     (= J1 0))
      )
      (inv_main121 O
             R1
             J
             Z1
             Y1
             B1
             H2
             L1
             J2
             T
             L
             Y
             N1
             C1
             X1
             H
             C
             G
             S1
             H1
             E1
             K1
             Q
             I2
             V
             E
             R
             F1
             D1
             C2
             Z
             T1
             E2
             M1
             D
             G1
             W
             K2
             Q1
             B
             F
             S
             J1
             U
             F2
             A
             O1
             V1
             K
             X
             B2
             G2
             W1
             U1
             P1
             N
             M
             D2
             I
             P
             A2
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main523 O
             A
             F2
             J2
             I2
             H1
             H2
             F
             Z
             C1
             E
             X1
             V1
             J1
             H
             C
             D2
             A1
             Y1
             K2
             K1
             O1
             C2
             M
             Q1
             B
             P1
             S
             N1
             Y
             D
             W
             Q
             R1
             J
             B1
             W1
             G2
             P
             B2
             T1
             M1
             Z1
             L1
             G1
             A2
             S1
             D1
             U
             X
             I1
             R
             I
             E1
             L
             E2
             T
             N
             F1
             K
             V
             G)
        (and (= U1 0)
     (<= 0 W1)
     (<= 0 F1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 N)
     (<= 0 K)
     (<= 0 J)
     (<= 0 G)
     (= G2 0))
      )
      (inv_main121 O
             A
             F2
             J2
             I2
             H1
             H2
             F
             Z
             C1
             E
             X1
             V1
             J1
             H
             C
             D2
             A1
             Y1
             K2
             K1
             O1
             C2
             M
             Q1
             B
             P1
             S
             N1
             Y
             D
             W
             Q
             R1
             J
             B1
             W1
             G2
             P
             B2
             T1
             M1
             U1
             L1
             G1
             A2
             S1
             D1
             U
             X
             I1
             R
             I
             E1
             L
             E2
             T
             N
             F1
             K
             V
             G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main523 I1
             N
             B2
             D2
             U
             C
             R1
             C1
             S1
             U1
             G
             O1
             Q1
             W
             H2
             M1
             P
             W1
             H1
             V1
             L
             B
             E
             N1
             Z1
             K1
             K2
             T
             B1
             X
             J2
             X1
             I
             C2
             K
             J
             G2
             A1
             G1
             Y1
             F2
             A
             J1
             V
             D1
             F1
             T1
             M
             O
             H
             Y
             L1
             I2
             E2
             S
             R
             F
             D
             P1
             Z
             Q
             A2)
        (and (not (= A1 0))
     (= C A)
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 P1)
     (<= 0 Z)
     (<= 0 K)
     (<= 0 J)
     (<= 0 F)
     (<= 0 D)
     (= E1 0))
      )
      (inv_main121 I1
             N
             B2
             D2
             U
             C
             R1
             C1
             S1
             U1
             G
             O1
             Q1
             W
             H2
             M1
             P
             W1
             H1
             V1
             L
             B
             E
             N1
             Z1
             K1
             K2
             T
             B1
             X
             J2
             X1
             I
             C2
             K
             J
             G2
             A1
             G1
             Y1
             F2
             A
             E1
             V
             D1
             F1
             T1
             M
             O
             H
             Y
             L1
             I2
             E2
             S
             R
             F
             D
             P1
             Z
             Q
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main523 I
             U1
             O
             I1
             J
             D1
             X
             Z1
             I2
             A
             F2
             T1
             H2
             E2
             O1
             V
             D2
             G1
             K1
             F1
             P
             J2
             C
             J1
             W1
             V1
             K
             E
             E1
             Q1
             B1
             C2
             A2
             H1
             C1
             G
             Z
             H
             A1
             Y1
             M
             F
             S1
             B
             P1
             R1
             Q
             N1
             G2
             N
             L
             W
             L1
             Y
             X1
             K2
             S
             U
             R
             D
             T
             B2)
        (and (not (= D1 F))
     (not (= H 0))
     (<= 0 B2)
     (<= 0 C1)
     (<= 0 Z)
     (<= 0 U)
     (<= 0 S)
     (<= 0 R)
     (<= 0 G)
     (<= 0 D)
     (= M1 0)
     (= v_63 D1))
      )
      (inv_main121 I
             U1
             O
             I1
             J
             D1
             X
             Z1
             I2
             A
             F2
             T1
             H2
             E2
             O1
             V
             D2
             G1
             K1
             F1
             P
             J2
             C
             J1
             W1
             V1
             K
             E
             E1
             Q1
             B1
             C2
             A2
             H1
             C1
             G
             Z
             H
             A1
             Y1
             v_63
             F
             M1
             B
             P1
             R1
             Q
             N1
             G2
             N
             L
             W
             L1
             Y
             X1
             K2
             S
             U
             R
             D
             T
             B2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main107 R1
             T1
             V1
             F
             J1
             K1
             D1
             P
             H1
             Z1
             K2
             G2
             F1
             U1
             A2
             T
             B
             N1
             P1
             C2
             X
             A1
             I
             J
             N
             W
             V
             Q1
             R
             U
             E1
             I2
             C1
             L1
             O1
             X1
             Y
             O
             G
             B2
             D2
             G1
             Y1
             S1
             Q
             Z
             H
             A
             K
             E
             M1
             J2
             F2
             E2
             I1
             S
             W1
             C
             D
             B1
             H2
             M)
        (and (= L (+ 1 J1))
     (not (= B 0))
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 O1)
     (<= 0 B1)
     (<= 0 Y)
     (<= 0 M)
     (<= 0 D)
     (<= 0 C)
     (= Q (- 12288)))
      )
      (inv_main121 R1
             T1
             V1
             F
             L
             K1
             D1
             P
             H1
             Z1
             K2
             G2
             F1
             U1
             A2
             T
             B
             N1
             P1
             C2
             X
             A1
             I
             J
             N
             W
             V
             Q1
             R
             U
             E1
             I2
             C1
             L1
             O1
             X1
             Y
             O
             G
             B2
             D2
             G1
             Y1
             S1
             Q
             Z
             H
             A
             K
             E
             M1
             J2
             F2
             E2
             I1
             S
             W1
             C
             D
             B1
             H2
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main107 D
             E2
             F
             S1
             M
             J1
             C
             M1
             K1
             F2
             T
             D2
             R1
             H2
             G1
             S
             Z1
             N
             C2
             G2
             H1
             L
             Y1
             K
             B1
             K2
             U1
             O1
             Y
             A1
             Z
             J
             T1
             V
             A
             I
             D1
             H
             G
             B2
             I2
             B
             X1
             A2
             J2
             U
             N1
             R
             F1
             Q
             V1
             X
             W1
             C1
             Q1
             W
             I1
             P
             O
             E
             L1
             E1)
        (and (= P1 (+ 1 M))
     (not (= U (- 16384)))
     (not (= J2 (- 12288)))
     (<= 0 A)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 P)
     (<= 0 O)
     (<= 0 I)
     (<= 0 E)
     (not (= Z1 0)))
      )
      (inv_main121 D
             E2
             F
             S1
             P1
             J1
             C
             M1
             K1
             F2
             T
             D2
             R1
             H2
             G1
             S
             Z1
             N
             C2
             G2
             H1
             L
             Y1
             K
             B1
             K2
             U1
             O1
             Y
             A1
             Z
             J
             T1
             V
             A
             I
             D1
             H
             G
             B2
             I2
             B
             X1
             A2
             J2
             U
             N1
             R
             F1
             Q
             V1
             X
             W1
             C1
             Q1
             W
             I1
             P
             O
             E
             L1
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main107 G1
             K2
             Y
             Z
             J
             L
             J1
             W
             C
             Q
             D1
             L1
             A2
             B1
             E1
             T1
             Z1
             R1
             N1
             V
             Q1
             O
             Y1
             C1
             P1
             E
             W1
             M
             B2
             H1
             J2
             D
             B
             U
             X1
             V1
             K
             S1
             H2
             M1
             A
             H
             G2
             U1
             T
             X
             A1
             O1
             E2
             C2
             F1
             I2
             K1
             N
             I1
             F2
             G
             S
             F
             I
             R
             D2)
        (and (= X (- 16384))
     (not (= T (- 12288)))
     (= P (+ 1 J))
     (<= 0 D2)
     (<= 0 X1)
     (<= 0 V1)
     (<= 0 S)
     (<= 0 K)
     (<= 0 I)
     (<= 0 G)
     (<= 0 F)
     (not (= Z1 0)))
      )
      (inv_main121 G1
             K2
             Y
             Z
             P
             L
             J1
             W
             C
             Q
             D1
             L1
             A2
             B1
             E1
             T1
             Z1
             R1
             N1
             V
             Q1
             O
             Y1
             C1
             P1
             E
             W1
             M
             B2
             H1
             J2
             D
             B
             U
             X1
             V1
             K
             S1
             H2
             M1
             A
             H
             G2
             U1
             T
             X
             A1
             O1
             E2
             C2
             F1
             I2
             K1
             N
             I1
             F2
             G
             S
             F
             I
             R
             D2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 B2
             T1
             J2
             G2
             F1
             I1
             O
             Q1
             T
             L1
             Q
             D
             I2
             I
             X
             U
             K1
             F2
             A2
             E
             C2
             N1
             F
             A
             K
             C1
             U1
             Z1
             E2
             P1
             B
             M
             N
             H1
             O1
             H
             R
             Y1
             C
             P
             S1
             W
             D2
             A1
             J
             S
             V
             H2
             R1
             B1
             X1
             D1
             W1
             E1
             V1
             Y
             G1
             G
             M1
             L
             Z
             J1)
        (and (not (= I1 8529))
     (not (= I1 8544))
     (not (= I1 8545))
     (not (= I1 8560))
     (not (= I1 8561))
     (not (= I1 8448))
     (not (= I1 8576))
     (not (= I1 8577))
     (not (= I1 8592))
     (not (= I1 8593))
     (not (= I1 8608))
     (not (= I1 8609))
     (not (= I1 8640))
     (not (= I1 8641))
     (= I1 8656)
     (not (= I1 8513))
     (not (= I1 12292))
     (not (= I1 16384))
     (not (= I1 8192))
     (not (= I1 24576))
     (not (= I1 8195))
     (not (= I1 8480))
     (not (= I1 8481))
     (not (= I1 8482))
     (not (= I1 8464))
     (not (= I1 8465))
     (not (= I1 8466))
     (not (= I1 8496))
     (not (= I1 8497))
     (not (= I1 8512))
     (<= 0 O1)
     (<= 0 M1)
     (<= 0 J1)
     (<= 0 G1)
     (<= 0 R)
     (<= 0 L)
     (<= 0 H)
     (<= 0 G)
     (not (= I1 8528))
     (= v_62 I1))
      )
      (inv_main458 B2
             T1
             J2
             G2
             F1
             I1
             O
             Q1
             T
             L1
             Q
             D
             I2
             I
             X
             U
             K1
             F2
             A2
             E
             C2
             N1
             F
             A
             K
             C1
             U1
             Z1
             E2
             P1
             B
             M
             N
             H1
             O1
             H
             R
             Y1
             C
             P
             S1
             v_62
             D2
             A1
             J
             S
             V
             H2
             R1
             B1
             X1
             D1
             W1
             E1
             V1
             Y
             G1
             G
             M1
             L
             Z
             J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 L1
             Q1
             Y
             J
             Z
             M1
             A1
             H1
             I
             P
             F2
             D2
             E1
             B2
             K1
             U
             C
             Z1
             S
             I2
             M
             X1
             V1
             B1
             O
             E
             A
             Q
             C1
             E2
             P1
             F1
             X
             G2
             D
             N1
             J2
             R
             J1
             F
             D1
             W1
             H2
             O1
             G1
             I1
             B
             N
             L
             H
             V
             Y1
             T
             A2
             K
             T1
             G
             C2
             U1
             R1
             S1
             W)
        (and (not (= M1 8529))
     (not (= M1 8544))
     (not (= M1 8545))
     (not (= M1 8560))
     (not (= M1 8561))
     (not (= M1 8448))
     (not (= M1 8576))
     (not (= M1 8577))
     (not (= M1 8592))
     (not (= M1 8593))
     (not (= M1 8608))
     (not (= M1 8609))
     (not (= M1 8640))
     (not (= M1 8641))
     (not (= M1 8656))
     (= M1 8657)
     (not (= M1 8513))
     (not (= M1 12292))
     (not (= M1 16384))
     (not (= M1 8192))
     (not (= M1 24576))
     (not (= M1 8195))
     (not (= M1 8480))
     (not (= M1 8481))
     (not (= M1 8482))
     (not (= M1 8464))
     (not (= M1 8465))
     (not (= M1 8466))
     (not (= M1 8496))
     (not (= M1 8497))
     (not (= M1 8512))
     (<= 0 C2)
     (<= 0 U1)
     (<= 0 R1)
     (<= 0 N1)
     (<= 0 W)
     (<= 0 G)
     (<= 0 D)
     (<= 0 J2)
     (not (= M1 8528))
     (= v_62 M1))
      )
      (inv_main458 L1
             Q1
             Y
             J
             Z
             M1
             A1
             H1
             I
             P
             F2
             D2
             E1
             B2
             K1
             U
             C
             Z1
             S
             I2
             M
             X1
             V1
             B1
             O
             E
             A
             Q
             C1
             E2
             P1
             F1
             X
             G2
             D
             N1
             J2
             R
             J1
             F
             D1
             v_62
             H2
             O1
             G1
             I1
             B
             N
             L
             H
             V
             Y1
             T
             A2
             K
             T1
             G
             C2
             U1
             R1
             S1
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main436 P1
             X1
             N1
             Z
             W1
             T
             H1
             E
             X
             O
             D
             D2
             E1
             A2
             U
             A1
             N
             C1
             Q1
             W
             J
             G2
             K
             B1
             Z1
             U1
             G1
             K2
             L1
             C2
             H
             V1
             A
             I1
             Q
             Y
             O1
             Y1
             S1
             B2
             F
             J1
             M
             D1
             G
             L
             C
             F1
             H2
             M1
             E2
             B
             F2
             R1
             R
             I
             P
             J2
             S
             I2
             V
             T1)
        (and (not (= R 12))
     (not (= R 15))
     (not (= R 18))
     (= R 21)
     (<= 0 I2)
     (<= 0 T1)
     (<= 0 O1)
     (<= 0 Y)
     (<= 0 S)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 J2)
     (not (= R 9)))
      )
      (inv_main540 P1
             X1
             N1
             Z
             W1
             T
             H1
             E
             X
             O
             D
             D2
             E1
             A2
             U
             A1
             N
             C1
             Q1
             W
             J
             G2
             K
             B1
             Z1
             U1
             G1
             K2
             L1
             C2
             H
             V1
             A
             I1
             Q
             Y
             O1
             Y1
             S1
             K1
             F
             J1
             M
             D1
             G
             L
             C
             F1
             H2
             M1
             E2
             B
             F2
             R1
             R
             I
             P
             J2
             S
             I2
             V
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main4 L1 I2)
        (and (= U1 8464)
     (= Q1 8464)
     (= F1 1)
     (= C1 (- 1))
     (not (= X 0))
     (= U 0)
     (= L 0)
     (= C 0)
     (= K2 8464)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 N1)
     (<= 0 I1)
     (<= 0 W)
     (<= 0 T)
     (<= 0 N)
     (<= 0 G)
     (= X1 0)
     (= v_63 D)
     (= v_64 X))
      )
      (inv_main540 Q1
             I2
             K2
             L
             P1
             U1
             T1
             E2
             R
             Q
             F2
             S1
             J2
             F1
             B
             S
             D2
             Y
             K1
             H1
             E
             X
             A
             J
             O1
             B1
             G2
             R1
             P
             I
             C2
             A1
             E1
             V
             W
             D
             v_63
             v_64
             W1
             C1
             H
             M
             C
             U
             F
             K
             M1
             B2
             O
             Z1
             D1
             J1
             H2
             A2
             X1
             G1
             I1
             N1
             N
             T
             Z
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main485 Q
             R1
             F
             K
             L1
             D
             I2
             Q1
             M
             L2
             J
             L
             T
             D2
             Y
             B2
             I
             A
             C
             A1
             H1
             U
             N
             U1
             B1
             O1
             E2
             G1
             B
             E1
             R
             H2
             I1
             K1
             V
             Y1
             N1
             C1
             K2
             O
             V1
             H
             S
             P1
             G2
             J1
             A2
             Z1
             Z
             M1
             G
             X
             X1
             W1
             F1
             D1
             E
             W
             P
             T1
             S1
             C2)
        (and (= F1 11)
     (<= 0 C2)
     (<= 0 Y1)
     (<= 0 T1)
     (<= 0 N1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 P)
     (<= 0 E)
     (= F2 12))
      )
      (inv_main488 Q
             R1
             F
             K
             L1
             D
             I2
             Q1
             M
             L2
             J
             L
             T
             D2
             Y
             B2
             I
             A
             C
             A1
             H1
             U
             N
             U1
             B1
             O1
             E2
             G1
             B
             E1
             R
             H2
             I1
             K1
             V
             Y1
             N1
             C1
             K2
             J2
             V1
             H
             S
             P1
             G2
             J1
             A2
             Z1
             Z
             M1
             G
             X
             X1
             W1
             F2
             D1
             E
             W
             P
             T1
             S1
             C2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main485 I
             X1
             I1
             U1
             Z1
             J
             G2
             P1
             O1
             C
             K1
             P
             X
             T1
             H1
             J1
             H
             D2
             R1
             W1
             Y
             D
             K
             Y1
             N
             M
             S
             N1
             F2
             G
             E1
             G1
             T
             J2
             B2
             D1
             I2
             V
             Q1
             O
             H2
             C2
             W
             R
             V1
             L
             E2
             L1
             A1
             U
             Z
             L2
             E
             C1
             B
             B1
             A
             S1
             F
             Q
             M1
             A2)
        (and (not (= B 11))
     (= F1 15)
     (<= 0 A)
     (<= 0 I2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 S1)
     (<= 0 D1)
     (<= 0 Q)
     (<= 0 F)
     (= B 14))
      )
      (inv_main488 I
             X1
             I1
             U1
             Z1
             J
             G2
             P1
             O1
             C
             K1
             P
             X
             T1
             H1
             J1
             H
             D2
             R1
             W1
             Y
             D
             K
             Y1
             N
             M
             S
             N1
             F2
             G
             E1
             G1
             T
             J2
             B2
             D1
             I2
             V
             Q1
             K2
             H2
             C2
             W
             R
             V1
             L
             E2
             L1
             A1
             U
             Z
             L2
             E
             C1
             F1
             B1
             A
             S1
             F
             Q
             M1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main485 X
             R1
             H1
             L1
             I
             K1
             Q1
             J2
             T
             H
             Z1
             D2
             V
             A
             R
             O
             U
             G
             S1
             J
             M1
             M
             A1
             P1
             T1
             N
             A2
             B2
             K2
             D
             J1
             U1
             G2
             I1
             C2
             G1
             N1
             I2
             E
             Y
             P
             W
             F1
             V1
             Y1
             K
             F
             Q
             E1
             O1
             C
             Z
             H2
             D1
             L2
             L
             C1
             X1
             W1
             B
             F2
             B1)
        (and (= L2 17)
     (not (= L2 14))
     (not (= L2 11))
     (<= 0 B)
     (<= 0 C2)
     (<= 0 X1)
     (<= 0 W1)
     (<= 0 N1)
     (<= 0 G1)
     (<= 0 C1)
     (<= 0 B1)
     (= E2 18))
      )
      (inv_main488 X
             R1
             H1
             L1
             I
             K1
             Q1
             J2
             T
             H
             Z1
             D2
             V
             A
             R
             O
             U
             G
             S1
             J
             M1
             M
             A1
             P1
             T1
             N
             A2
             B2
             K2
             D
             J1
             U1
             G2
             I1
             C2
             G1
             N1
             I2
             E
             S
             P
             W
             F1
             V1
             Y1
             K
             F
             Q
             E1
             O1
             C
             Z
             H2
             D1
             E2
             L
             C1
             X1
             W1
             B
             F2
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main485 C
             S1
             B
             C2
             A
             S
             J
             N
             D1
             E1
             J2
             G
             O1
             K
             T1
             Y
             L
             C1
             Q
             V
             H1
             L1
             I
             T
             X1
             J1
             E2
             P
             B1
             H2
             I1
             F1
             X
             M1
             Q1
             F
             P1
             I2
             L2
             G2
             U1
             W1
             B2
             V1
             W
             Z
             K2
             N1
             M
             Z1
             H
             E
             D2
             Y1
             K1
             A1
             R1
             G1
             R
             U
             D
             A2)
        (and (= K1 20)
     (not (= K1 17))
     (not (= K1 14))
     (not (= K1 11))
     (<= 0 A2)
     (<= 0 R1)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 G1)
     (<= 0 U)
     (<= 0 R)
     (<= 0 F)
     (= F2 21))
      )
      (inv_main488 C
             S1
             B
             C2
             A
             S
             J
             N
             D1
             E1
             J2
             G
             O1
             K
             T1
             Y
             L
             C1
             Q
             V
             H1
             L1
             I
             T
             X1
             J1
             E2
             P
             B1
             H2
             I1
             F1
             X
             M1
             Q1
             F
             P1
             I2
             L2
             O
             U1
             W1
             B2
             V1
             W
             Z
             K2
             N1
             M
             Z1
             H
             E
             D2
             Y1
             F2
             A1
             R1
             G1
             R
             U
             D
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main485 S
             E
             G2
             X1
             V
             G
             D1
             R1
             M1
             Q
             I
             P1
             I2
             J2
             H
             Z1
             L1
             G1
             A
             C2
             P
             H1
             F
             W1
             N1
             O1
             K1
             I1
             T
             D
             F2
             U1
             O
             B1
             U
             C
             F1
             T1
             Y1
             Y
             Z
             Q1
             N
             H2
             K
             L
             E2
             M
             A1
             A2
             X
             B
             S1
             K2
             W
             V1
             J
             D2
             J1
             B2
             E1
             R)
        (and (not (= W 17))
     (not (= W 14))
     (not (= W 11))
     (<= 0 D2)
     (<= 0 B2)
     (<= 0 J1)
     (<= 0 F1)
     (<= 0 U)
     (<= 0 R)
     (<= 0 J)
     (<= 0 C)
     (not (= W 20)))
      )
      (inv_main488 S
             E
             G2
             X1
             V
             G
             D1
             R1
             M1
             Q
             I
             P1
             I2
             J2
             H
             Z1
             L1
             G1
             A
             C2
             P
             H1
             F
             W1
             N1
             O1
             K1
             I1
             T
             D
             F2
             U1
             O
             B1
             U
             C
             F1
             T1
             Y1
             C1
             Z
             Q1
             N
             H2
             K
             L
             E2
             M
             A1
             A2
             X
             B
             S1
             K2
             W
             V1
             J
             D2
             J1
             B2
             E1
             R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main304 G2
             F2
             F1
             F
             G
             N1
             E2
             E1
             N
             B
             H1
             X1
             D1
             Y
             R
             P
             Z
             Z1
             B1
             A
             K
             C1
             E
             H2
             T1
             C2
             L1
             M1
             J2
             M
             U
             I2
             O
             B2
             Y1
             T
             H
             X
             V
             I
             Q
             A2
             L
             S
             R1
             D
             S1
             A1
             G1
             J1
             J
             P1
             I1
             D2
             K1
             W
             Q1
             U1
             O1
             W1
             V1
             C)
        (and (<= 0 Y1)
     (<= 0 W1)
     (<= 0 U1)
     (<= 0 Q1)
     (<= 0 O1)
     (<= 0 T)
     (<= 0 H)
     (<= 0 C)
     (not (= M1 0)))
      )
      (inv_main325 G2
             F2
             F1
             F
             G
             N1
             E2
             E1
             N
             B
             H1
             X1
             D1
             Y
             R
             P
             Z
             Z1
             B1
             A
             K
             C1
             E
             H2
             T1
             C2
             L1
             M1
             J2
             M
             U
             I2
             O
             B2
             Y1
             T
             H
             X
             V
             I
             Q
             A2
             L
             S
             R1
             D
             S1
             A1
             G1
             J1
             J
             P1
             I1
             D2
             K1
             W
             Q1
             U1
             O1
             W1
             V1
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main304 R1
             H1
             K1
             B2
             T1
             H2
             I1
             D2
             J2
             N
             J
             Y1
             A2
             F2
             I
             H
             P
             Y
             X
             A
             Z1
             T
             A1
             D1
             R
             L
             S1
             E
             W1
             E1
             E2
             G1
             L1
             B1
             M1
             Z
             M
             U1
             C1
             K
             P1
             N1
             U
             F1
             G
             D
             B
             V
             G2
             V1
             C2
             O1
             X1
             J1
             I2
             Q
             W
             O
             Q1
             C
             F
             S)
        (and (= E 0)
     (<= 0 Q1)
     (<= 0 M1)
     (<= 0 Z)
     (<= 0 W)
     (<= 0 S)
     (<= 0 O)
     (<= 0 M)
     (<= 0 C)
     (not (= M1 (- 30))))
      )
      (inv_main325 R1
             H1
             K1
             B2
             T1
             H2
             I1
             D2
             J2
             N
             J
             Y1
             A2
             F2
             I
             H
             P
             Y
             X
             A
             Z1
             T
             A1
             D1
             R
             L
             S1
             E
             W1
             E1
             E2
             G1
             L1
             B1
             M1
             Z
             M
             U1
             C1
             K
             P1
             N1
             U
             F1
             G
             D
             B
             V
             G2
             V1
             C2
             O1
             X1
             J1
             I2
             Q
             W
             O
             Q1
             C
             F
             S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main304 K
             H
             P
             V1
             H1
             I2
             X
             D2
             J
             S1
             F2
             T
             C1
             A1
             P1
             F
             V
             D
             J2
             C
             H2
             Z1
             N1
             T1
             A2
             O1
             G1
             Y1
             U1
             G
             R
             A
             F1
             G2
             E2
             R1
             E1
             D1
             N
             S
             K1
             Q1
             C2
             B
             U
             J1
             I1
             M
             W1
             E
             I
             B1
             W
             B2
             Z
             L1
             L
             Q
             M1
             O
             X1
             Y)
        (and (= E2 (- 30))
     (not (= E2 (- 1)))
     (= Y1 0)
     (<= 0 E2)
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 E1)
     (<= 0 Y)
     (<= 0 Q)
     (<= 0 O)
     (<= 0 L)
     (= H2 0))
      )
      (inv_main325 K
             H
             P
             V1
             H1
             I2
             X
             D2
             J
             S1
             F2
             T
             C1
             A1
             P1
             F
             V
             D
             J2
             C
             H2
             Z1
             N1
             T1
             A2
             O1
             G1
             Y1
             U1
             G
             R
             A
             F1
             G2
             E2
             R1
             E1
             D1
             N
             S
             K1
             Q1
             C2
             B
             U
             J1
             I1
             M
             W1
             E
             I
             B1
             W
             B2
             Z
             L1
             L
             Q
             M1
             O
             X1
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main304 H1
             A
             Q1
             Y
             H
             F1
             V
             V1
             G
             B1
             W
             C1
             E2
             I2
             M1
             J
             C2
             S
             O1
             C
             D2
             O
             T
             U1
             X1
             R1
             Q
             U
             L2
             Z
             X
             B2
             P
             A1
             K2
             W1
             D
             Z1
             H2
             N
             G2
             I
             S1
             F2
             J2
             M
             P1
             L
             D1
             F
             T1
             A2
             R
             K1
             L1
             I1
             G1
             B
             E
             N1
             K
             E1)
        (and (not (= D2 0))
     (not (= B2 (- 2)))
     (not (= B2 (- 4)))
     (= J1 512)
     (= U 0)
     (= K2 (- 30))
     (not (= K2 (- 1)))
     (>= F 65)
     (<= 0 B)
     (<= 0 W1)
     (<= 0 N1)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 E)
     (<= 0 D)
     (<= 0 K2)
     (= (+ Y1 (* (- 8) F)) 0)
     (= v_64 B2)
     (= v_65 B2))
      )
      (inv_main325 H1
             A
             Q1
             Y
             H
             F1
             V
             V1
             G
             B1
             W
             C1
             E2
             I2
             M1
             J
             C2
             S
             O1
             C
             D2
             O
             T
             U1
             X1
             R1
             Q
             U
             L2
             Z
             X
             B2
             P
             A1
             K2
             W1
             D
             Z1
             H2
             N
             G2
             I
             S1
             F2
             J2
             M
             P1
             L
             D1
             F
             J1
             A2
             R
             K1
             L1
             I1
             G1
             B
             v_64
             v_65
             Y1
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main304 X
             I2
             W
             A
             I1
             F
             D
             L2
             D1
             T1
             E2
             A1
             N
             G
             Q
             K
             B2
             P1
             R
             I
             V
             J
             K1
             C2
             Z1
             Z
             B
             Y
             H1
             H
             J1
             S
             Y1
             B1
             N1
             E1
             U
             X1
             F1
             L
             T
             M
             P
             G1
             R1
             J2
             E
             D2
             U1
             M1
             A2
             W1
             H2
             S1
             L1
             O1
             C1
             V1
             F2
             Q1
             G2
             K2)
        (and (= N1 (- 30))
     (not (= N1 (- 1)))
     (= Y 0)
     (not (= V 0))
     (not (= S (- 2)))
     (= S (- 4))
     (= O 1024)
     (>= M1 129)
     (<= 0 F2)
     (<= 0 V1)
     (<= 0 Q1)
     (<= 0 N1)
     (<= 0 E1)
     (<= 0 C1)
     (<= 0 U)
     (<= 0 K2)
     (= (+ C (* (- 8) M1)) 0)
     (= v_64 S)
     (= v_65 S))
      )
      (inv_main325 X
             I2
             W
             A
             I1
             F
             D
             L2
             D1
             T1
             E2
             A1
             N
             G
             Q
             K
             B2
             P1
             R
             I
             V
             J
             K1
             C2
             Z1
             Z
             B
             Y
             H1
             H
             J1
             S
             Y1
             B1
             N1
             E1
             U
             X1
             F1
             L
             T
             M
             P
             G1
             R1
             J2
             E
             D2
             U1
             M1
             O
             W1
             H2
             S1
             L1
             O1
             C1
             V1
             v_64
             v_65
             C
             K2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main121 B1
             S
             I
             R
             D1
             B2
             G2
             T1
             K1
             A
             D
             P1
             O
             A2
             Y
             A1
             J2
             C
             L1
             J1
             W
             F1
             U
             X1
             B
             C1
             H2
             N1
             V1
             E1
             J
             W1
             S1
             V
             F
             I2
             C2
             R1
             T
             D2
             Z1
             E2
             E
             F2
             U1
             X
             L
             H
             Q
             K2
             Z
             N
             M1
             Y1
             G1
             M
             P
             K
             I1
             H1
             Q1
             O1)
        (and (not (= B2 16384))
     (not (= B2 8192))
     (not (= B2 24576))
     (not (= B2 8195))
     (not (= B2 8480))
     (not (= B2 8481))
     (= B2 8482)
     (= G 3)
     (<= 0 I2)
     (<= 0 C2)
     (<= 0 O1)
     (<= 0 I1)
     (<= 0 H1)
     (<= 0 P)
     (<= 0 K)
     (<= 0 F)
     (not (= B2 12292)))
      )
      (inv_main202 B1
             S
             I
             R
             D1
             G
             G2
             T1
             K1
             A
             D
             P1
             O
             A2
             Y
             A1
             J2
             C
             L1
             J1
             W
             F1
             U
             X1
             B
             C1
             H2
             N1
             V1
             E1
             J
             W1
             S1
             V
             F
             I2
             C2
             R1
             T
             D2
             Z1
             B2
             E
             F2
             U1
             X
             L
             H
             Q
             K2
             Z
             N
             M1
             Y1
             G1
             M
             P
             K
             I1
             H1
             Q1
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main121 O2
             G
             D1
             B
             E
             W
             P1
             P
             T
             B2
             H
             B1
             S1
             D2
             A1
             J
             Z
             T1
             A2
             S
             G2
             U
             R1
             L
             J1
             F
             E1
             Q1
             G1
             L2
             M1
             L1
             M
             C
             Q
             D
             J2
             F1
             V1
             K
             N
             V
             W1
             H2
             E2
             I2
             X
             R
             Y1
             Y
             K2
             A
             C2
             I
             H1
             Z1
             O1
             I1
             N1
             C1
             K1
             N2)
        (and (= F2 8482)
     (= X1 8448)
     (not (= W 12292))
     (not (= W 16384))
     (not (= W 8192))
     (not (= W 24576))
     (not (= W 8195))
     (= W 8480)
     (= O 0)
     (<= 0 D)
     (<= 0 J2)
     (<= 0 O1)
     (<= 0 N1)
     (<= 0 I1)
     (<= 0 C1)
     (<= 0 Q)
     (<= 0 N2)
     (not (<= U1 0))
     (= M2 0))
      )
      (inv_main202 O2
             G
             D1
             B
             E
             X1
             P1
             P
             T
             B2
             M2
             B1
             S1
             D2
             A1
             O
             Z
             T1
             A2
             S
             G2
             U
             R1
             L
             J1
             F
             E1
             Q1
             G1
             L2
             F2
             L1
             M
             C
             Q
             D
             J2
             F1
             V1
             U1
             N
             W
             W1
             H2
             E2
             I2
             X
             R
             Y1
             Y
             K2
             A
             C2
             I
             H1
             Z1
             O1
             I1
             N1
             C1
             K1
             N2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main121 R1
             D
             O2
             E
             J
             U1
             F1
             E1
             K1
             B1
             L1
             P
             T1
             X
             K2
             D1
             N2
             S
             A1
             C
             H2
             D2
             G2
             U
             H1
             E2
             K
             V1
             N1
             L2
             L
             B2
             G
             G1
             R
             C2
             F
             I1
             Y
             C1
             S1
             B
             J2
             M1
             F2
             X1
             H
             A
             P1
             Y1
             O1
             Z1
             T
             V
             M2
             Q
             O
             Q1
             W
             N
             I2
             Z)
        (and (= W1 0)
     (not (= U1 12292))
     (not (= U1 16384))
     (not (= U1 8192))
     (not (= U1 24576))
     (not (= U1 8195))
     (not (= U1 8480))
     (= U1 8481)
     (= M 0)
     (= I 8482)
     (<= 0 C2)
     (<= 0 Q1)
     (<= 0 Z)
     (<= 0 W)
     (<= 0 R)
     (<= 0 O)
     (<= 0 N)
     (<= 0 F)
     (not (<= J1 0))
     (= A2 8448))
      )
      (inv_main202 R1
             D
             O2
             E
             J
             A2
             F1
             E1
             K1
             B1
             W1
             P
             T1
             X
             K2
             M
             N2
             S
             A1
             C
             H2
             D2
             G2
             U
             H1
             E2
             K
             V1
             N1
             L2
             I
             B2
             G
             G1
             R
             C2
             F
             I1
             Y
             J1
             S1
             U1
             J2
             M1
             F2
             X1
             H
             A
             P1
             Y1
             O1
             Z1
             T
             V
             M2
             Q
             O
             Q1
             W
             N
             I2
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main121 G1
             A1
             N2
             Q1
             Z
             K
             K2
             G2
             D1
             C2
             D2
             C
             I
             L1
             L2
             U
             J
             A
             F2
             V
             S1
             D
             J2
             W
             X1
             M2
             W1
             E1
             R
             P
             F1
             V1
             G
             F
             E2
             H2
             T
             S
             X
             C1
             N
             H1
             K1
             H
             M
             J1
             L
             Y
             P1
             U1
             T1
             E
             B
             Z1
             O1
             B2
             N1
             O
             M1
             B1
             R1
             Y1)
        (and (= I1 8576)
     (= Q 0)
     (not (= K 8528))
     (not (= K 8529))
     (not (= K 8544))
     (not (= K 8545))
     (= K 8560)
     (not (= K 8513))
     (not (= K 12292))
     (not (= K 16384))
     (not (= K 8192))
     (not (= K 24576))
     (not (= K 8195))
     (not (= K 8480))
     (not (= K 8481))
     (not (= K 8482))
     (not (= K 8464))
     (not (= K 8465))
     (not (= K 8466))
     (not (= K 8496))
     (not (= K 8497))
     (not (= K 8512))
     (<= 0 H2)
     (<= 0 E2)
     (<= 0 Y1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 B1)
     (<= 0 T)
     (<= 0 O)
     (not (<= A2 0))
     (= I2 8448))
      )
      (inv_main202 G1
             A1
             N2
             Q1
             Z
             I2
             K2
             G2
             D1
             C2
             Q
             C
             I
             L1
             L2
             U
             J
             A
             F2
             V
             S1
             D
             J2
             W
             X1
             M2
             W1
             E1
             R
             P
             I1
             V1
             G
             F
             E2
             H2
             T
             S
             X
             A2
             N
             K
             K1
             H
             M
             J1
             L
             Y
             P1
             U1
             T1
             E
             B
             Z1
             O1
             B2
             N1
             O
             M1
             B1
             R1
             Y1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main121 G1
             H
             E
             Y
             F1
             F
             A1
             K
             N2
             X1
             M1
             W
             M2
             R1
             S
             U1
             H2
             Z
             V1
             B2
             A2
             D2
             N1
             H1
             B1
             I
             C1
             O1
             N
             D
             U
             T1
             Q1
             K1
             G2
             W1
             C2
             P
             P1
             E1
             R
             I2
             K2
             L2
             L1
             L
             E2
             F2
             G
             J1
             B
             J
             C
             D1
             M
             O
             X
             A
             I1
             J2
             Y1
             Z1)
        (and (= T 8448)
     (= Q 0)
     (not (= F 8528))
     (not (= F 8529))
     (not (= F 8544))
     (not (= F 8545))
     (not (= F 8560))
     (= F 8561)
     (not (= F 8513))
     (not (= F 12292))
     (not (= F 16384))
     (not (= F 8192))
     (not (= F 24576))
     (not (= F 8195))
     (not (= F 8480))
     (not (= F 8481))
     (not (= F 8482))
     (not (= F 8464))
     (not (= F 8465))
     (not (= F 8466))
     (not (= F 8496))
     (not (= F 8497))
     (not (= F 8512))
     (<= 0 A)
     (<= 0 J2)
     (<= 0 G2)
     (<= 0 C2)
     (<= 0 Z1)
     (<= 0 W1)
     (<= 0 I1)
     (<= 0 X)
     (not (<= S1 0))
     (= V 8576))
      )
      (inv_main202 G1
             H
             E
             Y
             F1
             T
             A1
             K
             N2
             X1
             Q
             W
             M2
             R1
             S
             U1
             H2
             Z
             V1
             B2
             A2
             D2
             N1
             H1
             B1
             I
             C1
             O1
             N
             D
             V
             T1
             Q1
             K1
             G2
             W1
             C2
             P
             P1
             S1
             R
             F
             K2
             L2
             L1
             L
             E2
             F2
             G
             J1
             B
             J
             C
             D1
             M
             O
             X
             A
             I1
             J2
             Y1
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) ) 
    (=>
      (and
        (inv_main258 W
             S1
             S
             K1
             I
             I2
             U1
             T
             B2
             J1
             Z1
             P
             C2
             O1
             C
             K2
             P2
             I1
             D1
             D
             O
             B
             M1
             E1
             L
             D2
             E
             L1
             U
             R1
             L2
             H1
             Y
             F2
             O2
             Q1
             Z
             Y1
             E2
             G1
             M
             N1
             F1
             A1
             A
             C1
             W1
             R
             K
             G
             A2
             N
             H
             H2
             B1
             F
             G2
             V
             M2
             X1
             P1
             Q)
        (and (= J2 1)
     (= V1 1)
     (= T1 8496)
     (= B1 0)
     (= X 0)
     (<= 0 M2)
     (<= 0 G2)
     (<= 0 X1)
     (<= 0 Q1)
     (<= 0 Z)
     (<= 0 V)
     (<= 0 Q)
     (<= 0 O2)
     (not (<= J 0))
     (= N2 0))
      )
      (inv_main202 W
             S1
             S
             K1
             I
             T1
             U1
             T
             B2
             J1
             X
             P
             C2
             O1
             C
             N2
             P2
             I1
             D1
             D
             O
             B
             M1
             E1
             L
             D2
             E
             L1
             U
             R1
             L2
             H1
             Y
             F2
             O2
             Q1
             Z
             Y1
             E2
             J
             M
             N1
             F1
             J2
             A
             C1
             W1
             R
             K
             G
             A2
             N
             H
             H2
             V1
             F
             G2
             V
             M2
             X1
             P1
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) ) 
    (=>
      (and
        (inv_main258 H2
             G
             V
             I2
             L2
             T
             F
             K1
             K2
             L1
             U1
             O1
             S1
             F2
             L
             C2
             E
             D1
             E1
             Q
             C
             A1
             M
             H1
             X
             B2
             Q1
             N1
             W1
             A
             P
             N
             F1
             I
             P1
             O
             I1
             D2
             T1
             C1
             S
             A2
             R
             M2
             X1
             M1
             D
             Y
             B1
             J2
             W
             Z1
             K
             H
             E2
             Y1
             J
             B
             O2
             G1
             V1
             U)
        (and (not (= E2 0))
     (= J1 0)
     (= Z 1)
     (= N2 0)
     (<= 0 B)
     (<= 0 P1)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 U)
     (<= 0 O)
     (<= 0 J)
     (<= 0 O2)
     (not (<= R1 0))
     (= G2 8496))
      )
      (inv_main202 H2
             G
             V
             I2
             L2
             G2
             F
             K1
             K2
             L1
             J1
             O1
             S1
             F2
             L
             N2
             E
             D1
             E1
             Q
             C
             A1
             M
             H1
             X
             B2
             Q1
             N1
             W1
             A
             P
             N
             F1
             I
             P1
             O
             I1
             D2
             T1
             R1
             S
             A2
             R
             Z
             X1
             M1
             D
             Y
             B1
             J2
             W
             Z1
             K
             H
             E2
             Y1
             J
             B
             O2
             G1
             V1
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main275 Z1
             E2
             V
             Q
             C1
             Y
             S
             R1
             S1
             U
             M
             J2
             Z
             G
             F
             D2
             H1
             X1
             L1
             C
             L
             P
             N1
             X
             R
             O1
             H
             J
             O
             D
             F1
             K1
             W
             Y1
             G2
             K2
             A2
             V1
             B2
             B1
             L2
             P1
             E
             A
             E1
             T
             I2
             A1
             M1
             Q1
             J1
             K
             B
             W1
             C2
             T1
             I1
             I
             H2
             D1
             N
             G1)
        (and (= F2 0)
     (= U1 8656)
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 D1)
     (<= 0 I)
     (<= 0 K2)
     (not (<= B1 0))
     (not (= J2 0)))
      )
      (inv_main202 Z1
             E2
             V
             Q
             C1
             U1
             S
             R1
             S1
             U
             F2
             J2
             Z
             G
             F
             D2
             H1
             X1
             L1
             C
             L
             P
             N1
             X
             R
             O1
             H
             J
             O
             D
             F1
             K1
             W
             Y1
             G2
             K2
             A2
             V1
             B2
             B1
             L2
             P1
             E
             A
             E1
             T
             I2
             A1
             M1
             Q1
             J1
             K
             B
             W1
             C2
             T1
             I1
             I
             H2
             D1
             N
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main275 H
             D2
             E2
             C
             B1
             U1
             A
             H1
             Z
             W1
             F
             R
             G
             C2
             K1
             F1
             V1
             W
             D
             J2
             L
             X1
             D1
             U
             J1
             N1
             X
             Y1
             T
             L1
             E
             M
             P
             O1
             V
             E1
             P1
             R1
             A2
             I
             B
             G1
             Y
             C1
             A1
             N
             J
             O
             K2
             G2
             F2
             Q1
             B2
             S1
             Q
             K
             S
             I1
             H2
             Z1
             I2
             M1)
        (and (= R 0)
     (= L2 8512)
     (<= 0 H2)
     (<= 0 Z1)
     (<= 0 P1)
     (<= 0 M1)
     (<= 0 I1)
     (<= 0 E1)
     (<= 0 V)
     (<= 0 S)
     (not (<= I 0))
     (= T1 0))
      )
      (inv_main202 H
             D2
             E2
             C
             B1
             L2
             A
             H1
             Z
             W1
             T1
             R
             G
             C2
             K1
             F1
             V1
             W
             D
             J2
             L
             X1
             D1
             U
             J1
             N1
             X
             Y1
             T
             L1
             E
             M
             P
             O1
             V
             E1
             P1
             R1
             A2
             I
             B
             G1
             Y
             C1
             A1
             N
             J
             O
             K2
             G2
             F2
             Q1
             B2
             S1
             Q
             K
             S
             I1
             H2
             Z1
             I2
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main286 R
             Y
             M1
             Y1
             K1
             F1
             F
             J2
             V1
             U1
             Q
             E2
             X
             I1
             B1
             H1
             F2
             E
             P
             P1
             Z
             A1
             D1
             S
             O1
             T
             G2
             A
             C1
             L
             K
             G1
             B
             R1
             D
             O
             I
             W1
             L2
             H
             L1
             J
             I2
             S1
             N1
             K2
             M
             G
             A2
             C2
             D2
             B2
             N
             E1
             H2
             Q1
             X1
             V
             W
             C
             M2
             Z1)
        (and (= J1 0)
     (= U 1)
     (not (= L (- 256)))
     (<= 0 C)
     (<= 0 Z1)
     (<= 0 X1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 O)
     (<= 0 I)
     (<= 0 D)
     (= T1 8528)
     (= v_65 L))
      )
      (inv_main202 R
             Y
             M1
             Y1
             K1
             T1
             F
             J2
             V1
             U1
             J1
             E2
             X
             I1
             B1
             H1
             F2
             E
             P
             P1
             Z
             A1
             D1
             S
             O1
             T
             G2
             A
             C1
             L
             K
             G1
             B
             R1
             D
             O
             I
             W1
             L2
             H
             L1
             J
             U
             S1
             N1
             K2
             M
             G
             A2
             C2
             D2
             B2
             N
             E1
             H2
             Q1
             v_65
             V
             W
             C
             M2
             Z1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main286 A2
             L
             W1
             V1
             K
             O
             P
             U
             X
             H1
             B1
             J2
             G1
             L1
             B2
             E2
             O1
             R1
             H2
             N1
             E
             L2
             F1
             F
             D
             U1
             R
             G
             I
             M1
             N
             K1
             C
             T1
             C1
             I2
             M
             W
             B
             K2
             J1
             S
             S1
             Z1
             Q
             X1
             D2
             Q1
             V
             J
             G2
             C2
             H
             A
             I1
             E1
             N2
             M2
             D1
             F2
             P1
             Z)
        (and (= M1 (- 256))
     (= I1 2)
     (= A1 8528)
     (= T 0)
     (<= 0 I2)
     (<= 0 F2)
     (<= 0 D1)
     (<= 0 C1)
     (<= 0 Z)
     (<= 0 M)
     (<= 0 N2)
     (<= 0 M2)
     (not (<= Y 0))
     (= Y1 3)
     (= v_66 M1))
      )
      (inv_main202 A2
             L
             W1
             V1
             K
             A1
             P
             U
             X
             H1
             T
             J2
             G1
             L1
             B2
             E2
             O1
             R1
             H2
             N1
             E
             L2
             F1
             F
             D
             U1
             R
             G
             I
             M1
             N
             K1
             C
             T1
             C1
             I2
             M
             W
             B
             Y
             J1
             S
             S1
             Z1
             Q
             X1
             D2
             Q1
             V
             J
             G2
             C2
             H
             A
             Y1
             E1
             v_66
             M2
             D1
             F2
             P1
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main286 E2
             V1
             Y
             H1
             H2
             K2
             E
             H
             S
             J1
             Q1
             F2
             Z1
             C
             R1
             B2
             B1
             G1
             A
             N1
             A2
             M2
             R
             X1
             O
             W1
             N
             T
             E1
             D2
             V
             A1
             F1
             I2
             D
             D1
             T1
             J2
             C2
             P
             L1
             Y1
             Q
             S1
             I1
             B
             I
             Z
             L
             C1
             J
             M1
             M
             P1
             U1
             L2
             K1
             G2
             W
             G
             K
             X)
        (and (not (= U1 2))
     (= O1 0)
     (= F 8528)
     (<= 0 G2)
     (<= 0 T1)
     (<= 0 K1)
     (<= 0 D1)
     (<= 0 X)
     (<= 0 W)
     (<= 0 G)
     (<= 0 D)
     (not (<= U 0))
     (= D2 (- 256))
     (= v_65 D2))
      )
      (inv_main202 E2
             V1
             Y
             H1
             H2
             F
             E
             H
             S
             J1
             O1
             F2
             Z1
             C
             R1
             B2
             B1
             G1
             A
             N1
             A2
             M2
             R
             X1
             O
             W1
             N
             T
             E1
             D2
             V
             A1
             F1
             I2
             D
             D1
             T1
             J2
             C2
             U
             L1
             Y1
             Q
             S1
             I1
             B
             I
             Z
             L
             C1
             J
             M1
             M
             P1
             U1
             L2
             v_65
             G2
             W
             G
             K
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 B2
             Y1
             Q
             X
             E1
             B1
             E2
             V1
             D1
             A2
             J2
             S
             N
             V
             K
             X1
             T1
             C2
             P1
             G2
             C
             M1
             O1
             F
             Z
             H1
             F1
             A
             C1
             O
             U1
             Z1
             T
             D2
             L
             N1
             G1
             Q1
             L1
             A1
             H
             S1
             K1
             R
             H2
             J1
             R1
             U
             D
             I
             B
             E
             I1
             M
             P
             I2
             Y
             F2
             W1
             G
             J
             W)
        (and (not (= B1 8529))
     (not (= B1 8544))
     (not (= B1 8545))
     (not (= B1 8560))
     (not (= B1 8561))
     (= B1 8448)
     (not (= B1 8513))
     (not (= B1 12292))
     (not (= B1 16384))
     (not (= B1 8192))
     (not (= B1 24576))
     (not (= B1 8195))
     (not (= B1 8480))
     (not (= B1 8481))
     (not (= B1 8482))
     (not (= B1 8464))
     (not (= B1 8465))
     (not (= B1 8466))
     (not (= B1 8496))
     (not (= B1 8497))
     (not (= B1 8512))
     (not (<= 1 L1))
     (<= 0 F2)
     (<= 0 W1)
     (<= 0 N1)
     (<= 0 G1)
     (<= 0 Y)
     (<= 0 W)
     (<= 0 L)
     (<= 0 G)
     (not (= B1 8528))
     (= v_62 U1))
      )
      (inv_main202 B2
             Y1
             Q
             X
             E1
             U1
             E2
             V1
             D1
             A2
             J2
             S
             N
             V
             K
             X1
             T1
             C2
             P1
             G2
             C
             M1
             O1
             F
             Z
             H1
             F1
             A
             C1
             O
             v_62
             Z1
             T
             D2
             L
             N1
             G1
             Q1
             L1
             A1
             H
             B1
             K1
             R
             H2
             J1
             R1
             U
             D
             I
             B
             E
             I1
             M
             P
             I2
             Y
             F2
             W1
             G
             J
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main121 D2
             N
             U
             U1
             Q1
             G2
             F1
             O1
             V1
             M
             B2
             L1
             B1
             P
             D
             O
             T
             Y1
             G
             R1
             S
             I1
             J
             E
             X
             W
             S1
             C1
             F
             I
             H1
             P1
             V
             H
             N1
             Q
             M1
             A1
             Z1
             C2
             L
             W1
             B
             Y
             K
             X1
             Z
             D1
             C
             A2
             K2
             R
             E2
             G1
             A
             J2
             I2
             T1
             H2
             K1
             F2
             E1)
        (and (not (= G2 8529))
     (not (= G2 8544))
     (not (= G2 8545))
     (not (= G2 8560))
     (not (= G2 8561))
     (= G2 8448)
     (not (= G2 8513))
     (not (= G2 12292))
     (not (= G2 16384))
     (not (= G2 8192))
     (not (= G2 24576))
     (not (= G2 8195))
     (not (= G2 8480))
     (not (= G2 8481))
     (not (= G2 8482))
     (not (= G2 8464))
     (not (= G2 8465))
     (not (= G2 8466))
     (not (= G2 8496))
     (not (= G2 8497))
     (not (= G2 8512))
     (= J1 1)
     (<= 1 Z1)
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 T1)
     (<= 0 N1)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 E1)
     (<= 0 Q)
     (not (<= R 0))
     (not (= G2 8528))
     (= v_63 H1)
     (= v_64 R))
      )
      (inv_main202 D2
             N
             U
             U1
             Q1
             H1
             F1
             O1
             V1
             M
             B2
             L1
             J1
             P
             D
             O
             T
             Y1
             G
             R1
             S
             I1
             J
             E
             X
             W
             S1
             C1
             F
             I
             v_63
             P1
             V
             H
             N1
             Q
             M1
             A1
             R
             C2
             L
             G2
             B
             Y
             K
             X1
             Z
             D1
             C
             A2
             K2
             v_64
             E2
             G1
             A
             J2
             I2
             T1
             H2
             K1
             F2
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main393 B
             X
             K
             Z
             E2
             H
             J1
             E1
             U1
             J2
             B2
             Z1
             D
             E
             C1
             Q
             A1
             R1
             X1
             L1
             C
             I2
             H1
             Q1
             T
             V1
             H2
             I1
             L
             D1
             C2
             B1
             G1
             P1
             G2
             Y
             W1
             M1
             R
             K1
             J
             D2
             W
             S1
             N1
             G
             O1
             A2
             F1
             V
             S
             F2
             M
             P
             A
             K2
             O
             N
             Y1
             T1
             I
             F)
        (and (= U 8466)
     (<= 0 G2)
     (<= 0 Y1)
     (<= 0 W1)
     (<= 0 T1)
     (<= 0 Y)
     (<= 0 O)
     (<= 0 N)
     (<= 0 F)
     (not (<= K1 0))
     (= K1 2))
      )
      (inv_main202 B
             X
             K
             Z
             E2
             U
             J1
             E1
             U1
             J2
             B2
             Z1
             D
             E
             C1
             Q
             A1
             R1
             X1
             L1
             C
             I2
             H1
             Q1
             T
             V1
             H2
             I1
             L
             D1
             C2
             B1
             G1
             P1
             G2
             Y
             W1
             M1
             R
             K1
             J
             D2
             W
             S1
             N1
             G
             O1
             A2
             F1
             V
             S
             F2
             M
             P
             A
             K2
             O
             N
             Y1
             T1
             I
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main393 B2
             N2
             H2
             H
             Y
             I
             X
             C2
             L
             E1
             B1
             F1
             O1
             A1
             A
             D1
             W1
             K2
             P
             M
             T1
             G1
             K
             C
             M1
             T
             Z
             I1
             A2
             P1
             R1
             Z1
             S1
             U1
             M2
             Q
             X1
             J2
             E2
             C1
             G2
             U
             F2
             W
             O
             J1
             E
             L2
             I2
             N1
             J
             D
             H1
             N
             R
             Q1
             S
             D2
             V
             Y1
             G
             K1)
        (and (= L1 8592)
     (not (= C1 2))
     (= R 6)
     (= F 0)
     (<= 0 D2)
     (<= 0 Y1)
     (<= 0 X1)
     (<= 0 K1)
     (<= 0 V)
     (<= 0 S)
     (<= 0 Q)
     (<= 0 M2)
     (not (<= V1 0))
     (not (<= C1 0))
     (= B 7))
      )
      (inv_main202 B2
             N2
             H2
             H
             Y
             L1
             X
             C2
             L
             E1
             F
             F1
             O1
             A1
             A
             D1
             W1
             K2
             P
             M
             T1
             G1
             K
             C
             M1
             T
             Z
             I1
             A2
             P1
             R1
             Z1
             S1
             U1
             M2
             Q
             X1
             J2
             E2
             V1
             G2
             U
             F2
             W
             O
             J1
             E
             L2
             I2
             N1
             J
             D
             H1
             N
             B
             Q1
             S
             D2
             V
             Y1
             G
             K1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main393 F2
             V1
             M2
             K
             G
             G2
             M
             A1
             J2
             O1
             J1
             B2
             Y1
             F1
             R
             S1
             B1
             B
             G1
             C2
             C
             W1
             C1
             I
             K2
             K1
             T1
             A2
             P1
             Y
             X1
             Q1
             P
             X
             O
             I2
             D1
             H
             S
             N
             V
             R1
             H1
             A
             U
             W
             Q
             I1
             E2
             U1
             J
             H2
             D2
             L2
             Z1
             E1
             T
             D
             F
             E
             Z
             M1)
        (and (= L1 0)
     (not (= N 2))
     (= L 8592)
     (<= 0 I2)
     (<= 0 M1)
     (<= 0 D1)
     (<= 0 T)
     (<= 0 O)
     (<= 0 F)
     (<= 0 E)
     (<= 0 D)
     (not (<= N1 0))
     (not (<= N 0))
     (not (= Z1 6)))
      )
      (inv_main202 F2
             V1
             M2
             K
             G
             L
             M
             A1
             J2
             O1
             L1
             B2
             Y1
             F1
             R
             S1
             B1
             B
             G1
             C2
             C
             W1
             C1
             I
             K2
             K1
             T1
             A2
             P1
             Y
             X1
             Q1
             P
             X
             O
             I2
             D1
             H
             S
             N1
             V
             R1
             H1
             A
             U
             W
             Q
             I1
             E2
             U1
             J
             H2
             D2
             L2
             Z1
             E1
             T
             D
             F
             E
             Z
             M1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main439 O1
             R
             T1
             A
             W1
             U
             H
             Q
             W
             N1
             A2
             X1
             V1
             V
             D1
             I
             K
             J2
             Y
             I2
             G2
             Q1
             S1
             I1
             F1
             H2
             E1
             C2
             L2
             C
             G
             X
             M
             R1
             B2
             J
             Z1
             Z
             D2
             L
             S
             H1
             T
             F
             B1
             A1
             U1
             B
             C1
             K1
             F2
             K2
             M1
             Y1
             L1
             D
             G1
             J1
             O
             E
             N
             E2)
        (and (= P1 0)
     (= P 3)
     (<= 0 E2)
     (<= 0 B2)
     (<= 0 Z1)
     (<= 0 J1)
     (<= 0 G1)
     (<= 0 O)
     (<= 0 J)
     (<= 0 E)
     (not (<= L 0))
     (not (= X1 0)))
      )
      (inv_main202 O1
             R
             T1
             A
             W1
             P
             H
             Q
             W
             N1
             P1
             X1
             V1
             V
             D1
             I
             K
             J2
             Y
             I2
             G2
             Q1
             S1
             I1
             F1
             H2
             E1
             C2
             L2
             C
             G
             X
             M
             R1
             B2
             J
             Z1
             Z
             D2
             L
             S
             H1
             T
             F
             B1
             A1
             U1
             B
             C1
             K1
             F2
             K2
             M1
             Y1
             L1
             D
             G1
             J1
             O
             E
             N
             E2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main439 S1
             Q
             C
             V1
             K
             H1
             F2
             M
             J2
             W1
             I
             R1
             E1
             D
             Z1
             X
             X1
             S
             Q1
             H2
             W
             R
             H
             L2
             N1
             O1
             P1
             V
             F1
             J1
             N
             A1
             U1
             G
             I2
             P
             G1
             L
             T
             M1
             Z
             B2
             K2
             E2
             C1
             Y
             J
             B1
             Y1
             K1
             C2
             U
             B
             I1
             L1
             D1
             O
             A
             F
             G2
             T1
             A2)
        (and (= R1 0)
     (= E 8656)
     (<= 0 A)
     (<= 0 I2)
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 G1)
     (<= 0 P)
     (<= 0 O)
     (<= 0 F)
     (not (<= M1 0))
     (= D2 0))
      )
      (inv_main202 S1
             Q
             C
             V1
             K
             E
             F2
             M
             J2
             W1
             D2
             R1
             E1
             D
             Z1
             X
             X1
             S
             Q1
             H2
             W
             R
             H
             L2
             N1
             O1
             P1
             V
             F1
             J1
             N
             A1
             U1
             G
             I2
             P
             G1
             L
             T
             M1
             Z
             B2
             K2
             E2
             C1
             Y
             J
             B1
             Y1
             K1
             C2
             U
             B
             I1
             L1
             D1
             O
             A
             F
             G2
             T1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main488 G2
             B2
             I2
             C1
             L1
             M
             G1
             I
             Z
             L2
             K
             B1
             K1
             H1
             D2
             W1
             X
             P
             E
             E2
             V1
             U1
             Y
             X1
             J2
             F
             E1
             U
             F2
             S1
             O
             A1
             I1
             B
             L
             R1
             F1
             W
             P1
             D
             N1
             R
             M2
             V
             M1
             J
             A
             Z1
             H
             S
             Y1
             T
             C
             K2
             D1
             Q1
             A2
             T1
             O1
             C2
             N
             H2)
        (and (not (= B1 0))
     (= Q 0)
     (= G 8640)
     (<= 0 H2)
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 O1)
     (<= 0 F1)
     (<= 0 L)
     (not (<= D 0))
     (= J1 8448))
      )
      (inv_main202 G2
             B2
             I2
             C1
             L1
             J1
             G1
             I
             Z
             L2
             Q
             B1
             K1
             H1
             D2
             W1
             X
             P
             E
             E2
             V1
             U1
             Y
             X1
             J2
             F
             E1
             U
             F2
             S1
             G
             A1
             I1
             B
             L
             R1
             F1
             W
             P1
             D
             N1
             R
             M2
             V
             M1
             J
             A
             Z1
             H
             S
             Y1
             T
             C
             K2
             D1
             Q1
             A2
             T1
             O1
             C2
             N
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main488 C
             H2
             G
             Y1
             F2
             W
             F1
             I
             X1
             B
             V1
             M2
             J1
             I1
             H
             S
             P1
             Q1
             S1
             O1
             E2
             R1
             W1
             O
             A1
             Z
             Y
             X
             F
             L
             N1
             V
             C2
             A
             J
             T
             E1
             D1
             Z1
             N
             G2
             K2
             I2
             L2
             R
             T1
             G1
             J2
             H1
             C1
             U
             B1
             L1
             A2
             D2
             K1
             K
             Q
             P
             U1
             M1
             M)
        (and (= E 3)
     (= D 0)
     (= M2 0)
     (<= 0 U1)
     (<= 0 E1)
     (<= 0 T)
     (<= 0 Q)
     (<= 0 P)
     (<= 0 M)
     (<= 0 K)
     (<= 0 J)
     (not (<= N 0))
     (= B2 8448))
      )
      (inv_main202 C
             H2
             G
             Y1
             F2
             B2
             F1
             I
             X1
             B
             D
             M2
             J1
             I1
             H
             S
             P1
             Q1
             S1
             O1
             E2
             R1
             W1
             O
             A1
             Z
             Y
             X
             F
             L
             E
             V
             C2
             A
             J
             T
             E1
             D1
             Z1
             N
             G2
             K2
             I2
             L2
             R
             T1
             G1
             J2
             H1
             C1
             U
             B1
             L1
             A2
             D2
             K1
             K
             Q
             P
             U1
             M1
             M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main304 I2
             T1
             V
             D2
             U1
             C1
             P1
             G2
             D
             P
             A2
             L
             W
             Z1
             K
             E2
             E
             A
             M2
             O1
             E1
             H1
             I
             H2
             I1
             F2
             Y
             K1
             M1
             B2
             R1
             A1
             J1
             Q1
             Y1
             J
             R
             F1
             C2
             S1
             O
             K2
             D1
             N1
             S
             B
             G1
             H
             X1
             U
             T
             J2
             C
             W1
             V1
             L2
             L1
             Z
             M
             N
             Q
             B1)
        (and (= Y1 (- 1))
     (= K1 0)
     (= X 1)
     (= G 8544)
     (= F 0)
     (<= 0 Y1)
     (<= 0 L1)
     (<= 0 B1)
     (<= 0 Z)
     (<= 0 R)
     (<= 0 N)
     (<= 0 M)
     (<= 0 J)
     (= Y1 (- 30)))
      )
      (inv_main202 I2
             T1
             V
             D2
             U1
             G
             P1
             G2
             D
             P
             F
             L
             W
             Z1
             K
             E2
             E
             A
             M2
             O1
             E1
             H1
             I
             H2
             I1
             F2
             Y
             K1
             M1
             B2
             R1
             A1
             J1
             Q1
             Y1
             J
             R
             F1
             C2
             S1
             O
             K2
             X
             N1
             S
             B
             G1
             H
             X1
             U
             T
             J2
             C
             W1
             V1
             L2
             L1
             Z
             M
             N
             Q
             B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main304 C2
             V1
             Y1
             W1
             V
             D
             E
             A2
             J1
             H2
             T
             R
             S
             E1
             D2
             N1
             M1
             L1
             I1
             M
             F2
             J
             G1
             Q
             G
             A1
             D1
             L
             K
             H1
             M2
             W
             E2
             F1
             L2
             U
             Z1
             Y
             J2
             N
             C1
             C
             G2
             B
             T1
             K1
             S1
             B1
             X
             K2
             Z
             I
             A
             R1
             U1
             P
             B2
             F
             P1
             H
             Q1
             O1)
        (and (not (= F2 0))
     (= X1 0)
     (= W (- 2))
     (= O 1)
     (= L 0)
     (= L2 (- 30))
     (not (= L2 (- 1)))
     (<= 0 B2)
     (<= 0 Z1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 U)
     (<= 0 H)
     (<= 0 F)
     (<= 0 L2)
     (= I2 8544)
     (= v_65 W))
      )
      (inv_main202 C2
             V1
             Y1
             W1
             V
             I2
             E
             A2
             J1
             H2
             X1
             R
             S
             E1
             D2
             N1
             M1
             L1
             I1
             M
             F2
             J
             G1
             Q
             G
             A1
             D1
             L
             K
             H1
             M2
             W
             E2
             F1
             L2
             U
             Z1
             Y
             J2
             N
             C1
             C
             O
             B
             T1
             K1
             S1
             B1
             X
             K2
             Z
             I
             A
             R1
             U1
             P
             B2
             F
             v_65
             H
             Q1
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main304 B1
             X1
             G2
             H1
             V1
             W
             B
             C1
             D2
             C2
             B2
             F1
             Z
             C
             R
             F2
             S1
             S
             W1
             U
             P1
             G1
             I2
             Z1
             O
             T
             X
             Y1
             N
             J1
             M2
             J2
             I1
             L
             I
             T1
             H
             J
             K2
             E1
             M
             A
             D1
             N1
             L1
             F
             L2
             Q
             G
             U1
             Y
             A1
             A2
             M1
             E
             K1
             Q1
             P
             O2
             V
             H2
             O1)
        (and (= D 512)
     (not (= J2 (- 2)))
     (not (= J2 (- 4)))
     (= E2 1)
     (= Y1 0)
     (not (= P1 0))
     (= K 8544)
     (= I (- 30))
     (not (= I (- 1)))
     (= N2 0)
     (not (>= U1 65))
     (<= 0 T1)
     (<= 0 Q1)
     (<= 0 O1)
     (<= 0 V)
     (<= 0 P)
     (<= 0 I)
     (<= 0 H)
     (<= 0 O2)
     (= (+ R1 (* (- 8) U1)) 0)
     (= v_67 J2)
     (= v_68 J2))
      )
      (inv_main202 B1
             X1
             G2
             H1
             V1
             K
             B
             C1
             D2
             C2
             N2
             F1
             Z
             C
             R
             F2
             S1
             S
             W1
             U
             P1
             G1
             I2
             Z1
             O
             T
             X
             Y1
             N
             J1
             M2
             J2
             I1
             L
             I
             T1
             H
             J
             K2
             E1
             M
             A
             E2
             N1
             L1
             F
             L2
             Q
             G
             U1
             D
             A1
             A2
             M1
             E
             K1
             Q1
             P
             v_67
             v_68
             R1
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main304 L
             K1
             W
             X1
             G1
             V1
             B1
             D1
             E
             X
             D
             T
             Y
             M2
             U
             Z1
             J2
             L1
             B
             D2
             L2
             H1
             M
             K2
             I1
             H2
             U1
             J
             A
             K
             N2
             C2
             O
             A1
             I
             Y1
             P1
             M1
             J1
             H
             A2
             F2
             E1
             O2
             Q
             G2
             G
             B2
             F1
             P
             N1
             V
             C
             S
             T1
             Z
             I2
             W1
             R1
             C1
             Q1
             N)
        (and (not (= L2 0))
     (= E2 1024)
     (not (= C2 (- 2)))
     (= C2 (- 4))
     (= S1 8544)
     (= R 1)
     (= J 0)
     (= I (- 30))
     (not (= I (- 1)))
     (= F 0)
     (not (>= P 129))
     (<= 0 I2)
     (<= 0 Y1)
     (<= 0 W1)
     (<= 0 R1)
     (<= 0 P1)
     (<= 0 C1)
     (<= 0 N)
     (<= 0 I)
     (= (+ O1 (* (- 8) P)) 0)
     (= v_67 C2)
     (= v_68 C2))
      )
      (inv_main202 L
             K1
             W
             X1
             G1
             S1
             B1
             D1
             E
             X
             F
             T
             Y
             M2
             U
             Z1
             J2
             L1
             B
             D2
             L2
             H1
             M
             K2
             I1
             H2
             U1
             J
             A
             K
             N2
             C2
             O
             A1
             I
             Y1
             P1
             M1
             J1
             H
             A2
             F2
             R
             O2
             Q
             G2
             G
             B2
             F1
             P
             E2
             V
             C
             S
             T1
             Z
             I2
             W1
             v_67
             v_68
             O1
             N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main325 U
             X1
             N
             N1
             A2
             D1
             Z1
             G2
             V1
             Z
             M2
             U1
             J1
             F
             A
             B
             K
             R
             E
             Q1
             N2
             I2
             B2
             P1
             L2
             S
             V
             C
             L1
             K2
             Q
             Y
             J
             R1
             I1
             K1
             G1
             H2
             B1
             A1
             T
             M1
             J2
             H
             Y1
             M
             W
             C2
             H1
             D2
             P
             F1
             L
             T1
             I
             F2
             W1
             S1
             E2
             G
             O
             O1)
        (and (= C1 8544)
     (= X 0)
     (= I 3)
     (<= 0 E2)
     (<= 0 W1)
     (<= 0 S1)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 I1)
     (<= 0 G1)
     (<= 0 G)
     (not (<= E1 0))
     (= D 4))
      )
      (inv_main202 U
             X1
             N
             N1
             A2
             C1
             Z1
             G2
             V1
             Z
             X
             U1
             J1
             F
             A
             B
             K
             R
             E
             Q1
             N2
             I2
             B2
             P1
             L2
             S
             V
             C
             L1
             K2
             Q
             Y
             J
             R1
             I1
             K1
             G1
             H2
             B1
             E1
             T
             M1
             J2
             H
             Y1
             M
             W
             C2
             H1
             D2
             P
             F1
             L
             T1
             D
             F2
             W1
             S1
             E2
             G
             O
             O1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main325 V
             D2
             Y
             G2
             M
             R1
             U
             V1
             H2
             L
             H
             W
             E
             M1
             Z1
             P1
             L1
             D1
             I2
             R
             X
             T
             O1
             W1
             I1
             B
             A
             G
             J2
             J1
             B1
             F1
             K2
             Y1
             N
             A1
             D
             O
             G1
             E2
             T1
             J
             C1
             S1
             Q
             N1
             A2
             X1
             C
             L2
             Z
             M2
             U1
             F
             B2
             C2
             E1
             K
             F2
             H1
             Q1
             K1)
        (and (= P 8544)
     (= I 0)
     (<= 0 F2)
     (<= 0 K1)
     (<= 0 H1)
     (<= 0 E1)
     (<= 0 A1)
     (<= 0 N)
     (<= 0 K)
     (<= 0 D)
     (not (<= S 0))
     (not (= B2 3)))
      )
      (inv_main202 V
             D2
             Y
             G2
             M
             P
             U
             V1
             H2
             L
             I
             W
             E
             M1
             Z1
             P1
             L1
             D1
             I2
             R
             X
             T
             O1
             W1
             I1
             B
             A
             G
             J2
             J1
             B1
             F1
             K2
             Y1
             N
             A1
             D
             O
             G1
             S
             T1
             J
             C1
             S1
             Q
             N1
             A2
             X1
             C
             L2
             Z
             M2
             U1
             F
             B2
             C2
             E1
             K
             F2
             H1
             Q1
             K1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main337 A1
             Z1
             T1
             L
             G2
             P1
             U
             Q
             V
             E
             J2
             X
             I
             Y1
             B
             I2
             H2
             F
             X1
             F2
             C1
             M
             Z
             N1
             C
             L1
             M2
             V1
             Q1
             O1
             W1
             T
             K2
             G1
             J1
             P
             H
             A2
             D
             L2
             D1
             R
             J
             B1
             E2
             K
             Y
             N
             F1
             S
             K1
             W
             C2
             B2
             O
             E1
             M1
             R1
             I1
             A
             D2
             S1)
        (and (not (= X1 (- 4)))
     (not (= X1 (- 1)))
     (= U1 1)
     (= H1 8560)
     (= G 0)
     (<= 0 A)
     (<= 0 S1)
     (<= 0 R1)
     (<= 0 M1)
     (<= 0 J1)
     (<= 0 I1)
     (<= 0 P)
     (<= 0 H)
     (not (= F2 0)))
      )
      (inv_main202 A1
             Z1
             T1
             L
             G2
             H1
             U
             Q
             V
             E
             J2
             X
             I
             Y1
             B
             I2
             H2
             F
             X1
             F2
             C1
             M
             Z
             N1
             C
             G
             M2
             V1
             Q1
             O1
             W1
             T
             K2
             G1
             J1
             P
             H
             A2
             D
             L2
             D1
             R
             U1
             B1
             E2
             K
             Y
             N
             F1
             S
             K1
             W
             C2
             B2
             O
             E1
             M1
             R1
             I1
             A
             D2
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main343 F
             W
             D1
             B
             R1
             M1
             S
             G2
             X1
             L
             L1
             J
             Z1
             D2
             H2
             W1
             Y1
             O1
             P1
             E
             Q
             J2
             U1
             C2
             K2
             Z
             N1
             J1
             I
             X
             N
             B1
             C1
             H
             G
             M2
             E1
             K1
             Y
             Q1
             D
             A
             P
             V
             M
             F1
             C
             T1
             I1
             B2
             S1
             T
             F2
             H1
             V1
             K
             L2
             R
             G1
             U
             A1
             A2)
        (and (= E2 1)
     (= P1 (- 2))
     (not (= X (- 256)))
     (= O 0)
     (<= 0 A2)
     (<= 0 G1)
     (<= 0 E1)
     (<= 0 U)
     (<= 0 R)
     (<= 0 G)
     (<= 0 M2)
     (<= 0 L2)
     (= I2 8560)
     (= v_65 X))
      )
      (inv_main202 F
             W
             D1
             B
             R1
             I2
             S
             G2
             X1
             L
             L1
             J
             Z1
             D2
             H2
             W1
             Y1
             O1
             P1
             E
             Q
             J2
             U1
             C2
             K2
             O
             N1
             J1
             I
             X
             N
             B1
             C1
             H
             G
             M2
             E1
             K1
             Y
             Q1
             D
             A
             E2
             V
             M
             F1
             C
             T1
             I1
             B2
             S1
             T
             F2
             H1
             V1
             K
             L2
             R
             G1
             U
             A1
             v_65)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main337 O1
             V1
             L2
             W
             I
             K2
             H
             E1
             F1
             L1
             W1
             A1
             V
             M1
             K1
             C
             L
             G2
             Y1
             G1
             I1
             I2
             Z
             Y
             U1
             C2
             B1
             H1
             O
             J2
             Q1
             P
             B
             A
             D2
             X
             N1
             Z1
             J1
             N
             M
             X1
             M2
             C1
             K
             F2
             B2
             D
             P1
             E2
             J
             R
             G
             F
             E
             S
             R1
             H2
             D1
             T
             Q
             T1)
        (and (= Y1 (- 1))
     (= S1 0)
     (= U 1)
     (<= 0 H2)
     (<= 0 D2)
     (<= 0 T1)
     (<= 0 R1)
     (<= 0 N1)
     (<= 0 D1)
     (<= 0 X)
     (<= 0 T)
     (= A2 8560))
      )
      (inv_main202 O1
             V1
             L2
             W
             I
             A2
             H
             E1
             F1
             L1
             W1
             A1
             V
             M1
             K1
             C
             L
             G2
             Y1
             G1
             I1
             I2
             Z
             Y
             U1
             S1
             B1
             H1
             O
             J2
             Q1
             P
             B
             A
             D2
             X
             N1
             Z1
             J1
             N
             M
             X1
             U
             C1
             K
             F2
             B2
             D
             P1
             E2
             J
             R
             G
             F
             E
             S
             R1
             H2
             D1
             T
             Q
             T1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main343 H
             G1
             I
             I2
             Z1
             E
             D
             R1
             P2
             L
             K1
             W1
             X
             T
             N2
             B2
             P
             A
             J
             U
             X1
             O
             V1
             F
             G
             H2
             B
             T1
             N
             Q
             L1
             Y1
             C2
             O1
             H1
             S1
             J2
             F2
             M1
             A1
             Y
             G2
             J1
             D2
             C1
             P1
             A2
             V
             E2
             U1
             M
             M2
             I1
             B1
             S
             K2
             C
             Q1
             L2
             K
             R
             O2)
        (and (= F1 1)
     (= E1 8448)
     (= D1 5)
     (= Z 8576)
     (= S 4)
     (= Q (- 256))
     (<= 0 C)
     (<= 0 L2)
     (<= 0 J2)
     (<= 0 S1)
     (<= 0 Q1)
     (<= 0 H1)
     (<= 0 K)
     (<= 0 O2)
     (not (<= W 0))
     (= N1 0)
     (= v_68 Q))
      )
      (inv_main202 H
             G1
             I
             I2
             Z1
             E1
             D
             R1
             P2
             L
             N1
             W1
             X
             T
             N2
             B2
             P
             A
             J
             U
             X1
             O
             V1
             F
             G
             F1
             B
             T1
             N
             Q
             Z
             Y1
             C2
             O1
             H1
             S1
             J2
             F2
             M1
             W
             Y
             G2
             J1
             D2
             C1
             P1
             A2
             V
             E2
             U1
             M
             M2
             I1
             B1
             D1
             K2
             C
             Q1
             L2
             K
             R
             v_68)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main343 M
             T
             G1
             C
             C2
             X1
             O
             W
             U1
             R
             Q1
             O1
             J2
             H1
             A1
             Z
             I
             F
             V
             H
             B
             Y
             J
             K1
             H2
             N1
             M2
             L1
             Q
             K
             L2
             D
             B1
             X
             T1
             N2
             E1
             S1
             D1
             D2
             M1
             N
             A
             E
             I1
             G2
             A2
             G
             K2
             W1
             F2
             U
             J1
             S
             R1
             F1
             B2
             Y1
             V1
             O2
             I2
             L)
        (and (= Z1 0)
     (not (= R1 4))
     (= P1 8448)
     (= C1 1)
     (= K (- 256))
     (<= 0 B2)
     (<= 0 Y1)
     (<= 0 V1)
     (<= 0 T1)
     (<= 0 E1)
     (<= 0 L)
     (<= 0 O2)
     (<= 0 N2)
     (not (<= P 0))
     (= E2 8576)
     (= v_67 K))
      )
      (inv_main202 M
             T
             G1
             C
             C2
             P1
             O
             W
             U1
             R
             Z1
             O1
             J2
             H1
             A1
             Z
             I
             F
             V
             H
             B
             Y
             J
             K1
             H2
             C1
             M2
             L1
             Q
             K
             E2
             D
             B1
             X
             T1
             N2
             E1
             S1
             D1
             P
             M1
             N
             A
             E
             I1
             G2
             A2
             G
             K2
             W1
             F2
             U
             J1
             S
             R1
             F1
             B2
             Y1
             V1
             O2
             I2
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (P2 Int) (v_68 Int) ) 
    (=>
      (and
        (inv_main343 H1
             M2
             O1
             S
             K1
             L
             L2
             X
             F
             Q
             G2
             J
             Z1
             V
             E
             S1
             C2
             N2
             I1
             M1
             H
             A
             X1
             M
             H2
             T1
             L1
             P
             A1
             O
             I
             B2
             F1
             Y1
             J2
             E2
             W
             D
             B1
             R1
             D2
             K
             F2
             N
             G
             Z
             E1
             U
             G1
             T
             I2
             B
             J1
             P2
             D1
             V1
             K2
             P1
             C1
             Q1
             R
             O2)
        (and (= A2 8448)
     (= W1 5)
     (= N1 8576)
     (not (= I1 (- 2)))
     (= D1 4)
     (= Y 1)
     (not (= O (- 256)))
     (<= 0 K2)
     (<= 0 J2)
     (<= 0 E2)
     (<= 0 Q1)
     (<= 0 P1)
     (<= 0 C1)
     (<= 0 W)
     (<= 0 O2)
     (not (<= U1 0))
     (= C 0)
     (= v_68 O))
      )
      (inv_main202 H1
             M2
             O1
             S
             K1
             A2
             L2
             X
             F
             Q
             C
             J
             Z1
             V
             E
             S1
             C2
             N2
             I1
             M1
             H
             A
             X1
             M
             H2
             Y
             L1
             P
             A1
             O
             N1
             B2
             F1
             Y1
             J2
             E2
             W
             D
             B1
             U1
             D2
             K
             F2
             N
             G
             Z
             E1
             U
             G1
             T
             I2
             B
             J1
             P2
             W1
             V1
             K2
             P1
             C1
             Q1
             R
             v_68)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (O2 Int) (v_67 Int) ) 
    (=>
      (and
        (inv_main343 B1
             J2
             R1
             Z1
             Q
             U
             S1
             A2
             F1
             E
             D2
             C1
             H
             V
             L1
             D
             T1
             Y
             H1
             M1
             G
             K
             B2
             X
             T
             I
             E1
             O
             N1
             O1
             L
             Q1
             K2
             O2
             M2
             J1
             A1
             Y1
             U1
             C
             X1
             P
             V1
             J
             M
             N
             I1
             W1
             H2
             E2
             G1
             F2
             R
             F
             C2
             S
             B
             D1
             N2
             K1
             A
             P1)
        (and (= I2 8448)
     (= G2 0)
     (not (= C2 4))
     (not (= O1 (- 256)))
     (not (= H1 (- 2)))
     (= Z 8576)
     (<= 0 B)
     (<= 0 M2)
     (<= 0 P1)
     (<= 0 K1)
     (<= 0 J1)
     (<= 0 D1)
     (<= 0 A1)
     (<= 0 N2)
     (not (<= W 0))
     (= L2 1)
     (= v_67 O1))
      )
      (inv_main202 B1
             J2
             R1
             Z1
             Q
             I2
             S1
             A2
             F1
             E
             G2
             C1
             H
             V
             L1
             D
             T1
             Y
             H1
             M1
             G
             K
             B2
             X
             T
             L2
             E1
             O
             N1
             O1
             Z
             Q1
             K2
             O2
             M2
             J1
             A1
             Y1
             U1
             W
             X1
             P
             V1
             J
             M
             N
             I1
             W1
             H2
             E2
             G1
             F2
             R
             F
             C2
             S
             B
             D1
             N2
             K1
             A
             v_67)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main121 H
             T
             S1
             B
             X
             Z
             X1
             L
             J2
             W1
             R
             C2
             F2
             H1
             P
             Z1
             V
             U1
             S
             N2
             O1
             K1
             I
             E1
             U
             O
             N
             J1
             M
             G2
             C1
             K2
             L2
             F1
             B2
             D1
             H2
             D2
             E
             G1
             Y1
             W
             Q1
             M1
             R1
             G
             F
             I2
             E2
             I1
             M2
             A2
             L1
             T1
             V1
             B1
             K
             Y
             D
             A
             P1
             Q)
        (and (= V1 7)
     (= A1 0)
     (not (= Z 8528))
     (not (= Z 8529))
     (not (= Z 8544))
     (not (= Z 8545))
     (not (= Z 8560))
     (not (= Z 8561))
     (not (= Z 8448))
     (not (= Z 8576))
     (not (= Z 8577))
     (= Z 8592)
     (not (= Z 8513))
     (not (= Z 12292))
     (not (= Z 16384))
     (not (= Z 8192))
     (not (= Z 24576))
     (not (= Z 8195))
     (not (= Z 8480))
     (not (= Z 8481))
     (not (= Z 8482))
     (not (= Z 8464))
     (not (= Z 8465))
     (not (= Z 8466))
     (not (= Z 8496))
     (not (= Z 8497))
     (not (= Z 8512))
     (= J 8)
     (<= 0 A)
     (<= 0 D)
     (<= 0 H2)
     (<= 0 B2)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 Q)
     (<= 0 K)
     (not (<= N1 0))
     (= C 8608))
      )
      (inv_main202 H
             T
             S1
             B
             X
             C
             X1
             L
             J2
             W1
             A1
             C2
             F2
             H1
             P
             Z1
             V
             U1
             S
             N2
             O1
             K1
             I
             E1
             U
             O
             N
             J1
             M
             G2
             C1
             K2
             L2
             F1
             B2
             D1
             H2
             D2
             E
             N1
             Y1
             Z
             Q1
             M1
             R1
             G
             F
             I2
             E2
             I1
             M2
             A2
             L1
             T1
             J
             B1
             K
             Y
             D
             A
             P1
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main121 M1
             M
             G
             Z1
             B1
             L1
             D
             H1
             C
             E
             R
             O1
             G2
             I
             H2
             D2
             L
             C1
             Q1
             I2
             F2
             P
             C2
             T
             E1
             S1
             Z
             S
             J1
             Y1
             K1
             U1
             G1
             Q
             O
             K
             B
             T1
             E2
             F
             N1
             W
             M2
             F1
             X
             H
             A1
             J
             P1
             I1
             J2
             K2
             A2
             Y
             V1
             A
             L2
             X1
             B2
             V
             W1
             D1)
        (and (not (= L1 8528))
     (not (= L1 8529))
     (not (= L1 8544))
     (not (= L1 8545))
     (not (= L1 8560))
     (not (= L1 8561))
     (not (= L1 8448))
     (not (= L1 8576))
     (not (= L1 8577))
     (= L1 8592)
     (not (= L1 8513))
     (not (= L1 12292))
     (not (= L1 16384))
     (not (= L1 8192))
     (not (= L1 24576))
     (not (= L1 8195))
     (not (= L1 8480))
     (not (= L1 8481))
     (not (= L1 8482))
     (not (= L1 8464))
     (not (= L1 8465))
     (not (= L1 8466))
     (not (= L1 8496))
     (not (= L1 8497))
     (not (= L1 8512))
     (= U 8608)
     (= N 0)
     (<= 0 B)
     (<= 0 B2)
     (<= 0 X1)
     (<= 0 D1)
     (<= 0 V)
     (<= 0 O)
     (<= 0 K)
     (<= 0 L2)
     (not (<= R1 0))
     (not (= V1 7)))
      )
      (inv_main202 M1
             M
             G
             Z1
             B1
             U
             D
             H1
             C
             E
             N
             O1
             G2
             I
             H2
             D2
             L
             C1
             Q1
             I2
             F2
             P
             C2
             T
             E1
             S1
             Z
             S
             J1
             Y1
             K1
             U1
             G1
             Q
             O
             K
             B
             T1
             E2
             R1
             N1
             L1
             M2
             F1
             X
             H
             A1
             J
             P1
             I1
             J2
             K2
             A2
             Y
             V1
             A
             L2
             X1
             B2
             V
             W1
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main121 G1
             B1
             T
             O1
             K1
             S1
             J
             A2
             Y
             Z1
             F1
             R1
             G2
             I
             Z
             Q1
             L1
             O
             I1
             X1
             F2
             I2
             E2
             V1
             L2
             H2
             R
             C1
             D2
             H1
             E1
             M2
             W1
             Y1
             M
             A
             K2
             E
             J2
             T1
             V
             D1
             A1
             C
             Q
             H
             B
             L
             C2
             F
             N
             G
             N2
             P
             M1
             B2
             N1
             S
             J1
             K
             U1
             X)
        (and (not (= S1 8529))
     (not (= S1 8544))
     (not (= S1 8545))
     (not (= S1 8560))
     (not (= S1 8561))
     (not (= S1 8448))
     (not (= S1 8576))
     (not (= S1 8577))
     (not (= S1 8592))
     (= S1 8593)
     (not (= S1 8513))
     (not (= S1 12292))
     (not (= S1 16384))
     (not (= S1 8192))
     (not (= S1 24576))
     (not (= S1 8195))
     (not (= S1 8480))
     (not (= S1 8481))
     (not (= S1 8482))
     (not (= S1 8464))
     (not (= S1 8465))
     (not (= S1 8466))
     (not (= S1 8496))
     (not (= S1 8497))
     (not (= S1 8512))
     (= P1 0)
     (= M1 7)
     (= W 8608)
     (= U 8)
     (<= 0 A)
     (<= 0 K2)
     (<= 0 N1)
     (<= 0 J1)
     (<= 0 X)
     (<= 0 S)
     (<= 0 M)
     (<= 0 K)
     (not (<= D 0))
     (not (= S1 8528)))
      )
      (inv_main202 G1
             B1
             T
             O1
             K1
             W
             J
             A2
             Y
             Z1
             P1
             R1
             G2
             I
             Z
             Q1
             L1
             O
             I1
             X1
             F2
             I2
             E2
             V1
             L2
             H2
             R
             C1
             D2
             H1
             E1
             M2
             W1
             Y1
             M
             A
             K2
             E
             J2
             D
             V
             S1
             A1
             C
             Q
             H
             B
             L
             C2
             F
             N
             G
             N2
             P
             U
             B2
             N1
             S
             J1
             K
             U1
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main121 E1
             F
             Q1
             M1
             K
             I
             E
             P1
             T
             P
             O1
             R
             N1
             B2
             W1
             Y
             L1
             Z
             W
             C1
             D1
             X1
             A1
             M2
             A2
             J1
             V1
             I1
             C2
             S1
             V
             H1
             K2
             K1
             Z1
             L2
             I2
             L
             J
             E2
             F1
             C
             G
             U
             Q
             R1
             F2
             N
             D
             U1
             M
             S
             J2
             B
             B1
             Y1
             A
             G1
             H2
             G2
             T1
             X)
        (and (= O 0)
     (not (= I 8528))
     (not (= I 8529))
     (not (= I 8544))
     (not (= I 8545))
     (not (= I 8560))
     (not (= I 8561))
     (not (= I 8448))
     (not (= I 8576))
     (not (= I 8577))
     (not (= I 8592))
     (= I 8593)
     (not (= I 8513))
     (not (= I 12292))
     (not (= I 16384))
     (not (= I 8192))
     (not (= I 24576))
     (not (= I 8195))
     (not (= I 8480))
     (not (= I 8481))
     (not (= I 8482))
     (not (= I 8464))
     (not (= I 8465))
     (not (= I 8466))
     (not (= I 8496))
     (not (= I 8497))
     (not (= I 8512))
     (= H 8608)
     (<= 0 A)
     (<= 0 I2)
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 Z1)
     (<= 0 G1)
     (<= 0 X)
     (<= 0 L2)
     (not (<= D2 0))
     (not (= B1 7)))
      )
      (inv_main202 E1
             F
             Q1
             M1
             K
             H
             E
             P1
             T
             P
             O
             R
             N1
             B2
             W1
             Y
             L1
             Z
             W
             C1
             D1
             X1
             A1
             M2
             A2
             J1
             V1
             I1
             C2
             S1
             V
             H1
             K2
             K1
             Z1
             L2
             I2
             L
             J
             D2
             F1
             I
             G
             U
             Q
             R1
             F2
             N
             D
             U1
             M
             S
             J2
             B
             B1
             Y1
             A
             G1
             H2
             G2
             T1
             X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main121 A1
             Z
             R1
             T1
             P1
             P
             R
             N1
             H2
             M1
             S
             Y
             U1
             X
             H
             W
             C
             J
             J2
             K2
             M
             J1
             C2
             X1
             Q
             D1
             V1
             W1
             G1
             B
             V
             I1
             C1
             L
             B2
             I
             N2
             G2
             F2
             L1
             S1
             B1
             U
             M2
             N
             K1
             H1
             Q1
             Y1
             F1
             G
             I2
             T
             F
             O
             Z1
             K
             E
             D2
             D
             E1
             A2)
        (and (= E2 9)
     (= O1 8640)
     (not (= P 8528))
     (not (= P 8529))
     (not (= P 8544))
     (not (= P 8545))
     (not (= P 8560))
     (not (= P 8561))
     (not (= P 8448))
     (not (= P 8576))
     (not (= P 8577))
     (not (= P 8592))
     (not (= P 8593))
     (= P 8608)
     (not (= P 8513))
     (not (= P 12292))
     (not (= P 16384))
     (not (= P 8192))
     (not (= P 24576))
     (not (= P 8195))
     (not (= P 8480))
     (not (= P 8481))
     (not (= P 8482))
     (not (= P 8464))
     (not (= P 8465))
     (not (= P 8466))
     (not (= P 8496))
     (not (= P 8497))
     (not (= P 8512))
     (= O 8)
     (<= 0 D)
     (<= 0 D2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 K)
     (<= 0 I)
     (<= 0 E)
     (<= 0 N2)
     (not (<= A 0))
     (= L2 0))
      )
      (inv_main202 A1
             Z
             R1
             T1
             P1
             O1
             R
             N1
             H2
             M1
             L2
             Y
             U1
             X
             H
             W
             C
             J
             J2
             K2
             M
             J1
             C2
             X1
             Q
             D1
             V1
             W1
             G1
             B
             V
             I1
             C1
             L
             B2
             I
             N2
             G2
             F2
             A
             S1
             P
             U
             M2
             N
             K1
             H1
             Q1
             Y1
             F1
             G
             I2
             T
             F
             E2
             Z1
             K
             E
             D2
             D
             E1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main121 A1
             F
             Q1
             G1
             N
             F1
             P
             K
             O
             B1
             A
             S
             G2
             Y1
             Y
             N1
             D
             F2
             W1
             J2
             U1
             V1
             T1
             E1
             B
             B2
             C2
             A2
             R
             M1
             H
             U
             H2
             E2
             R1
             Z
             L2
             D1
             L1
             P1
             M
             C1
             K2
             Q
             T
             M2
             D2
             I
             X1
             S1
             I1
             V
             I2
             K1
             L
             G
             X
             J
             J1
             W
             O1
             C)
        (and (= H1 8640)
     (not (= F1 8528))
     (not (= F1 8529))
     (not (= F1 8544))
     (not (= F1 8545))
     (not (= F1 8560))
     (not (= F1 8561))
     (not (= F1 8448))
     (not (= F1 8576))
     (not (= F1 8577))
     (not (= F1 8592))
     (not (= F1 8593))
     (= F1 8608)
     (not (= F1 8513))
     (not (= F1 12292))
     (not (= F1 16384))
     (not (= F1 8192))
     (not (= F1 24576))
     (not (= F1 8195))
     (not (= F1 8480))
     (not (= F1 8481))
     (not (= F1 8482))
     (not (= F1 8464))
     (not (= F1 8465))
     (not (= F1 8466))
     (not (= F1 8496))
     (not (= F1 8497))
     (not (= F1 8512))
     (not (= L 8))
     (<= 0 C)
     (<= 0 R1)
     (<= 0 J1)
     (<= 0 Z)
     (<= 0 X)
     (<= 0 W)
     (<= 0 J)
     (<= 0 L2)
     (not (<= E 0))
     (= Z1 0))
      )
      (inv_main202 A1
             F
             Q1
             G1
             N
             H1
             P
             K
             O
             B1
             Z1
             S
             G2
             Y1
             Y
             N1
             D
             F2
             W1
             J2
             U1
             V1
             T1
             E1
             B
             B2
             C2
             A2
             R
             M1
             H
             U
             H2
             E2
             R1
             Z
             L2
             D1
             L1
             E
             M
             F1
             K2
             Q
             T
             M2
             D2
             I
             X1
             S1
             I1
             V
             I2
             K1
             L
             G
             X
             J
             J1
             W
             O1
             C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) ) 
    (=>
      (and
        (inv_main121 P1
             V1
             E1
             T1
             I
             G
             S
             N
             B
             Y
             O
             I1
             A1
             E
             Q
             B2
             F
             D1
             T
             F2
             G2
             E2
             D2
             C
             W1
             H
             S1
             J
             C2
             X1
             B1
             K2
             G1
             K
             W
             M2
             Q1
             L
             I2
             K1
             Y1
             Z1
             U1
             X
             L2
             R
             J2
             N1
             A
             F1
             A2
             J1
             H1
             R1
             M1
             V
             Z
             O1
             C1
             H2
             U
             N2)
        (and (= M1 8)
     (= P 9)
     (= M 8640)
     (not (= G 8528))
     (not (= G 8529))
     (not (= G 8544))
     (not (= G 8545))
     (not (= G 8560))
     (not (= G 8561))
     (not (= G 8448))
     (not (= G 8576))
     (not (= G 8577))
     (not (= G 8592))
     (not (= G 8593))
     (not (= G 8608))
     (= G 8609)
     (not (= G 8513))
     (not (= G 12292))
     (not (= G 16384))
     (not (= G 8192))
     (not (= G 24576))
     (not (= G 8195))
     (not (= G 8480))
     (not (= G 8481))
     (not (= G 8482))
     (not (= G 8464))
     (not (= G 8465))
     (not (= G 8466))
     (not (= G 8496))
     (not (= G 8497))
     (not (= G 8512))
     (<= 0 H2)
     (<= 0 Q1)
     (<= 0 O1)
     (<= 0 C1)
     (<= 0 Z)
     (<= 0 W)
     (<= 0 N2)
     (<= 0 M2)
     (not (<= L1 0))
     (= D 0))
      )
      (inv_main202 P1
             V1
             E1
             T1
             I
             M
             S
             N
             B
             Y
             D
             I1
             A1
             E
             Q
             B2
             F
             D1
             T
             F2
             G2
             E2
             D2
             C
             W1
             H
             S1
             J
             C2
             X1
             B1
             K2
             G1
             K
             W
             M2
             Q1
             L
             I2
             L1
             Y1
             G
             U1
             X
             L2
             R
             J2
             N1
             A
             F1
             A2
             J1
             H1
             R1
             P
             V
             Z
             O1
             C1
             H2
             U
             N2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) ) 
    (=>
      (and
        (inv_main121 Z
             J1
             C2
             L1
             F1
             M2
             C1
             R
             P1
             L2
             B2
             N
             K
             Q
             G2
             O
             W
             I2
             P
             E
             N1
             W1
             C
             R1
             U1
             F2
             U
             M1
             X
             K2
             V
             D2
             G
             T1
             M
             J
             O1
             S1
             Q1
             S
             H1
             G1
             B1
             D1
             E2
             T
             Z1
             K1
             B
             V1
             A2
             H2
             Y
             A1
             X1
             I
             I1
             Y1
             L
             F
             E1
             H)
        (and (= J2 8640)
     (not (= X1 8))
     (not (= M2 8528))
     (not (= M2 8529))
     (not (= M2 8544))
     (not (= M2 8545))
     (not (= M2 8560))
     (not (= M2 8561))
     (not (= M2 8448))
     (not (= M2 8576))
     (not (= M2 8577))
     (not (= M2 8592))
     (not (= M2 8593))
     (not (= M2 8608))
     (= M2 8609)
     (not (= M2 8513))
     (not (= M2 12292))
     (not (= M2 16384))
     (not (= M2 8192))
     (not (= M2 24576))
     (not (= M2 8195))
     (not (= M2 8480))
     (not (= M2 8481))
     (not (= M2 8482))
     (not (= M2 8464))
     (not (= M2 8465))
     (not (= M2 8466))
     (not (= M2 8496))
     (not (= M2 8497))
     (not (= M2 8512))
     (<= 0 Y1)
     (<= 0 O1)
     (<= 0 I1)
     (<= 0 M)
     (<= 0 L)
     (<= 0 J)
     (<= 0 H)
     (<= 0 F)
     (not (<= D 0))
     (= A 0))
      )
      (inv_main202 Z
             J1
             C2
             L1
             F1
             J2
             C1
             R
             P1
             L2
             A
             N
             K
             Q
             G2
             O
             W
             I2
             P
             E
             N1
             W1
             C
             R1
             U1
             F2
             U
             M1
             X
             K2
             V
             D2
             G
             T1
             M
             J
             O1
             S1
             Q1
             D
             H1
             M2
             B1
             D1
             E2
             T
             Z1
             K1
             B
             V1
             A2
             H2
             Y
             A1
             X1
             I
             I1
             Y1
             L
             F
             E1
             H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main458 V1
             G1
             R1
             D1
             E
             Q1
             M1
             T
             B2
             W
             R
             V
             I2
             J
             P1
             O
             W1
             U
             C
             J2
             F
             H1
             I1
             M2
             Y
             E2
             B
             L2
             U1
             X1
             K2
             O1
             G2
             G
             N
             K1
             N1
             I
             T1
             P
             D
             S
             F1
             A1
             C2
             J1
             C1
             F2
             X
             Q
             Y1
             A2
             S1
             L1
             Z
             A
             Z1
             B1
             M
             N2
             D2
             E1)
        (and (not (= S1 0))
     (not (= L1 0))
     (= Z 10)
     (= L 8672)
     (= K 11)
     (<= 0 Z1)
     (<= 0 N1)
     (<= 0 K1)
     (<= 0 E1)
     (<= 0 B1)
     (<= 0 N)
     (<= 0 M)
     (<= 0 N2)
     (not (<= H 0))
     (= H2 0)
     (= v_66 U1))
      )
      (inv_main202 V1
             G1
             R1
             D1
             E
             L
             M1
             T
             B2
             W
             H2
             V
             I2
             J
             P1
             O
             W1
             U
             C
             J2
             F
             H1
             I1
             M2
             Y
             E2
             B
             L2
             U1
             X1
             K2
             O1
             v_66
             G
             N
             K1
             N1
             I
             T1
             H
             D
             S
             F1
             A1
             C2
             J1
             C1
             F2
             X
             Q
             Y1
             A2
             S1
             L1
             K
             A
             Z1
             B1
             M
             N2
             D2
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main458 W1
             V
             G
             E2
             I
             X
             O1
             K
             R1
             R
             F
             U1
             B2
             D
             A2
             Q1
             Y1
             I1
             S
             G1
             H1
             U
             N2
             K1
             M1
             J
             W
             O
             M
             C1
             C
             G2
             F2
             I2
             P
             L2
             L
             H2
             T
             M2
             X1
             Z1
             D1
             L1
             T1
             A1
             B1
             F1
             N1
             B
             D2
             Q
             P1
             A
             H
             Z
             Y
             S1
             N
             C2
             E
             E1)
        (and (= K2 8672)
     (= J2 0)
     (not (= P1 0))
     (= J1 14)
     (= H 13)
     (not (= H 10))
     (<= 0 L2)
     (<= 0 C2)
     (<= 0 S1)
     (<= 0 E1)
     (<= 0 Y)
     (<= 0 P)
     (<= 0 N)
     (<= 0 L)
     (not (<= V1 0))
     (not (= A 0))
     (= v_66 M))
      )
      (inv_main202 W1
             V
             G
             E2
             I
             K2
             O1
             K
             R1
             R
             J2
             U1
             B2
             D
             A2
             Q1
             Y1
             I1
             S
             G1
             H1
             U
             N2
             K1
             M1
             J
             W
             O
             M
             C1
             C
             G2
             v_66
             I2
             P
             L2
             L
             H2
             T
             V1
             X1
             Z1
             D1
             L1
             T1
             A1
             B1
             F1
             N1
             B
             D2
             Q
             P1
             A
             J1
             Z
             Y
             S1
             N
             C2
             E
             E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main458 D
             G1
             N
             V
             Q1
             A2
             I1
             L
             O
             U
             H2
             E
             K
             N2
             H1
             O1
             Z1
             F2
             F
             T1
             L1
             E2
             J1
             X
             I
             J2
             C1
             V1
             S
             I2
             C2
             B
             E1
             T
             L2
             Q
             B1
             C
             X1
             K2
             G
             M
             W
             F1
             G2
             A1
             B2
             R
             Y
             A
             K1
             D1
             J
             P
             M1
             U1
             P1
             D2
             M2
             Y1
             S1
             N1)
        (and (= M1 16)
     (not (= M1 13))
     (not (= M1 10))
     (= Z 8672)
     (not (= P 0))
     (not (= J 0))
     (= H 17)
     (<= 0 L2)
     (<= 0 D2)
     (<= 0 Y1)
     (<= 0 P1)
     (<= 0 N1)
     (<= 0 B1)
     (<= 0 Q)
     (<= 0 M2)
     (not (<= R1 0))
     (= W1 0)
     (= v_66 S))
      )
      (inv_main202 D
             G1
             N
             V
             Q1
             Z
             I1
             L
             O
             U
             W1
             E
             K
             N2
             H1
             O1
             Z1
             F2
             F
             T1
             L1
             E2
             J1
             X
             I
             J2
             C1
             V1
             S
             I2
             C2
             B
             v_66
             T
             L2
             Q
             B1
             C
             X1
             R1
             G
             M
             W
             F1
             G2
             A1
             B2
             R
             Y
             A
             K1
             D1
             J
             P
             H
             U1
             P1
             D2
             M2
             Y1
             S1
             N1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (N2 Int) (v_66 Int) ) 
    (=>
      (and
        (inv_main458 M1
             R
             C1
             Z
             J1
             V1
             J
             W1
             Q
             D
             E2
             D2
             H2
             V
             B1
             S1
             I
             T
             C
             F
             L2
             X1
             X
             L1
             U1
             Y1
             E1
             A
             I2
             B2
             S
             P1
             G
             N1
             D1
             Y
             B
             W
             L
             K2
             G2
             M
             R1
             A2
             O
             N2
             N
             U
             K
             H
             F2
             I1
             P
             J2
             C2
             M2
             O1
             Z1
             T1
             K1
             A1
             E)
        (and (= C2 19)
     (not (= C2 16))
     (not (= C2 13))
     (not (= C2 10))
     (= Q1 20)
     (= H1 0)
     (= F1 8672)
     (not (= P 0))
     (<= 0 B)
     (<= 0 Z1)
     (<= 0 T1)
     (<= 0 O1)
     (<= 0 K1)
     (<= 0 D1)
     (<= 0 Y)
     (<= 0 E)
     (not (<= G1 0))
     (not (= J2 0))
     (= v_66 I2))
      )
      (inv_main202 M1
             R
             C1
             Z
             J1
             F1
             J
             W1
             Q
             D
             H1
             D2
             H2
             V
             B1
             S1
             I
             T
             C
             F
             L2
             X1
             X
             L1
             U1
             Y1
             E1
             A
             I2
             B2
             S
             P1
             v_66
             N1
             D1
             Y
             B
             W
             L
             G1
             G2
             M
             R1
             A2
             O
             N2
             N
             U
             K
             H
             F2
             I1
             P
             J2
             Q1
             M2
             O1
             Z1
             T1
             K1
             A1
             E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (M2 Int) (v_65 Int) ) 
    (=>
      (and
        (inv_main458 Y
             J1
             N1
             D
             L
             M
             V1
             T
             F
             X
             Q1
             K
             C1
             C
             H1
             Y1
             L1
             Z
             S1
             K1
             P1
             E1
             E
             L2
             V
             A1
             Z1
             H
             B
             D2
             D1
             B1
             U1
             I
             G1
             B2
             J2
             W
             F1
             I1
             G2
             M1
             A
             S
             N
             X1
             K2
             R
             J
             U
             M2
             O1
             Q
             T1
             E2
             I2
             C2
             R1
             A2
             P
             F2
             H2)
        (and (not (= E2 16))
     (not (= E2 13))
     (not (= E2 10))
     (= W1 8672)
     (not (= T1 0))
     (not (= Q 0))
     (= G 0)
     (<= 0 J2)
     (<= 0 H2)
     (<= 0 C2)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 R1)
     (<= 0 G1)
     (<= 0 P)
     (not (<= O 0))
     (not (= E2 19))
     (= v_65 B))
      )
      (inv_main202 Y
             J1
             N1
             D
             L
             W1
             V1
             T
             F
             X
             G
             K
             C1
             C
             H1
             Y1
             L1
             Z
             S1
             K1
             P1
             E1
             E
             L2
             V
             A1
             Z1
             H
             B
             D2
             D1
             B1
             v_65
             I
             G1
             B2
             J2
             W
             F1
             O
             G2
             M1
             A
             S
             N
             X1
             K2
             R
             J
             U
             M2
             O1
             Q
             T1
             E2
             I2
             C2
             R1
             A2
             P
             F2
             H2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main436 W
             L1
             M1
             N1
             N
             F
             C1
             G1
             Y1
             U
             E1
             T1
             B
             O
             G
             H
             E
             D1
             B2
             T
             R1
             K2
             U1
             D2
             K1
             Z
             J
             W1
             I1
             L
             B1
             H2
             E2
             X
             L2
             I2
             P1
             Q
             A1
             F2
             F1
             P
             Y
             Z1
             C
             M
             X1
             V1
             V
             Q1
             S
             H1
             D
             A2
             A
             I
             K
             O1
             C2
             R
             J2
             S1)
        (and (= J1 10)
     (<= 0 I2)
     (<= 0 C2)
     (<= 0 S1)
     (<= 0 P1)
     (<= 0 O1)
     (<= 0 R)
     (<= 0 K)
     (<= 0 L2)
     (= A 9))
      )
      (inv_main439 W
             L1
             M1
             N1
             N
             F
             C1
             G1
             Y1
             U
             E1
             T1
             B
             O
             G
             H
             E
             D1
             B2
             T
             R1
             K2
             U1
             D2
             K1
             Z
             J
             W1
             I1
             L
             B1
             H2
             E2
             X
             L2
             I2
             P1
             Q
             A1
             G2
             F1
             P
             Y
             Z1
             C
             M
             X1
             V1
             V
             Q1
             S
             H1
             D
             A2
             J1
             I
             K
             O1
             C2
             R
             J2
             S1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main436 D2
             E2
             H1
             M
             M1
             K2
             L2
             T
             U1
             Z
             P1
             Y1
             K
             E1
             E
             Y
             R
             D1
             W1
             C2
             C1
             G2
             B1
             C
             I
             N
             X1
             P
             Z1
             I2
             R1
             J1
             H2
             T1
             H
             A
             L
             J
             U
             K1
             J2
             O1
             G
             S1
             B
             W
             Q
             B2
             Q1
             N1
             A2
             F2
             S
             V1
             X
             O
             I1
             A1
             F1
             L1
             G1
             F)
        (and (= X 12)
     (= V 13)
     (<= 0 A)
     (<= 0 L1)
     (<= 0 I1)
     (<= 0 F1)
     (<= 0 A1)
     (<= 0 L)
     (<= 0 H)
     (<= 0 F)
     (not (= X 9)))
      )
      (inv_main439 D2
             E2
             H1
             M
             M1
             K2
             L2
             T
             U1
             Z
             P1
             Y1
             K
             E1
             E
             Y
             R
             D1
             W1
             C2
             C1
             G2
             B1
             C
             I
             N
             X1
             P
             Z1
             I2
             R1
             J1
             H2
             T1
             H
             A
             L
             J
             U
             D
             J2
             O1
             G
             S1
             B
             W
             Q
             B2
             Q1
             N1
             A2
             F2
             S
             V1
             V
             O
             I1
             A1
             F1
             L1
             G1
             F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main436 K
             W1
             T
             G2
             O
             C1
             M
             S
             J
             H
             L1
             Y
             K1
             S1
             N1
             T1
             Z1
             R
             J1
             G
             K2
             E
             H1
             R1
             I2
             I
             F2
             P
             X1
             N
             L2
             Q1
             Y1
             I1
             A
             C2
             A2
             X
             G1
             E2
             M1
             J2
             H2
             V
             W
             U1
             F
             D
             B2
             B1
             A1
             F1
             D1
             L
             E1
             B
             Q
             D2
             P1
             C
             Z
             V1)
        (and (not (= E1 12))
     (= E1 15)
     (= U 16)
     (<= 0 A)
     (<= 0 D2)
     (<= 0 C2)
     (<= 0 A2)
     (<= 0 V1)
     (<= 0 P1)
     (<= 0 Q)
     (<= 0 C)
     (not (= E1 9)))
      )
      (inv_main439 K
             W1
             T
             G2
             O
             C1
             M
             S
             J
             H
             L1
             Y
             K1
             S1
             N1
             T1
             Z1
             R
             J1
             G
             K2
             E
             H1
             R1
             I2
             I
             F2
             P
             X1
             N
             L2
             Q1
             Y1
             I1
             A
             C2
             A2
             X
             G1
             O1
             M1
             J2
             H2
             V
             W
             U1
             F
             D
             B2
             B1
             A1
             F1
             D1
             L
             U
             B
             Q
             D2
             P1
             C
             Z
             V1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) ) 
    (=>
      (and
        (inv_main436 Q
             Z
             I2
             H
             G2
             D2
             C2
             W
             Y
             D1
             E
             U
             F
             J2
             Z1
             L
             E2
             S
             Y1
             R
             L1
             K
             N1
             W1
             D
             S1
             A1
             C
             O
             H1
             E1
             M
             X
             L2
             B2
             T1
             U1
             I1
             G
             J
             F2
             R1
             G1
             P1
             Q1
             X1
             A2
             K1
             P
             H2
             O1
             C1
             B1
             K2
             A
             V
             V1
             M1
             I
             F1
             J1
             T)
        (and (not (= A 12))
     (not (= A 15))
     (= A 18)
     (= B 19)
     (<= 0 B2)
     (<= 0 V1)
     (<= 0 U1)
     (<= 0 T1)
     (<= 0 M1)
     (<= 0 F1)
     (<= 0 T)
     (<= 0 I)
     (not (= A 9)))
      )
      (inv_main439 Q
             Z
             I2
             H
             G2
             D2
             C2
             W
             Y
             D1
             E
             U
             F
             J2
             Z1
             L
             E2
             S
             Y1
             R
             L1
             K
             N1
             W1
             D
             S1
             A1
             C
             O
             H1
             E1
             M
             X
             L2
             B2
             T1
             U1
             I1
             G
             N
             F2
             R1
             G1
             P1
             Q1
             X1
             A2
             K1
             P
             H2
             O1
             C1
             B1
             K2
             B
             V
             V1
             M1
             I
             F1
             J1
             T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main436 B2
             I1
             U
             S1
             R1
             Z
             L
             E1
             H
             D2
             J
             E
             Q1
             G
             J1
             V1
             L1
             U1
             D1
             Q
             T
             I
             A2
             O1
             M1
             A
             P1
             C2
             W
             K
             O
             T1
             G1
             B1
             S
             J2
             H1
             G2
             X
             X1
             C1
             F1
             M
             Y1
             H2
             Y
             N
             W1
             F
             E2
             R
             I2
             D
             N1
             Z1
             K1
             K2
             C
             V
             B
             F2
             A1)
        (and (not (= Z1 12))
     (not (= Z1 15))
     (not (= Z1 18))
     (not (= Z1 21))
     (<= 0 H1)
     (<= 0 A1)
     (<= 0 V)
     (<= 0 S)
     (<= 0 C)
     (<= 0 B)
     (<= 0 K2)
     (<= 0 J2)
     (not (= Z1 9)))
      )
      (inv_main439 B2
             I1
             U
             S1
             R1
             Z
             L
             E1
             H
             D2
             J
             E
             Q1
             G
             J1
             V1
             L1
             U1
             D1
             Q
             T
             I
             A2
             O1
             M1
             A
             P1
             C2
             W
             K
             O
             T1
             G1
             B1
             S
             J2
             H1
             G2
             X
             P
             C1
             F1
             M
             Y1
             H2
             Y
             N
             W1
             F
             E2
             R
             I2
             D
             N1
             Z1
             K1
             K2
             C
             V
             B
             F2
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main202 B
             M1
             R
             Q1
             X1
             J2
             A
             U
             O
             H1
             B2
             I1
             K1
             O1
             P1
             D1
             M
             Z1
             L
             U1
             J
             R1
             F
             G
             S1
             C2
             S
             N
             E2
             C1
             V1
             I
             B1
             D
             Q
             T1
             H2
             Y1
             I2
             G1
             C
             K
             P
             E1
             Z
             F2
             T
             H
             F1
             D2
             N1
             W1
             J1
             X
             E
             Y
             G2
             A1
             W
             V
             L1
             A2)
        (and (= S 0)
     (= P 0)
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 A2)
     (<= 0 T1)
     (<= 0 A1)
     (<= 0 W)
     (<= 0 V)
     (<= 0 Q)
     (= P1 0))
      )
      (inv_main523 B
             M1
             R
             Q1
             X1
             J2
             A
             U
             O
             H1
             B2
             I1
             K1
             O1
             P1
             D1
             M
             Z1
             L
             U1
             J
             R1
             F
             G
             S1
             C2
             S
             N
             E2
             C1
             V1
             I
             B1
             D
             Q
             T1
             H2
             Y1
             I2
             G1
             C
             K
             P
             E1
             Z
             F2
             T
             H
             F1
             D2
             N1
             W1
             J1
             X
             E
             Y
             G2
             A1
             W
             V
             L1
             A2)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) ) 
    (=>
      (and
        (inv_main202 F2
             F1
             I2
             N
             H1
             H
             T
             O1
             W1
             L1
             V
             E
             P
             C2
             Z
             Q
             A1
             U1
             M
             E2
             L
             J2
             O
             I1
             A2
             J
             T1
             B
             S
             G1
             Q1
             S1
             A
             K2
             K1
             Y1
             D2
             B1
             D1
             P1
             R1
             G
             F
             J1
             E1
             I
             X1
             K
             D
             G2
             H2
             V1
             N1
             Y
             B2
             R
             M1
             W
             X
             C1
             Z1
             U)
        (and (not (= Z 0))
     (= F 0)
     (<= 0 D2)
     (<= 0 Y1)
     (<= 0 M1)
     (<= 0 K1)
     (<= 0 C1)
     (<= 0 X)
     (<= 0 W)
     (<= 0 U)
     (not (<= C 0))
     (= T1 0))
      )
      (inv_main523 F2
             F1
             I2
             N
             H1
             H
             T
             O1
             W1
             L1
             V
             E
             P
             C2
             Z
             Q
             A1
             U1
             M
             E2
             L
             J2
             O
             I1
             A2
             J
             T1
             B
             S
             G1
             Q1
             S1
             A
             K2
             K1
             Y1
             D2
             B1
             D1
             C
             R1
             G
             F
             J1
             E1
             I
             X1
             K
             D
             G2
             H2
             V1
             N1
             Y
             B2
             R
             M1
             W
             X
             C1
             Z1
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main121 B1
             H
             L2
             A1
             P1
             I1
             I
             M
             Q1
             C2
             V
             T1
             B2
             Z
             S1
             J1
             R
             Q
             D
             F1
             N
             E
             F
             Z1
             S
             F2
             E2
             O1
             Y1
             G1
             X
             A
             D2
             X1
             L1
             J2
             I2
             A2
             E1
             C
             V1
             Y
             O
             H1
             R1
             W1
             N1
             G
             J
             B
             G2
             K1
             K2
             D1
             M1
             P
             U1
             W
             L
             C1
             K
             U)
        (and (not (= I1 8528))
     (not (= I1 8529))
     (not (= I1 8544))
     (not (= I1 8545))
     (not (= I1 8560))
     (not (= I1 8561))
     (not (= I1 8448))
     (= I1 8576)
     (not (= I1 8513))
     (not (= I1 12292))
     (not (= I1 16384))
     (not (= I1 8192))
     (not (= I1 24576))
     (not (= I1 8195))
     (not (= I1 8480))
     (not (= I1 8481))
     (not (= I1 8482))
     (not (= I1 8464))
     (not (= I1 8465))
     (not (= I1 8466))
     (not (= I1 8496))
     (not (= I1 8497))
     (not (= I1 8512))
     (= T 6)
     (<= 0 J2)
     (<= 0 I2)
     (<= 0 U1)
     (<= 0 L1)
     (<= 0 C1)
     (<= 0 W)
     (<= 0 U)
     (<= 0 L)
     (= M1 5)
     (= v_64 I1))
      )
      (inv_main393 B1
             H
             L2
             A1
             P1
             I1
             I
             M
             Q1
             C2
             V
             T1
             B2
             Z
             S1
             J1
             R
             Q
             D
             F1
             N
             E
             F
             Z1
             S
             F2
             E2
             O1
             Y1
             G1
             X
             A
             D2
             X1
             L1
             J2
             I2
             A2
             E1
             H2
             V1
             v_64
             O
             H1
             R1
             W1
             N1
             G
             J
             B
             G2
             K1
             K2
             D1
             T
             P
             U1
             W
             L
             C1
             K
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main121 H1
             G1
             P
             N1
             Z1
             U
             I
             J2
             E2
             A2
             I1
             Y1
             Q1
             R
             S1
             B1
             K2
             F2
             O
             W1
             I2
             D2
             D
             V1
             O1
             E
             C
             L1
             W
             A1
             F
             X
             S
             E1
             G2
             U1
             R1
             K
             G
             N
             H2
             Q
             X1
             J1
             H
             T1
             F1
             K1
             J
             D1
             B2
             A
             M
             B
             T
             V
             P1
             Y
             Z
             C2
             M1
             C1)
        (and (not (= U 8529))
     (not (= U 8544))
     (not (= U 8545))
     (not (= U 8560))
     (not (= U 8561))
     (not (= U 8448))
     (= U 8576)
     (not (= U 8513))
     (not (= U 12292))
     (not (= U 16384))
     (not (= U 8192))
     (not (= U 24576))
     (not (= U 8195))
     (not (= U 8480))
     (not (= U 8481))
     (not (= U 8482))
     (not (= U 8464))
     (not (= U 8465))
     (not (= U 8466))
     (not (= U 8496))
     (not (= U 8497))
     (not (= U 8512))
     (not (= T 5))
     (<= 0 G2)
     (<= 0 C2)
     (<= 0 U1)
     (<= 0 R1)
     (<= 0 P1)
     (<= 0 C1)
     (<= 0 Z)
     (<= 0 Y)
     (not (= U 8528))
     (= v_63 U))
      )
      (inv_main393 H1
             G1
             P
             N1
             Z1
             U
             I
             J2
             E2
             A2
             I1
             Y1
             Q1
             R
             S1
             B1
             K2
             F2
             O
             W1
             I2
             D2
             D
             V1
             O1
             E
             C
             L1
             W
             A1
             F
             X
             S
             E1
             G2
             U1
             R1
             K
             G
             L
             H2
             v_63
             X1
             J1
             H
             T1
             F1
             K1
             J
             D1
             B2
             A
             M
             B
             T
             V
             P1
             Y
             Z
             C2
             M1
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (L2 Int) (v_64 Int) ) 
    (=>
      (and
        (inv_main121 H
             X
             H2
             K2
             X1
             T
             C
             U
             J1
             F2
             B2
             R1
             W
             K1
             M
             F1
             T1
             F
             E1
             D2
             P
             V
             I
             I1
             L
             J2
             S
             C1
             W1
             K
             Y1
             Z1
             Q
             M1
             Y
             Z
             C2
             N
             B1
             D1
             S1
             J
             L2
             A
             A1
             I2
             V1
             G
             Q1
             R
             B
             A2
             H1
             G1
             G2
             P1
             O
             D
             O1
             E
             N1
             U1)
        (and (= L1 6)
     (not (= T 8528))
     (not (= T 8529))
     (not (= T 8544))
     (not (= T 8545))
     (not (= T 8560))
     (not (= T 8561))
     (not (= T 8448))
     (not (= T 8576))
     (= T 8577)
     (not (= T 8513))
     (not (= T 12292))
     (not (= T 16384))
     (not (= T 8192))
     (not (= T 24576))
     (not (= T 8195))
     (not (= T 8480))
     (not (= T 8481))
     (not (= T 8482))
     (not (= T 8464))
     (not (= T 8465))
     (not (= T 8466))
     (not (= T 8496))
     (not (= T 8497))
     (not (= T 8512))
     (<= 0 C2)
     (<= 0 U1)
     (<= 0 O1)
     (<= 0 Z)
     (<= 0 Y)
     (<= 0 O)
     (<= 0 E)
     (<= 0 D)
     (= G2 5)
     (= v_64 T))
      )
      (inv_main393 H
             X
             H2
             K2
             X1
             T
             C
             U
             J1
             F2
             B2
             R1
             W
             K1
             M
             F1
             T1
             F
             E1
             D2
             P
             V
             I
             I1
             L
             J2
             S
             C1
             W1
             K
             Y1
             Z1
             Q
             M1
             Y
             Z
             C2
             N
             B1
             E2
             S1
             v_64
             L2
             A
             A1
             I2
             V1
             G
             Q1
             R
             B
             A2
             H1
             G1
             L1
             P1
             O
             D
             O1
             E
             N1
             U1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (K2 Int) (v_63 Int) ) 
    (=>
      (and
        (inv_main121 B1
             D2
             L1
             M1
             Y1
             E2
             G2
             H1
             G
             R1
             G1
             J2
             F1
             N1
             U1
             U
             V1
             X1
             F
             H
             K2
             E1
             D
             T
             J1
             H2
             Z
             W
             C2
             S
             O1
             Q
             Z1
             K1
             K
             M
             Y
             V
             F2
             W1
             N
             Q1
             B
             A1
             R
             E
             P
             I1
             I2
             P1
             S1
             X
             D1
             O
             J
             T1
             B2
             A2
             L
             I
             C1
             A)
        (and (not (= E2 8529))
     (not (= E2 8544))
     (not (= E2 8545))
     (not (= E2 8560))
     (not (= E2 8561))
     (not (= E2 8448))
     (not (= E2 8576))
     (= E2 8577)
     (not (= E2 8513))
     (not (= E2 12292))
     (not (= E2 16384))
     (not (= E2 8192))
     (not (= E2 24576))
     (not (= E2 8195))
     (not (= E2 8480))
     (not (= E2 8481))
     (not (= E2 8482))
     (not (= E2 8464))
     (not (= E2 8465))
     (not (= E2 8466))
     (not (= E2 8496))
     (not (= E2 8497))
     (not (= E2 8512))
     (not (= J 5))
     (<= 0 A)
     (<= 0 B2)
     (<= 0 A2)
     (<= 0 Y)
     (<= 0 M)
     (<= 0 L)
     (<= 0 K)
     (<= 0 I)
     (not (= E2 8528))
     (= v_63 E2))
      )
      (inv_main393 B1
             D2
             L1
             M1
             Y1
             E2
             G2
             H1
             G
             R1
             G1
             J2
             F1
             N1
             U1
             U
             V1
             X1
             F
             H
             K2
             E1
             D
             T
             J1
             H2
             Z
             W
             C2
             S
             O1
             Q
             Z1
             K1
             K
             M
             Y
             V
             F2
             C
             N
             v_63
             B
             A1
             R
             E
             P
             I1
             I2
             P1
             S1
             X
             D1
             O
             J
             T1
             B2
             A2
             L
             I
             C1
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 P1
             I
             X1
             I1
             O
             T
             N
             H1
             Z
             F2
             D1
             O1
             Q1
             N1
             V1
             K1
             C
             M
             K
             R
             Q
             U1
             E1
             S
             W
             Y
             B1
             F1
             T1
             P
             I2
             E2
             A2
             C2
             H2
             A1
             J
             L1
             C1
             S1
             V
             L
             A
             R1
             E
             W1
             H
             D2
             M1
             B2
             X
             Y1
             Z1
             G
             B
             J2
             G2
             F
             J1
             D
             U
             G1)
        (and (not (= T 8529))
     (= T 8544)
     (not (= T 8513))
     (not (= T 12292))
     (not (= T 16384))
     (not (= T 8192))
     (not (= T 24576))
     (not (= T 8195))
     (not (= T 8480))
     (not (= T 8481))
     (not (= T 8482))
     (not (= T 8464))
     (not (= T 8465))
     (not (= T 8466))
     (not (= T 8496))
     (not (= T 8497))
     (not (= T 8512))
     (<= 0 H2)
     (<= 0 G2)
     (<= 0 J1)
     (<= 0 G1)
     (<= 0 A1)
     (<= 0 J)
     (<= 0 F)
     (<= 0 D)
     (not (= T 8528))
     (= v_62 T))
      )
      (inv_main337 P1
             I
             X1
             I1
             O
             T
             N
             H1
             Z
             F2
             D1
             O1
             Q1
             N1
             V1
             K1
             C
             M
             K
             R
             Q
             U1
             E1
             S
             W
             Y
             B1
             F1
             T1
             P
             I2
             E2
             A2
             C2
             H2
             A1
             J
             L1
             C1
             S1
             V
             v_62
             A
             R1
             E
             W1
             H
             D2
             M1
             B2
             X
             Y1
             Z1
             G
             B
             J2
             G2
             F
             J1
             D
             U
             G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) (v_62 Int) ) 
    (=>
      (and
        (inv_main121 A1
             R1
             Q1
             F
             U
             M
             V1
             K1
             Z
             I
             O
             M1
             F1
             C2
             C1
             W1
             X
             N1
             I2
             Y
             V
             N
             X1
             S1
             Z1
             Y1
             D
             D2
             S
             H1
             G1
             J1
             H
             E
             F2
             E1
             L1
             R
             Q
             B
             B1
             G
             G2
             A
             U1
             J2
             O1
             P1
             T1
             T
             C
             I1
             J
             P
             B2
             E2
             L
             H2
             A2
             D1
             W
             K)
        (and (not (= M 8529))
     (not (= M 8544))
     (= M 8545)
     (not (= M 8513))
     (not (= M 12292))
     (not (= M 16384))
     (not (= M 8192))
     (not (= M 24576))
     (not (= M 8195))
     (not (= M 8480))
     (not (= M 8481))
     (not (= M 8482))
     (not (= M 8464))
     (not (= M 8465))
     (not (= M 8466))
     (not (= M 8496))
     (not (= M 8497))
     (not (= M 8512))
     (<= 0 H2)
     (<= 0 F2)
     (<= 0 A2)
     (<= 0 L1)
     (<= 0 E1)
     (<= 0 D1)
     (<= 0 L)
     (<= 0 K)
     (not (= M 8528))
     (= v_62 M))
      )
      (inv_main337 A1
             R1
             Q1
             F
             U
             M
             V1
             K1
             Z
             I
             O
             M1
             F1
             C2
             C1
             W1
             X
             N1
             I2
             Y
             V
             N
             X1
             S1
             Z1
             Y1
             D
             D2
             S
             H1
             G1
             J1
             H
             E
             F2
             E1
             L1
             R
             Q
             B
             B1
             v_62
             G2
             A
             U1
             J2
             O1
             P1
             T1
             T
             C
             I1
             J
             P
             B2
             E2
             L
             H2
             A2
             D1
             W
             K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) (V1 Int) (W1 Int) (X1 Int) (Y1 Int) (Z1 Int) (A2 Int) (B2 Int) (C2 Int) (D2 Int) (E2 Int) (F2 Int) (G2 Int) (H2 Int) (I2 Int) (J2 Int) ) 
    (=>
      (and
        (inv_main540 Q
             D
             I
             I2
             N1
             B2
             C1
             P
             A
             D2
             G2
             Q1
             R
             S1
             H1
             J1
             P1
             S
             X
             R1
             F1
             W
             A1
             F2
             H
             A2
             B
             O1
             I1
             B1
             C2
             G1
             J
             M1
             L1
             O
             G
             K
             Z1
             L
             C
             V1
             Y1
             Z
             M
             V
             X1
             E2
             Y
             K1
             E1
             E
             T
             U1
             F
             D1
             U
             N
             H2
             J2
             W1
             T1)
        (and (<= 0 T1)
     (<= 0 L1)
     (<= 0 U)
     (<= 0 O)
     (<= 0 N)
     (<= 0 G)
     (<= 0 J2)
     (<= 0 H2))
      )
      false
    )
  )
)

(check-sat)
(exit)
