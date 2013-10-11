autocmd Filetype java set makeprg=javac\ %
set errorformat=%A%f:%l:\ %m,%-Z%p^,%-C%.%#

map <F9> :make<Return>
map <F10> :copen<Return>:cprevious<Return>
map <F11> :copen<Return>:cnext<Return>
