#!/bin/tcsh
if ($# != 2) then
    echo "ERROR: Two parameters must be supplied."
    exit
else if (! -e $1) then
    echo "ERROR: $1 does not exist."
    exit
else if (-e $2) then
    echo -n "$2 already exists. Do you want to override it? [Y/n] "
    set input = $<
    if ($input !~ [YyNn]) then
        echo "ERROR: $input is not a valid choice."
        exit
    else if ($input =~ [Nn]) then
        echo "$2 will not be overwritten."
        exit
    endif
endif
echo "Copying $1 to $2."
cp $1 $2

