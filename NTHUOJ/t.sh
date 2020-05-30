#!/bin/bash

#needed in case we have empty folders
shopt -s nullglob

#we must write the full path here (no ~ character)
target="."

#we use a glob to list the folders. parsing the output of ls is baaaaaaaddd !!!!
#for every folder in our photo folder ... 
for dir in "$target"/*/
do
    #we list the subdirectories ...
    for sub in "$dir"/*/
    do
        #and we move the content of the subdirectories to the parent
        mv "$sub"/* "$dir"
        #if you want to remove subdirectories once the copy is done, uncoment the next line
        #rm -r "$sub"
    done
done
