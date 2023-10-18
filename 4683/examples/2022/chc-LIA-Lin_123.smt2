; ./tricera/sv-comp-2020/./mixed/test_locks_14-2.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main109| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main70| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main151| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main181| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main127| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main169| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main106| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main163| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main121| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main100| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main82| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main88| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main145| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main139| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main76| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main157| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main192| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main2| ( ) Bool)
(declare-fun |inv_main175| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main94| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main133| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main45| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main145 B P K B1 O E G C A1 J A X M D Q U N T S F W Z R I C1 V H Y L)
        (= Q 0)
      )
      (inv_main151 B P K B1 O E G C A1 J A X M D Q U N T S F W Z R I C1 V H Y L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main145 Q Y K T V E G D1 N J I L C1 H S F B Z D A1 B1 C A O W X U P R)
        (and (= M 0) (= F 1) (not (= S 0)))
      )
      (inv_main151 Q Y K T V E G D1 N J I L C1 H S M B Z D A1 B1 C A O W X U P R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main157 E S X V R T C W H G F B Y B1 J Z I M P D C1 K U O Q L N A A1)
        (= P 0)
      )
      (inv_main163 E S X V R T C W H G F B Y B1 J Z I M P D C1 K U O Q L N A A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main157 A1 S M D1 C O L V D Z R B1 X K N F P I J H T A W Q B C1 E U G)
        (and (not (= J 0)) (= H 1) (= Y 0))
      )
      (inv_main163 A1 S M D1 C O L V D Z R B1 X K N F P I J Y T A W Q B C1 E U G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main106 A1 I X K C1 F V L R W M U J T C E S D Y N G P O B A B1 H Q Z)
        (= A1 0)
      )
      (inv_main109 A1 I X K C1 F V L R W M U J T C E S D Y N G P O B A B1 H Q Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main106 X C E P B I T W U S M V D G J K Z N A F D1 L Y C1 R A1 Q B1 H)
        (and (= O 0) (= C 1) (not (= X 0)))
      )
      (inv_main109 X O E P B I T W U S M V D G J K Z N A F D1 L Y C1 R A1 Q B1 H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main133 B1 R V Y F D W C B G Q K H P O Z U I A L X S J T M A1 E C1 N)
        (= Q 0)
      )
      (inv_main139 B1 R V Y F D W C B G Q K H P O Z U I A L X S J T M A1 E C1 N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main133 O I D1 C1 A1 H D K A N L Q P X W E B B1 S V C F Z R G J U M Y)
        (and (= Q 1) (not (= L 0)) (= T 0))
      )
      (inv_main139 O I D1 C1 A1 H D K A N L T P X W E B B1 S V C F Z R G J U M Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main181 B V A F I E L R K W A1 T G D1 C1 P B1 H S Y Q X U M O J D Z C)
        (and (= N 0) (not (= D 0)) (= Z 1))
      )
      (inv_main45 B V A F I E L R K W A1 T G D1 C1 P B1 H S Y Q X U M O J D N C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        inv_main2
        true
      )
      (inv_main45 H O N U M X G Q E P D W C1 A1 T V L Y F I Z C B1 J A S B K R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main109 W X F V C1 D Q R N M Z B Y E A H L G U P S C T O I B1 J D1 A1)
        (and (= V 1) (= K 0) (not (= F 0)) (= C1 0))
      )
      (inv_main121 W X F K C1 D Q R N M Z B Y E A H L G U P S C T O I B1 J D1 A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main109 B1 D1 I F A S R U E Q A1 N M C1 P J O B H G T V D C Y W K L E1)
        (and (= Z 0) (= X 0) (= S 1) (not (= I 0)) (= F 1) (not (= A 0)))
      )
      (inv_main121 B1 D1 I Z A X R U E Q A1 N M C1 P J O B H G T V D C Y W K L E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main76 I M H T L Q B F S E D R G P K D1 O C1 C B1 A1 X U W E1 Z N A J)
        (and (= V 1) (not (= S 0)) (not (= D 0)) (= Y 1))
      )
      (inv_main82 I M H T L Q B F S Y D V G P K D1 O C1 C B1 A1 X U W E1 Z N A J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main76 U C V Y A1 K X M B1 F T A H S B W G N D1 C1 D Z O R L I Q J P)
        (and (= T 0) (= E 1) (not (= B1 0)))
      )
      (inv_main82 U C V Y A1 K X M B1 E T A H S B W G N D1 C1 D Z O R L I Q J P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main76 X H G N F W D1 A1 I K P S U Q C1 E O M B Y V A Z T C B1 D L J)
        (and (not (= P 0)) (= I 0) (= R 1))
      )
      (inv_main82 X H G N F W D1 A1 I K P R U Q C1 E O M B Y V A Z T C B1 D L J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main76 D T O R K Y H U A1 S Q C1 F E X P C V I N Z L A W B1 M B G J)
        (and (= Q 0) (= A1 0))
      )
      (inv_main82 D T O R K Y H U A1 S Q C1 F E X P C V I N Z L A W B1 M B G J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main82 Q F P N J Z A D1 M A1 C R W C1 E X B1 S L H B D T O E1 Y K G V)
        (and (= U 1) (= I 1) (not (= E 0)) (not (= W 0)))
      )
      (inv_main88 Q F P N J Z A D1 M A1 C R W I E U B1 S L H B D T O E1 Y K G V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main82 E D1 N J A1 H K W D X Q Z A C1 B1 O I V C G M L T B U S P R F)
        (and (= B1 0) (= Y 1) (not (= A 0)))
      )
      (inv_main88 E D1 N J A1 H K W D X Q Z A Y B1 O I V C G M L T B U S P R F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main82 N B1 Q P T Y H D L A1 G F U C1 M J D1 W S B O A R Z E V I X C)
        (and (not (= M 0)) (= K 1) (= U 0))
      )
      (inv_main88 N B1 Q P T Y H D L A1 G F U C1 M K D1 W S B O A R Z E V I X C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main82 Y N H B1 K W I O R L X A1 E V A G C1 D T F Z M B U C S J Q P)
        (and (= A 0) (= E 0))
      )
      (inv_main88 Y N H B1 K W I O R L X A1 E V A G C1 D T F Z M B U C S J Q P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main100 J E V D1 D P G T A F I W B C R X U O Q S C1 H N E1 L B1 Y Z A1)
        (and (= M 1) (not (= L 0)) (= K 1) (not (= Y 0)))
      )
      (inv_main106 J E V D1 D P G T A F I W B C R X U O Q S C1 H N E1 L M Y K A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main100 C1 S T B1 R H J U N D1 I G W F L D P V M C A1 K X Z A B Y Q E)
        (and (= Y 0) (= O 1) (not (= A 0)))
      )
      (inv_main106 C1 S T B1 R H J U N D1 I G W F L D P V M C A1 K X Z A O Y Q E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main100 Z P J M V U E O I T D Q H C1 B1 W S Y R C D1 L X B A1 A F K N)
        (and (= G 1) (not (= F 0)) (= A1 0))
      )
      (inv_main106 Z P J M V U E O I T D Q H C1 B1 W S Y R C D1 L X B A1 A F G N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main100 Y D I P X F W O C L B1 V G B Z E K C1 A1 S N M T A J R H U Q)
        (and (= H 0) (= J 0))
      )
      (inv_main106 Y D I P X F W O C L B1 V G B Z E K C1 A1 S N M T A J R H U Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main70 E X V N L M R G Z U E1 D1 B1 C Q P C1 I A1 A B T F H Y K W J O)
        (and (not (= R 0)) (not (= L 0)) (= D 1) (= S 1))
      )
      (inv_main76 E X V N L S R D Z U E1 D1 B1 C Q P C1 I A1 A B T F H Y K W J O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main70 A1 V H K N U P Z C1 C R J O F A D1 G M B L I W S T Y B1 X E D)
        (and (= P 0) (not (= N 0)) (= Q 1))
      )
      (inv_main76 A1 V H K N Q P Z C1 C R J O F A D1 G M B L I W S T Y B1 X E D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main70 Q J U T X S I C1 H P L R O N Z A E M D1 D B1 V B G C F Y A1 W)
        (and (= K 1) (not (= I 0)) (= X 0))
      )
      (inv_main76 Q J U T X S I K H P L R O N Z A E M D1 D B1 V B G C F Y A1 W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main70 G S U P F N B1 D K V C J R E M I Q B Y T A W C1 O A1 Z X L H)
        (and (= F 0) (= B1 0))
      )
      (inv_main76 G S U P F N B1 D K V C J R E M I Q B Y T A W C1 O A1 Z X L H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main94 H I S L C1 A K R W G A1 T O V D U F Z J X B1 B E D1 Q P Y N C)
        (and (not (= B1 0)) (= M 1) (not (= E 0)) (= E1 1))
      )
      (inv_main100 H I S L C1 A K R W G A1 T O V D U F Z J X B1 E1 E M Q P Y N C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main94 R G D N L H S C D1 Q C1 Y A W Z J B1 E B V U O X P M K F A1 I)
        (and (not (= U 0)) (= T 1) (= X 0))
      )
      (inv_main100 R G D N L H S C D1 Q C1 Y A W Z J B1 E B V U T X P M K F A1 I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main94 I D A1 H N D1 C Y M O L U S T B W E V R Z K Q F G J B1 C1 P X)
        (and (= K 0) (not (= F 0)) (= A 1))
      )
      (inv_main100 I D A1 H N D1 C Y M O L U S T B W E V R Z K Q F A J B1 C1 P X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main94 K B I A S H X C B1 U E F R W Z L T D A1 J P Q C1 N M G O Y V)
        (and (= P 0) (= C1 0))
      )
      (inv_main100 K B I A S H X C B1 U E F R W Z L T D A1 J P Q C1 N M G O Y V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main88 J D1 Q M P O C E L H T I C1 W F K A Y X A1 R N S Z V B1 G E1 U)
        (and (= B 1) (not (= X 0)) (= D 1) (not (= A 0)))
      )
      (inv_main94 J D1 Q M P O C E L H T I C1 W F K A D X B R N S Z V B1 G E1 U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main88 W D1 B H Z P T Q F N K I B1 G X D C1 C E S J R O L A1 A V Y U)
        (and (= M 1) (= E 0) (not (= C1 0)))
      )
      (inv_main94 W D1 B H Z P T Q F N K I B1 G X D C1 M E S J R O L A1 A V Y U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main88 C1 P A1 N R K W D V D1 C I T Y S E O H G Z A U M X B1 F L B J)
        (and (= O 0) (not (= G 0)) (= Q 1))
      )
      (inv_main94 C1 P A1 N R K W D V D1 C I T Y S E O H G Q A U M X B1 F L B J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main88 R V L C1 B F E K Q A1 T S M B1 G X J H O C Y A D N I W U Z P)
        (and (= J 0) (= O 0))
      )
      (inv_main94 R V L C1 B F E K Q A1 T S M B1 G X J H O C Y A D N I W U Z P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main175 E M V B1 F H J Q O U A W N G B P T Z C1 I S L X D K A1 R Y C)
        (= K 0)
      )
      (inv_main181 E M V B1 F H J Q O U A W N G B P T Z C1 I S L X D K A1 R Y C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main175 K U O V J I Z R L H X F W Y G D N P D1 B B1 A S C1 E A1 C Q M)
        (and (= T 0) (not (= E 0)) (= A1 1))
      )
      (inv_main181 K U O V J I Z R L H X F W Y G D N P D1 B B1 A S C1 E T C Q M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main151 S A1 F B U C1 O E B1 D W J Z N A C Y L X P H T I Q V M R K G)
        (= Y 0)
      )
      (inv_main157 S A1 F B U C1 O E B1 D W J Z N A C Y L X P H T I Q V M R K G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main151 C1 C Z G J P A X B1 O V Y T F H K S Q W B E U L M A1 D D1 N R)
        (and (= Q 1) (= I 0) (not (= S 0)))
      )
      (inv_main157 C1 C Z G J P A X B1 O V Y T F H K S I W B E U L M A1 D D1 N R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main121 A K W C S G N R V Q D T H B C1 L U P J A1 M E X Z B1 I F Y O)
        (= N 0)
      )
      (inv_main127 A K W C S G N R V Q D T H B C1 L U P J A1 M E X Z B1 I F Y O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main121 Q O S B1 K J I D1 B N H C L G W E R F A1 A V U M C1 T D Z P Y)
        (and (= X 0) (not (= I 0)) (= D1 1))
      )
      (inv_main127 Q O S B1 K J I X B N H C L G W E R F A1 A V U M C1 T D Z P Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) ) 
    (=>
      (and
        (inv_main45 I1
            P1
            R1
            C1
            Q1
            V
            D1
            H
            S
            E1
            P
            L1
            I
            K
            O1
            Q
            L
            E
            G1
            Z
            J1
            T
            G
            A
            D
            M1
            W
            K1
            X)
        (and (= J 0)
     (= F 0)
     (= C 0)
     (= B 0)
     (= N 0)
     (= O 0)
     (not (= R1 0))
     (= N1 0)
     (not (= I1 0))
     (= H1 0)
     (= F1 0)
     (= B1 1)
     (= A1 1)
     (= Y 0)
     (= U 0)
     (= R 0)
     (not (= M 0)))
      )
      (inv_main70 I1
            A1
            R1
            B1
            Q1
            U
            D1
            H1
            S
            N1
            P
            C
            I
            R
            O1
            Y
            L
            O
            G1
            B
            J1
            N
            G
            F1
            D
            J
            W
            F
            M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) ) 
    (=>
      (and
        (inv_main45 K
            H1
            X
            C
            V
            L
            B
            J
            N1
            H
            K1
            F1
            O
            Z
            M1
            W
            B1
            L1
            F
            P1
            E
            D1
            I1
            Q1
            I
            A
            N
            D
            O1)
        (and (not (= K 0))
     (= G 0)
     (= R1 0)
     (not (= J1 0))
     (= G1 0)
     (= E1 0)
     (= C1 0)
     (= A1 0)
     (= Y 0)
     (= X 0)
     (= U 1)
     (= T 0)
     (= S 0)
     (= R 0)
     (= Q 0)
     (= P 0)
     (= M 0))
      )
      (inv_main70 K
            U
            X
            C1
            V
            A1
            B
            E1
            N1
            S
            K1
            Y
            O
            R
            M1
            T
            B1
            Q
            F
            P
            E
            R1
            I1
            G1
            I
            M
            N
            G
            J1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) ) 
    (=>
      (and
        (inv_main45 H1
            L
            G
            J1
            P
            J
            P1
            O1
            F
            Z
            H
            D1
            F1
            N
            R1
            N1
            M1
            K1
            I1
            I
            W
            V
            C1
            L1
            U
            E
            G1
            D
            Q)
        (and (= K 0)
     (not (= G 0))
     (= C 0)
     (= B 1)
     (not (= A 0))
     (= O 0)
     (= Q1 0)
     (= H1 0)
     (= E1 0)
     (= B1 0)
     (= A1 0)
     (= Y 0)
     (= X 0)
     (= T 0)
     (= S 0)
     (= R 0)
     (= M 0))
      )
      (inv_main70 H1
            O
            G
            B
            P
            Y
            P1
            T
            F
            X
            H
            B1
            F1
            Q1
            R1
            E1
            M1
            S
            I1
            R
            W
            C
            C1
            A1
            U
            K
            G1
            M
            A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) ) 
    (=>
      (and
        (inv_main45 T
            D1
            Q
            J1
            A1
            H
            B1
            C
            Y
            F
            Z
            N1
            F1
            G
            K1
            S
            G1
            I
            Q1
            V
            A
            R
            W
            P1
            I1
            O1
            P
            M1
            U)
        (and (= L 0)
     (= K 0)
     (= J 0)
     (not (= E 0))
     (= D 0)
     (= B 0)
     (= N 0)
     (= O 0)
     (= R1 0)
     (= L1 0)
     (= H1 0)
     (= E1 0)
     (= C1 0)
     (= X 0)
     (= T 0)
     (= Q 0)
     (= M 0))
      )
      (inv_main70 T
            D
            Q
            R1
            A1
            O
            B1
            B
            Y
            E1
            Z
            X
            F1
            N
            K1
            L1
            G1
            M
            Q1
            H1
            A
            L
            W
            J
            I1
            K
            P
            C1
            E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main163 S B H G A1 T Y V J I M X W K Z C O C1 L D R A Q F B1 U P E N)
        (= R 0)
      )
      (inv_main169 S B H G A1 T Y V J I M X W K Z C O C1 L D R A Q F B1 U P E N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main163 L A P D M E B S V Q K G Z N J B1 C I X H W U T F D1 A1 Y O C1)
        (and (= U 1) (= R 0) (not (= W 0)))
      )
      (inv_main169 L A P D M E B S V Q K G Z N J B1 C I X H W R T F D1 A1 Y O C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main169 Y T C Z G F D W C1 A1 R H X S P U K I J E B1 O M Q N B L A V)
        (= M 0)
      )
      (inv_main175 Y T C Z G F D W C1 A1 R H X S P U K I J E B1 O M Q N B L A V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main169 H J S O F R D1 L D A1 W B1 E K M C1 N P B Z U I C G T A V Y X)
        (and (= G 1) (not (= C 0)) (= Q 0))
      )
      (inv_main175 H J S O F R D1 L D A1 W B1 E K M C1 N P B Z U I C Q T A V Y X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main139 D C1 L E V O Q M U A1 R T B C Z W N S Y B1 P H J K X G F I A)
        (= B 0)
      )
      (inv_main145 D C1 L E V O Q M U A1 R T B C Z W N S Y B1 P H J K X G F I A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main139 C P Z H V A M T W B1 A1 X C1 E D U N B Y L S I R G D1 F O Q J)
        (and (= K 0) (= E 1) (not (= C1 0)))
      )
      (inv_main145 C P Z H V A M T W B1 A1 X C1 K D U N B Y L S I R G D1 F O Q J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main106 X J L I P M A C V Y B K A1 H Z R D U Q W N F E G T C1 S O B1)
        (and (not (= J 1)) (not (= X 0)))
      )
      (inv_main192 X J L I P M A C V Y B K A1 H Z R D U Q W N F E G T C1 S O B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main109 O L I R S E Q C N D H W J V A B C1 G Y X U T A1 P Z M K B1 F)
        (= I 0)
      )
      (inv_main192 O L I R S E Q C N D H W J V A B C1 G Y X U T A1 P Z M K B1 F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main109 Z M A1 H F N Q O Y S B E A P R C1 W X L I V K J C D U T G B1)
        (and (not (= H 1)) (not (= A1 0)))
      )
      (inv_main192 Z M A1 H F N Q O Y S B E A P R C1 W X L I V K J C D U T G B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main109 L Q D1 T B W N H G B1 I E Z D S Y R P F A1 O U C J A V K M C1)
        (and (= X 0) (not (= W 1)) (= T 1) (not (= B 0)) (not (= D1 0)))
      )
      (inv_main192 L Q D1 X B W N H G B1 I E Z D S Y R P F A1 O U C J A V K M C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main121 Y B B1 X R A1 T G Z A O W C L I H M U S N K Q E D V J P F C1)
        (and (not (= G 1)) (not (= T 0)))
      )
      (inv_main192 Y B B1 X R A1 T G Z A O W C L I H M U S N K Q E D V J P F C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main127 R T F B1 X Q B U P C1 H Y C Z I K N D G O E A M L J S A1 V W)
        (and (not (= P 0)) (not (= C1 1)))
      )
      (inv_main192 R T F B1 X Q B U P C1 H Y C Z I K N D G O E A M L J S A1 V W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main133 O I W S B1 B T F M U G H V A1 Q L C1 C Z R E N D J X Y A K P)
        (and (not (= G 0)) (not (= H 1)))
      )
      (inv_main192 O I W S B1 B T F M U G H V A1 Q L C1 C Z R E N D J X Y A K P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main139 R X O D C A1 U V B1 N J L Q M P I G H W T K Y F B A S C1 Z E)
        (and (not (= M 1)) (not (= Q 0)))
      )
      (inv_main192 R X O D C A1 U V B1 N J L Q M P I G H W T K Y F B A S C1 Z E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main145 B C E L B1 V D X R M H S O U W A1 N I J C1 P A Q G Z T K F Y)
        (and (not (= W 0)) (not (= A1 1)))
      )
      (inv_main192 B C E L B1 V D X R M H S O U W A1 N I J C1 P A Q G Z T K F Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main151 T B E S R F D Y U A Z G Q C1 L J V P I C B1 M K H A1 O N X W)
        (and (not (= P 1)) (not (= V 0)))
      )
      (inv_main192 T B E S R F D Y U A Z G Q C1 L J V P I C B1 M K H A1 O N X W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main157 Y B A1 P N B1 Z O A M I U T K D W F L J H S C1 R C X E V G Q)
        (and (not (= H 1)) (not (= J 0)))
      )
      (inv_main192 Y B A1 P N B1 Z O A M I U T K D W F L J H S C1 R C X E V G Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main163 B1 C Y X I C1 W D K V E G R B S Z L U A1 F Q T M H P J N O A)
        (and (not (= Q 0)) (not (= T 1)))
      )
      (inv_main192 B1 C Y X I C1 W D K V E G R B S Z L U A1 F Q T M H P J N O A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main169 U E A1 W T S G Q F C1 D B1 N M B V J Y Z P L I C K R O X H A)
        (and (not (= C 0)) (not (= K 1)))
      )
      (inv_main192 U E A1 W T S G Q F C1 D B1 N M B V J Y Z P L I C K R O X H A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main175 K T G C Q H I V B J D W U Y L P X B1 M O A1 S F E Z A N C1 R)
        (and (not (= A 1)) (not (= Z 0)))
      )
      (inv_main192 K T G C Q H I V B J D W U Y L P X B1 M O A1 S F E Z A N C1 R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main181 Y V A M J U Z W T A1 L B G C1 F X E I D N B1 P S H K R O Q C)
        (= O 0)
      )
      (inv_main192 Y V A M J U Z W T A1 L B G C1 F X E I D N B1 P S H K R O Q C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main181 P B X M C C1 A1 F G Z T J B1 V S Q O N H A R W E D U L Y I K)
        (and (not (= I 1)) (not (= Y 0)))
      )
      (inv_main192 P B X M C C1 A1 F G Z T J B1 V S Q O N H A R W E D U L Y I K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main127 M P V K C1 N D R J U A Q Z I T O Y H S E B1 X A1 F B W C L G)
        (= J 0)
      )
      (inv_main133 M P V K C1 N D R J U A Q Z I T O Y H S E B1 X A1 F B W C L G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main127 X W B1 L J R M I B N Q D1 T U O V A D P C H S A1 Y F K Z G E)
        (and (= N 1) (not (= B 0)) (= C1 0))
      )
      (inv_main133 X W B1 L J R M I B C1 Q D1 T U O V A D P C H S A1 Y F K Z G E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main192 A1 I Q X Z Y H W D N S J F P B K O G C1 E T V B1 R U A L M C)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
