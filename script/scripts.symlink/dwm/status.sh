#!/bin/bash
# Status script for dwm
# colours: 01:normal 02:white 03:red 04:green 05:yellow 06:blue 07:cyan 08:magenta 09:grey

# mem(){
# 	mem="$(awk '/^-/ {print $3}' <(free -m))"
# 	echo -e "Mem\x04$mem\x01"
# }

#    # CPU line courtesy Procyon:https://bbs.archlinux.org/viewtopic.php?pid=874333#p874333
# cpu(){
# 	read cpu a b c previdle rest < /proc/stat
# 	prevtotal=$((a+b+c+previdle))
# 	sleep 0.5
# 	read cpu a b c idle rest < /proc/stat
# 	total=$((a+b+c+idle))
# 	cpu="$((100*( (total-prevtotal) - (idle-previdle) ) / (total-prevtotal) ))"
# 	echo -e "CPU\x05$cpu%\x01"
# 	}

# hdd(){
# 	hd="$(df -P | sort -d | awk '/^\/dev\//{s=s (s?" ":"") $5} END {printf "%s", s}')"
# 	echo -e "HDD\x08$hd\x01"
# }

# colours: 01:normal 02:white 03:red 04:green 05:yellow 06:blue 07:magenta 08:cyan 09:grey
minute=$(date +%M)
mpd(){
	status=4
	cur=$(mpc -f "[[%artist% - ]%title%]|[%file%]" | head -n 1)
	echo -e " \x08$cur\x01"
}

mail(){
	new=$(find ~/.mail/ -type f -wholename '*/new/*' | wc -l);
	unread=$(find ~/.mail/ -type f -regex '.*/cur/.*2,[^S]*$' | wc -l);
	if [ $new != 0 ]; then
		echo -e "\x04M:\x01$unread-$new"
	fi
}

pac(){
	pup="$(pacman -Qqu | wc -l)"
	if [ $pup != 0 ]; then
	    echo -e "\x04P:\x01$pup"
	fi
}

hdd(){
	if [ $minute == "35" ]; then
		disk=$(df /dev/sda7 --output=pcent | tail -n 1 | tr -d " ")
		echo -e "\x06H:\x01$disk"
	else
		echo -e "\x06H:\x01$disk"
	fi
}

int(){
	ipaddr=$(ifconfig wlan0 | awk '/inet / {print $2}')
	signal=$(cat /proc/net/wireless | grep wlan0 | awk '{print $3}' | tr -d ".")
    echo -e "\x06I:\x01($ipaddr) \x06W:\x01"
    if [ $signal -le 30 ]; then
    	echo -e "\x07$signal%\x01"
    else
    	echo -e "\x01$signal%\x01"
    fi
}

dte(){
	up=$(awk '{printf("%dd %02dh %02dm",($1/60/60/24),($1/60/60%24),($1/60%60))}' /proc/uptime
)
	tme=$(date "+%I:%M%P")
	dte=$(date "+%e %b'%g")
	echo -e "\x06Up:\x01$up \x08$tme\x01 $dte"
}

xsetroot -name "$(mpd) $(mail) $(pac) $(hdd) $(int) $(dte) "
