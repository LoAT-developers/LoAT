; ./tricera/sv-comp-2020/./mixed/test_locks_11.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main153| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main124| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main136| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main142| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main88| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main36| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main70| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main130| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main112| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main106| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main94| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main76| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main100| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main118| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main2| ( ) Bool)
(declare-fun |inv_main58| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main82| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main85| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main64| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) ) 
    (=>
      (and
        (inv_main36 V H1 P M O Y Z N F E1 B K F1 G1 A1 D G D1 Q A L W U)
        (and (= C1 0)
     (= B1 0)
     (= X 0)
     (not (= V 0))
     (= T 1)
     (= S 0)
     (= R 0)
     (not (= P 0))
     (not (= J 0))
     (= I 0)
     (= H 0)
     (= E 0)
     (= C 1)
     (= I1 0))
      )
      (inv_main58 V C P T O H Z X F I B I1 F1 S A1 C1 G E Q R L B1 J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) ) 
    (=>
      (and
        (inv_main36 W J P G1 A1 A O E1 U F1 D I1 V D1 X S L Z H Y C1 I R)
        (and (= B1 0)
     (not (= W 0))
     (= T 1)
     (= Q 0)
     (= P 0)
     (= N 0)
     (= M 0)
     (= K 0)
     (= G 0)
     (= F 0)
     (not (= E 0))
     (= C 0)
     (= B 0)
     (= H1 0))
      )
      (inv_main58 W T P G A1 N O H1 U C D M V B1 X Q L F H B C1 K E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) ) 
    (=>
      (and
        (inv_main36 F1 E A1 C1 M W G B K E1 D1 S Z N F I1 J T C B1 D A O)
        (and (= G1 0)
     (= F1 0)
     (not (= A1 0))
     (= Y 0)
     (= X 1)
     (= V 0)
     (= U 0)
     (= R 0)
     (= Q 0)
     (not (= P 0))
     (= L 0)
     (= I 0)
     (= H 0)
     (= H1 0))
      )
      (inv_main58 F1 V A1 X M U G I K Y D1 L Z H F H1 J G1 C R D Q P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) ) 
    (=>
      (and
        (inv_main36 Q P J E1 D1 N C1 X H1 Z I H F1 B1 K E B G I1 U R F M)
        (and (= A1 0)
     (not (= Y 0))
     (= W 0)
     (= V 0)
     (= T 0)
     (= S 0)
     (= Q 0)
     (= O 0)
     (= L 0)
     (= J 0)
     (= D 0)
     (= C 0)
     (= A 0)
     (= G1 0))
      )
      (inv_main58 Q A J C D1 V C1 L H1 O I S F1 D K G1 B A1 I1 T R W Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main112 T E A B L D V M O Q U S G F J R P K H N W C I)
        (= U 0)
      )
      (inv_main118 T E A B L D V M O Q U S G F J R P K H N W C I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main112 V J B F H Q M I U X S T L C W G P N E O R D K)
        (and (not (= S 0)) (= A 0) (= T 1))
      )
      (inv_main118 V J B F H Q M I U X S A L C W G P N E O R D K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main118 C P V J W R L U D A Q G T O F S K H N E M I B)
        (= T 0)
      )
      (inv_main124 C P V J W R L U D A Q G T O F S K H N E M I B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main118 C I X H M F Q P T L K G S E A D R B J O W U N)
        (and (not (= S 0)) (= E 1) (= V 0))
      )
      (inv_main124 C I X H M F Q P T L K G S V A D R B J O W U N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main64 I H V U X G R O M T Q F E B J N W C L P Y D S)
        (and (not (= M 0)) (= K 1) (= A 1) (not (= Q 0)))
      )
      (inv_main70 I H V U X G R O M A Q K E B J N W C L P Y D S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main64 F S P D C R B T X J H G I A E Q V W O L U N K)
        (and (= M 1) (= H 0) (not (= X 0)))
      )
      (inv_main70 F S P D C R B T X M H G I A E Q V W O L U N K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main64 J F K A E W O V B H C U T D I L X G N S M R P)
        (and (not (= C 0)) (= B 0) (= Q 1))
      )
      (inv_main70 J F K A E W O V B H C Q T D I L X G N S M R P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main64 T M E I A N K O U P W C L J V B H G D Q S R F)
        (and (= U 0) (= W 0))
      )
      (inv_main70 T M E I A N K O U P W C L J V B H G D Q S R F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main124 E D I F C O A H K Q R P W M N L J G U B T V S)
        (= N 0)
      )
      (inv_main130 E D I F C O A H K Q R P W M N L J G U B T V S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main124 L Q H K I F O G S R M W A U X V P B J C E N T)
        (and (= V 1) (= D 0) (not (= X 0)))
      )
      (inv_main130 L Q H K I F O G S R M W A U X D P B J C E N T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main94 T I R J U P O H C N B Q G W S V D K L A M F E)
        (= U 0)
      )
      (inv_main100 T I R J U P O H C N B Q G W S V D K L A M F E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main94 E I M Q S V L W K F J N B G P O T C H X D A R)
        (and (= U 0) (not (= S 0)) (= V 1))
      )
      (inv_main100 E I M Q S U L W K F J N B G P O T C H X D A R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main85 J N F M B H P S V T L A C D E O G I U R Q W K)
        (and (not (= J 0)) (not (= N 1)))
      )
      (inv_main153 J N F M B H P S V T L A C D E O G I U R Q W K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main88 C P H T E R M L A J I F B N S G U W Q O D V K)
        (and (not (= H 0)) (not (= T 1)))
      )
      (inv_main153 C P H T E R M L A J I F B N S G U W Q O D V K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main94 T M D Q P V C H L S F K W N R A I B G J E U O)
        (and (not (= P 0)) (not (= V 1)))
      )
      (inv_main153 T M D Q P V C H L S F K W N R A I B G J E U O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main100 Q M B G W L R V S U K J E P D I T O H C A N F)
        (and (not (= R 0)) (not (= V 1)))
      )
      (inv_main153 Q M B G W L R V S U K J E P D I T O H C A N F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main106 C F N M B P U E T I A O W S J G H R V L Q K D)
        (and (not (= I 1)) (not (= T 0)))
      )
      (inv_main153 C F N M B P U E T I A O W S J G H R V L Q K D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main112 K J P E N G L V A R B U H M T C Q S F O D I W)
        (and (not (= B 0)) (not (= U 1)))
      )
      (inv_main153 K J P E N G L V A R B U H M T C Q S F O D I W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main118 Q P R H L J W U V M G K B T S A D C F N E I O)
        (and (not (= B 0)) (not (= T 1)))
      )
      (inv_main153 Q P R H L J W U V M G K B T S A D C F N E I O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main124 C L R A E U O D P G K H S M T Q N J B F V I W)
        (and (not (= Q 1)) (not (= T 0)))
      )
      (inv_main153 C L R A E U O D P G K H S M T Q N J B F V I W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main130 O G R I B V Q F J D P T K E M L A S U N H C W)
        (and (not (= A 0)) (not (= S 1)))
      )
      (inv_main153 O G R I B V Q F J D P T K E M L A S U N H C W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main136 C R A L E Q M P I D W B N F V T H K J S O U G)
        (and (not (= J 0)) (not (= S 1)))
      )
      (inv_main153 C R A L E Q M P I D W B N F V T H K J S O U G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main142 K S D J E W M Q C N I R P F B G V O H A U L T)
        (and (not (= L 1)) (not (= U 0)))
      )
      (inv_main153 K S D J E W M Q C N I R P F B G V O H A U L T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main142 G C K W U E O I T Q P D A F R H M J V S N L B)
        (= N 0)
      )
      (inv_main36 G C K W U E O I T Q P D A F R H M J V S N L B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main142 I X M F G T K Q W U N O V A C S L E H R P B D)
        (and (= J 0) (= B 1) (not (= P 0)))
      )
      (inv_main36 I X M F G T K Q W U N O V A C S L E H R P J D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        inv_main2
        true
      )
      (inv_main36 R M N T O V S F W H E B L U I Q D P C G K A J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main85 V U W O F J B L D A R N T M C P E Q S H K G I)
        (= V 0)
      )
      (inv_main88 V U W O F J B L D A R N T M C P E Q S H K G I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main85 X T E W P V L S J R D O H G C M F B U N K I Q)
        (and (= T 1) (= A 0) (not (= X 0)))
      )
      (inv_main88 X A E W P V L S J R D O H G C M F B U N K I Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main82 R B P H W O S K Q U V G T F E A L X J C D N I)
        (and (not (= D 0)) (= M 1))
      )
      (inv_main85 R B P H W O S K Q U V G T F E A L X J C D M I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main82 A L C W E S R T Q P I N H J D G V K M U B O F)
        (= B 0)
      )
      (inv_main85 A L C W E S R T Q P I N H J D G V K M U B O F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main130 V B A N M G F U D J T I W E O H K S Q C L R P)
        (= K 0)
      )
      (inv_main136 V B A N M G F U D J T I W E O H K S Q C L R P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main130 H D T G O L Q B R J K E V X P C S N M A I F W)
        (and (not (= S 0)) (= N 1) (= U 0))
      )
      (inv_main136 H D T G O L Q B R J K E V X P C S U M A I F W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main100 U K L O G V M P E H S T N I B C F J A Q D W R)
        (= M 0)
      )
      (inv_main106 U K L O G V M P E H S T N I B C F J A Q D W R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main100 J Q P E G S A K D R F O I N H C M V T U W B X)
        (and (= K 1) (not (= A 0)) (= L 0))
      )
      (inv_main106 J Q P E G S A L D R F O I N H C M V T U W B X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main76 H E P U Y K S G T Q R B A I D N L J O W X C F)
        (and (not (= O 0)) (= M 1) (not (= L 0)) (= V 1))
      )
      (inv_main82 H E P U Y K S G T Q R B A I D N L M O V X C F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main76 Q E D R M G L N J F V P A I T X B U C S O H K)
        (and (= C 0) (not (= B 0)) (= W 1))
      )
      (inv_main82 Q E D R M G L N J F V P A I T X B W C S O H K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main76 V Q W S E M U J A P X O R N F I H G T D C K B)
        (and (= L 1) (= H 0) (not (= T 0)))
      )
      (inv_main82 V Q W S E M U J A P X O R N F I H G T L C K B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main76 J F Q S W T U G A H I R M K B C L E V O P N D)
        (and (= L 0) (= V 0))
      )
      (inv_main82 J F Q S W T U G A H I R M K B C L E V O P N D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main58 G M L Y U Q R O K H X J F T W P V E S N B A C)
        (and (not (= R 0)) (= I 1) (= D 1) (not (= U 0)))
      )
      (inv_main64 G M L Y U D R I K H X J F T W P V E S N B A C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main58 V F Q P X O G S K U W H T B D N A E R J L I M)
        (and (= G 0) (= C 1) (not (= X 0)))
      )
      (inv_main64 V F Q P X C G S K U W H T B D N A E R J L I M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main58 V R O P N H G D C S M L W J X I U F B K E T Q)
        (and (not (= G 0)) (= A 1) (= N 0))
      )
      (inv_main64 V R O P N H G A C S M L W J X I U F B K E T Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main58 P Q F A M R L V H E B S K U D G J W T C I O N)
        (and (= L 0) (= M 0))
      )
      (inv_main64 P Q F A M R L V H E B S K U D G J W T C I O N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main88 N S I Q P O A G J B C E K D H M L W F R V U T)
        (= I 0)
      )
      (inv_main94 N S I Q P O A G J B C E K D H M L W F R V U T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main88 H D G B C W T R L A U I J F S K X V E O M N P)
        (and (not (= G 0)) (= B 1) (= Q 0))
      )
      (inv_main94 H D G Q C W T R L A U I J F S K X V E O M N P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main106 L J D F Q P A I R O K H B V G W C E U M T N S)
        (= R 0)
      )
      (inv_main112 L J D F Q P A I R O K H B V G W C E U M T N S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main106 L X K S G A O P U M R V J W B T Q N E F D C I)
        (and (= M 1) (= H 0) (not (= U 0)))
      )
      (inv_main112 L X K S G A O P U H R V J W B T Q N E F D C I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main136 A O C W V Q L M K T D N J B U I H F S R P G E)
        (= S 0)
      )
      (inv_main142 A O C W V Q L M K T D N J B U I H F S R P G E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main136 V U H M B W A J N I T G X F K C Q S E O L P D)
        (and (= O 1) (not (= E 0)) (= R 0))
      )
      (inv_main142 V U H M B W A J N I T G X F K C Q S E R L P D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main70 J W Y F O A T V E I S R H L Q X D C B U K P G)
        (and (= N 1) (= M 1) (not (= H 0)) (not (= Q 0)))
      )
      (inv_main76 J W Y F O A T V E I S R H N Q M D C B U K P G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main70 P J F Q M H X D A S T E B W L K V R I G O N U)
        (and (= C 1) (not (= B 0)) (= L 0))
      )
      (inv_main76 P J F Q M H X D A S T E B C L K V R I G O N U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) ) 
    (=>
      (and
        (inv_main70 V A R W C D G K E X S J L H P M O F N U T Q B)
        (and (= L 0) (= I 1) (not (= P 0)))
      )
      (inv_main76 V A R W C D G K E X S J L H P I O F N U T Q B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main70 W L Q N C V G D S I F E O U M R P A K T J B H)
        (and (= M 0) (= O 0))
      )
      (inv_main76 W L Q N C V G D S I F E O U M R P A K T J B H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) ) 
    (=>
      (and
        (inv_main153 E J F D S W H O U V K A T R Q B G C I L P M N)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
