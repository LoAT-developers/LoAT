; ./seahorn/./sv_comp_flat_small/ldv-linux-3.4-simple/43_1a_cilled_true-unreach-call_ok_nondet_linux-43_1a-drivers--media--dvb--dvb-usb--dvb-usb-dibusb-mc.ko-ldv_main0_sequence_infinite_withcheck_stateful.cil.out.c.flat_000.smt2
(set-logic HORN)

(declare-fun |main_1| ( Int ) Bool)

(assert
  (forall ( (v_0 Int) ) 
    (=>
      (and
        (and true (= 0 v_0))
      )
      (main_1 v_0)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (v_7 Int) (v_8 Int) ) 
    (=>
      (and
        (main_1 v_7)
        (and (= 0 v_7)
     (or (not B) (not C) (not E))
     (or (not F) (and D G))
     (or (not D) (and C E))
     (= F true)
     (= B (= A 0))
     (= 1 v_8))
      )
      (main_1 v_8)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Bool) (D Bool) (E Bool) (F Bool) (G Bool) (v_7 Int) (v_8 Int) ) 
    (=>
      (and
        (main_1 v_7)
        (and (= 0 v_7)
     (or B (not C) (not E))
     (or (not F) (and D G))
     (or (not D) (and C E))
     (= F true)
     (= B (= A 0))
     (= 2 v_8))
      )
      (main_1 v_8)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (v_14 Int) (v_15 Int) ) 
    (=>
      (and
        (main_1 v_14)
        (and (= 1 v_14)
     (or (not F) (not L) (not G))
     (or D (not K) (not H))
     (or (not J) (and L G) (and K H))
     (or (not B) (not J) (not N))
     (or (not I) F (not G))
     (or (not H) (= D (= C 0)))
     (or (not H) (and I G))
     (or (not M) (and J N))
     (or (not J) (= B (= A 0)))
     (= M true)
     (= F (= E 0))
     (= 1 v_15))
      )
      (main_1 v_15)
    )
  )
)
(assert
  (forall ( (A Int) (B Bool) (C Int) (D Bool) (E Int) (F Bool) (G Bool) (H Bool) (I Bool) (J Bool) (K Bool) (L Bool) (M Bool) (N Bool) (O Bool) (P Bool) (Q Bool) (R Bool) (S Bool) (v_19 Int) (v_20 Int) ) 
    (=>
      (and
        (main_1 v_19)
        (and (= 1 v_19)
     (or (not M) (and O G) (and N K))
     (or (not G) F (not L))
     (or (not R) (not M) B)
     (or (not Q) (not K) (not D))
     (or (not P) (and R M) (and Q K))
     (or (not O) (not G) (not F))
     (or (not N) (not K) D)
     (or (not H) (and P S))
     (or (not M) (= B (= A 0)))
     (or (not K) (= D (= C 0)))
     (or (not K) (and G L))
     (or (not I) (and H J))
     (= I true)
     (= F (= E 0))
     (= 2 v_20))
      )
      (main_1 v_20)
    )
  )
)
(assert
  (forall ( (v_0 Int) ) 
    (=>
      (and
        (main_1 v_0)
        (= 2 v_0)
      )
      false
    )
  )
)

(check-sat)
(exit)
