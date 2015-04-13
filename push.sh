git add -A
git commit -m "Minor bug fixes"
git push origin master
git tag -d 2.0.1
git push origin :refs/tags/2.0.1
git tag 2.0.1
git push origin 2.0.1