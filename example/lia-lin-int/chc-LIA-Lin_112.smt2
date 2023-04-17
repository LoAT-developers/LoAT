; ./tricera/sv-comp-2020/./mixed/s3_srvr_1b.cil.c-1_000.smt2
(set-logic HORN)

(declare-fun |inv_main9| ( Int Int Int Int ) Bool)
(declare-fun |inv_main3| ( Int ) Bool)
(declare-fun |inv_main45| ( Int Int Int Int ) Bool)
(declare-fun |inv_main56| ( Int Int Int Int ) Bool)

(assert
  (forall ( (A Int) ) 
    (=>
      (and
        true
      )
      (inv_main3 A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main9 A D C B)
        (and (<= A 8512) (<= 3 C))
      )
      (inv_main56 A D C B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main45 B A C D)
        (and (= C 5) (not (= C 4)))
      )
      (inv_main56 B A C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main9 E F B C)
        (and (= A 8656)
     (= E 8466)
     (= D 2)
     (not (= F 0))
     (or (not (<= 3 B)) (not (<= E 8512)))
     (= B 0))
      )
      (inv_main9 A F D C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main9 D C B A)
        (and (= E 2)
     (= D 8466)
     (= C 0)
     (= F 8512)
     (or (not (<= 3 B)) (not (<= D 8512)))
     (= B 0))
      )
      (inv_main9 F C E A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main9 B A E D)
        (and (= C 8656)
     (= B 8466)
     (not (= E 0))
     (or (not (<= 3 E)) (not (<= B 8512)))
     (not (= A 0)))
      )
      (inv_main9 C A E D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main9 D C E B)
        (and (= D 8466)
     (= C 0)
     (not (= E 0))
     (or (not (<= D 8512)) (not (<= 3 E)))
     (= A 8512))
      )
      (inv_main9 A C E B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main9 F A C B)
        (and (not (= D 0))
     (not (= F 8466))
     (= F 8512)
     (or (not (<= 3 C)) (not (<= F 8512)))
     (= E 8466))
      )
      (inv_main9 E A C D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main9 A F B D)
        (and (= A 8512)
     (= E 0)
     (= C 8640)
     (or (not (<= 3 B)) (not (<= A 8512)))
     (not (= A 8466)))
      )
      (inv_main9 C F B E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main9 B C A E)
        (and (not (= B 8466))
     (not (= B 8512))
     (= A 3)
     (= D 4)
     (= C 0)
     (= F 8656)
     (or (not (<= 3 A)) (not (<= B 8512)))
     (= B 8640))
      )
      (inv_main9 F C D E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main9 C E D A)
        (and (= C 8640)
     (not (= C 8466))
     (not (= C 8512))
     (= B 8656)
     (= E 0)
     (or (not (<= C 8512)) (not (<= 3 D)))
     (not (= D 3)))
      )
      (inv_main9 B E D A)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) (F Int) ) 
    (=>
      (and
        (inv_main45 E D C F)
        (and (= A 5) (not (= D 0)) (= C 4) (= B 8640))
      )
      (inv_main9 B D A F)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main45 B E D C)
        (and (not (= D 4)) (not (= D 5)) (not (= E 0)) (= A 8640))
      )
      (inv_main9 A E D C)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main3 E)
        (and (= D 0) (= A 8466))
      )
      (inv_main9 A C D B)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) (E Int) ) 
    (=>
      (and
        (inv_main9 B D C E)
        (and (= C 2)
     (not (= B 8640))
     (= B 8656)
     (not (= B 8466))
     (not (= B 8512))
     (or (not (<= B 8512)) (not (<= 3 C)))
     (= A 3))
      )
      (inv_main45 B D A E)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main9 C A B D)
        (and (= C 8656)
     (not (= C 8466))
     (not (= C 8512))
     (not (= B 2))
     (or (not (<= C 8512)) (not (<= 3 B)))
     (not (= C 8640)))
      )
      (inv_main45 C A B D)
    )
  )
)
(assert
  (forall ( (A Int) (B Int) (C Int) (D Int) ) 
    (=>
      (and
        (inv_main56 C A B D)
        true
      )
      false
    )
  )
)

(check-sat)
(exit)
