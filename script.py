#!/usr/bin/python
# -*- coding: iso-8859-1 -*-

import serial

comport = serial.Serial('COM4', 9600)
print('Serial Iniciada...\n')

import mysql.connector

cnx = mysql.connector.connect(
    host="127.0.0.1",
    database="banco_arduino",
    user="root",
    password=""
)
cursor = cnx.cursor()
##cursor.execute("INSERT INTO circuito")
add_temp = ("INSERT INTO circuito (temperatura) VALUES (%s)")
while (True):
    serialValue = str(comport.readline())
    characters = "b'"
    for x in range(len(characters)):
        serialValue = serialValue.replace(characters[x], "")
    data_sinais = serialValue.split("\r\n")
    #print(data_sinais)
    cursor.execute(add_temp, data_sinais)
    cnx.commit()

cursor.close()
cnx.close()
comport.close()
