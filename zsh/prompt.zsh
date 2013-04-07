##Custom Prompt##################################################################################
#PROMPT="${success}%{$fg[magenta]%}%n%{$fg[green]%} {%m}:[%2~%{$fg[green]%}]%{$fg[cyan]%}>%{$reset_color%} "

setopt prompt_subst
autoload -Uz vcs_info
zstyle ':vcs_info:*' stagedstr 'M'
zstyle ':vcs_info:*' unstagedstr 'M'
zstyle ':vcs_info:*' check-for-changes true
zstyle ':vcs_info:*' actionformats '%F{5}[%F{2}%b%F{3}|%F{1}%a%F{5}]%f '
zstyle ':vcs_info:*' formats \
  '%F{5}[%F{2}%b%F{5}] %F{2}%c%F{3}%u%f'
zstyle ':vcs_info:git*+set-message:*' hooks git-untracked
zstyle ':vcs_info:*' enable git

+vi-git-untracked() {
  if [[ $(git rev-parse --is-inside-work-tree 2> /dev/null) == 'true' ]] && \
    git status --porcelain | grep '??' &> /dev/null ; then
    hook_com[unstaged]+='%F{1}??%f'
  fi
}

precmd () { vcs_info }
PROMPT='%F{5}[%F{2}%n%F{5}] %F{6}%3~ ${vcs_info_msg_0_} %f> '

RPROMPT="[%{$fg[yellow]%}%*%{$reset_color%}]"
