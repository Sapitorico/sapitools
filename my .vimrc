set nu
  1 set rnu
  2 set background=dark
  3 highlight Normal ctermfg=white ctermbg=black       
  4 set tabstop=8 shiftwidth=8
  5 set autoindent
  6 set smartindent
  7 set cindent
  8 set noswapfile
  9 syntax on
 10 call plug#begin('~/.vim/plugged')
 11 Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
 12 Plug 'vim-airline/vim-airline'
 13 Plug 'jiangmiao/auto-pairs'
 14 "ALE PLUG"
 15 Plug 'NLKNguyen/papercolor-theme'
 16 Plug 'dense-analysis/ale'
 17 Plug 'JuanDAC/betty-ale-vim'
 18 let g:ale_linters = {'c': ['betty-style', 'betty-doc']}
 19 "ENDOF ALEPLUG""
 20 "RAINBOW PLUGINH"
 21 Plug 'frazrepo/vim-rainbow'
 22 let g:rainbow_active = 1
 23 "ENDOF RAINBOW PLUG"
 24 "LIGHTLINE PLUGIN"
 25 Plug 'itchyny/lightline.vim'
 26 set laststatus=2
 27 if !has('gui_running')
 28   set t_Co=256
 29 endif
 30 "ENDOF LIGHTLINE PLUGIN""
 31 " Initialize plugin system
 32 call plug#end()
