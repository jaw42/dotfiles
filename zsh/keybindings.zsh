#Make the delete key work#
#bindkey    "^[[3~"          delete-char
#bindkey    "^[3;5~"         delete-char

#Allow forward and backward by word #
#bindkey ';5D' emacs-backward-word
#bindkey ';5C' emacs-forward-word

bindkey '^[[1;5C' emacs-forward-word
bindkey '^[[1;5D' emacs-backward-word

#bindkey '^[^[[D' backward-word
#bindkey '^[^[[C' forward-word
#bindkey '^[[5D' beginning-of-line
#bindkey '^[[5C' end-of-line
#bindkey '^[[3~' delete-char
#bindkey '^[^N' newtab
#bindkey '^?' backward-delete-char
