;;; (load-file (buffer-file-name))

(defvar *my-rx-constituents*)
(setq *my-rx-constituents*
      `((string . ,(rx "\"" (*? (or (regexp "[^\\\"]") (regexp "\\."))) "\""))
        (comma . ,(rx (0+ (any " " "\t" "\n"))
                      ","
                      (0+ (any " " "\t" "\n"))))
        (white* . ,(rx (*? white)))
        (id . ,(rx (regexp "[a-zA-Z_][a-zA-Z_0-9]*?")))
        (ws0 . ,(rx (0+ (any " " "\t" "\n"))))
        (ws+ . ,(rx (+ (any " " "\t" "\n"))))
        (int . ,(rx (+ digit)))))


(defun foo-bar()
  (let ((case-fold-search nil))
    (goto-char (point-min))
    (while (re-search-forward
            (rx-extra ";" ws0 "char name[N_MXVLNTH];") nil t)
      (replace-match ";"))))

(when nil
  (foo-bar))

;;; SPfrontEnd->IFnewUid (ckt,&(data->namelist[data->numPlots++]),NULL, name, UID_OTHER, NULL);


(defun do-file (file)
  (with-current-buffer (find-file file)
    (widen)
    (goto-char (point-min))
    (foo-bar)
    (save-buffer)
    (kill-buffer)))

(defun doit ()
  (loop for file in (process-lines "git" "--no-pager" "grep" "-le" "\\bname\\b"
                                   "--" "*noi*.c")
        do (do-file file)))

(when t
  (doit))
