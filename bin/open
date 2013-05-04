#!/bin/bash

# ---------------------------------------------------------
# Variables.
# Change things here to suit your needs.
# ---------------------------------------------------------

# Genres -----------
Genre_array=(video pdf web image word)

# Programs ---------
        video=mplayer

     pdf_fast=zathura
  pdf_complex=evince

     web_fast=luakit
  web_complex=google-chrome

        image=fehviewer

         word=abiword

# File types -------
video_array=(mpg mpeg avi webm)
pdf_array=(pdf)
web_array=(html htm)
image_array=(jpg jpeg png bmp)
word_array=(docx doc odf rtf)

# Other Options ----
default=fast #fast/complex
verbose_output=false #true/false

# --------------------------------------------------------
# Program
# --------------------------------------------------------

# Check if a value exists in an array
# Usage: in_array "$needle" "${haystack[@]}"
# See: http://fvue.nl/wiki/Bash:_Check_if_array_element_exists
in_array() {
    local hay needle=$1
    shift
    for hay; do
        [[ $hay == $needle ]] && return 0
    done
    return 1
}

verbose() {
    if $verbose_output; then
        if [[ $2 == "n" ]]; then
           echo -n $1 
        else 
            echo $1
        fi
    fi
}

while getopts ":fcv" opt; do
    case $opt in
        f)
            echo "Fast option selected"
            fast=true
            complex=false
            ;;
        c)
            echo "Complex option"
            complex=true
            fast=false
            ;;
        v)
            verbose_output=true
            ;;
        \?)
            echo "Unkown option: -$OPTARG. Defaulting to fast"
    esac
done

shift $((OPTIND-1))
ext=${1##*.}
ext=${ext,,}
verbose "Extension is $ext"

for fileType in "${Genre_array[@]}" ; do
    fileType_array="$fileType""_array[@]"
    
    verbose "Checking genre $fileType ..." n

    if in_array $ext "${!fileType_array}"; then
        verbose "Found extension $ext in genre $fileType"
        
        if [[ default=="fast" ]]; then
            do_default="$fileType""_fast"
        fi
        do_fast="$fileType""_fast"
        do_complex="$fileType""_complex"

        verbose "Filetype = $fileType"

        if [[ $fast ]]; then
            ${!do_fast} "$1"
        elif [[ $complex ]]; then
            ${!do_complex} "$1"
        else
            verbose "No fast/complex option given, using default - $default"
            if [[ -z ${!do_default} ]]; then
                ${!fileType} "$1"
            else
                ${!do_default} "$1"
            fi
        fi
        break
    else
        verbose "nope"
    fi
done


