#!/bin/sh
# 逐个跑一遍五十例
for f in build/*.exe; do
  echo "===== $f ====="
  "$f" || echo "(失败：$?)"
done