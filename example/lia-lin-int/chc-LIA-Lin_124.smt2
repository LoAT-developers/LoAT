; ./tricera/sv-comp-2020/./mixed/test_locks_14-1.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main109| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main70| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main151| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main181| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main127| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main169| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main106| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main163| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main115| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
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
        (inv_main145 R F N E G C A1 K A X L D P T M S V B W Z Q I C1 U H Y J B1 O)
        (= M 0)
      )
      (inv_main151 R F N E G C A1 K A X L D P T M S V B W Z Q I C1 U H Y J B1 O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main145 D Z U E G D1 N J I L C1 H S F B Y M Q B1 C A O V W T P K R X)
        (and (= Y 1) (not (= B 0)) (= A1 0))
      )
      (inv_main151 D Z U E G D1 N J I L C1 H S F B A1 M Q B1 C A O V W T P K R X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main157 Q D T U C Y I G F B Z B1 K A1 J N H E C1 L V P S M R A X W O)
        (= C1 0)
      )
      (inv_main163 Q D T U C Y I G F B Z B1 K A1 J N H E C1 L V P S M R A X W O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main157 I G C N K U D Y Q A1 W J M F O H X Z S A V P B C1 E T L D1 R)
        (and (= B1 0) (not (= S 0)) (= A 1))
      )
      (inv_main163 I G C N K U D Y Q A1 W J M F O H X Z S B1 V P B C1 E T L D1 R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main106 Z O C1 F W M S X N V K U C E T D J A1 G Q P B A B1 H R Y L I)
        (= Z 0)
      )
      (inv_main109 Z O C1 F W M S X N V K U C E T D J A1 G Q P B A B1 H R Y L I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main106 A F B H T W U S L V D G I J Z M O X D1 K Y C1 R A1 Q B1 E P C)
        (and (= N 0) (= F 1) (not (= A 0)))
      )
      (inv_main109 A N B H T W U S L V D G I J Z M O X D1 K Y C1 R A1 Q B1 E P C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main109 A L F D W C B G P K H O N Z T I Y B1 X R J S M A1 E C1 U V Q)
        (= F 0)
      )
      (inv_main115 A L F D W C B G P K H O N Z T I Y B1 X R J S M A1 E C1 U V Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main109 T W A1 I D L A O M R Q Y X F B B1 U P C G Z S H K V N D1 C1 J)
        (and (= I 1) (= E 0) (not (= A1 0)))
      )
      (inv_main115 T W A1 E D L A O M R Q Y X F B B1 U P C G Z S H K V N D1 C1 J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main133 R X H D K Q J V Z S F C1 B1 O A1 G M B P W U L N I C Y A E T)
        (= F 0)
      )
      (inv_main139 R X H D K Q J V Z S F C1 B1 O A1 G M B P W U L N I C Y A E T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main133 O N U H X E Q D P D1 W T A1 L V F Y R I Z C B1 J A S B K M G)
        (and (not (= W 0)) (= T 1) (= C1 0))
      )
      (inv_main139 O N U H X E Q D P D1 W C1 A1 L V F Y R I Z C B1 J A S B K M G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main181 Y Q B1 D P R N M Z B X E A H L G K W S C T O I A1 J C1 F V U)
        (= F 0)
      )
      (inv_main45 Y Q B1 D P R N M Z B X E A H L G K W S C T O I A1 J C1 F V U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main181 A1 C1 I F A S R U E Q Z N M B1 P J O B H G T V D C X W K L D1)
        (and (= L 1) (not (= K 0)) (= Y 0))
      )
      (inv_main45 A1 C1 I F A S R U E Q Z N M B1 P J O B H G T V D C X W K Y D1)
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
      (inv_main45 U A1 J N Y H A L S B P R F D E I Q K O G M C Z X W T V C1 B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main115 P Z L O I F N G S W Y H V J A1 E Q A U T K M R B C1 B1 C X D)
        (= I 0)
      )
      (inv_main121 P Z L O I F N G S W Y H V J A1 E Q A U T K M R B C1 B1 C X D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main115 T A V D1 Z U B B1 D O H Q F W C1 A1 J L S M E G P K X I C Y N)
        (and (= U 1) (= R 0) (not (= Z 0)))
      )
      (inv_main121 T A V D1 Z R B B1 D O H Q F W C1 A1 J L S M E G P K X I C Y N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main76 E1 D1 A1 K A Y C1 M B F P T J Z G W B1 V D L R O X I C U H N Q)
        (and (= S 1) (not (= P 0)) (= E 1) (not (= B 0)))
      )
      (inv_main82 E1 D1 A1 K A Y C1 M B S P E J Z G W B1 V D L R O X I C U H N Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main76 W D D1 X K I P N J Y A C1 M Z C R V B1 S U Q G L H B F T O A1)
        (and (not (= J 0)) (= E 1) (= A 0))
      )
      (inv_main82 W D D1 X K I P N J E A C1 M Z C R V B1 S U Q G L H B F T O A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main76 C1 G U C W T Q S N J B1 I K X D Y R Z O P V F E D1 B H M L A1)
        (and (not (= B1 0)) (= N 0) (= A 1))
      )
      (inv_main82 C1 G U C W T Q S N J B1 A K X D Y R Z O P V F E D1 B H M L A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main76 C1 E Q Y H T K V P O S X I D L Z G F J W U C M B1 R B N A A1)
        (and (= P 0) (= S 0))
      )
      (inv_main82 C1 E Q Y H T K V P O S X I D L Z G F J W U C M B1 R B N A A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main82 C1 S B1 L A V B T I Q G D1 J X H N R K W E1 F P C O Z M U E A1)
        (and (not (= J 0)) (not (= H 0)) (= D 1) (= Y 1))
      )
      (inv_main88 C1 S B1 L A V B T I Q G D1 J Y H D R K W E1 F P C O Z M U E A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main82 V D1 L Z W X T B1 E O H S B G J U C D N Y K F P R A1 I M C1 A)
        (and (= J 0) (not (= B 0)) (= Q 1))
      )
      (inv_main88 V D1 L Z W X T B1 E O H S B Q J U C D N Y K F P R A1 I M C1 A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main82 F K X A1 A C Y Q T C1 P J L U O D1 I G D H V E B1 S N B Z M R)
        (and (not (= O 0)) (= L 0) (= W 1))
      )
      (inv_main88 F K X A1 A C Y Q T C1 P J L U O W I G D H V E B1 S N B Z M R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main82 B1 N X B A1 A F J H M V U E Q G T D R W K Y O Z P S C C1 L I)
        (and (= E 0) (= G 0))
      )
      (inv_main88 B1 N X B A1 A F J H M V U E Q G T D R W K Y O Z P S C C1 L I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main100 X B1 O M V A J T H W I R A1 F Z P C K B S E L E1 Q Y D D1 U N)
        (and (= C1 1) (not (= Y 0)) (= G 1) (not (= D1 0)))
      )
      (inv_main106 X B1 O M V A J T H W I R A1 F Z P C K B S E L E1 Q Y C1 D1 G N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main100 P R X J W I U M K L Q F Y T D1 C1 A1 C H N D V Z A B S E G B1)
        (and (= E 0) (not (= B 0)) (= O 1))
      )
      (inv_main106 P R X J W I U M K L Q F Y T D1 C1 A1 C H N D V Z A B O E G B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main100 F P R S X B1 W E G J M T O Y C1 C Q I D1 B L D A1 U A K H V Z)
        (and (= N 1) (not (= H 0)) (= A 0))
      )
      (inv_main106 F P R S X B1 W E G J M T O Y C1 C Q I D1 B L D A1 U A K H N Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main100 O I C G D F Y Z U T X S J B1 H N L R B Q M W P K C1 E A1 V A)
        (and (= A1 0) (= C1 0))
      )
      (inv_main106 O I C G D F Y Z U T X S J B1 H N L R B Q M W P K C1 E A1 V A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main70 K W A Y E1 Q C1 B1 A1 M V R F P D1 D L X E G J N B I H T Z U O)
        (and (not (= C1 0)) (= S 1) (= C 1) (not (= E1 0)))
      )
      (inv_main76 K W A Y E1 C C1 S A1 M V R F P D1 D L X E G J N B I H T Z U O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main70 U O Q P Z M S L C1 A K R W H A1 T N V Y C G I J X B1 B E D1 F)
        (and (= S 0) (= D 1) (not (= Z 0)))
      )
      (inv_main76 U O Q P Z D S L C1 A K R W H A1 T N V Y C G I J X B1 B E D1 F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main70 X D1 Y P N L F A1 D M K H T C C1 Q B1 Z J U E I S G B W V O R)
        (and (= N 0) (not (= F 0)) (= A 1))
      )
      (inv_main76 X D1 Y P N L F A D M K H T C C1 Q B1 Z J U E I S G B W V O R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main70 Q X C D H A1 B1 M Z E K C1 A W J L I R T P S V F B O Y G N U)
        (and (= H 0) (= B1 0))
      )
      (inv_main76 Q X C D H A1 B1 M Z E K C1 A W J L I R T P S V F B O Y G N U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main94 H A R S D1 P O I Q A1 K E1 V J Z B C1 W Y E N D F X M C B1 L T)
        (and (not (= N 0)) (= G 1) (not (= F 0)) (= U 1))
      )
      (inv_main100 H A R S D1 P O I Q A1 K E1 V J Z B C1 W Y E N G F U M C B1 L T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main94 H U T A1 D D1 N J M L A B I E Q G B1 S W R F C1 V Y O K P X Z)
        (and (not (= F 0)) (= C 1) (= V 0))
      )
      (inv_main100 H U T A1 D D1 N J M L A B I E Q G B1 S W R F C V Y O K P X Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main94 J I Q O B1 A X Z C K A1 R V S H P N L F E D W Y D1 G U M T B)
        (and (not (= Y 0)) (= D 0) (= C1 1))
      )
      (inv_main100 J I Q O B1 A X Z C K A1 R V S H P N L F E D W Y C1 G U M T B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main94 W C1 O V Z F L B Y N Q K T D S B1 C I E M H J A1 P G X A R U)
        (and (= H 0) (= A1 0))
      )
      (inv_main100 W C1 O V Z F L B Y N Q K T D S B1 C I E M H J A1 P G X A R U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main88 U P A1 A D N H Y W C1 L E1 B F E I S B1 D1 J Z K G R Q X O C T)
        (and (= V 1) (not (= S 0)) (= M 1) (not (= D1 0)))
      )
      (inv_main94 U P A1 A D N H Y W C1 L E1 B F E I S V D1 M Z K G R Q X O C T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main88 R O K B1 U A1 W C1 F H J S Q V A X P G Z D E N D1 I T M Y C L)
        (and (not (= P 0)) (= B 1) (= Z 0))
      )
      (inv_main94 R O K B1 U A1 W C1 F H J S Q V A X P B Z D E N D1 I T M Y C L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main88 P O C Q N U J I Z R L H X F W Y G D K T D1 B B1 A S C1 E A1 V)
        (and (not (= K 0)) (= G 0) (= M 1))
      )
      (inv_main94 P O C Q N U J I Z R L H X F W Y G D K M D1 B B1 A S C1 E A1 V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main88 L H S K F B V C1 P E B1 D X J Z O A C T A1 Y Q G U I R W M N)
        (and (= A 0) (= T 0))
      )
      (inv_main94 L H S K F B V C1 P E B1 D X J Z O A C T A1 Y Q G U I R W M N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main175 P Q C1 M Y G I O A V A1 N T X R F H J B1 C U B E S K L Z D W)
        (= K 0)
      )
      (inv_main181 P Q C1 M Y G I O A V A1 N T X R F H J B1 C U B E S K L Z D W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main175 M D C1 J G Z X C U H O T W S E V I B R P A L K B1 N F Y A1 Q)
        (and (not (= N 0)) (= F 1) (= D1 0))
      )
      (inv_main181 M D C1 J G Z X C U H O T W S E V I B R P A L K B1 N D1 Y A1 Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main151 F X Y P S A1 K J I C1 B N H C L G W E Q O Z A V U M B1 T D R)
        (= W 0)
      )
      (inv_main157 F X Y P S A1 K J I C1 B N H C L G W E Q O Z A V U M B1 T D R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main151 G X E A C A1 N Y D1 Q C1 M R D K S I Z J H B O V B1 U P W L T)
        (and (not (= I 0)) (= F 0) (= Z 1))
      )
      (inv_main157 G X E A C A1 N Y D1 Q C1 M R D K S I F J H B O V B1 U P W L T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main121 F I C1 B C N E P D M K A J L G U V H X Q Z R W O A1 T S B1 Y)
        (= E 0)
      )
      (inv_main127 F I C1 B C N E P D M K A J L G U V H X Q Z R W O A1 T S B1 Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main121 B1 Q L D R H K P M O J A I C1 D1 Z Y G U A1 N E V C T B W X S)
        (and (not (= K 0)) (= F 0) (= P 1))
      )
      (inv_main127 B1 Q L D R H K F M O J A I C1 D1 Z Y G U A1 N E V C T B W X S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) ) 
    (=>
      (and
        (inv_main45 K1
            Q
            J1
            D
            H
            I1
            P
            K
            P1
            O1
            F
            Z
            I
            D1
            F1
            N
            R1
            N1
            H1
            M
            G1
            J
            W
            V
            C1
            M1
            U
            E
            A)
        (and (not (= G 0))
     (= C 0)
     (= B 0)
     (= O 1)
     (= Q1 0)
     (= L1 1)
     (not (= K1 0))
     (not (= J1 0))
     (= E1 0)
     (= B1 0)
     (= A1 0)
     (= Y 0)
     (= X 0)
     (= T 0)
     (= S 0)
     (= R 0)
     (= L 0))
      )
      (inv_main70 K1
            L1
            J1
            O
            H
            B
            P
            Y
            P1
            T
            F
            X
            I
            B1
            F1
            Q1
            R1
            E1
            H1
            S
            G1
            R
            W
            C
            C1
            A1
            U
            L
            G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) ) 
    (=>
      (and
        (inv_main45 I
            V
            R
            M1
            Q
            J1
            B1
            H
            C1
            C
            Z
            F
            A1
            N1
            F1
            G
            K1
            T
            U
            D1
            Q1
            W
            A
            S
            X
            P1
            I1
            O1
            E)
        (and (= L 0)
     (= K 0)
     (= J 0)
     (not (= I 0))
     (= D 0)
     (= B 0)
     (= N 0)
     (= O 0)
     (= R1 0)
     (= L1 0)
     (= H1 0)
     (= G1 1)
     (= E1 0)
     (= Y 0)
     (= R 0)
     (= P 0)
     (not (= M 0)))
      )
      (inv_main70 I
            G1
            R
            D
            Q
            R1
            B1
            P
            C1
            B
            Z
            E1
            A1
            Y
            F1
            O
            K1
            L1
            U
            N
            Q1
            H1
            A
            L
            X
            J
            I1
            K
            M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) ) 
    (=>
      (and
        (inv_main45 E1
            C
            N
            K
            N1
            F1
            L1
            H1
            P
            O
            S
            J1
            I1
            Q
            M1
            E
            V
            P1
            R
            F
            A1
            B
            Z
            H
            O1
            G1
            W
            G
            U)
        (and (= L 0)
     (= J 0)
     (= I 0)
     (= D 0)
     (= A 1)
     (not (= N 0))
     (= R1 0)
     (= Q1 0)
     (= K1 0)
     (= E1 0)
     (= D1 0)
     (not (= C1 0))
     (= B1 0)
     (= Y 0)
     (= X 0)
     (= T 0)
     (= M 0))
      )
      (inv_main70 E1
            R1
            N
            A
            N1
            M
            L1
            D1
            P
            J
            S
            K1
            I1
            X
            M1
            D
            V
            I
            R
            B1
            A1
            Y
            Z
            L
            O1
            T
            W
            Q1
            C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) ) 
    (=>
      (and
        (inv_main45 M1
            E1
            A
            T
            N1
            B
            H
            B1
            K1
            O
            O1
            I1
            J
            N
            G1
            C
            H1
            V
            F1
            D1
            G
            A1
            W
            Q1
            C1
            Z
            D
            S
            R)
        (and (= L 0)
     (= K 0)
     (= I 0)
     (= F 0)
     (= E 0)
     (= A 0)
     (= R1 0)
     (= P1 0)
     (= M1 0)
     (= L1 0)
     (= J1 0)
     (= Y 0)
     (= X 0)
     (= U 0)
     (= Q 0)
     (= P 0)
     (not (= M 0)))
      )
      (inv_main70 M1
            K
            A
            L1
            N1
            L
            H
            P1
            K1
            Q
            O1
            U
            J
            P
            G1
            E
            H1
            I
            F1
            F
            G
            R1
            W
            Y
            C1
            J1
            D
            X
            M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main163 O W U X R N F Q C1 L D Z V A1 E K M B1 H J B Y T I C G S A P)
        (= B 0)
      )
      (inv_main169 O W U X R N F Q C1 L D Z V A1 E K M B1 H J B Y T I C G S A P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main163 X J Y I F K N E W P R O V B1 S U B C T A D D1 Z C1 Q H L M G)
        (and (= A1 0) (not (= D 0)) (= D1 1))
      )
      (inv_main169 X J Y I F K N E W P R O V B1 S U B C T A D A1 Z C1 Q H L M G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main169 B J M O Y H T A L R U A1 Z V B1 E D S C N W K Q I P G C1 F X)
        (= Q 0)
      )
      (inv_main175 B J M O Y H T A L R U A1 Z V B1 E D S C N W K Q I P G C1 F X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main169 S I U D1 T P M H Q N A C W Z B L B1 G V C1 Y K R X O E D F J)
        (and (= X 1) (not (= R 0)) (= A1 0))
      )
      (inv_main175 S I U D1 T P M H Q N A C W Z B L B1 G V C1 Y K R A1 O E D F J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main139 H G L C1 J S T F R D P E I X K W A B O M Z Y V U B1 Q A1 N C)
        (= I 0)
      )
      (inv_main145 H G L C1 J S T F R D P E I X K W A B O M Z Y V U B1 Q A1 N C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main139 X B1 T H A1 G F N Q O Y S B E A P R D1 Z M L I V K J C D U C1)
        (and (= E 1) (not (= B 0)) (= W 0))
      )
      (inv_main145 X B1 T H A1 G F N Q O Y S B W A P R D1 Z M L I V K J C D U C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main106 L Q C1 T B W N H G A1 I E Y D S X R P F Z O U C J A V K M B1)
        (and (not (= L 0)) (not (= Q 1)))
      )
      (inv_main192 L Q C1 T B W N H G A1 I E Y D S X R P F Z O U C J A V K M B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main109 U C1 O F B1 X Q A1 S G Z A N Y C L I H W B R M K P E D V J T)
        (and (not (= F 1)) (not (= O 0)))
      )
      (inv_main192 U C1 O F B1 X Q A1 S G Z A N Y C L I H W B R M K P E D V J T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main115 D W A1 V F B1 X Q B U R C1 H Y C Z I K P T G O E A N L J S M)
        (and (not (= F 0)) (not (= B1 1)))
      )
      (inv_main192 D W A1 V F B1 X Q B U R C1 H Y C Z I K P T G O E A N L J S M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main121 C P A K X T C1 B U F M V G H W B1 Q L O I A1 S E N D J Y Z R)
        (and (not (= B 1)) (not (= C1 0)))
      )
      (inv_main192 C P A K X T C1 B U F M V G H W B1 Q L O I A1 S E N D J Y Z R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main127 G E C1 Y N D C Z T U A1 M I K Q L O H P W V S J X F B A R B1)
        (and (not (= T 0)) (not (= U 1)))
      )
      (inv_main192 G E C1 Y N D C Z T U A1 M I K Q L O H P W V S J X F B A R B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main133 J Y N G F M B1 V E X R L I S O U W A1 B C K C1 P A Q H Z T D)
        (and (not (= L 1)) (not (= R 0)))
      )
      (inv_main192 J Y N G F M B1 V E X R L I S O U W A1 B C K C1 P A Q H Z T D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main139 R W S X E T Q F D Y V A Z G P C1 L J U B I C B1 M K H A1 O N)
        (and (not (= G 1)) (not (= Z 0)))
      )
      (inv_main192 R W S X E T Q F D Y V A Z G P C1 L J U B I C B1 M K H A1 O N)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main145 K Q V F A1 P N B1 Z O B M H U T J D W Y A I G S C1 R C X E L)
        (and (not (= J 1)) (not (= T 0)))
      )
      (inv_main192 K Q V F A1 P N B1 Z O B M H U T J D W Y A I G S C1 R C X E L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main151 U A N O Y X J C1 W D L V E H R B S Z B1 C A1 F Q T M I P K G)
        (and (not (= S 0)) (not (= Z 1)))
      )
      (inv_main192 U A N O Y X J C1 W D L V E H R B S Z B1 C A1 F Q T M I P K G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main157 Y A X H A1 W T S G Q F C1 D B1 N L B V U E Z P K I C J R O M)
        (and (not (= E 1)) (not (= U 0)))
      )
      (inv_main192 Y A X H A1 W T S G Q F C1 D B1 N L B V U E Z P K I C J R O M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main163 B1 S P C1 G C R H I W B K D X V Y L Q J U N O A1 T F E Z A M)
        (and (not (= N 0)) (not (= O 1)))
      )
      (inv_main192 B1 S P C1 G C R H I W B K D X V Y L Q J U N O A1 T F E Z A M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main169 I D N P A L H T Z W S A1 K B F C1 E X Y U C M B1 O R G J Q V)
        (and (not (= O 1)) (not (= B1 0)))
      )
      (inv_main192 I D N P A L H T Z W S A1 K B F C1 E X Y U C M B1 O R G J Q V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main175 O L Y J X N C C1 A1 G H Z T K B1 V S Q P B I A R W F E U M D)
        (and (not (= E 1)) (not (= F 0)))
      )
      (inv_main192 O L Y J X N C C1 A1 G H Z T K B1 V S Q P B I A R W F E U M D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main181 H G C N W K C1 O D S J V A R Z I U P M Q T E B1 Y A1 F B X L)
        (and (not (= B 0)) (not (= X 1)))
      )
      (inv_main192 H G C N W K C1 O D S J V A R Z I U P M Q T E B1 Y A1 F B X L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main127 C F Z E A1 K I Q L H A M P C1 S T N U W V O B G R Y X D J B1)
        (= L 0)
      )
      (inv_main133 C F Z E A1 K I Q L H A M P C1 S T N U W V O B G R Y X D J B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) ) 
    (=>
      (and
        (inv_main127 K B1 U B L N P W Y X H V D M R J F O G C Z I C1 E S T A1 Q A)
        (and (not (= Y 0)) (= X 1) (= D1 0))
      )
      (inv_main133 K B1 U B L N P W Y D1 H V D M R J F O G C Z I C1 E S T A1 Q A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) ) 
    (=>
      (and
        (inv_main192 C Z M B C1 K B1 E W X F U Y P J T H I A L D R G O Q V S A1 N)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
