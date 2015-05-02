git add -A
git commit -m "Conflict with UIAlertView Category resolved"
git push origin master
git tag -d 2.0.2
git push origin :refs/tags/2.0.2
git tag 2.0.2
git push origin 2.0.2