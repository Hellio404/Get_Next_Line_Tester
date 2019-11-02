brew > brew_check 2>&1
check=$(cat brew_check |  wc -l | tr -d " ")
if [ $check -lt 5 ]
then
  git clone https://github.com/Homebrew/brew ~/.brew
  echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc
  source $HOME/.zshrc
  brew help
fi
rm brew_check
brew install valgrind
