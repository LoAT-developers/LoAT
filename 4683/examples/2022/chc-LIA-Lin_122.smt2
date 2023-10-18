; ./tricera/sv-comp-2020/./mixed/test_locks_8.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main46| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main2| ( ) Bool)
(declare-fun |inv_main103| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main73| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main97| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main64| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main114| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main27| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main91| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main85| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main79| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main52| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main58| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main67| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (CHC_COMP_UNUSED Bool) ) 
    (=>
      (and
        true
      )
      inv_main2
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main64 H C I D B J P E O G L N F M K A Q)
        (= H 0)
      )
      (inv_main67 H C I D B J P E O G L N F M K A Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main64 F B R J K I P Q G A M H D L O C E)
        (and (not (= F 0)) (= B 1) (= N 0))
      )
      (inv_main67 F N R J K I P Q G A M H D L O C E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main103 N P M K Q J A C L F E H B D I G O)
        (= I 0)
      )
      (inv_main27 N P M K Q J A C L F E H B D I G O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main103 P J G F N M O Q K C E B D L H I A)
        (and (= I 1) (not (= H 0)) (= R 0))
      )
      (inv_main27 P J G F N M O Q K C E B D L H R A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        inv_main2
        true
      )
      (inv_main27 G H Q J L K I B M C N O F P E D A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main73 G I D L Q P B E N O F K A M J C H)
        (= Q 0)
      )
      (inv_main79 G I D L Q P B E N O F K A M J C H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main73 A G L J B O E H I Q F N R M P D C)
        (and (= K 0) (not (= B 0)) (= O 1))
      )
      (inv_main79 A G L J B K E H I Q F N R M P D C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main91 K C I L O B D J F G A H E P N M Q)
        (= A 0)
      )
      (inv_main97 K C I L O B D J F G A H E P N M Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main91 P R N K F A C J M B I L H E Q O G)
        (and (not (= I 0)) (= D 0) (= L 1))
      )
      (inv_main97 P R N K F A C J M B I D H E Q O G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) ) 
    (=>
      (and
        (inv_main46 E P M G O K F D H A S L J I C Q N)
        (and (= R 1) (not (= O 0)) (not (= F 0)) (= B 1))
      )
      (inv_main52 E P M G O R F B H A S L J I C Q N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main46 B M R F N L Q K P J G O E C A H D)
        (and (not (= N 0)) (= I 1) (= Q 0))
      )
      (inv_main52 B M R F N I Q K P J G O E C A H D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main46 O I G F A D N K J H B L P R Q C M)
        (and (not (= N 0)) (= E 1) (= A 0))
      )
      (inv_main52 O I G F A D N E J H B L P R Q C M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main46 N G O C D F B P E A L M I K H Q J)
        (and (= B 0) (= D 0))
      )
      (inv_main52 N G O C D F B P E A L M I K H Q J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main64 P C D B M E I G O J F Q A H N L K)
        (and (not (= C 1)) (not (= P 0)))
      )
      (inv_main114 P C D B M E I G O J F Q A H N L K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main67 O M L E Q I P B K H C F D A G J N)
        (and (not (= E 1)) (not (= L 0)))
      )
      (inv_main114 O M L E Q I P B K H C F D A G J N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main73 A E I K F N L J H D P G O B Q C M)
        (and (not (= F 0)) (not (= N 1)))
      )
      (inv_main114 A E I K F N L J H D P G O B Q C M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main79 K J H Q L A D E G F B M P O C I N)
        (and (not (= D 0)) (not (= E 1)))
      )
      (inv_main114 K J H Q L A D E G F B M P O C I N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main85 E L G K O Q A I D N F M P C H B J)
        (and (not (= D 0)) (not (= N 1)))
      )
      (inv_main114 E L G K O Q A I D N F M P C H B J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main91 M J O H E D N L I B P A G C Q K F)
        (and (not (= A 1)) (not (= P 0)))
      )
      (inv_main114 M J O H E D N L I B P A G C Q K F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main97 G K I Q B L C P J D F E O N M H A)
        (and (not (= N 1)) (not (= O 0)))
      )
      (inv_main114 G K I Q B L C P J D F E O N M H A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main103 O G N J I P Q E K M B C A F L H D)
        (and (not (= H 1)) (not (= L 0)))
      )
      (inv_main114 O G N J I P Q E K M B C A F L H D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main85 F H B G K M J O P A Q E I L C N D)
        (= P 0)
      )
      (inv_main91 F H B G K M J O P A Q E I L C N D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main85 E Q O J K L F M D H C N A R B G P)
        (and (= H 1) (not (= D 0)) (= I 0))
      )
      (inv_main91 E Q O J K L F M D I C N A R B G P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) ) 
    (=>
      (and
        (inv_main58 Q S M G E J I O B F P L D A H K R)
        (and (not (= H 0)) (not (= D 0)) (= C 1) (= N 1))
      )
      (inv_main64 Q S M G E J I O B F P L D N H C R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main58 J K L C D E F I P R A N H Q G M B)
        (and (not (= H 0)) (= G 0) (= O 1))
      )
      (inv_main64 J K L C D E F I P R A N H O G M B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main58 Q J E D K N P O L H C F B A R M I)
        (and (= G 1) (= B 0) (not (= R 0)))
      )
      (inv_main64 Q J E D K N P O L H C F B A R G I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main58 Q B P N F I O K C D J M E L H A G)
        (and (= E 0) (= H 0))
      )
      (inv_main64 Q B P N F I O K C D J M E L H A G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main27 X K H C P O T A U B J Y Q G R Z N)
        (and (= E 1)
     (= D 0)
     (not (= H 0))
     (= I 0)
     (not (= X 0))
     (= W 0)
     (= V 0)
     (= S 1)
     (not (= M 0))
     (= L 0)
     (= F 0))
      )
      (inv_main46 X S H E P L T D U I J W Q F R V M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main27 E M Y U G Z Q N I W S L R T P F D)
        (and (= C 0)
     (= B 0)
     (= A 0)
     (= H 0)
     (= Y 0)
     (= X 0)
     (= V 0)
     (= O 1)
     (not (= K 0))
     (= J 0)
     (not (= E 0)))
      )
      (inv_main46 E O Y H G C Q X I V S J R B P A K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main27 E Z F S R J Y V W Q X C B O M L U)
        (and (not (= F 0))
     (= E 0)
     (= D 1)
     (= A 0)
     (= H 0)
     (not (= I 0))
     (= T 0)
     (= P 0)
     (= N 0)
     (= K 0)
     (= G 0))
      )
      (inv_main46 E K F D R G Y H W P X T B N M A I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main27 O E S F Z J Y A L G V K M R N I P)
        (and (= C 0)
     (= B 0)
     (= H 0)
     (not (= X 0))
     (= W 0)
     (= U 0)
     (= T 0)
     (= S 0)
     (= Q 0)
     (= O 0)
     (= D 0))
      )
      (inv_main46 O T S W Z Q Y C L B V H M U N D X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main67 F H K Q B A D L G O C P I E N J M)
        (= K 0)
      )
      (inv_main73 F H K Q B A D L G O C P I E N J M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main67 N F R E I A D J O M P Q B G C K H)
        (and (= L 0) (= E 1) (not (= R 0)))
      )
      (inv_main73 N F R L I A D J O M P Q B G C K H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main97 B G C Q E N H D K A J L P O M I F)
        (= P 0)
      )
      (inv_main103 B G C Q E N H D K A J L P O M I F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main97 D K H J E F L M A I G R B C P N O)
        (and (= C 1) (not (= B 0)) (= Q 0))
      )
      (inv_main103 D K H J E F L M A I G R B Q P N O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) ) 
    (=>
      (and
        (inv_main52 L K A H B R Q O G S E F D P N J M)
        (and (not (= G 0)) (not (= E 0)) (= C 1) (= I 1))
      )
      (inv_main58 L K A H B R Q O G C E I D P N J M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main52 I R Q O P H G B M J F A L K N D C)
        (and (= F 0) (= E 1) (not (= M 0)))
      )
      (inv_main58 I R Q O P H G B M E F A L K N D C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main52 B C G R K O I P M J N F E D H Q A)
        (and (= M 0) (= L 1) (not (= N 0)))
      )
      (inv_main58 B C G R K O I P M J N L E D H Q A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main52 N E A M Q D H P F J B I G C K O L)
        (and (= B 0) (= F 0))
      )
      (inv_main58 N E A M Q D H P F J B I G C K O L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main79 I E F G D Q M N L P J K A C B O H)
        (= M 0)
      )
      (inv_main85 I E F G D Q M N L P J K A C B O H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) ) 
    (=>
      (and
        (inv_main79 R M K J I O Q N A L B G P F D H E)
        (and (= N 1) (= C 0) (not (= Q 0)))
      )
      (inv_main85 R M K J I O Q C A L B G P F D H E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) ) 
    (=>
      (and
        (inv_main114 J K F P I O A G N B C M E D H Q L)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
