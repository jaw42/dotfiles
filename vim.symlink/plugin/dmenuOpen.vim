" Strip the newline from the end of a string
function! Chomp(str)
	let str = substitute(a:str, ' ', '\\ ', 'g')
	return substitute(str, '\n$', '', '')
endfunction

" Find a file and pass it to cmd
function! DmenuOpen(cmd)

	let command = "ag -g \"\""
	let fname = Chomp(system(command . " | dmenu -b -i -l 20 -p " . a:cmd))
	if empty(fname)
		return
	endif
	execute a:cmd . " " . fname
endfunction

map <c-t> :call DmenuOpen("tabe")<cr>
map <c-f> :call DmenuOpen("e")<cr>
