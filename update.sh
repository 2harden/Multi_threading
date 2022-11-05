#REM Author: 2harden
#REM Created Time: 2022/11/5
#REM Release: 1.1
#REM Description: update commit

echo -n "enter commit msg: "
read msg

git add .
git commit -m "$msg"
git push