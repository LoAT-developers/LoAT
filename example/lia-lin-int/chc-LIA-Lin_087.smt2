; ./eldarica-misc/./LIA/HOLA/26.c_000.smt2
(set-logic HORN)

(declare-fun |h44| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h19| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h30| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h39| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h16| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h42| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h4| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h35| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h7| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h43| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h10| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h37| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h14| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h49| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h13| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h38| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h26| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |h25| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h48| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h18| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h33| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h46| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h1| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h45| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h11| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h24| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h12| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h34| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h36| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h15| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h20| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h22| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h41| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h3| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h2| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h6| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h17| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h47| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h31| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h32| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h5| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h29| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h40| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h27| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h23| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h28| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h8| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h9| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |h21| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (v_7 Int) (v_8 Int) (v_9 Int) (v_10 Int) (v_11 Int) (v_12 Int) (v_13 Int) ) 
    (=>
      (and
        (and true
     (= v_7 A)
     (= v_8 B)
     (= v_9 C)
     (= v_10 D)
     (= v_11 E)
     (= v_12 F)
     (= v_13 G))
      )
      (h1 A B C D E F G v_7 v_8 v_9 v_10 v_11 v_12 v_13)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (h1 A B C D E F G O P Q R L M N)
        (and (= J 0) (= I 0) (= H 1) (= K 0))
      )
      (h2 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h2 A B C D E F G H I J K L M N)
        true
      )
      (h3 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h3 A B C D E F G H I J K L M N)
        true
      )
      (h4 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h4 A B C D E F G H I J K L M N)
        true
      )
      (h5 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h5 A B C D E F G H I J K L M N)
        true
      )
      (h6 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h6 A B C D E F G H I J K L M N)
        true
      )
      (h7 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h7 A B C D E F G H I J K L M N)
        true
      )
      (h8 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h8 A B C D E F G H I J K L M N)
        (<= N (- 1))
      )
      (h9 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h9 A B C D E F G H I J K L M N)
        true
      )
      (h10 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h8 A B C D E F G H I J K L M N)
        (>= N 1)
      )
      (h11 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h11 A B C D E F G H I J K L M N)
        true
      )
      (h10 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h8 A B C D E F G H I J K L M N)
        (= N 0)
      )
      (h12 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h12 A B C D E F G H I J K L M N)
        true
      )
      (h13 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h13 A B C D E F G H I J K L M N)
        true
      )
      (h14 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h10 A B C D E F G H I J K L M N)
        true
      )
      (h15 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h15 A B C D E F G H I J K L M N)
        true
      )
      (h16 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h16 A B C D E F G H I J K L M N)
        true
      )
      (h17 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h17 A B C D E F G H I J K L M N)
        true
      )
      (h18 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h18 A B C D E F G H I J K L M N)
        true
      )
      (h19 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h19 A B C D E F G H I J K L M N)
        (<= L (- 1))
      )
      (h20 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h20 A B C D E F G H I J K L M N)
        true
      )
      (h21 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h19 A B C D E F G H I J K L M N)
        (>= L 1)
      )
      (h22 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h22 A B C D E F G H I J K L M N)
        true
      )
      (h21 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h19 A B C D E F G H I J K L M N)
        (= L 0)
      )
      (h23 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h23 A B C D E F G H I J K L M N)
        true
      )
      (h24 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h24 A B C D E F G H I J K L M N)
        true
      )
      (h25 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h21 A B C D E F G H I J K L M N)
        true
      )
      (h26 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) ) 
    (=>
      (and
        (h26 A B C D E F G H I O K L M N)
        (= O (+ (- 1) J))
      )
      (h27 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h21 A B C D E F G H I J K L M N)
        true
      )
      (h28 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h28 A B C D E F G H I J K L M N)
        true
      )
      (h29 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h21 A B C D E F G H I J K L M N)
        true
      )
      (h30 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h30 A B C D E F G H I J K L M N)
        true
      )
      (h29 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h27 A B C D E F G H I J K L M N)
        true
      )
      (h29 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h29 A B C D E F G H I J K L M N)
        true
      )
      (h31 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) ) 
    (=>
      (and
        (h31 A B C D E F G H I J O L M N)
        (= O (+ (- 1) K))
      )
      (h32 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h29 A B C D E F G H I J K L M N)
        true
      )
      (h33 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h33 A B C D E F G H I J K L M N)
        true
      )
      (h16 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h29 A B C D E F G H I J K L M N)
        true
      )
      (h34 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h34 A B C D E F G H I J K L M N)
        true
      )
      (h16 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h32 A B C D E F G H I J K L M N)
        true
      )
      (h16 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h25 A B C D E F G H I J K L M N)
        true
      )
      (h35 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h35 A B C D E F G H I J K L M N)
        true
      )
      (h36 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h36 A B C D E F G H I J K L M N)
        true
      )
      (h37 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h37 A B C D E F G H I J K L M N)
        true
      )
      (h38 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h38 A B C D E F G H I J K L M N)
        true
      )
      (h39 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h39 A B C D E F G H I J K L M N)
        true
      )
      (h40 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h40 A B C D E F G H I J K L M N)
        (<= M (- 1))
      )
      (h41 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (h41 A B C D E F G O P J K L M N)
        (and (= J (+ (* (- 1) K) I)) (= H (+ 1 I)))
      )
      (h42 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h40 A B C D E F G H I J K L M N)
        (>= M 1)
      )
      (h43 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) ) 
    (=>
      (and
        (h43 A B C D E F G O P J K L M N)
        (and (= J (+ (* (- 1) K) I)) (= H (+ 1 I)))
      )
      (h42 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h40 A B C D E F G H I J K L M N)
        (= M 0)
      )
      (h44 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h44 A B C D E F G H I J K L M N)
        true
      )
      (h45 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h45 A B C D E F G H I J K L M N)
        true
      )
      (h46 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h42 A B C D E F G H I J K L M N)
        true
      )
      (h37 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h46 A B C D E F G H I J K L M N)
        true
      )
      (h5 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h14 A B C D E F G H I J K L M N)
        true
      )
      (h47 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h47 A B C D E F G H I J K L M N)
        (<= (+ J (* (- 1) K)) (- 1))
      )
      (h48 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h47 A B C D E F G H I J K L M N)
        (>= (+ J (* (- 1) K)) 1)
      )
      (h49 A B C D E F G H I J K L M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h48 A B C D E F G H I J K L M N)
        true
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) ) 
    (=>
      (and
        (h49 A B C D E F G H I J K L M N)
        true
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        CHC_COMP_FALSE
      )
      false
    )
  )
)

(check-sat)
(exit)
