;;; (load-file (buffer-file-name))

(when nil
  (grep "cd .. && git --no-pager grep -nHi -e 'isspace'"))

(setq *is-them*
      "isalnum\\|isalpha\\|iscntrl\\|isdigit\\|isgraph\\|islower\\|isprint\\|ispunct\\|isspace\\|isupper\\|isxdigit\\|isascii\\|isblank")

(setq *to-them*
      "tolower\\|toupper")

(defun insert-char-to-int()
  (let ((case-fold-search nil))
    (goto-char (point-min))
    (while (re-search-forward
            (concat "\\b\\(" *them* "\\) *(") nil t)
      (replace-match "\\1_c("))))

(defun do-file (file)
  (with-current-buffer (find-file file)
    (widen)
    (goto-char (point-min))
    (insert-char-to-int)
    (save-buffer)
    (kill-buffer)))

(when nil
  (let ((*them* *is-them*))
    (map nil #'do-file
         (process-lines "git" "--no-pager" "grep" "-le" *them* "--" "src")))
  (let ((*them* *to-them*))
    (map nil #'do-file
         (process-lines "git" "--no-pager" "grep" "-le" *them* "--" "src"))))

(when nil
  (let ((*them* *is-them*))
    (insert-char-to-int)))

;;; isspace(xx*(4+5))+8
