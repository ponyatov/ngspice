;;; (load-file (buffer-file-name))

(when nil
  (grep "cd .. && git --no-pager grep -nHi -e 'isspace'"))

(setq *them*
      "isalnum\\|isalpha\\|iscntrl\\|isdigit\\|isgraph\\|islower\\|isprint\\|ispunct\\|isspace\\|isupper\\|isxdigit\\|isascii\\|isblank\\|tolower\\|toupper")

(defun insert-char-to-int()
  (let ((case-fold-search nil))
    (goto-char (point-min))
    (while (re-search-forward
            (concat "\\b\\(" *them* "\\) *(\\(char_to_int\\)?") nil t)
      (unless (match-beginning 2)
        (let ((e (scan-sexps (- (match-end 0) 1) 1)))
          (when e
            (save-excursion
              (goto-char e)
              (insert ")"))
            (replace-match "\\1(char_to_int(")))))))

(defun do-file (file)
  (with-current-buffer (find-file file)
    (widen)
    (goto-char (point-min))
    (insert-char-to-int)
    (save-buffer)
    (kill-buffer)))

(when nil
  (map nil #'do-file
       (process-lines "git" "--no-pager" "grep" "-le" *them* "--" "src")))

(when nil
  (insert-char-to-int))

;;; isspace(xx*(4+5))+8
