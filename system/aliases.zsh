alias ls='ls --color=auto'
alias cp="rsync -poghb --backup-dir=/tmp/rsync -e /dev/null --progress --"
alias mv='mv -i -v'
alias less='less -F'
alias sprunge='curl -F "sprunge=<-" http://sprunge.us'
alias y3p='cd ~/Documents/Physics/Year\ 3'
alias redwm='cd ~/.scripts/dwm; makepkg -g >> PKGBUILD; makepkg -fi --noconfirm; killall dwm'
alias rest='cd ~/.scripts/st; makepkg -g >> PKGBUILD; makepkg -fi --noconfirm'

alias g++='g++ -Wall -o'

alias useless='while [ true ]; do head -n 100 /dev/urandom; sleep .1; done | hexdump -C | grep "ca fe"'
