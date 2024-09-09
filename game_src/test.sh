#!/bin/bash 
make clear && make && 
read -n 1 -s -r -p "Press any key to continue" && clear &&
./GAME -log -debug && clear &&
cat latest.log | rainbow --blue=ImchadaEngine --red=ERROR --yellow=WARN --green=LOG --green=# 
