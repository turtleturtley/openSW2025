#!/bin/bash

file_wordcnt() {
  for file in "$@"
  do
    count=$(wc -w < "$file")
    echo "$file 파일의 단어는 $count 개 입니다."
  done
}

file_wordcnt file1.txt file2.txt file3.txt
