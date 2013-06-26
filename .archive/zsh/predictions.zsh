autoload predict-on
zle -N predict-off
zle -N predict-on
bindkey '^Z'   predict-on
bindkey '^X^Z' predict-off
zstyle ':predict' verbose true

zstyle :predict verbose yes
zstyle :predict cursor key
zstyle ':completion:predict:*' completer \
  _oldlist _complete _ignored _history _prefix
