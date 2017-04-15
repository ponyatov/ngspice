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

(defmacro rx-extra (&rest body-forms)
  (let ((rx-constituents (append *my-rx-constituents* rx-constituents)))
    (macroexpand `(rx ,@body-forms))))


(defun foo-bar()
  (let ((case-fold-search nil))
    (goto-char (point-min))
    (while (re-search-forward
            (rx-extra "(void)" ws0 "sprintf(" ws0 "name" comma
                      (group string) comma (group (regexp "[^,]+")) comma (group (regexp "[^)]+")) ");" ws0
                      "data->namelist" ws0 "=" ws0 "TREALLOC(" ws0 "IFuid" comma "data->namelist" comma "data->numPlots" ws0 "+" ws0 "1);" ws0
                      "if" ws0 "(!data->namelist)" ws0 "return(E_NOMEM);" ws0
                      "SPfrontEnd->IFnewUid" ws0 "(ckt" comma
                      (group "&(data->namelist[data->numPlots++])") comma
                      "NULL" comma "name" comma "UID_OTHER" comma "NULL);"
                      (? ws0 "/* we've added one more plot */"))
            nil t)
      (replace-match "NOISE_ADD_OUTVAR(ckt, data, \\1, \\2, \\3);"))))


(when nil
  (foo-bar))

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
