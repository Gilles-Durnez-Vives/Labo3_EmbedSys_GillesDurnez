cmake_minimum_required(VERSION 2.6)
project(Labo3_GillesD)
add_executable(Labo3_Site site.c)

include_directories(/usr/include/mariadb /usr/include/mariadb/mysql)

target_link_libraries(Labo3_Site mariadb)