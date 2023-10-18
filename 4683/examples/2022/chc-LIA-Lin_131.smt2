; ./tricera/sv-comp-2020/./mixed/test_locks_12.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main107| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main125| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main143| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main39| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main101| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main131| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main80| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main155| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main62| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main92| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main166| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main137| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main95| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main113| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main86| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main2| ( ) Bool)
(declare-fun |inv_main74| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main68| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main119| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main149| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main92 N G W I S F Y O X U T R C E D M K B H L A J Q P V)
        (= N 0)
      )
      (inv_main95 N G W I S F Y O X U T R C E D M K B H L A J Q P V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main92 W D I B J L T H Z Q P K R V O U S X N M Y C A E G)
        (and (= F 0) (= D 1) (not (= W 0)))
      )
      (inv_main95 W F I B J L T H Z Q P K R V O U S X N M Y C A E G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main92 G D F S H R W X O P J U N T K C I B L Y V E A Q M)
        (and (not (= D 1)) (not (= G 0)))
      )
      (inv_main166 G D F S H R W X O P J U N T K C I B L Y V E A Q M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main95 A C W S G U I F V T L J K R M H D Y N B X E Q O P)
        (and (not (= S 1)) (not (= W 0)))
      )
      (inv_main166 A C W S G U I F V T L J K R M H D Y N B X E Q O P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main101 N Q Y D P J B O A W R F H S L C K I V G T X M U E)
        (and (not (= J 1)) (not (= P 0)))
      )
      (inv_main166 N Q Y D P J B O A W R F H S L C K I V G T X M U E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main107 F V J U K I E C L P W O D X B Y Q M R A T H G N S)
        (and (not (= C 1)) (not (= E 0)))
      )
      (inv_main166 F V J U K I E C L P W O D X B Y Q M R A T H G N S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main113 S F R C I J O X G Y V M H P N U T K A E Q D W B L)
        (and (not (= G 0)) (not (= Y 1)))
      )
      (inv_main166 S F R C I J O X G Y V M H P N U T K A E Q D W B L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main119 I C J M V Y K U O X B R T N W Q H E S P A D L G F)
        (and (not (= B 0)) (not (= R 1)))
      )
      (inv_main166 I C J M V Y K U O X B R T N W Q H E S P A D L G F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main125 E D H M U T V O A C X B W Y J I S K R P L Q N G F)
        (and (not (= W 0)) (not (= Y 1)))
      )
      (inv_main166 E D H M U T V O A C X B W Y J I S K R P L Q N G F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main131 Y M U O V K J D R P S A T B E X L G W F H I Q N C)
        (and (not (= E 0)) (not (= X 1)))
      )
      (inv_main166 Y M U O V K J D R P S A T B E X L G W F H I Q N C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main137 U J E I P A H L T V Q Y O M N W G K C S B F X R D)
        (and (not (= G 0)) (not (= K 1)))
      )
      (inv_main166 U J E I P A H L T V Q Y O M N W G K C S B F X R D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main143 D W H A Q J X R V Y U P B I M S L O N T K G F E C)
        (and (not (= N 0)) (not (= T 1)))
      )
      (inv_main166 D W H A Q J X R V Y U P B I M S L O N T K G F E C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main149 F J P O U A Y X W R L D V E M H N B I K S Q G T C)
        (and (not (= Q 1)) (not (= S 0)))
      )
      (inv_main166 F J P O U A Y X W R L D V E M H N B I K S Q G T C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main155 V Y I J P U E F G S K L D X M A R Q W O H C N B T)
        (and (not (= B 1)) (not (= N 0)))
      )
      (inv_main166 V Y I J P U E F G S K L D X M A R Q W O H C N B T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main131 U J Q S I W H K X O T R E Y C M P F V G B A D N L)
        (= C 0)
      )
      (inv_main137 U J Q S I W H K X O T R E Y C M P F V G B A D N L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main131 I Q C P U T E S K Y G W O V A N L M R D J F Z H X)
        (and (= N 1) (= B 0) (not (= A 0)))
      )
      (inv_main137 I Q C P U T E S K Y G W O V A B L M R D J F Z H X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main149 B V D W Q R C X L H F T Y K U O I A S P G N E J M)
        (= G 0)
      )
      (inv_main155 B V D W Q R C X L H F T Y K U O I A S P G N E J M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main149 K P U O V Y N X F M E S W L B R H T A D C Q Z I G)
        (and (= J 0) (not (= C 0)) (= Q 1))
      )
      (inv_main155 K P U O V Y N X F M E S W L B R H T A D C J Z I G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main155 D O Y P L U H G B T K E S X J R C Q W N V F A I M)
        (= A 0)
      )
      (inv_main39 D O Y P L U H G B T K E S X J R C Q W N V F A I M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main155 A Z Q C W U V J R E I D H O K N Y L B S G X T M F)
        (and (= P 0) (= M 1) (not (= T 0)))
      )
      (inv_main39 A Z Q C W U V J R E I D H O K N Y L B S G X T P F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        inv_main2
        true
      )
      (inv_main39 N U T J R M H B G V S E Q K X L W P I F A Y D O C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) ) 
    (=>
      (and
        (inv_main86 A M J U A1 H G Q C R W O F V K X T P I D L E B Z S)
        (and (= Y 1) (= N 1) (not (= L 0)) (not (= B 0)))
      )
      (inv_main92 A M J U A1 H G Q C R W O F V K X T P I D L N B Y S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main86 K U B P F M W N L A C G I T O V Z X R Y Q S E J H)
        (and (= E 0) (= D 1) (not (= Q 0)))
      )
      (inv_main92 K U B P F M W N L A C G I T O V Z X R Y Q D E J H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main86 Q F R D M X L U Y A C P E K O W B S T Z H N I V G)
        (and (not (= I 0)) (= H 0) (= J 1))
      )
      (inv_main92 Q F R D M X L U Y A C P E K O W B S T Z H N I J G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main86 I B N S L M V X O F U J P Q A E R G K Y H C W D T)
        (and (= H 0) (= W 0))
      )
      (inv_main92 I B N S L M V X O F U J P Q A E R G K Y H C W D T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main137 I E G F K U X R N V W P C A M T J D H Y Q S L B O)
        (= J 0)
      )
      (inv_main143 I E G F K U X R N V W P C A M T J D H Y Q S L B O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main137 G P F Y H E B O W K T D R C J L Z N A M V Q X U S)
        (and (= N 1) (= I 0) (not (= Z 0)))
      )
      (inv_main143 G P F Y H E B O W K T D R C J L Z I A M V Q X U S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main95 F O U M C L E P S R V W Q T H J X Y B I D K N A G)
        (= U 0)
      )
      (inv_main101 F O U M C L E P S R V W Q T H J X Y B I D K N A G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main95 N W H S B D M Z A X C P O G K U Q R F V J T E I Y)
        (and (= L 0) (not (= H 0)) (= S 1))
      )
      (inv_main101 N W H L B D M Z A X C P O G K U Q R F V J T E I Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main113 T E F N K G S B M J W X Q P R L O V C D H A I Y U)
        (= M 0)
      )
      (inv_main119 T E F N K G S B M J W X Q P R L O V C D H A I Y U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main113 E L F R X B U C N H Y V Q T P K G J Z I W M D A S)
        (and (not (= N 0)) (= H 1) (= O 0))
      )
      (inv_main119 E L F R X B U C N O Y V Q T P K G J Z I W M D A S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main143 E X L Q B N J K F U W Y D R M O I V A S G P H C T)
        (= A 0)
      )
      (inv_main149 E X L Q B N J K F U W Y D R M O I V A S G P H C T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main143 S C Q O F D X U G L B P I T W Z A J Y R N K V M H)
        (and (= R 1) (= E 0) (not (= Y 0)))
      )
      (inv_main149 S C Q O F D X U G L B P I T W Z A J Y E N K V M H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) ) 
    (=>
      (and
        (inv_main68 U H R N D A X G M A1 V S Y W Q C K I O L T F P Z J)
        (and (not (= V 0)) (not (= M 0)) (= E 1) (= B 1))
      )
      (inv_main74 U H R N D A X G M B V E Y W Q C K I O L T F P Z J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main68 B O G H N D Y X P C Z W U K V F T Q E L M S J R I)
        (and (= Z 0) (not (= P 0)) (= A 1))
      )
      (inv_main74 B O G H N D Y X P A Z W U K V F T Q E L M S J R I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main68 K H C E U V B I O T N G L P Y F A S Z J X R Q M D)
        (and (= O 0) (not (= N 0)) (= W 1))
      )
      (inv_main74 K H C E U V B I O T N W L P Y F A S Z J X R Q M D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main68 I X W L E S V M A K Y P R O G N H J U D T Q C B F)
        (and (= A 0) (= Y 0))
      )
      (inv_main74 I X W L E S V M A K Y P R O G N H J U D T Q C B F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main119 L E Y U W V B I K J O T C M N D A G X F R Q S P H)
        (= O 0)
      )
      (inv_main125 L E Y U W V B I K J O T C M N D A G X F R Q S P H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main119 B O J N Z G E I Y T X P D F H C U S K A V W R Q M)
        (and (= P 1) (= L 0) (not (= X 0)))
      )
      (inv_main125 B O J N Z G E I Y T X L D F H C U S K A V W R Q M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) ) 
    (=>
      (and
        (inv_main74 T L A1 Y X K D B A S C E H W I V F P Z R J Q N U M)
        (and (not (= I 0)) (not (= H 0)) (= G 1) (= O 1))
      )
      (inv_main80 T L A1 Y X K D B A S C E H O I G F P Z R J Q N U M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main74 F E W L B H R V T C D G S O A P U I M Q X N Y K J)
        (and (= Z 1) (not (= S 0)) (= A 0))
      )
      (inv_main80 F E W L B H R V T C D G S Z A P U I M Q X N Y K J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main74 N V U S T W B L R I Q P F O A K D E G X M J Y Z H)
        (and (= F 0) (= C 1) (not (= A 0)))
      )
      (inv_main80 N V U S T W B L R I Q P F O A C D E G X M J Y Z H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main74 V C F K Y S W A E L N D I M R J X Q H P U G T B O)
        (and (= I 0) (= R 0))
      )
      (inv_main80 V C F K Y S W A E L N D I M R J X Q H P U G T B O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) ) 
    (=>
      (and
        (inv_main62 I B Q T H M P U G J Y S Z A1 D R L V K N O E C A F)
        (and (= W 1) (not (= P 0)) (not (= H 0)) (= X 1))
      )
      (inv_main68 I B Q T H X P W G J Y S Z A1 D R L V K N O E C A F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main62 B U Y D V L R H O K G Z F I N E J T S A P W X M C)
        (and (= R 0) (= Q 1) (not (= V 0)))
      )
      (inv_main68 B U Y D V Q R H O K G Z F I N E J T S A P W X M C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main62 X R H F B G W P S V D K Y Z M T L N O I C A J Q U)
        (and (= E 1) (= B 0) (not (= W 0)))
      )
      (inv_main68 X R H F B G W E S V D K Y Z M T L N O I C A J Q U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main62 C W N Q H R B O A X P J T I Y G L F U K V D E S M)
        (and (= B 0) (= H 0))
      )
      (inv_main68 C W N Q H R B O A X P J T I Y G L F U K V D E S M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main107 F V Y P M E R A D U Q I H O N L C X J G B W K S T)
        (= R 0)
      )
      (inv_main113 F V Y P M E R A D U Q I H O N L C X J G B W K S T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main107 R S F N M Q Z H A D V T B E L Y X K P W J I O G U)
        (and (= H 1) (= C 0) (not (= Z 0)))
      )
      (inv_main113 R S F N M Q Z C A D V T B E L Y X K P W J I O G U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) ) 
    (=>
      (and
        (inv_main80 P A H D E M V A1 N L R I Q O K G F Y Z X T S C W B)
        (and (= U 1) (= J 1) (not (= F 0)) (not (= Z 0)))
      )
      (inv_main86 P A H D E M V A1 N L R I Q O K G F J Z U T S C W B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main80 C Q R F P W T U O A G Z M L N K D S I X V E H J B)
        (and (= I 0) (not (= D 0)) (= Y 1))
      )
      (inv_main86 C Q R F P W T U O A G Z M L N K D Y I X V E H J B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main80 K W L D Y C X I J P G F N R U H Z V T A Q O E B M)
        (and (not (= T 0)) (= S 1) (= Z 0))
      )
      (inv_main86 K W L D Y C X I J P G F N R U H Z V T S Q O E B M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main80 T B K L J F P M E D Y X I U C O V S R W H G Q A N)
        (and (= R 0) (= V 0))
      )
      (inv_main86 T B K L J F P M E D Y X I U C O V S R W H G Q A N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main101 E N G I H A V M Q D Y R C U F K O S B T P J W L X)
        (= H 0)
      )
      (inv_main107 E N G I H A V M Q D Y R C U F K O S B T P J W L X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main101 Z L K C B N Y T D J W X A P V E S O Q G I U R M H)
        (and (= F 0) (not (= B 0)) (= N 1))
      )
      (inv_main107 Z L K C B F Y T D J W X A P V E S O Q G I U R M H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) ) 
    (=>
      (and
        (inv_main39 A Z I E K1 D1 L B1 W F1 X H S D C1 U J1 L1 Y H1 R K O P G)
        (and (not (= I 0))
     (= F 0)
     (= C 1)
     (= B 0)
     (not (= A 0))
     (= M 0)
     (= I1 0)
     (= G1 0)
     (= E1 0)
     (= A1 0)
     (= V 0)
     (not (= T 0))
     (= Q 1)
     (= N 0)
     (= J 0))
      )
      (inv_main62 A C I Q K1 V L N W B X M S A1 C1 J J1 F Y G1 R I1 O E1 T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) ) 
    (=>
      (and
        (inv_main39 F K1 M K V I T G B D1 I1 X F1 U L H1 G1 J E A E1 D H C B1)
        (and (= M 0)
     (= L1 0)
     (not (= J1 0))
     (= C1 0)
     (= A1 0)
     (= Z 1)
     (= Y 0)
     (= W 0)
     (= S 0)
     (= R 0)
     (= Q 0)
     (= P 0)
     (= O 0)
     (= N 0)
     (not (= F 0)))
      )
      (inv_main62 F Z M S V A1 T Y B C1 I1 Q F1 W L P G1 R E O E1 N H L1 J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) ) 
    (=>
      (and
        (inv_main39 W F F1 I C1 S E1 H1 T D X C R D1 B1 J G J1 Y A M P I1 K L)
        (and (= E 0)
     (= B 0)
     (= L1 0)
     (= K1 1)
     (= G1 0)
     (not (= F1 0))
     (not (= A1 0))
     (= Z 0)
     (= W 0)
     (= V 0)
     (= U 0)
     (= Q 0)
     (= O 0)
     (= N 0)
     (= H 0))
      )
      (inv_main62 W O F1 K1 C1 E E1 H T Z X L1 R G1 B1 N G B Y V M Q I1 U A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) ) 
    (=>
      (and
        (inv_main39 J1 E1 G A1 C I E J H1 D F P N Y H Q O M I1 T G1 W D1 B L1)
        (and (= G 0)
     (= A 0)
     (= L 0)
     (= K1 0)
     (= J1 0)
     (= F1 0)
     (= C1 0)
     (not (= B1 0))
     (= Z 0)
     (= X 0)
     (= V 0)
     (= U 0)
     (= S 0)
     (= R 0)
     (= K 0))
      )
      (inv_main62 J1 K1 G A C R E C1 H1 L F K N V H X O S I1 U G1 Z D1 F1 B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main125 T J G I D B K W P S H V L Q M Y O R F X A U E C N)
        (= L 0)
      )
      (inv_main131 T J G I D B K W P S H V L Q M Y O R F X A U E C N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) ) 
    (=>
      (and
        (inv_main125 O L P I B X Y F A E T V H C J R N S Q U Z G K W M)
        (and (= D 0) (= C 1) (not (= H 0)))
      )
      (inv_main131 O L P I B X Y F A E T V H D J R N S Q U Z G K W M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) ) 
    (=>
      (and
        (inv_main166 S M L D Y V R U W C F O H N T K Q X E I B G A P J)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
