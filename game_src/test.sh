set -xe
make clear && make && read -n 1 -s -r -p "Press Any key to continue" && clear && ./GAME -log -debug && cat latest.log
