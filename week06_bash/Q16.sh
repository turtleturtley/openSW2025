#!/bin/bash

# Q15의 함수를 가져와서 수정
file_wordcnt() {
  # Q16: 파일 존재 여부 확인 (이미지의 5-8행)
  if [ ! -e "$1" ]; then
    echo "$1 파일이 존재하지 않습니다."
    return 1 # 실패(1)를 반환하고 함수 종료
  fi
  
  # 파일이 존재할 경우 (Q15의 로직)
  count=$(wc -w < "$1")
  echo "$1 파일의 단어는 $count 개 입니다."
  # 성공(0)은 자동으로 반환됨
}

# Q16: 사용자 입력 받기 (이미지의 14행)
read -p "Enter a file name: " FILE

# Q16: 함수 호출 (이미지의 15행)
file_wordcnt $FILE

# Q16: 종료 상태 출력 (이미지의 16행)
echo "file_wordcnt 함수의 종료 상태: $?"
