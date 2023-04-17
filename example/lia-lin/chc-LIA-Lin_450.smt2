; ./sv-comp/./2015-05-26/LIA/Eldarica/VHDL/synlifo.correct.nts_000.smt2
(set-logic HORN)

(declare-fun |main_s44| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s19| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s5| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s27| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_init_params| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s51| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s7| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s18| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s14| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s13| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s36| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s50| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s26| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s8| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s47| ( Int Int Int Int Int Int ) Bool)
(declare-fun |CHC_COMP_FALSE| ( ) Bool)
(declare-fun |main_s40| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s43| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s15| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s11| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s42| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s34| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s0| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s59| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s41| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s35| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s2| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s3| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s33| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s12| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s10| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s6| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s32| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s_init| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s39| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s46| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s4| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s1| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s58| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s45| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s9| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s37| ( Int Int Int Int Int Int ) Bool)
(declare-fun |main_s38| ( Int Int Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s46 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s38 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s14 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s6 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s38 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s14 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s6 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s44 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s36 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s12 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s4 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s36 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s12 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s4 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s40 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s32 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s8 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s0 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s32 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s8 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= H (+ (- 1) I))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (not (= H (+ (- 1) I)))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (not (= H (+ (- 1) I)))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s0 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s46 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s38 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s14 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s6 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s46 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s14 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s6 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s44 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s36 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s12 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s4 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s44 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s12 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s4 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s40 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s32 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s8 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s0 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s40 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= H (+ (- 1) I))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (not (= H (+ (- 1) I)))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (not (= H (+ (- 1) I)))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s8 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s0 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s46 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s38 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s14 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s6 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s46 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s38 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s6 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s44 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s36 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s12 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s4 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s44 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s36 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s4 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s40 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s32 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s8 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s0 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s40 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= H (+ (- 1) I))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (not (= H (+ (- 1) I)))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (not (= H (+ (- 1) I)))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s32 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s0 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s46 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s38 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s14 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s6 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s46 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s38 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s14 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s44 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s36 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s12 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s4 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s44 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s36 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s12 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s2 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s42 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s34 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s10 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s59 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s51 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s40 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s32 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s27 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s19 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s8 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s0 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s58 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s50 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s47 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= H (+ (- 1) I))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (not (= H 0)))
      )
      (main_s45 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (not (= H (+ (- 1) I)))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (= H 0))
      )
      (main_s43 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (not (= H (+ (- 1) I)))
     (= F I)
     (= E (+ (- 1) H))
     (= E (+ 1 H))
     (= D H)
     (not (= H 0)))
      )
      (main_s41 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s40 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s39 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s37 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (= H 0))
      )
      (main_s35 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ 1 H)) (= D H) (not (= H 0)))
      )
      (main_s33 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s32 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s26 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s15 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s13 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (= H 0))
      )
      (main_s11 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E (+ (- 1) H)) (= D H) (not (= H 0)))
      )
      (main_s9 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= E H) (= D G) (= F I))
      )
      (main_s8 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s7 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (= H (+ (- 1) I)) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s5 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (= H 0))
      )
      (main_s3 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C G H I)
        (and (not (= H (+ (- 1) I))) (= F I) (= E H) (= D H) (not (= H 0)))
      )
      (main_s1 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s_init A B C G H I)
        (and (= E 0) (= D 0) (= F I))
      )
      (main_s18 A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_init_params A B C G H I)
        (and (= E H) (not (<= I 1)) (= F I))
      )
      (main_s_init A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (and (= B E) (= A D) (= C F))
      )
      (main_init_params A B C D E F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s59 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s58 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s51 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s50 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s47 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (not (= D (+ (- 1) F))) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s46 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (not (= D (+ (- 1) F))) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s45 A B C D E F)
        (and (= H E) (= G D) (not (= D (+ (- 1) F))) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s44 A B C D E F)
        (and (= H E) (= G D) (not (= D (+ (- 1) F))) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s43 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (>= D (+ (- 1) F)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s42 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (>= D (+ (- 1) F)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s41 A B C D E F)
        (and (= H E) (= G D) (>= D (+ (- 1) F)) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s40 A B C D E F)
        (and (= H E) (= G D) (>= D (+ (- 1) F)) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s39 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (not (= D (+ (- 1) F))) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s38 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (not (= D (+ (- 1) F))) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s37 A B C D E F)
        (and (= H E) (= G D) (not (= D (+ (- 1) F))) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s36 A B C D E F)
        (and (= H E) (= G D) (not (= D (+ (- 1) F))) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s35 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (>= D (+ (- 1) F)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s34 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (>= D (+ (- 1) F)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s33 A B C D E F)
        (and (= H E) (= G D) (>= D (+ (- 1) F)) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s32 A B C D E F)
        (and (= H E) (= G D) (>= D (+ (- 1) F)) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s27 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s26 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s19 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s18 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s15 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (not (= D (+ (- 1) F))) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s14 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (not (= D (+ (- 1) F))) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s13 A B C D E F)
        (and (= H E) (= G D) (not (= D (+ (- 1) F))) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s12 A B C D E F)
        (and (= H E) (= G D) (not (= D (+ (- 1) F))) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s11 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (>= D (+ (- 1) F)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s10 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (>= D (+ (- 1) F)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s9 A B C D E F)
        (and (= H E) (= G D) (>= D (+ (- 1) F)) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s8 A B C D E F)
        (and (= H E) (= G D) (>= D (+ (- 1) F)) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s7 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (not (= D (+ (- 1) F))) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s6 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (not (= D (+ (- 1) F))) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s5 A B C D E F)
        (and (= H E) (= G D) (not (= D (+ (- 1) F))) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s4 A B C D E F)
        (and (= H E) (= G D) (not (= D (+ (- 1) F))) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s3 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (>= D (+ (- 1) F)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s2 A B C D E F)
        (and (= H E) (= G D) (not (= D 0)) (>= D (+ (- 1) F)) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s1 A B C D E F)
        (and (= H E) (= G D) (>= D (+ (- 1) F)) (<= D 0) (= I F))
      )
      CHC_COMP_FALSE
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) (G Int) (H Int) (I Int) ) 
    (=>
      (and
        (main_s0 A B C D E F)
        (and (= H E) (= G D) (>= D (+ (- 1) F)) (<= D 0) (= I F))
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
