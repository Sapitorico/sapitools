set nu
set rnu
set background=dark
highlight Normal ctermfg=white ctermbg=black       
set tabstop=8 shiftwidth=8
set autoindent
set smartindent
set cindent
set noswapfile
syntax on
call plug#begin('~/.vim/plugged')
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'vim-airline/vim-airline'
Plug 'jiangmiao/auto-pairs'
"ALE PLUG"
Plug 'NLKNguyen/papercolor-theme'
Plug 'dense-analysis/ale'
Plug 'JuanDAC/betty-ale-vim'
let g:ale_linters = {'c': ['betty-style', 'betty-doc']}
"ENDOF ALEPLUG""
"RAINBOW PLUGINH"
Plug 'frazrepo/vim-rainbow'
let g:rainbow_active = 1
"ENDOF RAINBOW PLUG"
"LIGHTLINE PLUGIN"
Plug 'itchyny/lightline.vim'
set laststatus=2
if !has('gui_running')
   set t_Co=256
endif
"ENDOF LIGHTLINE PLUGIN""
" Initialize plugin system
call plug#end()
