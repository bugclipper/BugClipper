git add -A
git commit -m "framework and podspec updated"
git push origin master
git tag -d 2.0.0
git push origin :refs/tags/2.0.0
git tag 2.0.0
git push origin 2.0.0