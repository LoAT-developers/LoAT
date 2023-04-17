; ./tricera/sv-comp-2020/./mixed/test_locks_10.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main99| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main33| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main105| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main93| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main2| ( ) Bool)
(declare-fun |inv_main72| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main78| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main140| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main117| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main66| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main123| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main87| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main54| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main81| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main60| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main129| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main111| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main66 S N V F D A Q K C B O E J H M G T W I L U)
        (and (= P 1) (not (= M 0)) (not (= J 0)) (= R 1))
      )
      (inv_main72 S N V F D A Q K C B O E J R M P T W I L U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main66 U J Q I H V D M P B K L G C T O F E S N A)
        (and (= R 1) (not (= G 0)) (= T 0))
      )
      (inv_main72 U J Q I H V D M P B K L G R T O F E S N A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main66 G H V E M A C N U L B T F D P O I R J K S)
        (and (not (= P 0)) (= F 0) (= Q 1))
      )
      (inv_main72 G H V E M A C N U L B T F D P Q I R J K S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main66 F N P E L M H D C U B Q I T G S K J A R O)
        (and (= G 0) (= I 0))
      )
      (inv_main72 F N P E L M H D C U B Q I T G S K J A R O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main105 P D F G I A Q K B H O C N R S T M E J L U)
        (= O 0)
      )
      (inv_main111 P D F G I A Q K B H O C N R S T M E J L U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main105 G I V J H S O Q U K D P N C L B R E M A T)
        (and (= F 0) (not (= D 0)) (= P 1))
      )
      (inv_main111 G I V J H S O Q U K D F N C L B R E M A T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main60 U O W S V E R N C B D M K G J A H Q P T F)
        (and (= I 1) (not (= D 0)) (not (= C 0)) (= L 1))
      )
      (inv_main66 U O W S V E R N C I D L K G J A H Q P T F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main60 Q D S C O E V B A K H G I N P J U R T L F)
        (and (= H 0) (not (= A 0)) (= M 1))
      )
      (inv_main66 Q D S C O E V B A M H G I N P J U R T L F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main60 U K S H R J C D B V G E I Q T P A O M N L)
        (and (= F 1) (= B 0) (not (= G 0)))
      )
      (inv_main66 U K S H R J C D B V G F I Q T P A O M N L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main60 N S R H G L Q J K F T O I C U B A E P M D)
        (and (= K 0) (= T 0))
      )
      (inv_main66 N S R H G L Q J K F T O I C U B A E P M D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main72 E W I V U F R H B T G K L J S M D C N Q O)
        (and (not (= N 0)) (not (= D 0)) (= A 1) (= P 1))
      )
      (inv_main78 E W I V U F R H B T G K L J S M D P N A O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main72 J L Q T S K A V F M O C R B H P D E I U G)
        (and (= I 0) (not (= D 0)) (= N 1))
      )
      (inv_main78 J L Q T S K A V F M O C R B H P D N I U G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main72 M U H O E I Q R K S F J D N C L A G T V P)
        (and (= B 1) (= A 0) (not (= T 0)))
      )
      (inv_main78 M U H O E I Q R K S F J D N C L A G T B P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main72 O T K I C L R Q F H J N P A E M B S D U G)
        (and (= B 0) (= D 0))
      )
      (inv_main78 O T K I C L R Q F H J N P A E M B S D U G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main111 F C A J I U G Q R T H O L K B N P D S E M)
        (= L 0)
      )
      (inv_main117 F C A J I U G Q R T H O L K B N P D S E M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main111 B J H C I O D U S F K L N R G M Q A V E P)
        (and (= R 1) (not (= N 0)) (= T 0))
      )
      (inv_main117 B J H C I O D U S F K L N T G M Q A V E P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main129 K T O G B S C D R L H F U J P N I M E Q A)
        (= E 0)
      )
      (inv_main33 K T O G B S C D R L H F U J P N I M E Q A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main129 S P R H E M A N J O T C V I K B U G D Q L)
        (and (= F 0) (not (= D 0)) (= Q 1))
      )
      (inv_main33 S P R H E M A N J O T C V I K B U G D F L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        inv_main2
        true
      )
      (inv_main33 Q H E S D R T I F C M A G J O P N U L B K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main93 S H A N K B J L D I F C G E M P Q U T R O)
        (= J 0)
      )
      (inv_main99 S H A N K B J L D I F C G E M P Q U T R O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main93 F A P N V C U D I G R B J E K H Q O M T L)
        (and (= S 0) (= D 1) (not (= U 0)))
      )
      (inv_main99 F A P N V C U S I G R B J E K H Q O M T L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main33 R C Y Q F U A1 D1 D I V F1 H A T B1 X P E G B)
        (and (not (= C1 0))
     (= Z 1)
     (not (= Y 0))
     (= W 0)
     (= S 0)
     (not (= R 0))
     (= O 0)
     (= N 0)
     (= M 0)
     (= L 1)
     (= K 0)
     (= J 0)
     (= E1 0))
      )
      (inv_main54 R Z Y L F W A1 J D S V M H O T E1 X K E N C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main33 D1 Y A E1 J M O Q W C B C1 R G E T V F1 D F P)
        (and (= H 0)
     (= A 0)
     (not (= D1 0))
     (= B1 0)
     (= A1 1)
     (= Z 0)
     (= X 0)
     (= U 0)
     (= S 0)
     (= N 0)
     (not (= L 0))
     (= K 0)
     (= I 0))
      )
      (inv_main54 D1 A1 A Z J N O K W B1 B I R H E S V X D U L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main33 O L K X E1 V D1 Y S T J I P B Z N B1 R A1 C U)
        (and (= G 0)
     (= F 0)
     (= E 0)
     (= D 1)
     (= A 0)
     (not (= F1 0))
     (= C1 0)
     (= W 0)
     (= Q 0)
     (= O 0)
     (= M 0)
     (not (= K 0))
     (= H 0))
      )
      (inv_main54 O A K D E1 Q D1 H S F J E P C1 Z W B1 M A1 G F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main33 C1 H B1 I D1 R Z J Q T B Y O N E1 M F1 X V D K)
        (and (= F 0)
     (= E 0)
     (= C 0)
     (= A 0)
     (= C1 0)
     (= B1 0)
     (= A1 0)
     (= W 0)
     (= U 0)
     (= S 0)
     (not (= P 0))
     (= L 0)
     (= G 0))
      )
      (inv_main54 C1 W B1 C D1 S Z L Q A B E O G E1 F F1 U V A1 P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main78 S I A Q U F K P G D B T J N O M H C R L E)
        (= S 0)
      )
      (inv_main81 S I A Q U F K P G D B T J N O M H C R L E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main78 M G J P A U B K H C R Q N I T F S E L V D)
        (and (not (= M 0)) (= G 1) (= O 0))
      )
      (inv_main81 M O J P A U B K H C R Q N I T F S E L V D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main117 F H L R T M S K G Q B A P C D N U E O J I)
        (= D 0)
      )
      (inv_main123 F H L R T M S K G Q B A P C D N U E O J I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main117 C F V A R U E D O G P H K M S Q T J B I L)
        (and (= Q 1) (= N 0) (not (= S 0)))
      )
      (inv_main123 C F V A R U E D O G P H K M S N T J B I L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main87 R G T C H I Q U B F P D J S O E K L N M A)
        (= H 0)
      )
      (inv_main93 R G T C H I Q U B F P D J S O E K L N M A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main87 F A L Q C R I T N K B P E O J D H V S G M)
        (and (= R 1) (not (= C 0)) (= U 0))
      )
      (inv_main93 F A L Q C U I T N K B P E O J D H V S G M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main81 Q U F S N P I A H L T G B R D O K M E C J)
        (= F 0)
      )
      (inv_main87 Q U F S N P I A H L T G B R D O K M E C J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main81 J N D A G V I B L C H Q T M O U K F P R E)
        (and (not (= D 0)) (= A 1) (= S 0))
      )
      (inv_main87 J N D S G V I B L C H Q T M O U K F P R E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main99 S R T B J O A I Q E D U H P G C N F M L K)
        (= Q 0)
      )
      (inv_main105 S R T B J O A I Q E D U H P G C N F M L K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main99 P E S V T N D U O C F K B H A R L M Q I J)
        (and (= G 0) (= C 1) (not (= O 0)))
      )
      (inv_main105 P E S V T N D U O G F K B H A R L M Q I J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main123 U C G T P D J F K B A S N O L M Q I H R E)
        (= Q 0)
      )
      (inv_main129 U C G T P D J F K B A S N O L M Q I H R E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main123 E S R H K V G D U A T C Q J O P L B N M I)
        (and (= F 0) (= B 1) (not (= L 0)))
      )
      (inv_main129 E S R H K V G D U A T C Q J O P L F N M I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main78 E D B T M O A G C S N Q J L P F K I H U R)
        (and (not (= D 1)) (not (= E 0)))
      )
      (inv_main140 E D B T M O A G C S N Q J L P F K I H U R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main81 L E Q A C U H N I G F B K J P T M O S D R)
        (and (not (= A 1)) (not (= Q 0)))
      )
      (inv_main140 L E Q A C U H N I G F B K J P T M O S D R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main87 C R P O N M I J H G E K T A Q L D B F S U)
        (and (not (= M 1)) (not (= N 0)))
      )
      (inv_main140 C R P O N M I J H G E K T A Q L D B F S U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main93 O Q A F L S E I C H R D U G N P J T K M B)
        (and (not (= E 0)) (not (= I 1)))
      )
      (inv_main140 O Q A F L S E I C H R D U G N P J T K M B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main99 N D M F J H R L O B P I Q E K U S C G A T)
        (and (not (= B 1)) (not (= O 0)))
      )
      (inv_main140 N D M F J H R L O B P I Q E K U S C G A T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main105 S M B U G H R O A T F L I Q D N J E C P K)
        (and (not (= F 0)) (not (= L 1)))
      )
      (inv_main140 S M B U G H R O A T F L I Q D N J E C P K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main111 I T M A L E C U R K G Q P B S F J O N H D)
        (and (not (= B 1)) (not (= P 0)))
      )
      (inv_main140 I T M A L E C U R K G Q P B S F J O N H D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main117 D A M K G P Q N C S I R O H L E F U T B J)
        (and (not (= E 1)) (not (= L 0)))
      )
      (inv_main140 D A M K G P Q N C S I R O H L E F U T B J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main123 T S C U R N G P Q O E A M B D F L H K J I)
        (and (not (= H 1)) (not (= L 0)))
      )
      (inv_main140 T S C U R N G P Q O E A M B D F L H K J I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main129 A U D N T F C O J E B M G L P K H S Q R I)
        (and (not (= Q 0)) (not (= R 1)))
      )
      (inv_main140 A U D N T F C O J E B M G L P K H S Q R I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main54 U N W L P H D F E T K V G C J S Q B A M I)
        (and (not (= P 0)) (= O 1) (not (= D 0)) (= R 1))
      )
      (inv_main60 U N W L P O D R E T K V G C J S Q B A M I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main54 V G C R I L N E D F M J B U K P O Q T H S)
        (and (not (= I 0)) (= A 1) (= N 0))
      )
      (inv_main60 V G C R I A N E D F M J B U K P O Q T H S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) ) 
    (=>
      (and
        (inv_main54 J M N F I H V P D L U E T C B O G A R K S)
        (and (= Q 1) (= I 0) (not (= V 0)))
      )
      (inv_main60 J M N F I H V Q D L U E T C B O G A R K S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main54 S H J N M L U P E R I F T A Q K B C O G D)
        (and (= M 0) (= U 0))
      )
      (inv_main60 S H J N M L U P E R I F T A Q K B C O G D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) ) 
    (=>
      (and
        (inv_main140 K I E R U M A T D P O H N C F S B L J Q G)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
