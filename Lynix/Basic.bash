#!/bin/bash

# ==============================
# 1. Linux Basics
# ==============================

# Q1. What is Linux?
# A: Open-source, Unix-like OS kernel used in servers, desktops, embedded systems.

# Q2. Root vs Sudo?
# A: root has full privileges. sudo lets normal users execute commands as root.

# Q3. Show current directory?
pwd
# Output example: /home/user

# Q4. List files in current directory?
ls -l
# Output:
# -rw-r--r-- 1 user user 123 Sep 30 12:00 file.txt

# Q5. Change directory?
cd /tmp

# Q6. Show hidden files?
ls -a
# Output: .  ..  .bashrc  .profile  file.txt

# Q7. Show Linux version?
uname -a
# Output example: Linux ubuntu 5.15.0-50-generic x86_64 GNU/Linux

# Q8. Show kernel release?
uname -r

# Q9. Current logged-in user?
whoami

# Q10. Show last logged-in users?
last | head -5

# ==============================
# 2. File & Directory Management
# ==============================

# Q1. Create a file?
touch testfile.txt

# Q2. Create directory?
mkdir myfolder

# Q3. Copy files?
cp testfile.txt copyfile.txt

# Q4. Move/rename files?
mv copyfile.txt renamed.txt

# Q5. Delete file?
rm renamed.txt

# Q6. Delete directory recursively?
rm -r myfolder

# Q7. Search for a file?
find /tmp -name "testfile.txt"

# Q8. Check permissions?
ls -l testfile.txt

# Q9. Change permissions?
chmod 755 testfile.txt

# Q10. Change owner?
sudo chown root:root testfile.txt

# Q11. Display first 10 lines of a file?
head -10 testfile.txt

# Q12. Display last 10 lines of a file?
tail -10 testfile.txt

# Q13. Count lines in a file?
wc -l testfile.txt

# ==============================
# 3. Text Processing
# ==============================

# Q1. Search text in file?
echo -e "apple\nbanana\napple" > fruits.txt
grep "apple" fruits.txt
# Output: apple \n apple

# Q2. Case-insensitive search?
grep -i "Apple" fruits.txt

# Q3. Count occurrences?
grep -c "apple" fruits.txt
# Output: 2

# Q4. Search recursively?
grep -r "apple" /tmp

# Q5. Sort file contents?
sort fruits.txt

# Q6. Remove duplicate lines?
uniq fruits.txt

# Q7. Count lines, words, chars?
wc fruits.txt

# Q8. Extract column from CSV?
echo -e "name,age\njohn,25\njane,30" > people.csv
cut -d',' -f2 people.csv

# Q9. Print first column using awk?
awk -F',' '{print $1}' people.csv

# Q10. Replace text using sed?
sed 's/apple/orange/g' fruits.txt

# Q11. Show line numbers with grep?
grep -n "apple" fruits.txt
# Output: 1:apple 3:apple

# ==============================
# 4. Bash Scripting & Automation
# ==============================

# Q1. Loop through files in folder?
for file in /tmp/*.txt; do
    echo "Found file: $file"
done

# Q2. Check if file exists?
if [ -f testfile.txt ]; then
    echo "File exists"
else
    echo "File does not exist"
fi

# Q3. Bash function?
myfunc() { echo "Hello $1"; }
myfunc "Rocky"

# Q4. Pass arguments to script?
# $1, $2, $@ for all

# Q5. Conditional example?
read -p "Enter number: " num
if [ $num -gt 10 ]; then
    echo "Greater than 10"
else
    echo "10 or less"
fi

# Q6. Schedule script with cron?
# crontab -e
# 0 2 * * * /path/to/script.sh

# Q7. Infinite loop with sleep?
while true; do
    echo "Running..."
    sleep 10
done

# ==============================
# 5. Process Management
# ==============================

# Q1. List all processes?
ps aux | head -5

# Q2. Interactive process viewer?
top -n 1

# Q3. Kill process by PID?
sleep 100 &
pid=$!
kill $pid

# Q4. Force kill process?
sleep 100 &
pid=$!
kill -9 $pid

# Q5. Jobs, bg, fg example?
sleep 100 &
jobs
bg %1
fg %1

# Q6. Set process priority?
nice -n 10 command
renice 5 -p $pid

# ==============================
# 6. Networking
# ==============================

# Q1. Check IP addresses?
ip a

# Q2. Ping a host?
ping -c 2 google.com

# Q3. Check listening ports?
ss -tulnp

# Q4. Fetch URL content?
curl -s https://example.com | head -5

# Q5. Copy files over SSH?
# scp file.txt user@host:/path

# Q6. Connect via SSH?
# ssh user@host

# ==============================
# 7. Disk & Storage
# ==============================

# Q1. Check disk usage?
df -h

# Q2. Directory size?
du -sh /tmp

# Q3. Mount filesystem?
# mount /dev/sdb1 /mnt

# Q4. Unmount filesystem?
# umount /mnt

# Q5. Check inode usage?
df -i

# Q6. List block devices?
lsblk

# ==============================
# 8. Logs & Monitoring
# ==============================

# Q1. Tail last 10 lines?
tail -n 10 /var/log/syslog

# Q2. Follow log in real-time?
tail -f /var/log/syslog

# Q3. View kernel messages?
dmesg | tail -10

# Q4. Check systemd logs?
journalctl -xe | tail -10

# Q5. Check disk errors?
sudo smartctl -a /dev/sda

# ==============================
# 9. Package Management
# ==============================

# Q1. Install package Ubuntu/Debian?
# sudo apt-get install tree

# Q2. Install package CentOS/RedHat?
# sudo yum install tree

# Q3. Remove package?
# sudo apt-get remove tree
# sudo yum remove tree

# Q4. Update packages?
# sudo apt-get update && sudo apt-get upgrade
# sudo yum update

# ==============================
# 10. DevOps & Advanced Scenarios
# ==============================

# Q1. Manage system services?
# systemctl status nginx
# systemctl start nginx
# systemctl stop nginx

# Q2. List cron jobs?
crontab -l

# Q3. Docker basic commands
docker ps
docker ps -a
docker images
docker run -d --name mynginx -p 8080:80 nginx
docker exec -it mynginx bash
docker stop mynginx
docker rm mynginx

# Q4. Backup MySQL database?
# mysqldump -u root -p mydb > /backup/mydb_$(date +%F).sql

# Q5. Backup folder to remote server?
# rsync -avz /var/www user@remote-server:/backup/www

# Q6. Disk usage alert > 80%?
disk_usage=$(df / | grep / | awk '{print $5}' | sed 's/%//g')
if [ $disk_usage -gt 80 ]; then
    echo "Warning! Disk usage is above 80%: $disk_usage%"
fi

# Q7. Monitor memory usage?
free -h
vmstat 1 5

# Q8. Environment variable example?
export APP_ENV=production
echo $APP_ENV

# Q9. Clear cache?
sync; echo 3 > /proc/sys/vm/drop_caches

# Q10. Real-world combined script example
backup_dir="/backup/www_$(date +%F)"
mkdir -p $backup_dir
tar -czf $backup_dir/www.tar.gz /var/www
echo "Backup completed at $(date)"
cat /dev/null > /var/log/myapp.log
echo "Logs rotated"
