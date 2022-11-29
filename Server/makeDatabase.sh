dbname=LABO3GillesD
tablename=templogger
username=labo3GillesDurnez
userpassword=labo2GillesDurnezPW

sudo mysql -e "CREATE DATABASE IF NOT EXISTS $dbname;"
sudo mysql -e "CREATE USER IF NOT EXISTS '$username'@'localhost' IDENTIFIED BY '$userpassword';"
sudo mysql -e "GRANT ALL PRIVILEGES ON $dbname.* TO '$username'@'localhost';"

sudo mysql -e "USE $dbname; CREATE TABLE IF NOT EXISTS $tablename (temp VARCHAR(20), time TIMESTAMP DEFAULT CURRENT_TIMESTAMP);"