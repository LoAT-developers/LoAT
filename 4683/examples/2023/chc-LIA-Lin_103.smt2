; ./prepared/tricera/sv-comp-2020/./mixed/test_locks_15-2.c-1_000.smt2
(set-logic HORN)


(declare-fun |inv_main188| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main92| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main98| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main80| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main104| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main122| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main205| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main74| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main134| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main140| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main182| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main170| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main116| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main86| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main110| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main158| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main2| ( ) Bool)
(declare-fun |inv_main194| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main176| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main152| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main48| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main128| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main146| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main113| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)
(declare-fun |inv_main164| ( Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int Int ) Bool)

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
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main113 R Q B1 C L X D G J H A1 E K S T I Y A D1 P V O E1 U M N W B Z F C1)
        (and (not (= Q 1)) (not (= R 0)))
      )
      (inv_main205 R Q B1 C L X D G J H A1 E K S T I Y A D1 P V O E1 U M N W B Z F C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main116 L G A1 I F M R Q A B H D1 Z S E1 J X E Y P W T V N D O C U C1 B1 K)
        (and (not (= I 1)) (not (= A1 0)))
      )
      (inv_main205 L G A1 I F M R Q A B H D1 Z S E1 J X E Y P W T V N D O C U C1 B1 K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main122 V O A1 L R D1 S B1 E C1 B P T I U X M Q G K J C N Z Y H A D E1 F W)
        (and (not (= R 0)) (not (= D1 1)))
      )
      (inv_main205 V O A1 L R D1 S B1 E C1 B P T I U X M Q G K J C N Z Y H A D E1 F W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main128 R K O V E C1 W E1 F Z X D C B S H I M A1 B1 J Q D1 P A T Y N L U G)
        (and (not (= W 0)) (not (= E1 1)))
      )
      (inv_main205 R K O V E C1 W E1 F Z X D C B S H I M A1 B1 J Q D1 P A T Y N L U G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main134 C1 W E1 M B1 D1 D H A K L N P Q X Y B E O Z S I C V A1 F G R U J T)
        (and (not (= A 0)) (not (= K 1)))
      )
      (inv_main205 C1 W E1 M B1 D1 D H A K L N P Q X Y B E O Z S I C V A1 F G R U J T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main140 B C I F L E K S B1 X G U D1 E1 C1 P N H T W R Z V Y O M D J A A1 Q)
        (and (not (= G 0)) (not (= U 1)))
      )
      (inv_main205 B C I F L E K S B1 X G U D1 E1 C1 P N H T W R Z V Y O M D J A A1 Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main146 I N Q E P D W E1 B1 T V L Z F D1 R Y O C A1 J C1 S A K B U M X H G)
        (and (not (= F 1)) (not (= Z 0)))
      )
      (inv_main205 I N Q E P D W E1 B1 T V L Z F D1 R Y O C A1 J C1 S A K B U M X H G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main152 V D A1 P Z C B F O J M I A Y E1 X H U K Q L B1 G D1 C1 W S E N T R)
        (and (not (= X 1)) (not (= E1 0)))
      )
      (inv_main205 V D A1 P Z C B F O J M I A Y E1 X H U K Q L B1 G D1 C1 W S E N T R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main158 Z C N O Q D1 P K A1 B Y C1 F H I U E1 D L X J M A G S T E V B1 R W)
        (and (not (= D 1)) (not (= E1 0)))
      )
      (inv_main205 Z C N O Q D1 P K A1 B Y C1 F H I U E1 D L X J M A G S T E V B1 R W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main164 E1 W J Q K O N D1 Z C1 V I S C E A1 B1 U M Y H A L T B P R G D F X)
        (and (not (= M 0)) (not (= Y 1)))
      )
      (inv_main205 E1 W J Q K O N D1 Z C1 V I S C E A1 B1 U M Y H A L T B P R G D F X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main170 M R I E1 B S H X D O F U E D1 W C A P Q J V K B1 Z Y L C1 N T G A1)
        (and (not (= K 1)) (not (= V 0)))
      )
      (inv_main205 M R I E1 B S H X D O F U E D1 W C A P Q J V K B1 Z Y L C1 N T G A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main176 C B1 D1 Q N D R K I X Y B O V M Z C1 A F J E L E1 W G A1 P H U S T)
        (and (not (= W 1)) (not (= E1 0)))
      )
      (inv_main205 C B1 D1 Q N D R K I X Y B O V M Z C1 A F J E L E1 W G A1 P H U S T)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main182 Q K C R T Y G D J M F B1 O A X E1 I B N U L A1 C1 W S V H D1 Z E P)
        (and (not (= S 0)) (not (= V 1)))
      )
      (inv_main205 Q K C R T Y G D J M F B1 O A X E1 I B N U L A1 C1 W S V H D1 Z E P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main188 A Y T P F K E1 C H S O D1 B J W N V I L C1 D Z U Q E B1 A1 X G R M)
        (and (not (= X 1)) (not (= A1 0)))
      )
      (inv_main205 A Y T P F K E1 C H S O D1 B J W N V I L C1 D Z U Q E B1 A1 X G R M)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main194 K H F G E1 B E M D S Z U R P W N L B1 C V Q X A A1 C1 D1 J O Y T I)
        (and (not (= T 1)) (not (= Y 0)))
      )
      (inv_main205 K H F G E1 B E M D S Z U R P W N L B1 C V Q X A A1 C1 D1 J O Y T I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (inv_main80 O
            C
            H
            Y
            A
            T
            D
            W
            V
            G
            R
            M
            P
            U
            C1
            X
            Z
            K
            F
            E1
            A1
            E
            Q
            F1
            G1
            L
            N
            B1
            J
            S
            D1)
        (and (not (= V 0)) (not (= R 0)) (= I 1) (= B 1))
      )
      (inv_main86 O
            C
            H
            Y
            A
            T
            D
            W
            V
            I
            R
            B
            P
            U
            C1
            X
            Z
            K
            F
            E1
            A1
            E
            Q
            F1
            G1
            L
            N
            B1
            J
            S
            D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main80 A R C1 C A1 L D1 H O M T J K P Y U G E F1 F B1 D I V S Q N X E1 B W)
        (and (= T 0) (not (= O 0)) (= Z 1))
      )
      (inv_main86 A R C1 C A1 L D1 H O Z T J K P Y U G E F1 F B1 D I V S Q N X E1 B W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main80 O M V F D1 H N A Z K F1 B J U I W E P G T X E1 D Q S L C1 B1 C Y R)
        (and (= A1 1) (= Z 0) (not (= F1 0)))
      )
      (inv_main86 O M V F D1 H N A Z K F1 A1 J U I W E P G T X E1 D Q S L C1 B1 C Y R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main80 Q I U F P J T E R X D1 G W N Z K A1 O D C1 L Y C A B B1 H V M S E1)
        (and (= R 0) (= D1 0))
      )
      (inv_main86 Q I U F P J T E R X D1 G W N Z K A1 O D C1 L Y C A B B1 H V M S E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main146 U D1 P N J F Y M B B1 D S E1 L A1 T C1 C K X A Z R H W I Q V E G O)
        (= E1 0)
      )
      (inv_main152 U D1 P N J F Y M B B1 D S E1 L A1 T C1 C K X A Z R H W I Q V E G O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main146 H
             X
             E1
             F1
             D
             L
             S
             D1
             I
             T
             E
             P
             A1
             Y
             C
             A
             G
             V
             K
             R
             J
             M
             O
             Q
             N
             C1
             F
             B1
             W
             B
             U)
        (and (= Z 0) (= Y 1) (not (= A1 0)))
      )
      (inv_main152 H
             X
             E1
             F1
             D
             L
             S
             D1
             I
             T
             E
             P
             A1
             Z
             C
             A
             G
             V
             K
             R
             J
             M
             O
             Q
             N
             C1
             F
             B1
             W
             B
             U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main122 C1 R G A1 E1 O N B B1 D A U L M P W X Q E F K J T V Y D1 C Z I H S)
        (= E1 0)
      )
      (inv_main128 C1 R G A1 E1 O N B B1 D A U L M P W X Q E F K J T V Y D1 C Z I H S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main122 A1
             I
             B
             H
             N
             S
             Q
             Y
             F1
             J
             B1
             E
             C
             X
             D
             G
             Z
             F
             W
             M
             U
             P
             E1
             D1
             O
             T
             R
             L
             K
             A
             C1)
        (and (= S 1) (not (= N 0)) (= V 0))
      )
      (inv_main128 A1
             I
             B
             H
             N
             V
             Q
             Y
             F1
             J
             B1
             E
             C
             X
             D
             G
             Z
             F
             W
             M
             U
             P
             E1
             D1
             O
             T
             R
             L
             K
             A
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main188 Q L G H B1 T A W E1 Z D1 R A1 C1 V M E S C K Y O J P D X I F B N U)
        (= I 0)
      )
      (inv_main194 Q L G H B1 T A W E1 Z D1 R A1 C1 V M E S C K Y O J P D X I F B N U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main188 I
             F
             E1
             Z
             E
             C
             R
             F1
             B1
             P
             T
             N
             D1
             M
             L
             A
             X
             S
             U
             B
             W
             Q
             V
             G
             C1
             O
             H
             D
             K
             J
             A1)
        (and (not (= H 0)) (= D 1) (= Y 0))
      )
      (inv_main194 I
             F
             E1
             Z
             E
             C
             R
             F1
             B1
             P
             T
             N
             D1
             M
             L
             A
             X
             S
             U
             B
             W
             Q
             V
             G
             C1
             O
             H
             Y
             K
             J
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main140 A1 P Z N M O E K C B1 J L T G D1 B C1 Q Y R I E1 D U S H A F W X V)
        (= J 0)
      )
      (inv_main146 A1 P Z N M O E K C B1 J L T G D1 B C1 Q Y R I E1 D U S H A F W X V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main140 T
             X
             J
             F
             E1
             D1
             C1
             O
             M
             G
             C
             F1
             L
             Z
             K
             N
             S
             U
             W
             A1
             V
             R
             H
             Y
             Q
             D
             I
             B1
             E
             P
             B)
        (and (= F1 1) (not (= C 0)) (= A 0))
      )
      (inv_main146 T X J F E1 D1 C1 O M G C A L Z K N S U W A1 V R H Y Q D I B1 E P B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main176 F E K B1 U A Z J D1 D G W T H A1 Y V N M X C1 C R L E1 S O P Q I B)
        (= R 0)
      )
      (inv_main182 F E K B1 U A Z J D1 D G W T H A1 Y V N M X C1 C R L E1 S O P Q I B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main176 Z
             E1
             C
             O
             L
             E
             T
             H
             D1
             J
             F
             W
             A
             K
             D
             Y
             B
             I
             R
             B1
             S
             N
             V
             A1
             G
             C1
             Q
             F1
             P
             M
             U)
        (and (= X 0) (not (= V 0)) (= A1 1))
      )
      (inv_main182 Z E1 C O L E T H D1 J F W A K D Y B I R B1 S N V X G C1 Q F1 P M U)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main158 K U F S L O C1 J Y G D1 D N C I X Q E P T B1 M W A B Z A1 H V R E1)
        (= Q 0)
      )
      (inv_main164 K U F S L O C1 J Y G D1 D N C I X Q E P T B1 M W A B Z A1 H V R E1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main158 P
             V
             F
             F1
             U
             K
             S
             Z
             O
             G
             Q
             J
             T
             E1
             B1
             I
             E
             B
             D1
             Y
             M
             H
             C1
             C
             R
             N
             X
             L
             W
             D
             A1)
        (and (not (= E 0)) (= B 1) (= A 0))
      )
      (inv_main164 P
             V
             F
             F1
             U
             K
             S
             Z
             O
             G
             Q
             J
             T
             E1
             B1
             I
             E
             A
             D1
             Y
             M
             H
             C1
             C
             R
             N
             X
             L
             W
             D
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main110 W
             Z
             H
             E1
             M
             A1
             B
             J
             L
             T
             D
             R
             K
             B1
             C
             E
             Y
             I
             O
             D1
             A
             F1
             F
             G
             S
             N
             V
             C1
             P
             U
             Q)
        (and (not (= P 0)) (= X 1))
      )
      (inv_main113 W
             Z
             H
             E1
             M
             A1
             B
             J
             L
             T
             D
             R
             K
             B1
             C
             E
             Y
             I
             O
             D1
             A
             F1
             F
             G
             S
             N
             V
             C1
             P
             X
             Q)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main110 I H Q E C D1 A V E1 Z C1 J O U R X K F N S B W L Y D G T P M A1 B1)
        (= M 0)
      )
      (inv_main113 I H Q E C D1 A V E1 Z C1 J O U R X K F N S B W L Y D G T P M A1 B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main128 Y H U B1 X S V E P B M O A I E1 A1 F K W D G Z N C T Q L J C1 D1 R)
        (= V 0)
      )
      (inv_main134 Y H U B1 X S V E P B M O A I E1 A1 F K W D G Z N C T Q L J C1 D1 R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main128 E1
             M
             K
             L
             D
             Z
             N
             V
             F
             I
             Q
             Y
             X
             T
             P
             F1
             D1
             A1
             A
             S
             C1
             G
             R
             O
             C
             W
             B
             B1
             U
             J
             H)
        (and (not (= N 0)) (= E 0) (= V 1))
      )
      (inv_main134 E1
             M
             K
             L
             D
             Z
             N
             E
             F
             I
             Q
             Y
             X
             T
             P
             F1
             D1
             A1
             A
             S
             C1
             G
             R
             O
             C
             W
             B
             B1
             U
             J
             H)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (inv_main86 G
            O
            Z
            C1
            E
            H
            K
            A
            W
            E1
            V
            T
            Y
            S
            C
            F
            P
            R
            Q
            F1
            N
            X
            B1
            D
            I
            L
            A1
            D1
            M
            G1
            J)
        (and (not (= Y 0)) (= U 1) (not (= C 0)) (= B 1))
      )
      (inv_main92 G
            O
            Z
            C1
            E
            H
            K
            A
            W
            E1
            V
            T
            Y
            U
            C
            B
            P
            R
            Q
            F1
            N
            X
            B1
            D
            I
            L
            A1
            D1
            M
            G1
            J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main86 X L O V C B H J F C1 G T R Z D1 P Y A E1 W D A1 Q E B1 U I S F1 M K)
        (and (not (= R 0)) (= N 1) (= D1 0))
      )
      (inv_main92 X L O V C B H J F C1 G T R N D1 P Y A E1 W D A1 Q E B1 U I S F1 M K)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main86 A D1 C1 Z G T K A1 C H W P U F1 Y Q E L E1 V B1 M R J N F D I S O X)
        (and (= U 0) (= B 1) (not (= Y 0)))
      )
      (inv_main92 A D1 C1 Z G T K A1 C H W P U F1 Y B E L E1 V B1 M R J N F D I S O X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main86 Q E1 Y I A1 R X S B1 O W V D1 C1 D C E M L A B T K N U J H G F Z P)
        (and (= D 0) (= D1 0))
      )
      (inv_main92 Q E1 Y I A1 R X S B1 O W V D1 C1 D C E M L A B T K N U J H G F Z P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (inv_main104 A
             I
             Y
             H
             W
             D
             A1
             C
             O
             B1
             U
             F
             N
             K
             P
             T
             M
             R
             F1
             G
             C1
             E
             J
             Z
             E1
             V
             X
             S
             Q
             D1
             B)
        (and (not (= E1 0)) (not (= X 0)) (= L 1) (= G1 1))
      )
      (inv_main110 A
             I
             Y
             H
             W
             D
             A1
             C
             O
             B1
             U
             F
             N
             K
             P
             T
             M
             R
             F1
             G
             C1
             E
             J
             Z
             E1
             L
             X
             G1
             Q
             D1
             B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main104 L K P B1 A1 C F B M Z E1 I D D1 G R U T C1 E Y A X N W J Q H S O V)
        (and (not (= W 0)) (= Q 0) (= F1 1))
      )
      (inv_main110 L
             K
             P
             B1
             A1
             C
             F
             B
             M
             Z
             E1
             I
             D
             D1
             G
             R
             U
             T
             C1
             E
             Y
             A
             X
             N
             W
             F1
             Q
             H
             S
             O
             V)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main104 N
             P
             Y
             Z
             G
             Q
             C
             T
             E
             B
             B1
             W
             F
             I
             L
             J
             H
             D
             V
             A
             O
             U
             K
             S
             E1
             R
             D1
             X
             A1
             F1
             C1)
        (and (not (= D1 0)) (= M 1) (= E1 0))
      )
      (inv_main110 N
             P
             Y
             Z
             G
             Q
             C
             T
             E
             B
             B1
             W
             F
             I
             L
             J
             H
             D
             V
             A
             O
             U
             K
             S
             E1
             R
             D1
             M
             A1
             F1
             C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main104 D A N R G T H X V B1 P Y C F E E1 B L W O Q A1 M K C1 J I S Z U D1)
        (and (= I 0) (= C1 0))
      )
      (inv_main110 D A N R G T H X V B1 P Y C F E E1 B L W O Q A1 M K C1 J I S Z U D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main134 O V A1 K N B E1 D1 A S J L R Q E P Z C1 H C B1 F Y T I U M G W X D)
        (= A 0)
      )
      (inv_main140 O V A1 K N B E1 D1 A S J L R Q E P Z C1 H C B1 F Y T I U M G W X D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main134 P E S I C1 M A1 Y H X T U W F1 D B1 A N B F V R K Q Z G J O C E1 L)
        (and (= X 1) (not (= H 0)) (= D1 0))
      )
      (inv_main140 P
             E
             S
             I
             C1
             M
             A1
             Y
             H
             D1
             T
             U
             W
             F1
             D
             B1
             A
             N
             B
             F
             V
             R
             K
             Q
             Z
             G
             J
             O
             C
             E1
             L)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main152 E1 Z Y J H D1 D Q A R V P M B O F L C U C1 B1 G S W N X T I K A1 E)
        (= O 0)
      )
      (inv_main158 E1 Z Y J H D1 D Q A R V P M B O F L C U C1 B1 G S W N X T I K A1 E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main152 D
             A1
             N
             B
             S
             R
             M
             V
             P
             Q
             H
             F
             X
             E1
             T
             C
             C1
             W
             J
             I
             L
             B1
             O
             K
             E
             G
             F1
             A
             D1
             U
             Z)
        (and (not (= T 0)) (= C 1) (= Y 0))
      )
      (inv_main158 D
             A1
             N
             B
             S
             R
             M
             V
             P
             Q
             H
             F
             X
             E1
             T
             Y
             C1
             W
             J
             I
             L
             B1
             O
             K
             E
             G
             F1
             A
             D1
             U
             Z)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main113 T B1 N L F R A A1 P V Y Z S W B C Q E1 J X M I K D1 H U E O D C1 G)
        (= T 0)
      )
      (inv_main116 T B1 N L F R A A1 P V Y Z S W B C Q E1 J X M I K D1 H U E O D C1 G)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main113 D1 B H S P J C T C1 X N Z G D U K Y I M V A1 Q E O F F1 E1 L R W A)
        (and (= B1 0) (= B 1) (not (= D1 0)))
      )
      (inv_main116 D1
             B1
             H
             S
             P
             J
             C
             T
             C1
             X
             N
             Z
             G
             D
             U
             K
             Y
             I
             M
             V
             A1
             Q
             E
             O
             F
             F1
             E1
             L
             R
             W
             A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main164 U P G A1 W C V E1 B D1 J D N I B1 K T X O E L Z C1 Y Q M H R F A S)
        (= O 0)
      )
      (inv_main170 U P G A1 W C V E1 B D1 J D N I B1 K T X O E L Z C1 Y Q M H R F A S)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main164 X
             B1
             R
             N
             F1
             A
             Z
             E1
             C1
             D1
             K
             L
             Y
             G
             J
             I
             C
             B
             F
             Q
             E
             M
             O
             W
             P
             U
             S
             T
             D
             H
             A1)
        (and (= Q 1) (not (= F 0)) (= V 0))
      )
      (inv_main170 X
             B1
             R
             N
             F1
             A
             Z
             E1
             C1
             D1
             K
             L
             Y
             G
             J
             I
             C
             B
             F
             V
             E
             M
             O
             W
             P
             U
             S
             T
             D
             H
             A1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (inv_main98 Z
            F
            O
            F1
            I
            U
            R
            B1
            E
            W
            A
            L
            N
            X
            G1
            P
            C
            V
            K
            M
            E1
            C1
            H
            D
            G
            B
            A1
            S
            T
            Y
            D1)
        (and (= Q 1) (= J 1) (not (= H 0)) (not (= E1 0)))
      )
      (inv_main104 Z
             F
             O
             F1
             I
             U
             R
             B1
             E
             W
             A
             L
             N
             X
             G1
             P
             C
             V
             K
             M
             E1
             Q
             H
             J
             G
             B
             A1
             S
             T
             Y
             D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main98 B1 X E R Y D Q J E1 F S A1 U D1 C1 G O A L P H N W V Z F1 T B K M I)
        (and (not (= H 0)) (= C 1) (= W 0))
      )
      (inv_main104 B1
             X
             E
             R
             Y
             D
             Q
             J
             E1
             F
             S
             A1
             U
             D1
             C1
             G
             O
             A
             L
             P
             H
             C
             W
             V
             Z
             F1
             T
             B
             K
             M
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main98 D N F Y A1 E1 B T U X H F1 C B1 J C1 Q L S Z G W E R P A K M D1 V I)
        (and (= G 0) (not (= E 0)) (= O 1))
      )
      (inv_main104 D
             N
             F
             Y
             A1
             E1
             B
             T
             U
             X
             H
             F1
             C
             B1
             J
             C1
             Q
             L
             S
             Z
             G
             W
             E
             O
             P
             A
             K
             M
             D1
             V
             I)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main98 H R N G F U W I Q D1 E1 M D C Y P V C1 E O Z K A B1 X L A1 S T B J)
        (and (= A 0) (= Z 0))
      )
      (inv_main104 H R N G F U W I Q D1 E1 M D C Y P V C1 E O Z K A B1 X L A1 S T B J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main182 C B T N R O H K A1 I F S D1 X A M J G E1 U Q Z D E V B1 C1 W L P Y)
        (= V 0)
      )
      (inv_main188 C B T N R O H K A1 I F S D1 X A M J G E1 U Q Z D E V B1 C1 W L P Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main182 E
             G
             O
             E1
             V
             I
             B
             A
             C
             K
             J
             S
             F
             T
             P
             D1
             W
             N
             F1
             M
             D
             A1
             U
             C1
             H
             L
             Q
             X
             B1
             Z
             Y)
        (and (= L 1) (not (= H 0)) (= R 0))
      )
      (inv_main188 E
             G
             O
             E1
             V
             I
             B
             A
             C
             K
             J
             S
             F
             T
             P
             D1
             W
             N
             F1
             M
             D
             A1
             U
             C1
             H
             R
             Q
             X
             B1
             Z
             Y)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main170 T Y R I C1 D1 C K H A1 M Q W E B1 P V D Z A O G L E1 U J X N B S F)
        (= O 0)
      )
      (inv_main176 T Y R I C1 D1 C K H A1 M Q W E B1 P V D Z A O G L E1 U J X N B S F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main170 U
             V
             J
             S
             K
             B1
             R
             X
             A1
             F1
             E1
             Q
             F
             D1
             Z
             B
             I
             L
             C
             N
             H
             Y
             A
             O
             E
             C1
             G
             M
             W
             T
             P)
        (and (not (= H 0)) (= D 0) (= Y 1))
      )
      (inv_main176 U
             V
             J
             S
             K
             B1
             R
             X
             A1
             F1
             E1
             Q
             F
             D1
             Z
             B
             I
             L
             C
             N
             H
             D
             A
             O
             E
             C1
             G
             M
             W
             T
             P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (inv_main92 A X V B1 P C O Y G1 G F1 B I T U W Z J D E1 N D1 F S H L M Q E K C1)
        (and (not (= Z 0)) (= R 1) (not (= D 0)) (= A1 1))
      )
      (inv_main98 A X V B1 P C O Y G1 G F1 B I T U W Z R D A1 N D1 F S H L M Q E K C1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main92 E D X G Z R Q C D1 M L S N U C1 P F T A W E1 A1 B F1 H Y V K J I O)
        (and (= B1 1) (not (= F 0)) (= A 0))
      )
      (inv_main98 E D X G Z R Q C D1 M L S N U C1 P F B1 A W E1 A1 B F1 H Y V K J I O)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main92 M I K Z C1 E D Y E1 O W S L J Q V A T X R A1 H D1 C B F F1 U B1 N P)
        (and (not (= X 0)) (= G 1) (= A 0))
      )
      (inv_main98 M I K Z C1 E D Y E1 O W S L J Q V A T X G A1 H D1 C B F F1 U B1 N P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main92 B1 X U A H Y V G A1 O Z L D Q C1 E1 J I M P W F T E R C S N K B D1)
        (and (= J 0) (= M 0))
      )
      (inv_main98 B1 X U A H Y V G A1 O Z L D Q C1 E1 J I M P W F T E R C S N K B D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) ) 
    (=>
      (and
        (inv_main74 I F1 B F C A1 Y N G1 K D O J U A X C1 T R Q H M L G V S E1 E D1 Z P)
        (and (not (= Y 0)) (= W 1) (not (= C 0)) (= B1 1))
      )
      (inv_main80 I F1 B F C W Y B1 G1 K D O J U A X C1 T R Q H M L G V S E1 E D1 Z P)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main74 R Y O T C J S P V F1 Q W A X E1 E B Z K D C1 U G A1 B1 L D1 H I M F)
        (and (= N 1) (not (= C 0)) (= S 0))
      )
      (inv_main80 R Y O T C N S P V F1 Q W A X E1 E B Z K D C1 U G A1 B1 L D1 H I M F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main74 F1 X S M E H A O N I D1 F L C1 Y E1 R T V Q J B P K B1 W G Z C U D)
        (and (= A1 1) (= E 0) (not (= A 0)))
      )
      (inv_main80 F1 X S M E H A A1 N I D1 F L C1 Y E1 R T V Q J B P K B1 W G Z C U D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main74 E1 B U M T D S A C F D1 J K Q E X I P C1 O Y G H Z A1 W N R L V B1)
        (and (= S 0) (= T 0))
      )
      (inv_main80 E1 B U M T D S A C F D1 J K Q E X I P C1 O Y G H Z A1 W N R L V B1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main116 C G N D1 S A1 E Z M T K O Q D X C1 Y W J B1 V H A U E1 L B P F I R)
        (= N 0)
      )
      (inv_main122 C G N D1 S A1 E Z M T K O Q D X C1 Y W J B1 V H A U E1 L B P F I R)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main116 P
             C1
             J
             U
             O
             A1
             Z
             Y
             R
             F1
             N
             C
             B1
             K
             D
             E
             G
             X
             E1
             M
             V
             Q
             B
             H
             I
             T
             S
             D1
             A
             F
             W)
        (and (= L 0) (not (= J 0)) (= U 1))
      )
      (inv_main122 P
             C1
             J
             L
             O
             A1
             Z
             Y
             R
             F1
             N
             C
             B1
             K
             D
             E
             G
             X
             E1
             M
             V
             Q
             B
             H
             I
             T
             S
             D1
             A
             F
             W)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main194 A U Z P D G A1 D1 C R E1 N K V I X T B L M O B1 H F W E Q Y S C1 J)
        (= S 0)
      )
      (inv_main48 A U Z P D G A1 D1 C R E1 N K V I X T B L M O B1 H F W E Q Y S C1 J)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) ) 
    (=>
      (and
        (inv_main194 X
             Z
             E
             E1
             M
             P
             G
             D1
             J
             V
             Y
             Q
             F
             R
             I
             L
             U
             C
             C1
             S
             H
             W
             B1
             N
             O
             D
             A1
             T
             K
             B
             F1)
        (and (not (= K 0)) (= B 1) (= A 0))
      )
      (inv_main48 X Z E E1 M P G D1 J V Y Q F R I L U C C1 S H W B1 N O D A1 T K A F1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        inv_main2
        true
      )
      (inv_main48 Y R W G Z Q A1 F T M S P H N L O K I E D1 B D C1 E1 V A B1 J C U X)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) ) 
    (=>
      (and
        (inv_main48 T1
            R1
            G1
            B1
            B
            U
            C1
            X
            K
            A1
            H
            S1
            F1
            I
            W
            J
            E1
            Z
            O
            H1
            P
            R
            L
            F
            D
            O1
            K1
            N1
            U1
            M1
            V)
        (and (= M 0)
     (= G 1)
     (= E 0)
     (= C 0)
     (= A 0)
     (not (= T1 0))
     (= Q1 0)
     (= P1 0)
     (= L1 0)
     (= J1 0)
     (= I1 0)
     (not (= G1 0))
     (not (= D1 0))
     (= Y 0)
     (= T 0)
     (= S 0)
     (= Q 1)
     (= N 0))
      )
      (inv_main74 T1
            Q
            G1
            G
            B
            I1
            C1
            N
            K
            J1
            H
            S
            F1
            M
            W
            Y
            E1
            E
            O
            P1
            P
            L1
            L
            A
            D
            C
            K1
            T
            U1
            Q1
            D1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) ) 
    (=>
      (and
        (inv_main48 Z
            D
            C1
            N
            N1
            O
            G
            S
            L
            K1
            H1
            F1
            A1
            J1
            Y
            Q
            I
            Q1
            U1
            F
            E1
            S1
            H
            R
            E
            B
            P
            V
            M1
            X
            R1)
        (and (= K 0)
     (= J 0)
     (= C 0)
     (= A 0)
     (= T1 1)
     (= P1 0)
     (= O1 0)
     (not (= L1 0))
     (= I1 0)
     (= G1 0)
     (= D1 0)
     (= C1 0)
     (= B1 0)
     (not (= Z 0))
     (= W 0)
     (= U 0)
     (= T 0)
     (= M 0))
      )
      (inv_main74 Z
            T1
            C1
            M
            N1
            W
            G
            B1
            L
            T
            H1
            U
            A1
            J
            Y
            G1
            I
            O1
            U1
            A
            E1
            C
            H
            K
            E
            D1
            P
            I1
            M1
            P1
            L1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) ) 
    (=>
      (and
        (inv_main48 K1
            J
            N1
            G
            E
            X
            C1
            S1
            U1
            V
            O1
            T1
            H1
            J1
            D1
            B1
            W
            P
            F
            N
            R1
            Q1
            I1
            K
            M
            Q
            L1
            Y
            L
            F1
            I)
        (and (= D 0)
     (= C 1)
     (= B 0)
     (= A 0)
     (= O 0)
     (= P1 0)
     (not (= N1 0))
     (= M1 0)
     (= K1 0)
     (not (= G1 0))
     (= E1 0)
     (= A1 0)
     (= Z 0)
     (= U 0)
     (= T 0)
     (= S 0)
     (= R 0)
     (= H 0))
      )
      (inv_main74 K1
            P1
            N1
            C
            E
            Z
            C1
            D
            U1
            S
            O1
            H
            H1
            B
            D1
            M1
            W
            A
            F
            U
            R1
            O
            I1
            R
            M
            A1
            L1
            T
            L
            E1
            G1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) (F1 Int) (G1 Int) (H1 Int) (I1 Int) (J1 Int) (K1 Int) (L1 Int) (M1 Int) (N1 Int) (O1 Int) (P1 Int) (Q1 Int) (R1 Int) (S1 Int) (T1 Int) (U1 Int) ) 
    (=>
      (and
        (inv_main48 A1
            J
            G1
            Q
            B
            L
            S
            Y
            W
            I
            T
            U1
            G
            R
            M1
            N
            J1
            B1
            Z
            U
            I1
            A
            H
            D1
            K
            O1
            E1
            N1
            X
            P
            C1)
        (and (= F 0)
     (= E 0)
     (= D 0)
     (= C 0)
     (= O 0)
     (= T1 0)
     (= S1 0)
     (= R1 0)
     (= Q1 0)
     (not (= P1 0))
     (= L1 0)
     (= K1 0)
     (= H1 0)
     (= G1 0)
     (= F1 0)
     (= A1 0)
     (= V 0)
     (= M 0))
      )
      (inv_main74 A1
            L1
            G1
            O
            B
            Q1
            S
            C
            W
            S1
            T
            H1
            G
            F
            M1
            V
            J1
            E
            Z
            T1
            I1
            M
            H
            K1
            K
            R1
            E1
            D
            X
            F1
            P1)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) (J Int) (K Int) (L Int) (M Int) (N Int) (O Int) (P Int) (Q Int) (R Int) (S Int) (T Int) (U Int) (V Int) (W Int) (X Int) (Y Int) (Z Int) (A1 Int) (B1 Int) (C1 Int) (D1 Int) (E1 Int) ) 
    (=>
      (and
        (inv_main205 I A J R O V E1 Q F M D1 S U N B Y A1 P G T H B1 E Z X L W K D C C1)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
