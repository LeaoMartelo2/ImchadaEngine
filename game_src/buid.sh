set -xe
make clear && make && clear && ./GAME -log -debug && cat latest.log
