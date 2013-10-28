if !filereadable("makefile")
	autocmd Filetype java set makeprg=javac\ %
endif
set errorformat=%A%f:%l:\ %m,%-Z%p^,%-C%.%#
