#!/bin/bash

# ==============================
# Advanced Linux + DevOps Scenarios
# ==============================

# ==============================
# 1. Log Rotation & Monitoring
# ==============================

# Q1. How to monitor logs in real-time and search for errors?
tail -f /var/log/syslog | grep -i "error"
# Output: Streams syslog lines containing "error"

# Q2. How to rotate logs manually?
# Move old log to backup and create new one
cp /var/log/syslog /var/log/syslog.bak
cat /dev/null > /var/log/syslog

# Q3. Using logrotate config
# Example config /etc/logrotate.d/custom:
# /var/log/myapp.log {
#    daily
#    rotate 7
#    compress
#    missingok
#    notifempty
#    create 0640 root root
# }

# ==============================
# 2. Disk & Process Monitoring
# ==============================

# Q1. Check disk usage and alert if > 80%
disk_usage=$(df / | grep / | awk '{ print $5 }' | sed 's/%//g')
if [ $disk_usage -gt 80 ]; then
    echo "Warning! Disk usage is above 80%: $disk_usage%"
fi

# Q2. Monitor memory usage
free -h
vmstat 1 5

# Q3. Check top CPU-consuming processes
ps aux --sort=-%cpu | head -5

# Q4. Automatically kill a process if it exceeds memory
# WARNING: Example for demonstration
mem_limit=50000  # in KB
for pid in $(ps -e -o pid --no-headers); do
    mem=$(pmap $pid | tail -n 1 | awk '/[0-9]K/{print $2}' | sed 's/K//')
    if [ "$mem" -gt "$mem_limit" ]; then
        echo "Killing PID $pid using $mem KB memory"
        kill -9 $pid
    fi
done

# ==============================
# 3. Cron Job Automation
# ==============================

# Q1. Backup /var/www daily at 2AM
# crontab -e
# 0 2 * * * tar -czf /backup/www_$(date +\%F).tar.gz /var/www

# Q2. Clean /tmp folder every day at midnight
# 0 0 * * * rm -rf /tmp/*

# ==============================
# 4. Docker Deployment & Management
# ==============================

# Q1. Pull and run nginx container
docker pull nginx:latest
docker run -d --name mynginx -p 8080:80 nginx:latest

# Q2. Check running containers
docker ps

# Q3. Enter container shell
# docker exec -it mynginx bash

# Q4. Stop and remove container
docker stop mynginx
docker rm mynginx

# Q5. Remove unused images
docker image prune -f

# ==============================
# 5. Backup Automation
# ==============================

# Q1. Backup MySQL database
# mysqldump -u root -p mydb > /backup/mydb_$(date +%F).sql

# Q2. Backup folder to remote server
# rsync -avz /var/www user@remote-server:/backup/www

# ==============================
# 6. Network Monitoring
# ==============================

# Q1. Check listening ports and services
ss -tulnp
# Output example: tcp LISTEN 0 128 0.0.0.0:22 0.0.0.0:* users:(("sshd",pid=1234,fd=3))

# Q2. Monitor network traffic
iftop -n -P
# Requires sudo, real-time traffic display

# Q3. Test connectivity to multiple hosts
for host in google.com github.com example.com; do
    ping -c 2 $host
done

# ==============================
# 7. System Optimization & Maintenance
# ==============================

# Q1. Remove unnecessary packages
sudo apt-get autoremove -y

# Q2. Check and fix disk errors
sudo fsck -n /dev/sda1

# Q3. Clear system cache
sync; echo 3 > /proc/sys/vm/drop_caches

# ==============================
# 8. Environment & Automation Tips
# ==============================

# Q1. Export environment variable for scripts
export APP_ENV=production
echo $APP_ENV

# Q2. Loop through multiple servers and run commands
servers=("server1" "server2" "server3")
for server in "${servers[@]}"; do
    echo "Checking disk usage on $server"
    ssh user@$server df -h /
done

# Q3. Monitor log size growth and alert
log_file="/var/log/myapp.log"
max_size=10485760  # 10MB
actual_size=$(stat -c%s "$log_file")
if [ "$actual_size" -gt "$max_size" ]; then
    echo "Alert! Log file exceeded 10MB: $actual_size bytes"
fi

# ==============================
# 9. Combined Real-World Script Example
# ==============================

# This script backs up /var/www, rotates logs, monitors disk, and cleans temp files

backup_dir="/backup/www_$(date +%F)"
mkdir -p $backup_dir
tar -czf $backup_dir/www.tar.gz /var/www
echo "Backup completed at $(date)"

# Rotate myapp.log
cp /var/log/myapp.log /var/log/myapp.log.bak
cat /dev/null > /var/log/myapp.log

# Disk alert
disk_usage=$(df / | grep / | awk '{print $5}' | sed 's/%//g')
if [ $disk_usage -gt 80 ]; then
    echo "Warning! Disk usage is above 80%: $disk_usage%"
fi

# Clean /tmp older than 7 days
find /tmp -type f -mtime +7 -exec rm -f {} \;
echo "Old temp files cleaned"
