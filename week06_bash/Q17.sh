#!/bin/bash

file_wordcnt() {
  for file in *.txt
  do
    count=$(wc -w < "$file")
    echo "$file 파일의 단어는 $count 개 입니다."
  done
}

file_wordcnt
