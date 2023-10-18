; ./sv-comp/./2015-05-26/LIA/Eldarica/linear-tree-like/rsolv.smt2-0042_000.smt2
(set-logic HORN)

(declare-fun |predh26_9| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_4| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_16| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_17| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh26_27| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_7| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_19| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh26_20| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_10| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh26_24| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_11| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_14| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_8| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh26_15| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_13| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_25| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh26_2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_22| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_23| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_6| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_18| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_12| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_5| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_26| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_21| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |predh35_3| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (v_31 Int) ) 
    (=>
      (and
        (predh26_2 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 L) (= A (+ 1 L)) (= 0 v_31))
      )
      (predh35_1 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A v_31 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (predh35_3 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 (+ (* (- 1) O) K))
     (<= 0 (+ (* (- 1) L) B))
     (<= 0 (+ (* (- 1) L) D))
     (<= 0 (+ L (* (- 1) C)))
     (<= 0 (+ L (* (- 1) E)))
     (= A (+ (- 1) L)))
      )
      (predh26_2 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M A K J I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_4 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_3 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_5 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_4 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_6 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_5 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_7 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_6 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_8 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_7 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (v_31 Int) ) 
    (=>
      (and
        (predh26_9 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 L) (= A (+ 1 L)) (= 0 v_31))
      )
      (predh35_8 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A v_31 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (predh35_10 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 (+ (* (- 1) O) K))
     (<= 0 (+ (* (- 1) L) B))
     (<= 0 (+ (* (- 1) L) D))
     (<= 0 (+ L (* (- 1) C)))
     (<= 0 (+ L (* (- 1) E)))
     (= A (+ (- 1) L)))
      )
      (predh26_9 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M A K J I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_11 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_10 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_12 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_11 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_13 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_12 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_14 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_13 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (v_31 Int) ) 
    (=>
      (and
        (predh26_15 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 L) (= A (+ 1 L)) (= 0 v_31))
      )
      (predh35_14 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A v_31 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (predh35_16 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 (+ (* (- 1) O) K))
     (<= 0 (+ (* (- 1) L) B))
     (<= 0 (+ (* (- 1) L) D))
     (<= 0 (+ L (* (- 1) C)))
     (<= 0 (+ L (* (- 1) E)))
     (= A (+ (- 1) L)))
      )
      (predh26_15 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M A K J I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_17 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_16 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_18 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_17 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_19 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_18 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (v_31 Int) ) 
    (=>
      (and
        (predh26_20 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 L) (= A (+ 1 L)) (= 0 v_31))
      )
      (predh35_19 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A v_31 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (predh35_21 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 (+ (* (- 1) O) K))
     (<= 0 (+ (* (- 1) L) B))
     (<= 0 (+ (* (- 1) L) D))
     (<= 0 (+ L (* (- 1) C)))
     (<= 0 (+ L (* (- 1) E)))
     (= A (+ (- 1) L)))
      )
      (predh26_20 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M A K J I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_22 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_21 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_23 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_22 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (v_31 Int) ) 
    (=>
      (and
        (predh26_24 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 L) (= A (+ 1 L)) (= 0 v_31))
      )
      (predh35_23 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A v_31 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (predh35_25 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 (+ (* (- 1) O) K))
     (<= 0 (+ (* (- 1) L) B))
     (<= 0 (+ (* (- 1) L) D))
     (<= 0 (+ L (* (- 1) C)))
     (<= 0 (+ L (* (- 1) E)))
     (= A (+ (- 1) L)))
      )
      (predh26_24 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M A K J I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (predh35_26 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 0 (+ (* (- 1) K) D))
     (<= 0 (+ (* (- 1) K) F))
     (<= 0 (+ (* (- 1) L) H))
     (<= 0 (+ K (* (- 1) E)))
     (<= 0 (+ K (* (- 1) G)))
     (<= 0 (+ O (* (- 1) K)))
     (<= 0 (+ L (* (- 1) I)))
     (= A (+ 1 K)))
      )
      (predh35_25 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A F1 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (v_31 Int) ) 
    (=>
      (and
        (predh26_27 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B)
        (and (<= 1 L) (= A (+ 1 L)) (= 0 v_31))
      )
      (predh35_26 E1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L A v_31 I H G F E D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (v_16 Int) (v_17 Int) (v_18 Int) (v_19 Int) (v_20 Int) (v_21 Int) (v_22 Int) (v_23 Int) (v_24 Int) (v_25 Int) (v_26 Int) (v_27 Int) (v_28 Int) (v_29 Int) ) 
    (=>
      (and
        (and (<= 11 B)
     (= A (+ (- 1) B))
     (= v_16 G)
     (= v_17 B)
     (= v_18 F)
     (= v_19 E)
     (= v_20 D)
     (= v_21 C)
     (= 1 v_22)
     (= v_23 B)
     (= 1 v_24)
     (= v_25 B)
     (= 1 v_26)
     (= v_27 B)
     (= 1 v_28)
     (= v_29 B))
      )
      (predh26_27 G
            B
            F
            E
            P
            D
            C
            O
            N
            M
            L
            K
            J
            I
            H
            v_16
            v_17
            v_18
            v_19
            A
            v_20
            v_21
            v_22
            v_23
            v_24
            v_25
            v_26
            v_27
            v_28
            v_29)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (predh35_1 D1 C1 B1 A1 Z Y X W V U T S R Q P O N M L K J I H G F E D C B A)
        (and (<= 0 (+ N (* (- 1) J))) (<= 1 (+ (* (- 1) J) D)))
      )
      false
    )
  )
)

(check-sat)
(exit)
