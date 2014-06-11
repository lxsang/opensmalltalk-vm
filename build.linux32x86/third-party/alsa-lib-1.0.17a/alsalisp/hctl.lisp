(setq card (Acall 'card_next -1))
(setq card (Aresult card))
(while (>= card 0)
  (progn
    (princ "found card: " card "\n")
    (princ "  name    : " (Aresult (Acall 'card_get_name card)) "\n")
    (princ "  longname: " (Aresult (Acall 'card_get_longname card)) "\n")
    (setq card (Acall 'card_next card))
    (setq card (Aresult card))
  )
)
(unsetq card)

(princ "card_get_index test (SI7018): " (Acall 'card_get_index "SI7018") "\n")
(princ "card_get_index test (ABCD): " (Acall 'card_get_index "ABCD") "\n")

(setq hctl (Acall 'hctl_open 'default nil))
(if (= (Aerror hctl) 0)
  (progn
    (princ "open success: " hctl "\n")
    (setq hctl (Ahandle hctl))
    (princ "open hctl: " hctl "\n")
    (setq hctl (Acall 'hctl_close hctl))
    (if (= hctl 0)
      (princ "close success\n")
      (princ "close failed: " hctl "\n")
    )
  )
  (progn
    (princ "open failed: " hctl "\n")
  )
)
(unsetq hctl)

(setq ctl (Acall 'ctl_open 'default nil))
(if (= (Aerror ctl) 0)
  (progn
    (princ "ctl open success: " ctl "\n")
    (setq ctl (Ahandle ctl))
    (setq info (Aresult (Acall 'ctl_card_info ctl)))
    (princ "ctl card info: " info "\n")
    (princ "ctl card info (mixername): " (cdr (assq "mixername" info)) "\n")
    (unsetq info)
    (setq hctl (Acall 'hctl_open_ctl ctl))
    (if (= (Aerror hctl) 0)
      (progn
        (princ "hctl open success: " hctl "\n")
        (setq hctl (Ahandle hctl))
        (princ "open hctl: " hctl "\n")
	(princ "load hctl: " (Acall 'hctl_load hctl) "\n")
	(princ "first    : " (Acall 'hctl_first_elem hctl) "\n")
	(princ "last     : " (Acall 'hctl_last_elem hctl) "\n")
	(princ "next (first): " (Acall 'hctl_elem_next (Acall 'hctl_first_elem hctl)) "\n")
	(princ "prev (last) : " (Acall 'hctl_elem_prev (Acall 'hctl_last_elem hctl)) "\n")
	(setq elem (Acall 'hctl_first_elem hctl))
	(while elem
	  (progn
	    (setq info (Acall 'hctl_elem_info elem))
	    (princ info "\n")
	    (setq value (Acall 'hctl_elem_read elem))
	    (princ value "\n")
	    (when (equal (cdr (assq "name" (car (cdr (assq "id" (Aresult info)))))) "Master Playback Volume")
	      (princ "write Master: " (Acall 'hctl_elem_write elem (20 20)) "\n")
	    )
	    (unsetq info value)
	    (gc)
	    (setq elem (Acall 'hctl_elem_next elem))
	  )
        )
	(unsetq elem)
        (setq hctl (Acall 'hctl_close hctl))
        (if (= hctl 0)
          (princ "hctl close success\n")
          (princ "hctl close failed: " hctl "\n")
        )
      )
      (progn
        (princ "hctl open failed: " hctl "\n")
	(Acall 'ctl_close ctl)
      )
    )
    (unsetq hctl)
  )
  (progn
    (princ "ctl open failed: " ctl "\n")
  )
)
(unsetq ctl)

(&stat-memory)
(&dump-memory "memory.dump")