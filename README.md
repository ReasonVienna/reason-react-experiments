This is a repo with examples usages of [Reason-React](https://github.com/reasonml/reason-react), whose docs are [here](https://github.com/reasonml/reason-react/blob/master/documentation.md).
Have something you don't understand? Join us on [Discord](https://discord.gg/reasonml)!

## System setup

```sh
# On OSX, install opam via Homebrew:
brew update
brew install opam
# On Linux, see here (you'll need opam >= 1.2.2): http://opam.ocaml.org/doc/Install.html

opam init

# **Note**: add the line below to your ~/.bashrc or ~/.zshrc too; it's needed at every shell startup
eval $(opam config env)
opam update
opam switch 4.02.3

opam install reason
opam install merlin
```

## Install project and dependencies

```sh
# Clone the repo
git clone https://github.com/chenglou/reason-react-example.git
cd reason-react-example

npm install
npm start
# in another tab
npm run build
# open the html file directly in your browsers e.g. src/tictactoe/index.html
```

After you see the webpack compilation succeed (the `npm run build` step), open up the nested html files in `src/*`! Then modify whichever file in `src` and refresh the page to see the changes.
