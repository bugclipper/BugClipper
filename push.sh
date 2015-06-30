git add -A
git commit -m "Framework complilation issue resolved"
git push origin master
git tag -d 2.0.4
git push origin :refs/tags/2.0.4
git tag 2.0.4
git push origin 2.0.4