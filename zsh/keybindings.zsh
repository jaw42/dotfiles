#Make the delete key work#
bindkey    "^[[3~"          delete-char
bindkey    "^[3;5~"         delete-char

#Allow forward and backward by word #
bindkey ';5D' emacs-backward-word
bindkey ';5C' emacs-forward-word
