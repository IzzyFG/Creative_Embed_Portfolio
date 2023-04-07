#!/bin/bash

# Ugly little Bash script, generates a set of .h files for GFX using
# GNU FreeFont sources.  There are three fonts: 'Mono' (Courier-like),
# 'Sans' (Helvetica-like) and 'Serif' (Times-like); four styles: regular,
# bold, oblique or italic, and bold+oblique or bold+italic; and four
# sizes: 9, 12, 18 and 24 point.  No real error checking or anything,
# this just powers through all the combinations, calling the fontconvert
# utility and redirecting the output to a .h file for each combo.

# Adafruit_GFX repository does not include the source outline fonts
# (huge zipfile, different license) but they're easily acquired:
# http://savannah.gnu.org/projects/freefont/

convert=./fontconvert
inpath=../../freefont-20120503/
outpath=../Fonts/
fonts= (FreeSerif)
sizes=(19 20 21 22 23 25 26 27 28)

if [[ ! -e $outpath ]]; then
    mkdir $outpath
fi

for f in ${fonts[*]}
do
	for si in ${sizes[*]}
	do
		infile=$inpath$f".ttf"
		if [ -f $infile ] # Does source combination exist?
			then
			outfile=$outpath$f$si"pt7b.h"
			printf "%s %s %s > %s\n" $convert $infile $si $outfile
			$convert $infile $si > $outfile
		fi
	done
	
done
