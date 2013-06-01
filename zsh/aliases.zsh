alias reload!='. ~/.zshrc'

alias ls='ls --color=auto'
alias cp="rsync -poghb --backup-dir=/tmp/rsync -e /dev/null --progress --"
alias mv='mv -i -v'
alias rm='rm -v'
alias less='less -F'
alias sprunge='curl -F "sprunge=<-" http://sprunge.us'

# Quick move -----------------------------
alias y3p='cd ~/Documents/Physics/Year\ 3'

# Rebuild dwm, install and restart -------
alias redwm='cd ~/.scripts/dwm; makepkg -g >> PKGBUILD; makepkg -fi --noconfirm; killall dwm'

alias g++='g++ -Wall -o'

# Pointess command to look wierd and cool
alias useless='while [ true ]; do head -n 100 /dev/urandom; sleep .1; done | hexdump -C | grep "ca fe"'

paclist() {
  sudo pacman -Qei $(pacman -Qu|cut -d" " -f 1)|awk ' BEGIN {FS=":"}/^Name/{printf("\033[1;36m%s\033[1;37m", $2)}/^Description/{print $2}'
}

# Print a calendar for the next week using the width of the terminal as max
alias calw='rem -w$COLUMNS,0,1 -m -c+1'

alias mail='mailx -A gmail'
alias mailv='mailx -vA gmail'

# Media -------------------------------
alias mplayer='mplayer -msgcolor -nolirc -nojoystick'
alias mute-beep='xset -b && sudo rmmod pcspkr'
alias play-dvd='mplayer -nocache -dvd-device /dev/sr0 -mouse-movements dvdnav://'


alias vless='vim -u /usr/share/vim/vim73/macros/less.vim'  
