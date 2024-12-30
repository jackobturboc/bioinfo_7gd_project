#!/bin/bash
 
. .config
 
case "$1" in
  push)
    echo "Push!"
    git push https://"$USERNAME:$PASSWORD"@github.com/jackobturboc/bioinfo_7gd_project
.git
    ;;
  pull)
    echo "Pull!"
    git pull https://"$USERNAME:$PASSWORD"@github.com/jackobturboc/bioinfo_7gd_project
.git
    ;;
  *help)
    echo "Help Information:"
    echo "Script to connect with github (pull and push command are available)"
    ;;
  *)
    exit 1
esac
