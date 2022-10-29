set number relativenumber	"Números relativos para saltar"
"set background=balck
highlight Normal ctermfg=white ctermbg=black
set showmatch	"resaltar paréntesis y corchetes coincidentes"
set wildmenu "habilitar el menú salvaje visual"
let &t_ut=''	"Para representar correctamente el fondo del esquema de colori"
set splitbelow splitright	"Configure las divisiones para que se abran en el lado derecho y debajo"
set nocompatible	"anular la compatibilidad con Vi"
set history=1000	"aumentar la cantidad de comandos"
set tabstop=8 shiftwidth=8
set lazyredraw  
set ttyfast
set autoindent
set smartindent
set cindent
set noswapfile
syntax on
call plug#begin('~/.vim/plugged')
Plug 'iamcco/mathjax-support-for-mkdp'
Plug 'mctechnology17/vimtools'
" Carga bajo demanda 
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle'  }
Plug 'tpope/vim-fireplace', { 'for': 'clojure'  }
" Se permite cualquier URL de git válida 
Plug 'https://github.com/junegunn/vim-github-dashboard.git'
" Se pueden escribir varios comandos de Plug en una sola línea usando | separators
Plug 'SirVer/ultisnips' | Plug 'honza/vim-snippets'
" Usando una rama no predeterminada
Plug 'rdnetto/YCM-Generator', { 'branch': 'stable'  }
" Usando una versión etiquetada; comodín permitido (requiere git 1.9.2 o superior) 
Plug 'fatih/vim-go', { 'tag': '*'  }
" Plugin options
Plug 'nsf/gocode', { 'tag': 'v.20150303', 'rtp': 'vim'  }
" Plugin outside ~/.vim/plugged with post-update hook
Plug 'junegunn/fzf', { 'dir': '~/.fzf', 'do': './install --all'  }
" Unmanaged plugin (manually installed and updated)
Plug '~/my-prototype-plugin'
Plug 'morhetz/gruvbox'
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
colorscheme gruvbox
