#!/bin/sh
rm *.o
rm ./*
git add --all && git commit -m "$1" && git push