; ./eldarica-misc/./LIA/HOLA/05.c_000.smt2
(set-logic HORN)

(declare-fun |h20| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h4| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h8| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h12| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h16| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h7| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h1| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h3| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h10| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h15| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h9| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h21| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h5| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h13| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h2| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h11| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h17| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h14| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h18| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h19| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h6| ( Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (v_6 Int) (v_7 Int) (v_8 Int) (v_9 Int) (v_10 Int) (v_11 Int) ) 
    (=>
      (and
        (and true (= v_6 A) (= v_7 B) (= v_8 C) (= v_9 D) (= v_10 E) (= v_11 F))
      )
      (h1 A B C D E F v_6 v_7 v_8 v_9 v_10 v_11)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (h1 A B C D E F G M N O P L)
        (and (= I 0) (= H 0) (= K 0) (= J 0))
      )
      (h2 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h2 A B C D E F G H I J K L)
        true
      )
      (h3 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h3 A B C D E F G H I J K L)
        true
      )
      (h4 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h4 A B C D E F G H I J K L)
        true
      )
      (h5 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h5 A B C D E F G H I J K L)
        true
      )
      (h6 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h6 A B C D E F G H I J K L)
        true
      )
      (h7 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h7 A B C D E F G H I J K L)
        true
      )
      (h8 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h8 A B C D E F G H I J K L)
        (<= L (- 1))
      )
      (h9 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (h9 A B C D E F G M O P N L)
        (and (= O (+ (- 1) I))
     (= N (+ (* (- 1) H) K))
     (= M (+ (- 1) H))
     (= P (+ (* (- 1) I) J)))
      )
      (h10 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h8 A B C D E F G H I J K L)
        (>= L 1)
      )
      (h11 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (h11 A B C D E F G M O P N L)
        (and (= O (+ (- 1) I))
     (= N (+ (* (- 1) H) K))
     (= M (+ (- 1) H))
     (= P (+ (* (- 1) I) J)))
      )
      (h10 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h8 A B C D E F G H I J K L)
        (= L 0)
      )
      (h12 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h12 A B C D E F G H I J K L)
        true
      )
      (h13 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h13 A B C D E F G H I J K L)
        true
      )
      (h14 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h10 A B C D E F G H I J K L)
        true
      )
      (h15 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h15 A B C D E F G H I J K L)
        (<= G (- 1))
      )
      (h16 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (h16 A B C D E F G H I M K L)
        (= M (+ (- 1) J))
      )
      (h17 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h15 A B C D E F G H I J K L)
        (>= G 1)
      )
      (h18 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) ) 
    (=>
      (and
        (h18 A B C D E F G H I M K L)
        (= M (+ (- 1) J))
      )
      (h17 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h15 A B C D E F G H I J K L)
        (= G 0)
      )
      (h19 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h19 A B C D E F G H I J K L)
        true
      )
      (h5 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h17 A B C D E F G H I J K L)
        true
      )
      (h5 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h14 A B C D E F G H I J K L)
        true
      )
      (h20 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h20 A B C D E F G H I J K L)
        (<= (+ J (* (- 1) K)) (- 1))
      )
      (h21 A B C D E F G H I J K L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) ) 
    (=>
      (and
        (h21 A B C D E F G H I J K L)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
