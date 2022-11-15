set nocompatible			"required
filetype off				"required

"set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

"alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

"let Vundle manage Vundle, required
Plugin 'gmarik/Vundle.vim'

"add all your plugins here (note older versions of Vundle
"used Bundle instead of Plugin)

"Plugin for autocomplete
Bundle 'Valloric/YouCompleteMe'
"Plugin for indentation
Plugin 'vim-scripts/indentpython.vim'
"Plugin for fold
Plugin 'tmhedberg/SimpylFold'
"Plugin for syntax checking
Plugin 'vim-syntastic/syntastic'
"Plugin for checking PEP 8
Plugin 'nvie/vim-flake8'
"Plugin for color-schemes
Plugin 'jnurmine/Zenburn'
Plugin 'altercation/vim-colors-solarized'
"Plugin for file browsing
Plugin 'scrooloose/nerdtree'
Plugin 'jistr/vim-nerdtree-tabs'
"Plugin for super searching
Plugin 'kien/ctrlp.vim'
"Plugin for git integration
Plugin 'tpope/vim-fugitive'
"Plugin for status bar(PowerLine)
Plugin 'Lokaltog/powerline', {'rtp': 'powerline/bindings/vim/'}
Plugin 'git://git.wincent.com/command-t.git'

"All of your Plugins must be added before the following line
call vundle#end()			"required
filetype plugin indent on		"required

autocmd filetype cpp nnoremap <F5> :w <bar> !g++ -ulimit -Wall -Wno-unused-result -std=c++11   -O2   % -o %:r && ./%:r < ./inp.txt <CR>
autocmd filetype cpp nnoremap <F6> :w <bar> !g++ -ulimit -Wall -Wno-unused-result -std=c++11   -O2   % -o %:r && ./%:r <CR>
syntax on

"Manage split
set splitbelow
set splitright

"Move between splits
nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

"Enable folding
set foldmethod=indent
set foldlevel=99

"Enable folding with spacebar
nnoremap <space> za

"Get docstring
let g:SimpylFold_docstring_preview=1

"Handle Python indentation
au BufNewFile,BufRead *.py,*.c,*.cpp
	\ set tabstop=2 |
	\ set softtabstop=2 |
	\ set shiftwidth=2 |
	\ set textwidth=79 |
	\ set expandtab |
	\ set autoindent |
	\ set fileformat=unix

"Handle fullstack indentation
au BufNewFile,BufRead *.js,*.html,*.css
	\ set tabstop=2 |
	\ set softtabstop=2 |
	\ set shiftwidth=2

"Mark extra(bad) whitespaces as bad(red)
"au BufRead,BufNewFile *.py,*.pyw,*.c,*.cpp,*.h match BadWhitespace /\s\+$/

"UTF-8 Support
set encoding=utf-8

let g:ycm_autoclose_preview_window_after_completion=1
map <leader>g :YcmCompleter GoToDefinitionElseDeclaration<CR>

"python with virtualenv support
python3<<EOF
import os
import sys
if 'VIRTUAL_ENV' in os.environ:
	project_base_dir = os.environ['VIRTUAL_ENV']
	activate_this = os.path.join(project_base_dir, 'bin/activate_this.py')
	execfile(activate_this, dict(__file__=activate_this))
EOF

let python_highlight_all=1
syntax on

autocmd BufNewFile  *.cpp 0r ~/.vim/template/template.cpp

if has('gui_running')
	set background=dark
	colorscheme solarized
else
	colorscheme zenburn
endif

"Mapping F5 to switch between backgrounds
call togglebg#map("<F5>")

"To hide .pyc files
let NERDTreeIgnore=['\.pyc$', '\~$']		"Ignore files in NERD Tree

"Setting hybrid line number
set number relativenumber
set nu rnu

"Show matching brackets
set showmatch

" Enhanced keyboard mappings
"
" in normal mode F2 will save the file
nmap <F2> :w<CR>
" in insert mode F2 will exit insert, save, enters insert again
imap <F2> <ESC>:w<CR>i
" switch between header/source with F4
map <F4> :e %:p:s,.h$,.X123X,:s,.cpp$,.h,:s,.X123X$,.cpp,<CR>
" recreate tags file with F5
map <F5> :!ctags -R –c++-kinds=+p –fields=+iaS –extra=+q .<CR>
" create doxygen comment
map <F6> :Dox<CR>
" build using makeprg with <F7>
map <F7> :make<CR>
" build using makeprg with <S-F7>
map <S-F7> :make clean all<CR>
" goto definition with F12
map <F12> <C-]>
" in diff mode we use the spell check keys for merging
if &diff
  ” diff settings
  map <M-Down> ]c
  map <M-Up> [c
  map <M-Left> do
  map <M-Right> dp
  map <F9> :new<CR>:read !svn diff<CR>:set syntax=diff buftype=nofile<CR>gg
else
  " spell settings
  :setlocal spell spelllang=en
  " set the spellfile - folders must exist
  set spellfile=~/.vim/spellfile.add
  map <M-Down> ]s
  map <M-Up> [s
endif

" Load standard tag files
set tags+=~/.vim/tags/cpp
set tags+=~/.vim/tags/gl
set tags+=~/.vim/tags/sdl
set tags+=~/.vim/tags/qt4

