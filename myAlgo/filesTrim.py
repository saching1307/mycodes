import os
import sys

def findElement(folderName, lists):
	for i in lists:
		if folderName == i:
			return 1
	return 0

t = open('diff_set')
unique_folder = []
for filename in t.readlines():
	folder = filename.split("/")
	folderName = "";
	del folder[-1]
	for j in folder:
		folderName +=j+"/"
	if findElement(folderName,unique_folder)==0:
		unique_folder.append(folderName)
for i in unique_folder:
	print i	
